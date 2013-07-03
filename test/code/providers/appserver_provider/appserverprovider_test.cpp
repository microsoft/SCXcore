/*--------------------------------------------------------------------------------
  Copyright (c) Microsoft Corporation.  All rights reserved.

*/
/**
   \file

   \brief       Tests for the appserver provider

   \date        2011-05-05

*/
/*----------------------------------------------------------------------------*/

#include <scxcorelib/scxcmn.h>
#include <scxsystemlib/scxostypeinfo.h>
#include <testutils/scxunit.h>
#include <testutils/providertestutils.h>
#include "appserver/appserverenumeration.h"
#include "appserver/websphereappserverinstance.h"
#include "appserver/appserverprovider.h"
#include "SCX_Application_Server_Class_Provider.h"

using namespace SCXCore;
using namespace SCXCoreLib;
using namespace SCXSystemLib;

class AppServerTestEnumeration : public AppServerEnumeration
{
public:
    AppServerTestEnumeration() {};
    ~AppServerTestEnumeration() {};

    virtual void Init()
    {
        Update(false);
    };

    virtual void Update(bool /*updateInstances*/)
    {
        if (Size() == 0)
        {
            SCXHandle<AppServerInstance> inst = SCXHandle<AppServerInstance>(
                new AppServerInstance(L"/opt/jboss-5.1.0.GA/", L"JBoss"));

            inst->SetHttpPort(L"8280");
            inst->SetHttpsPort(L"8643");
            inst->SetVersion(L"5.1.0.GA");

            AddInstance(inst);

            SCXHandle<WebSphereAppServerInstance> inst2 = SCXHandle<WebSphereAppServerInstance>(
                new WebSphereAppServerInstance(L"/opt/websphere/AppServer/profiles/AppSrv01/",
                L"Node01Cell", L"Node01", L"AppSrv01", L"server1"));

            inst2->SetHttpPort(L"9080");
            inst2->SetHttpsPort(L"9443");
            inst2->SetVersion(L"7.0.0.0");

            AddInstance(inst2);
        }
    };

    virtual void CleanUp() {};
};

class AppServerProviderTestPALDependencies : public AppServerProviderPALDependencies
{
public:
    virtual ~AppServerProviderTestPALDependencies() {};
    
    virtual SCXHandle<AppServerEnumeration> CreateEnum()
    {
        return SCXHandle<AppServerEnumeration>(new AppServerTestEnumeration());
    }
};

class SCXASProviderTest : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE( SCXASProviderTest );

    CPPUNIT_TEST( callDumpStringForCoverage );
    CPPUNIT_TEST( TestDoEnumInstances );
    CPPUNIT_TEST( TestDoGetInstanceGood );
    CPPUNIT_TEST( TestDoGetInstanceNotFound );
    CPPUNIT_TEST( TestEnumerateKeysOnly );
    CPPUNIT_TEST( TestVerifyKeyCompletePartial );
    CPPUNIT_TEST( TestDoInvokeMethodNoAppServer );
    CPPUNIT_TEST( TestDoInvokeMethodMissingArg );
    CPPUNIT_TEST( TestDoInvokeMethodGood );

    CPPUNIT_TEST_SUITE_END();

private:
    std::vector<std::wstring> m_keyNames;

