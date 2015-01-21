/*--------------------------------------------------------------------------------
  Copyright (c) Microsoft Corporation.  All rights reserved.

  Created date    2011-05-18

  websphere appserver data colletion test class.

*/
/*----------------------------------------------------------------------------*/
#include <scxcorelib/scxcmn.h>
#include <scxcorelib/stringaid.h>
#include <scxcorelib/scxfilesystem.h>
#include <testutils/scxunit.h>

#include <websphereappserverinstance.h>

#include <cppunit/extensions/HelperMacros.h>

using namespace SCXCoreLib;
using namespace SCXSystemLib;
using namespace std;

// Test dependencies used to get the XML content from string constants instead of from files
// Also has the ability to control some aspects of the XML to supply, to simulate different problems
class WebSphereAppServerInstanceTestPALDependencies : public WebSphereAppServerInstancePALDependencies
{
public:

    WebSphereAppServerInstanceTestPALDependencies() : 
        m_xmlServerFilename(L""), m_noServerFile(false), m_emptyServerFile(false), m_badXmlServerFile(false),
        m_xmlVersionFilename(L""), m_noVersionFile(false), m_emptyVersionFile(false), m_badXmlVersionFile(false),m_version(7)
    {}

    // Should the we throw an exception when opening the server file
    void SetNoServerFile(bool noServerFile)
    {
        m_noServerFile = noServerFile;
    }

    // Should the we return an empty string for the content of the server file
    void SetEmptyServerFile(bool emptyServerFile)
    {
        m_emptyServerFile = emptyServerFile;
    }

    // Should the we return invalid XML for the content of the server file
    void SetBadXmlServerFile(bool badXmlServerFile)
    {
        m_badXmlServerFile = badXmlServerFile;
    }

    // Should the we throw an exception when opening the version file
    void SetNoVersionFile(bool noVersionFile)
    {
        m_noVersionFile = noVersionFile;
    }

    // Should the we return an empty string for the content of the version file
    void SetEmptyVersionFile(bool emptyVersionFile)
    {
        m_emptyVersionFile = emptyVersionFile;
    }
    
    // If we need specific version - besides 7 - what version file to return
    void SetVersion(int version)
    {
        m_version = version;
    }

    // Should the we return invalid XML for the content of the version file
    void SetBadXmlVersionFile(bool badXmlVersionFile)
    {
        m_badXmlVersionFile = badXmlVersionFile;
    }

    virtual SCXHandle<std::istream> OpenXmlVersionFile(const wstring& filename)
    {
        m_xmlVersionFilename = filename;

        SCXHandle<stringstream> xmlcontent( new stringstream );

        if (m_noVersionFile)
        {
            throw SCXFilePathNotFoundException(filename, SCXSRCLOCATION);
        }

        if (m_emptyVersionFile)
        {
            return xmlcontent;
        }

        *xmlcontent << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl;
        *xmlcontent << "<profile>" << endl;
        *xmlcontent << "  <id>default</id>" << endl;
        *xmlcontent << "  <version>" << m_version << ".0.0.0</version>" << endl;

        *xmlcontent << "  <build-info date=\"8/31/08\" level=\"r0835.03\"/>" << endl;
        
        if (!m_badXmlVersionFile)
        {
            *xmlcontent << "</profile>" << endl;
        }

        return xmlcontent;
    }

