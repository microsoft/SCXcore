/*----------------------------------------------------------------------
    Copyright (c) Microsoft Corporation. All rights reserved. See license.txt for license information.
*/
/**
   \file        weblogicappserverenumeration.cpp

   \brief       Enumerator of WebLogic Application Server

   \date        11-08-18 12:00:00
*/
/*----------------------------------------------------------------------*/

#include <algorithm>
#include <string>
#include <vector>

#include <scxcorelib/scxcmn.h>
#include <scxcorelib/scxcondition.h>
#include <scxcorelib/scxdirectoryinfo.h>
#include <scxcorelib/scxexception.h>
#include <scxcorelib/scxfile.h>
#include <scxcorelib/scxfilepath.h>
#include <scxcorelib/scxlog.h>
#include <scxcorelib/stringaid.h>
#include <util/XElement.h>

#include "appserverconstants.h"
#include "weblogicappserverenumeration.h"
#include "weblogicappserverinstance.h"

using namespace std;
using namespace SCXCoreLib;
using namespace SCX::Util::Xml;
using namespace SCXSystemLib;

namespace SCXSystemLib {
    /*------------------------------------------------------------------*/
    /**
     Constructor for a file-system abstraction
     Note: this function exists for the purpose of unit-testing
     
     */
    WebLogicFileReader::WebLogicFileReader() : IWebLogicFileReader() {
        m_log = SCXLogHandleFactory::GetLogHandle(L"scx.core.common.pal.system.appserver.weblogicfilereader");
        SCX_LOGTRACE(m_log, L"WebLogicFileReader Constructor");
    }

    /*------------------------------------------------------------------*/
    /**
     Wrapper to the filesystem check if the given file exists.
     Note: this function exists for the purpose of unit-testing
     
     \param[in]  path   Full filepath to the XML file containing
                 the domain's servers's configuration
     
     */
    bool WebLogicFileReader::DoesConfigXmlExist(
            const SCXFilePath& path)
    {
        return SCXFile::Exists(path);
    }

    /*------------------------------------------------------------------*/
    /**
     Wrapper to the filesystem check if the given file exists.
     Note: this function exists for the purpose of unit-testing
     
     \param[in]  path   Full filepath to the XML file containing
                 the domains for a WebLogic 11g install
     
     */
    bool WebLogicFileReader::DoesDomainRegistryXmlExist(
            const SCXFilePath& path)
    {
        return SCXFile::Exists(path);
    }

    /*------------------------------------------------------------------*/
    /**
     Wrapper to the filesystem check if the given file exists.
     Note: this function exists for the purpose of unit-testing
     
     \param[in]  path   Full filepath to the INI file containing
     the domains for a WebLogic 10g install

     */
    bool WebLogicFileReader::DoesNodemanagerDomainsExist(
            const SCXFilePath& path)
    {
        return SCXFile::Exists(path);
    }

    /*------------------------------------------------------------------*/
    /**
     Wrapper to the filesystem check if the given file exists.
     
     In addition to abstracting the file-system access, this check is
     used to determine if a WebLogic managed server is available on
     this particular system.
     
     In a cluster environment, all of the managed servers are present in
     the XML file.  Aparently, the directory will only exist on disk
     if the managed server has been run at least once. This check is
     necessary to prevent instance being discovered on the wrong box
     in a clustered environment.
     
     \param[in]  path   Full filepath to the directory that contains
     the working content of the server's files.

     */
    bool WebLogicFileReader::DoesServerDirectoryExist(
            const SCXFilePath& path)
    {
        return SCXDirectory::Exists(path);
    }

