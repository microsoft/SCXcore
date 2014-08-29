/*--------------------------------------------------------------------------------
    Copyright (c) Microsoft Corporation. All rights reserved. See license.txt for license information.
*/
/**
    \file        websphereappserverinstance.cpp

    \brief       PAL representation of a WebSphere application server

    \date        11-08-20 12:00:00
*/
/*----------------------------------------------------------------------------*/

#include <scxcorelib/scxcmn.h>

#include <string>

#include <scxcorelib/stringaid.h>
#include <scxcorelib/scxfile.h>
#include <scxcorelib/scxfilepath.h>
#include <scxcorelib/scxregex.h>
#include <util/XElement.h>

#include "appserverconstants.h"
#include "websphereappserverinstance.h"

using namespace std;
using namespace SCXCoreLib;
using namespace SCX::Util::Xml;

namespace SCXSystemLib
{

    /**
       Returns a stream for reading from server.xml

       \param[in]  filename   Name of file to open
    */
    SCXHandle<istream> WebSphereAppServerInstancePALDependencies::OpenXmlServerFile(const wstring& filename)
    {
        return SCXFile::OpenFstream(filename, ios::in);
    }

    /**
       Returns a stream for reading from profile.version

       \param[in]  filename   Name of file to open
    */
    SCXHandle<istream> WebSphereAppServerInstancePALDependencies::OpenXmlVersionFile(const wstring& filename)
    {
        return SCXFile::OpenFstream(filename, ios::in);
    }

    /*----------------------------------------------------------------------------*/
    /**
        Constructor

       \param[in]  cell          The WebSphere Cell Name
       \param[in]  node          The WebSphere Node Name
       \param[in]  profile       The WebSphete Profile Name
       \param[in]  installDir    The folder where WebSphere is installed
       \param[in]  server        The WebSphere Server Name
       \param[in]  deps          Dependency instance to use
    */
    WebSphereAppServerInstance::WebSphereAppServerInstance(
        wstring installDir, wstring cell, wstring node, wstring profile, wstring server,
        SCXHandle<WebSphereAppServerInstancePALDependencies> deps) : 
        AppServerInstance(installDir, APP_SERVER_TYPE_WEBSPHERE), m_deps(deps)
    {
        SCXFilePath installPath;

        installPath.SetDirectory(installDir);

        m_diskPath = installPath.Get();
        
        m_cell = cell;
        m_node = node;
        m_profile = profile;
        m_server = server;

        wstring id = profile;
        SetId(id.append(L"-").append(cell).append(L"-").append(node).append(L"-").append(server));

        SCX_LOGTRACE(m_log, wstring(L"WebSphereAppServerInstance default constructor - ").append(GetId()));
    }


    /*----------------------------------------------------------------------------*/
    /**
        Destructor
    */
    WebSphereAppServerInstance::~WebSphereAppServerInstance()
    {
        SCX_LOGTRACE(m_log, wstring(L"WebSphereAppServerInstance destructor - ").append(GetId()));
    }

    
    /*----------------------------------------------------------------------------*/
    /**
        Get port from a specialEndpoints tag from the serverindex.xml file
        
       \param[in]  node   specialEndpoint node to get port from
       \param[out] found  Set to true if successfully read port
       \param[out] port   Return the port if found
    */
    void WebSphereAppServerInstance::GetPortFromXml(const XElementPtr& node, bool& found, wstring& port)
    {
        const string cEndPointNodeName("endPoint");
        const string cPortAttributeName("port");

        XElementPtr endPoint;
        if (node->GetChild(cEndPointNodeName, endPoint))
        {
            string portstr;
            if (endPoint->GetAttributeValue(cPortAttributeName, portstr))
            {
                port = StrFromUTF8(portstr);
                found = true;
            }
        }
    }
    /*----------------------------------------------------------------------------*/
    /**
       function that returns the profileDiskPath instead of the full server disk path
       profile Disk Path ex:/opt/IBM/WebSphere/AppServer/profiles/AppSrv01
       server Disk Path  ec:/opt/IBM/WebSphere/AppServer/profiles/AppSrv01/servers/server1

       to check if we have the already have the profile diskPath we check if the 2nd to last entry is
       const string "profiles"
    */
    wstring returnProfileDiskPath(wstring m_diskPath)
    {
        SCXRegex re(L"(.*)/(.*)/(.*)/(.*)/(.*)");
        vector<wstring> v_profileDiskPath;
        if (re.ReturnMatch(m_diskPath,v_profileDiskPath,0))
        {
            //v_profileDiskPath[1] will include disk path until profile name <../../../../profiles>
            //v_profileDiskPath[2] will include profile name <AppSrv01>
            if(v_profileDiskPath[3].compare(L"servers") == 0)
            {
                return v_profileDiskPath[1].append(L"/").append(v_profileDiskPath[2]).append(L"/");
            }
        }
        return m_diskPath;
    }

