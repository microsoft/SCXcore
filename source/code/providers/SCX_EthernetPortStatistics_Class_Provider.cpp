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
    SCX_PEX_BEGIN
    {
        // Global lock for NetworkProvider class
        SCXCoreLib::SCXThreadLock lock(SCXCoreLib::ThreadLockHandleGet(L"SCXCore::NetworkProvider::Lock"));
    
        SCX_LOGTRACE(SCXCore::g_NetworkProvider.GetLogHandle(), L"EthernetPortStatistics Provider EnumerateInstances");

        // Update network PAL instance. This is both update of number of interfaces and
        // current statistics for each interfaces.
        SCXHandle<SCXCore::NetworkProviderDependencies> deps = SCXCore::g_NetworkProvider.getDependencies();
        deps->UpdateIntf(false);

        SCX_LOGTRACE(SCXCore::g_NetworkProvider.GetLogHandle(), StrAppend(L"Number of interfaces = ", deps->IntfCount()));

        for(size_t i = 0; i < deps->IntfCount(); i++)
        {
            SCXCoreLib::SCXHandle<SCXSystemLib::NetworkInterfaceInstance> intf = deps->GetIntf(i);
            SCX_EthernetPortStatistics_Class inst;
            EnumerateOneInstance(context, inst, keysOnly, intf);
        }

        context.Post(MI_RESULT_OK);
    }
    SCX_PEX_END( L"SCX_EthernetPortStatistics_Class_Provider::EnumerateInstances",
                 SCXCore::g_NetworkProvider.GetLogHandle() );

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
