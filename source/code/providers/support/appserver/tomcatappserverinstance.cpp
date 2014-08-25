/*--------------------------------------------------------------------------------
    Copyright (c) Microsoft Corporation. All rights reserved. See license.txt for license information.
*/
/**
    \file        tomcatappserverinstance.cpp

    \brief       PAL representation of a Tomcat application server

    \date        11-05-18 12:00:00
*/
/*----------------------------------------------------------------------------*/

#include <scxcorelib/scxcmn.h>

#include <string>

#include <scxcorelib/stringaid.h>
#include <scxcorelib/scxfile.h>
#include <scxcorelib/scxfilepath.h>
#include <scxcorelib/scxregex.h>
#include <scxcorelib/scxprocess.h>
#include <util/XElement.h>
#include <scxsystemlib/scxsysteminfo.h>

#include "appserverconstants.h"
#include "tomcatappserverinstance.h"

using namespace std;
using namespace SCXCoreLib;
using namespace SCX::Util::Xml;

namespace SCXSystemLib
{

    /**
       Returns a stream for reading from RELEASE-NOTES text file

       \param[in]  filename   Name of file to open
    */
    SCXHandle<istream> TomcatAppServerInstancePALDependencies::OpenVersionFile(wstring filename)
    {
        return SCXFile::OpenFstream(filename, ios::in);
    }

    /**
       Returns a stream for reading from server.xml

       \param[in]  filename   Name of file to open
    */
    SCXHandle<istream> TomcatAppServerInstancePALDependencies::OpenXmlServerFile(wstring filename)
    {
        return SCXFile::OpenFstream(filename, ios::in);
    }

	/**
       Returns a command for running version script

       \param[in]  filename   Name of file to open
    */
	wstring TomcatAppServerInstancePALDependencies::GetVersionScriptCommand(SCXCoreLib::SCXFilePath filepath)
	{
		SCXCoreLib::SCXFilePath filename(filepath);
		filename.Append(L"version.sh");

		return filename.Get();
	}

    /*----------------------------------------------------------------------------*/
    /**
        Constructor

       \param[in]  id            Identifier for the appserver (= install path for the appserver configuration)
       \param[in]  homePath      Root install path for the application server
       \param[in]  deps          Dependency instance to use
    */
    TomcatAppServerInstance::TomcatAppServerInstance(
        wstring id, wstring homePath, SCXHandle<TomcatAppServerInstancePALDependencies> deps) : 
        AppServerInstance(id, APP_SERVER_TYPE_TOMCAT), m_deps(deps)
    {
        SCXFilePath installPath;
        SCXFilePath homeFilePath;

        installPath.SetDirectory(id);
        SetId(installPath.Get());
        m_diskPath = GetId();
        homeFilePath.SetDirectory(homePath);
        m_homePath = homeFilePath.Get();

        SCX_LOGTRACE(m_log, wstring(L"TomcatAppServerInstance default constructor - ").append(GetId()));
    }


    /*----------------------------------------------------------------------------*/
    /**
        Destructor
    */
    TomcatAppServerInstance::~TomcatAppServerInstance()
    {
        SCX_LOGTRACE(m_log, wstring(L"TomcatAppServerInstance destructor - ").append(GetId()));
    }

