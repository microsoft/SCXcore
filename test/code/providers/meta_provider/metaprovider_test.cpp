/*--------------------------------------------------------------------------------
  Copyright (c) Microsoft Corporation.  All rights reserved.

*/
/**
   \file

   \brief       Tests for the meta provider

   \date        2008-03-18 09:20:15

*/
/*----------------------------------------------------------------------------*/

#include <scxcorelib/scxcmn.h>
#include <scxcorelib/scxexception.h>
#include <scxsystemlib/scxostypeinfo.h>
#include <testutils/scxunit.h>
#include <testutils/providertestutils.h>

#include "metaprovider.h"
#include "SCX_Agent.h"
#include "SCX_Agent_Class_Provider.h"

using namespace SCXCore;
using namespace SCXCoreLib;
using namespace SCXSystemLib;

class SCXMetaProviderTest : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE( SCXMetaProviderTest );

    CPPUNIT_TEST( callDumpStringForCoverage );
    CPPUNIT_TEST( VerifyMultipleLoadUnloadMethods );
    CPPUNIT_TEST( VerifyBasicFunctions );
    CPPUNIT_TEST( TestEnumerateKeysOnly );
    CPPUNIT_TEST( VerifyKeyCompletePartial );
    CPPUNIT_TEST( TestLowestLogLevel );
//    CPPUNIT_TEST( PrintAsEnumeration ); /* For debug printouts */

    CPPUNIT_TEST_SUITE_END();

