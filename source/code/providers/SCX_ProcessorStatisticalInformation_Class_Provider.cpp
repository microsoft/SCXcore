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
#include <scxcorelib/scxregex.h>
#include <scxcorelib/scxpatternfinder.h>
#include <scxsystemlib/cpuenumeration.h>

#include "support/startuplog.h"
#include "support/scxcimutils.h"

# define QLENGTH 1000

using namespace SCXSystemLib;
using namespace SCXCoreLib;

namespace
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
                SCXCore::LogStartup();
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
    CPUProvider g_CPUProvider;
    int CPUProvider::ms_loadCount = 0;

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
        g_CPUProvider.Load();

        // Notify that we don't wish to unload
        MI_Result r = context.RefuseUnload();
        if ( MI_RESULT_OK != r )
        {
            SCX_LOGWARNING(g_CPUProvider.GetLogHandle(),
                SCXCoreLib::StrAppend(L"SCX_ProcessorStatisticalInformation_Class_Provider::Load() refuses to not unload, error = ", r));
        }

        context.Post(MI_RESULT_OK);
    }
    SCX_PEX_END( L"SCX_ProcessorStatisticalInformation_Class_Provider::Load", g_CPUProvider.GetLogHandle() );
}

void SCX_ProcessorStatisticalInformation_Class_Provider::Unload(
        Context& context)
{
    SCX_PEX_BEGIN
    {
        // Global lock for CPUProvider class
        SCXCoreLib::SCXThreadLock lock(SCXCoreLib::ThreadLockHandleGet(L"CPUProvider::Lock"));
        g_CPUProvider.Unload();
        context.Post(MI_RESULT_OK);
    }
    SCX_PEX_END( L"SCX_ProcessorStatisticalInformation_Class_Provider:::Unload", g_CPUProvider.GetLogHandle() );
}

void SCX_ProcessorStatisticalInformation_Class_Provider::EnumerateInstances(
    Context& context,
    const String& nameSpace,
    const PropertySet& propertySet,
    bool keysOnly,
    const MI_Filter* filter)
{
    SCXLogHandle& log = g_CPUProvider.GetLogHandle();
    SCX_LOGTRACE(log, L"ProcessorStat EnumerateInstances begin");

    SCX_PEX_BEGIN
    {
        // Global lock for CPUProvider class
        SCXCoreLib::SCXThreadLock lock(SCXCoreLib::ThreadLockHandleGet(L"CPUProvider::Lock"));
        wstring procName=L"";
        size_t instancePos=(size_t)-1;

        if(filter)
        {
            char* exprStr[QLENGTH]={'\0'};
            char* qtypeStr[QLENGTH]={'\0'};
            const MI_Char** expr=(const MI_Char**)&exprStr;
            const MI_Char** qtype=(const MI_Char**)&qtypeStr;

            MI_Filter_GetExpression(filter, qtype, expr);
            SCX_LOGTRACE(log, SCXCoreLib::StrAppend(L"ProcessorStat Provider Filter Set with Expression: ",*expr));

            std::wstring filterQuery(SCXCoreLib::StrFromUTF8(*expr));

            SCXCoreLib::SCXPatternFinder::SCXPatternCookie s_patternID = 0, id=0;
            SCXCoreLib::SCXPatternFinder::SCXPatternMatch param;
            std::wstring s_pattern(L"select * from SCX_ProcessorStatisticalInformation where Name=%name");

            SCXCoreLib::SCXPatternFinder patterenfinder;
            patterenfinder.RegisterPattern(s_patternID, s_pattern);

            bool status=patterenfinder.Match(filterQuery, id, param);

            if ( status && param.end() != param.find(L"name") && id == s_patternID )
            {
                procName=param.find(L"name")->second;
                SCX_LOGTRACE(log,  SCXCoreLib::StrAppend(L"ProcessorStat Provider Enum Requested for processor: ",procName));
            }
        }

        // Prepare ProcessorStatisticalInformation Enumeration
        // (Note: Only do full update if we're not enumerating keys)
        SCXHandle<SCXSystemLib::CPUEnumeration> cpuEnum = g_CPUProvider.GetEnumCPUs();

        procName!= L"" && procName!= L"_Total"?cpuEnum->UpdateSpecific(procName, &instancePos):cpuEnum->Update(!keysOnly);

        if (instancePos != (size_t)-1)
        {
            SCX_ProcessorStatisticalInformation_Class inst;
            SCXHandle<SCXSystemLib::CPUInstance> cpuInst = cpuEnum->GetInstance(instancePos);
            EnumerateOneInstance(context, inst, keysOnly, cpuInst);
        }
        else
        {
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
        }

        context.Post(MI_RESULT_OK);
    }
    SCX_PEX_END( L"SCX_ProcessorStatisticalInformation_Class_Provider::EnumerateInstances", log );

    SCX_LOGTRACE(log, L"ProcessorStat EnumerateInstances end");
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
        SCXCoreLib::SCXThreadLock lock(SCXCoreLib::ThreadLockHandleGet(L"CPUProvider::Lock"));

        SCXHandle<SCXSystemLib::CPUEnumeration> cpuEnum = g_CPUProvider.GetEnumCPUs();
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
                    g_CPUProvider.GetLogHandle() );
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
