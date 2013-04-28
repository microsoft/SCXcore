/*--------------------------------------------------------------------------------
  Copyright (c) Microsoft Corporation.  All rights reserved.

  Created date    2011-05-18

  appserver data colletion test class.

*/
/*----------------------------------------------------------------------------*/
#include <scxcorelib/scxcmn.h>
#include <scxcorelib/stringaid.h>
#include <testutils/scxunit.h>

#include <appserverinstance.h>

#include <cppunit/extensions/HelperMacros.h>

using namespace SCXCoreLib;
using namespace SCXSystemLib;
using namespace std;


class AppServerInstance_Test : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE( AppServerInstance_Test );

    CPPUNIT_TEST( testAllMembers );
    CPPUNIT_TEST( testSetIsDeepMonitoredHTTP );
    CPPUNIT_TEST( testSetIsDeepMonitoredHTTPS );
    CPPUNIT_TEST( testSetIsDeepMonitored );
    CPPUNIT_TEST( testSetIsRunning );
    CPPUNIT_TEST( testOperatorEqualsTrue );
    CPPUNIT_TEST( testOperatorEqualsFalseOnDiskPath );
    CPPUNIT_TEST( testOperatorEqualsFalseOnHttpPort );
    CPPUNIT_TEST( testOperatorEqualsFalseOnHttpsPort );
    CPPUNIT_TEST( testOperatorEqualsFalseOnIsDeepMonitored );
    CPPUNIT_TEST( testOperatorEqualsFalseOnIsRunning );
    CPPUNIT_TEST( testOperatorEqualsFalseOnType );
    CPPUNIT_TEST( testOperatorEqualsFalseOnVersion );
    CPPUNIT_TEST( testExtractMajorVersion );
    CPPUNIT_TEST_SUITE_END();

    public:

    void setUp(void)
    {
    }

    void tearDown(void)
    {
    }

    void testAllMembers()
    {
        SCXCoreLib::SCXHandle<AppServerInstance> asInstance( new AppServerInstance(L"id", L"type") );

        // This call shouldn't do anything
        asInstance->Update();

        CPPUNIT_ASSERT(asInstance->GetId() == L"id");
        CPPUNIT_ASSERT(asInstance->GetHttpPort() == L"");
        CPPUNIT_ASSERT(asInstance->GetHttpsPort() == L"");
        CPPUNIT_ASSERT(asInstance->GetVersion() == L"");
        CPPUNIT_ASSERT(asInstance->GetMajorVersion() == L"");
        CPPUNIT_ASSERT(asInstance->GetDiskPath() == L"id");
        CPPUNIT_ASSERT(asInstance->GetType() == L"type");
        CPPUNIT_ASSERT(asInstance->GetIsDeepMonitored() == false);
        CPPUNIT_ASSERT(asInstance->GetIsRunning() == true);
    }

    void testSetIsDeepMonitoredHTTP()
    {
        SCXCoreLib::SCXHandle<AppServerInstance> asInstance( new AppServerInstance(L"id", L"type") );

        asInstance->SetHttpPort(L"8080");
        CPPUNIT_ASSERT(asInstance->GetIsDeepMonitored() == false);
        CPPUNIT_ASSERT(asInstance->GetHttpPort() == L"8080");

        asInstance->SetIsDeepMonitored(true, L"HTTP");

        CPPUNIT_ASSERT(asInstance->GetIsDeepMonitored() == true);
        CPPUNIT_ASSERT(asInstance->GetPort() == L"8080");
        CPPUNIT_ASSERT(asInstance->GetProtocol() == L"HTTP");
    }

    void testSetIsDeepMonitoredHTTPS()
    {
        SCXCoreLib::SCXHandle<AppServerInstance> asInstance( new AppServerInstance(L"id", L"type") );

        asInstance->SetHttpsPort(L"8443");
        CPPUNIT_ASSERT(asInstance->GetIsDeepMonitored() == false);
        CPPUNIT_ASSERT(asInstance->GetHttpsPort() == L"8443");

        asInstance->SetIsDeepMonitored(true, L"HTTPS");

        CPPUNIT_ASSERT(asInstance->GetIsDeepMonitored() == true);
        CPPUNIT_ASSERT(asInstance->GetPort() == L"8443");
        CPPUNIT_ASSERT(asInstance->GetProtocol() == L"HTTPS");
    }

    void testSetIsDeepMonitored()
    {
        SCXCoreLib::SCXHandle<AppServerInstance> asInstance( new AppServerInstance(L"id", L"type") );

        asInstance->SetHttpPort(L"8080");
        CPPUNIT_ASSERT(asInstance->GetIsDeepMonitored() == false);
        CPPUNIT_ASSERT(asInstance->GetHttpPort() == L"8080");

        asInstance->SetIsDeepMonitored(true, L"ABCD");

        CPPUNIT_ASSERT(asInstance->GetIsDeepMonitored() == true);
        CPPUNIT_ASSERT(asInstance->GetPort() == L"8080");
        CPPUNIT_ASSERT(asInstance->GetProtocol() == L"HTTP");
    }

    void testSetIsRunning()
    {
        SCXCoreLib::SCXHandle<AppServerInstance> asInstance( new AppServerInstance(L"id", L"type") );

        CPPUNIT_ASSERT(asInstance->GetIsRunning() == true);

        asInstance->SetIsRunning(false);

        CPPUNIT_ASSERT(asInstance->GetIsRunning() == false);
    }

    /*-------------------------------------------------------------------*/
    /**
       Verify Operator== works for two identical objects
    */

    void testOperatorEqualsTrue()
    {
        SCXCoreLib::SCXHandle<AppServerInstance> cutting( 
                new AppServerInstance(L"/opt/jboss", L"type") );
        SCXCoreLib::SCXHandle<AppServerInstance> shipping( 
                new AppServerInstance(L"/opt/jboss", L"type") );

        // Verify that equal works for itself
        CPPUNIT_ASSERT_MESSAGE("AppServerInstance should equal itself", 
                *cutting == *cutting);

        // Verify that equal works for two identical objects
        CPPUNIT_ASSERT_MESSAGE(
                "AppServerInstance should equal an identical object",
                *cutting == *shipping);
        CPPUNIT_ASSERT( *shipping == *cutting );
    }

    /*-------------------------------------------------------------------*/
    /**
       Verify Operator==/Operator!= finds difference for different Disk Paths
    */
    void testOperatorEqualsFalseOnDiskPath()
    {
        SCXCoreLib::SCXHandle<AppServerInstance> cutting( 
                new AppServerInstance(L"/opt/jboss1", L"type") );
        SCXCoreLib::SCXHandle<AppServerInstance> shipping( 
                new AppServerInstance(L"/opt/jboss2", L"type") );

        CPPUNIT_ASSERT_MESSAGE(
                "AppServerInstance should not be equal for different DiskPaths",
                *cutting != *shipping);
        CPPUNIT_ASSERT( *shipping != *cutting );
    }

    /*-------------------------------------------------------------------*/
    /**
       Verify Operator==/Operator!= finds difference for different HTTP ports
    */
    void testOperatorEqualsFalseOnHttpPort()
    {
        SCXCoreLib::SCXHandle<AppServerInstance> cutting( 
                new AppServerInstance(L"/opt/jboss", L"type") );
        SCXCoreLib::SCXHandle<AppServerInstance> shipping( 
                new AppServerInstance(L"/opt/jboss", L"type") );

        cutting->SetHttpPort(L"8080");
        shipping->SetHttpPort(L"8081");

        CPPUNIT_ASSERT_MESSAGE(
                "AppServerInstance should not be equal for different HttpPorts",
                *cutting != *shipping);
        CPPUNIT_ASSERT( *shipping != *cutting );
    }

    /*-------------------------------------------------------------------*/
    /**
       Verify Operator==/Operator!= finds difference for different HTTPS ports
    */
    void testOperatorEqualsFalseOnHttpsPort()
    {
        SCXCoreLib::SCXHandle<AppServerInstance> cutting( 
                new AppServerInstance(L"/opt/jboss", L"type") );
        SCXCoreLib::SCXHandle<AppServerInstance> shipping( 
                new AppServerInstance(L"/opt/jboss", L"type") );

        cutting->SetHttpsPort(L"8443");
        shipping->SetHttpsPort(L"8444");

        CPPUNIT_ASSERT_MESSAGE(
                "AppServerInstance should not be equal for different HttpsPorts",
                *cutting != *shipping);
        CPPUNIT_ASSERT( *shipping != *cutting );
    }

    /*-------------------------------------------------------------------*/
    /**
       Verify Operator==/Operator!= finds difference for IsDeepMonitored
    */
    void testOperatorEqualsFalseOnIsDeepMonitored()
    {
        SCXCoreLib::SCXHandle<AppServerInstance> cutting( 
                new AppServerInstance(L"/opt/jboss", L"type") );
        SCXCoreLib::SCXHandle<AppServerInstance> shipping( 
                new AppServerInstance(L"/opt/jboss", L"type") );

        cutting->SetIsDeepMonitored(true, L"HTTP");
        shipping->SetIsDeepMonitored(false, L"HTTP");

        CPPUNIT_ASSERT_MESSAGE(
                "AppServerInstance should not be equal for differences in deep monitoring",
                *cutting != *shipping);
        CPPUNIT_ASSERT( *shipping != *cutting );
    }

    /*-------------------------------------------------------------------*/
    /**
       Verify Operator==/Operator!= finds difference for IsRunning
    */
    void testOperatorEqualsFalseOnIsRunning()
    {
        SCXCoreLib::SCXHandle<AppServerInstance> cutting( 
                new AppServerInstance(L"/opt/jboss", L"type") );
        SCXCoreLib::SCXHandle<AppServerInstance> shipping( 
                new AppServerInstance(L"/opt/jboss", L"type") );

        cutting->SetIsRunning(true);
        shipping->SetIsRunning(false);

        CPPUNIT_ASSERT_MESSAGE(
                "AppServerInstance should not be equal if one is running and the other is not",
                *cutting != *shipping);
        CPPUNIT_ASSERT( *shipping != *cutting );
    }

    /*-------------------------------------------------------------------*/
    /**
       Verify Operator==/Operator!= finds difference for different Type
    */
    void testOperatorEqualsFalseOnType()
    {
        SCXCoreLib::SCXHandle<AppServerInstance> cutting( 
                new AppServerInstance(L"/opt/jboss", L"TOMCAT") );
        SCXCoreLib::SCXHandle<AppServerInstance> shipping( 
                new AppServerInstance(L"/opt/jboss", L"JBOSS") );

        CPPUNIT_ASSERT_MESSAGE(
                "AppServerInstance should not be equal for different App Server types",
                *cutting != *shipping);
        CPPUNIT_ASSERT( *shipping != *cutting );
    }

    /*-------------------------------------------------------------------*/
    /**
       Verify Operator==/Operator!= finds difference for different Version
    */
    void testOperatorEqualsFalseOnVersion()
    {
        SCXCoreLib::SCXHandle<AppServerInstance> cutting( 
                new AppServerInstance(L"/opt/jboss", L"JBOSS") );
        SCXCoreLib::SCXHandle<AppServerInstance> shipping( 
                new AppServerInstance(L"/opt/jboss", L"JBOSS") );

        cutting->SetVersion(L"5.1.0-GA");
        shipping->SetVersion(L"4.2.0");

        CPPUNIT_ASSERT_MESSAGE(
                "AppServerInstance should not be equal for different App Server versions",
                *cutting != *shipping);
        CPPUNIT_ASSERT( *shipping != *cutting );
    }

    /*-------------------------------------------------------------------*/
    /**
       Test the extraction of the major version from the version number
    */
    void testExtractMajorVersion()
    {
        SCXCoreLib::SCXHandle<AppServerInstance> asinst( new AppServerInstance(L"/opt/jboss", L"JBOSS") );

        asinst->SetVersion(L"5.1.0-GA");
        CPPUNIT_ASSERT(asinst->GetMajorVersion() == L"5");

        asinst->SetVersion(L"4.2.0");
        CPPUNIT_ASSERT(asinst->GetMajorVersion() == L"4");

        asinst->SetVersion(L"10.3.2");
        CPPUNIT_ASSERT(asinst->GetMajorVersion() == L"10");
    }


};

CPPUNIT_TEST_SUITE_REGISTRATION( AppServerInstance_Test );
