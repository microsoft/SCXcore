/*--------------------------------------------------------------------------------
    Copyright (c) Microsoft Corporation.  All rights reserved.

*/
/**
    \file

    \brief       Tests for the disk provider

    \date        2008-04-24 09:00

*/
/*----------------------------------------------------------------------------*/
#include <scxcorelib/scxcmn.h>
#include <scxsystemlib/scxostypeinfo.h>
#include <scxcorelib/scxexception.h>
#include <cppunit/extensions/HelperMacros.h>
#include <testutils/scxunit.h>
#include <testutils/disktestutils.h>
#include <testutils/providertestutils.h>
#include "support/diskprovider.h"
#include "support/filesystemprovider.h"

#include "SCX_DiskDrive.h"
#include "SCX_DiskDrive_Class_Provider.h"
#include "SCX_DiskDriveStatisticalInformation_Class_Provider.h"
#include "SCX_FileSystem_Class_Provider.h"
#include "SCX_FileSystemStatisticalInformation_Class_Provider.h"

class SCXDiskProviderTest : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE( SCXDiskProviderTest );
    CPPUNIT_TEST( TestCountsAndEnumerations );

    CPPUNIT_TEST( TestEnumInstanceNamesSanity );
    CPPUNIT_TEST( TestPhysicalLogicalDiskDecoupled );
    CPPUNIT_TEST( RemoveTotalInstanceShouldFail );
    CPPUNIT_TEST( RemoveDiskDriveAlsoRemovesStatisticalInstance );
    CPPUNIT_TEST( RemoveFileSystemAlsoRemovesStatisticalInstance );
    
    SCXUNIT_TEST_ATTRIBUTE(TestEnumInstanceNamesSanity, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(TestPhysicalLogicalDiskDecoupled, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(RemoveTotalInstanceShouldFail, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(TestVerifyKeyCompletePartial, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(RemoveDiskDriveAlsoRemovesStatisticalInstance, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(RemoveFileSystemAlsoRemovesStatisticalInstance, SLOW);
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp(void)
    {
        std::wstring errMsg;
        TestableContext context;
        SetUpAgent<mi::SCX_DiskDrive_Class_Provider>(context, CALL_LOCATION(errMsg));
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, true, context.WasRefuseUnloadCalled() );
        SetUpAgent<mi::SCX_DiskDriveStatisticalInformation_Class_Provider>(context, CALL_LOCATION(errMsg));
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, true, context.WasRefuseUnloadCalled() );
        SetUpAgent<mi::SCX_FileSystem_Class_Provider>(context, CALL_LOCATION(errMsg));
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, true, context.WasRefuseUnloadCalled() );
        SetUpAgent<mi::SCX_FileSystemStatisticalInformation_Class_Provider>(context, CALL_LOCATION(errMsg));
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, true, context.WasRefuseUnloadCalled() );
    }

    void tearDown(void)
    {
        std::wstring errMsg;
        TestableContext context;
        TearDownAgent<mi::SCX_DiskDrive_Class_Provider>(context, CALL_LOCATION(errMsg));
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, false, context.WasRefuseUnloadCalled() );
        TearDownAgent<mi::SCX_DiskDriveStatisticalInformation_Class_Provider>(context, CALL_LOCATION(errMsg));
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, false, context.WasRefuseUnloadCalled() );
        TearDownAgent<mi::SCX_FileSystem_Class_Provider>(context, CALL_LOCATION(errMsg));
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, false, context.WasRefuseUnloadCalled() );
        TearDownAgent<mi::SCX_FileSystemStatisticalInformation_Class_Provider>(context, CALL_LOCATION(errMsg));
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, false, context.WasRefuseUnloadCalled() );
    }

    size_t DDCount()
    {
        SCXCoreLib::SCXHandle<SCXSystemLib::StaticPhysicalDiskEnumeration> diskEnum =
            SCXCore::g_DiskProvider.getEnumstaticPhysicalDisks();
        return diskEnum->Size();
    }

    size_t DDSCount()
    {
        SCXCoreLib::SCXHandle<SCXSystemLib::StatisticalPhysicalDiskEnumeration> diskEnum =
            SCXCore::g_DiskProvider.getEnumstatisticalPhysicalDisks();
        // In the case of statistical enumeration classes we set total to 1 because _Total instance is not actually stored
        // in the enumeration collection but is instead generated on the fly. in other cases we set total to 0.
        return diskEnum->Size() + 1;
    }

    size_t FSCount()
    {
        SCXCoreLib::SCXHandle<SCXSystemLib::StaticLogicalDiskEnumeration> diskEnum =
            SCXCore::g_FileSystemProvider.getEnumstaticLogicalDisks();
        return diskEnum->Size();
    }

    size_t FSSCount()
    {
        SCXCoreLib::SCXHandle<SCXSystemLib::StatisticalLogicalDiskEnumeration> diskEnum =
            SCXCore::g_FileSystemProvider.getEnumstatisticalLogicalDisks();
        // In the case of statistical enumeration classes we set total to 1 because _Total instance is not actually stored
        // in the enumeration collection but is instead generated on the fly. in other cases we set total to 0.
        return diskEnum->Size() + 1;
    }

    /*----------------------------------------------------------------------------*/
    //! Removes instance of a disk with a particular name.
    //! \param  T               type of instance to be removed
    //! \param  TInstanceName   type of the parameter with which the remover is called.
    //! \param  TParam          type of the parameter object containing name with which the remover is called.
    //! \param[in]  errMsg      String containing error messages.
    //! \returns                returns true if removal was sucessfull.
    template<class T, class TInstanceName, class TParam> bool InvokeRemoveDisk(const std::wstring& d,
        std::wstring errMsg)
    {
        TestableContext context;
        TInstanceName instanceName;
        TParam param;
        param.Name_value(SCXCoreLib::StrToMultibyte(d).c_str());

        mi::Module Module;
        T agent(&Module);
        agent.Invoke_RemoveByName(context, NULL, instanceName, param);
        if (context.GetResult() == MI_RESULT_OK)
        {
            const std::vector<TestableInstance> &instances = context.GetInstances();
            // We expect two instances to be returned, the instance of the object and then the instance of the return value.
            CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, 2u, instances.size());
            return instances[1].GetMIReturn_MIBoolean(CALL_LOCATION(errMsg));
        }
        return false;
    }

    bool InvokeRemoveDiskDrive(const std::wstring& d, std::wstring errMsg)
    {
        return InvokeRemoveDisk<mi::SCX_DiskDrive_Class_Provider, mi::SCX_DiskDrive_Class,
            mi::SCX_DiskDrive_RemoveByName_Class>(d, CALL_LOCATION(errMsg));
    }
    
    bool InvokeRemoveFileSystem(const std::wstring& d, std::wstring errMsg)
    {
        return InvokeRemoveDisk<mi::SCX_FileSystem_Class_Provider, mi::SCX_FileSystem_Class,
            mi::SCX_FileSystem_RemoveByName_Class>(d, CALL_LOCATION(errMsg));
    }

    void TestCountsAndEnumerations()
    {
        std::wstring errMsg;
        if ( ! MeetsPrerequisites(L"SCXDiskProviderTest::TestCountsAndEnumerations"))
        {
            return;
        }
        if ( ! HasPhysicalDisks(L"SCXDiskProviderTest::TestCountsAndEnumerations") )
        {
            return;
        }

        TestableContext dd, dds, fs, fss;
        EnumInstances<mi::SCX_DiskDrive_Class_Provider>(dd, CALL_LOCATION(errMsg));
        EnumInstances<mi::SCX_DiskDriveStatisticalInformation_Class_Provider>(dds, CALL_LOCATION(errMsg));
        EnumInstances<mi::SCX_FileSystem_Class_Provider>(fs, CALL_LOCATION(errMsg));
        EnumInstances<mi::SCX_FileSystemStatisticalInformation_Class_Provider>(fss, CALL_LOCATION(errMsg));

        CPPUNIT_ASSERT_EQUAL(dd.Size(), DDCount());
        CPPUNIT_ASSERT_EQUAL(dds.Size(), DDSCount());
        CPPUNIT_ASSERT_EQUAL(fs.Size(), FSCount());
        CPPUNIT_ASSERT_EQUAL(fss.Size(), FSSCount());
    }

    void TestEnumInstanceNamesSanity()
    {
        std::wstring errMsg;
        if ( ! MeetsPrerequisites(L"SCXDiskProviderTest::TestEnumInstanceNamesSanity"))
        {
            return;
        }
        if ( ! HasPhysicalDisks(L"SCXDiskProviderTest::TestEnumInstanceNamesSanity") )
        {
            return;
        }

        TestableContext dd, dds, fs, fss;
        EnumInstances<mi::SCX_DiskDrive_Class_Provider>(dd, CALL_LOCATION(errMsg));
        EnumInstances<mi::SCX_DiskDriveStatisticalInformation_Class_Provider>(dds, CALL_LOCATION(errMsg));
        EnumInstances<mi::SCX_FileSystem_Class_Provider>(fs, CALL_LOCATION(errMsg));
        EnumInstances<mi::SCX_FileSystemStatisticalInformation_Class_Provider>(fss, CALL_LOCATION(errMsg));
        // There should be at least one disk/filesystem.
        CPPUNIT_ASSERT(0 < dd.Size()
                       || !HasPhysicalDisks(L"SCXDiskProviderTest::TestEnumInstanceNamesSanity", true));
        CPPUNIT_ASSERT(0 < dds.Size());
        CPPUNIT_ASSERT(0 < fs.Size());
        CPPUNIT_ASSERT(0 < fss.Size());

        // Statistical collections have total instance - the others don't.
        CPPUNIT_ASSERT_EQUAL(dd.Size()+1, dds.Size());
        CPPUNIT_ASSERT_EQUAL(fs.Size()+1, fss.Size());
    }

    void RemoveTotalInstanceShouldFail()
    {
        std::wstring errMsg;
        CPPUNIT_ASSERT( ! InvokeRemoveDiskDrive(L"_Total", CALL_LOCATION(errMsg)));
        CPPUNIT_ASSERT( ! InvokeRemoveFileSystem(L"_Total", CALL_LOCATION(errMsg)));
    }

    void RemoveDiskDriveAlsoRemovesStatisticalInstance(void)
    {
        std::wstring errMsg;

        if ( ! MeetsPrerequisites(L"SCXDiskProviderTest::RemoveDiskDriveAlsoRemovesStatisticalInstance"))
        {
            return;
        }
        if ( ! HasPhysicalDisks(L"SCXDiskProviderTest::RemoveDiskDriveAlsoRemovesStatisticalInstance") )
        {
            return;
        }

        TestableContext dd, dds;
        EnumInstances<mi::SCX_DiskDrive_Class_Provider>(dd, CALL_LOCATION(errMsg));
        EnumInstances<mi::SCX_DiskDriveStatisticalInformation_Class_Provider>(dds, CALL_LOCATION(errMsg));
        const std::vector<TestableInstance> &instances = dd.GetInstances();
        CPPUNIT_ASSERT(instances.size() > 0);
        CPPUNIT_ASSERT( InvokeRemoveDiskDrive(instances[0].GetProperty(L"Name",
            CALL_LOCATION(errMsg)).GetValue_MIString(CALL_LOCATION(errMsg)), CALL_LOCATION(errMsg)));
        CPPUNIT_ASSERT_EQUAL(dd.Size()-1, DDCount());
        CPPUNIT_ASSERT_EQUAL(dds.Size()-1, DDSCount());
    }

    void RemoveFileSystemAlsoRemovesStatisticalInstance(void)
    {
        std::wstring errMsg;

        TestableContext fs, fss;
        EnumInstances<mi::SCX_FileSystem_Class_Provider>(fs, CALL_LOCATION(errMsg));
        EnumInstances<mi::SCX_FileSystemStatisticalInformation_Class_Provider>(fss, CALL_LOCATION(errMsg));
        const std::vector<TestableInstance> &instances = fs.GetInstances();
        CPPUNIT_ASSERT(instances.size() > 0);
        CPPUNIT_ASSERT( InvokeRemoveFileSystem(instances[0].GetProperty(L"Name",
            CALL_LOCATION(errMsg)).GetValue_MIString(CALL_LOCATION(errMsg)), CALL_LOCATION(errMsg)));

        CPPUNIT_ASSERT_EQUAL(fs.Size()-1, FSCount());
        CPPUNIT_ASSERT_EQUAL(fss.Size()-1, FSSCount());
    }
    
    void TestPhysicalLogicalDiskDecoupled(void)
    {
        // This test ensures that DiskDrive and LogicalDisk providers are decoupled. No instances of
        // StaticPhysicalDiskInstance or StatisticalPhysicalDiskInstance should be created while LogicalDisk provider
        // is running.

        // Before we run our test we first shut down any existing DiskDrive objects so we can check if any were created
        // during the test.
        std::wstring errMsg;
        TestableContext context;
        TearDownAgent<mi::SCX_DiskDrive_Class_Provider>(context, CALL_LOCATION(errMsg));
        TearDownAgent<mi::SCX_DiskDriveStatisticalInformation_Class_Provider>(context, CALL_LOCATION(errMsg));

        // Get the state before the LogicalDisk provider is ran.
        CPPUNIT_ASSERT_EQUAL_MESSAGE("After shutting down SCX_DiskDrive_Class_Provider there "
            "are still StaticPhysicalDiskInstance-s present. Memory leak?",
            0u, SCXSystemLib::StaticPhysicalDiskInstance::GetCurrentInstancesCount());
        CPPUNIT_ASSERT_EQUAL_MESSAGE("After shutting down SCX_DiskDriveStatisticalInformation_Class_Provider there "
            "are still StatisticalPhysicalDiskInstance-s present. Memory leak?",
            0u, SCXSystemLib::StatisticalPhysicalDiskInstance::GetCurrentInstancesCount());
        size_t staticPhysicalInstancesSinceStart =
            SCXSystemLib::StaticPhysicalDiskInstance::GetInstancesCountSinceModuleStart();
        size_t statisticalPhysicalInstancesSinceStart =
            SCXSystemLib::StatisticalPhysicalDiskInstance::GetInstancesCountSinceModuleStart();

        // Run the LogicalDisk provider.
        TestableContext fs, fss;
        EnumInstances<mi::SCX_FileSystem_Class_Provider>(fs, CALL_LOCATION(errMsg));
        EnumInstances<mi::SCX_FileSystemStatisticalInformation_Class_Provider>(fss, CALL_LOCATION(errMsg));
        CPPUNIT_ASSERT_MESSAGE("There are no logical disks on this system?!", 0 < fs.Size());
        CPPUNIT_ASSERT_EQUAL_MESSAGE("Mismatch between static and statistical disk drive counts", fs.Size()+1, fss.Size());

        // Verify no DiskDrive disk instances were created.
        CPPUNIT_ASSERT_EQUAL_MESSAGE("After running FileSystem and FileSystemStatisticalInformation providers there "
            "are StaticPhysicalDiskInstance-s present.",
            0u, SCXSystemLib::StaticPhysicalDiskInstance::GetCurrentInstancesCount());
        CPPUNIT_ASSERT_EQUAL_MESSAGE("After running FileSystem and FileSystemStatisticalInformation providers there "
            "are StatisticalPhysicalDiskInstance-s present.",
            0u, SCXSystemLib::StatisticalPhysicalDiskInstance::GetCurrentInstancesCount());
        CPPUNIT_ASSERT_EQUAL_MESSAGE("While running FileSystem and FileSystemStatisticalInformation providers "
            "StaticPhysicalDiskInstance-s were created.",
            staticPhysicalInstancesSinceStart,
            SCXSystemLib::StaticPhysicalDiskInstance::GetInstancesCountSinceModuleStart());
        CPPUNIT_ASSERT_EQUAL_MESSAGE("While running FileSystem and FileSystemStatisticalInformation providers "
            "StatisticalPhysicalDiskInstance-s were created.",
            statisticalPhysicalInstancesSinceStart,
            SCXSystemLib::StatisticalPhysicalDiskInstance::GetInstancesCountSinceModuleStart());

        // After the test we restore DiskDrive objects to make sure object counters match (for each destruction
        // there's creation and vice-versa).
        SetUpAgent<mi::SCX_DiskDrive_Class_Provider>(context, CALL_LOCATION(errMsg));
        SetUpAgent<mi::SCX_DiskDriveStatisticalInformation_Class_Provider>(context, CALL_LOCATION(errMsg));
    }
};

CPPUNIT_TEST_SUITE_REGISTRATION( SCXDiskProviderTest );
