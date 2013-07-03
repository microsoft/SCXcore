/*--------------------------------------------------------------------------------
    Copyright (c) Microsoft Corporation.  All rights reserved.

    Created date    2007-07-04 10:08:57

    Memory provider test class.

    Only tests the functionality of the provider class.
    The actual data gathering is tested by a separate class.

*/
/*----------------------------------------------------------------------------*/
#include <scxcorelib/scxcmn.h>
#include <scxcorelib/scxexception.h>
#include <scxsystemlib/scxostypeinfo.h>
#include <testutils/scxunit.h>
#include <testutils/providertestutils.h>

#include "startuplog.h"
#include "memoryprovider.h"
#include "SCX_Agent.h"
#include "SCX_Agent_Class_Provider.h"
#include "SCX_MemoryStatisticalInformation_Class_Provider.h"

using namespace SCXCore;
using namespace SCXCoreLib;
using namespace SCXSystemLib;

class MemoryProvider_Test : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE( MemoryProvider_Test  );
    CPPUNIT_TEST( callDumpStringForCoverage );
    CPPUNIT_TEST( TestEnumerateInstancesKeysOnly );
    CPPUNIT_TEST( TestEnumerateInstances );
    CPPUNIT_TEST( TestVerifyKeyCompletePartial );
    CPPUNIT_TEST( TestGetInstance );

    SCXUNIT_TEST_ATTRIBUTE(callDumpStringForCoverage, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(TestEnumerateInstancesKeysOnly, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(TestEnumerateInstances, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(TestVerifyKeyCompletePartial, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(TestGetInstance, SLOW);
    CPPUNIT_TEST_SUITE_END();

private:
    std::vector<std::wstring> m_keyNames;

public:
    void setUp(void)
    {
        std::wostringstream errMsg;
        TestableContext context;
        SetUpAgent<mi::SCX_MemoryStatisticalInformation_Class_Provider>(context, CALL_LOCATION(errMsg));
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, true, context.WasRefuseUnloadCalled() );
        m_keyNames.push_back(L"Name");
    }

    void tearDown(void)
    {
        std::wostringstream errMsg;
        TestableContext context;
        TearDownAgent<mi::SCX_MemoryStatisticalInformation_Class_Provider>(context, CALL_LOCATION(errMsg));
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, false, context.WasRefuseUnloadCalled() );
    }

    void callDumpStringForCoverage()
    {
        CPPUNIT_ASSERT(g_MemoryProvider.DumpString().find(L"MemoryProvider") != std::wstring::npos);
    }

    void TestEnumerateInstancesKeysOnly()
    {
        std::wostringstream errMsg;
        TestableContext context;
        StandardTestEnumerateKeysOnly<mi::SCX_MemoryStatisticalInformation_Class_Provider>(
            m_keyNames, context, CALL_LOCATION(errMsg));
        CPPUNIT_ASSERT_EQUAL(1u, context.Size());
        CPPUNIT_ASSERT_EQUAL(L"Memory", context[0].GetKey(L"Name", CALL_LOCATION(errMsg)));
    }

    void TestEnumerateInstances()
    {
        std::wostringstream errMsg;
        TestableContext context;
        StandardTestEnumerateInstances<mi::SCX_MemoryStatisticalInformation_Class_Provider>(
            m_keyNames, context, CALL_LOCATION(errMsg));
        CPPUNIT_ASSERT_EQUAL(1u, context.Size());
        ValidateInstance(context, CALL_LOCATION(errMsg));
    }

    void TestVerifyKeyCompletePartial()
    {
        std::wostringstream errMsg;
        StandardTestVerifyGetInstanceKeys<mi::SCX_MemoryStatisticalInformation_Class_Provider,
                mi::SCX_MemoryStatisticalInformation_Class>(m_keyNames, CALL_LOCATION(errMsg));
    }

    void TestGetInstance()
    {
        std::wostringstream errMsg;

        std::vector<std::wstring> keyValues;
        keyValues.push_back(L"Memory");
        TestableContext context;
        CPPUNIT_ASSERT_EQUAL(MI_RESULT_OK, (GetInstance<mi::SCX_MemoryStatisticalInformation_Class_Provider,
            mi::SCX_MemoryStatisticalInformation_Class>(m_keyNames, keyValues, context, CALL_LOCATION(errMsg))));
        ValidateInstance(context, CALL_LOCATION(errMsg));
    }

    void ValidateInstance(const TestableContext& context, std::wostringstream &errMsg)
    {
        CPPUNIT_ASSERT_EQUAL(1u, context.Size());// This provider has only one instance.
        const TestableInstance &instance = context[0];
        
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, m_keyNames[0], instance.GetKeyName(0, CALL_LOCATION(errMsg)));
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, L"Memory", instance.GetKeyValue(0, CALL_LOCATION(errMsg)));

        std::wstring tmpExpectedProperties[] = {L"Caption",
                                                  L"Description",
                                                  L"Name",
                                                  L"IsAggregate",
                                                  L"AvailableMemory",
                                                  L"PercentAvailableMemory",
                                                  L"UsedMemory",
                                                  L"PercentUsedMemory",
                                                  L"PagesPerSec",
                                                  L"PagesReadPerSec",
                                                  L"PagesWrittenPerSec",
                                                  L"AvailableSwap",
                                                  L"PercentAvailableSwap",
                                                  L"UsedSwap",
                                                  L"PercentUsedSwap",
                                                  L"PercentUsedByCache"};

        const size_t numprops = sizeof(tmpExpectedProperties) / sizeof(tmpExpectedProperties[0]);
        VerifyInstancePropertyNames(instance, tmpExpectedProperties, numprops, CALL_LOCATION(errMsg));

        // Test that the percentages add up to about 100%.
        TestableInstance::PropertyInfo info;
        CPPUNIT_ASSERT_EQUAL(MI_RESULT_OK, instance.FindProperty(L"PercentAvailableMemory", info));
        MI_Uint8 percentAvailableMemory = info.GetValue_MIUint8(CALL_LOCATION(errMsg));
        CPPUNIT_ASSERT_EQUAL(MI_RESULT_OK, instance.FindProperty(L"PercentUsedMemory", info));
        MI_Uint8 percentUsedMemory = info.GetValue_MIUint8(CALL_LOCATION(errMsg));

        SCXUNIT_ASSERT_BETWEEN(static_cast<unsigned int>(percentAvailableMemory) + percentUsedMemory, 98, 102);
    }
};

CPPUNIT_TEST_SUITE_REGISTRATION( MemoryProvider_Test );