    /*------------------------------------------------------------------*/
    /**
     From the necessary file, read the domains and return a unique list
     of potential domains.
     
     */
    vector<SCXFilePath> WebLogicFileReader::GetDomains()
    {
        SCX_LOGTRACE(m_log, L"WebLogicFileReader::GetDomains");

        vector<SCXFilePath> domains;

        // Logic necessary for reading WebLogic 11g domains
        SCXFilePath domainRegistryXml;
        domainRegistryXml.SetDirectory(m_installationPath);
        domainRegistryXml.SetFilename(
                WEBLOGIC_DOMAIN_REGISTRY_XML_FILENAME);
        
        if (DoesDomainRegistryXmlExist(domainRegistryXml))
        {
            ReadDomainRegistryXml(domainRegistryXml, domains);
        }

        // Logic necessary for reading WebLogic 10g domains
        SCXFilePath nodemanagerDomains;
        nodemanagerDomains.SetDirectory(m_installationPath);
        nodemanagerDomains.AppendDirectory(WEBLOGIC_NODEMANAGER_DOMAINS_DIRECTORY);
        nodemanagerDomains.SetFilename(WEBLOGIC_NODEMANAGER_DOMAINS_FILENAME);

        if (DoesNodemanagerDomainsExist(nodemanagerDomains))
        {
            ReadNodemanagerDomains(nodemanagerDomains, domains);
        }
        
        // There may be duplicates in the list, it is necessary to
        // sort the list of domains and return only the unique instances.
        sort(domains.begin(), domains.end(), SortPath());
        vector<SCXFilePath>::iterator tmp = 
                unique(domains.begin(), domains.end());
        domains.resize(tmp-domains.begin());
                
        SCX_LOGTRACE(m_log, 
                wstring(L"WebLogicFileReader::GetDomains() - ").
                append(L"Found ").append(StrFrom(domains.size())).append(L" domain(s)"));

        return domains;
    }
    
    /*------------------------------------------------------------------*/
    /**
       From the necessary XML configuration file, read information about
       the known instances.
       
       The file should be:
           ${Install}/${Domain}/config/config.xml

       \param[in]  domains    List of domains to find instances for

       \param[out] instances  vector to add instances to
       
    */    
    void WebLogicFileReader::GetInstances(
            const SCXFilePath& domain,
            vector<SCXHandle<AppServerInstance> >& instances)
    {
        SCXFilePath configXml;
        configXml.SetDirectory(domain.Get());
        configXml.AppendDirectory(WEBLOGIC_CONFIG_DIRECTORY);
        configXml.Append(WEBLOGIC_CONFIG_FILENAME);
        
        if (DoesConfigXmlExist(configXml))        
           {
            SCX_LOGTRACE(m_log, 
                    wstring(L"WebLogicFileReader::GetInstances() - ").
                    append(L"Reading ").append(configXml.Get()));
            ReadConfigXml(domain, configXml, instances);
           }
        else
        {
            SCX_LOGTRACE(m_log, 
                    wstring(L"WebLogicFileReader::GetInstances() - ").
                    append(L"Expected configuration file '").
                    append(configXml.Get()).append(L"' does not exist."));
        }
    }

    /*------------------------------------------------------------------*/
    /**
       Returns a stream for reading the domain's config/config.xml file.
       This configuration file contains info for the Admin Server and all
       Managed Servers known to the domain.

       \param[in]  filename   Name of file to open
    */
    SCXHandle<istream> WebLogicFileReader::OpenConfigXml(
            const wstring& filename)
    {
        return SCXFile::OpenFstream(filename, ios::in);
    }
    
    /*------------------------------------------------------------------*/
    /**
       Returns a stream for reading the domain-registry.xml file.
       This is a simple XML file containing directories to the domains
       known to the installation.

       \param[in]  filename   Name of file to open
    */
    SCXHandle<istream> WebLogicFileReader::OpenDomainRegistryXml(
            const wstring& filename)
    {
        return SCXFile::OpenFstream(filename, ios::in);
    }

    /*------------------------------------------------------------------*/
    /**
       Returns a stream for reading the nodemanger.domains file.
       This is a simple text file containing directories to the domains
       known to the installation.

       \param[in]  filename   Name of file to open
    */
    SCXHandle<istream> WebLogicFileReader::OpenNodemanagerDomains(
            const wstring& filename)
    {
        return SCXFile::OpenFstream(filename, ios::in);
    }

