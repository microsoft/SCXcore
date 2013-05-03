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
#include <scxsystemlib/scxostypeinfo.h>
#include <scxcorelib/scxexception.h>
#include <testutils/scxunit.h>
#include <testutils/disktestutils.h>
#include <testutils/providertestutils.h>
#include "support/diskprovider.h"

#include "SCX_DiskDrive.h"
#include "SCX_DiskDrive_Class_Provider.h"
#include "SCX_DiskDriveStatisticalInformation_Class_Provider.h"
#include "SCX_FileSystem_Class_Provider.h"
#include "SCX_FileSystemStatisticalInformation_Class_Provider.h"

using namespace SCXCoreLib;
using namespace SCXSystemLib;

class SCXDiskKeyTest : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE( SCXDiskKeyTest );

    CPPUNIT_TEST( TestDiskDriveEnumerateKeysOnly );
    CPPUNIT_TEST( TestFileSystemEnumerateKeysOnly );
    CPPUNIT_TEST( TestDiskDriveStatisticalInformationEnumerateKeysOnly );
    CPPUNIT_TEST( TestFileSystemStatisticalInformationEnumerateKeysOnly );

    CPPUNIT_TEST( TestDiskDriveCheckKeyValues );
    CPPUNIT_TEST( TestFileSystemCheckKeyValues );

    CPPUNIT_TEST( TestVerifyKeyCompletePartialFileSystemStatisticalInformation );
    CPPUNIT_TEST( TestVerifyKeyCompletePartialDiskDriveStatisticalInformation );
    CPPUNIT_TEST( TestVerifyKeyCompletePartialDiskDrive );
    CPPUNIT_TEST( TestVerifyKeyCompletePartialFileSystem );

    CPPUNIT_TEST( TestDiskDriveGetInstance );
    CPPUNIT_TEST( TestFileSystemGetInstance );
    CPPUNIT_TEST( TestDiskDriveStatisticalInformationGetInstance );
    CPPUNIT_TEST( TestFileSystemStatisticalInformationGetInstance );


    SCXUNIT_TEST_ATTRIBUTE(TestDiskDriveEnumerateKeysOnly, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(TestFileSystemEnumerateKeysOnly, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(TestDiskDriveStatisticalInformationEnumerateKeysOnly, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(TestFileSystemStatisticalInformationEnumerateKeysOnly, SLOW);

    SCXUNIT_TEST_ATTRIBUTE(TestDiskDriveCheckKeyValues, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(TestFileSystemCheckKeyValues, SLOW);

    SCXUNIT_TEST_ATTRIBUTE(TestVerifyKeyCompletePartialFileSystemStatisticalInformation, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(TestVerifyKeyCompletePartialDiskDriveStatisticalInformation, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(TestVerifyKeyCompletePartialDiskDrive, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(TestVerifyKeyCompletePartialFileSystem, SLOW);

    SCXUNIT_TEST_ATTRIBUTE(TestDiskDriveGetInstance, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(TestFileSystemGetInstance, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(TestDiskDriveStatisticalInformationGetInstance, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(TestFileSystemStatisticalInformationGetInstance, SLOW);

    CPPUNIT_TEST_SUITE_END();

private:
    std::vector<std::wstring> m_keyNamesFSS;
    std::vector<std::wstring> m_keyNamesDDS;
    std::vector<std::wstring> m_keyNamesDD;
    std::vector<std::wstring> m_keyNamesFS;

public:
    void setUp(void)
    {
        std::wostringstream errMsg;
        SetUpAgent<mi::SCX_DiskDrive_Class_Provider>(CALL_LOCATION(errMsg));
        SetUpAgent<mi::SCX_DiskDriveStatisticalInformation_Class_Provider>(CALL_LOCATION(errMsg));
        SetUpAgent<mi::SCX_FileSystem_Class_Provider>(CALL_LOCATION(errMsg));
        SetUpAgent<mi::SCX_FileSystemStatisticalInformation_Class_Provider>(CALL_LOCATION(errMsg));

        m_keyNamesFSS.push_back(L"Name");

        m_keyNamesDDS.push_back(L"Name");

        m_keyNamesDD.push_back(L"SystemCreationClassName");
        m_keyNamesDD.push_back(L"SystemName");
        m_keyNamesDD.push_back(L"CreationClassName");
        m_keyNamesDD.push_back(L"DeviceID");

        m_keyNamesFS.push_back(L"Name");
        m_keyNamesFS.push_back(L"CSCreationClassName");
        m_keyNamesFS.push_back(L"CSName");
        m_keyNamesFS.push_back(L"CreationClassName");
    }

    void tearDown(void)
    {
        std::wostringstream errMsg;
        TearDownAgent<mi::SCX_DiskDrive_Class_Provider>(CALL_LOCATION(errMsg));
        TearDownAgent<mi::SCX_DiskDriveStatisticalInformation_Class_Provider>(CALL_LOCATION(errMsg));
        TearDownAgent<mi::SCX_FileSystem_Class_Provider>(CALL_LOCATION(errMsg));
        TearDownAgent<mi::SCX_FileSystemStatisticalInformation_Class_Provider>(CALL_LOCATION(errMsg));
    }

    void TestDiskDriveEnumerateKeysOnly()
    {
        if ( ! MeetsPrerequisites(L"SCXDiskKeyTest::TestDiskDriveEnumerateKeysOnly"))
        {
            return;
        }
        if ( ! HasPhysicalDisks(L"SCXDiskKeyTest::TestDiskDriveEnumerateKeysOnly") )
        {
            return;
        }

        std::wostringstream errMsg;
        TestableContext context;
        StandardTestEnumerateKeysOnly<mi::SCX_DiskDrive_Class_Provider>(
            m_keyNamesDD, context, CALL_LOCATION(errMsg));
    }

    void TestFileSystemEnumerateKeysOnly()
    {
        std::wostringstream errMsg;
        TestableContext context;
        StandardTestEnumerateKeysOnly<mi::SCX_FileSystem_Class_Provider>(
            m_keyNamesFS, context, CALL_LOCATION(errMsg));
    }

    void TestDiskDriveStatisticalInformationEnumerateKeysOnly()
    {
        if ( ! HasPhysicalDisks(L"SCXDiskKeyTest::TestDiskDriveStatisticalInformationEnumerateKeysOnly") )
        {
            return;
        }

        std::wostringstream errMsg;
        TestableContext context;
        StandardTestEnumerateKeysOnly<mi::SCX_DiskDriveStatisticalInformation_Class_Provider>(
            m_keyNamesDDS, context, CALL_LOCATION(errMsg));
    }

    void TestFileSystemStatisticalInformationEnumerateKeysOnly()
    {
        std::wostringstream errMsg;
        TestableContext context;
        StandardTestEnumerateKeysOnly<mi::SCX_FileSystemStatisticalInformation_Class_Provider>(
            m_keyNamesFSS, context, CALL_LOCATION(errMsg));
    }

    void TestDiskDriveCheckKeyValues()
    {
        if ( ! MeetsPrerequisites(L"SCXDiskKeyTest::TestDiskDriveCheckKeyValues"))
        {
            return;
        }
        if ( ! HasPhysicalDisks(L"SCXDiskKeyTest::TestDiskDriveCheckKeyValues") )
        {
            return;
        }

        std::wostringstream errMsg;
// Some hpux may timeout because can't find server address.
// Some sun may return mix of upper-lower case in the provider, impossible to compare, for example sun10.SCX.com.
#if !defined(sun) && !defined(hpux)
        std::wstring fqHostName = GetFQHostName(CALL_LOCATION(errMsg));
#endif
        TestableContext context;

        std::vector<std::wstring> keysSame;
        keysSame.push_back(L"SystemName");

        std::vector<std::wstring> keyNames;
        std::vector<std::wstring> keyValues;
        keyNames.push_back(L"SystemCreationClassName");
        keyValues.push_back(L"SCX_ComputerSystem");
#if !defined(sun) && !defined(hpux)
        keyNames.push_back(L"SystemName");
        keyValues.push_back(fqHostName);
#endif
        keyNames.push_back(L"CreationClassName");
        keyValues.push_back(L"SCX_DiskDrive");
        StandardTestCheckKeyValues<mi::SCX_DiskDrive_Class_Provider>(keyNames, keyValues, keysSame, context,
            CALL_LOCATION(errMsg));
    }

    void TestFileSystemCheckKeyValues()
    {
        std::wostringstream errMsg;
// Some hpux may timeout because can't find server address.
// Some sun may return mix of upper-lower case in the provider, impossible to compare, for example sun10.SCX.com.
#if !defined(sun) && !defined(hpux)
        std::wstring fqHostName = GetFQHostName(CALL_LOCATION(errMsg));
#endif
        TestableContext context;

        std::vector<std::wstring> keysSame;
        keysSame.push_back(L"CSName");

        std::vector<std::wstring> keyNames;
        std::vector<std::wstring> keyValues;
        keyNames.push_back(L"CSCreationClassName");
        keyValues.push_back(L"SCX_ComputerSystem");
#if !defined(sun) && !defined(hpux)
        keyNames.push_back(L"CSName");
        keyValues.push_back(fqHostName);
#endif
        keyNames.push_back(L"CreationClassName");
        keyValues.push_back(L"SCX_FileSystem");
        StandardTestCheckKeyValues<mi::SCX_FileSystem_Class_Provider>(keyNames, keyValues, keysSame, context,
            CALL_LOCATION(errMsg));
    }

    void TestDiskDriveGetInstance()
    {
        if ( ! MeetsPrerequisites(L"SCXDiskKeyTest::TestDiskDriveGetInstance"))
        {
            return;
        }
        if ( ! HasPhysicalDisks(L"SCXDiskKeyTest::TestDiskDriveGetInstance") )
        {
            return;
        }

        std::wostringstream errMsg;
        TestableContext context;
        StandardTestGetInstance<mi::SCX_DiskDrive_Class_Provider, mi::SCX_DiskDrive_Class>(
            context, m_keyNamesDD.size(), CALL_LOCATION(errMsg));
    }

    void TestFileSystemGetInstance()
    {
        std::wostringstream errMsg;
        TestableContext context;
        StandardTestGetInstance<mi::SCX_FileSystem_Class_Provider, mi::SCX_FileSystem_Class>(
            context, m_keyNamesFS.size(), CALL_LOCATION(errMsg));
    }

    void TestDiskDriveStatisticalInformationGetInstance()
    {
        if ( ! HasPhysicalDisks(L"SCXDiskKeyTest::TestDiskDriveStatisticalInformationGetInstance") )
        {
            return;
        }

        std::wostringstream errMsg;
        TestableContext context;
        StandardTestGetInstance<mi::SCX_DiskDriveStatisticalInformation_Class_Provider,
            mi::SCX_DiskDriveStatisticalInformation_Class>(
            context, m_keyNamesDDS.size(), CALL_LOCATION(errMsg));
    }

    void TestFileSystemStatisticalInformationGetInstance()
    {
        std::wostringstream errMsg;
        TestableContext context;
        StandardTestGetInstance<mi::SCX_FileSystemStatisticalInformation_Class_Provider,
            mi::SCX_FileSystemStatisticalInformation_Class>(
            context, m_keyNamesFSS.size(), CALL_LOCATION(errMsg));
    }

    void TestVerifyKeyCompletePartialFileSystemStatisticalInformation()
    {
        std::wostringstream errMsg;
        StandardTestVerifyGetInstanceKeys<mi::SCX_FileSystemStatisticalInformation_Class_Provider,
                mi::SCX_FileSystemStatisticalInformation_Class>(m_keyNamesFSS, CALL_LOCATION(errMsg));
    }

    void TestVerifyKeyCompletePartialDiskDriveStatisticalInformation()
    {
        if ( ! HasPhysicalDisks(L"SCXDiskKeyTest::TestVerifyKeyCompletePartialDiskDriveStatisticalInformation") )
        {
            return;
        }

        std::wostringstream errMsg;
        StandardTestVerifyGetInstanceKeys<mi::SCX_DiskDriveStatisticalInformation_Class_Provider,
                mi::SCX_DiskDriveStatisticalInformation_Class>(m_keyNamesDDS, CALL_LOCATION(errMsg));
    }

    void TestVerifyKeyCompletePartialDiskDrive()
    {
        if ( ! MeetsPrerequisites(L"SCXDiskKeyTest::TestVerifyKeyCompletePartialDiskDrive"))
        {
            return;
        }
        if ( ! HasPhysicalDisks(L"SCXDiskKeyTest::TestVerifyKeyCompletePartialDiskDrive") )
        {
            return;
        }
 
        std::wostringstream errMsg;
        StandardTestVerifyGetInstanceKeys<mi::SCX_DiskDrive_Class_Provider,
                mi::SCX_DiskDrive_Class>(m_keyNamesDD, CALL_LOCATION(errMsg));
    }

    void TestVerifyKeyCompletePartialFileSystem()
    {
        std::wostringstream errMsg;
        StandardTestVerifyGetInstanceKeys<mi::SCX_FileSystem_Class_Provider,
                mi::SCX_FileSystem_Class>(m_keyNamesFS, CALL_LOCATION(errMsg));
    }
};

CPPUNIT_TEST_SUITE_REGISTRATION( SCXDiskKeyTest );