public:
    void setUp(void)
    {
        m_keyNames.push_back(L"Name");

        std::wostringstream errMsg;
        SCXCore::g_AppServerProvider.UpdateDependencies(SCXCoreLib::SCXHandle<AppServerProviderPALDependencies>(
            new AppServerProviderTestPALDependencies()));
        TestableContext context;
        SetUpAgent<mi::SCX_Application_Server_Class_Provider>(context, CALL_LOCATION(errMsg));
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, true, context.WasRefuseUnloadCalled() );
    }

    void tearDown(void)
    {
        std::wostringstream errMsg;
        TestableContext context;
        TearDownAgent<mi::SCX_Application_Server_Class_Provider>(context, CALL_LOCATION(errMsg));
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, false, context.WasRefuseUnloadCalled() );
    }

    void callDumpStringForCoverage()
    {
        CPPUNIT_ASSERT(SCXCore::g_AppServerProvider.DumpString().find(L"ApplicationServerProvider") != std::wstring::npos);
    }

    void TestDoEnumInstances()
    {
        std::wostringstream errMsg;
        TestableContext context;

        StandardTestEnumerateInstances<mi::SCX_Application_Server_Class_Provider>(
            m_keyNames, context, CALL_LOCATION(errMsg));

        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, 2u, context.Size());
        ValidateInstance0(context[0], CALL_LOCATION(errMsg));
        ValidateInstance1(context[1], CALL_LOCATION(errMsg));
    }

    void ValidateInstance0(const TestableInstance& instance, std::wostringstream &errMsg)
    {
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, L"/opt/jboss-5.1.0.GA/",
            instance.GetKey(L"Name", CALL_LOCATION(errMsg)));
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, 17u, instance.GetNumberOfProperties());
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, L"SCX Application Server", instance.GetProperty(
            L"Caption", CALL_LOCATION(errMsg)).GetValue_MIString(CALL_LOCATION(errMsg)));
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, L"Represents a JEE Application Server", instance.GetProperty(
            L"Description", CALL_LOCATION(errMsg)).GetValue_MIString(CALL_LOCATION(errMsg)));
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, L"8280", instance.GetProperty(
            L"HttpPort", CALL_LOCATION(errMsg)).GetValue_MIString(CALL_LOCATION(errMsg)));
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, L"8643", instance.GetProperty(
            L"HttpsPort", CALL_LOCATION(errMsg)).GetValue_MIString(CALL_LOCATION(errMsg)));
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, L"5.1.0.GA", instance.GetProperty(
            L"Version", CALL_LOCATION(errMsg)).GetValue_MIString(CALL_LOCATION(errMsg)));
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, L"5", instance.GetProperty(
            L"MajorVersion", CALL_LOCATION(errMsg)).GetValue_MIString(CALL_LOCATION(errMsg)));
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, L"", instance.GetProperty(
            L"Port", CALL_LOCATION(errMsg)).GetValue_MIString(CALL_LOCATION(errMsg)));
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, L"", instance.GetProperty(
            L"Protocol", CALL_LOCATION(errMsg)).GetValue_MIString(CALL_LOCATION(errMsg)));
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, L"/opt/jboss-5.1.0.GA/", instance.GetProperty(
            L"DiskPath", CALL_LOCATION(errMsg)).GetValue_MIString(CALL_LOCATION(errMsg)));
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, L"JBoss", instance.GetProperty(
            L"Type", CALL_LOCATION(errMsg)).GetValue_MIString(CALL_LOCATION(errMsg)));
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, false, instance.GetProperty(
            L"IsDeepMonitored", CALL_LOCATION(errMsg)).GetValue_MIBoolean(CALL_LOCATION(errMsg)));
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, true, instance.GetProperty(
            L"IsRunning", CALL_LOCATION(errMsg)).GetValue_MIBoolean(CALL_LOCATION(errMsg)));
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, L"", instance.GetProperty(
            L"Profile", CALL_LOCATION(errMsg)).GetValue_MIString(CALL_LOCATION(errMsg)));
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, L"", instance.GetProperty(
            L"Cell", CALL_LOCATION(errMsg)).GetValue_MIString(CALL_LOCATION(errMsg)));
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, L"", instance.GetProperty(
            L"Node", CALL_LOCATION(errMsg)).GetValue_MIString(CALL_LOCATION(errMsg)));
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, L"", instance.GetProperty(
            L"Server", CALL_LOCATION(errMsg)).GetValue_MIString(CALL_LOCATION(errMsg)));
    }

    void ValidateInstance1(const TestableInstance& instance, std::wostringstream &errMsg)
    {
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, L"AppSrv01-Node01Cell-Node01-server1",
            instance.GetKey(L"Name", CALL_LOCATION(errMsg)));
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, 17u, instance.GetNumberOfProperties());
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, L"SCX Application Server", instance.GetProperty(
            L"Caption", CALL_LOCATION(errMsg)).GetValue_MIString(CALL_LOCATION(errMsg)));
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, L"Represents a JEE Application Server", instance.GetProperty(
            L"Description", CALL_LOCATION(errMsg)).GetValue_MIString(CALL_LOCATION(errMsg)));
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, L"9080", instance.GetProperty(
            L"HttpPort", CALL_LOCATION(errMsg)).GetValue_MIString(CALL_LOCATION(errMsg)));
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, L"9443", instance.GetProperty(
            L"HttpsPort", CALL_LOCATION(errMsg)).GetValue_MIString(CALL_LOCATION(errMsg)));
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, L"7.0.0.0", instance.GetProperty(
            L"Version", CALL_LOCATION(errMsg)).GetValue_MIString(CALL_LOCATION(errMsg)));
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, L"7", instance.GetProperty(
            L"MajorVersion", CALL_LOCATION(errMsg)).GetValue_MIString(CALL_LOCATION(errMsg)));
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, L"", instance.GetProperty(
            L"Port", CALL_LOCATION(errMsg)).GetValue_MIString(CALL_LOCATION(errMsg)));
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, L"", instance.GetProperty(
            L"Protocol", CALL_LOCATION(errMsg)).GetValue_MIString(CALL_LOCATION(errMsg)));
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, L"/opt/websphere/AppServer/profiles/AppSrv01/", instance.GetProperty(
            L"DiskPath", CALL_LOCATION(errMsg)).GetValue_MIString(CALL_LOCATION(errMsg)));
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, L"WebSphere", instance.GetProperty(
            L"Type", CALL_LOCATION(errMsg)).GetValue_MIString(CALL_LOCATION(errMsg)));
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, false, instance.GetProperty(
            L"IsDeepMonitored", CALL_LOCATION(errMsg)).GetValue_MIBoolean(CALL_LOCATION(errMsg)));
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, true, instance.GetProperty(
            L"IsRunning", CALL_LOCATION(errMsg)).GetValue_MIBoolean(CALL_LOCATION(errMsg)));
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, L"AppSrv01", instance.GetProperty(
            L"Profile", CALL_LOCATION(errMsg)).GetValue_MIString(CALL_LOCATION(errMsg)));
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, L"Node01Cell", instance.GetProperty(
            L"Cell", CALL_LOCATION(errMsg)).GetValue_MIString(CALL_LOCATION(errMsg)));
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, L"Node01", instance.GetProperty(
            L"Node", CALL_LOCATION(errMsg)).GetValue_MIString(CALL_LOCATION(errMsg)));
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, L"server1", instance.GetProperty(
            L"Server", CALL_LOCATION(errMsg)).GetValue_MIString(CALL_LOCATION(errMsg)));
    }

    void TestDoGetInstanceGood()
    {
        std::wostringstream errMsg;

        std::vector<std::wstring> keyValues0;
        keyValues0.push_back(L"/opt/jboss-5.1.0.GA/");
        TestableContext context0;
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, MI_RESULT_OK, (GetInstance<mi::SCX_Application_Server_Class_Provider,
            mi::SCX_Application_Server_Class>(m_keyNames, keyValues0, context0, CALL_LOCATION(errMsg))));
        ValidateInstance0(context0[0], CALL_LOCATION(errMsg));

        std::vector<std::wstring> keyValues1;
        keyValues1.push_back(L"AppSrv01-Node01Cell-Node01-server1");
        TestableContext context1;
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, MI_RESULT_OK, (GetInstance<mi::SCX_Application_Server_Class_Provider,
            mi::SCX_Application_Server_Class>(m_keyNames, keyValues1, context1, CALL_LOCATION(errMsg))));
        ValidateInstance1(context1[0], CALL_LOCATION(errMsg));
    }

    void TestDoGetInstanceNotFound()
    {
        std::wostringstream errMsg;

        std::vector<std::wstring> keyValues;
        keyValues.push_back(L"dummy");
        TestableContext context;
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, MI_RESULT_NOT_FOUND,
            (GetInstance<mi::SCX_Application_Server_Class_Provider,
            mi::SCX_Application_Server_Class>(m_keyNames, keyValues, context, CALL_LOCATION(errMsg))));
    }

    void TestEnumerateKeysOnly()
    {
        std::wostringstream errMsg;
        TestableContext context;
        StandardTestEnumerateKeysOnly<mi::SCX_Application_Server_Class_Provider>(
            m_keyNames, context, CALL_LOCATION(errMsg));
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, 2u, context.Size());
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, L"/opt/jboss-5.1.0.GA/",
            context[0].GetKey(L"Name", CALL_LOCATION(errMsg)));
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, L"AppSrv01-Node01Cell-Node01-server1",
            context[1].GetKey(L"Name", CALL_LOCATION(errMsg)));
    }

    void TestVerifyKeyCompletePartial()
    {
        std::wostringstream errMsg;
        StandardTestVerifyGetInstanceKeys<mi::SCX_Application_Server_Class_Provider,
                mi::SCX_Application_Server_Class>(m_keyNames, CALL_LOCATION(errMsg));
    }

    void InvokeSetDeepMonitoring(mi::SCX_Application_Server_SetDeepMonitoring_Class &param, MI_Result result,
        std::wostringstream &errMsg)
    {
        TestableContext context;
        mi::SCX_Application_Server_Class instanceName;
        mi::Module Module;
        mi::SCX_Application_Server_Class_Provider agent(&Module);
        agent.Invoke_SetDeepMonitoring(context, NULL, instanceName, param);
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, result, context.GetResult());
        // We expect one instance to be returned.
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, 1u, context.Size());
        if (context.GetResult() == MI_RESULT_OK)
        {
            CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, true, context[0].GetProperty("MIReturn",
                CALL_LOCATION(errMsg)).GetValue_MIBoolean(CALL_LOCATION(errMsg)));
        }
        else
        {
            CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, false, context[0].GetProperty("MIReturn",
                CALL_LOCATION(errMsg)).GetValue_MIBoolean(CALL_LOCATION(errMsg)));
        }
    }

    void TestDoInvokeMethodNoAppServer()
    {
        std::wostringstream errMsg;
        mi::SCX_Application_Server_SetDeepMonitoring_Class param;
        param.id_value("dummy");
        param.deep_value(true);
        InvokeSetDeepMonitoring(param, MI_RESULT_NOT_FOUND, CALL_LOCATION(errMsg));
    }

    void TestDoInvokeMethodMissingArg()
    {
        std::wostringstream errMsg;

        // Test for failure if id argument is missing.
        mi::SCX_Application_Server_SetDeepMonitoring_Class param0;
        param0.deep_value(true);
        InvokeSetDeepMonitoring(param0, MI_RESULT_INVALID_PARAMETER, CALL_LOCATION(errMsg));

        // Test for failure if deep argument is missing.
        mi::SCX_Application_Server_SetDeepMonitoring_Class param1;
        param1.id_value("/opt/jboss-5.1.0.GA/");
        InvokeSetDeepMonitoring(param1, MI_RESULT_INVALID_PARAMETER, CALL_LOCATION(errMsg));
        
    }

    void TestDoInvokeMethodGood()
    {
        std::wostringstream errMsg;
        mi::SCX_Application_Server_SetDeepMonitoring_Class param;
        param.id_value("/opt/jboss-5.1.0.GA/");
        param.deep_value(true);
        InvokeSetDeepMonitoring(param, MI_RESULT_OK, CALL_LOCATION(errMsg));

        TestableContext context;
        StandardTestEnumerateInstances<mi::SCX_Application_Server_Class_Provider>(
            m_keyNames, context, CALL_LOCATION(errMsg));
        CPPUNIT_ASSERT_MESSAGE(ERROR_MESSAGE, 0 < context.Size());
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, true, context[0].GetProperty(
            L"IsDeepMonitored", CALL_LOCATION(errMsg)).GetValue_MIBoolean(CALL_LOCATION(errMsg)));
    }
};

CPPUNIT_TEST_SUITE_REGISTRATION( SCXASProviderTest );