    /*------------------------------------------------------------------*/
    /**
       Read a simple XML file to find the locations of the both 
       the Admin and Managed servers for a WebLogic 11g R1 installation.
       
       Example:
       <?xml version="1.0" encoding="UTF-8"?>
       <domain ...>
         <name>base_domain</name>
         <domain-version>10.3.2.0</domain-version>
         <security-configuration ...>
            ...
         </security-configuration>
         <server>
           <name>AdminServer</name>
           <ssl>
             <name>AdminServer</name>
             <enabled>true</enabled>
             <listen-port>7012</listen-port>
           </ssl>
           <machine>new_UnixMachine_1</machine>
           <listen-port>7011</listen-port>
           <listen-address/>
         </server>
         <server>
           <name>new_ManagedServer_1</name>
           <ssl>
             <name>new_ManagedServer_1</name>
             <enabled>true</enabled>
             <listen-port>7513</listen-port>
           </ssl>
           <machine>new_UnixMachine_1</machine>
           <listen-port>7013</listen-port>
           <listen-address/>
         </server>
         <embedded-ldap>
           <name>base_domain</name>
           <credential-encrypted>{AES}RVX+Cadq8XJ5EvV7/1Ta2qGZrJlxve6t5CEa2A9euGUkYOMDTAwAqytymqDBS00Q</credential-encrypted>
         </embedded-ldap>
         <configuration-version>10.3.2.0</configuration-version>
         <machine xsi:type="unix-machineType">
           <name>new_UnixMachine_1</name>
           <node-manager>
             <name>new_UnixMachine_1</name>
             <listen-address>localhost</listen-address>
             <listen-port>5566</listen-port>
           </node-manager>
         </machine>
         <admin-server-name>AdminServer</admin-server-name>
       </domain>

              \param[in]  domainDir         Directory of the domain (needed
                                            for build the path to the server
       
              \param[in]  configXml         File object of the XML file
                                            to open.
                                            
              \param[out] instances         vector that will contain the
                                            list of server instances for the
                                            given domain.
       
     */
    void WebLogicFileReader::ReadConfigXml(
            const SCXFilePath& domainDir,
            const SCXFilePath& configXml,
            vector<SCXHandle<AppServerInstance> >& instances)
    {
        SCX_LOGTRACE(m_log, L"WebLogicFileReader::ReadConfigXml");
        SCX_LOGTRACE(m_log, 
                wstring(L"WebLogicFileReader::ReadConfigXml() - ").
                append(L"Reading the file: ").append(configXml.Get()));
        string xml;

        try {
            SCXHandle<istream> reader = 
                    OpenConfigXml(configXml.Get());
            GetStringFromStream(reader, xml);

            XElementPtr domainNode;
            XElement::Load(xml, domainNode);
            
            if (domainNode->GetName() == WEBLOGIC_DOMAIN_XML_NODE)
            {
                string version;
                ReadConfigXmlForVersion(domainNode, version);
                
                string adminServerName;
                ReadConfigXmlForAdminServerName(domainNode, adminServerName);
                
                XElementList serverNodes;
                domainNode->GetChildren(serverNodes);
                for (size_t index = 0; index < serverNodes.size(); ++index)
                {
                    if (serverNodes[index]->GetName() == WEBLOGIC_SERVER_XML_NODE)
                    {
                        bool isAdminServer = false;
                        bool isSslEnabled = false;
                        string name = "";
                        string httpPort = "";
                        string httpsPort = "";

                        XElementList childNodes;
                        serverNodes[index]->GetChildren(childNodes);
                        for (size_t j = 0; j < childNodes.size(); ++j)
                        {
                            /*
                             *   <server>
                             *     <name>new_ManagedServer_1</name>
                             *     <ssl>
                             *       <name>new_ManagedServer_1</name>
                             *       <enabled>true</enabled>
                             *       <listen-port>7513</listen-port>
                             *     </ssl>
                             *     <machine>new_UnixMachine_1</machine>
                             *     <listen-port>7013</listen-port>
                             *     <listen-address/>
                             *   </server>
                             * 
                             */
                            if (childNodes[j]->GetName() == WEBLOGIC_NAME_XML_NODE)
                            {
                                childNodes[j]->GetContent(name);
                                isAdminServer = adminServerName == name;                                       
                            } 
                            else if (childNodes[j]->GetName() == WEBLOGIC_SSL_XML_NODE)
                            {
                                ReadConfigXmlForSslInformation(
                                        childNodes[j],
                                        isSslEnabled,
                                        httpsPort);
                            } 
                            else if (childNodes[j]->GetName() == WEBLOGIC_LISTEN_PORT_XML_NODE)
                            {
                                childNodes[j]->GetContent(httpPort);
                            }                            
                        }
                        /*
                         * Having found the server node, 
                         * read the children
                         */
                        wstring wideName = StrFromUTF8(name);
                        SCXFilePath pathOnDisk;
                        pathOnDisk.SetDirectory(domainDir.Get());
                        pathOnDisk.AppendDirectory(WEBLOGIC_SERVERS_DIRECTORY);
                        pathOnDisk.AppendDirectory(wideName);

                        if (DoesServerDirectoryExist(pathOnDisk))
                        {
                            SCX_LOGTRACE(m_log, 
                                    wstring(L"WebLogicFileReader::ReadConfigXml() - ").
                                    append(L"Adding instance for ID='").append(pathOnDisk.Get()).
                                    append(L"'"));
                            // when the HTTP port is not set for the AdminServer,
                            // default to the default weblogic HTTP port (i.e. 7001)
                            wstring wideHttpPort = StrFromUTF8(httpPort);
                            if(isAdminServer && L"" == wideHttpPort)
                            {
                                wideHttpPort = DEFAULT_WEBLOGIC_HTTP_PORT;
                            }

                            // when the HTTPS port is not set, default to
                            // the default HTTPS port (i.e. 7002)
                            wstring wideHttpsPort = StrFromUTF8(httpsPort);
                            if(L"" == wideHttpsPort)
                            {
                                wideHttpsPort = DEFAULT_WEBLOGIC_HTTPS_PORT;
                            }
                        
                            wstring wideVersion = StrFromUTF8(version);
                        
                            SCXHandle<AppServerInstance> instance(
                                 new WebLogicAppServerInstance (
                                        pathOnDisk.GetDirectory()));
                        
                            instance->SetHttpPort(wideHttpPort);
                            instance->SetHttpsPort(wideHttpsPort);
                            instance->SetIsDeepMonitored(false, PROTOCOL_HTTPS);
                            instance->SetIsRunning(false);
                            instance->SetVersion(wideVersion);
                        
                            instance->SetServer(
                                    isAdminServer ?
                                            WEBLOGIC_SERVER_TYPE_ADMIN :
                                            WEBLOGIC_SERVER_TYPE_MANAGED);
                           
                            instances.push_back(instance);
                        }
                        else
                        {
                            SCX_LOGTRACE(m_log, 
                                    wstring(L"WebLogicFileReader::ReadConfigXml() - ").
                                    append(L"The directory (").append(pathOnDisk.Get()).
                                    append(L") does not exist on disk, ignoring this instance"));
                        }
                    }
                }
            }
        }
        catch (SCXFilePathNotFoundException&)
        {
            SCX_LOGERROR(m_log, 
                    wstring(L"WebLogicFileReader::ReadConfigXml() - ").
                    append(m_installationPath).append(L" - Could not find file: ").
                    append(configXml.Get()));
        }
        catch (SCXUnauthorizedFileSystemAccessException&)
        {
            SCX_LOGERROR(m_log, 
                    wstring(L"WebLogicFileReader::ReadConfigXml() - ").
                    append(m_installationPath).append(L" - not authorized to open file: ").
                    append(configXml.Get()));
        }
        catch (XmlException& x)
        {
            SCX_LOGERROR(m_log, 
                    wstring(L"WebLogicFileReader::ReadConfigXml() - ").
                    append(m_installationPath).append(L" - Could not load XML from file: ").
                    append(configXml.Get()));
        }
    }

