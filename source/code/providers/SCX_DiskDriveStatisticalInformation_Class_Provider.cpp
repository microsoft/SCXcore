/*--------------------------------------------------------------------------------
    Copyright (c) Microsoft Corporation. All rights reserved. See license.txt for license information.
*/
/**
    \file        SCX_DiskDriveStatisticalInformation_Class_Provider.cpp

    \brief       Provider support using OMI framework.
    
    \date        03-14-2013 11:09:45
*/
/*----------------------------------------------------------------------------*/

/* @migen@ */
#include <MI.h>
#include "SCX_DiskDriveStatisticalInformation_Class_Provider.h"
#include <scxcorelib/scxcmn.h>
#include <scxcorelib/stringaid.h>
#include <scxcorelib/scxnameresolver.h>
#include "support/diskprovider.h"
#include "support/scxcimutils.h"

using namespace SCXCoreLib;
using namespace SCXSystemLib;


MI_BEGIN_NAMESPACE

static void EnumerateOneInstance(
    Context& context,
    SCX_DiskDriveStatisticalInformation_Class& inst,
    bool keysOnly,
    SCXHandle<SCXSystemLib::StatisticalPhysicalDiskInstance> diskinst)
{
    // Populate the key values
    std::wstring name;
    if (diskinst->GetDiskName(name))
    {
        inst.Name_value(StrToMultibyte(name).c_str());
    }

    if (!keysOnly)
    {
        inst.Caption_value("Disk drive information");
        inst.Description_value("Performance statistics related to a physical unit of secondary storage");

        scxulong data1;
        scxulong data2;
        double ddata1;
        double ddata2;
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

        if (diskinst->GetIOTimes(ddata1, ddata2))
        {
            inst.AverageReadTime_value(ddata1);
            inst.AverageWriteTime_value(ddata2);
        }

        if (diskinst->GetDiskQueueLength(ddata1))
        {
            inst.AverageDiskQueueLength_value(ddata1);
        }
    }
    context.Post(inst);
}

SCX_DiskDriveStatisticalInformation_Class_Provider::SCX_DiskDriveStatisticalInformation_Class_Provider(
    Module* module) :
    m_Module(module)
{
}

SCX_DiskDriveStatisticalInformation_Class_Provider::~SCX_DiskDriveStatisticalInformation_Class_Provider()
{
}

void SCX_DiskDriveStatisticalInformation_Class_Provider::Load(
        Context& context)
{
    SCX_PEX_BEGIN
    {
        // Global lock for DiskProvider class
        SCXCoreLib::SCXThreadLock lock(SCXCoreLib::ThreadLockHandleGet(L"SCXCore::DiskProvider::Lock"));
        SCXCore::g_DiskProvider.Load();

        // Notify that we don't wish to unload
        MI_Result r = context.RefuseUnload();
        if ( MI_RESULT_OK != r )
        {
            SCX_LOGWARNING(SCXCore::g_DiskProvider.GetLogHandle(),
                SCXCoreLib::StrAppend(L"SCX_DiskDriveStatisticalInformation_Class_Provider::Load() refuses to not unload, error = ", r));
        }

        context.Post(MI_RESULT_OK);
    }
    SCX_PEX_END(  L"SCX_DiskDriveStatisticalInformation_Class_Provider::Load", SCXCore::g_DiskProvider.GetLogHandle() );
}

void SCX_DiskDriveStatisticalInformation_Class_Provider::Unload(
        Context& context)
{
    SCX_PEX_BEGIN
    {
        // Global lock for DiskProvider class
        SCXCoreLib::SCXThreadLock lock(SCXCoreLib::ThreadLockHandleGet(L"SCXCore::DiskProvider::Lock"));
        SCXCore::g_DiskProvider.UnLoad();
        context.Post(MI_RESULT_OK);
    }
    SCX_PEX_END( L"SCX_DiskDriveStatisticalInformation_Class_Provider::Unload", SCXCore::g_DiskProvider.GetLogHandle() );
}

