/*--------------------------------------------------------------------------------
  Copyright (c) Microsoft Corporation.  All rights reserved.

  Created date    2011-05-18

  tomcat appserver data colletion test class.

*/
/*----------------------------------------------------------------------------*/
#include <scxcorelib/scxcmn.h>
#include <scxcorelib/stringaid.h>
#include <scxcorelib/scxfilesystem.h>
#include <testutils/scxunit.h>
#include <scxcorelib/scxprocess.h>

#include <tomcatappserverinstance.h>

#include <cppunit/extensions/HelperMacros.h>

using namespace SCXCoreLib;
using namespace SCXSystemLib;
using namespace std;

// Test dependencies used to get the XML content from string constants instead of from files
// Also has the ability to control some aspects of the XML to supply, to simulate different problems
class TomcatAppServerInstanceTestPALDependencies : public TomcatAppServerInstancePALDependencies
{
public:

    TomcatAppServerInstanceTestPALDependencies() : 
        m_versionFilename(L""), m_xmlServerFilename(L""), m_noVersionFile(false), m_noVersion(false), 
        m_noServerFile(false), m_emptyVersionFile(false), m_emptyServerFile(false), m_badXmlServerFile(false),
        m_NoProtocol(false), m_IncludeHTTPS(true), m_includeVersionScript(false)
    {}
	
	// Should the version script file be used when trying to determine version
	void SetIncludeVersionScript(bool includeVersionScript)
	{
		m_includeVersionScript = includeVersionScript;
	}

    // Should the we throw an exception when opening the version file
    void SetNoVersionFile(bool noVersionFile)
    {
        m_noVersionFile = noVersionFile;
    }

    // Should the version file contain the version string
    void SetNoVersion(bool noVersion)
    {
        m_noVersion = noVersion;
    }

    // Should the we throw an exception when opening the server file
    void SetNoServerFile(bool noServerFile)
    {
        m_noServerFile = noServerFile;
    }