    /*------------------------------------------------------------------*/
    /**
       Read the Admin Server Name 
       
              \param[in]  domainNode        domain node to read

              \param[out] adminServerName   discovered/parsed name
     */
    void WebLogicFileReader::ReadConfigXmlForAdminServerName(
            const XElementPtr& domainNode,
            string& adminServerName)
    {
        XElementList adminNodes;
        domainNode->GetChildren(adminNodes);
        for (size_t index = 0; index < adminNodes.size(); ++index)
        {
            if (adminNodes[index]->GetName() == WEBLOGIC_ADMIN_SERVER_XML_NODE)
            {
                adminNodes[index]->GetContent(adminServerName);
            }
        }    
    }
    
    /*------------------------------------------------------------------*/
    /**
       Read the SSL information from the config.xml 
       
              \param[in]  sslNode           SSL node to read.

              \param[out] sslEnabled        is SSL enabled
              
              \param[out] httpsPort         HTTPS Port discovered
     */
    void WebLogicFileReader::ReadConfigXmlForSslInformation(
            const XElementPtr& sslNode,
            bool& sslEnabled,
            string& httpsPort)
    {
        sslEnabled =false;
        httpsPort = "";
        
        XElementList sslChildrenNodes;
        sslNode->GetChildren(sslChildrenNodes);
        for (size_t index = 0; index < sslChildrenNodes.size(); ++index)
        {
            if (sslChildrenNodes[index]->GetName() == WEBLOGIC_SSL_ENABLED_XML_NODE)
            {
                wstring wide;
                sslChildrenNodes[index]->GetContent(wide);
                wide = StrToLower(wide);
                sslEnabled = TRUE_TEXT == wide;
            }
            else if (sslChildrenNodes[index]->GetName() == WEBLOGIC_LISTEN_PORT_XML_NODE)
            {
                 sslChildrenNodes[index]->GetContent(httpsPort);
            }
        }    
    }

