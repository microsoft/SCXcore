/*--------------------------------------------------------------------------------
    Copyright (c) Microsoft Corporation.  All rights reserved.

    Created date    2008-05-29 12:41:51

    CPU provider test class.

    Only tests the functionality of the provider class.
    The actual data gathering is tested by a separate class.

*/
/*----------------------------------------------------------------------------*/
#include <scxcorelib/scxcmn.h>
#include <scxsystemlib/scxostypeinfo.h>
#include <testutils/scxunit.h>
#include <testutils/providertestutils.h>
#include <cppunit/extensions/HelperMacros.h>
#include "SCX_ProcessorStatisticalInformation_Class_Provider.h"

using namespace SCXCoreLib;
using namespace SCXSystemLib;

class CPUProvider_Test : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE( CPUProvider_Test  );
    CPPUNIT_TEST( TestEnumerateInstancesKeysOnly );
    CPPUNIT_TEST( TestEnumerateInstances );
    CPPUNIT_TEST( TestGetInstance );
    CPPUNIT_TEST( TestVerifyKeyCompletePartial );

    SCXUNIT_TEST_ATTRIBUTE(TestEnumerateInstancesKeysOnly, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(TestEnumerateInstances, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(TestGetInstance, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(TestVerifyKeyCompletePartial, SLOW);
    CPPUNIT_TEST_SUITE_END();

private:
    std::vector<std::wstring> m_keyNames;
public:
    void setUp(void)
    {
        std::wostringstream errMsg;
        TestableContext context;
        SetUpAgent<mi::SCX_ProcessorStatisticalInformation_Class_Provider>(context, CALL_LOCATION(errMsg));
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, true, context.WasRefuseUnloadCalled() );
        m_keyNames.push_back(L"Name");
    }

    void tearDown(void)
    {
        std::wostringstream errMsg;
        TestableContext context;
        TearDownAgent<mi::SCX_ProcessorStatisticalInformation_Class_Provider>(context, CALL_LOCATION(errMsg));
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, false, context.WasRefuseUnloadCalled() );
    }

    void TestEnumerateInstancesKeysOnly()
    {
        std::wostringstream errMsg;
        TestableContext context;
        StandardTestEnumerateKeysOnly<mi::SCX_ProcessorStatisticalInformation_Class_Provider>(
            m_keyNames, context, CALL_LOCATION(errMsg));
    }

    void TestEnumerateInstances()
    {
        std::wostringstream errMsg;
        TestableContext context;
        StandardTestEnumerateInstances<mi::SCX_ProcessorStatisticalInformation_Class_Provider>(
            m_keyNames, context, CALL_LOCATION(errMsg));
        ValidateInstance(context, CALL_LOCATION(errMsg));
    }

    void TestVerifyKeyCompletePartial()
    {
        std::wostringstream errMsg;
        StandardTestVerifyGetInstanceKeys<mi::SCX_ProcessorStatisticalInformation_Class_Provider,
                mi::SCX_ProcessorStatisticalInformation_Class>(m_keyNames, CALL_LOCATION(errMsg));
    }

    void TestGetInstance()
    {
        std::wostringstream errMsg;
        TestableContext context;
        StandardTestGetInstance<mi::SCX_ProcessorStatisticalInformation_Class_Provider,
            mi::SCX_ProcessorStatisticalInformation_Class>(context, m_keyNames.size(), CALL_LOCATION(errMsg));
        ValidateInstance(context, CALL_LOCATION(errMsg));
    }

    void ValidateInstance(const TestableContext& context, std::wostringstream &errMsg)
    {
        for (size_t n = 0; n < context.Size(); n++)
        {
            const TestableInstance &instance = context[n];
            CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, m_keyNames[0], instance.GetKeyName(0, CALL_LOCATION(errMsg)));

#if defined(linux)
            std::wstring tmpExpectedProperties[] = {L"Caption",
                                                            L"Description",
                                                            L"Name",
                                                            L"IsAggregate",
                                                            L"PercentIdleTime",
                                                            L"PercentUserTime",
                                                            L"PercentNiceTime",
                                                            L"PercentPrivilegedTime",
                                                            L"PercentInterruptTime",
                                                            L"PercentDPCTime",
                                                            L"PercentProcessorTime",
                                                            L"PercentIOWaitTime"};
#elif defined(sun) | defined(aix)
            std::wstring tmpExpectedProperties[] = {L"Caption",
                                                            L"Description",
                                                            L"Name",
                                                            L"IsAggregate",
                                                            L"PercentIdleTime",
                                                            L"PercentUserTime",
                                                            L"PercentPrivilegedTime",
                                                            L"PercentProcessorTime",
                                                            L"PercentIOWaitTime"};
#elif defined(hpux)
            std::wstring tmpExpectedProperties[] = {L"Caption",
                                                            L"Description",
                                                            L"Name",
                                                            L"IsAggregate",
                                                            L"PercentIdleTime",
                                                            L"PercentUserTime",
                                                            L"PercentNiceTime",
                                                            L"PercentPrivilegedTime",
                                                            L"PercentProcessorTime",
                                                            L"PercentIOWaitTime"};
#endif

            const size_t numprops = sizeof(tmpExpectedProperties) / sizeof(tmpExpectedProperties[0]);
            VerifyInstancePropertyNames(instance, tmpExpectedProperties, numprops, CALL_LOCATION(errMsg));
        }
    }
};

CPPUNIT_TEST_SUITE_REGISTRATION( CPUProvider_Test );
