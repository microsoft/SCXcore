/*---------------------------------------------------------
 Copyright (c) Microsoft Corporation.  All rights reserved.
 */
/**
 \file        weblogicappserverenumeration_test.h

 \brief       Tests for the logic of enumerating
 WebLogic application servers

 \date        11-08-18 12:00:00

 */

/*------------------------------------------------------*/
#include <scxcorelib/scxcmn.h>
#include <scxcorelib/stringaid.h>
#include <scxcorelib/scxfilesystem.h>
#include <scxcorelib/scxlog.h>
#include <testutils/scxunit.h>

#include <appserverconstants.h>
#include <appserverinstance.h>
#include <weblogicappserverenumeration.h>
#include <weblogicappserverinstance.h>

#include <cppunit/extensions/HelperMacros.h>

#include <iostream>

using namespace SCXCoreLib;
using namespace SCXSystemLib;
using namespace std;

namespace SCXUnitTests {

    const static size_t zeroSize = 0;
    const static size_t oneSize = 1;
    const static size_t twoSize = 2;
    const static size_t threeSize = 3;
    const static size_t fourSize = 4;

    const static wstring WEBLOGIC_MAJOR_VERSION_10 = L"10";
    const static wstring WEBLOGIC_MAJOR_VERSION_11 = L"11";

    const static wstring WEBLOGIC_VERSION_10 = L"10.3.0.0";
    const static wstring WEBLOGIC_VERSION_11 = L"10.3.2.0";

    const static wstring MOCK_WEBLOGIC_PROTOCOL = PROTOCOL_HTTPS;
    const static wstring MOCK_WEBLOGIC_ADMIN_HTTP_PORT = L"7011";
    const static wstring MOCK_WEBLOGIC_ADMIN_HTTPS_PORT = L"7012";
    const static wstring MOCK_WEBLOGIC_MANAGED_HTTP_PORT = L"7013";
    const static wstring MOCK_WEBLOGIC_MANAGED_HTTPS_PORT = L"7513";

    const static wstring WEBLOGIC_DEFAULT_INSTALLATION_PATH =
          L"/opt/Oracle/WebLogic-11/Middleware/";
    const static wstring WEBLOGIC_DEFAULT_DOMAIN_PATH =
          L"/opt/Oracle/WebLogic-11/Middleware/user_projects/domains/base_domain/";
    const static wstring WEBLOGIC_DEFAULT_ADMIN_SERVER_PATH =
          L"/opt/Oracle/WebLogic-11/Middleware/user_projects/domains/base_domain/servers/AdminServer/";
    const static wstring WEBLOGIC_DEFAULT_MANAGED_SERVER_PATH =
          L"/opt/Oracle/WebLogic-11/Middleware/user_projects/domains/base_domain/servers/new_ManagedServer_1/";

    const static wstring WEBLOGIC_OTHER_INSTALLATION_PATH =
          L"/opt/Oracle/WebLogic-11-testbed/Middleware/";
    const static wstring WEBLOGIC_OTHER_DOMAIN_PATH =
          L"/opt/Oracle/WebLogic-11-testbed/Middleware/user_projects/domains/base_domain/";
    const static wstring WEBLOGIC_OTHER_ADMIN_SERVER_PATH =
          L"/opt/Oracle/WebLogic-11-testbed/Middleware/user_projects/domains/base_domain/servers/AdminServer/";
    const static wstring WEBLOGIC_OTHER_MANAGED_SERVER_PATH =
          L"/opt/Oracle/WebLogic-11-testbed/Middleware/user_projects/domains/base_domain/servers/new_ManagedServer_1/";


/*
 * Unit Test mock implementation for a file reader that 
 * has a both the domain-registry.xml file for WebLogic 11 
 * as well as a nodemanger.domains for WebLogic 10; however,
 * both files are empty
 */
class EmptyDomainFiles : public WebLogicFileReader
{
public:
    EmptyDomainFiles() :
        WebLogicFileReader() 
        {
            m_installationPath = WEBLOGIC_DEFAULT_INSTALLATION_PATH;
        };

    virtual ~EmptyDomainFiles() {};
    
protected:
    virtual bool DoesDomainRegistryXmlExist(const SCXFilePath& /*path*/)
    {
        return true;
    }

    virtual bool DoesNodemanagerDomainsExist(const SCXFilePath& /*path*/)
    {
        return true;
    }
    
    virtual bool DoesServerDirectoryExist(const SCXFilePath& /*path*/)
    {
        return true;
    }
    
    /*
     * This function should never be called because the domain files
     * do not exist.
     */
    virtual SCXHandle<istream> OpenConfigXml(const wstring&)
    {
        throw 404;
    }
    
    /*
     * Helper Method to Mock out the returned domain-registry.xml
     * for WebLogic 11g R1.
     * 
     * <?xml version="1.0" encoding="UTF-8"?>
     * <domain-registry xmlns="http://xmlns.oracle.com/weblogic/domain-registry">
     * </domain-registry>
     * 
     */
    virtual SCXHandle<istream> OpenDomainRegistryXml(const wstring&)
    {
        SCXHandle<stringstream> xmlcontent( new stringstream );

        *xmlcontent << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl;
        *xmlcontent << "<domain-registry xmlns=\"http://xmlns.oracle.com/weblogic/domain-registry\">" << endl;
        *xmlcontent << "</domain-registry>" << endl;

        return xmlcontent;
    }
    
    /*
     * Helper Method to Mock out the returned nodemanager.domains
     * for WebLogic 10g R3. Note that the first domain appears in both
     * the domain-registry.xml as well as the older nodemanager.domains
     * file.
     * 
     * #Domains and directories created by Configuration Wizard
     * #Tue Apr 12 15:23:12 PDT 2011
     * 
     * Note: It is not clear if this can exist using the Oracle tools;
     * however, theoritcally a user code modify the files to look like
     * this (unclear if WebLogic would still run).
     */
    virtual SCXHandle<istream> OpenNodemanagerDomains(const wstring&)
    {
        SCXHandle<stringstream> content( new stringstream );

        *content << "#Domains and directories created by Configuration Wizard" << endl;
        *content << "#Tue Apr 12 15:23:12 PDT 2011" << endl;

        return content;
    }
};

/*
 * Unit Test mock implementation for a file reader that 
 * has a missing domain-registry.xml file for WebLogic 11 
 * as well as a missing nodemanger.domains for WebLogic 10
 */
class MissingDomainFiles : public WebLogicFileReader
{
public:
    MissingDomainFiles() :
        WebLogicFileReader() 
    {
        m_installationPath = WEBLOGIC_DEFAULT_INSTALLATION_PATH;
    };

    virtual ~MissingDomainFiles() {};

protected:
    virtual bool DoesDomainRegistryXmlExist(const SCXFilePath& /*path*/)
    {
        return false;
    }
    
    virtual bool DoesNodemanagerDomainsExist(const SCXFilePath& /*path*/)
    {
        return false;
    }