    /*----------------------------------------------------------------------------*/
    /**
        Update ports for WebSphere

        Load XML file <disk path>/config/cells/<Cell Name>/nodes/<Node Name>/serverindex.xml
        
        Ger serverIndex/serverEntries node where serverName attribute is the name of the server
        For HTTP port get specialEndpoints node where endPointName is WC_defaulthost and 
          get port attribute from endPoint node
        For HTTPS port get specialEndpoints node where endPointName is WC_defaulthost_secure and 
          get port attribute from endPoint node
    */
    void WebSphereAppServerInstance::UpdatePorts()
    {
        const string cServerIndexNodeName("serverindex:ServerIndex");
        const string cServerEntriesNodeName("serverEntries");
        const string cServerNameAttributeName("serverName");
        const string cSpecialEndpointsNodeName("specialEndpoints");
        const string cEndPointNameAttributeName("endPointName");
        const string cWCdefaultHostName("WC_defaulthost");
        const string cWCdefaultHostSecureName("WC_defaulthost_secure");
        const string cEndPointNodeName("endPoint");
        const string cPortAttributeName("port");
        
        string xmlcontent;
        SCXFilePath filename(returnProfileDiskPath(m_diskPath));        

        filename.AppendDirectory(L"config");
        filename.AppendDirectory(L"cells");
        filename.AppendDirectory(m_cell);
        filename.AppendDirectory(L"nodes");
        filename.AppendDirectory(m_node);
        filename.SetFilename(L"serverindex.xml");

        try {
            SCXHandle<istream> mystream = m_deps->OpenXmlServerFile(filename.Get());
            GetStringFromStream(mystream, xmlcontent);

            // Load the XML, but don't honor namespaces
            XElementPtr serverIndexNode;
            XElement::Load(xmlcontent, serverIndexNode, false);

            if (serverIndexNode->GetName() == cServerIndexNodeName)
            {
                XElementList serverEntriesNodes;
                bool foundServer = false;

                serverIndexNode->GetChildren(serverEntriesNodes);

                for (size_t idx = 0; !foundServer && idx < serverEntriesNodes.size(); ++idx)
                {
                    string name;
                    if (serverEntriesNodes[idx]->GetName() == cServerEntriesNodeName && 
                        serverEntriesNodes[idx]->GetAttributeValue(cServerNameAttributeName, name) && 
                        m_server == StrFromUTF8(name))
                    {
                        XElementList childNodes;
                        bool foundHTTPnode = false;
                        bool foundHTTPSnode = false;
                        foundServer = true;

                        serverEntriesNodes[idx]->GetChildren(childNodes);

                        for (size_t idx2 = 0; !(foundHTTPnode && foundHTTPSnode) && idx2 < childNodes.size(); ++idx2)
                        {
                            if (childNodes[idx2]->GetName() == cSpecialEndpointsNodeName && 
                                childNodes[idx2]->GetAttributeValue(cEndPointNameAttributeName, name))
                            { 
                                if (cWCdefaultHostName == name)
                                {
                                    GetPortFromXml(childNodes[idx2], foundHTTPnode, m_httpPort);
                                }
                                else if (cWCdefaultHostSecureName == name)
                                {
                                    GetPortFromXml(childNodes[idx2], foundHTTPSnode, m_httpsPort);
                                }
                            }
                        }
                    }
                }
            }
        }
        catch (SCXFilePathNotFoundException&)
        {
            SCX_LOGERROR(m_log, wstring(L"WebSphereAppServerInstance::UpdatePorts() - ").append(GetId()).append(L" - Could not find file: ").append(filename));
        }
        catch (SCXUnauthorizedFileSystemAccessException&)
        {
            SCX_LOGERROR(m_log, wstring(L"WebSphereAppServerInstance::UpdatePorts() - ").append(GetId()).append(L" - not authorized to open file: ").append(filename));
        }
        catch (XmlException&)
        {
            SCX_LOGERROR(m_log, wstring(L"WebSphereAppServerInstance::UpdatePorts() - ").append(GetId()).append(L" - Could not load XML from file: ").append(filename));
        }
    }

