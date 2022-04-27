/*--------------------------------------------------------------------------------
    Copyright (c) Microsoft Corporation. All rights reserved. See license.txt for license information.
*/
/**
    \file        SCX_EthernetPortStatistics_Class_Provider.cpp

    \brief       Provider support using OMI framework.
    
    \date        03-14-2013 11:09:45
*/
/*----------------------------------------------------------------------------*/

/* @migen@ */
#include <MI.h>
#include "SCX_EthernetPortStatistics_Class_Provider.h"
#include "SCX_EthernetPortStatistics.h"

#include <scxcorelib/scxcmn.h>
#include <scxcorelib/stringaid.h>
#include <scxcorelib/scxthreadlock.h>
#include <scxsystemlib/networkinterfaceenumeration.h>
#include "support/networkprovider.h"
#include "support/scxcimutils.h"
#include <sstream>
#include <scxcorelib/scxregex.h>
#include <scxcorelib/scxpatternfinder.h>

# define QLENGTH 1000

using namespace SCXSystemLib;
using namespace SCXCoreLib;
using namespace SCXCore;

MI_BEGIN_NAMESPACE

static void EnumerateOneInstance(Context& context,
                          SCX_EthernetPortStatistics_Class& inst, bool keysOnly,
                          SCXCoreLib::SCXHandle<SCXSystemLib::NetworkInterfaceInstance> intf)
{
    // Add the key properperties first.
    inst.InstanceID_value(StrToMultibyte(intf->GetName()).c_str());

    if (!keysOnly)
    {
        inst.Caption_value("Ethernet port information");
        inst.Description_value("Statistics on transfer performance for a port");

        scxulong ulong = 0;
        scxulong bytesReceived = intf->GetBytesReceived(ulong) ? ulong : 0;
        inst.BytesReceived_value(bytesReceived);

        scxulong bytesTransmitted = intf->GetBytesSent(ulong) ? ulong : 0;
        inst.BytesTransmitted_value(bytesTransmitted);

        inst.BytesTotal_value(bytesReceived + bytesTransmitted);

        inst.PacketsReceived_value(intf->GetPacketsReceived(ulong) ? ulong : 0);
        inst.PacketsTransmitted_value(intf->GetPacketsSent(ulong) ? ulong : 0);

        inst.TotalTxErrors_value(intf->GetErrorsSending(ulong) ? ulong : 0);

        inst.TotalRxErrors_value(intf->GetErrorsReceiving(ulong) ? ulong : 0);

        inst.TotalCollisions_value(intf->GetCollisions(ulong) ? ulong : 0);
    }
    context.Post(inst);
}

SCX_EthernetPortStatistics_Class_Provider::SCX_EthernetPortStatistics_Class_Provider(
    Module* module) :
    m_Module(module)
{
}

SCX_EthernetPortStatistics_Class_Provider::~SCX_EthernetPortStatistics_Class_Provider()
{
}

void SCX_EthernetPortStatistics_Class_Provider::Load(
        Context& context)
{
    SCX_PEX_BEGIN
    {
        // Global lock for NetworkProvider class
        SCXCoreLib::SCXThreadLock lock(SCXCoreLib::ThreadLockHandleGet(L"SCXCore::NetworkProvider::Lock"));
        SCXCore::g_NetworkProvider.Load();

        // Notify that we don't wish to unload
        MI_Result r = context.RefuseUnload();
        if ( MI_RESULT_OK != r )
        {
            SCX_LOGWARNING(SCXCore::g_NetworkProvider.GetLogHandle(),
                    SCXCoreLib::StrAppend(L"SCX_EthernetPortStatistics_Class_Provider::Load() refuses to not unload, error = ", r));
        }

        context.Post(MI_RESULT_OK);
    }
    SCX_PEX_END( L"SCX_EthernetPortStatistics_Class_Provider::Load", SCXCore::g_NetworkProvider.GetLogHandle() );
}

void SCX_EthernetPortStatistics_Class_Provider::Unload(
        Context& context)
{
    SCX_PEX_BEGIN
    {
        // Global lock for NetworkProvider class
        SCXCoreLib::SCXThreadLock lock(SCXCoreLib::ThreadLockHandleGet(L"SCXCore::NetworkProvider::Lock"));
        SCXCore::g_NetworkProvider.Unload();

        context.Post(MI_RESULT_OK);
    }
    SCX_PEX_END( L"SCX_EthernetPortStatistics_Class_Provider::Unload", SCXCore::g_NetworkProvider.GetLogHandle() );
}

