/*--------------------------------------------------------------------------------
    Copyright (c) Microsoft Corporation.  All rights reserved.

    Created date    2008-09-22 15:22:00

    Operating System provider test class.

    Only tests the functionality of the provider class.
    The actual data gathering is tested by a separate class.
*/
/*----------------------------------------------------------------------------*/

#include <scxcorelib/scxcmn.h>

#include <osprovider.h>

#include <testutils/providertestutils.h>

#include <cppunit/extensions/HelperMacros.h>
#include <testutils/scxunit.h>

using namespace SCXCore;
using namespace SCXCoreLib;
using namespace SCXSystemLib;
using namespace SCXProviderLib;

class TestableOSProvider : public TestableProvider, public OSProvider
{
public:
    void TestDoInit()
    {
        DoInit();
    }

    void TestDoEnumInstanceNames(const SCXProviderLib::SCXCallContext& callContext,
                                 SCXProviderLib::SCXInstanceCollection &names)
    {
        DoEnumInstanceNames(callContext, names);
    }

    void TestDoEnumInstances(const SCXProviderLib::SCXCallContext& callContext,
                             SCXProviderLib::SCXInstanceCollection &instances)
    {
        DoEnumInstances(callContext, instances);
    }

    void TestDoGetInstance(const SCXProviderLib::SCXCallContext& callContext,
                           SCXProviderLib::SCXInstance& instance)
    {
        DoGetInstance(callContext, instance);
    }

    void TestDoInvokeMethod(const SCXProviderLib::SCXCallContext& callContext,
                            const std::wstring& methodname, const SCXProviderLib::SCXArgs& args,
                            SCXProviderLib::SCXArgs& outargs, SCXProviderLib::SCXProperty& result)
    {
        DoInvokeMethod(callContext, methodname, args, outargs, result);
    }

    void TestDoCleanup()
    {
        DoCleanup();
    }
};