    /*
     * This function should never be called because the domain files
     * do not exist.
     */
    virtual SCXHandle<istream> OpenConfigXml(const wstring&)
    {
        throw 404;
    }

    /*
     * Helper Method to Mock out the returned domain-registry.xml
     * for WebLogic 11g R1.
     * 
     * This method should never get called because another method
     * for checking the file existence is hard-coded to false. To
     * be safe the function throws an exception.
     */
    virtual SCXHandle<istream> OpenDomainRegistryXml(const wstring&)
    {
        throw 404;
    }

    /*
     * Helper Method to Mock out the returned nodemanager.domains
     * for WebLogic 10g R3.
     */
    virtual SCXHandle<istream> OpenNodemanagerDomains(const wstring&)
    {
        throw 404;
    }
};

/*
 * Unit Test mock implementation for a file reader that has one
 * entry in the nodemanager.domains file. This in
 * turn points a simple installation that only has one Admin
 * Server and one managed server. The config.xml does not list
 * ports for HTTP or HTTPS for the Admin server - this implies
 * that the defaults are to be used. The Managed server does NOT
 * have SSL configured.
 */
class StandardWebLogic10 : public WebLogicFileReader
{
    
public:
    StandardWebLogic10() :
        WebLogicFileReader() 
        {
            m_installationPath = WEBLOGIC_DEFAULT_INSTALLATION_PATH;
        };
    
    virtual ~StandardWebLogic10() {};

protected:
    virtual bool DoesConfigXmlExist(const SCXFilePath& /*path*/)
    {
        return true;
    }

    virtual bool DoesDomainRegistryXmlExist(const SCXFilePath& /*path*/)
    {
        return false;
    }

    /*
     * For an 11g installation, this file exists, but is empty
     */
    virtual bool DoesNodemanagerDomainsExist(const SCXFilePath& /*path*/)
    {
        return true;
    }

    virtual bool DoesServerDirectoryExist(const SCXFilePath& /*path*/)
    {
        return true;
    }

    /*
     * Helper Method to Mock out the returned domain-registry.xml
     * for WebLogic 11g R1.
     * 
     * <?xml version="1.0" encoding="UTF-8"?>
     * <domain-registry xmlns="http://xmlns.oracle.com/weblogic/domain-registry">
     *   <domain location="/opt/Oracle/WebLogic-11/Middleware/user_projects/domains/base_domain"/>
     * </domain-registry>
     * 
     */
    virtual SCXHandle<istream> OpenConfigXml(const wstring&)
    {
        SCXHandle<stringstream> xmlcontent( new stringstream );

        *xmlcontent << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl;
        *xmlcontent << "<domain xsi:schemaLocation=\"http://xmlns.oracle.com/weblogic/security/wls http://xmlns.oracle.com/weblogic/security/wls/1.0/wls.xsd http://xmlns.oracle.com/weblogic/domain http://xmlns.oracle.com/weblogic/1.0/domain.xsdhttp://xmlns.oracle.com/weblogic/security http://xmlns.oracle.com/weblogic/1.0/security.xsd http://xmlns.oracle.com/weblogic/security/xacml http://xmlns.oracle.com/weblogic/security/xacml/1.0/xacml.xsd\" xmlns=\"http://xmlns.oracle.com/weblogic/domain\" xmlns:sec=\"http://xmlns.oracle.com/weblogic/security\" xmlns:wls=\"http://xmlns.oracle.com/weblogic/security/wls\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\">" << endl;
        *xmlcontent << "  <name>base_domain</name>" << endl;
        *xmlcontent << "  <domain-version>10.3.0.0</domain-version>" << endl;
        *xmlcontent << "  <security-configuration xmlns:xacml=\"http://xmlns.oracle.com/weblogic/security/xacml\" xmlns:pas=\"http://xmlns.oracle.com/weblogic/security/providers/passwordvalidator\">" << endl;
        *xmlcontent << "    <name>base_domain</name>" << endl;
        *xmlcontent << "    <realm>" << endl;
        *xmlcontent << "      <sec:authentication-provider xsi:type=\"wls:default-authenticatorType\"/>" << endl;
        *xmlcontent << "      <sec:authentication-provider xsi:type=\"wls:default-identity-asserterType\">" << endl;
        *xmlcontent << "        <sec:active-type>AuthenticatedUser</sec:active-type>" << endl;
        *xmlcontent << "      </sec:authentication-provider>" << endl;
        *xmlcontent << "      <sec:role-mapper xsi:type=\"xacml:xacml-role-mapperType\"/>" << endl;
        *xmlcontent << "      <sec:authorizer xsi:type=\"xacml:xacml-authorizerType\"/>" << endl;
        *xmlcontent << "      <sec:adjudicator xsi:type=\"wls:default-adjudicatorType\"/>" << endl;
        *xmlcontent << "      <sec:credential-mapper xsi:type=\"wls:default-credential-mapperType\"/>" << endl;
        *xmlcontent << "      <sec:cert-path-provider xsi:type=\"wls:web-logic-cert-path-providerType\"/>" << endl;
        *xmlcontent << "      <sec:cert-path-builder>WebLogicCertPathProvider</sec:cert-path-builder>" << endl;
        *xmlcontent << "      <sec:name>myrealm</sec:name>" << endl;
        *xmlcontent << "      <sec:password-validator xsi:type=\"pas:system-password-validatorType\">" << endl;
        *xmlcontent << "        <sec:name>SystemPasswordValidator</sec:name>" << endl;
        *xmlcontent << "        <pas:min-password-length>8</pas:min-password-length>" << endl;
        *xmlcontent << "        <pas:min-numeric-or-special-characters>1</pas:min-numeric-or-special-characters>" << endl;
        *xmlcontent << "      </sec:password-validator>" << endl;
        *xmlcontent << "    </realm>" << endl;
        *xmlcontent << "    <default-realm>myrealm</default-realm>" << endl;
        *xmlcontent << "    <credential-encrypted>{AES}ukCl5R/HDunoQwvIelAh5RX2I3zdmYFyrOGhXXa58ViNkM7JwYElmg8PzGwsiPPpVzMIpA95L0EL+sEGOkr3GEjAixsVy4XbRZD09wH+jxkH/6JeOoRIgIfYy364gHHC</credential-encrypted>" << endl;
        *xmlcontent << "    <node-manager-username>weblogic</node-manager-username>" << endl;
        *xmlcontent << "    <node-manager-password-encrypted>{AES}PnV58TDPVejTkKti4bUbES0JCzwOfBDnEcdnwsM9Z48=</node-manager-password-encrypted>" << endl;
        *xmlcontent << "  </security-configuration>" << endl;
        *xmlcontent << "  <server>" << endl;
        *xmlcontent << "    <name>AdminServer</name>" << endl;
        *xmlcontent << "    <ssl>" << endl;
        *xmlcontent << "      <name>AdminServer</name>" << endl;
        *xmlcontent << "      <enabled>true</enabled>" << endl;
        *xmlcontent << "    </ssl>" << endl;
        *xmlcontent << "    <machine>new_UnixMachine_1</machine>" << endl;
        *xmlcontent << "    <listen-address/>" << endl;
        *xmlcontent << "  </server>" << endl;
        *xmlcontent << "  <server>" << endl;
        *xmlcontent << "    <name>new_ManagedServer_1</name>" << endl;
        *xmlcontent << "    <machine>new_UnixMachine_1</machine>" << endl;
        *xmlcontent << "    <listen-port>7013</listen-port>" << endl;
        *xmlcontent << "    <listen-address/>" << endl;
        *xmlcontent << "  </server>" << endl;
        *xmlcontent << "  <embedded-ldap>" << endl;
        *xmlcontent << "    <name>base_domain</name>" << endl;
        *xmlcontent << "    <credential-encrypted>{AES}RVX+Cadq8XJ5EvV7/1Ta2qGZrJlxve6t5CEa2A9euGUkYOMDTAwAqytymqDBS00Q</credential-encrypted>" << endl;
        *xmlcontent << "  </embedded-ldap>" << endl;
        *xmlcontent << "  <configuration-version>10.3.0.0</configuration-version>" << endl;
        *xmlcontent << "  <machine xsi:type=\"unix-machineType\">" << endl;
        *xmlcontent << "    <name>new_UnixMachine_1</name>" << endl;
        *xmlcontent << "    <node-manager>" << endl;
        *xmlcontent << "      <name>new_UnixMachine_1</name>" << endl;
        *xmlcontent << "      <listen-address>localhost</listen-address>" << endl;
        *xmlcontent << "      <listen-port>5566</listen-port>" << endl;
        *xmlcontent << "    </node-manager>" << endl;
        *xmlcontent << "  </machine>" << endl;
        *xmlcontent << "  <admin-server-name>AdminServer</admin-server-name>" << endl;
        *xmlcontent << "</domain>" << endl;

        return xmlcontent;
    }

