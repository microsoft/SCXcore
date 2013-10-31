/*--------------------------------------------------------------------------------
    Copyright (c) Microsoft Corporation. All rights reserved. See license.txt for license information.
*/
/**
    \file        SCX_FileSystemStatisticalInformation_Class_Provider.cpp

    \brief       Provider support using OMI framework.
    
    \date        03-14-2013 11:09:45
*/
/*----------------------------------------------------------------------------*/

/* @migen@ */
#include <MI.h>
#include "SCX_FileSystemStatisticalInformation_Class_Provider.h"
#include <scxcorelib/scxcmn.h>
#include <scxcorelib/stringaid.h>
#include <scxcorelib/scxnameresolver.h>
#include <scxcorelib/scxmath.h>
#include "support/filesystemprovider.h"
#include "support/scxcimutils.h"

using namespace SCXCoreLib;
using namespace SCXSystemLib;

MI_BEGIN_NAMESPACE

static void EnumerateOneInstance(
    Context& context,
    SCX_FileSystemStatisticalInformation_Class& inst,
    bool keysOnly,
    SCXHandle<SCXSystemLib::StatisticalLogicalDiskInstance> diskinst)
{
    diskinst->Update();

    // Populate the key values
    std::wstring name;
    if (diskinst->GetDiskName(name))
    {
        inst.Name_value(StrToMultibyte(name).c_str());
    }

    if (!keysOnly)
    {
        inst.Caption_value("File system information");
        inst.Description_value("Performance statistics related to a logical unit of secondary storage");

        scxulong data1;
        scxulong data2;
        double ddata1;
        bool healthy;

        if (diskinst->GetHealthState(healthy))
        {
            inst.IsOnline_value(healthy);
        }

        inst.IsAggregate_value(diskinst->IsTotal());

        if (diskinst->GetIOPercentageTotal(data1))
        {
            inst.PercentBusyTime_value((unsigned char) data1);
            inst.PercentIdleTime_value((unsigned char) (100-data1));
        }

        if (diskinst->GetBytesPerSecondTotal(data1))
        {
            inst.BytesPerSecond_value(data1);
        }

        if (diskinst->GetBytesPerSecond(data1, data2))
        {
            inst.ReadBytesPerSecond_value(data1);
            inst.WriteBytesPerSecond_value(data2);
        }

        if (diskinst->GetTransfersPerSecond(data1))
        {
            inst.TransfersPerSecond_value(data1);
        }

        if (diskinst->GetReadsPerSecond(data1))
        {
            inst.ReadsPerSecond_value(data1);
        }

        if (diskinst->GetWritesPerSecond(data1))
        {
            inst.WritesPerSecond_value(data1);
        }

        if (diskinst->GetIOTimesTotal(ddata1))
        {
            inst.AverageTransferTime_value(ddata1);
        }

        if (diskinst->GetDiskSize(data1, data2))
        {
            inst.FreeMegabytes_value(data2);
            inst.UsedMegabytes_value(data1);
            unsigned char freeSpace = 100;
            unsigned char usedSpace = 0;
            if (0 < data1+data2)
            {
                freeSpace = (unsigned char) SCXCoreLib::GetPercentage(0, data2, 0, data1+data2);
                usedSpace = (unsigned char) SCXCoreLib::GetPercentage(0, data2, 0, data1+data2, true);
            }
            inst.PercentFreeSpace_value(freeSpace);
            inst.PercentUsedSpace_value(usedSpace);
        }

        // Report percentages for inodes even if inode data is not known
        {
            if (!diskinst->GetInodeUsage(data1, data2))
            {
                data1 = data2 = 0;
            }
            unsigned char freeInodes = 100;
            unsigned char usedInodes = 0;

            if (0 < data1+data2)
            {
                freeInodes = (unsigned char) SCXCoreLib::GetPercentage(0, data2, 0, data1);
                usedInodes = (unsigned char) SCXCoreLib::GetPercentage(0, data2, 0, data1, true);
            }

            inst.PercentFreeInodes_value(freeInodes);
            inst.PercentUsedInodes_value(usedInodes);
        }

        if (diskinst->GetDiskQueueLength(ddata1))
        {
            inst.AverageDiskQueueLength_value(ddata1);
        }
    }
    context.Post(inst);
}

SCX_FileSystemStatisticalInformation_Class_Provider::SCX_FileSystemStatisticalInformation_Class_Provider(
    Module* module) :
    m_Module(module)
{
}

SCX_FileSystemStatisticalInformation_Class_Provider::~SCX_FileSystemStatisticalInformation_Class_Provider()
{
}

void SCX_FileSystemStatisticalInformation_Class_Provider::Load(
        Context& context)
{
    SCX_PEX_BEGIN
    {
        // Global lock for DiskProvider class
        SCXCoreLib::SCXThreadLock lock(SCXCoreLib::ThreadLockHandleGet(L"SCXCore::DiskProvider::Lock"));
        SCXCore::g_FileSystemProvider.Load();

        // Notify that we don't wish to unload
        MI_Result r = context.RefuseUnload();
        if ( MI_RESULT_OK != r )
        {
            SCX_LOGWARNING(SCXCore::g_FileSystemProvider.GetLogHandle(),
            SCXCoreLib::StrAppend(L"SCX_FileSystemStatisticalInformation_Class_Provider::Load() refuses to not unload, error = ", r));
        }

        context.Post(MI_RESULT_OK);
    }
    SCX_PEX_END(  L"SCX_FileSystemStatisticalInformation_Class_Provider::Load", SCXCore::g_FileSystemProvider.GetLogHandle() );
}