public:
    void setUp(void)
    {
        std::wostringstream errMsg;
        TestableContext context;
        SetUpAgent<mi::SCX_Agent_Class_Provider>(context, CALL_LOCATION(errMsg));
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, true, context.WasRefuseUnloadCalled() );
    }

    void tearDown(void)
    {
        std::wostringstream errMsg;
        TestableContext context;
        TearDownAgent<mi::SCX_Agent_Class_Provider>(context, CALL_LOCATION(errMsg));
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, false, context.WasRefuseUnloadCalled() );
    }

    void callDumpStringForCoverage()
    {
        CPPUNIT_ASSERT(g_MetaProvider.DumpString().find(L"MetaProvider") != std::wstring::npos);
    }

    // Since setUp() / tearDown() already load/unload, this tests that a second call to Load() works
    void VerifyMultipleLoadUnloadMethods()
    {
        mi::Module Module;
        mi::SCX_Agent_Class_Provider agent(&Module);
        TestableContext context;

        // Call load, verify result is okay, and verify RefuseUnload() was called
        agent.Load(context);
        CPPUNIT_ASSERT_EQUAL( MI_RESULT_OK, context.GetResult() );
        CPPUNIT_ASSERT_EQUAL( true, context.WasRefuseUnloadCalled() );

        agent.Unload(context);
        CPPUNIT_ASSERT_EQUAL( MI_RESULT_OK, context.GetResult() );
    }

    void VerifyBasicFunctions()
    {
        mi::Module Module;
        mi::SCX_Agent_Class_Provider agent(&Module);
        TestableContext context;

        agent.EnumerateInstances(context, NULL, context.GetPropertySet(), false, NULL);
        CPPUNIT_ASSERT_EQUAL( MI_RESULT_OK, context.GetResult() );

        const std::vector<TestableInstance>& instances = context.GetInstances();
        CPPUNIT_ASSERT_EQUAL(static_cast<size_t> (1), instances.size());

        TestableInstance inst(instances[0]);
        struct TestableInstance::PropertyInfo info;

        // Verify that the key is correct
        CPPUNIT_ASSERT_EQUAL( static_cast<MI_Uint32>(1), inst.GetNumberOfKeys() );
        CPPUNIT_ASSERT_EQUAL( MI_RESULT_OK, inst.FindProperty("Name", info) );

        CPPUNIT_ASSERT_EQUAL_MESSAGE("Field 'Name' is not a key", true, info.isKey);
        CPPUNIT_ASSERT_EQUAL_MESSAGE("Field 'Name' is not of type string", MI_STRING, info.type);
        CPPUNIT_ASSERT_EQUAL_MESSAGE("Field 'Name' has wrong value", std::string("scx"), info.value.string);

        // Test for presence of a few non-null string properties
        const char *stringprops[] = {
#if !defined(PF_DISTRO_ULINUX)
            "Description", "VersionString", "Architecture", "OSName", "OSType", 
            "OSVersion", "Hostname", "OSAlias", "UnameArchitecture", 0
#else // !defined(PF_DISTRO_LINUX)
            // ULINUX: Not "OSVersion" since we may run on an uninstalled machine
            "Description", "VersionString", "Architecture", "OSName", "OSType", 
            "Hostname", "OSAlias", "UnameArchitecture", 0
#endif // !defined(PF_DISTRO_LINUX)
        }; // NB: Not "KitVersionString" since we may run on an uninstalled machine.

        for (int i = 0; stringprops[i]; i++) 
        {
            std::string msgFragment = std::string("Property ") + stringprops[i];
            CPPUNIT_ASSERT_EQUAL_MESSAGE(msgFragment + " not found", MI_RESULT_OK, inst.FindProperty(stringprops[i], info));
            CPPUNIT_ASSERT_EQUAL_MESSAGE(msgFragment + " not of type string", MI_STRING, info.type);
            CPPUNIT_ASSERT_EQUAL_MESSAGE(msgFragment + " was not enumerated", true, info.exists);
            CPPUNIT_ASSERT_MESSAGE(msgFragment + " is zero in length", strlen(info.value.string) > 0);
        }

        // Test that major version is 1 or above.
        CPPUNIT_ASSERT_EQUAL( MI_RESULT_OK, inst.FindProperty("MajorVersion", info) );
        CPPUNIT_ASSERT_EQUAL(MI_UINT16, info.type);
        CPPUNIT_ASSERT(info.value.uint16 >= 1);
    }

    void TestEnumerateKeysOnly()
    {
        mi::Module Module;
        mi::SCX_Agent_Class_Provider agent(&Module);
        TestableContext context;

        agent.EnumerateInstances(context, NULL, context.GetPropertySet(), true, NULL);
        CPPUNIT_ASSERT_EQUAL( MI_RESULT_OK, context.GetResult() );

        const std::vector<TestableInstance>& instances = context.GetInstances();
        CPPUNIT_ASSERT_EQUAL(static_cast<size_t> (1), instances.size());

        TestableInstance inst(instances[0]);

        // We know the key is correct from VerifyBasicFunctions()
        // Just validate that we didn't enumerate properties we didn't need
        CPPUNIT_ASSERT_EQUAL( static_cast<MI_Uint32>(1), inst.GetNumberOfKeys() );
        CPPUNIT_ASSERT_EQUAL( static_cast<MI_Uint32>(1), inst.GetNumberOfProperties() );
    }

    void VerifyKeyCompletePartial()
    {
        std::wostringstream errMsg;
        std::vector<std::wstring> keyNames;
        keyNames.push_back(L"Name");
        StandardTestVerifyGetInstanceKeys<mi::SCX_Agent_Class_Provider,
                mi::SCX_Agent_Class>(keyNames, CALL_LOCATION(errMsg));
    }

    void TestLowestLogLevel()
    {
        mi::Module Module;
        mi::SCX_Agent_Class_Provider agent(&Module);
        TestableContext context;

        agent.EnumerateInstances(context, NULL, context.GetPropertySet(), false, NULL);
        CPPUNIT_ASSERT_EQUAL( MI_RESULT_OK, context.GetResult() );

        const std::vector<TestableInstance>& instances = context.GetInstances();
        CPPUNIT_ASSERT_EQUAL(static_cast<size_t> (1), instances.size());

        TestableInstance inst(instances[0]);
        struct TestableInstance::PropertyInfo info;

        CPPUNIT_ASSERT_EQUAL(MI_RESULT_OK, inst.FindProperty("MinActiveLogSeverityThreshold", info));

        std::string lowestLogThreshold = info.value.string;
        CPPUNIT_ASSERT_EQUAL(std::string("INFO"), lowestLogThreshold); // Since this is the default.

        // Set a lower logging threshold, then fetch again and verify we pick it up
        SCXCoreLib::SCXLogHandle logH = SCXLogHandleFactory::GetLogHandle(L"scx.test");
        logH.SetSeverityThreshold(SCXCoreLib::eTrace);

        context.Reset();
        agent.EnumerateInstances(context, NULL, context.GetPropertySet(), false, NULL);
        CPPUNIT_ASSERT_EQUAL( MI_RESULT_OK, context.GetResult() );
        const std::vector<TestableInstance>& instances2 = context.GetInstances();
        CPPUNIT_ASSERT_EQUAL(static_cast<size_t> (1), instances2.size());

        TestableInstance inst2(instances2[0]);
        CPPUNIT_ASSERT_EQUAL(MI_RESULT_OK, inst2.FindProperty("MinActiveLogSeverityThreshold", info));

        lowestLogThreshold = info.value.string;
        CPPUNIT_ASSERT_EQUAL(std::string("TRACE"), lowestLogThreshold);
    }

    /** Print the same output that an enumeration would. */
    void PrintAsEnumeration()
    {
        mi::Module Module;
        mi::SCX_Agent_Class_Provider agent(&Module);
        TestableContext context;

        agent.EnumerateInstances(context, NULL, context.GetPropertySet(), false, NULL);
        CPPUNIT_ASSERT_EQUAL( MI_RESULT_OK, context.GetResult() );

        const std::vector<TestableInstance>& instances = context.GetInstances();
        CPPUNIT_ASSERT_EQUAL(static_cast<size_t> (1), instances.size());

        TestableInstance inst(instances[0]);
        inst.Print();
    }
};

CPPUNIT_TEST_SUITE_REGISTRATION( SCXMetaProviderTest );
