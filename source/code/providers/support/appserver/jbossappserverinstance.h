/*--------------------------------------------------------------------------------
  Copyright (c) Microsoft Corporation. All rights reserved. See license.txt for license information.
*/
/**
   \file        jbossappserverinstance.h

   \brief       PAL representation of a JBoss Application Server

   \date        11-05-18 12:00:00
*/
/*----------------------------------------------------------------------------*/
#ifndef JBOSSAPPSERVERINSTANCE_H
#define JBOSSAPPSERVERINSTANCE_H

#include <string>

#include "appserverinstance.h"

namespace SCXSystemLib
{
    /*----------------------------------------------------------------------------*/
    /**
       Class representing all external dependencies from the AppServer PAL.

    */
	typedef enum {
		jboss_version_7,
		jboss_version_8
	} jboss_version_type;
    class JBossAppServerInstancePALDependencies
    {
    public:
        virtual SCXCoreLib::SCXHandle<std::istream> OpenXmlVersionFile(std::wstring filename);
        virtual SCXCoreLib::SCXHandle<std::istream> OpenXmlPortsFile(std::wstring filename);
        virtual SCXCoreLib::SCXHandle<std::istream> OpenXmlServiceFile(std::wstring filename);
        virtual SCXCoreLib::SCXHandle<std::istream> OpenXmlServerFile(std::wstring filename);
        virtual SCXCoreLib::SCXHandle<std::istream> OpenXmlBindingFile(std::wstring filename);
		virtual SCXCoreLib::SCXHandle<std::istream> OpenDomainHostXmlFile(std::wstring filename);
		virtual SCXCoreLib::SCXHandle<std::istream> OpenDomainXmlFile(std::wstring filename);
		virtual SCXCoreLib::SCXHandle<std::istream> OpenModuleXmlFile (std::wstring filename);
		virtual bool versionJBossWildfly(SCXCoreLib::SCXFilePath filepath, jboss_version_type &version);
        virtual ~JBossAppServerInstancePALDependencies() {};
    };

    /*----------------------------------------------------------------------------*/
    /**
       Class that represents an instances.

       Concrete implementation of an instance of a JBoss Application Server

    */
    class JBossAppServerInstance : public AppServerInstance
    {
        friend class AppServerEnumeration;

	public:
        JBossAppServerInstance(
            std::wstring id, 
            std::wstring config,
            std::wstring portsBinding,
            SCXCoreLib::SCXHandle<JBossAppServerInstancePALDependencies> deps = SCXCoreLib::SCXHandle<JBossAppServerInstancePALDependencies>(new JBossAppServerInstancePALDependencies()));
        JBossAppServerInstance(
            std::wstring diskPath,
            SCXCoreLib::SCXHandle<JBossAppServerInstancePALDependencies> deps = SCXCoreLib::SCXHandle<JBossAppServerInstancePALDependencies>(new JBossAppServerInstancePALDependencies()));
        virtual ~JBossAppServerInstance();

        virtual void Update();

    private:
        void UpdateVersion();
        void UpdateJBoss4PortsFromServiceBinding(std::wstring filename, std::string servername);
        void UpdateJBoss4PortsFromServerConfiguration();
        void UpdateJBoss4Ports();
        void UpdateJBoss5Ports();
        void UpdateJBoss7Ports();
        void GetStringFromStream(SCXCoreLib::SCXHandle<std::istream> mystream, std::string& content);
        void TryReadInteger(unsigned int& result, bool& found, const std::wstring& value, const std::wstring& errorText);
		
		std::vector<std::wstring> GetJBossWildflyServerHostXmlInformation();
        std::wstring m_config;
        std::wstring m_serverName;
        std::wstring m_basePath;
        std::wstring m_portsBinding;

        SCXCoreLib::SCXHandle<JBossAppServerInstancePALDependencies> m_deps;
    };

}

#endif /* JBOSSAPPSERVERINSTANCE_H */
/*----------------------------E-N-D---O-F---F-I-L-E---------------------------*/