    // Should the we return an empty string for the content of the version file
    void SetEmptyVersionFile(bool emptyVersionFile)
    {
        m_emptyVersionFile = emptyVersionFile;
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

    // Should the Connector's contain a protocol attribute
    void SetNoProtocol(bool noProtocol)
    {
        m_NoProtocol = noProtocol;
    }

    // Should the Service contain a HTTPS connector
    void SetIncludeHTTPS(bool includeHTTPS)
    {
        m_IncludeHTTPS = includeHTTPS;
    }

    virtual SCXHandle<std::istream> OpenVersionFile(wstring filename)
    {
        m_versionFilename = filename;

        SCXHandle<stringstream> filecontent( new stringstream );

        if (m_noVersionFile)
        {
            throw SCXFilePathNotFoundException(filename, SCXSRCLOCATION);
        }

        if (m_emptyVersionFile)
        {
            return filecontent;
        }

        *filecontent << "================================================================================" << endl;
        *filecontent << "           Licensed to the Apache Software Foundation (ASF) under one or more" << endl;
        *filecontent << "  contributor license agreements.  See the NOTICE file distributed with" << endl;
        *filecontent << "  this work for additional information regarding copyright ownership." << endl;
        *filecontent << "               The ASF licenses this file to You under the Apache License, Version 2.0" << endl;
        *filecontent << "               (the \"License\"); you may not use this file except in compliance with" << endl;
        *filecontent << "  the License.  You may obtain a copy of the License at" << endl;
        *filecontent << "" << endl;
        *filecontent << "                                    http://www.apache.org/licenses/LICENSE-2.0" << endl;
        *filecontent << "" << endl;
        *filecontent << "           Unless required by applicable law or agreed to in writing, software" << endl;
        *filecontent << "               distributed under the License is distributed on an \"AS IS\" BASIS," << endl;
        *filecontent << "               WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied." << endl;
        *filecontent << "  See the License for the specific language governing permissions and" << endl;
        *filecontent << "  limitations under the License." << endl;
        *filecontent << "================================================================================" << endl;
        *filecontent << "" << endl;
        *filecontent << "               $Id: RELEASE-NOTES 786654 2009-06-19 20:25:01Z markt $" << endl;
        *filecontent << "" << endl;
        *filecontent << "" << endl;

        if (!m_noVersion)
        {
            *filecontent << "                     Apache Tomcat Version 6.0.29 \r" << endl;
        }

        *filecontent << "                            Release Notes" << endl;
        *filecontent << "" << endl;
        *filecontent << "" << endl;
        *filecontent << "=============================" << endl;
        *filecontent << "KNOWN ISSUES IN THIS RELEASE:" << endl;
        *filecontent << "=============================" << endl;
        *filecontent << "" << endl;
        *filecontent << "* Dependency Changes" << endl;
        *filecontent << "* JNI Based Applications" << endl;
        *filecontent << "* Bundled APIs" << endl;
        *filecontent << "* Web application reloading and static fields in shared libraries" << endl;
        *filecontent << "* Tomcat on Linux" << endl;
        *filecontent << "* Enabling SSI and CGI Support" << endl;

        return filecontent;
    }

    virtual SCXHandle<std::istream> OpenXmlServerFile(wstring filename)
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

        *xmlcontent << "<?xml version='1.0' encoding='utf-8'?>" << endl;
        *xmlcontent << "<Server port=\"8005\" shutdown=\"SHUTDOWN\">" << endl;
        *xmlcontent << "  <Listener className=\"org.apache.catalina.core.JreMemoryLeakPreventionListener\" />" << endl;
        *xmlcontent << "  <Listener className=\"org.apache.catalina.mbeans.GlobalResourcesLifecycleListener\" />" << endl;
        *xmlcontent << "  <Service name=\"Catalina\">" << endl;
        *xmlcontent << "    <Connector port=\"8011\" protocol=\"MyProtocol\" redirectPort=\"8443\" />" << endl;
        *xmlcontent << "    <Connector port=\"8080\" "<< endl;
        if(!m_NoProtocol)
        {
            *xmlcontent << "           protocol=\"HTTP/1.1\" " << endl;
        }
        *xmlcontent << "               connectionTimeout=\"20000\" " << endl;
        *xmlcontent << "               redirectPort=\"8443\" />" << endl;

        if(m_IncludeHTTPS)
        {
            *xmlcontent << "    <Connector port=\"8443\" SSLEnabled=\"true\"" << endl;
            if(!m_NoProtocol)
            {
                *xmlcontent << "           protocol=\"HTTP/1.1\" " << endl;
            }
            *xmlcontent << "               maxThreads=\"150\" scheme=\"https\" secure=\"true\"" << endl;
            *xmlcontent << "               clientAuth=\"false\" sslProtocol=\"TLS\" />" << endl;
        }

        *xmlcontent << "    <Connector port=\"8009\" protocol=\"AJP/1.3\" redirectPort=\"8443\" />" << endl;
        *xmlcontent << "    <Engine name=\"Catalina\" defaultHost=\"localhost\">" << endl;
        *xmlcontent << "      <Realm className=\"org.apache.catalina.realm.UserDatabaseRealm\"" << endl;
        *xmlcontent << "             resourceName=\"UserDatabase\"/>" << endl;
        *xmlcontent << "      <Host name=\"localhost\"  appBase=\"webapps\"" << endl;
        *xmlcontent << "            unpackWARs=\"true\" autoDeploy=\"true\"" << endl;
        *xmlcontent << "            xmlValidation=\"false\" xmlNamespaceAware=\"false\">" << endl;
        *xmlcontent << "      </Host>" << endl;
        *xmlcontent << "    </Engine>" << endl;
        *xmlcontent << "  </Service>" << endl;
        
        if (!m_badXmlServerFile)
        {
            *xmlcontent << "</Server>" << endl;
        }

        return xmlcontent;
    }

	virtual wstring GetVersionScriptCommand(SCXCoreLib::SCXFilePath filepath)
    {
        wstring cli;
        if(m_includeVersionScript)
        {
            cli = L"./testfiles/TomcatVersionCheck.sh";
        }
        return cli;
    }

    wstring m_versionFilename;
    wstring m_xmlServerFilename;
    bool m_noVersionFile;
    bool m_noVersion;
    bool m_noServerFile;
    bool m_emptyVersionFile;
    bool m_emptyServerFile;
    bool m_badXmlServerFile;
    bool m_NoProtocol;
    bool m_IncludeHTTPS;
	bool m_includeVersionScript;
};

