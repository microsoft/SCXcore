/*--------------------------------------------------------------------------------
    Copyright (c) Microsoft Corporation. All rights reserved. See license.txt for license information.
*/
/**
    \file        SCX_MemoryStatisticalInformation_Class_Provider.cpp

    \brief       Provider support using OMI framework.
    
    \date        03-22-2013 17:48:44
*/
/*----------------------------------------------------------------------------*/

/* @migen@ */
#include <MI.h>
#include "SCX_MemoryStatisticalInformation_Class_Provider.h"

#include <scxcorelib/scxcmn.h>
#include <scxcorelib/scxlog.h>
#include <scxcorelib/stringaid.h>
#include <scxsystemlib/memoryenumeration.h>
#include <scxcorelib/scxmath.h>

#include "support/startuplog.h"
#include "support/memoryprovider.h"
#include "support/scxcimutils.h"

using namespace SCXSystemLib;
using namespace SCXCoreLib;

MI_BEGIN_NAMESPACE

static void EnumerateOneInstance(
    Context& context,
    SCX_MemoryStatisticalInformation_Class& inst,
    bool keysOnly,
    SCXCoreLib::SCXHandle<SCXSystemLib::MemoryInstance> meminst)
{
    // Populate the key values
    inst.Name_value("Memory");

    if (!keysOnly)
    {
        scxulong physmem = 0;
        scxulong resmem = 0;
        scxulong usermem = 0;
        scxulong avail = 0;
        scxulong data = 0;
        scxulong data2 = 0;

        inst.Caption_value("Memory information");
        inst.Description_value("Memory usage and performance statistics");

        inst.IsAggregate_value(meminst->IsTotal());

        if (meminst->GetTotalPhysicalMemory(physmem))
        {
            // Adjust numbers from PAL to Megabytes
            physmem = BytesToMegaBytes(physmem);

            if (meminst->GetReservedMemory(resmem))
            {
                resmem = BytesToMegaBytes(resmem);
            }
            else
            {
                resmem = 0;
            }

            // If available, get memory unavailable for user processes and remove it from physical memory
            usermem = physmem - resmem;
        }

        if (meminst->GetAvailableMemory(avail))
        {
            // Adjust numbers from PAL to Megabytes
            avail = BytesToMegaBytes(avail);
            inst.AvailableMemory_value(avail);

            // If we have a number for physical memory use it to compute a percentage
            if (usermem > 0)
            {
                // Need an unsigned char since this is what is required by the MOF
                unsigned char percent = static_cast<unsigned char> (GetPercentage(0, avail, 0, usermem));
                inst.PercentAvailableMemory_value(percent);
            }
        }

        if (meminst->GetUsedMemory(data))
        {
            // Adjust numbers from PAL to Megabytes
            data = BytesToMegaBytes(data);
            inst.UsedMemory_value(data);

            // If we have a number for physical memory use it to compute a percentage
            if (usermem > 0)
            {
                unsigned char percent = static_cast<unsigned char> (GetPercentage(0, data, 0, usermem));
                inst.PercentUsedMemory_value(percent);
            }
        }

        {
            data = 0;
            unsigned char percent = static_cast<unsigned char> (0);

            if (meminst->GetCacheSize(data) && usermem > 0)
            {
                percent = static_cast<unsigned char> (GetPercentage(0, BytesToMegaBytes(data), 0, usermem));
            }
            inst.PercentUsedByCache_value(percent);
        }

        bool pageReadsAvailable = meminst->GetPageReads(data);
        bool pageWritesAvailable = meminst->GetPageWrites(data2);
        if (pageReadsAvailable && pageWritesAvailable)
        {
            inst.PagesPerSec_value(data + data2);
        }
        
        if (pageReadsAvailable)
        {
            inst.PagesReadPerSec_value(data);
        }
        
        if (pageWritesAvailable)
        {
            inst.PagesWrittenPerSec_value(data2);
        }

        if (meminst->GetAvailableSwap(data))
        {
            // Adjust numbers from PAL to Megabytes
            data = BytesToMegaBytes(data);
            inst.AvailableSwap_value(data);

            if (meminst->GetTotalSwap(data2))
            {
                // Adjust numbers from PAL to Megabytes
                data2 = BytesToMegaBytes(data2);

                unsigned char percent = static_cast<unsigned char> (GetPercentage(0, data, 0, data2));
                inst.PercentAvailableSwap_value(percent);
            }
        }

        if (meminst->GetUsedSwap(data))
        {
            // Adjust numbers from PAL to Megabytes
            data = BytesToMegaBytes(data);

            inst.UsedSwap_value(data);

            if (meminst->GetTotalSwap(data2))
            {
                // Adjust numbers from PAL to Megabytes
                data2 = BytesToMegaBytes(data2);

                unsigned char percent = static_cast<unsigned char> (GetPercentage(0, data, 0, data2));
                inst.PercentUsedSwap_value(percent);
            }
        }
    }

    context.Post(inst);
}

SCX_MemoryStatisticalInformation_Class_Provider::SCX_MemoryStatisticalInformation_Class_Provider(
    Module* module) :
    m_Module(module)
{
}

SCX_MemoryStatisticalInformation_Class_Provider::~SCX_MemoryStatisticalInformation_Class_Provider()
{
}

