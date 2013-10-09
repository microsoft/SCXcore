/*--------------------------------------------------------------------------------
    Copyright (c) Microsoft Corporation.  All rights reserved.
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
#include <util/XElement.h>

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
                            // we will use the Connectors as they appear in the file.
                            bool hasAttribute = connectorNodes[idx]->GetAttributeValue(cProtocolAttributeName, protocolprop);
                            if( ( hasAttribute && (cHTTP11Name == protocolprop) ) ||
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
    */
    void TomcatAppServerInstance::UpdateVersion()
    {
        const string cTomcatVersionPrecursor("Apache Tomcat Version ");

        SCXFilePath filename(m_homePath);
        filename.Append(L"RELEASE-NOTES");

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
            SCX_LOGERROR(m_log, wstring(L"TomcatAppServerInstance::UpdateVersion() - ").append(GetId()).append(L" - Could not find file: ").append(filename));
        }
        catch (SCXUnauthorizedFileSystemAccessException&)
        {
            SCX_LOGERROR(m_log, wstring(L"TomcatAppServerInstance::UpdateVersion() - ").append(GetId()).append(L" - not authorized to open file: ").append(filename));
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