    /*
     * Helper Method to Mock out the returned domain-registry.xml.
     * This file does not exist on WebLogic 10, so the mock object
     * will throw an exception.
     */
    virtual SCXHandle<istream> OpenDomainRegistryXml(const wstring&)
    {
        throw 404;
    }

    /*
     * Helper Method to Mock out the returned nodemanager.domains
     * for WebLogic 10g R3. Note that the first domain appears in both
     * the domain-registry.xml as well as the older nodemanager.domains
     * file.
     * 
     * #Domains and directories created by Configuration Wizard
     * #Tue Apr 12 15:23:12 PDT 2011
     * base_domain=/opt/Oracle/WebLogic-11/Middleware/user_projects/domains/base_domain
     * 
     */
    virtual SCXHandle<istream> OpenNodemanagerDomains(const wstring&)
    {
        SCXHandle<stringstream> content( new stringstream );

        *content << "#Domains and directories created by Configuration Wizard" << endl;
        *content << "#Tue Apr 12 15:23:12 PDT 2011" << endl;
        *content << "base_domain=/opt/Oracle/WebLogic-11/Middleware/user_projects/domains/base_domain" << endl;

        return content;
    }   
};

/*
 * Unit Test mock implementation for a file reader that has one
 * entry in the domain-registry.xml file for WebLogic 11. This in
 * turn points to a simple installation that only has one Admin
 * Server.
 * 
 * In essense, this would be the case if a discovery were run on
 * a WebLogic that had just been installed. 
 */
class StandardWebLogic11 : public WebLogicFileReader
{
    
public:
    StandardWebLogic11() :
        WebLogicFileReader() 
        {
            m_installationPath = WEBLOGIC_DEFAULT_INSTALLATION_PATH;
        };
    
    virtual ~StandardWebLogic11() {};

protected:
    virtual bool DoesConfigXmlExist(const SCXFilePath& /*path*/)
    {
        return true;
    }

    virtual bool DoesDomainRegistryXmlExist(const SCXFilePath& /*path*/)
    {
        return true;
    }

    /*
     * For an 11g installation, this file exists, but is empty
     */
    virtual bool DoesNodemanagerDomainsExist(const SCXFilePath& /*path*/)
    {
        return true;
    }
    
    virtual bool DoesServerDirectoryExist(const SCXFilePath& /*path*/)
    {
        return true;
    }

