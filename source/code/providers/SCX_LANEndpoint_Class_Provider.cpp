/*--------------------------------------------------------------------------------
    Copyright (c) Microsoft Corporation. All rights reserved. See license.txt for license information.
*/
/**
    \file        SCX_LANEndpoint_Class_Provider.cpp

    \brief       Provider support using OMI framework.
    
    \date        03-14-2013 11:09:45
*/
/*----------------------------------------------------------------------------*/

/* @migen@ */
#include <MI.h>
#include "SCX_LANEndpoint_Class_Provider.h"
#include "SCX_LANEndpoint.h"

#include <scxcorelib/scxcmn.h>
#include <scxcorelib/stringaid.h>
#include <scxcorelib/scxthreadlock.h>
#include <scxcorelib/scxnameresolver.h>
#include <scxsystemlib/networkinterfaceenumeration.h>
#include "support/networkprovider.h"
#include "support/scxcimutils.h"
#include <sstream>

using namespace SCXSystemLib;
using namespace SCXCoreLib;
using namespace SCXCore;

MI_BEGIN_NAMESPACE

static void EnumerateOneInstance(Context& context,
                          SCX_LANEndpoint_Class& inst, bool keysOnly,
                          SCXCoreLib::SCXHandle<SCXSystemLib::NetworkInterfaceInstance> intf)
{
    // Add the key properperties first.
    inst.CreationClassName_value("SCX_LANEndpoint");
    inst.Name_value(StrToMultibyte(intf->GetName()).c_str());

    // Add the scoping systems keys.
    inst.SystemCreationClassName_value("SCX_ComputerSystem");
    SCXCoreLib::NameResolver mi;
    inst.SystemName_value(StrToMultibyte(mi.GetHostDomainname()).c_str());
    if (!keysOnly)
    {
        inst.InstanceID_value(StrToMultibyte(intf->GetName()).c_str());
        inst.Caption_value("LAN endpoint caption information");
        inst.Description_value("LAN Endpoint description information");
        
        inst.ElementName_value(StrToMultibyte(intf->GetName()).c_str());

        std::wstring text;
        if(intf->GetMACAddressRAW(text))
        {
            inst.MACAddress_value(StrToMultibyte(text).c_str());
            intf->GetMACAddress(text, '-', true);
            inst.FormattedMACAddress_value(StrToMultibyte(text).c_str());
        }
    }
    context.Post(inst);
}

SCX_LANEndpoint_Class_Provider::SCX_LANEndpoint_Class_Provider(
    Module* module) :
    m_Module(module)
{
}

SCX_LANEndpoint_Class_Provider::~SCX_LANEndpoint_Class_Provider()
{
}

void SCX_LANEndpoint_Class_Provider::Load(
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
                    SCXCoreLib::StrAppend(L"SCX_LANEndpoint_Class_Provider::Load() refuses to not unload, error = ", r));
        }

        context.Post(MI_RESULT_OK);
    }
    SCX_PEX_END( L"SCX_LANEndpoint_Class_Provider::Load", SCXCore::g_NetworkProvider.GetLogHandle() );
}

void SCX_LANEndpoint_Class_Provider::Unload(
        Context& context)
{
    SCX_PEX_BEGIN
    {
        // Global lock for NetworkProvider class
        SCXCoreLib::SCXThreadLock lock(SCXCoreLib::ThreadLockHandleGet(L"SCXCore::NetworkProvider::Lock"));
        SCXCore::g_NetworkProvider.Unload();

        context.Post(MI_RESULT_OK);
    }
    SCX_PEX_END( L"SCX_LANEndpoint_Class_Provider::Unload", SCXCore::g_NetworkProvider.GetLogHandle() );
}

void SCX_LANEndpoint_Class_Provider::EnumerateInstances(
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

        SCX_LOGTRACE(SCXCore::g_NetworkProvider.GetLogHandle(), L"LANEndpoint Provider EnumerateInstances");

        // Update network PAL instance. This is both update of number of interfaces and
        // current statistics for each interfaces.
        SCXHandle<SCXCore::NetworkProviderDependencies> deps = SCXCore::g_NetworkProvider.getDependencies();
        deps->UpdateIntf(false);

        SCX_LOGTRACE(SCXCore::g_NetworkProvider.GetLogHandle(), StrAppend(L"Number of interfaces = ", deps->IntfCount()));

        for(size_t i = 0; i < deps->IntfCount(); i++)
        {
            SCXCoreLib::SCXHandle<SCXSystemLib::NetworkInterfaceInstance> intf = deps->GetIntf(i);
            SCX_LANEndpoint_Class inst;
            EnumerateOneInstance(context, inst, keysOnly, intf);
        }
        context.Post(MI_RESULT_OK);
    }
    SCX_PEX_END( L"SCX_LANEndpoint_Class_Provider::EnumerateInstances", SCXCore::g_NetworkProvider.GetLogHandle() );

}