    /*------------------------------------------------------------------*/
    /**
       Read the Admin Server Name 
       
              \param[in]  domainNode        domain node to read

              \param[out] version           discovered/parsed version
     */
    void WebLogicFileReader::ReadConfigXmlForVersion(
            const XElementPtr& domainNode,
            string& version)
    {
        XElementList versionNodes;
        domainNode->GetChildren(versionNodes);
        for (size_t index = 0; index < versionNodes.size(); ++index)
        {
            if (versionNodes[index]->GetName() == WEBLOGIC_VERSION_XML_NODE)
            {
                 versionNodes[index]->GetContent(version);
            }
        }    
    }
        
    /*------------------------------------------------------------------*/
    /**
       Read a simple XML file to find the locations of the domains for
       this WebLogic 11g R1 installation.
       
       Example:
       <?xml version="1.0" encoding="UTF-8"?>
       <domain-registry xmlns="http://xmlns.oracle.com/weblogic/domain-registry">
         <domain location="/opt/Oracle/Middleware/user_projects/domains/base_domain"/>
       </domain-registry> 
       
              \param[in]  domainRegistryXml File object of the XML file
                                            to open.
                                            
              \param[out] domains           vector that will contain the
                                            list of discovered domains.
     */
    void WebLogicFileReader::ReadDomainRegistryXml(
            const SCXFilePath& domainRegistryXml,
            vector<SCXFilePath>& domains)
    {
        string xml;

        try {
            SCXHandle<istream> reader = 
                    OpenDomainRegistryXml(domainRegistryXml.Get());
            GetStringFromStream(reader, xml);

            XElementPtr domainRegistryNode;
            XElement::Load(xml, domainRegistryNode);
            if (domainRegistryNode->GetName() == WEBLOGIC_DOMAIN_REGISTRY_XML_NODE)
            {
                XElementList domainNodes;
                domainRegistryNode->GetChildren(domainNodes);
                for (size_t index = 0; index < domainNodes.size(); ++index)
                {
                    string location;
                    if (domainNodes[index]->GetName() == WEBLOGIC_DOMAIN_XML_NODE && 
                        domainNodes[index]->GetAttributeValue(WEBLOGIC_LOCATION_XML_ATTRIBUTE, location))
                    {
                        wstring wideLocation = StrFromUTF8(location);
                        SCXFilePath domainPath;
                        domainPath.SetDirectory(wideLocation);                                
                        domains.push_back(domainPath);
                    }
                }
            }
        }
        catch (SCXFilePathNotFoundException&)
        {
            SCX_LOGERROR(m_log, 
                    wstring(L"WebLogicFileReader::ReadDomainRegistryXml() - ").
                    append(m_installationPath).append(L" - Could not find file: ").
                    append(domainRegistryXml.Get()));
        }
        catch (SCXUnauthorizedFileSystemAccessException&)
        {
            SCX_LOGERROR(m_log, 
                    wstring(L"WebLogicFileReader::ReadDomainRegistryXml() - ").
                    append(m_installationPath).append(L" - not authorized to open file: ").
                    append(domainRegistryXml.Get()));
        }
        catch (XmlException&)
        {
            SCX_LOGERROR(m_log, 
                    wstring(L"WebLogicFileReader::ReadDomainRegistryXml() - ").
                    append(m_installationPath).append(L" - Could not load XML from file: ").
                    append(domainRegistryXml.Get()));
        }
    }