    /*
     * Helper Method to Mock out the returned domain-registry.xml
     * for WebLogic 11g R1.
     * 
     * <?xml version="1.0" encoding="UTF-8"?>
     * <domain-registry xmlns="http://xmlns.oracle.com/weblogic/domain-registry">
     *   <domain location="/opt/Oracle/WebLogic-11/Middleware/user_projects/domains/base_domain"/>
     * </domain-registry>
     * 
     */
    virtual SCXHandle<istream> OpenConfigXml(const wstring&)
    {
        SCXHandle<stringstream> xmlcontent( new stringstream );

        *xmlcontent << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl;
        *xmlcontent << "<domain xsi:schemaLocation=\"http://xmlns.oracle.com/weblogic/security/wls http://xmlns.oracle.com/weblogic/security/wls/1.0/wls.xsd http://xmlns.oracle.com/weblogic/domain http://xmlns.oracle.com/weblogic/1.0/domain.xsdhttp://xmlns.oracle.com/weblogic/security http://xmlns.oracle.com/weblogic/1.0/security.xsd http://xmlns.oracle.com/weblogic/security/xacml http://xmlns.oracle.com/weblogic/security/xacml/1.0/xacml.xsd\" xmlns=\"http://xmlns.oracle.com/weblogic/domain\" xmlns:sec=\"http://xmlns.oracle.com/weblogic/security\" xmlns:wls=\"http://xmlns.oracle.com/weblogic/security/wls\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\">" << endl;
        *xmlcontent << "  <name>base_domain</name>" << endl;
        *xmlcontent << "  <domain-version>10.3.2.0</domain-version>" << endl;
        *xmlcontent << "  <security-configuration xmlns:xacml=\"http://xmlns.oracle.com/weblogic/security/xacml\" xmlns:pas=\"http://xmlns.oracle.com/weblogic/security/providers/passwordvalidator\">" << endl;
        *xmlcontent << "    <name>base_domain</name>" << endl;
        *xmlcontent << "    <realm>" << endl;
        *xmlcontent << "      <sec:authentication-provider xsi:type=\"wls:default-authenticatorType\"/>" << endl;
        *xmlcontent << "      <sec:authentication-provider xsi:type=\"wls:default-identity-asserterType\">" << endl;
        *xmlcontent << "        <sec:active-type>AuthenticatedUser</sec:active-type>" << endl;
        *xmlcontent << "      </sec:authentication-provider>" << endl;
        *xmlcontent << "      <sec:role-mapper xsi:type=\"xacml:xacml-role-mapperType\"/>" << endl;
        *xmlcontent << "      <sec:authorizer xsi:type=\"xacml:xacml-authorizerType\"/>" << endl;
        *xmlcontent << "      <sec:adjudicator xsi:type=\"wls:default-adjudicatorType\"/>" << endl;
        *xmlcontent << "      <sec:credential-mapper xsi:type=\"wls:default-credential-mapperType\"/>" << endl;
        *xmlcontent << "      <sec:cert-path-provider xsi:type=\"wls:web-logic-cert-path-providerType\"/>" << endl;
        *xmlcontent << "      <sec:cert-path-builder>WebLogicCertPathProvider</sec:cert-path-builder>" << endl;
        *xmlcontent << "      <sec:name>myrealm</sec:name>" << endl;
        *xmlcontent << "      <sec:password-validator xsi:type=\"pas:system-password-validatorType\">" << endl;
        *xmlcontent << "        <sec:name>SystemPasswordValidator</sec:name>" << endl;
        *xmlcontent << "        <pas:min-password-length>8</pas:min-password-length>" << endl;
        *xmlcontent << "        <pas:min-numeric-or-special-characters>1</pas:min-numeric-or-special-characters>" << endl;
        *xmlcontent << "      </sec:password-validator>" << endl;
        *xmlcontent << "    </realm>" << endl;
        *xmlcontent << "    <default-realm>myrealm</default-realm>" << endl;
        *xmlcontent << "    <credential-encrypted>{AES}ukCl5R/HDunoQwvIelAh5RX2I3zdmYFyrOGhXXa58ViNkM7JwYElmg8PzGwsiPPpVzMIpA95L0EL+sEGOkr3GEjAixsVy4XbRZD09wH+jxkH/6JeOoRIgIfYy364gHHC</credential-encrypted>" << endl;
        *xmlcontent << "    <node-manager-username>weblogic</node-manager-username>" << endl;
        *xmlcontent << "    <node-manager-password-encrypted>{AES}PnV58TDPVejTkKti4bUbES0JCzwOfBDnEcdnwsM9Z48=</node-manager-password-encrypted>" << endl;
        *xmlcontent << "  </security-configuration>" << endl;
        *xmlcontent << "  <server>" << endl;
        *xmlcontent << "    <name>AdminServer</name>" << endl;
        *xmlcontent << "    <ssl>" << endl;
        *xmlcontent << "      <name>AdminServer</name>" << endl;
        *xmlcontent << "      <enabled>true</enabled>" << endl;
        *xmlcontent << "      <listen-port>7012</listen-port>" << endl;
        *xmlcontent << "    </ssl>" << endl;
        *xmlcontent << "    <machine>new_UnixMachine_1</machine>" << endl;
        *xmlcontent << "    <listen-port>7011</listen-port>" << endl;
        *xmlcontent << "    <listen-address/>" << endl;
        *xmlcontent << "  </server>" << endl;
        *xmlcontent << "  <server>" << endl;
        *xmlcontent << "    <name>new_ManagedServer_1</name>" << endl;
        *xmlcontent << "    <ssl>" << endl;
        *xmlcontent << "      <name>new_ManagedServer_1</name>" << endl;
        *xmlcontent << "      <enabled>true</enabled>" << endl;
        *xmlcontent << "      <listen-port>7513</listen-port>" << endl;
        *xmlcontent << "    </ssl>" << endl;
        *xmlcontent << "    <machine>new_UnixMachine_1</machine>" << endl;
        *xmlcontent << "    <listen-port>7013</listen-port>" << endl;
        *xmlcontent << "    <listen-address/>" << endl;
        *xmlcontent << "  </server>" << endl;
        *xmlcontent << "  <embedded-ldap>" << endl;
        *xmlcontent << "    <name>base_domain</name>" << endl;
        *xmlcontent << "    <credential-encrypted>{AES}RVX+Cadq8XJ5EvV7/1Ta2qGZrJlxve6t5CEa2A9euGUkYOMDTAwAqytymqDBS00Q</credential-encrypted>" << endl;
        *xmlcontent << "  </embedded-ldap>" << endl;
        *xmlcontent << "  <configuration-version>10.3.2.0</configuration-version>" << endl;
        *xmlcontent << "  <machine xsi:type=\"unix-machineType\">" << endl;
        *xmlcontent << "    <name>new_UnixMachine_1</name>" << endl;
        *xmlcontent << "    <node-manager>" << endl;
        *xmlcontent << "      <name>new_UnixMachine_1</name>" << endl;
        *xmlcontent << "      <listen-address>localhost</listen-address>" << endl;
        *xmlcontent << "      <listen-port>5566</listen-port>" << endl;
        *xmlcontent << "    </node-manager>" << endl;
        *xmlcontent << "  </machine>" << endl;
        *xmlcontent << "  <admin-server-name>AdminServer</admin-server-name>" << endl;
        *xmlcontent << "</domain>" << endl;

        return xmlcontent;
    }

    /*
     * Helper Method to Mock out the returned domain-registry.xml
     * for WebLogic 11g R1.
     * 
     * <?xml version="1.0" encoding="UTF-8"?>
     * <domain-registry xmlns="http://xmlns.oracle.com/weblogic/domain-registry">
     *   <domain location="/opt/Oracle/WebLogic-11/Middleware/user_projects/domains/base_domain"/>
     * </domain-registry>
     * 
     */
    virtual SCXHandle<istream> OpenDomainRegistryXml(const wstring&)
    {
        SCXHandle<stringstream> xmlcontent( new stringstream );

        *xmlcontent << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl;
        *xmlcontent << "<domain-registry xmlns=\"http://xmlns.oracle.com/weblogic/domain-registry\">" << endl;
        *xmlcontent << "  <domain location=\"/opt/Oracle/WebLogic-11/Middleware/user_projects/domains/base_domain\"/>" << endl;
        *xmlcontent << "</domain-registry>" << endl;

        return xmlcontent;
    }

    /*
     * Helper Method to Mock out the returned nodemanager.domains
     * for WebLogic 10g R3. Note that the first domain appears in both
     * the domain-registry.xml as well as the older nodemanager.domains
     * file.
     * 
     * #Domains and directories created by Configuration Wizard
     * #Tue Apr 12 15:23:12 PDT 2011
     * base_domain=/opt/Oracle/WebLogic-11/Middleware/user_projects/domains/base_domain
     * 
     */
    virtual SCXHandle<istream> OpenNodemanagerDomains(const wstring&)
    {
        SCXHandle<stringstream> content( new stringstream );

        *content << "#Domains and directories created by Configuration Wizard" << endl;
        *content << "#Tue Apr 12 15:23:12 PDT 2011" << endl;
        *content << "base_domain=/opt/Oracle/WebLogic-11/Middleware/user_projects/domains/base_domain" << endl;

        return content;
    }   
};

/*
 * Unit Test mock implementation for a file reader that has one
 * entry in the domain-registry.xml file for WebLogic 11. This in
 * turn points to a simple installation that only has one Admin
 * Server.
 * 
 * In essense, this would be the case if a discovery were run on
 * a WebLogic that had just been installed. 
 */
class WebLogic11Cluster : public StandardWebLogic11
{
    
public:
    WebLogic11Cluster() : StandardWebLogic11() {};
    
