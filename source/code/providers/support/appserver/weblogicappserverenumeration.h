/*--------------------------------------------------------------------------------
    Copyright (c) Microsoft Corporation. All rights reserved. See license.txt for license information.
*/
/**
   \file        weblogicappserverenumeration.h

   \brief       Enumeration of weblogic application servers

   \date        11-05-18 12:00:00
*/
/*----------------------------------------------------------------------------*/
#ifndef WEBLOGICAPPSERVERENUMERATION_H
#define WEBLOGICAPPSERVERENUMERATION_H

#include <vector>

#include <scxsystemlib/entityenumeration.h>
#include <scxcorelib/scxlog.h>
#include <util/XElement.h>

#include "appserverconstants.h"
#include "weblogicappserverinstance.h"

namespace SCXSystemLib {
    /*--------------------------------------------------------*/
    /**
     Sort object for use with a comparison operation run against
     a vector of SCXFilePaths.
     */
    struct SortPath : 
        public std::binary_function<SCXCoreLib::SCXFilePath,
            SCXCoreLib::SCXFilePath, bool> {
            inline bool operator()(const SCXCoreLib::SCXFilePath& a,
                    const SCXCoreLib::SCXFilePath& b) {
                return a.Get() < b.Get();
            }
    };

    /*--------------------------------------------------------*/
    /**
     Class that represents an interface for accessing the filesystem
     of a WebLogic installation.
     
     */
    class IWebLogicFileReader {
        public:
            virtual ~IWebLogicFileReader() {};

            virtual std::vector<SCXCoreLib::SCXFilePath> GetDomains() = 0;

            /*--------------------------------------------------------*/
            /*
             * Get a list of instances associated with this installation
             * of WebLogic.
             * 
             */
            virtual void
                    GetInstances(
                            const SCXCoreLib::SCXFilePath& domain,
                            std::vector<
                                    SCXCoreLib::SCXHandle<AppServerInstance> >& instances) = 0;

            virtual void SetPath(const std::wstring& path) = 0;
    };

    /*--------------------------------------------------------------*/
    /**
     Class representing the piece of logic for obtaining the
     necessary information from the filesystem regarding files and
     directories about WebLogic installs.

     */
    class WebLogicFileReader: public IWebLogicFileReader {
        protected:

            std::wstring m_installationPath;

            /*
             * Handle for the class Logger
             */
            SCXCoreLib::SCXLogHandle m_log;

        public:
            WebLogicFileReader();

            virtual ~WebLogicFileReader() {};

            virtual std::vector<SCXCoreLib::SCXFilePath> GetDomains();

            virtual void
                    GetInstances(
                            const SCXCoreLib::SCXFilePath& domain,
                            std::vector<
                                    SCXCoreLib::SCXHandle<AppServerInstance> >& instances);

            virtual void SetPath(const std::wstring& path);

        protected:
            virtual bool
                    DoesConfigXmlExist(const SCXCoreLib::SCXFilePath& path);

            virtual bool DoesDomainRegistryXmlExist(
                    const SCXCoreLib::SCXFilePath& path);

            virtual bool DoesNodemanagerDomainsExist(
                    const SCXCoreLib::SCXFilePath& path);

            virtual bool DoesServerDirectoryExist(
                    const SCXCoreLib::SCXFilePath& path);

            virtual SCXCoreLib::SCXHandle<std::istream> OpenConfigXml(
                    const std::wstring& filename);

            virtual SCXCoreLib::SCXHandle<std::istream> OpenDomainRegistryXml(
                    const std::wstring& filename);

            virtual SCXCoreLib::SCXHandle<std::istream> OpenNodemanagerDomains(
                    const std::wstring& filename);

            void
                    ReadConfigXml(
                            const SCXCoreLib::SCXFilePath& domainDir,
                            const SCXCoreLib::SCXFilePath& configXml,
                            std::vector<
                                    SCXCoreLib::SCXHandle<AppServerInstance> >& instances);

            /*-------------------------------------------------------------*/
            /**
             Read the domain-registry.xml file to get a list of the
             WebLogic 11g domains associated with the installation.
             
             Note: this file is located in the base installation folder
             i.e. /opt/Oracle/Middleware/domain-registry.xml
             */
            void ReadDomainRegistryXml(
                    const SCXCoreLib::SCXFilePath& domainRegistryXml,
                    std::vector<SCXCoreLib::SCXFilePath>& domains);

            /*-------------------------------------------------------------*/
            /**
             Read the nodemanager.domains file to get a list of the
             WebLogic 10g domains associated with the installation.
             
             Note: this file is located up the tree in a 'well-known'
             location.
             i.e. /opt/Oracle/Middleware/wlserver_10.3/common/nodemanager/nodemanager.domains
             
             */
            void ReadNodemanagerDomains(
                    const SCXCoreLib::SCXFilePath& domainRegistryXml,
                    std::vector<SCXCoreLib::SCXFilePath>& domains);

        private:
            void GetStringFromStream(
                    SCXCoreLib::SCXHandle<std::istream> mystream,
                    std::string& content);

            void ReadConfigXmlForAdminServerName(
                    const SCX::Util::Xml::XElementPtr& domainNode,
                    std::string& adminServerName);

            void ReadConfigXmlForSslInformation(
                    const SCX::Util::Xml::XElementPtr& sslNode,
                    bool& sslEnabled, string& httpsPort);

            void ReadConfigXmlForVersion(
                    const SCX::Util::Xml::XElementPtr& domainNode,
                    std::string& version);
    };

    /*--------------------------------------------------------------*/
    /**
     Class that given a set of directories, will review each on for 
     the appropriate XML files that describe Admin and Managed 
     WebLogic servers.

     On WebLogic 11gR1, the expectation is that the path given is 
     the location of the installation. From this location there is
     a XML file domain-registry.xml that contains a list of the 
     domains. For each of these domains, it is then necessary
     to location the config/config.xml file that has the XML blob
     to parse.

     <domain ... >
     <name>base_domain</name>
     <domain-version>10.3.2.0</domain-version>
     <security-configuration ... >
     <name>base_domain</name>
     ...
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
     ...
     </domain>

     On WebLogic 10gR3, the configuration file is the same; however,
     the name/format/location of the file containing the domains
     is different. The file to look for is a INI file (i.e. text
     file of name/value pairs) located in the 'well-known' location.
     
     ${root}/wlserver_10.3/common/nodemanager/nodemanager.domains
     
     */
    class WebLogicAppServerEnumeration {
        public:
            WebLogicAppServerEnumeration(SCXCoreLib::SCXHandle<
                    IWebLogicFileReader>);

            virtual ~WebLogicAppServerEnumeration();

            void
                    GetInstances(
                            std::vector<std::wstring>& installations,
                            std::vector<
                                    SCXCoreLib::SCXHandle<AppServerInstance> >& result);

        protected:
            /*
             * Filesystem abstraction for interacting with XML and Text
             * Configuration files.
             */
            SCXCoreLib::SCXHandle<IWebLogicFileReader> m_reader;

        private:

            /*
             * Handle for the class Logger
             */
            SCXCoreLib::SCXLogHandle m_log;
    };

}

#endif /* WEBLOGICAPPSERVERENUMERATION_H */
/*----------------------------E-N-D---O-F---F-I-L-E---------------------------*/
