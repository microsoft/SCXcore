/*--------------------------------------------------------------------------------
    Copyright (c) Microsoft Corporation.  All rights reserved.

    Created date    2008-09-22 15:22:00

    Operating System provider test class.

    Only tests the functionality of the provider class.
    The actual data gathering is tested by a separate class.
*/
/*----------------------------------------------------------------------------*/

#include <scxcorelib/scxcmn.h>
#include <scxcorelib/scxexception.h>
#include <scxsystemlib/scxostypeinfo.h>
#include <scxsystemlib/osenumeration.h>
#include <testutils/scxunit.h>
#include <testutils/providertestutils.h>
#include <cppunit/extensions/HelperMacros.h>
#include <testutils/scxunit.h>
#include "support/osprovider.h"
#include "SCX_OperatingSystem_Class_Provider.h"

using namespace SCXCore;
using namespace SCXCoreLib;
using namespace SCXSystemLib;

class OSProvider_Test : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE( OSProvider_Test  );
    CPPUNIT_TEST( callDumpStringForCoverage );
    CPPUNIT_TEST( TestEnumerateInstancesKeysOnly );
    CPPUNIT_TEST( TestEnumerateInstances );
    CPPUNIT_TEST( TestGetInstance );
    CPPUNIT_TEST( TestVerifyKeyCompletePartial );

    SCXUNIT_TEST_ATTRIBUTE(callDumpStringForCoverage, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(TestEnumerateInstancesKeysOnly, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(TestEnumerateInstances, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(TestGetInstance, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(TestVerifyKeyCompletePartial, SLOW);
    CPPUNIT_TEST_SUITE_END();

private:
    std::vector<std::wstring> m_keyNames;

public:

    OSProvider_Test()
    {
        m_keyNames.push_back(L"Name");
        m_keyNames.push_back(L"CSCreationClassName");
        m_keyNames.push_back(L"CSName");
        m_keyNames.push_back(L"CreationClassName");
    }

    void setUp(void)
    {
        std::wostringstream errMsg;
        SetUpAgent<mi::SCX_OperatingSystem_Class_Provider>(CALL_LOCATION(errMsg));
    }

    void tearDown(void)
    {
        std::wostringstream errMsg;
        TearDownAgent<mi::SCX_OperatingSystem_Class_Provider>(CALL_LOCATION(errMsg));
    }

    void callDumpStringForCoverage()
    {
        CPPUNIT_ASSERT(g_OSProvider.DumpString().find(L"OSProvider") != std::wstring::npos);
    }

    void TestEnumerateInstancesKeysOnly()
    {
        std::wostringstream errMsg;
        TestableContext context;
        StandardTestEnumerateKeysOnly<mi::SCX_OperatingSystem_Class_Provider>(
            m_keyNames, context, CALL_LOCATION(errMsg));
        CPPUNIT_ASSERT_EQUAL(1u, context.Size());
    }

    void TestEnumerateInstances()
    {
        std::wostringstream errMsg;
        TestableContext context;
        StandardTestEnumerateInstances<mi::SCX_OperatingSystem_Class_Provider>(
            m_keyNames, context, CALL_LOCATION(errMsg));
        CPPUNIT_ASSERT_EQUAL(1u, context.Size());

        ValidateInstance(context, CALL_LOCATION(errMsg));
    }

    void TestGetInstance()
    {
        std::wostringstream errMsg;
        TestableContext context;
        StandardTestGetInstance<mi::SCX_OperatingSystem_Class_Provider,
            mi::SCX_OperatingSystem_Class>(context, m_keyNames.size(), CALL_LOCATION(errMsg));
        ValidateInstance(context, CALL_LOCATION(errMsg));
    }

    void TestVerifyKeyCompletePartial()
    {
        std::wostringstream errMsg;
        StandardTestVerifyGetInstanceKeys<mi::SCX_OperatingSystem_Class_Provider,
                mi::SCX_OperatingSystem_Class>(m_keyNames, CALL_LOCATION(errMsg));
    }

    void ValidateInstance(const TestableContext &context, std::wostringstream &errMsg)
    {
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, 1u, context.Size());
        
        const TestableInstance &instance = context[0];
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE,
            GetDistributionName(CALL_LOCATION(errMsg)), instance.GetKeyValue(0, CALL_LOCATION(errMsg)));
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, L"SCX_ComputerSystem", instance.GetKeyValue(1, CALL_LOCATION(errMsg)));
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE,
            GetFQHostName(CALL_LOCATION(errMsg)), instance.GetKeyValue(2, CALL_LOCATION(errMsg)));
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, L"SCX_OperatingSystem", instance.GetKeyValue(3, CALL_LOCATION(errMsg)));
#if defined(linux)
        std::wstring tmpExpectedProperties[] = {L"Caption",
                                                L"Description",
                                                L"Name",
                                                L"EnabledState",
                                                L"RequestedState",
                                                L"EnabledDefault",
                                                L"CSCreationClassName",
                                                L"CSName",
                                                L"CreationClassName",
                                                L"OSType",
                                                L"OtherTypeDescription",
                                                L"Version",
                                                L"LastBootUpTime",
                                                L"LocalDateTime",
                                                L"CurrentTimeZone",
                                                L"NumberOfLicensedUsers",
                                                L"NumberOfUsers",
                                                L"NumberOfProcesses",
                                                L"MaxNumberOfProcesses",
                                                L"TotalSwapSpaceSize",
                                                L"TotalVirtualMemorySize",
                                                L"FreeVirtualMemory",
                                                L"FreePhysicalMemory",
                                                L"TotalVisibleMemorySize",
                                                L"SizeStoredInPagingFiles",
                                                L"FreeSpaceInPagingFiles",
                                                L"MaxProcessMemorySize",
                                                L"MaxProcessesPerUser",
                                                L"OperatingSystemCapability",
                                                L"SystemUpTime"
        };