    /*----------------------------------------------------------------------------*/
    /**
        Update ports for Tomcat

        Load XML file <ConfigPath>/conf/server.xml

        Get node /Server/Service/Connector where attribute protocol is HTTP/1.1 and secure is true
        Get attribute named port for HTTPS Port
        Get node /Server/Service/Connector where attribute protocol is HTTP/1.1 and no attribute named secure exist
        Get attribute named port for HTTP Port
    */
    void TomcatAppServerInstance::UpdatePorts()
    {
        const string cDeploymentNodeName("deployment");
        const string cServerNodeName("Server");
        const string cServiceNodeName("Service");
        const string cConnectorNodeName("Connector");
        const string cProtocolAttributeName("protocol");
        const string cSecureAttributeName("secure");
        const string cPortAttributeName("port");
        const string cHTTP11Name("HTTP/1.1");
		const string cTomcat8HTTP11Name("org.apache.coyote.http11.Http11NioProtocol");
        const string cTrueName("true");

        SCXFilePath filename(m_diskPath);

        string xmlcontent;
        filename.Append(L"/conf/server.xml");

        try {
            SCXHandle<istream> mystream = m_deps->OpenXmlServerFile(filename.Get());
            GetStringFromStream(mystream, xmlcontent);

            XElementPtr serverNode;
            XElement::Load(xmlcontent, serverNode);
            if (serverNode->GetName() == cServerNodeName)
            {
                XElementPtr serviceNode;

                if (serverNode->GetChild(cServiceNodeName, serviceNode))
                {
                    XElementList connectorNodes;
                    bool foundHTTPnode = false;
                    bool foundHTTPSnode = false;

                    serviceNode->GetChildren(connectorNodes);
                    for (size_t idx = 0; !(foundHTTPnode && foundHTTPSnode) && idx < connectorNodes.size(); ++idx)
                    {
                        string protocolprop;
                        if (connectorNodes[idx]->GetName() == cConnectorNodeName)
                        {
                            // For Tomcat 5 there is no 'Protocol' specified for the HTTP Connector
							// Tomcat 8 uses org.apache.coyote.http11.Http11NioProtocol as the protocol name.
                            // we will use the Connectors as they appear in the file.
                            bool hasAttribute = connectorNodes[idx]->GetAttributeValue(cProtocolAttributeName, protocolprop);
							if ((hasAttribute && (cHTTP11Name == protocolprop)) || 
								(hasAttribute && (cTomcat8HTTP11Name == protocolprop)) ||
                                !hasAttribute )
                            {
                                string secureprop;
                                string portprop;

                                if (connectorNodes[idx]->GetAttributeValue(cPortAttributeName, portprop))
                                {
                                    if (connectorNodes[idx]->GetAttributeValue(cSecureAttributeName, secureprop) && 
                                        cTrueName == secureprop)
                                    {
                                        m_httpsPort = StrFromUTF8(portprop);
                                        foundHTTPSnode = true;
                                    }
                                    else
                                    {
                                        m_httpPort = StrFromUTF8(portprop);
                                        foundHTTPnode = true;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        catch (SCXFilePathNotFoundException&)
        {
            SCX_LOGERROR(m_log, wstring(L"TomcatAppServerInstance::UpdateTomcatPorts() - ").append(GetId()).append(L" - Could not find file: ").append(filename));
        }
        catch (SCXUnauthorizedFileSystemAccessException&)
        {
            SCX_LOGERROR(m_log, wstring(L"TomcatAppServerInstance::UpdateTomcatPorts() - ").append(GetId()).append(L" - not authorized to open file: ").append(filename));
        }
        catch (XmlException&)
        {
            SCX_LOGERROR(m_log, wstring(L"TomcatAppServerInstance::UpdateTomcatPorts() - ").append(GetId()).append(L" - Could not load XML from file: ").append(filename));
        }
    }

    /*----------------------------------------------------------------------------*/
    /**
        Update version

        Open text file RELEASE-NOTES from the home folder
        Find line that contains the string "Apache Tomcat Version " 
        Get the rest of the text on that line as the version

		This file does not exist when installed from package manager
		In order to find the version without the RELEASE-NOTES we can use the
		version.sh script inside the bin directory
    */
    void TomcatAppServerInstance::UpdateVersion()
    {
        const string cTomcatVersionPrecursor("Apache Tomcat Version ");

        SCXFilePath filename(m_homePath);
		SCXFilePath filename2(m_homePath);
        filename.Append(L"RELEASE-NOTES");
		bool tryTomcatVersionScript = false;

        try {
            string filecontent;
            SCXHandle<istream> mystream = m_deps->OpenVersionFile(filename.Get());
            bool foundVersion = false;

            while (!foundVersion && SCXStream::IsGood(*mystream))
            {
                string tmp;
                getline(*mystream, tmp);
                size_t pos = tmp.find(cTomcatVersionPrecursor);
                if (string::npos != pos)
                {
                    foundVersion = true;
                    string version = tmp.substr(pos + cTomcatVersionPrecursor.length());
                    SetVersion(StrStrip(StrFromUTF8(version), L" \t\n\r"));
                }
            }
        }
        catch (SCXFilePathNotFoundException&)
        {
			tryTomcatVersionScript = true;
        }
        catch (SCXUnauthorizedFileSystemAccessException&)
        {
            SCX_LOGERROR(m_log, wstring(L"TomcatAppServerInstance::UpdateVersion() - ").append(GetId()).append(L" - not authorized to open file: ").append(filename));
        }
		if(tryTomcatVersionScript)
		{
			try 
			{
				filename2.Append(L"bin/");

				std::istringstream in;
				std::ostringstream out;
				std::ostringstream err;

				// Get command line from function
				// Determine if version.sh exists
				// Only use SCProcess::Run If version.sh exists
				wstring cli = m_deps->GetVersionScriptCommand(filename2);
				bool versionScriptFileExists = SCXFile::Exists(cli);
				
				if(cli.length() && versionScriptFileExists)
				{
					SystemInfo si;
					wstring command = si.GetShellCommand(cli);
					
					int exitStatus = SCXCoreLib::SCXProcess::Run(command, in, out, err, 10000);
					if(exitStatus != 0 || err.str().length())
					{
						wstring werr = SCXCoreLib::StrFromUTF8(err.str());
						SCX_LOGERROR(m_log, wstring(L"TomcatAppServerInstance::UpdateVersion() - ").append(GetId()).append(L" - error in command line: ").append(werr));
					}
					else
					{
						wstring commandOutput = SCXCoreLib::StrFromUTF8(out.str());
						vector<wstring> v_version;

						SCXRegex re(L"Server number:  (.*).(OS Name)");
						if(re.ReturnMatch(commandOutput, v_version, 0))
						{
							SetVersion(v_version[1]);
						}
						else
							SCX_LOGERROR(m_log, wstring(L"No REGEX match"));
					}
				}
			}
			catch (SCXUnauthorizedFileSystemAccessException&)
			{
				SCX_LOGERROR(m_log, wstring(L"TomcatAppServerInstance::UpdateVersion() - ").append(GetId()).append(L" - not authorized to open file: ").append(filename));
			}
		}
		else
		{
            SCX_LOGERROR(m_log, wstring(L"TomcatAppServerInstance::UpdateVersion() - ").append(GetId()).append(L" - Could not find file: ").append(filename));
		}
	}

    /*----------------------------------------------------------------------------*/
    /**
        Update values

    */
    void TomcatAppServerInstance::Update()
    {
        SCX_LOGTRACE(m_log, wstring(L"TomcatAppServerInstance::Update() - ").append(GetId()));

        UpdateVersion();
        UpdatePorts();
    }

    /*----------------------------------------------------------------------------*/
    /**
        Read all lines from a stream and save in a string

       \param[in]  mystream   Stream to read from
       \param[out] content    String to return content in
    */
    void TomcatAppServerInstance::GetStringFromStream(SCXHandle<istream> mystream, string& content)
    {
        content = "";
        while (SCXStream::IsGood(*mystream))
        {
            string tmp;
            getline(*mystream, tmp);
            content.append(tmp);
            content.append("\n");
        }
    }

}

/*----------------------------E-N-D---O-F---F-I-L-E---------------------------*/