    /*------------------------------------------------------------------*/
    /**
        Read the nodemanager.domains file to get a list of the
        WebLogic 10g domains associated with the installation.
           
        Note: this file is located up the tree in a 'well-known' location.
              i.e. /opt/Oracle/Middleware/wlserver_10.3/common/nodemanager/nodemanager.domains
       
       Example:
       #Domains and directories created by Configuration Wizard
       #Tue Apr 12 15:23:12 PDT 2011
       base_domain=/opt/Oracle/Middleware/user_projects/domains/base_domain 
       
       \param[in]  nodemanagerDomains File object of the text file
                                      to open.
                                            
       \param[out] domains           vector that will be populated with
                                     list of discovered domains.
       
     */
    void WebLogicFileReader::ReadNodemanagerDomains(
            const SCXFilePath& nodemanagerDomains,
            vector<SCXFilePath>& domains)
    {
        string content;

        try {
            
            /*
             * Parse the INI file. 
             * 
             * After a '#', assume the rest of the line is a comment.
             * The file should consist of name/value pairs seperated
             * by an '='. 
             */
            SCXHandle<istream> reader = 
                    OpenNodemanagerDomains(nodemanagerDomains.Get());
            
            while (SCXStream::IsGood(*reader))
            {
                string buffer;
                getline(*reader, buffer);
                
                size_t delimiterLocation = buffer.find(INI_DELIMITER);
                if (string::npos != delimiterLocation)
                {
                    string narrowPath = buffer.substr(delimiterLocation + 1);
                    wstring widePath = StrFromUTF8(narrowPath);
                    SCXFilePath domainPath;
                    domainPath.SetDirectory(widePath);
                    domains.push_back(domainPath);
                }
            }
        }
        catch (SCXFilePathNotFoundException&)
        {
            SCX_LOGERROR(m_log, 
                    wstring(L"WebLogicFileReader::ReadNodemanagerDomains() - ").
                    append(m_installationPath).append(L" - Could not find file: ").
                    append(nodemanagerDomains.Get()));
        }
        catch (SCXUnauthorizedFileSystemAccessException&)
        {
            SCX_LOGERROR(m_log, 
                    wstring(L"WebLogicFileReader::ReadNodemanagerDomains() - ").
                    append(m_installationPath).append(L" - not authorized to open file: ").
                    append(nodemanagerDomains.Get()));
        }
    }
    
    /*------------------------------------------------------------------*/
    /**
        Read all lines from a stream and save in a string

       \param[in]  reader   Stream to read from
       \param[out] content    String to return content in
    */
    void WebLogicFileReader::GetStringFromStream(
            SCXHandle<istream> reader, 
            string& content)
    {
        content = "";
        while (SCXStream::IsGood(*reader))
        {
            string buffer;
            getline(*reader, buffer);
            content.append(buffer);
            content.append("\n");
        }
    }

    /*------------------------------------------------------------------*/
    /**
        Read all lines from a stream and save in a string

       \param[in]  path         Full Path to an installation home 
    */
    void WebLogicFileReader::SetPath(const wstring& path)
    {
        m_installationPath = path;
    }
    
    /*------------------------------------------------------------------*/
    /**
       Constructor

    */   
    WebLogicAppServerEnumeration::WebLogicAppServerEnumeration(
            SCXHandle<IWebLogicFileReader> reader)
    {
        m_log = SCXLogHandleFactory::GetLogHandle(L"scx.core.common.pal.system.appserver.weblogicappserverenumeration");
        SCX_LOGTRACE(m_log, L"WebLogicAppServerEnumeration Constructor");

        m_reader = reader;
    }

    /*------------------------------------------------------------------*/
    /**
       Destructor

    */
    WebLogicAppServerEnumeration::~WebLogicAppServerEnumeration()
    {
        SCX_LOGTRACE(m_log, L"WebLogicAppServerEnumeration destructor");
    }

    /*------------------------------------------------------------------*/
    /**
       GetInstances

       \param[in]  installations    List of directories containing
                                    installs of WebLogic
       \param[out] result           output list of WebLogic application
                                    server instances

    */
    void WebLogicAppServerEnumeration::GetInstances(
        vector<wstring>& installations,
        vector<SCXHandle<AppServerInstance> >& result)
    {
        SCX_LOGTRACE(m_log, L"WebLogicAppServerEnumeration::GetInstances()");

        // the given list of installations has no guranteed ordering. Use the
        // STL to sort the incoming vector and find the unique instances.
        sort(installations.begin(), installations.end());
        vector<wstring>::iterator uniqueEnd = unique(installations.begin(), installations.end());
        installations.resize(uniqueEnd-installations.begin());

        // for each installation, add all discovered instances associated with that
        // installation and domain to the result set.
        result.clear();

        for (vector<wstring>::iterator installation = installations.begin();
                installation != installations.end();
                ++installation)
        {
            m_reader->SetPath(*installation);
            vector<SCXFilePath> domains = m_reader->GetDomains();
            
            for (vector<SCXFilePath>::iterator domain = domains.begin();
                    domain != domains.end();
                    ++domain)
            {
                SCX_LOGTRACE(m_log, 
                        wstring(L"WebLogicAppServerEnumeration::GetInstances() - ").
                        append(L"Searching for servers in the domain '").
                        append((*domain).Get()).append(L"'"));

                m_reader->GetInstances(*domain, result);
            }
        }
    }
}
/*----------------------------E-N-D---O-F---F-I-L-E---------------------------*/