    virtual ~WebLogic11Cluster() {};

protected:
    
    virtual bool DoesServerDirectoryExist(const SCXFilePath& path)
    {
        bool returnValue = false;
        
        if (path.Get() == WEBLOGIC_DEFAULT_ADMIN_SERVER_PATH)
        {
            returnValue = true;
        }
        
        return returnValue;
    }
};

class MultipleInstallationsOfWebLogic11 : public StandardWebLogic11
{

    private:
           int m_counter;

    public:
        MultipleInstallationsOfWebLogic11() : StandardWebLogic11()
        {
            m_counter = 0;
        };

        virtual ~MultipleInstallationsOfWebLogic11() {};

        virtual void
                GetInstances(
                        const SCXCoreLib::SCXFilePath& domain,
                        std::vector<
                                SCXCoreLib::SCXHandle<AppServerInstance> >& instances)
        {
            if (m_counter < 1)
            {
                cout << "bumping counter" << endl;

                ++m_counter;
            }
            else
            {
                cout << "switch installation path" << endl;
                m_installationPath = WEBLOGIC_OTHER_INSTALLATION_PATH;
            }
            
            StandardWebLogic11::GetInstances(domain, instances);
        };

protected:
        virtual SCXCoreLib::SCXHandle<std::istream> OpenDomainRegistryXml(
                                const std::wstring& filename)
        {
            if (0 != m_counter )
            {
                SCXHandle<stringstream> xmlcontent( new stringstream );

                *xmlcontent << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl;
                *xmlcontent << "<domain-registry xmlns=\"http://xmlns.oracle.com/weblogic/domain-registry\">" << endl;
                *xmlcontent << "  <domain location=\"/opt/Oracle/WebLogic-11-testbed/Middleware/user_projects/domains/base_domain\"/>" << endl;
                *xmlcontent << "</domain-registry>" << endl;

                return xmlcontent;
            }
            else
            {
                return StandardWebLogic11::OpenDomainRegistryXml(filename);
            }
        }

        virtual SCXHandle<istream> OpenNodemanagerDomains(const wstring& filename)
        {
            if (0 != m_counter )
            {
                SCXHandle<stringstream> content( new stringstream );
                return content;
            }
            else
            {
                return StandardWebLogic11::OpenNodemanagerDomains(filename);
            }
        }
};

/*
 * Unit Tests for the logic of enumerating WebLogic instances.
 * 
 * WebLogic is different compared to the other application servers.
 * From the running process, it is not possible to determine 
 * specifics about the application server. Instead, from the running
 * process it is necessary to extract the base location of the
 * WebLogic installations, parse the domains from the appropriate file,
 * and then for each domain parse the XML file to find the Admin and
 * Managed servers.
 * 
 * For the following tests, the most important piece is to manipulate
 * the parsed XML to represent various user configurations.

 */
class WebLogicAppServerEnumeration_Test : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE( WebLogicAppServerEnumeration_Test );

    CPPUNIT_TEST( WebLogicDiscoveryForEmptyInstallationsGoldenCase );
    CPPUNIT_TEST( WebLogicDiscoveryForEmptyInstallationsZeroesResult );

    CPPUNIT_TEST( WebLogicDiscoveryForNoDomainsDueToEmptyFiles);
    CPPUNIT_TEST( WebLogicDiscoveryForNoDomainsDueToMissingFiles);

    CPPUNIT_TEST( WebLogicDiscoveryForDomainRegistryParsingOnWebLogic10 );
    CPPUNIT_TEST( WebLogicDiscoveryForDomainRegistryParsingOnWebLogic11 );
    CPPUNIT_TEST( WebLogicDiscoveryForWebLogic10ThatRequiresDefaultPorts );
    CPPUNIT_TEST( WebLogicDiscoveryForWebLogic11 );
    CPPUNIT_TEST( WebLogicDiscoveryForWebLogic11Cluster );

    CPPUNIT_TEST( WebLogicDiscoveryForWebLogic11WithDuplicateInstallations );
    CPPUNIT_TEST( WebLogicDiscoveryForWebLogic11WithMultipleInstallations );

    CPPUNIT_TEST_SUITE_END();

public:

    /*------------------------------------------------------------------*/
    /*
     * Unit Test setup method run before each test.
     */
    void setUp(void)
    {
    }

    /*------------------------------------------------------------------*/
    /*
     * Unit Test tear down method run after each test.
     */
    void tearDown(void)
    {
    }
    
    /*------------------------------------------------------------------*/
    /*
     * Helper Method
     * 
     * Factory method for getting an enumerator to test with the default
     * Filesystem access-points mocked-out for unit-testing.
     */
    WebLogicAppServerEnumeration* GetWebLogic10Enumerator(void)
    {
        IWebLogicFileReader* fileReader = new StandardWebLogic10();
        
        return new WebLogicAppServerEnumeration(
                SCXHandle<IWebLogicFileReader>(fileReader));
    }    

    /*------------------------------------------------------------------*/
    /*
     * Helper Method
     * 
     * Factory method for getting an enumerator to test with the default
     * Filesystem access-points mocked out for unit-testing.
     */
    WebLogicAppServerEnumeration* GetWebLogic11Enumerator(void)
    {
        IWebLogicFileReader* fileReader = new StandardWebLogic11();
        
        return new WebLogicAppServerEnumeration(
                SCXHandle<IWebLogicFileReader>(fileReader));
    }    

    /*------------------------------------------------------------------*/
    /*
     * Helper Method
     * 
     * Factory method for getting an enumerator to test with the default
     * Filesystem access-points mocked out for unit-testing.
     */
    WebLogicAppServerEnumeration* GetWebLogic11Cluster(void)
    {
        IWebLogicFileReader* fileReader = new WebLogic11Cluster();
        
        return new WebLogicAppServerEnumeration(
                SCXHandle<IWebLogicFileReader>(fileReader));
    }    

    /*------------------------------------------------------------------*/
    /*
     * Helper Method
     * 
     * Create a sample of WegbLogic 11g R1 instance.
     */
    SCXHandle<AppServerInstance> createDefaultWebLogicInstance11(void)
    {
        SCXHandle<AppServerInstance> instance(
                new AppServerInstance (
                        WEBLOGIC_DEFAULT_INSTALLATION_PATH,
                        APP_SERVER_TYPE_WEBLOGIC));
        instance->SetHttpPort(DEFAULT_WEBLOGIC_HTTP_PORT);
        instance->SetHttpsPort(DEFAULT_WEBLOGIC_HTTPS_PORT);
        instance->SetIsDeepMonitored(true, MOCK_WEBLOGIC_PROTOCOL);
        instance->SetIsRunning(false);
        instance->SetVersion(WEBLOGIC_VERSION_11);

        return instance;
    }