    /*----------------------------------------------------------------------------*/
    /**
        Update version
        
        Load XML file <disk path>\properties\version\profile.version

        <?xml version="1.0" encoding="UTF-8"?>
        <profile>
          <id>default</id>
          <version>7.0.0.0</version>
          <build-info date="8/31/08" level="r0835.03"/>
        </profile>
              
    */
    void WebSphereAppServerInstance::UpdateVersion()
    {
        const string cProfileNodeName("profile");
        const string cVersionNodeName("version");
        
        string xmlcontent;
        SCXFilePath filename(GetProfileVersionXml());

        try {
            SCXHandle<istream> mystream = m_deps->OpenXmlVersionFile(filename.Get());
            GetStringFromStream(mystream, xmlcontent);

            XElementPtr profileNode;
            XElement::Load(xmlcontent, profileNode);

            if (profileNode->GetName() == cProfileNodeName)
            {
                XElementPtr versionNode;
                if (profileNode->GetChild(cVersionNodeName, versionNode))
                {
                    wstring version;
                    versionNode->GetContent(version);
                    SetVersion(version);
                }
            }
        }
        catch (SCXFilePathNotFoundException&)
        {
            SCX_LOGERROR(m_log, wstring(L"WebSphereAppServerInstance::UpdateVersion() - ").append(GetId()).append(L" - Could not find file: ").append(filename));
        }
        catch (SCXUnauthorizedFileSystemAccessException&)
        {
            SCX_LOGERROR(m_log, wstring(L"WebSphereAppServerInstance::UpdateVersion() - ").append(GetId()).append(L" - not authorized to open file: ").append(filename));
        }
        catch (XmlException&)
        {
            SCX_LOGERROR(m_log, wstring(L"WebSphereAppServerInstance::UpdateVersion() - ").append(GetId()).append(L" - Could not load XML from file: ").append(filename));
        }
    }

    /*----------------------------------------------------------------------------*/
    /**
        Return a file path to the profile.version XML file

    */
    SCXFilePath WebSphereAppServerInstance::GetProfileVersionXml() const
    {
        SCXFilePath filename(returnProfileDiskPath(m_diskPath));
       
        filename.AppendDirectory(L"properties");
        filename.AppendDirectory(L"version");
        filename.SetFilename(L"profile.version");
        
        return filename;
    }

    /*----------------------------------------------------------------------------*/
    /**
        Update values

    */
    void WebSphereAppServerInstance::Update()
    {
        SCX_LOGTRACE(m_log, wstring(L"WebSphereAppServerInstance::Update() - ").append(GetId()));

        UpdateVersion();
        UpdatePorts();
    }

    /*----------------------------------------------------------------------------*/
    /**
        Read all lines from a stream and save in a string

       \param[in]  mystream   Stream to read from
       \param[out] content    String to return content in
    */
    void WebSphereAppServerInstance::GetStringFromStream(SCXHandle<istream> mystream, string& content)
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

    /*--------------------------------------------------------------------*/
    /**
        Check if the application server is still installed.
        
        This overrides the default logic

    */
    bool WebSphereAppServerInstance::IsStillInstalled()
    {
        return SCXFile::Exists(GetProfileVersionXml());
    }
}

/*----------------------------E-N-D---O-F---F-I-L-E---------------------------*/