void SCX_EthernetPortStatistics_Class_Provider::EnumerateInstances(
    Context& context,
    const String& nameSpace,
    const PropertySet& propertySet,
    bool keysOnly,
    const MI_Filter* filter)
{
    SCXLogHandle& log = SCXCore::g_NetworkProvider.GetLogHandle();
    SCX_LOGTRACE(log, L"EthernetPortStatistics Provider EnumerateInstances begin");

    SCX_PEX_BEGIN
    {
        // Global lock for NetworkProvider class
        SCXCoreLib::SCXThreadLock lock(SCXCoreLib::ThreadLockHandleGet(L"SCXCore::NetworkProvider::Lock"));
    
        // Update network PAL instance. This is both update of number of interfaces and
        // current statistics for each interfaces.
        SCXHandle<SCXCore::NetworkProviderDependencies> deps = SCXCore::g_NetworkProvider.getDependencies();
        wstring interfaceString=L"";
        size_t instancePos=(size_t)-1;

        if(filter) {
            //char* exprStr[QLENGTH]={'\0'};
	        char ** exprStr = new char *[QLENGTH]();
            //char* qtypeStr[QLENGTH]={'\0'};
	        char ** qtypeStr = new char *[QLENGTH]();

            const MI_Char** expr=(const MI_Char**)&exprStr;
            const MI_Char** qtype=(const MI_Char**)&qtypeStr;

            MI_Filter_GetExpression(filter, qtype, expr);
            SCX_LOGTRACE(log, SCXCoreLib::StrAppend(L"EthernetPortStatistics Provider Filter Set with Expression: ",*expr));

            std::wstring filterQuery(SCXCoreLib::StrFromUTF8(*expr));

            SCXCoreLib::SCXPatternFinder::SCXPatternCookie s_patternID = 0, id=0;
            SCXCoreLib::SCXPatternFinder::SCXPatternMatch param;
            std::wstring s_pattern(L"select * from SCX_EthernetPortStatistics where InstanceID=%name");

            SCXCoreLib::SCXPatternFinder patterenfinder;
            patterenfinder.RegisterPattern(s_patternID, s_pattern);

            bool status=patterenfinder.Match(filterQuery, id, param);


            if ( status && param.end() != param.find(L"name") && id == s_patternID )
            {
                interfaceString=param.find(L"name")->second;
                SCX_LOGTRACE(log,  SCXCoreLib::StrAppend(L"EthernetPortStatistics Provider Enum Requested for Interface: ",interfaceString));
            }
        }

        deps->UpdateIntf(false, interfaceString, interfaceString==L""?NULL:&instancePos);

        if (interfaceString == L""){
            SCX_LOGTRACE(log, StrAppend(L"Number of interfaces = ", deps->IntfCount()));
            for(size_t i = 0; i < deps->IntfCount(); i++)
            {
                SCXCoreLib::SCXHandle<SCXSystemLib::NetworkInterfaceInstance> intf = deps->GetIntf(i);
                SCX_EthernetPortStatistics_Class inst;
                EnumerateOneInstance(context, inst, keysOnly, intf);
            }
        }
        else if (instancePos != (size_t)-1){
            SCXCoreLib::SCXHandle<SCXSystemLib::NetworkInterfaceInstance> intf = deps->GetIntf(instancePos);
            SCX_EthernetPortStatistics_Class inst;
            EnumerateOneInstance(context, inst, keysOnly, intf);
        }

        context.Post(MI_RESULT_OK);
    }
    SCX_PEX_END( L"SCX_EthernetPortStatistics_Class_Provider::EnumerateInstances", log );

    SCX_LOGTRACE(log, L"EthernetPortStatistics Provider EnumerateInstances end");
}

void SCX_EthernetPortStatistics_Class_Provider::GetInstance(
    Context& context,
    const String& nameSpace,
    const SCX_EthernetPortStatistics_Class& instanceName,
    const PropertySet& propertySet)
{
    SCX_PEX_BEGIN
    {
        // Global lock for NetworkProvider class
        SCXCoreLib::SCXThreadLock lock(SCXCoreLib::ThreadLockHandleGet(L"SCXCore::NetworkProvider::Lock"));

        SCX_LOGTRACE(SCXCore::g_NetworkProvider.GetLogHandle(), L"EthernetPortStatistics Provider GetInstances");

        // Update network PAL instance. This is both update of number of interfaces and
        // current statistics for each interfaces.
        SCXHandle<SCXCore::NetworkProviderDependencies> deps = SCXCore::g_NetworkProvider.getDependencies();
        deps->UpdateIntf(false);

        const std::string interfaceId = instanceName.InstanceID_value().Str();

        if (interfaceId.size() == 0)
        {
            context.Post(MI_RESULT_INVALID_PARAMETER);
            return;
        }

        SCXCoreLib::SCXHandle<SCXSystemLib::NetworkInterfaceInstance> intf = deps->GetIntf(StrFromUTF8(interfaceId));

        if (intf == NULL)
        {
            // Didn't find a match.
            context.Post(MI_RESULT_NOT_FOUND);
            return;
        }

        // Found a Match. Enumerate the properties for the instance.
        SCX_EthernetPortStatistics_Class inst;
        EnumerateOneInstance(context, inst, false, intf);

        context.Post(MI_RESULT_OK);
    }
    SCX_PEX_END( L"SCX_EthernetPortStatistics_Class_Provider::GetInstance", SCXCore::g_NetworkProvider.GetLogHandle() );
}

void SCX_EthernetPortStatistics_Class_Provider::CreateInstance(
    Context& context,
    const String& nameSpace,
    const SCX_EthernetPortStatistics_Class& newInstance)
{
    context.Post(MI_RESULT_NOT_SUPPORTED);
}

void SCX_EthernetPortStatistics_Class_Provider::ModifyInstance(
    Context& context,
    const String& nameSpace,
    const SCX_EthernetPortStatistics_Class& modifiedInstance,
    const PropertySet& propertySet)
{
    context.Post(MI_RESULT_NOT_SUPPORTED);
}

void SCX_EthernetPortStatistics_Class_Provider::DeleteInstance(
    Context& context,
    const String& nameSpace,
    const SCX_EthernetPortStatistics_Class& instanceName)
{
    context.Post(MI_RESULT_NOT_SUPPORTED);
}

void SCX_EthernetPortStatistics_Class_Provider::Invoke_ResetSelectedStats(
    Context& context,
    const String& nameSpace,
    const SCX_EthernetPortStatistics_Class& instanceName,
    const SCX_EthernetPortStatistics_ResetSelectedStats_Class& in)
{
    context.Post(MI_RESULT_NOT_SUPPORTED);
}


MI_END_NAMESPACE
