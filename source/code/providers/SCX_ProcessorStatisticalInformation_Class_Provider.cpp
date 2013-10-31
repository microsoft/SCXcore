/*--------------------------------------------------------------------------------
    Copyright (c) Microsoft Corporation. All rights reserved. See license.txt for license information.
*/
/**
    \file        SCX_ProcessorStatisticalInformation_Class_Provider.cpp

    \brief       Provider support using OMI framework.
    
    \date        03-22-2013 17:48:44
*/
/*----------------------------------------------------------------------------*/

/* @migen@ */
#include <MI.h>
#include "SCX_ProcessorStatisticalInformation_Class_Provider.h"

#include <scxcorelib/scxcmn.h>
#include <scxcorelib/scxlog.h>
#include <scxcorelib/stringaid.h>
#include <scxsystemlib/cpuenumeration.h>

#include "support/startuplog.h"
#include "support/scxcimutils.h"

using namespace SCXSystemLib;
using namespace SCXCoreLib;

namespace SCXCore
{
    class CPUProvider
    {
    public:
        virtual ~CPUProvider() { };
        void Load()
        {
            if ( 1 == ++ms_loadCount )
            {
                m_log = SCXLogHandleFactory::GetLogHandle(L"scx.core.providers.cpuprovider");
                LogStartup();
                SCX_LOGTRACE(m_log, L"CPUProvider::Load()");

                m_cpusEnum = new CPUEnumeration();
                m_cpusEnum->Init();
            }
        }
        
        void Unload()
        {
            SCX_LOGTRACE(m_log, L"CPUProvider::Unload()");
            if (0 == --ms_loadCount)
            {
                if (m_cpusEnum != NULL)
                {
                    m_cpusEnum->CleanUp();
                    m_cpusEnum == NULL;
                }
            }
        }

        SCXCoreLib::SCXHandle<SCXSystemLib::CPUEnumeration> GetEnumCPUs() const 
        {
            return m_cpusEnum;
        }

        SCXLogHandle& GetLogHandle() { return m_log; }

    private:
        //! PAL implementation retrieving CPU information for local host
        SCXCoreLib::SCXHandle<SCXSystemLib::CPUEnumeration> m_cpusEnum;
        SCXCoreLib::SCXLogHandle m_log;
        static int ms_loadCount;
    };
    SCXCore::CPUProvider g_CPUProvider;
    int SCXCore::CPUProvider::ms_loadCount = 0;

}

MI_BEGIN_NAMESPACE

static void EnumerateOneInstance(
    Context& context,
    SCX_ProcessorStatisticalInformation_Class& inst,
    bool keysOnly,
    SCXHandle<SCXSystemLib::CPUInstance> cpuinst)
{
    // Populate the key values
    std::wstring name = cpuinst->GetProcName();
    inst.Name_value(StrToMultibyte(name).c_str());

    if (!keysOnly)
    {
        inst.Caption_value("Processor information");
        inst.Description_value("CPU usage statistics");
     
        scxulong data;

        inst.IsAggregate_value(cpuinst->IsTotal());

        if (cpuinst->GetProcessorTime(data))
        {
            inst.PercentProcessorTime_value(static_cast<unsigned char> (data));
        }

        if (cpuinst->GetIdleTime(data))
        {
            inst.PercentIdleTime_value(static_cast<unsigned char> (data));
        }

        if (cpuinst->GetUserTime(data))
        {
            inst.PercentUserTime_value(static_cast<unsigned char> (data));
        }

        if (cpuinst->GetNiceTime(data))
        {
            inst.PercentNiceTime_value(static_cast<unsigned char> (data));
        }

        if (cpuinst->GetPrivilegedTime(data))
        {
            inst.PercentPrivilegedTime_value(static_cast<unsigned char> (data));
        }

        if (cpuinst->GetIowaitTime(data))
        {
            inst.PercentIOWaitTime_value(static_cast<unsigned char> (data));
        }

        if (cpuinst->GetInterruptTime(data))
        {
            inst.PercentInterruptTime_value(static_cast<unsigned char> (data));
        }

        if (cpuinst->GetDpcTime(data))
        {
            inst.PercentDPCTime_value(static_cast<unsigned char> (data));
        }
    }
    context.Post(inst);
}

SCX_ProcessorStatisticalInformation_Class_Provider::SCX_ProcessorStatisticalInformation_Class_Provider(
    Module* module) :
    m_Module(module)
{
}

SCX_ProcessorStatisticalInformation_Class_Provider::~SCX_ProcessorStatisticalInformation_Class_Provider()
{
}

void SCX_ProcessorStatisticalInformation_Class_Provider::Load(
        Context& context)
{
    SCX_PEX_BEGIN
    {
        // Global lock for CPUProvider class
        SCXCoreLib::SCXThreadLock lock(SCXCoreLib::ThreadLockHandleGet(L"SCXCore::CPUProvider::Lock"));
        SCXCore::g_CPUProvider.Load();

        // Notify that we don't wish to unload
        MI_Result r = context.RefuseUnload();
        if ( MI_RESULT_OK != r )
        {
            SCX_LOGWARNING(SCXCore::g_CPUProvider.GetLogHandle(),
                SCXCoreLib::StrAppend(L"SCX_ProcessorStatisticalInformation_Class_Provider::Load() refuses to not unload, error = ", r));
        }

        context.Post(MI_RESULT_OK); 
    }
    SCX_PEX_END( L"SCX_ProcessorStatisticalInformation_Class_Provider::Load", SCXCore::g_CPUProvider.GetLogHandle() );
}