#elif defined(aix)
        std::wstring tmpExpectedProperties[] = {L"Caption",
                                                L"Description",
                                                L"Name",
                                                L"EnabledState",
                                                L"RequestedState",
                                                L"EnabledDefault",
                                                L"CSCreationClassName",
                                                L"CSName",
                                                L"CreationClassName",
                                                L"OSType",
                                                L"OtherTypeDescription",
                                                L"Version",
                                                L"LocalDateTime",
                                                L"CurrentTimeZone",
                                                L"NumberOfLicensedUsers",
                                                L"NumberOfUsers",
                                                L"NumberOfProcesses",
                                                L"TotalSwapSpaceSize",
                                                L"TotalVirtualMemorySize",
                                                L"FreeVirtualMemory",
                                                L"FreePhysicalMemory",
                                                L"TotalVisibleMemorySize",
                                                L"SizeStoredInPagingFiles",
                                                L"FreeSpaceInPagingFiles",
                                                L"OperatingSystemCapability",
                                                L"MaxProcessMemorySize",
                                                L"MaxProcessesPerUser"
        };
#elif defined(hpux)
        std::wstring tmpExpectedProperties[] = {L"Caption",
                                                L"Description",
                                                L"Name",
                                                L"EnabledState",
                                                L"RequestedState",
                                                L"EnabledDefault",
                                                L"CSCreationClassName",
                                                L"CSName",
                                                L"CreationClassName",
                                                L"OSType",
                                                L"OtherTypeDescription",
                                                L"Version",
                                                L"LastBootUpTime",
                                                L"LocalDateTime",
                                                L"CurrentTimeZone",
                                                L"NumberOfLicensedUsers",
                                                L"NumberOfUsers",
                                                L"NumberOfProcesses",
                                                L"MaxNumberOfProcesses",
                                                L"TotalSwapSpaceSize",
                                                L"TotalVirtualMemorySize",
                                                L"FreeVirtualMemory",
                                                L"FreePhysicalMemory",
                                                L"TotalVisibleMemorySize",
                                                L"SizeStoredInPagingFiles",
                                                L"FreeSpaceInPagingFiles",
                                                L"MaxProcessMemorySize",
                                                L"MaxProcessesPerUser",
                                                L"OperatingSystemCapability",
                                                L"SystemUpTime"
        };
#elif defined(sun)
        std::wstring tmpExpectedProperties[] = {L"Caption",
                                                L"Description",
                                                L"Name",
                                                L"EnabledState",
                                                L"RequestedState",
                                                L"EnabledDefault",
                                                L"CSCreationClassName",
                                                L"CSName",
                                                L"CreationClassName",
                                                L"OSType",
                                                L"OtherTypeDescription",
                                                L"Version",
                                                L"LocalDateTime",
                                                L"CurrentTimeZone",
                                                L"NumberOfLicensedUsers",
                                                L"NumberOfUsers",
                                                L"NumberOfProcesses",
                                                L"TotalSwapSpaceSize",
                                                L"TotalVirtualMemorySize",
                                                L"FreeVirtualMemory",
                                                L"FreePhysicalMemory",
                                                L"TotalVisibleMemorySize",
                                                L"SizeStoredInPagingFiles",
                                                L"FreeSpaceInPagingFiles",
                                                L"MaxProcessMemorySize",
                                                L"MaxProcessesPerUser",
                                                L"OperatingSystemCapability"
        };
