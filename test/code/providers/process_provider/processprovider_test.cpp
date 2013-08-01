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

//WI567597: Property ModulePath not returned during pbuild on ostcdev64-sles11-01, ostcdev-sles10-01, ostcdev64-rhel4-01 and ostcdev-rhel4-10.
//WI567598: Property Parameters not returned on ostcdev-sles9-10.
static bool brokenProvider = true;

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
        std::wstring errMsg;
        TestableContext context;
        SetUpAgent<mi::SCX_UnixProcess_Class_Provider>(context, CALL_LOCATION(errMsg));
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, true, context.WasRefuseUnloadCalled() );
        SetUpAgent<mi::SCX_UnixProcessStatisticalInformation_Class_Provider>(context, CALL_LOCATION(errMsg));
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, true, context.WasRefuseUnloadCalled() );
        
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
        std::wstring errMsg;
        TestableContext context;
        TearDownAgent<mi::SCX_UnixProcess_Class_Provider>(context, CALL_LOCATION(errMsg));
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, false, context.WasRefuseUnloadCalled() );
        TearDownAgent<mi::SCX_UnixProcessStatisticalInformation_Class_Provider>(context, CALL_LOCATION(errMsg));
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, false, context.WasRefuseUnloadCalled() );
    }

    void TestUnixProcessEnumerateInstances()
    {
        std::wstring errMsg;
        TestableContext context;
        StandardTestEnumerateInstances<mi::SCX_UnixProcess_Class_Provider>(
            m_keyNamesUP, context, CALL_LOCATION(errMsg));
        CPPUNIT_ASSERT_MESSAGE(ERROR_MESSAGE, context.Size() > 10);

        ValidateInstance(context, CALL_LOCATION(errMsg));
    }

    void TestUnixProcessStatisticalInformationEnumerateInstances()
    {
        std::wstring errMsg;
        TestableContext context;
        StandardTestEnumerateInstances<mi::SCX_UnixProcessStatisticalInformation_Class_Provider>(
            m_keyNamesUPS, context, CALL_LOCATION(errMsg));
        CPPUNIT_ASSERT_MESSAGE(ERROR_MESSAGE, context.Size() > 10);

        ValidateInstanceStatisticalInformation(context, CALL_LOCATION(errMsg));
    }

    void TestUnixProcessGetInstance()
    {
        std::wstring errMsg;
        TestableContext context;
        StandardTestGetInstance<mi::SCX_UnixProcess_Class_Provider,
            mi::SCX_UnixProcess_Class>(
            context, m_keyNamesUP.size(), CALL_LOCATION(errMsg));

        ValidateInstance(context, CALL_LOCATION(errMsg));
    }

    void TestUnixProcessStatisticalInformationGetInstance()
    {
        std::wstring errMsg;
        TestableContext context;
        StandardTestGetInstance<mi::SCX_UnixProcessStatisticalInformation_Class_Provider,
            mi::SCX_UnixProcessStatisticalInformation_Class>(
            context, m_keyNamesUPS.size(), CALL_LOCATION(errMsg));

        ValidateInstanceStatisticalInformation(context, CALL_LOCATION(errMsg));
    }

    void TestUnixProcessGetThisInstance()
    {
        std::wstring errMsg;
        TestableContext context;

        std::vector<std::wstring> keyValues;
        keyValues.push_back(L"SCX_ComputerSystem");
        keyValues.push_back(GetFQHostName(CALL_LOCATION(errMsg)));
        keyValues.push_back(L"SCX_OperatingSystem");
        keyValues.push_back(GetDistributionName(CALL_LOCATION(errMsg)));
        keyValues.push_back(L"SCX_UnixProcess");
        keyValues.push_back(SCXCoreLib::StrFrom(getpid()));

        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, MI_RESULT_OK, (GetInstance<
            mi::SCX_UnixProcess_Class_Provider, mi::SCX_UnixProcess_Class>(
            m_keyNamesUP, keyValues, context, CALL_LOCATION(errMsg))));
        
        // Yes, but is it us?
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, L"testrunner", context[0].GetProperty("Name",
            CALL_LOCATION(errMsg)).GetValue_MIString(CALL_LOCATION(errMsg)));

        ValidateInstance(context, CALL_LOCATION(errMsg));
    }

    void TestUnixProcessStatisticalInformationGetThisInstance()
    {
        std::wstring errMsg;
        TestableContext context;

        std::vector<std::wstring> keyValues;
        keyValues.push_back(L"testrunner");// Looking for us.
        keyValues.push_back(L"SCX_ComputerSystem");
        keyValues.push_back(GetFQHostName(CALL_LOCATION(errMsg)));
        keyValues.push_back(L"SCX_OperatingSystem");
        keyValues.push_back(GetDistributionName(CALL_LOCATION(errMsg)));
        keyValues.push_back(SCXCoreLib::StrFrom(getpid()));
        keyValues.push_back(L"SCX_UnixProcessStatisticalInformation");

        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, MI_RESULT_OK, (GetInstance<
            mi::SCX_UnixProcessStatisticalInformation_Class_Provider, mi::SCX_UnixProcessStatisticalInformation_Class>(
            m_keyNamesUPS, keyValues, context, CALL_LOCATION(errMsg))));

        ValidateInstanceStatisticalInformation(context, CALL_LOCATION(errMsg));
    }

    bool GetTopResourceConsumers(const char* resourceName, std::wstring errMsg)
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
        std::wstring errMsg;
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, true, GetTopResourceConsumers("CPUTime", CALL_LOCATION(errMsg)));
    }

    void TestUnixProcessInvokeTopResourceConsumersFail()
    {
        std::wstring errMsg;
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, false,
            GetTopResourceConsumers("InvalidResource", CALL_LOCATION(errMsg)));
    }

    void ValidateInstance(const TestableContext& context, std::wstring errMsg)
    {
        for (size_t n = 0; n < context.Size(); n++)
        {
            const TestableInstance &instance = context[n];

            std::vector<std::wstring> tmpExpectedProperties;
            std::vector<std::wstring> tmpPossibleProperties;
            tmpExpectedProperties.push_back(L"Caption");
            tmpExpectedProperties.push_back(L"Description");
            tmpExpectedProperties.push_back(L"Name");
            tmpExpectedProperties.push_back(L"CSCreationClassName");
            tmpExpectedProperties.push_back(L"CSName");
            tmpExpectedProperties.push_back(L"OSCreationClassName");
            tmpExpectedProperties.push_back(L"OSName");
            tmpExpectedProperties.push_back(L"CreationClassName");
            tmpExpectedProperties.push_back(L"Handle");
            tmpExpectedProperties.push_back(L"ExecutionState");
            tmpExpectedProperties.push_back(L"CreationDate");
            tmpPossibleProperties.push_back(L"TerminationDate");
            tmpExpectedProperties.push_back(L"KernelModeTime");
            tmpExpectedProperties.push_back(L"UserModeTime");
            tmpExpectedProperties.push_back(L"ParentProcessID");
            tmpExpectedProperties.push_back(L"RealUserID");
            tmpExpectedProperties.push_back(L"ProcessGroupID");
            tmpExpectedProperties.push_back(L"ProcessNiceValue");
            tmpExpectedProperties.push_back(L"Priority");
#if defined(hpux)
            tmpPossibleProperties.push_back(L"ProcessSessionID");
#else
            tmpExpectedProperties.push_back(L"ProcessSessionID");
#endif
#if !(defined(linux) || defined(aix) || defined(sun))
            tmpExpectedProperties.push_back(L"ProcessTTY");
#endif
#if defined(linux)
            if (brokenProvider == true)
            {
                tmpPossibleProperties.push_back(L"ModulePath");
                tmpPossibleProperties.push_back(L"Parameters");
            }
            else
            {
                tmpExpectedProperties.push_back(L"ModulePath");
                tmpExpectedProperties.push_back(L"Parameters");
            }
#else// linux
#if defined(hpux) || defined(aix) || (defined(sun) && PF_MAJOR == 5 && PF_MINOR > 9)
            tmpPossibleProperties.push_back(L"ModulePath");
#else
            tmpExpectedProperties.push_back(L"ModulePath");
#endif
            tmpPossibleProperties.push_back(L"Parameters");
#endif// linux
#if !(defined(hpux) || defined(aix) || defined(sun))
            tmpPossibleProperties.push_back(L"ProcessWaitingForEvent");
#endif

            VerifyInstancePropertyNames(instance, &tmpExpectedProperties[0], tmpExpectedProperties.size(),
                &tmpPossibleProperties[0], tmpPossibleProperties.size(), CALL_LOCATION(errMsg));
        }
    }

    void ValidateInstanceStatisticalInformation(const TestableContext& context, std::wstring errMsg)
    {
        for (size_t n = 0; n < context.Size(); n++)
        {
            const TestableInstance &instance = context[n];

            std::wstring tmpExpectedProperties[] = {
                                                    L"Caption",
                                                    L"Description",
                                                    L"Name",
                                                    L"CSCreationClassName",
                                                    L"CSName",
                                                    L"OSCreationClassName",
                                                    L"OSName",
                                                    L"Handle",
                                                    L"ProcessCreationClassName",
                                                    L"CPUTime",
                                                    L"VirtualData",
                                                    L"CpuTimeDeadChildren",
                                                    L"SystemTimeDeadChildren",
                                                    L"PercentUserTime",
                                                    L"PercentPrivilegedTime",
                                                    L"UsedMemory",
                                                    L"PercentUsedMemory",
#if !(defined(linux) || defined(sun) || defined(aix))
                                                    L"RealText",
                                                    L"RealData",
                                                    L"RealStack",
                                                    L"VirtualMemoryMappedFileSize",
#endif
#if !defined(aix)
                                                    L"VirtualText",
                                                    L"PagesReadPerSec",
#endif
#if !defined(linux)
                                                    L"VirtualStack",
#endif
#if !(defined(sun) || defined(aix))
                                                    L"VirtualSharedMemory",
#endif
#if !(defined(linux) || defined(aix))
                                                    L"BlockReadsPerSecond",
                                                    L"BlockWritesPerSecond",
                                                    L"BlockTransfersPerSecond",
#endif
                                                    };

            const size_t numprops = sizeof(tmpExpectedProperties) / sizeof(tmpExpectedProperties[0]);
            VerifyInstancePropertyNames(instance, tmpExpectedProperties, numprops, CALL_LOCATION(errMsg));
        }
    }
};

CPPUNIT_TEST_SUITE_REGISTRATION( SCXProcessProviderTest );