class OSProvider_Test : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE( OSProvider_Test  );
    CPPUNIT_TEST( callDumpStringForCoverage );
    CPPUNIT_TEST( testDoEnumInstanceNames );
    CPPUNIT_TEST( testDoEnumInstances );
    CPPUNIT_TEST( testDoGetInstance );

    SCXUNIT_TEST_ATTRIBUTE(callDumpStringForCoverage, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(testDoEnumInstanceNames, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(testDoEnumInstances, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(testDoGetInstance, SLOW);
    CPPUNIT_TEST_SUITE_END();

private:
    SCXCoreLib::SCXHandle<TestableOSProvider> mp;

public:

    void setUp(void)
    {
        mp = new TestableOSProvider();
        mp->TestDoInit();
    }

    void tearDown(void)
    {
        mp->TestDoCleanup();
        mp = 0;
    }

    void callDumpStringForCoverage()
    {
        CPPUNIT_ASSERT(mp->DumpString().find(L"OSProvider") != std::wstring::npos);
    }

    void testDoEnumInstanceNames()
    {
        SCXInstanceCollection instances;
        SCXInstance objectPath;
        SCXCallContext context(objectPath, eDirectSupport);

        mp->TestDoEnumInstanceNames(context, instances);

        CPPUNIT_ASSERT(1 == instances.Size());
        CPPUNIT_ASSERT(4 == instances[0]->NumberOfKeys());
        CPPUNIT_ASSERT(L"Name" == instances[0]->GetKey(0)->GetName());
        CPPUNIT_ASSERT(L"CSCreationClassName" == instances[0]->GetKey(1)->GetName());
        CPPUNIT_ASSERT(L"CSName" == instances[0]->GetKey(2)->GetName());
        CPPUNIT_ASSERT(L"CreationClassName" == instances[0]->GetKey(3)->GetName());
    }

    void testDoEnumInstances()
    {
        SCXInstanceCollection instances;
        SCXInstance objectPath;
        SCXCallContext context(objectPath, eDirectSupport);

        mp->TestDoEnumInstances(context, instances);

        CPPUNIT_ASSERT(1 == instances.Size());
        CPPUNIT_ASSERT(4 == instances[0]->NumberOfKeys());

        // Can't validate Key 0 (Name): Distribution name
        CPPUNIT_ASSERT(L"SCX_ComputerSystem" == instances[0]->GetKey(1)->GetStrValue());
        // Can't validate Key 2 (CSName): hostname.domain
        CPPUNIT_ASSERT(L"SCX_OperatingSystem" == instances[0]->GetKey(3)->GetStrValue());

        ValidateInstance(*(instances[0]));
    }


    void testDoGetInstance()
    {
        SCXProperty key(L"Name", L"SCX_OperatingSystem");
        SCXInstance instance;
        SCXInstance objectPath;

        objectPath.AddKey(key);

        SCXCallContext context(objectPath, eDirectSupport);
        mp->TestDoGetInstance(context, instance);

        ValidateInstance(instance);
    }

    void ValidateInstance(const SCXInstance& instance)
    {
#if defined(linux)
        std::wstring tmpExpectedProperties[] = {L"Caption",
                                                L"Description",
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
        const int numprops = sizeof(tmpExpectedProperties) / sizeof(tmpExpectedProperties[0]);
        std::set<std::wstring> expectedProperties(tmpExpectedProperties, tmpExpectedProperties + numprops);

        for (size_t i = 0; i < instance.NumberOfProperties(); ++i)
        {
            const SCXProperty* prop = instance.GetProperty(i);
            CPPUNIT_ASSERT_MESSAGE(
                std::string("Property mismatch: ") + SCXCoreLib::StrToMultibyte(prop->GetName()),
                1 == expectedProperties.count(prop->GetName()));
        }

        // Be sure that all of the properties in our set exist in the property list
        for (std::set<std::wstring>::const_iterator iter = expectedProperties.begin();
             iter != expectedProperties.end();
             ++iter)
        {
#if defined(PF_DISTRO_ULINUX)
            // Universal system OS provider looks at installed path to run GetLinuxOS.sh.
            // If the kit isn't installed, things fail.  Fix that!
            if (L"Version" == *iter)
            {
                continue;
            }
#endif // defined(PF_DISTRO_ULINUX)
            CPPUNIT_ASSERT_MESSAGE(
                std::string("Missing property: ") + SCXCoreLib::StrToMultibyte(*iter),
                0 != instance.GetProperty(*iter));
        }

        // Do some basic validity tests on some properties that always exist
        // Note: Some of the numeric tests are "reasonable guesses", and may need adjustments

        const SCXProperty *propCaption = instance.GetProperty(L"Caption");
        const SCXProperty *propCountProcesses = instance.GetProperty(L"NumberOfProcesses");
        const SCXProperty *propTotalSwap = instance.GetProperty(L"TotalSwapSpaceSize");
        const SCXProperty *propTotalVM = instance.GetProperty(L"TotalVirtualMemorySize");
        const SCXProperty *propFreeVM = instance.GetProperty(L"FreeVirtualMemory");
        const SCXProperty *propFreeMem = instance.GetProperty(L"FreePhysicalMemory");
        const SCXProperty *propTotalMem = instance.GetProperty(L"TotalVisibleMemorySize");
        const SCXProperty *propTotalPage = instance.GetProperty(L"SizeStoredInPagingFiles");
        const SCXProperty *propFreePage = instance.GetProperty(L"FreeSpaceInPagingFiles");
        const SCXProperty *propOSCapability = instance.GetProperty(L"OperatingSystemCapability");

        std::wstring strCaption = propCaption->GetStrValue();
        scxulong uiCountProcesses = propCountProcesses->GetUIntValue();
        scxulong ulTotalSwap = propTotalSwap->GetULongValue();
        scxulong ulTotalVM = propTotalVM->GetULongValue();
        scxulong ulFreeVM = propFreeVM->GetULongValue();
        scxulong ulFreeMem = propFreeMem->GetULongValue();
        scxulong ulTotalMem = propTotalMem->GetULongValue();
        scxulong ulTotalPage = propTotalPage->GetULongValue();
        scxulong ulFreePage = propFreePage->GetULongValue();
        std::wstring strOSCapability = propOSCapability->GetStrValue();

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