class TomcatAppServerInstance_Test : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE( TomcatAppServerInstance_Test );

    CPPUNIT_TEST( testAllGood );
    CPPUNIT_TEST( testNoVersion );
    CPPUNIT_TEST( testNoServerFile );
    CPPUNIT_TEST( testNoVersionFile );
    CPPUNIT_TEST( testEmptyServerFile );
    CPPUNIT_TEST( testEmptyVersionFile );
    CPPUNIT_TEST( testBadXmlServerFile );
    CPPUNIT_TEST( testAllGoodTomcat5 );
    CPPUNIT_TEST( testAllGoodNoHTTPS );
	CPPUNIT_TEST( testVersionScript );

    CPPUNIT_TEST_SUITE_END();

    public:

    void setUp(void)
    {
    }

    void tearDown(void)
    {
    }

	// Test to make sure we can retrieve version from version.sh script
	void testVersionScript()
	{
        SCXHandle<TomcatAppServerInstanceTestPALDependencies> deps(new TomcatAppServerInstanceTestPALDependencies());
        
		deps->SetNoVersionFile(true);
		deps->SetIncludeVersionScript(true);

        SCXHandle<TomcatAppServerInstance> asInstance( new TomcatAppServerInstance(L"id/", L"home/", deps) );

        asInstance->Update();

        CPPUNIT_ASSERT_EQUAL(L"id/", asInstance->GetId());
        CPPUNIT_ASSERT_EQUAL(L"id/", asInstance->GetDiskPath());
        CPPUNIT_ASSERT_EQUAL(L"Tomcat", asInstance->GetType());

        CPPUNIT_ASSERT_EQUAL(L"8.0.9.0", asInstance->GetVersion());
        CPPUNIT_ASSERT_EQUAL(L"8", asInstance->GetMajorVersion());

        CPPUNIT_ASSERT_EQUAL(L"8080", asInstance->GetHttpPort());
        CPPUNIT_ASSERT_EQUAL(L"8443", asInstance->GetHttpsPort());

	}

    // Test with XML not containing the HTTPBinding property, but which do contain the HTTP section
    void testAllGood()
    {
        SCXHandle<TomcatAppServerInstanceTestPALDependencies> deps(new TomcatAppServerInstanceTestPALDependencies());
        
        SCXHandle<TomcatAppServerInstance> asInstance( new TomcatAppServerInstance(L"id/", L"home/", deps) );

        asInstance->Update();

        CPPUNIT_ASSERT(asInstance->GetId() == L"id/");
        CPPUNIT_ASSERT(asInstance->GetDiskPath() == L"id/");
        CPPUNIT_ASSERT(asInstance->GetType() == L"Tomcat");

        CPPUNIT_ASSERT(asInstance->GetVersion() == L"6.0.29");
        CPPUNIT_ASSERT(asInstance->GetMajorVersion() == L"6");

        CPPUNIT_ASSERT(asInstance->GetHttpPort() == L"8080");
        CPPUNIT_ASSERT(asInstance->GetHttpsPort() == L"8443");

        CPPUNIT_ASSERT(deps->m_versionFilename == L"home/RELEASE-NOTES");
        CPPUNIT_ASSERT(deps->m_xmlServerFilename == L"id/conf/server.xml");
    }

    // Test with XML not containing the section we get the version from 
    void testNoVersion()
    {
        SCXHandle<TomcatAppServerInstanceTestPALDependencies> deps(new TomcatAppServerInstanceTestPALDependencies());

        deps->SetNoVersion(true);
        
        SCXHandle<TomcatAppServerInstance> asInstance( new TomcatAppServerInstance(L"id/", L"home/", deps) );

        asInstance->Update();

        CPPUNIT_ASSERT(asInstance->GetId() == L"id/");
        CPPUNIT_ASSERT(asInstance->GetDiskPath() == L"id/");
        CPPUNIT_ASSERT(asInstance->GetType() == L"Tomcat");

        CPPUNIT_ASSERT(asInstance->GetVersion() == L"");
        CPPUNIT_ASSERT(asInstance->GetMajorVersion() == L"");

        CPPUNIT_ASSERT(asInstance->GetHttpPort() == L"8080");
        CPPUNIT_ASSERT(asInstance->GetHttpsPort() == L"8443");

        CPPUNIT_ASSERT(deps->m_versionFilename == L"home/RELEASE-NOTES");
        CPPUNIT_ASSERT(deps->m_xmlServerFilename == L"id/conf/server.xml");
    }

    // Test with code that throw exception when we try to open the ports file
    void testNoServerFile()
    {
        SCXHandle<TomcatAppServerInstanceTestPALDependencies> deps(new TomcatAppServerInstanceTestPALDependencies());
        
        deps->SetNoServerFile(true);

        SCXHandle<TomcatAppServerInstance> asInstance( new TomcatAppServerInstance(L"id/", L"home/", deps) );

        asInstance->Update();

        CPPUNIT_ASSERT(asInstance->GetId() == L"id/");
        CPPUNIT_ASSERT(asInstance->GetDiskPath() == L"id/");
        CPPUNIT_ASSERT(asInstance->GetType() == L"Tomcat");

        CPPUNIT_ASSERT(asInstance->GetVersion() == L"6.0.29");
        CPPUNIT_ASSERT(asInstance->GetMajorVersion() == L"6");

        CPPUNIT_ASSERT(asInstance->GetHttpPort() == L"");
        CPPUNIT_ASSERT(asInstance->GetHttpsPort() == L"");

        CPPUNIT_ASSERT(deps->m_versionFilename == L"home/RELEASE-NOTES");
        CPPUNIT_ASSERT(deps->m_xmlServerFilename == L"id/conf/server.xml");
    }

    // Test with code that throw exception when we try to open the version file
    void testNoVersionFile()
    {
        SCXHandle<TomcatAppServerInstanceTestPALDependencies> deps(new TomcatAppServerInstanceTestPALDependencies());
        
        deps->SetNoVersionFile(true);

        SCXHandle<TomcatAppServerInstance> asInstance( new TomcatAppServerInstance(L"id/", L"home/", deps) );

        asInstance->Update();

        CPPUNIT_ASSERT(asInstance->GetId() == L"id/");
        CPPUNIT_ASSERT(asInstance->GetDiskPath() == L"id/");
        CPPUNIT_ASSERT(asInstance->GetType() == L"Tomcat");

        CPPUNIT_ASSERT(asInstance->GetVersion() == L"");
        CPPUNIT_ASSERT(asInstance->GetMajorVersion() == L"");

        CPPUNIT_ASSERT(asInstance->GetHttpPort() == L"8080");
        CPPUNIT_ASSERT(asInstance->GetHttpsPort() == L"8443");

        CPPUNIT_ASSERT(deps->m_versionFilename == L"home/RELEASE-NOTES");
        CPPUNIT_ASSERT(deps->m_xmlServerFilename == L"id/conf/server.xml");
    }

    // Test with code that returns an empty string from the ports file
    void testEmptyServerFile()
    {
        SCXHandle<TomcatAppServerInstanceTestPALDependencies> deps(new TomcatAppServerInstanceTestPALDependencies());
        
        deps->SetEmptyServerFile(true);

        SCXHandle<TomcatAppServerInstance> asInstance( new TomcatAppServerInstance(L"id/", L"home/", deps) );

        asInstance->Update();

        CPPUNIT_ASSERT(asInstance->GetId() == L"id/");
        CPPUNIT_ASSERT(asInstance->GetDiskPath() == L"id/");
        CPPUNIT_ASSERT(asInstance->GetType() == L"Tomcat");

        CPPUNIT_ASSERT(asInstance->GetVersion() == L"6.0.29");
        CPPUNIT_ASSERT(asInstance->GetMajorVersion() == L"6");

        CPPUNIT_ASSERT(asInstance->GetHttpPort() == L"");
        CPPUNIT_ASSERT(asInstance->GetHttpsPort() == L"");

        CPPUNIT_ASSERT(deps->m_versionFilename == L"home/RELEASE-NOTES");
        CPPUNIT_ASSERT(deps->m_xmlServerFilename == L"id/conf/server.xml");
    }

    // Test with code that returns an empty string from the version file
    void testEmptyVersionFile()
    {
        SCXHandle<TomcatAppServerInstanceTestPALDependencies> deps(new TomcatAppServerInstanceTestPALDependencies());
        
        deps->SetEmptyVersionFile(true);

        SCXHandle<TomcatAppServerInstance> asInstance( new TomcatAppServerInstance(L"id/", L"home/", deps) );

        asInstance->Update();

        CPPUNIT_ASSERT(asInstance->GetId() == L"id/");
        CPPUNIT_ASSERT(asInstance->GetDiskPath() == L"id/");
        CPPUNIT_ASSERT(asInstance->GetType() == L"Tomcat");

        CPPUNIT_ASSERT(asInstance->GetVersion() == L"");
        CPPUNIT_ASSERT(asInstance->GetMajorVersion() == L"");

        CPPUNIT_ASSERT(asInstance->GetHttpPort() == L"8080");
        CPPUNIT_ASSERT(asInstance->GetHttpsPort() == L"8443");

        CPPUNIT_ASSERT(deps->m_versionFilename == L"home/RELEASE-NOTES");
        CPPUNIT_ASSERT(deps->m_xmlServerFilename == L"id/conf/server.xml");
    }

    // Test with code that returns invalid XML from the ports file
    void testBadXmlServerFile()
    {
        SCXHandle<TomcatAppServerInstanceTestPALDependencies> deps(new TomcatAppServerInstanceTestPALDependencies());
        
        deps->SetBadXmlServerFile(true);

        SCXHandle<TomcatAppServerInstance> asInstance( new TomcatAppServerInstance(L"id", L"home", deps) );

        asInstance->Update();

        CPPUNIT_ASSERT(asInstance->GetId() == L"id/");
        CPPUNIT_ASSERT(asInstance->GetDiskPath() == L"id/");
        CPPUNIT_ASSERT(asInstance->GetType() == L"Tomcat");

        CPPUNIT_ASSERT(asInstance->GetVersion() == L"6.0.29");
        CPPUNIT_ASSERT(asInstance->GetMajorVersion() == L"6");

        CPPUNIT_ASSERT(asInstance->GetHttpPort() == L"");
        CPPUNIT_ASSERT(asInstance->GetHttpsPort() == L"");

        CPPUNIT_ASSERT(deps->m_versionFilename == L"home/RELEASE-NOTES");
        CPPUNIT_ASSERT(deps->m_xmlServerFilename == L"id/conf/server.xml");
    }

    // Test with XML not containing the protocol attribute for the Connector
    // this is the default Tomcat 5 configuration
    void testAllGoodTomcat5()
    {
        SCXHandle<TomcatAppServerInstanceTestPALDependencies> deps(new TomcatAppServerInstanceTestPALDependencies());

        deps->SetNoProtocol(true);

        SCXHandle<TomcatAppServerInstance> asInstance( new TomcatAppServerInstance(L"id/", L"home/", deps) );

        asInstance->Update();

        CPPUNIT_ASSERT(asInstance->GetId() == L"id/");
        CPPUNIT_ASSERT(asInstance->GetDiskPath() == L"id/");
        CPPUNIT_ASSERT(asInstance->GetType() == L"Tomcat");

        CPPUNIT_ASSERT(asInstance->GetVersion() == L"6.0.29");
        CPPUNIT_ASSERT(asInstance->GetMajorVersion() == L"6");

        CPPUNIT_ASSERT(asInstance->GetHttpPort() == L"8080");
        CPPUNIT_ASSERT(asInstance->GetHttpsPort() == L"8443");

        CPPUNIT_ASSERT(deps->m_versionFilename == L"home/RELEASE-NOTES");
        CPPUNIT_ASSERT(deps->m_xmlServerFilename == L"id/conf/server.xml");
    }

    // Test with XML not containing the secure protocol attribute for the Connector
    // this is the default Tomcat setting i.e. no HTTPS configured
    void testAllGoodNoHTTPS()
    {
        SCXHandle<TomcatAppServerInstanceTestPALDependencies> deps(new TomcatAppServerInstanceTestPALDependencies());

        deps->SetIncludeHTTPS(false);
        
        SCXHandle<TomcatAppServerInstance> asInstance( new TomcatAppServerInstance(L"id/", L"home/", deps) );

        asInstance->Update();

        CPPUNIT_ASSERT(asInstance->GetId() == L"id/");
        CPPUNIT_ASSERT(asInstance->GetDiskPath() == L"id/");
        CPPUNIT_ASSERT(asInstance->GetType() == L"Tomcat");

        CPPUNIT_ASSERT(asInstance->GetVersion() == L"6.0.29");
        CPPUNIT_ASSERT(asInstance->GetMajorVersion() == L"6");

        CPPUNIT_ASSERT(asInstance->GetHttpPort() == L"8080");
        CPPUNIT_ASSERT(asInstance->GetHttpsPort() == L"");

        CPPUNIT_ASSERT(deps->m_versionFilename == L"home/RELEASE-NOTES");
        CPPUNIT_ASSERT(deps->m_xmlServerFilename == L"id/conf/server.xml");
    }

};

CPPUNIT_TEST_SUITE_REGISTRATION( TomcatAppServerInstance_Test );