void SCX_LANEndpoint_Class_Provider::GetInstance(
    Context& context,
    const String& nameSpace,
    const SCX_LANEndpoint_Class& instanceName,
    const PropertySet& propertySet)
{
    SCX_PEX_BEGIN
    {
        // Global lock for NetworkProvider class
        SCXCoreLib::SCXThreadLock lock(SCXCoreLib::ThreadLockHandleGet(L"SCXCore::NetworkProvider::Lock"));

        // We have 4-part key:
        //   [Key] Name=eth0
        //   [Key] SystemCreationClassName=SCX_ComputerSystem
        //   [Key] SystemName=jeffcof64-rhel6-01.scx.com
        //   [Key] CreationClassName=SCX_IPProtocolEndpoint

        if (!instanceName.Name_exists() || !instanceName.SystemCreationClassName_exists() ||
            !instanceName.SystemName_exists() || !instanceName.CreationClassName_exists())
        {
            context.Post(MI_RESULT_INVALID_PARAMETER);
            return;
        }

        std::string csName;
        try {
            NameResolver mi;
            csName = StrToMultibyte(mi.GetHostDomainname()).c_str();
        } catch (SCXException& e) {
            SCX_LOGWARNING(SCXCore::g_NetworkProvider.GetLogHandle(), StrAppend(
                               StrAppend(L"Can't read host/domainname because ", e.What()),
                               e.Where()));
        }

        // Now compare (case insensitive for the class names, case sensitive for the others)
        if ( 0 != strcasecmp("SCX_ComputerSystem", instanceName.SystemCreationClassName_value().Str())
             || 0 != strcmp(csName.c_str(), instanceName.SystemName_value().Str())
             || 0 != strcasecmp("SCX_LANEndpoint", instanceName.CreationClassName_value().Str()))
        {
            context.Post(MI_RESULT_NOT_FOUND);
            return;
        }

        SCX_LOGTRACE(SCXCore::g_NetworkProvider.GetLogHandle(), L"LANEndpoint Provider GetInstance");

        // Update network PAL instance. This is both update of number of interfaces and
        // current statistics for each interfaces.
        SCXHandle<SCXCore::NetworkProviderDependencies> deps = SCXCore::g_NetworkProvider.getDependencies();
        deps->UpdateIntf(false);

        const std::string interfaceId = instanceName.Name_value().Str();

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
        SCX_LANEndpoint_Class inst;
        EnumerateOneInstance(context, inst, false, intf);

        context.Post(MI_RESULT_OK);
    }
    SCX_PEX_END( L"SCX_LANEndpoint_Class_Provider::GetInstance", SCXCore::g_NetworkProvider.GetLogHandle() );
}

void SCX_LANEndpoint_Class_Provider::CreateInstance(
    Context& context,
    const String& nameSpace,
    const SCX_LANEndpoint_Class& newInstance)
{
    context.Post(MI_RESULT_NOT_SUPPORTED);
}

void SCX_LANEndpoint_Class_Provider::ModifyInstance(
    Context& context,
    const String& nameSpace,
    const SCX_LANEndpoint_Class& modifiedInstance,
    const PropertySet& propertySet)
{
    context.Post(MI_RESULT_NOT_SUPPORTED);
}

void SCX_LANEndpoint_Class_Provider::DeleteInstance(
    Context& context,
    const String& nameSpace,
    const SCX_LANEndpoint_Class& instanceName)
{
    context.Post(MI_RESULT_NOT_SUPPORTED);
}

void SCX_LANEndpoint_Class_Provider::Invoke_RequestStateChange(
    Context& context,
    const String& nameSpace,
    const SCX_LANEndpoint_Class& instanceName,
    const SCX_LANEndpoint_RequestStateChange_Class& in)
{
    context.Post(MI_RESULT_NOT_SUPPORTED);
}


MI_END_NAMESPACE