    // --------------------------------------------------------
    /*
     * Verify that the WebLogic discovery will always return back
     * zero instances if given an empty list of installations.  
     * This is the golden, expected scenario because the supplied 
     * result vector is already empty.
     */
    void WebLogicDiscoveryForEmptyInstallationsGoldenCase()
    {
        vector<wstring> installations;
        vector<SCXHandle<AppServerInstance> > result;

        CPPUNIT_ASSERT_EQUAL(zeroSize, installations.size());
        CPPUNIT_ASSERT_EQUAL(zeroSize, result.size());

        SCXHandle<WebLogicAppServerEnumeration> enumerator(GetWebLogic11Enumerator());
        enumerator->GetInstances(installations, result);

        CPPUNIT_ASSERT_EQUAL(zeroSize, installations.size());
        CPPUNIT_ASSERT_EQUAL(zeroSize, result.size());
    }

    // --------------------------------------------------------
    /*
     * Verify that the WebLogic discovery will always return back
     * zero instances if given an empty list of installations.  
     * This test  the supplied result vector is non-empty. This 
     * code should verifies that the supplied result vector is
     * treated like an output parameter only.
     */
    void WebLogicDiscoveryForEmptyInstallationsZeroesResult()
    {
        vector<wstring> installations;
        vector<SCXHandle<AppServerInstance> > result;

        result.push_back(createDefaultWebLogicInstance11());

        CPPUNIT_ASSERT_EQUAL(zeroSize, installations.size());
        CPPUNIT_ASSERT_EQUAL(oneSize, result.size());

        SCXHandle<WebLogicAppServerEnumeration> enumerator(GetWebLogic11Enumerator());
        enumerator->GetInstances(installations, result);

        CPPUNIT_ASSERT_EQUAL(zeroSize, installations.size());
        CPPUNIT_ASSERT_EQUAL(zeroSize, result.size());
    }

    // --------------------------------------------------------
    /*
     * Verify that the WebLogic discovery finds nothing if the
     * XML files that contain domain information are empty. The
     * chances of this logic actually happening would be rare, but
     * concievable could happen if the installation had previously
     * been discovered, then deleted, then the discovery occurs
     * from the cached version. 
     */
    void WebLogicDiscoveryForNoDomainsDueToEmptyFiles()
    {
        SCXHandle<IWebLogicFileReader> domainCheck(new EmptyDomainFiles());
        vector<SCXFilePath> result = domainCheck->GetDomains();

        CPPUNIT_ASSERT_EQUAL(zeroSize, result.size());
    }
    
    // --------------------------------------------------------
    /*
     * Verify that the WebLogic discovery finds nothing if the
     * XML files that contain domain information are empty. The
     * chances of this logic actually happening would be rare, but
     * concievable could happen if the installation had previously
     * been discovered, then deleted, then the discovery occurs
     * from the cached version. 
     */
    void WebLogicDiscoveryForNoDomainsDueToMissingFiles()
    {
        SCXHandle<IWebLogicFileReader> domainCheck(new MissingDomainFiles());
        vector<SCXFilePath> result = domainCheck->GetDomains();

        CPPUNIT_ASSERT_EQUAL(zeroSize, result.size());
    }
    
    // --------------------------------------------------------
    /*
     * Verify that the WebLogic domain discovery works for the
     * case of a simple installation that has only one domain
     * for WebLogic 10  
     */
    void WebLogicDiscoveryForDomainRegistryParsingOnWebLogic10()
    {
        SCXHandle<IWebLogicFileReader> domainCheck(new StandardWebLogic10());
        vector<SCXFilePath> result = domainCheck->GetDomains();

        CPPUNIT_ASSERT_EQUAL(oneSize, result.size());
        CPPUNIT_ASSERT(
                WEBLOGIC_DEFAULT_DOMAIN_PATH == result[0].Get());
    }

    
    // --------------------------------------------------------
    /*
     * Verify that the WebLogic domain discovery works for the
     * case of a simple installation that has only one domain
     * for WebLogic 11
     */
    void WebLogicDiscoveryForDomainRegistryParsingOnWebLogic11()
    {
        SCXHandle<IWebLogicFileReader> domainCheck(new StandardWebLogic11());
        vector<SCXFilePath> result = domainCheck->GetDomains();

        CPPUNIT_ASSERT_EQUAL(oneSize, result.size());
        CPPUNIT_ASSERT(
                WEBLOGIC_DEFAULT_DOMAIN_PATH == result[0].Get());
    }

    // --------------------------------------------------------
    /*
     * Verify that the WebLogic discovery works for the case of
     * a very simple installation. There are no managed servers,
     * only one Admin Server (obviously) only one domain as well.
     */
    void WebLogicDiscoveryForWebLogic10ThatRequiresDefaultPorts()
    {
        vector<wstring> installations;
        installations.push_back(WEBLOGIC_DEFAULT_INSTALLATION_PATH);
        vector<SCXHandle<AppServerInstance> > result;

        CPPUNIT_ASSERT_EQUAL(oneSize, installations.size());
        CPPUNIT_ASSERT_EQUAL(zeroSize, result.size());

        SCXHandle<WebLogicAppServerEnumeration> enumerator(GetWebLogic10Enumerator());
        enumerator->GetInstances(installations, result);

        CPPUNIT_ASSERT_EQUAL(twoSize, result.size());
        
        // Verify the AdminServer
        CPPUNIT_ASSERT(
                DEFAULT_WEBLOGIC_HTTP_PORT == result[0]->GetHttpPort());
        CPPUNIT_ASSERT(
                DEFAULT_WEBLOGIC_HTTPS_PORT == result[0]->GetHttpsPort());
        CPPUNIT_ASSERT(
                WEBLOGIC_VERSION_10 == result[0]->GetVersion());
        CPPUNIT_ASSERT(
                WEBLOGIC_MAJOR_VERSION_10 == result[0]->GetMajorVersion());
        CPPUNIT_ASSERT(
                WEBLOGIC_DEFAULT_ADMIN_SERVER_PATH == result[0]->GetDiskPath());
        CPPUNIT_ASSERT(
                WEBLOGIC_SERVER_TYPE_ADMIN == result[0]->GetServer());
        CPPUNIT_ASSERT(
                APP_SERVER_TYPE_WEBLOGIC == result[0]->GetType());
        
        // Verify the ManagedServer
        CPPUNIT_ASSERT(
                MOCK_WEBLOGIC_MANAGED_HTTP_PORT == result[1]->GetHttpPort());
        CPPUNIT_ASSERT(
                DEFAULT_WEBLOGIC_HTTPS_PORT == result[1]->GetHttpsPort());
        CPPUNIT_ASSERT(
                WEBLOGIC_VERSION_10 == result[1]->GetVersion());
        CPPUNIT_ASSERT(
                WEBLOGIC_MAJOR_VERSION_10 == result[1]->GetMajorVersion());
        CPPUNIT_ASSERT(
                WEBLOGIC_DEFAULT_MANAGED_SERVER_PATH == result[1]->GetDiskPath());
        CPPUNIT_ASSERT(
                WEBLOGIC_SERVER_TYPE_MANAGED == result[1]->GetServer());
        CPPUNIT_ASSERT(
                APP_SERVER_TYPE_WEBLOGIC == result[1]->GetType());
    }