void SCX_MemoryStatisticalInformation_Class_Provider::Load(
        Context& context)
{
    SCX_PEX_BEGIN
    {
        // Global lock for MemoryProvider class
        SCXCoreLib::SCXThreadLock lock(SCXCoreLib::ThreadLockHandleGet(L"SCXCore::MemoryProvider::Lock"));
        SCXCore::g_MemoryProvider.Load();

        // Notify that we don't wish to unload
        MI_Result r = context.RefuseUnload();
        if ( MI_RESULT_OK != r )
        {
            SCX_LOGWARNING(SCXCore::g_MemoryProvider.GetLogHandle(),
                SCXCoreLib::StrAppend(L"SCX_MemoryStatisticalInformation_Class_Provider::Load() refuses to not unload, error = ", r));
        }

        context.Post(MI_RESULT_OK);
    }
    SCX_PEX_END( L"SCX_MemoryStatisticalInformation_Class_Provider::Load", SCXCore::g_MemoryProvider.GetLogHandle() );
}

void SCX_MemoryStatisticalInformation_Class_Provider::Unload(
        Context& context)
{
    SCX_PEX_BEGIN
    {
        // Global lock for MemoryProvider class
        SCXCoreLib::SCXThreadLock lock(SCXCoreLib::ThreadLockHandleGet(L"SCXCore::MemoryProvider::Lock"));
        SCXCore::g_MemoryProvider.Unload();
        context.Post(MI_RESULT_OK);
    }
    SCX_PEX_END( L"SCX_MemoryStatisticalInformation_Class_Provider::Unload", SCXCore::g_MemoryProvider.GetLogHandle() );
}

void SCX_MemoryStatisticalInformation_Class_Provider::EnumerateInstances(
    Context& context,
    const String& nameSpace,
    const PropertySet& propertySet,
    bool keysOnly,
    const MI_Filter* filter)
{
    SCX_PEX_BEGIN
    {
        // Global lock for MemoryProvider class
        SCXCoreLib::SCXThreadLock lock(SCXCoreLib::ThreadLockHandleGet(L"SCXCore::MemoryProvider::Lock"));

        // Prepare MemoryStatisticalInformation Enumeration
        SCXCoreLib::SCXHandle<SCXSystemLib::MemoryEnumeration> memEnum = SCXCore::g_MemoryProvider.GetMemoryEnumeration();

        if ( !keysOnly )
        {
            memEnum->Update();
        }

        // There should be only one instance.
        SCXCoreLib::SCXHandle<SCXSystemLib::MemoryInstance> meminst = memEnum->GetTotalInstance();
        if (meminst != 0)
        {
            SCX_MemoryStatisticalInformation_Class inst;
            EnumerateOneInstance(context, inst, keysOnly, meminst);
        }

        context.Post(MI_RESULT_OK);
    }
    SCX_PEX_END( L"SCX_MemoryStatisticalInformation_Class_Provider::EnumerateInstances",
                       SCXCore::g_MemoryProvider.GetLogHandle() );
}

void SCX_MemoryStatisticalInformation_Class_Provider::GetInstance(
    Context& context,
    const String& nameSpace,
    const SCX_MemoryStatisticalInformation_Class& instanceName,
    const PropertySet& propertySet)
{
    SCX_PEX_BEGIN
    {
        // Global lock for MemoryProvider class
        SCXCoreLib::SCXThreadLock lock(SCXCoreLib::ThreadLockHandleGet(L"SCXCore::MemoryProvider::Lock"));

        if ( !instanceName.Name_exists() )
        {
            context.Post(MI_RESULT_INVALID_PARAMETER);
            return;
        }
        
        if ( strcmp("Memory", instanceName.Name_value().Str()) )
        {
            context.Post(MI_RESULT_NOT_FOUND);
            return;
        }

        SCXCoreLib::SCXHandle<SCXSystemLib::MemoryEnumeration> memEnum = SCXCore::g_MemoryProvider.GetMemoryEnumeration();
        memEnum->Update();

        // There should be only one instance.
        SCXCoreLib::SCXHandle<SCXSystemLib::MemoryInstance> meminst = memEnum->GetTotalInstance();
        if ( meminst == NULL )
        {
            context.Post(MI_RESULT_FAILED);
            return;
        }

        SCX_MemoryStatisticalInformation_Class inst;
        EnumerateOneInstance(context, inst, false, meminst);
        context.Post(MI_RESULT_OK);
    }
    SCX_PEX_END( L"SCX_MemoryStatisticalInformation_Class_Provider::GetInstance",
                      SCXCore::g_MemoryProvider.GetLogHandle() );
}

void SCX_MemoryStatisticalInformation_Class_Provider::CreateInstance(
    Context& context,
    const String& nameSpace,
    const SCX_MemoryStatisticalInformation_Class& newInstance)
{
    context.Post(MI_RESULT_NOT_SUPPORTED);
}

void SCX_MemoryStatisticalInformation_Class_Provider::ModifyInstance(
    Context& context,
    const String& nameSpace,
    const SCX_MemoryStatisticalInformation_Class& modifiedInstance,
    const PropertySet& propertySet)
{
    context.Post(MI_RESULT_NOT_SUPPORTED);
}

void SCX_MemoryStatisticalInformation_Class_Provider::DeleteInstance(
    Context& context,
    const String& nameSpace,
    const SCX_MemoryStatisticalInformation_Class& instanceName)
{
    context.Post(MI_RESULT_NOT_SUPPORTED);
}


MI_END_NAMESPACE
