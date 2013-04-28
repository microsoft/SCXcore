/*-----------------------------------------------------------------------
 Copyright (c) Microsoft Corporation.  All rights reserved.
 */
/**
 \file        appserverconstants.h

 \brief       Constants associated with the various application
 servers

 \date        11-08-19 12:00:00
 */
/*-----------------------------------------------------------------------*/
#ifndef APPSERVERCONSTANTS_H
#define APPSERVERCONSTANTS_H

#include <string>

namespace SCXSystemLib {
    /*-------------------------------------------------------------------*/
    //
    // Generic Provider Constants
    //
    /*-------------------------------------------------------------------*/

    const static std::wstring PROTOCOL_HTTP = L"HTTP";

    const static std::wstring PROTOCOL_HTTPS = L"HTTPS";

    const static std::wstring APP_SERVER_TYPE_JBOSS = L"JBoss";

    const static std::wstring APP_SERVER_TYPE_TOMCAT = L"Tomcat";

    const static std::wstring APP_SERVER_TYPE_WEBLOGIC = L"WebLogic";

    const static std::wstring APP_SERVER_TYPE_WEBSPHERE = L"WebSphere";

    /*-------------------------------------------------------------------*/
    //
    // Generic File Reading Constants
    //
    /*-------------------------------------------------------------------*/

    const static std::wstring EMPTY_STRING = L"";

    const static std::string INI_COMMENT = "#";

    const static std::string INI_DELIMITER = "=";

    const static std::wstring TRUE_TEXT = L"true";

    /*-------------------------------------------------------------------*/
    //
    // WebLogic Constants
    //
    /*-------------------------------------------------------------------*/

    const static std::wstring DEFAULT_WEBLOGIC_HTTP_PORT = L"7001";

    const static std::wstring DEFAULT_WEBLOGIC_HTTPS_PORT = L"7002";

    const static std::string WEBLOGIC_ADMIN_SERVER_NAME = "AdminServer";

    const static std::string WEBLOGIC_ADMIN_SERVER_XML_NODE = "admin-server-name";    

    const static std::wstring WEBLOGIC_BRANDED_VERSION_10 = L"10";

    const static std::wstring WEBLOGIC_BRANDED_VERSION_11 = L"11";

    const static std::wstring WEBLOGIC_CONFIG_DIRECTORY = L"config/";

    const static std::wstring WEBLOGIC_CONFIG_FILENAME = L"config.xml";

    const static std::string WEBLOGIC_DOMAIN_ADMIN_SERVER_NAME = "domain-admin-server-name";

    const static std::wstring WEBLOGIC_DOMAIN_REGISTRY_XML_FILENAME = L"domain-registry.xml";

    const static std::string WEBLOGIC_DOMAIN_REGISTRY_XML_NODE = "domain-registry";

    const static std::string WEBLOGIC_DOMAIN_XML_NODE = "domain";

    const static std::string WEBLOGIC_DOMAIN_VERSION_XML_NODE = "domain-version";

    const static std::string WEBLOGIC_LISTEN_PORT_XML_NODE = "listen-port";

    const static std::string WEBLOGIC_LOCATION_XML_ATTRIBUTE = "location";

    const static std::string WEBLOGIC_NAME_XML_NODE = "name";

    const static std::wstring WEBLOGIC_NODEMANAGER_DOMAINS_DIRECTORY = L"/wlserver_10.3/common/nodemanager/";

    const static std::wstring WEBLOGIC_NODEMANAGER_DOMAINS_FILENAME = L"nodemanager.domains";

    const static std::wstring WEBLOGIC_SERVERS_DIRECTORY = L"servers";

    const static std::wstring WEBLOGIC_SERVER_TYPE_ADMIN = L"Admin";

    const static std::wstring WEBLOGIC_SERVER_TYPE_MANAGED = L"Managed";

    const static std::string WEBLOGIC_SERVER_XML_NODE = "server";

    const static std::string WEBLOGIC_SSL_XML_NODE = "ssl";

    const static std::string WEBLOGIC_SSL_ENABLED_XML_NODE = "enabled";

    const static std::string WEBLOGIC_VERSION_XML_NODE = "domain-version";

    const static unsigned int WEBLOGIC_VERSION_MINOR = 3;

    /*
     * This class should not be used, it exists so the constants
     * file will compile properly.
     */
    class AppServerConstants
    {
    public:

        AppServerConstants() {};

        virtual ~AppServerConstants() {};
    };

}

#endif /* APPSERVERCONSTANTS_H */
/*----------------------------E-N-D---O-F---F-I-L-E---------------------------*/
