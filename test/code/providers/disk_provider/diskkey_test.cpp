/*--------------------------------------------------------------------------------
  Copyright (c) Microsoft Corporation.  All rights reserved.

*/
/**
   \file

   \brief       Tests the keys of the SCX_DiskDrive and SCX_FileSystem classes

   \date        2008-09-23 12:51:03

*/
/*----------------------------------------------------------------------------*/

#include <scxcorelib/scxcmn.h>
#include <source/code/providers/disk_provider/diskprovider.h>
#include <scxcorelib/scxexception.h>
#include <testutils/scxunit.h>
#include <testutils/disktestutils.h>
#include <testutils/providertestutils.h>
#include "testablediskprovider.h"

using namespace SCXCore;
using namespace SCXCoreLib;
using namespace SCXSystemLib;
using namespace SCXProviderLib;


class SCXDiskKeyTest : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE( SCXDiskKeyTest );
    CPPUNIT_TEST( testGetFileSystemStatisticalInformationInstance );
    CPPUNIT_TEST( testGetDiskDriveStatisticalInformationInstance );
    CPPUNIT_TEST( testGetDiskDriveInstance );
    CPPUNIT_TEST( testDiskDriveSystemCreationClassName );
    CPPUNIT_TEST( testDiskDriveSystemNameIsSameForAll );
    CPPUNIT_TEST( testDiskDriveCreationClassName );
    CPPUNIT_TEST( testDiskDriveDeviceIDIsKey );

    CPPUNIT_TEST( testFileSystemNameIsKey );
    CPPUNIT_TEST( testFileSystemCreationClassName );
    CPPUNIT_TEST( testFileSystemCSCreationClassName );
    CPPUNIT_TEST( testFileSystemCSNameIsSameForAll );

    SCXUNIT_TEST_ATTRIBUTE(testGetFileSystemStatisticalInformationInstance, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(testGetDiskDriveStatisticalInformationInstance, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(testGetDiskDriveInstance, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(testDiskDriveSystemCreationClassName, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(testDiskDriveSystemNameIsSameForAll, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(testDiskDriveCreationClassName, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(testDiskDriveDeviceIDIsKey, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(testFileSystemNameIsKey, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(testFileSystemCreationClassName, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(testFileSystemCSCreationClassName, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(testFileSystemCSNameIsSameForAll, SLOW);
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp(void)
    {
    }

    void tearDown(void)
    {
    }

    void testGetFileSystemStatisticalInformationInstance()
    {
        try {
            TestableDiskProvider provider;
            std::vector<std::wstring> keyNames;
            keyNames.push_back(L"Name");
            CPPUNIT_ASSERT(provider.VerifyGetInstanceByCompleteKeySuccess(L"SCX_FileSystemStatisticalInformation", keyNames,
                    TestableProvider::eKeysOnly));
            CPPUNIT_ASSERT(provider.VerifyGetInstanceByPartialKeyFailure(L"SCX_FileSystemStatisticalInformation", keyNames,
                    TestableProvider::eKeysOnly));
        } catch (SCXAccessViolationException&) {
            // Skip access violations because some properties
            // require root access.
            SCXUNIT_WARNING(L"Skipping test - need root access");
            SCXUNIT_RESET_ASSERTION();
        }
    }

    void testGetDiskDriveStatisticalInformationInstance()
    {
        if ( ! HasPhysicalDisks(L"SCXDiskKeyTest::testGetDiskDriveStatisticalInformationInstance") )
            return;

        try {
            TestableDiskProvider provider;
            std::vector<std::wstring> keyNames;
            keyNames.push_back(L"Name");
            CPPUNIT_ASSERT(provider.VerifyGetInstanceByCompleteKeySuccess(L"SCX_DiskDriveStatisticalInformation", keyNames,
                    TestableProvider::eKeysOnly));
            CPPUNIT_ASSERT(provider.VerifyGetInstanceByPartialKeyFailure(L"SCX_DiskDriveStatisticalInformation", keyNames,
                    TestableProvider::eKeysOnly));
        } catch (SCXAccessViolationException&) {
            // Skip access violations because some properties
            // require root access.
            SCXUNIT_WARNING(L"Skipping test - need root access");
            SCXUNIT_RESET_ASSERTION();
        }
    }

    void testGetDiskDriveInstance()
    {
        if ( ! HasPhysicalDisks(L"SCXDiskKeyTest::testGetDiskDriveInstance") )
            return;

        try {
            TestableDiskProvider provider;
            std::vector<std::wstring> keyNames;
            keyNames.push_back(L"CreationClassName");
            keyNames.push_back(L"SystemCreationClassName");
            keyNames.push_back(L"SystemName");
            keyNames.push_back(L"DeviceID");
            CPPUNIT_ASSERT(provider.VerifyGetInstanceByCompleteKeySuccess(L"SCX_DiskDrive", keyNames));
            CPPUNIT_ASSERT(provider.VerifyGetInstanceByPartialKeyFailure(L"SCX_DiskDrive", keyNames));
        } catch (SCXAccessViolationException&) {
            // Skip access violations because some properties
            // require root access.
            SCXUNIT_WARNING(L"Skipping test - need root access");
            SCXUNIT_RESET_ASSERTION();
        } catch (SCXErrnoOpenException& e) {
            if (e.ErrorNumber() == 13) {
                // Skip permission denied because some properties
                // require root access.
                SCXUNIT_WARNING(L"Skipping test - need root access");
                SCXUNIT_RESET_ASSERTION();
            }
        }
    }

    void testGetFileSystemInstance()
    {
        try {
            TestableDiskProvider provider;
            std::vector<std::wstring> keyNames;
            keyNames.push_back(L"Name");
            keyNames.push_back(L"CSName");
            keyNames.push_back(L"CSCreationClassName");
            keyNames.push_back(L"CreationClassName");
            CPPUNIT_ASSERT(provider.VerifyGetInstanceByCompleteKeySuccess(L"SCX_FileSystem", keyNames));
            CPPUNIT_ASSERT(provider.VerifyGetInstanceByPartialKeyFailure(L"SCX_FileSystem", keyNames));
        } catch (SCXAccessViolationException&) {
            // Skip access violations because some properties
            // require root access.
            SCXUNIT_WARNING(L"Skipping test - need root access");
            SCXUNIT_RESET_ASSERTION();
        }
    }


    void GivenAllInstanceNamesEnumerated(std::wstring classToEnumerate, SCXInstanceCollection& instances)
    {
        SCXCoreLib::SCXHandle<TestableDiskProvider> pp( new TestableDiskProvider() );

        SCXInstance objectPath;
        objectPath.SetCimClassName(classToEnumerate);
        SCXCallContext context(objectPath, eDirectSupport);
        pp->TestDoEnumInstanceNames(context, instances, true);
    }

    /**
        Tests if key is a key for each instance of classToCheck.
     */
    void testIsKey(std::wstring classToCheck, std::wstring key)
    {
        SCXInstanceCollection instances;

        try {
            GivenAllInstanceNamesEnumerated(classToCheck, instances);
        } catch (SCXAccessViolationException&) {
            // Skip access violations because some properties
            // require root access.
            SCXUNIT_WARNING(L"Skipping test - need root access");
            SCXUNIT_RESET_ASSERTION();
            return;
        }

        for(unsigned int i = 0; i < instances.Size(); ++i)
        {
            CPPUNIT_ASSERT_MESSAGE(StrToMultibyte(StrAppend(L"Could not find key: ", key)), NULL != instances[i]->GetKey(key));
        }
    }

    /**
        Tests if key has value "value" for each instance of classToCheck.
     */
    void testKeyValueEquals(std::wstring classToCheck, std::wstring key, std::wstring value)
    {
        SCXInstanceCollection instances;

        try {
            GivenAllInstanceNamesEnumerated(classToCheck, instances);
        } catch (SCXAccessViolationException&) {
            // Skip access violations because some properties
            // require root access.
            SCXUNIT_WARNING(L"Skipping test - need root access");
            SCXUNIT_RESET_ASSERTION();
            return;
        }

        for(unsigned int i = 0; i < instances.Size(); ++i)
        {
            CPPUNIT_ASSERT_MESSAGE(StrToMultibyte(StrAppend(L"Could not find key: ", key)), NULL != instances[i]->GetKey(key));
            CPPUNIT_ASSERT_MESSAGE(StrToMultibyte(StrAppend(L"Value of \"", key).append(L"\" is not \"").append(value).append(L"\"")),
                                   value == instances[i]->GetKey(key)->GetStrValue());
        }
    }

    /**
        Tests if key has the same non-empty value for each instance of classToCheck.
     */
    void testKeyIsSameForAllInstances(std::wstring classToCheck, std::wstring key)
    {
        SCXInstanceCollection instances;

        try {
            GivenAllInstanceNamesEnumerated(classToCheck, instances);
        } catch (SCXAccessViolationException&) {
            // Skip access violations because some properties
            // require root access.
            SCXUNIT_WARNING(L"Skipping test - need root access");
            SCXUNIT_RESET_ASSERTION();
            return;
        }

        if (instances.Size() == 0)
        {
            // Nothing to test;
            return;
        }
        CPPUNIT_ASSERT(NULL != instances[0]->GetKey(key));
        std::wstring value = instances[0]->GetKey(key)->GetStrValue();
        CPPUNIT_ASSERT(L"" != value);
        for(unsigned int i = 1; i < instances.Size(); ++i)
        {
            CPPUNIT_ASSERT_MESSAGE(StrToMultibyte(StrAppend(L"Could not find key: ", key)), NULL != instances[i]->GetKey(key));
            CPPUNIT_ASSERT_MESSAGE(StrToMultibyte(StrAppend(L"Value of \"", key).append(L"\" is not \"").append(value).append(L"\"")),
                                   value == instances[i]->GetKey(key)->GetStrValue());
        }
    }

    void testDiskDriveSystemCreationClassName()
    {
        testKeyValueEquals(L"SCX_DiskDrive", L"SystemCreationClassName", L"SCX_ComputerSystem");
    }

    void testDiskDriveSystemNameIsSameForAll()
    {
        testKeyIsSameForAllInstances(L"SCX_DiskDrive", L"SystemName");
    }

    void testDiskDriveCreationClassName()
    {
        testKeyValueEquals(L"SCX_DiskDrive", L"CreationClassName", L"SCX_DiskDrive");
    }

    void testDiskDriveDeviceIDIsKey()
    {
        testIsKey(L"SCX_DiskDrive", L"DeviceID");
    }

    void  testFileSystemNameIsKey()
    {
        testIsKey(L"SCX_FileSystem", L"Name");
    }

    void  testFileSystemCreationClassName()
    {
        testKeyValueEquals(L"SCX_FileSystem", L"CreationClassName", L"SCX_FileSystem");
    }

    void  testFileSystemCSCreationClassName()
    {
        testKeyValueEquals(L"SCX_FileSystem", L"CSCreationClassName", L"SCX_ComputerSystem");
    }

    void  testFileSystemCSNameIsSameForAll()
    {
        testKeyIsSameForAllInstances(L"SCX_FileSystem", L"CSName");
    }
};

CPPUNIT_TEST_SUITE_REGISTRATION( SCXDiskKeyTest );