void SCX_DiskDriveStatisticalInformation_Class_Provider::EnumerateInstances(
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

        //  Prepare Disk Drive Enumeration
        // (Note: Only do full update if we're not enumerating keys)
        SCXCoreLib::SCXHandle<SCXSystemLib::StatisticalPhysicalDiskEnumeration> diskEnum = SCXCore::g_DiskProvider.getEnumstatisticalPhysicalDisks();
        diskEnum->Update(!keysOnly);

        for(size_t i = 0; i < diskEnum->Size(); i++)
        {
            SCX_DiskDriveStatisticalInformation_Class inst;
            SCXHandle<SCXSystemLib::StatisticalPhysicalDiskInstance> diskInst = diskEnum->GetInstance(i);
            EnumerateOneInstance(context, inst, keysOnly, diskInst);
        }

        // Enumerate Total instance
        SCXHandle<SCXSystemLib::StatisticalPhysicalDiskInstance> totalInst= diskEnum->GetTotalInstance();
        if (totalInst != NULL)
        {
            // There will always be one total instance
            SCX_DiskDriveStatisticalInformation_Class inst;
            EnumerateOneInstance(context, inst, keysOnly, totalInst);
        }

        context.Post(MI_RESULT_OK);
    }
    SCX_PEX_END( L"SCX_DiskDriveStatisticalInformation_Class_Provider::EnumerateInstances",
                     SCXCore::g_DiskProvider.GetLogHandle() );
}

void SCX_DiskDriveStatisticalInformation_Class_Provider::GetInstance(
    Context& context,
    const String& nameSpace,
    const SCX_DiskDriveStatisticalInformation_Class& instanceName,
    const PropertySet& propertySet)
{
    SCX_PEX_BEGIN
    {
        // Global lock for DiskProvider class
        SCXCoreLib::SCXThreadLock lock(SCXCoreLib::ThreadLockHandleGet(L"SCXCore::DiskProvider::Lock"));

        SCXHandle<SCXSystemLib::StatisticalPhysicalDiskEnumeration> diskEnum = SCXCore::g_DiskProvider.getEnumstatisticalPhysicalDisks();
        diskEnum->Update(true);

        const std::string name = instanceName.Name_value().Str();
        if (name.size() == 0)
        {
            context.Post(MI_RESULT_INVALID_PARAMETER);
            return;
        }

        SCXHandle<SCXSystemLib::StatisticalPhysicalDiskInstance> diskInst;
        diskInst = diskEnum->GetInstance(StrFromUTF8(name));

        if (diskInst == NULL)
        {
            context.Post(MI_RESULT_NOT_FOUND);
            return;
        }

        SCX_DiskDriveStatisticalInformation_Class inst;
        EnumerateOneInstance(context, inst, false, diskInst);
        context.Post(MI_RESULT_OK);
    }
    SCX_PEX_END( L"SCX_DiskDriveStatisticalInformation_Class_Provider::GetInstance",
                      SCXCore::g_DiskProvider.GetLogHandle() );
}

void SCX_DiskDriveStatisticalInformation_Class_Provider::CreateInstance(
    Context& context,
    const String& nameSpace,
    const SCX_DiskDriveStatisticalInformation_Class& newInstance)
{
    context.Post(MI_RESULT_NOT_SUPPORTED);
}

void SCX_DiskDriveStatisticalInformation_Class_Provider::ModifyInstance(
    Context& context,
    const String& nameSpace,
    const SCX_DiskDriveStatisticalInformation_Class& modifiedInstance,
    const PropertySet& propertySet)
{
    context.Post(MI_RESULT_NOT_SUPPORTED);
}

void SCX_DiskDriveStatisticalInformation_Class_Provider::DeleteInstance(
    Context& context,
    const String& nameSpace,
    const SCX_DiskDriveStatisticalInformation_Class& instanceName)
{
    context.Post(MI_RESULT_NOT_SUPPORTED);
}


MI_END_NAMESPACE