    virtual SCXHandle<std::istream> OpenXmlServerFile(const wstring& filename)
    {
        m_xmlServerFilename = filename;

        SCXHandle<stringstream> xmlcontent( new stringstream );

        if (m_noServerFile)
        {
            throw SCXFilePathNotFoundException(filename, SCXSRCLOCATION);
        }

        if (m_emptyServerFile)
        {
            return xmlcontent;
        }

        *xmlcontent << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl;
        *xmlcontent << "      <serverindex:ServerIndex xmi:version=\"2.0\" xmlns:xmi=\"http://www.omg.org/XMI\" xmlns:serverindex=\"http://www.ibm.com/websphere/appserver/schemas/5.0/serverindex.xmi\" xmi:id=\"ServerIndex_1\" hostName=\"SCXOMD-WS7-07.SCX.com\">" << endl;
        *xmlcontent << "      <serverEntries xmi:id=\"ServerEntry_1183122129640\" serverName=\"server1\" serverType=\"APPLICATION_SERVER\">" << endl;
        *xmlcontent << "    <deployedApplications>WebSphereWSDM.ear/deployments/WebSphereWSDM</deployedApplications>" << endl;
        *xmlcontent << "    <deployedApplications>isclite.ear/deployments/isclite</deployedApplications>" << endl;
        *xmlcontent << "    <deployedApplications>DefaultApplication.ear/deployments/DefaultApplication</deployedApplications>" << endl;
        *xmlcontent << "    <deployedApplications>ivtApp.ear/deployments/ivtApp</deployedApplications>" << endl;
        *xmlcontent << "    <deployedApplications>query.ear/deployments/query</deployedApplications>" << endl;
        *xmlcontent << "    <deployedApplications>ibmasyncrsp.ear/deployments/ibmasyncrsp</deployedApplications>" << endl;
        *xmlcontent << "      <specialEndpoints xmi:id=\"NamedEndPoint_1183122129640\" endPointName=\"BOOTSTRAP_ADDRESS\">" << endl;
        *xmlcontent << "      <endPoint xmi:id=\"EndPoint_1183122129640\" host=\"SCXOMD-WS7-07.SCX.com\" port=\"2809\"/>" << endl;
        *xmlcontent << "    </specialEndpoints>" << endl;
        *xmlcontent << "      <specialEndpoints xmi:id=\"NamedEndPoint_1183122129641\" endPointName=\"SOAP_CONNECTOR_ADDRESS\">" << endl;
        *xmlcontent << "      <endPoint xmi:id=\"EndPoint_1183122129641\" host=\"SCXOMD-WS7-07.SCX.com\" port=\"8880\"/>" << endl;
        *xmlcontent << "    </specialEndpoints>" << endl;
        *xmlcontent << "      <specialEndpoints xmi:id=\"NamedEndPoint_1183122129642\" endPointName=\"ORB_LISTENER_ADDRESS\">" << endl;
        *xmlcontent << "      <endPoint xmi:id=\"EndPoint_1183122129642\" host=\"SCXOMD-WS7-07.SCX.com\" port=\"9100\"/>" << endl;
        *xmlcontent << "    </specialEndpoints>" << endl;
        *xmlcontent << "      <specialEndpoints xmi:id=\"NamedEndPoint_1183122129643\" endPointName=\"SAS_SSL_SERVERAUTH_LISTENER_ADDRESS\">" << endl;
        *xmlcontent << "      <endPoint xmi:id=\"EndPoint_1183122129643\" host=\"SCXOMD-WS7-07.SCX.com\" port=\"9401\"/>" << endl;
        *xmlcontent << "    </specialEndpoints>" << endl;
        *xmlcontent << "      <specialEndpoints xmi:id=\"NamedEndPoint_1183122129644\" endPointName=\"CSIV2_SSL_SERVERAUTH_LISTENER_ADDRESS\">" << endl;
        *xmlcontent << "      <endPoint xmi:id=\"EndPoint_1183122129644\" host=\"SCXOMD-WS7-07.SCX.com\" port=\"9403\"/>" << endl;
        *xmlcontent << "    </specialEndpoints>" << endl;
        *xmlcontent << "      <specialEndpoints xmi:id=\"NamedEndPoint_1183122129645\" endPointName=\"CSIV2_SSL_MUTUALAUTH_LISTENER_ADDRESS\">" << endl;
        *xmlcontent << "      <endPoint xmi:id=\"EndPoint_1183122129645\" host=\"SCXOMD-WS7-07.SCX.com\" port=\"9402\"/>" << endl;
        *xmlcontent << "    </specialEndpoints>" << endl;
        *xmlcontent << "      <specialEndpoints xmi:id=\"NamedEndPoint_1183122129646\" endPointName=\"WC_adminhost\">" << endl;
        *xmlcontent << "      <endPoint xmi:id=\"EndPoint_1183122129646\" host=\"*\" port=\"9060\"/>" << endl;
        *xmlcontent << "    </specialEndpoints>" << endl;
        *xmlcontent << "      <specialEndpoints xmi:id=\"NamedEndPoint_1183122129647\" endPointName=\"WC_defaulthost\">" << endl;
        *xmlcontent << "      <endPoint xmi:id=\"EndPoint_1183122129647\" host=\"*\" port=\"9080\"/>" << endl;
        *xmlcontent << "    </specialEndpoints>" << endl;
        *xmlcontent << "      <specialEndpoints xmi:id=\"NamedEndPoint_1183122129648\" endPointName=\"DCS_UNICAST_ADDRESS\">" << endl;
        *xmlcontent << "      <endPoint xmi:id=\"EndPoint_1183122129648\" host=\"*\" port=\"9353\"/>" << endl;
        *xmlcontent << "    </specialEndpoints>" << endl;
        *xmlcontent << "      <specialEndpoints xmi:id=\"NamedEndPoint_1183122129649\" endPointName=\"WC_adminhost_secure\">" << endl;
        *xmlcontent << "      <endPoint xmi:id=\"EndPoint_1183122129649\" host=\"*\" port=\"9043\"/>" << endl;
        *xmlcontent << "    </specialEndpoints>" << endl;
        *xmlcontent << "      <specialEndpoints xmi:id=\"NamedEndPoint_1183122129650\" endPointName=\"WC_defaulthost_secure\">" << endl;
        *xmlcontent << "      <endPoint xmi:id=\"EndPoint_1183122129650\" host=\"*\" port=\"9443\"/>" << endl;
        *xmlcontent << "    </specialEndpoints>" << endl;
        *xmlcontent << "      <specialEndpoints xmi:id=\"NamedEndPoint_1183122129651\" endPointName=\"SIP_DEFAULTHOST\">" << endl;
        *xmlcontent << "      <endPoint xmi:id=\"EndPoint_1183122129651\" host=\"*\" port=\"5060\"/>" << endl;
        *xmlcontent << "    </specialEndpoints>" << endl;
        *xmlcontent << "      <specialEndpoints xmi:id=\"NamedEndPoint_1183122129652\" endPointName=\"SIP_DEFAULTHOST_SECURE\">" << endl;
        *xmlcontent << "      <endPoint xmi:id=\"EndPoint_1183122129652\" host=\"*\" port=\"5061\"/>" << endl;
        *xmlcontent << "    </specialEndpoints>" << endl;
        *xmlcontent << "      <specialEndpoints xmi:id=\"NamedEndPoint_1183122129653\" endPointName=\"SIB_ENDPOINT_ADDRESS\">" << endl;
        *xmlcontent << "      <endPoint xmi:id=\"EndPoint_1294703843065\" host=\"*\" port=\"7276\"/>" << endl;
        *xmlcontent << "    </specialEndpoints>" << endl;
        *xmlcontent << "      <specialEndpoints xmi:id=\"NamedEndPoint_1183122129654\" endPointName=\"SIB_ENDPOINT_SECURE_ADDRESS\">" << endl;
        *xmlcontent << "      <endPoint xmi:id=\"EndPoint_1294703843068\" host=\"*\" port=\"7286\"/>" << endl;
        *xmlcontent << "    </specialEndpoints>" << endl;
        *xmlcontent << "      <specialEndpoints xmi:id=\"NamedEndPoint_1183122129655\" endPointName=\"SIB_MQ_ENDPOINT_ADDRESS\">" << endl;
        *xmlcontent << "      <endPoint xmi:id=\"EndPoint_1294703843072\" host=\"*\" port=\"5558\"/>" << endl;
        *xmlcontent << "    </specialEndpoints>" << endl;
        *xmlcontent << "      <specialEndpoints xmi:id=\"NamedEndPoint_1183122129656\" endPointName=\"SIB_MQ_ENDPOINT_SECURE_ADDRESS\">" << endl;
        *xmlcontent << "      <endPoint xmi:id=\"EndPoint_1294703843077\" host=\"*\" port=\"5578\"/>" << endl;
        *xmlcontent << "    </specialEndpoints>" << endl;
        *xmlcontent << "      <specialEndpoints xmi:id=\"NamedEndPoint_1183122129657\" endPointName=\"IPC_CONNECTOR_ADDRESS\">" << endl;
        *xmlcontent << "      <endPoint xmi:id=\"EndPoint_1183122129657\" host=\"${LOCALHOST_NAME}\" port=\"9633\"/>" << endl;
        *xmlcontent << "    </specialEndpoints>" << endl;
        *xmlcontent << "  </serverEntries>" << endl;
        *xmlcontent << "      <serverEntries xmi:id=\"ServerEntry_1313615896936\" serverName=\"WebServer1\" serverType=\"WEB_SERVER\">" << endl;
        *xmlcontent << "    <deployedApplications>query.ear/deployments/query</deployedApplications>" << endl;
        *xmlcontent << "    <deployedApplications>ivtApp.ear/deployments/ivtApp</deployedApplications>" << endl;
        *xmlcontent << "    <deployedApplications>DefaultApplication.ear/deployments/DefaultApplication</deployedApplications>" << endl;
        *xmlcontent << "      <specialEndpoints xmi:id=\"NamedEndPoint_1313615896936\" endPointName=\"WEBSERVER_ADDRESS\">" << endl;
        *xmlcontent << "      <endPoint xmi:id=\"EndPoint_1313615896936\" host=\"SCXOMD-WS7-07.SCX.com\" port=\"80\"/>" << endl;
        *xmlcontent << "    </specialEndpoints>" << endl;
        *xmlcontent << "      <specialEndpoints xmi:id=\"NamedEndPoint_1313615896937\" endPointName=\"WEBSERVER_ADMIN_ADDRESS\">" << endl;
        *xmlcontent << "      <endPoint xmi:id=\"EndPoint_1313615896937\" host=\"SCXOMD-WS7-07.SCX.com\" port=\"8008\"/>" << endl;
        *xmlcontent << "    </specialEndpoints>" << endl;
        *xmlcontent << "  </serverEntries>" << endl;
        
        if (!m_badXmlServerFile)
        {
            *xmlcontent << "</serverindex:ServerIndex>" << endl;
        }

        return xmlcontent;
    }

