/*--------------------------------------------------------------------------------
  Copyright (c) Microsoft Corporation.  All rights reserved.

*/
/**
   \file

   \brief       Tests for the process provider

   \date        2008-04-10 12:02

   Only tests the functionality of the provider class.
   The actual data gathering is tested by a separate class.

*/
/*----------------------------------------------------------------------------*/

#include <scxcorelib/scxcmn.h>
#include <scxsystemlib/scxostypeinfo.h>
#include <testutils/scxunit.h>
#include <testutils/providertestutils.h>
#include "SCX_UnixProcess_Class_Provider.h"
#include "SCX_UnixProcessStatisticalInformation_Class_Provider.h"

using namespace SCXCoreLib;

class SCXProcessProviderTest : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE( SCXProcessProviderTest );

    CPPUNIT_TEST( TestUnixProcessEnumerateInstances );
    CPPUNIT_TEST( TestUnixProcessStatisticalInformationEnumerateInstances );

    CPPUNIT_TEST( TestUnixProcessGetInstance );
    CPPUNIT_TEST( TestUnixProcessStatisticalInformationGetInstance );

    CPPUNIT_TEST( TestUnixProcessGetThisInstance );
    CPPUNIT_TEST( TestUnixProcessStatisticalInformationGetThisInstance );

    CPPUNIT_TEST( TestUnixProcessInvokeTopResourceConsumers );
    CPPUNIT_TEST( TestUnixProcessInvokeTopResourceConsumersFail );


    SCXUNIT_TEST_ATTRIBUTE(TestUnixProcessEnumerateInstances, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(TestUnixProcessStatisticalInformationEnumerateInstances, SLOW);

    SCXUNIT_TEST_ATTRIBUTE(TestUnixProcessGetInstance, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(TestUnixProcessStatisticalInformationGetInstance, SLOW);

    SCXUNIT_TEST_ATTRIBUTE(TestUnixProcessGetThisInstance, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(TestUnixProcessStatisticalInformationGetThisInstance, SLOW);

    SCXUNIT_TEST_ATTRIBUTE(TestUnixProcessInvokeTopResourceConsumers, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(TestUnixProcessInvokeTopResourceConsumersFail, SLOW);

    CPPUNIT_TEST_SUITE_END();

private:
    std::vector<std::wstring> m_keyNamesUP;// SCX_UnixProcess key names.
    std::vector<std::wstring> m_keyNamesUPS;// SCX_UnixProcessStatisticalInformation key names.

public:
    void setUp(void)
    {
        std::wostringstream errMsg;
        SetUpAgent<mi::SCX_UnixProcess_Class_Provider>(CALL_LOCATION(errMsg));
        SetUpAgent<mi::SCX_UnixProcessStatisticalInformation_Class_Provider>(CALL_LOCATION(errMsg));
        
        m_keyNamesUP.push_back(L"CSCreationClassName");
        m_keyNamesUP.push_back(L"CSName");
        m_keyNamesUP.push_back(L"OSCreationClassName");
        m_keyNamesUP.push_back(L"OSName");
        m_keyNamesUP.push_back(L"CreationClassName");
        m_keyNamesUP.push_back(L"Handle");

        m_keyNamesUPS.push_back(L"Name");
        m_keyNamesUPS.push_back(L"CSCreationClassName");
        m_keyNamesUPS.push_back(L"CSName");
        m_keyNamesUPS.push_back(L"OSCreationClassName");
        m_keyNamesUPS.push_back(L"OSName");
        m_keyNamesUPS.push_back(L"Handle");
        m_keyNamesUPS.push_back(L"ProcessCreationClassName");
    }

    void tearDown(void)
    {
        std::wostringstream errMsg;
        TearDownAgent<mi::SCX_UnixProcess_Class_Provider>(CALL_LOCATION(errMsg));
        TearDownAgent<mi::SCX_UnixProcessStatisticalInformation_Class_Provider>(CALL_LOCATION(errMsg));
    }

    void TestUnixProcessEnumerateInstances()
    {
        std::wostringstream errMsg;
        TestableContext context;
        StandardTestEnumerateInstances<mi::SCX_UnixProcess_Class_Provider>(
            m_keyNamesUP, context, CALL_LOCATION(errMsg));
        CPPUNIT_ASSERT_MESSAGE(ERROR_MESSAGE, context.Size() > 10);

        ValidateInstance(context, CALL_LOCATION(errMsg));
    }

    void TestUnixProcessStatisticalInformationEnumerateInstances()
    {
        std::wostringstream errMsg;
        TestableContext context;
        StandardTestEnumerateInstances<mi::SCX_UnixProcessStatisticalInformation_Class_Provider>(
            m_keyNamesUPS, context, CALL_LOCATION(errMsg));
        CPPUNIT_ASSERT_MESSAGE(ERROR_MESSAGE, context.Size() > 10);

        ValidateInstanceStatisticalInformation(context, CALL_LOCATION(errMsg));
    }

    void TestUnixProcessGetInstance()
    {
        std::wostringstream errMsg;
        TestableContext context;
        StandardTestGetInstance<mi::SCX_UnixProcess_Class_Provider,
            mi::SCX_UnixProcess_Class>(
            context, m_keyNamesUP.size(), CALL_LOCATION(errMsg));

        ValidateInstance(context, CALL_LOCATION(errMsg));
    }

    void TestUnixProcessStatisticalInformationGetInstance()
    {
        std::wostringstream errMsg;
        TestableContext context;
        StandardTestGetInstance<mi::SCX_UnixProcessStatisticalInformation_Class_Provider,
            mi::SCX_UnixProcessStatisticalInformation_Class>(
            context, m_keyNamesUPS.size(), CALL_LOCATION(errMsg));

        ValidateInstanceStatisticalInformation(context, CALL_LOCATION(errMsg));
    }

    void TestUnixProcessGetThisInstance()
    {
        std::wostringstream errMsg;
        TestableContext context;

        std::vector<std::wstring> keyValues;
        keyValues.push_back(L"SCX_ComputerSystem");
        keyValues.push_back(GetFQHostName(CALL_LOCATION(errMsg)));
        keyValues.push_back(L"SCX_OperatingSystem");
        keyValues.push_back(GetDistributionName(CALL_LOCATION(errMsg)));
        keyValues.push_back(L"SCX_UnixProcess");
        keyValues.push_back(SCXCoreLib::StrFrom(getpid()));

        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, true, (GetInstance<
            mi::SCX_UnixProcess_Class_Provider, mi::SCX_UnixProcess_Class>(
            m_keyNamesUP, keyValues, context, CALL_LOCATION(errMsg))));
        
        // Yes, but is it us?
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, L"testrunner", context[0].GetProperty("Name",
            CALL_LOCATION(errMsg)).GetValue_MIString(CALL_LOCATION(errMsg)));

        ValidateInstance(context, CALL_LOCATION(errMsg));
    }

    void TestUnixProcessStatisticalInformationGetThisInstance()
    {
        std::wostringstream errMsg;
        TestableContext context;

        std::vector<std::wstring> keyValues;
        keyValues.push_back(L"testrunner");// Looking for us.
        keyValues.push_back(L"SCX_ComputerSystem");
        keyValues.push_back(GetFQHostName(CALL_LOCATION(errMsg)));
        keyValues.push_back(L"SCX_OperatingSystem");
        keyValues.push_back(GetDistributionName(CALL_LOCATION(errMsg)));
        keyValues.push_back(SCXCoreLib::StrFrom(getpid()));
        keyValues.push_back(L"SCX_UnixProcessStatisticalInformation");

        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, true, (GetInstance<
            mi::SCX_UnixProcessStatisticalInformation_Class_Provider, mi::SCX_UnixProcessStatisticalInformation_Class>(
            m_keyNamesUPS, keyValues, context, CALL_LOCATION(errMsg))));

        ValidateInstanceStatisticalInformation(context, CALL_LOCATION(errMsg));
    }

    bool GetTopResourceConsumers(const char* resourceName, std::wostringstream &errMsg)
    {
        TestableContext context;
        mi::SCX_UnixProcess_Class instanceName;
        mi::SCX_UnixProcess_TopResourceConsumers_Class param;
        param.resource_value(resourceName);
        param.count_value(10);

        mi::Module Module;
        mi::SCX_UnixProcess_Class_Provider agent(&Module);
        agent.Invoke_TopResourceConsumers(context, NULL, instanceName, param);
        if (context.GetResult() == MI_RESULT_OK)
        {
            const std::vector<TestableInstance> &instances = context.GetInstances();
            // We expect one instance to be returned.
            CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, 1u, instances.size());
            CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, L"PID", instances[0].GetProperty("MIReturn",
                CALL_LOCATION(errMsg)).GetValue_MIString(CALL_LOCATION(errMsg)).substr(1, 3));
            return true;
        }
        return false;
    }

    void TestUnixProcessInvokeTopResourceConsumers()
    {
        std::wostringstream errMsg;
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, true, GetTopResourceConsumers("CPUTime", CALL_LOCATION(errMsg)));
    }

    void TestUnixProcessInvokeTopResourceConsumersFail()
    {
        std::wostringstream errMsg;
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, false,
            GetTopResourceConsumers("InvalidResource", CALL_LOCATION(errMsg)));
    }

    void ValidateInstance(const TestableContext& context, std::wostringstream &errMsg)
    {
        for (size_t n = 0; n < context.Size(); n++)
        {
            const TestableInstance &instance = context[n];

            std::wstring tmpExpectedProperties[] = {
                                                    L"InstanceID",
                                                    L"Caption",
                                                    L"Description",
                                                    L"ElementName",
                                                    L"InstallDate",
                                                    L"Name",
                                                    L"OperationalStatus",
                                                    L"StatusDescriptions",
                                                    L"Status",
                                                    L"HealthState",
                                                    L"CommunicationStatus",
                                                    L"DetailedStatus",
                                                    L"OperatingStatus",
                                                    L"PrimaryStatus",
                                                    L"EnabledState",
                                                    L"OtherEnabledState",
                                                    L"RequestedState",
                                                    L"EnabledDefault",
                                                    L"TimeOfLastStateChange",
                                                    L"AvailableRequestedStates",
                                                    L"TransitioningToState",
                                                    L"CSCreationClassName",
                                                    L"CSName",
                                                    L"OSCreationClassName",
                                                    L"OSName",
                                                    L"CreationClassName",
                                                    L"Handle",
                                                    L"Priority",
                                                    L"ExecutionState",
                                                    L"OtherExecutionDescription",
                                                    L"CreationDate",
                                                    L"TerminationDate",
                                                    L"KernelModeTime",
                                                    L"UserModeTime",
                                                    L"WorkingSetSize",
                                                    L"ParentProcessID",
                                                    L"RealUserID",
                                                    L"ProcessGroupID",
                                                    L"ProcessSessionID",
                                                    L"ProcessTTY",
                                                    L"ModulePath",
                                                    L"Parameters",
                                                    L"ProcessNiceValue",
                                                    L"ProcessWaitingForEvent"};

            const size_t numprops = sizeof(tmpExpectedProperties) / sizeof(tmpExpectedProperties[0]);
            VerifyInstancePropertyNames(instance, tmpExpectedProperties, numprops, CALL_LOCATION(errMsg));
        }
    }

    void ValidateInstanceStatisticalInformation(const TestableContext& context, std::wostringstream &errMsg)
    {
        for (size_t n = 0; n < context.Size(); n++)
        {
            const TestableInstance &instance = context[n];

            std::wstring tmpExpectedProperties[] = {
                                                    L"InstanceID",
                                                    L"Caption",
                                                    L"Description",
                                                    L"ElementName",
                                                    L"Name",
                                                    L"CSCreationClassName",
                                                    L"CSName",
                                                    L"OSCreationClassName",
                                                    L"OSName",
                                                    L"Handle",
                                                    L"ProcessCreationClassName",
                                                    L"CPUTime",
                                                    L"RealText",
                                                    L"RealData",
                                                    L"RealStack",
                                                    L"VirtualText",
                                                    L"VirtualData",
                                                    L"VirtualStack",
                                                    L"VirtualMemoryMappedFileSize",
                                                    L"VirtualSharedMemory",
                                                    L"CpuTimeDeadChildren",
                                                    L"SystemTimeDeadChildren",
                                                    L"BlockReadsPerSecond",
                                                    L"BlockWritesPerSecond",
                                                    L"BlockTransfersPerSecond",
                                                    L"PercentUserTime",
                                                    L"PercentPrivilegedTime",
                                                    L"UsedMemory",
                                                    L"PercentUsedMemory",
                                                    L"PagesReadPerSec"};

            const size_t numprops = sizeof(tmpExpectedProperties) / sizeof(tmpExpectedProperties[0]);
            VerifyInstancePropertyNames(instance, tmpExpectedProperties, numprops, CALL_LOCATION(errMsg));
        }
    }
};

CPPUNIT_TEST_SUITE_REGISTRATION( SCXProcessProviderTest );