void SCX_FileSystemStatisticalInformation_Class_Provider::Unload(
        Context& context)
{
    SCX_PEX_BEGIN
    {
        // Global lock for DiskProvider class
        SCXCoreLib::SCXThreadLock lock(SCXCoreLib::ThreadLockHandleGet(L"SCXCore::DiskProvider::Lock"));
        SCXCore::g_FileSystemProvider.UnLoad();
        context.Post(MI_RESULT_OK);
    }
    SCX_PEX_END( L"SCX_FileSystemStatisticalInformation_Class_Provider::Unload", SCXCore::g_FileSystemProvider.GetLogHandle() );
}

void SCX_FileSystemStatisticalInformation_Class_Provider::EnumerateInstances(
    Context& context,
    const String& nameSpace,
    const PropertySet& propertySet,
    bool keysOnly,
    const MI_Filter* filter)
{
    SCX_PEX_BEGIN
    {
        // Global lock for DiskProvider class
        SCXCoreLib::SCXThreadLock lock(SCXCoreLib::ThreadLockHandleGet(L"SCXCore::DiskProvider::Lock"));

        //  Prepare FIle System Enumeration
        // (Note: Only do full update if we're not enumerating keys)
        SCXHandle<SCXSystemLib::StatisticalLogicalDiskEnumeration> diskEnum = SCXCore::g_FileSystemProvider.getEnumstatisticalLogicalDisks();
        diskEnum->Update(!keysOnly);

        for(size_t i = 0; i < diskEnum->Size(); i++)
        {
            SCX_FileSystemStatisticalInformation_Class inst;
            SCXHandle<SCXSystemLib::StatisticalLogicalDiskInstance> diskInst = diskEnum->GetInstance(i);
            EnumerateOneInstance(context, inst, keysOnly, diskInst);
        }

        SCXHandle<SCXSystemLib::StatisticalLogicalDiskInstance> totalInst= diskEnum->GetTotalInstance();
        if (totalInst != NULL)
        {
            // There will always be one total instance
            SCX_FileSystemStatisticalInformation_Class inst;
            EnumerateOneInstance(context, inst, keysOnly, totalInst);
        }

        context.Post(MI_RESULT_OK);
    }
    SCX_PEX_END( L"SCX_FileSystemStatisticalInformation_Class_Provider::EnumerateInstances",
                      SCXCore::g_FileSystemProvider.GetLogHandle() );
}

void SCX_FileSystemStatisticalInformation_Class_Provider::GetInstance(
    Context& context,
    const String& nameSpace,
    const SCX_FileSystemStatisticalInformation_Class& instanceName,
    const PropertySet& propertySet)
{
    SCX_PEX_BEGIN
    {
        // Global lock for DiskProvider class
        SCXCoreLib::SCXThreadLock lock(SCXCoreLib::ThreadLockHandleGet(L"SCXCore::DiskProvider::Lock"));

        SCXHandle<SCXSystemLib::StatisticalLogicalDiskEnumeration> diskEnum = SCXCore::g_FileSystemProvider.getEnumstatisticalLogicalDisks();
        diskEnum->Update(true);

        const std::string name = instanceName.Name_value().Str();

        if (name.size() == 0)
        {
            context.Post(MI_RESULT_INVALID_PARAMETER);
            return;
        }

        SCXHandle<SCXSystemLib::StatisticalLogicalDiskInstance> diskInst;
        diskInst = diskEnum->GetInstance(StrFromUTF8(name));

        if (diskInst == NULL)
        {
            context.Post(MI_RESULT_NOT_FOUND);
            return;
        }

        SCX_FileSystemStatisticalInformation_Class inst;
        EnumerateOneInstance(context, inst, false, diskInst);
        context.Post(MI_RESULT_OK);
    }
    SCX_PEX_END( L"SCX_FileSystemStatisticalInformation_Class_Provider::GetInstance", 
                      SCXCore::g_FileSystemProvider.GetLogHandle() )
}

void SCX_FileSystemStatisticalInformation_Class_Provider::CreateInstance(
    Context& context,
    const String& nameSpace,
    const SCX_FileSystemStatisticalInformation_Class& newInstance)
{
    context.Post(MI_RESULT_NOT_SUPPORTED);
}

void SCX_FileSystemStatisticalInformation_Class_Provider::ModifyInstance(
    Context& context,
    const String& nameSpace,
    const SCX_FileSystemStatisticalInformation_Class& modifiedInstance,
    const PropertySet& propertySet)
{
    context.Post(MI_RESULT_NOT_SUPPORTED);
}

void SCX_FileSystemStatisticalInformation_Class_Provider::DeleteInstance(
    Context& context,
    const String& nameSpace,
    const SCX_FileSystemStatisticalInformation_Class& instanceName)
{
    context.Post(MI_RESULT_NOT_SUPPORTED);
}


MI_END_NAMESPACE