    wstring m_xmlServerFilename;
    bool m_noServerFile;
    bool m_emptyServerFile;
    bool m_badXmlServerFile;
    wstring m_xmlVersionFilename;
    bool m_noVersionFile;
    bool m_emptyVersionFile;
    bool m_badXmlVersionFile;
    int m_version;
};

class WebSphereAppServerInstance_Test : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE( WebSphereAppServerInstance_Test );

    CPPUNIT_TEST( testAllGood );
    CPPUNIT_TEST( testAllGoodNonDefaultProfiles );
    CPPUNIT_TEST( testNoServerFile );
    CPPUNIT_TEST( testNoVersionFile );
    CPPUNIT_TEST( testEmptyServerFile );
    CPPUNIT_TEST( testEmptyVersionFile );
    CPPUNIT_TEST( testBadXmlServerFile );
    CPPUNIT_TEST( testBadXmlVersionFile );
    CPPUNIT_TEST( testRemovingNetworkDeploymentInstallation );

    CPPUNIT_TEST_SUITE_END();

    public:

    void setUp(void)
    {
    }

    void tearDown(void)
    {
    }

    // Test with XML not containing the HTTPBinding property, but which do contain the HTTP section
    void testAllGood()
    {
        SCXHandle<WebSphereAppServerInstanceTestPALDependencies> deps(new WebSphereAppServerInstanceTestPALDependencies());
        
        SCXHandle<WebSphereAppServerInstance> asInstance( new WebSphereAppServerInstance(L"home", L"cell", L"node", L"profile", L"server1", deps) );

        asInstance->Update();

        CPPUNIT_ASSERT(asInstance->GetId() == L"profile-cell-node-server1");
        CPPUNIT_ASSERT(asInstance->GetDiskPath() == L"home/");
        CPPUNIT_ASSERT(asInstance->GetProfile() == L"profile");
        CPPUNIT_ASSERT(asInstance->GetCell() == L"cell");
        CPPUNIT_ASSERT(asInstance->GetNode() == L"node");
        CPPUNIT_ASSERT(asInstance->GetServer() == L"server1");
        CPPUNIT_ASSERT(asInstance->GetType() == L"WebSphere");
        CPPUNIT_ASSERT(asInstance->GetVersion() == L"7.0.0.0");
        CPPUNIT_ASSERT(asInstance->GetMajorVersion() == L"7");

        CPPUNIT_ASSERT_EQUAL("9080", StrToMultibyte(asInstance->GetHttpPort()));
        CPPUNIT_ASSERT(asInstance->GetHttpsPort() == L"9443");

        CPPUNIT_ASSERT(deps->m_xmlServerFilename == L"home/config/cells/cell/nodes/node/serverindex.xml");
        CPPUNIT_ASSERT(deps->m_xmlVersionFilename == L"home/properties/version/profile.version");
    }

    // Test with non default profiles path for WebSphere 6.1 and WebSphere 7.0
    void testAllGoodNonDefaultProfiles()
    {
        SCXHandle<WebSphereAppServerInstanceTestPALDependencies> deps(new WebSphereAppServerInstanceTestPALDependencies());
        
        SCXHandle<WebSphereAppServerInstance> asInstance( new WebSphereAppServerInstance(L"/opt/IBM/WebSphere/AppServer/Profiles/AppSrv01", L"cell", L"node", L"profile", L"server1", deps) );

        asInstance->Update();

        CPPUNIT_ASSERT(asInstance->GetId() == L"profile-cell-node-server1");
        CPPUNIT_ASSERT_EQUAL( "/opt/IBM/WebSphere/AppServer/Profiles/AppSrv01/",StrToMultibyte(asInstance->GetDiskPath()));
        CPPUNIT_ASSERT(asInstance->GetProfile() == L"profile");
        CPPUNIT_ASSERT(asInstance->GetCell() == L"cell");
        CPPUNIT_ASSERT(asInstance->GetNode() == L"node");
        CPPUNIT_ASSERT(asInstance->GetServer() == L"server1");
        CPPUNIT_ASSERT(asInstance->GetType() == L"WebSphere");
        CPPUNIT_ASSERT(asInstance->GetVersion() == L"7.0.0.0");
        CPPUNIT_ASSERT(asInstance->GetMajorVersion() == L"7");

        CPPUNIT_ASSERT_EQUAL("9080", StrToMultibyte(asInstance->GetHttpPort()));
        CPPUNIT_ASSERT(asInstance->GetHttpsPort() == L"9443");

        CPPUNIT_ASSERT(deps->m_xmlServerFilename == L"/opt/IBM/WebSphere/AppServer/Profiles/AppSrv01/config/cells/cell/nodes/node/serverindex.xml");
        CPPUNIT_ASSERT(deps->m_xmlVersionFilename == L"/opt/IBM/WebSphere/AppServer/Profiles/AppSrv01/properties/version/profile.version");
    }


    // Test with code that throw exception when we try to open the ports file
    void testNoServerFile()
    {
        SCXHandle<WebSphereAppServerInstanceTestPALDependencies> deps(new WebSphereAppServerInstanceTestPALDependencies());
        
        deps->SetNoServerFile(true);

        SCXHandle<WebSphereAppServerInstance> asInstance( new WebSphereAppServerInstance(L"home", L"cell", L"node", L"profile", L"server1", deps) );

        asInstance->Update();

        CPPUNIT_ASSERT(asInstance->GetId() == L"profile-cell-node-server1");
        CPPUNIT_ASSERT(asInstance->GetDiskPath() == L"home/");
        CPPUNIT_ASSERT(asInstance->GetProfile() == L"profile");
        CPPUNIT_ASSERT(asInstance->GetCell() == L"cell");
        CPPUNIT_ASSERT(asInstance->GetNode() == L"node");
        CPPUNIT_ASSERT(asInstance->GetServer() == L"server1");
        CPPUNIT_ASSERT(asInstance->GetType() == L"WebSphere");
        CPPUNIT_ASSERT(asInstance->GetVersion() == L"7.0.0.0");
        CPPUNIT_ASSERT(asInstance->GetMajorVersion() == L"7");

        CPPUNIT_ASSERT(asInstance->GetHttpPort() == L"");
        CPPUNIT_ASSERT(asInstance->GetHttpsPort() == L"");

        CPPUNIT_ASSERT(deps->m_xmlServerFilename == L"home/config/cells/cell/nodes/node/serverindex.xml");
        CPPUNIT_ASSERT(deps->m_xmlVersionFilename == L"home/properties/version/profile.version");
    }

    // Test with code that throw exception when we try to open the version file
    void testNoVersionFile()
    {
        SCXHandle<WebSphereAppServerInstanceTestPALDependencies> deps(new WebSphereAppServerInstanceTestPALDependencies());
        
        deps->SetNoVersionFile(true);

        SCXHandle<WebSphereAppServerInstance> asInstance( new WebSphereAppServerInstance(L"home", L"cell", L"node", L"profile", L"server1", deps) );

        asInstance->Update();

        CPPUNIT_ASSERT(asInstance->GetId() == L"profile-cell-node-server1");
        CPPUNIT_ASSERT(asInstance->GetDiskPath() == L"home/");
        CPPUNIT_ASSERT(asInstance->GetProfile() == L"profile");
        CPPUNIT_ASSERT(asInstance->GetCell() == L"cell");
        CPPUNIT_ASSERT(asInstance->GetNode() == L"node");
        CPPUNIT_ASSERT(asInstance->GetServer() == L"server1");
        CPPUNIT_ASSERT(asInstance->GetType() == L"WebSphere");
        CPPUNIT_ASSERT(asInstance->GetVersion() == L"");
        CPPUNIT_ASSERT(asInstance->GetMajorVersion() == L"");

        CPPUNIT_ASSERT_EQUAL("9080", StrToMultibyte(asInstance->GetHttpPort()));
        CPPUNIT_ASSERT(asInstance->GetHttpsPort() == L"9443");

        CPPUNIT_ASSERT(deps->m_xmlServerFilename == L"home/config/cells/cell/nodes/node/serverindex.xml");
        CPPUNIT_ASSERT(deps->m_xmlVersionFilename == L"home/properties/version/profile.version");
    }

    // Test with code that returns an empty string from the ports file
    void testEmptyServerFile()
    {
        SCXHandle<WebSphereAppServerInstanceTestPALDependencies> deps(new WebSphereAppServerInstanceTestPALDependencies());
        
        deps->SetEmptyServerFile(true);

        SCXHandle<WebSphereAppServerInstance> asInstance( new WebSphereAppServerInstance(L"home", L"cell", L"node", L"profile", L"server1", deps) );

        asInstance->Update();

        CPPUNIT_ASSERT(asInstance->GetId() == L"profile-cell-node-server1");
        CPPUNIT_ASSERT(asInstance->GetDiskPath() == L"home/");
        CPPUNIT_ASSERT(asInstance->GetProfile() == L"profile");
        CPPUNIT_ASSERT(asInstance->GetCell() == L"cell");
        CPPUNIT_ASSERT(asInstance->GetNode() == L"node");
        CPPUNIT_ASSERT(asInstance->GetServer() == L"server1");
        CPPUNIT_ASSERT(asInstance->GetType() == L"WebSphere");
        CPPUNIT_ASSERT(asInstance->GetVersion() == L"7.0.0.0");
        CPPUNIT_ASSERT(asInstance->GetMajorVersion() == L"7");

        CPPUNIT_ASSERT(asInstance->GetHttpPort() == L"");
        CPPUNIT_ASSERT(asInstance->GetHttpsPort() == L"");

        CPPUNIT_ASSERT(deps->m_xmlServerFilename == L"home/config/cells/cell/nodes/node/serverindex.xml");
        CPPUNIT_ASSERT(deps->m_xmlVersionFilename == L"home/properties/version/profile.version");
    }

    // Test with code that returns an empty string from the version file
    void testEmptyVersionFile()
    {
        SCXHandle<WebSphereAppServerInstanceTestPALDependencies> deps(new WebSphereAppServerInstanceTestPALDependencies());
        
        deps->SetEmptyVersionFile(true);

        SCXHandle<WebSphereAppServerInstance> asInstance( new WebSphereAppServerInstance(L"home", L"cell", L"node", L"profile", L"server1", deps) );

        asInstance->Update();

        CPPUNIT_ASSERT(asInstance->GetId() == L"profile-cell-node-server1");
        CPPUNIT_ASSERT(asInstance->GetDiskPath() == L"home/");
        CPPUNIT_ASSERT(asInstance->GetProfile() == L"profile");
        CPPUNIT_ASSERT(asInstance->GetCell() == L"cell");
        CPPUNIT_ASSERT(asInstance->GetNode() == L"node");
        CPPUNIT_ASSERT(asInstance->GetServer() == L"server1");
        CPPUNIT_ASSERT(asInstance->GetType() == L"WebSphere");
        CPPUNIT_ASSERT(asInstance->GetVersion() == L"");
        CPPUNIT_ASSERT(asInstance->GetMajorVersion() == L"");

        CPPUNIT_ASSERT_EQUAL("9080", StrToMultibyte(asInstance->GetHttpPort()));
        CPPUNIT_ASSERT(asInstance->GetHttpsPort() == L"9443");

        CPPUNIT_ASSERT(deps->m_xmlServerFilename == L"home/config/cells/cell/nodes/node/serverindex.xml");
        CPPUNIT_ASSERT(deps->m_xmlVersionFilename == L"home/properties/version/profile.version");
    }

    // Test with code that returns invalid XML from the ports file
    void testBadXmlServerFile()
    {
        SCXHandle<WebSphereAppServerInstanceTestPALDependencies> deps(new WebSphereAppServerInstanceTestPALDependencies());
        
        deps->SetBadXmlServerFile(true);

        SCXHandle<WebSphereAppServerInstance> asInstance( new WebSphereAppServerInstance(L"home", L"cell", L"node", L"profile", L"server1", deps) );

        asInstance->Update();

        CPPUNIT_ASSERT(asInstance->GetId() == L"profile-cell-node-server1");
        CPPUNIT_ASSERT(asInstance->GetDiskPath() == L"home/");
        CPPUNIT_ASSERT(asInstance->GetProfile() == L"profile");
        CPPUNIT_ASSERT(asInstance->GetCell() == L"cell");
        CPPUNIT_ASSERT(asInstance->GetNode() == L"node");
        CPPUNIT_ASSERT(asInstance->GetServer() == L"server1");
        CPPUNIT_ASSERT(asInstance->GetType() == L"WebSphere");
        CPPUNIT_ASSERT(asInstance->GetVersion() == L"7.0.0.0");
        CPPUNIT_ASSERT(asInstance->GetMajorVersion() == L"7");

        CPPUNIT_ASSERT(asInstance->GetHttpPort() == L"");
        CPPUNIT_ASSERT(asInstance->GetHttpsPort() == L"");

        CPPUNIT_ASSERT(deps->m_xmlServerFilename == L"home/config/cells/cell/nodes/node/serverindex.xml");
        CPPUNIT_ASSERT(deps->m_xmlVersionFilename == L"home/properties/version/profile.version");
    }

    // Test with code that returns invalid XML from the version file
    void testBadXmlVersionFile()
    {
        SCXHandle<WebSphereAppServerInstanceTestPALDependencies> deps(new WebSphereAppServerInstanceTestPALDependencies());
        
        deps->SetBadXmlVersionFile(true);

        SCXHandle<WebSphereAppServerInstance> asInstance( new WebSphereAppServerInstance(L"home", L"cell", L"node", L"profile", L"server1", deps) );

        asInstance->Update();

        CPPUNIT_ASSERT(asInstance->GetId() == L"profile-cell-node-server1");
        CPPUNIT_ASSERT(asInstance->GetDiskPath() == L"home/");
        CPPUNIT_ASSERT(asInstance->GetProfile() == L"profile");
        CPPUNIT_ASSERT(asInstance->GetCell() == L"cell");
        CPPUNIT_ASSERT(asInstance->GetNode() == L"node");
        CPPUNIT_ASSERT(asInstance->GetServer() == L"server1");
        CPPUNIT_ASSERT(asInstance->GetType() == L"WebSphere");
        CPPUNIT_ASSERT(asInstance->GetVersion() == L"");
        CPPUNIT_ASSERT(asInstance->GetMajorVersion() == L"");

        CPPUNIT_ASSERT_EQUAL("9080", StrToMultibyte(asInstance->GetHttpPort()));
        CPPUNIT_ASSERT(asInstance->GetHttpsPort() == L"9443");

        CPPUNIT_ASSERT(deps->m_xmlServerFilename == L"home/config/cells/cell/nodes/node/serverindex.xml");
        CPPUNIT_ASSERT(deps->m_xmlVersionFilename == L"home/properties/version/profile.version");
    }

        // Test removing non existent WebSphere Application Server with greater logic than checking profile.version
        // This change is neccessary for WebSphere Network Deployment configurations
        void testRemovingNetworkDeploymentInstallation()
        {
                SCXHandle<WebSphereAppServerInstanceTestPALDependencies> deps(new WebSphereAppServerInstanceTestPALDependencies());

                // Set WebSphere version to 8
                deps->SetVersion(8);

                // Create good instance with proper server directory
                // Note: Makefile.tests, as part of setup, creates directory
                //   structure under $(TARGET_DIR)/testfiles.
                SCXHandle<WebSphereAppServerInstance> asInstance(new WebSphereAppServerInstance(L"testfiles/websphere_networkdeployment/profiles/profile1/servers/server1", L"cell", L"node", L"profile", L"server1", deps));
                asInstance->Update();
                CPPUNIT_ASSERT_EQUAL(L"8.0.0.0", asInstance->GetVersion());
                
                // Create bad instance with incorrect server directory
                SCXHandle<WebSphereAppServerInstance> asInstance2(new WebSphereAppServerInstance(L"../../test/code/shared/testutils/websphere_badnetworkdeployment/profiles/profile1/", L"cell", L"node", L"profile", L"server1", deps));
                asInstance2->Update();
                CPPUNIT_ASSERT_EQUAL(L"8.0.0.0", asInstance2->GetVersion());

                CPPUNIT_ASSERT_EQUAL(true, asInstance->IsStillInstalled());
                CPPUNIT_ASSERT_EQUAL(false, asInstance2->IsStillInstalled());

        }
};

CPPUNIT_TEST_SUITE_REGISTRATION( WebSphereAppServerInstance_Test );