    // --------------------------------------------------------
    /*
     * Verify that the WebLogic discovery works for the case of
     * a very simple installation. There are no managed servers,
     * only one Admin Server (obviously) only one domain as well.
     */
    void WebLogicDiscoveryForWebLogic11()
    {
        vector<wstring> installations;
        installations.push_back(WEBLOGIC_DEFAULT_INSTALLATION_PATH);
        vector<SCXHandle<AppServerInstance> > result;

        CPPUNIT_ASSERT_EQUAL(oneSize, installations.size());
        CPPUNIT_ASSERT_EQUAL(zeroSize, result.size());

        SCXHandle<WebLogicAppServerEnumeration> enumerator(GetWebLogic11Enumerator());
        enumerator->GetInstances(installations, result);

        CPPUNIT_ASSERT_EQUAL(twoSize, result.size());
        
        // Verify the AdminServer
        CPPUNIT_ASSERT(
                MOCK_WEBLOGIC_ADMIN_HTTP_PORT == result[0]->GetHttpPort());
        CPPUNIT_ASSERT(
                MOCK_WEBLOGIC_ADMIN_HTTPS_PORT == result[0]->GetHttpsPort());
        CPPUNIT_ASSERT(
                WEBLOGIC_VERSION_11 == result[0]->GetVersion());
        CPPUNIT_ASSERT(
                WEBLOGIC_MAJOR_VERSION_11 == result[0]->GetMajorVersion());
        CPPUNIT_ASSERT(
                WEBLOGIC_DEFAULT_ADMIN_SERVER_PATH == result[0]->GetDiskPath());
        CPPUNIT_ASSERT(
                WEBLOGIC_SERVER_TYPE_ADMIN == result[0]->GetServer());
        CPPUNIT_ASSERT(
                APP_SERVER_TYPE_WEBLOGIC == result[0]->GetType());
        
        // Verify the ManagedServer
        CPPUNIT_ASSERT(
                MOCK_WEBLOGIC_MANAGED_HTTP_PORT == result[1]->GetHttpPort());
        CPPUNIT_ASSERT(
                MOCK_WEBLOGIC_MANAGED_HTTPS_PORT == result[1]->GetHttpsPort());
        CPPUNIT_ASSERT(
                WEBLOGIC_VERSION_11 == result[1]->GetVersion());
        CPPUNIT_ASSERT(
                WEBLOGIC_MAJOR_VERSION_11 == result[1]->GetMajorVersion());
        CPPUNIT_ASSERT(
                WEBLOGIC_DEFAULT_MANAGED_SERVER_PATH == result[1]->GetDiskPath());
        CPPUNIT_ASSERT(
                WEBLOGIC_SERVER_TYPE_MANAGED == result[1]->GetServer());
        CPPUNIT_ASSERT(
                APP_SERVER_TYPE_WEBLOGIC == result[1]->GetType());
    }

    // --------------------------------------------------------
    /*
     * Verify that the WebLogic discovery works for the case of
     * a very simple installation. There are no managed servers,
     * only one Admin Server (obviously) only one domain as well.
     */
    void WebLogicDiscoveryForWebLogic11Cluster()
    {
        vector<wstring> installations;
        installations.push_back(WEBLOGIC_DEFAULT_INSTALLATION_PATH);
        vector<SCXHandle<AppServerInstance> > result;

        CPPUNIT_ASSERT_EQUAL(oneSize, installations.size());
        CPPUNIT_ASSERT_EQUAL(zeroSize, result.size());

        SCXHandle<WebLogicAppServerEnumeration> enumerator(GetWebLogic11Cluster());
        enumerator->GetInstances(installations, result);

        CPPUNIT_ASSERT_EQUAL(oneSize, result.size());
        
        // Verify the AdminServer
        CPPUNIT_ASSERT(
                MOCK_WEBLOGIC_ADMIN_HTTP_PORT == result[0]->GetHttpPort());
        CPPUNIT_ASSERT(
                MOCK_WEBLOGIC_ADMIN_HTTPS_PORT == result[0]->GetHttpsPort());
        CPPUNIT_ASSERT(
                WEBLOGIC_VERSION_11 == result[0]->GetVersion());
        CPPUNIT_ASSERT(
                WEBLOGIC_MAJOR_VERSION_11 == result[0]->GetMajorVersion());
        CPPUNIT_ASSERT(
                WEBLOGIC_DEFAULT_ADMIN_SERVER_PATH == result[0]->GetDiskPath());
        CPPUNIT_ASSERT(
                WEBLOGIC_SERVER_TYPE_ADMIN == result[0]->GetServer());
        CPPUNIT_ASSERT(
                APP_SERVER_TYPE_WEBLOGIC == result[0]->GetType());
    }

    // --------------------------------------------------------
    /*
     * Verify that the WebLogic discovery works as expected if the
     * input vector of installations contains duplicates. The
     * expected behavior is that the duplicate installations will
     * be discarded and only one set of Application Server instances
     * will be returned. 
     */
    void WebLogicDiscoveryForWebLogic11WithDuplicateInstallations()
    {
        vector<wstring> installations;
        installations.push_back(WEBLOGIC_DEFAULT_INSTALLATION_PATH);
        installations.push_back(WEBLOGIC_DEFAULT_INSTALLATION_PATH);
        installations.push_back(WEBLOGIC_DEFAULT_INSTALLATION_PATH);
        vector<SCXHandle<AppServerInstance> > result;

        CPPUNIT_ASSERT_EQUAL(threeSize, installations.size());
        CPPUNIT_ASSERT_EQUAL(zeroSize, result.size());

        SCXHandle<WebLogicAppServerEnumeration> enumerator(GetWebLogic11Enumerator());
        enumerator->GetInstances(installations, result);

        CPPUNIT_ASSERT_EQUAL(twoSize, result.size());
        
        // Verify the AdminServer
        CPPUNIT_ASSERT(
                MOCK_WEBLOGIC_ADMIN_HTTP_PORT == result[0]->GetHttpPort());
        CPPUNIT_ASSERT(
                MOCK_WEBLOGIC_ADMIN_HTTPS_PORT == result[0]->GetHttpsPort());
        CPPUNIT_ASSERT(
                WEBLOGIC_VERSION_11 == result[0]->GetVersion());
        CPPUNIT_ASSERT(
                WEBLOGIC_MAJOR_VERSION_11 == result[0]->GetMajorVersion());
        CPPUNIT_ASSERT(
                WEBLOGIC_DEFAULT_ADMIN_SERVER_PATH == result[0]->GetDiskPath());
        CPPUNIT_ASSERT(
                WEBLOGIC_SERVER_TYPE_ADMIN == result[0]->GetServer());
        CPPUNIT_ASSERT(
                APP_SERVER_TYPE_WEBLOGIC == result[0]->GetType());
        
        // Verify the ManagedServer
        CPPUNIT_ASSERT(
                MOCK_WEBLOGIC_MANAGED_HTTP_PORT == result[1]->GetHttpPort());
        CPPUNIT_ASSERT(
                MOCK_WEBLOGIC_MANAGED_HTTPS_PORT == result[1]->GetHttpsPort());
        CPPUNIT_ASSERT(
                WEBLOGIC_VERSION_11 == result[1]->GetVersion());
        CPPUNIT_ASSERT(
                WEBLOGIC_MAJOR_VERSION_11 == result[1]->GetMajorVersion());
        CPPUNIT_ASSERT(
                WEBLOGIC_DEFAULT_MANAGED_SERVER_PATH == result[1]->GetDiskPath());
        CPPUNIT_ASSERT(
                WEBLOGIC_SERVER_TYPE_MANAGED == result[1]->GetServer());
        CPPUNIT_ASSERT(
                APP_SERVER_TYPE_WEBLOGIC == result[1]->GetType());
    }