#else
#error Platform not supported
#endif
        const size_t numprops = sizeof(tmpExpectedProperties) / sizeof(tmpExpectedProperties[0]);
        std::set<std::wstring> expectedProperties(tmpExpectedProperties, tmpExpectedProperties + numprops);

        for (MI_Uint32 i = 0; i < instance.GetNumberOfProperties(); ++i)
        {
            TestableInstance::PropertyInfo info;
            CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, MI_RESULT_OK, instance.FindProperty(i, info));
            CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE + "Property mismatch: " + SCXCoreLib::StrToMultibyte(info.name),
                1u, expectedProperties.count(info.name));
        }

        // Be sure that all of the properties in our set exist in the property list
        for (std::set<std::wstring>::const_iterator iter = expectedProperties.begin();
             iter != expectedProperties.end(); ++iter)
        {
#if defined(PF_DISTRO_ULINUX)
            // Universal system OS provider looks at installed path to run GetLinuxOS.sh.
            // If the kit isn't installed, "Version" is not set. For this reason we skip the "Version" property.
            if (L"Version" == *iter)
            {
                continue;
            }
#endif // defined(PF_DISTRO_ULINUX)
            TestableInstance::PropertyInfo info;
            CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE + "Missing property: " + SCXCoreLib::StrToMultibyte(*iter),
                MI_RESULT_OK, instance.FindProperty((*iter).c_str(), info));
        }
    
        std::wstring strCaption = instance.GetProperty(L"Caption", CALL_LOCATION(errMsg)).
            GetValue_MIString(CALL_LOCATION(errMsg));
        scxulong uiCountProcesses = instance.GetProperty(L"NumberOfProcesses", CALL_LOCATION(errMsg)).
            GetValue_MIUint32(CALL_LOCATION(errMsg));
        scxulong ulTotalSwap = instance.GetProperty(L"TotalSwapSpaceSize", CALL_LOCATION(errMsg)).
            GetValue_MIUint64(CALL_LOCATION(errMsg));
        scxulong ulTotalVM = instance.GetProperty(L"TotalVirtualMemorySize", CALL_LOCATION(errMsg)).
            GetValue_MIUint64(CALL_LOCATION(errMsg));
        scxulong ulFreeVM = instance.GetProperty(L"FreeVirtualMemory", CALL_LOCATION(errMsg)).
            GetValue_MIUint64(CALL_LOCATION(errMsg));
        scxulong ulFreeMem = instance.GetProperty(L"FreePhysicalMemory", CALL_LOCATION(errMsg)).
            GetValue_MIUint64(CALL_LOCATION(errMsg));
        scxulong ulTotalMem = instance.GetProperty(L"TotalVisibleMemorySize", CALL_LOCATION(errMsg)).
            GetValue_MIUint64(CALL_LOCATION(errMsg));
        scxulong ulTotalPage = instance.GetProperty(L"SizeStoredInPagingFiles", CALL_LOCATION(errMsg)).
            GetValue_MIUint64(CALL_LOCATION(errMsg));
        scxulong ulFreePage = instance.GetProperty(L"FreeSpaceInPagingFiles", CALL_LOCATION(errMsg)).
            GetValue_MIUint64(CALL_LOCATION(errMsg));
        std::wstring strOSCapability = instance.GetProperty(L"OperatingSystemCapability", CALL_LOCATION(errMsg)).
            GetValue_MIString(CALL_LOCATION(errMsg));

        // On ULINUX, we may be running on an installed machine
#if !defined(PF_DISTRO_ULINUX)
        CPPUNIT_ASSERT(6 <= strCaption.length());
#endif
        CPPUNIT_ASSERT(uiCountProcesses > 0);
        CPPUNIT_ASSERT(256000 <= ulTotalSwap);
        CPPUNIT_ASSERT(512000 <= ulTotalVM);
        CPPUNIT_ASSERT(ulFreeVM <= ulTotalVM);
        CPPUNIT_ASSERT(ulFreeMem <= ulTotalMem);
        CPPUNIT_ASSERT(128000 <= ulTotalMem);
        CPPUNIT_ASSERT(256000 <= ulTotalPage);
        CPPUNIT_ASSERT(ulFreePage <= ulTotalPage);
        CPPUNIT_ASSERT(strOSCapability == L"32 bit" || strOSCapability == L"64 bit");
    }
};

CPPUNIT_TEST_SUITE_REGISTRATION( OSProvider_Test );
