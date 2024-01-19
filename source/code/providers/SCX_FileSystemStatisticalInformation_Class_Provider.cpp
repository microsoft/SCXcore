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
#include <scxcorelib/scxregex.h>
#include <scxcorelib/scxpatternfinder.h>

# define QLENGTH 1000

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
        scxulong data3;
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

        if (diskinst->GetDiskSize(data1, data2, data3))
        {
            inst.FreeMegabytes_value(data2);
            inst.UsedMegabytes_value(data1);
            unsigned char freeSpace = 100;
            unsigned char usedSpace = 0;
            scxulong totalData = data1 + data2;
            if (0 < totalData)
            {
                freeSpace = (unsigned char) SCXCoreLib::GetPercentage(0, data2, 0, totalData);
                usedSpace = (unsigned char) SCXCoreLib::GetPercentage(0, data1, 0, totalData);
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
    SCXLogHandle& log = SCXCore::g_FileSystemProvider.GetLogHandle();
    SCX_LOGTRACE(log, L"FileSystemStat EnumerateInstances begin");

    SCX_PEX_BEGIN
    {
        // Global lock for DiskProvider class
        SCXCoreLib::SCXThreadLock lock(SCXCoreLib::ThreadLockHandleGet(L"SCXCore::DiskProvider::Lock"));

        // Prepare File System Enumeration
        // (Note: Only do full update if we're not enumerating keys)

        wstring mountPoint=L"";
        size_t instancePos=(size_t)-1;

        if(filter) {
            char* exprStr[QLENGTH]={NULL};
            char* qtypeStr[QLENGTH]={NULL};

            const MI_Char** expr=(const MI_Char**)&exprStr;
            const MI_Char** qtype=(const MI_Char**)&qtypeStr;

            MI_Filter_GetExpression(filter, qtype, expr);
            SCX_LOGTRACE(log, SCXCoreLib::StrAppend(L"FileSystemStatisticalInformation Provider Filter Set with Expression: ",*expr));

            std::wstring filterQuery(SCXCoreLib::StrFromUTF8(*expr));

            SCXCoreLib::SCXPatternFinder::SCXPatternCookie s_patternID = 0, id=0;
            SCXCoreLib::SCXPatternFinder::SCXPatternMatch param;
            std::wstring s_pattern(L"select * from SCX_FileSystemStatisticalInformation where Name=%name");

            SCXCoreLib::SCXPatternFinder patterenfinder;
            patterenfinder.RegisterPattern(s_patternID, s_pattern);

            bool status=patterenfinder.Match(filterQuery, id, param);


            if ( status && param.end() != param.find(L"name") && id == s_patternID )
            {
                mountPoint=param.find(L"name")->second;
                SCX_LOGTRACE(log,  SCXCoreLib::StrAppend(L"FileSystemStatisticalInformation Provider Enum Requested for mount point: ",mountPoint));
            }
        }

        SCXHandle<SCXSystemLib::StatisticalLogicalDiskEnumeration> diskEnum = SCXCore::g_FileSystemProvider.getEnumstatisticalLogicalDisks();

        mountPoint != L"" && mountPoint != L"_Total"?diskEnum->UpdateSpecific(mountPoint, &instancePos):diskEnum->Update(!keysOnly); 
        if (instancePos != (size_t)-1)
        {
            SCXHandle<SCXSystemLib::StatisticalLogicalDiskInstance> diskInst = diskEnum->GetInstance(instancePos);
            SCX_FileSystemStatisticalInformation_Class inst;
            EnumerateOneInstance(context, inst, keysOnly, diskInst);
        }
        else
        {
            for(size_t i = 0; i < diskEnum->Size(); i++)
            {
                SCXHandle<SCXSystemLib::StatisticalLogicalDiskInstance> diskInst = diskEnum->GetInstance(i);
                SCX_FileSystemStatisticalInformation_Class inst;
                EnumerateOneInstance(context, inst, keysOnly, diskInst);
            }

            SCXHandle<SCXSystemLib::StatisticalLogicalDiskInstance> totalInst= diskEnum->GetTotalInstance();
            if (totalInst != NULL)
            {
            	// There will always be one total instance
            	SCX_FileSystemStatisticalInformation_Class inst;
            	EnumerateOneInstance(context, inst, keysOnly, totalInst);
            }
        }

        context.Post(MI_RESULT_OK);
    }
    SCX_PEX_END( L"SCX_FileSystemStatisticalInformation_Class_Provider::EnumerateInstances", log );

    SCX_LOGTRACE(log, L"FileSystemStat EnumerateInstances end");
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