    // --------------------------------------------------------
    /*
     * Verify that the WebLogic discovery works as expected if the
     * input vector of installations contains duplicates. The
     * expected behavior is that the duplicate installations will
     * be discarded and only one set of Application Server instances
     * will be returned. 
     */
    void WebLogicDiscoveryForWebLogic11WithMultipleInstallations()
    {
        vector<wstring> installations;
        installations.push_back(WEBLOGIC_DEFAULT_INSTALLATION_PATH);
        installations.push_back(WEBLOGIC_OTHER_INSTALLATION_PATH);
        vector<SCXHandle<AppServerInstance> > result;

        CPPUNIT_ASSERT_EQUAL(twoSize, installations.size());
        CPPUNIT_ASSERT_EQUAL(zeroSize, result.size());
        
        IWebLogicFileReader* fileReader = new MultipleInstallationsOfWebLogic11();

        SCXHandle<WebLogicAppServerEnumeration> enumerator(
                new WebLogicAppServerEnumeration(
                                    SCXHandle<IWebLogicFileReader>(fileReader)));
        enumerator->GetInstances(installations, result);

        CPPUNIT_ASSERT_EQUAL(fourSize, result.size());

        // Verify the AdminServer (Default)
        CPPUNIT_ASSERT(
                MOCK_WEBLOGIC_ADMIN_HTTP_PORT == result[0]->GetHttpPort());
        CPPUNIT_ASSERT(
                MOCK_WEBLOGIC_ADMIN_HTTPS_PORT == result[0]->GetHttpsPort());
        CPPUNIT_ASSERT(
                WEBLOGIC_VERSION_11 == result[0]->GetVersion());
        CPPUNIT_ASSERT(
                WEBLOGIC_MAJOR_VERSION_11 == result[0]->GetMajorVersion());
        CPPUNIT_ASSERT(
                WEBLOGIC_DEFAULT_ADMIN_SERVER_PATH == result[0]->GetDiskPath());
        CPPUNIT_ASSERT(
                WEBLOGIC_SERVER_TYPE_ADMIN == result[0]->GetServer());
        CPPUNIT_ASSERT(
                APP_SERVER_TYPE_WEBLOGIC == result[0]->GetType());

        // Verify the ManagedServer (Managed)
        CPPUNIT_ASSERT(
                MOCK_WEBLOGIC_MANAGED_HTTP_PORT == result[1]->GetHttpPort());
        CPPUNIT_ASSERT(
                MOCK_WEBLOGIC_MANAGED_HTTPS_PORT == result[1]->GetHttpsPort());
        CPPUNIT_ASSERT(
                WEBLOGIC_VERSION_11 == result[1]->GetVersion());
        CPPUNIT_ASSERT(
                WEBLOGIC_MAJOR_VERSION_11 == result[1]->GetMajorVersion());
        CPPUNIT_ASSERT(
                WEBLOGIC_DEFAULT_MANAGED_SERVER_PATH == result[1]->GetDiskPath());
        CPPUNIT_ASSERT(
                WEBLOGIC_SERVER_TYPE_MANAGED == result[1]->GetServer());
        CPPUNIT_ASSERT(
                APP_SERVER_TYPE_WEBLOGIC == result[1]->GetType());

        // Verify the AdminServer (Default)
        CPPUNIT_ASSERT(
                MOCK_WEBLOGIC_ADMIN_HTTP_PORT == result[2]->GetHttpPort());
        CPPUNIT_ASSERT(
                MOCK_WEBLOGIC_ADMIN_HTTPS_PORT == result[2]->GetHttpsPort());
        CPPUNIT_ASSERT(
                WEBLOGIC_VERSION_11 == result[2]->GetVersion());
        CPPUNIT_ASSERT(
                WEBLOGIC_MAJOR_VERSION_11 == result[2]->GetMajorVersion());
        CPPUNIT_ASSERT(
                WEBLOGIC_OTHER_ADMIN_SERVER_PATH == result[2]->GetDiskPath());
        CPPUNIT_ASSERT(
                WEBLOGIC_SERVER_TYPE_ADMIN == result[2]->GetServer());
        CPPUNIT_ASSERT(
                APP_SERVER_TYPE_WEBLOGIC == result[2]->GetType());

        // Verify the ManagedServer (Managed)
        CPPUNIT_ASSERT(
                MOCK_WEBLOGIC_MANAGED_HTTP_PORT == result[3]->GetHttpPort());
        CPPUNIT_ASSERT(
                MOCK_WEBLOGIC_MANAGED_HTTPS_PORT == result[3]->GetHttpsPort());
        CPPUNIT_ASSERT(
                WEBLOGIC_VERSION_11 == result[3]->GetVersion());
        CPPUNIT_ASSERT(
                WEBLOGIC_MAJOR_VERSION_11 == result[3]->GetMajorVersion());
        CPPUNIT_ASSERT(
                WEBLOGIC_OTHER_MANAGED_SERVER_PATH == result[3]->GetDiskPath());
        CPPUNIT_ASSERT(
                WEBLOGIC_SERVER_TYPE_MANAGED == result[3]->GetServer());
        CPPUNIT_ASSERT(
                APP_SERVER_TYPE_WEBLOGIC == result[3]->GetType());
    }

    
}; // End WebLogicAppServerEnumeration_Test 

}    // End namespace

CPPUNIT_TEST_SUITE_REGISTRATION
( SCXUnitTests::WebLogicAppServerEnumeration_Test);