void SCX_ProcessorStatisticalInformation_Class_Provider::Unload(
        Context& context)
{
    SCX_PEX_BEGIN
    {
        // Global lock for CPUProvider class
        SCXCoreLib::SCXThreadLock lock(SCXCoreLib::ThreadLockHandleGet(L"SCXCore::CPUProvider::Lock"));
        SCXCore::g_CPUProvider.Unload();
        context.Post(MI_RESULT_OK);
    }
    SCX_PEX_END( L"SCX_ProcessorStatisticalInformation_Class_Provider:::Unload", SCXCore::g_CPUProvider.GetLogHandle() );
}

void SCX_ProcessorStatisticalInformation_Class_Provider::EnumerateInstances(
    Context& context,
    const String& nameSpace,
    const PropertySet& propertySet,
    bool keysOnly,
    const MI_Filter* filter)
{
    SCX_PEX_BEGIN
    {
        // Global lock for CPUProvider class
        SCXCoreLib::SCXThreadLock lock(SCXCoreLib::ThreadLockHandleGet(L"SCXCore::CPUProvider::Lock"));

        // Prepare ProcessorStatisticalInformation Enumeration
        // (Note: Only do full update if we're not enumerating keys)
        SCXHandle<SCXSystemLib::CPUEnumeration> cpuEnum = SCXCore::g_CPUProvider.GetEnumCPUs();
        cpuEnum->Update(!keysOnly);

        for(size_t i = 0; i < cpuEnum->Size(); i++)
        {
            SCX_ProcessorStatisticalInformation_Class inst;
            SCXHandle<SCXSystemLib::CPUInstance> cpuInst = cpuEnum->GetInstance(i);
            EnumerateOneInstance(context, inst, keysOnly, cpuInst);
        }

        // Enumerate Total instance
        SCXHandle<SCXSystemLib::CPUInstance> totalInst = cpuEnum->GetTotalInstance();
        if (totalInst != NULL)
        {
            // There will always be one total instance
            SCX_ProcessorStatisticalInformation_Class inst;
            EnumerateOneInstance(context, inst, keysOnly, totalInst);
        }

        context.Post(MI_RESULT_OK);
    }
    SCX_PEX_END( L"SCX_ProcessorStatisticalInformation_Class_Provider::EnumerateInstances", 
                     SCXCore::g_CPUProvider.GetLogHandle() );
}

void SCX_ProcessorStatisticalInformation_Class_Provider::GetInstance(
    Context& context,
    const String& nameSpace,
    const SCX_ProcessorStatisticalInformation_Class& instanceName,
    const PropertySet& propertySet)
{
    SCX_PEX_BEGIN
    {
        // Global lock for CPUProvider class
        SCXCoreLib::SCXThreadLock lock(SCXCoreLib::ThreadLockHandleGet(L"SCXCore::CPUProvider::Lock"));

        SCXHandle<SCXSystemLib::CPUEnumeration> cpuEnum = SCXCore::g_CPUProvider.GetEnumCPUs();
        cpuEnum->Update(true);

        const std::string name = instanceName.Name_value().Str();

        if (name.size() == 0)
        {
            context.Post(MI_RESULT_INVALID_PARAMETER);
            return;
        }

        bool instFound = false;
        SCXHandle<SCXSystemLib::CPUInstance> cpuInst;
        for(size_t i=0; i<cpuEnum->Size(); i++)
        {
            cpuInst = cpuEnum->GetInstance(i);
            // Compare key values of input args and the current instance
            if (cpuInst->GetProcName() == StrFromUTF8(name))
            {
                // Match
                instFound = true;
                break;
            }
        }

        if (instFound == false)
        {
            // As last resort, check if we the request is for the _Total instance
            if (cpuEnum->GetTotalInstance() != NULL)
            {
                cpuInst = cpuEnum->GetTotalInstance();
                if (cpuInst->GetProcName() == StrFromUTF8(name))
                {
                    instFound = true;
                }
            }

            if (instFound == false)
            {
                context.Post(MI_RESULT_NOT_FOUND);
                return;
            }
        }

        SCX_ProcessorStatisticalInformation_Class inst;
        EnumerateOneInstance(context, inst, false, cpuInst);
        context.Post(MI_RESULT_OK);
    }
    SCX_PEX_END( L"SCX_ProcessorStatisticalInformation_Class_Provider::GetInstance",
                    SCXCore::g_CPUProvider.GetLogHandle() );
}

void SCX_ProcessorStatisticalInformation_Class_Provider::CreateInstance(
    Context& context,
    const String& nameSpace,
    const SCX_ProcessorStatisticalInformation_Class& newInstance)
{
    context.Post(MI_RESULT_NOT_SUPPORTED);
}

void SCX_ProcessorStatisticalInformation_Class_Provider::ModifyInstance(
    Context& context,
    const String& nameSpace,
    const SCX_ProcessorStatisticalInformation_Class& modifiedInstance,
    const PropertySet& propertySet)
{
    context.Post(MI_RESULT_NOT_SUPPORTED);
}

void SCX_ProcessorStatisticalInformation_Class_Provider::DeleteInstance(
    Context& context,
    const String& nameSpace,
    const SCX_ProcessorStatisticalInformation_Class& instanceName)
{
    context.Post(MI_RESULT_NOT_SUPPORTED);
}


MI_END_NAMESPACE
