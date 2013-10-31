/*--------------------------------------------------------------------------------
    Copyright (c) Microsoft Corporation. All rights reserved. See license.txt for license information.
*/
/**
    \file        SCX_Application_Server_Class_Provider.cpp

    \brief       Provider support using OMI framework.
    
    \date        03-22-2013 17:48:44
*/
/*----------------------------------------------------------------------------*/

/* @migen@ */
#include <MI.h>
#include <string>
#include <scxcorelib/scxcmn.h>
#include <scxcorelib/scxlog.h>
#include "support/appserver/appserverenumeration.h"
#include "support/appserver/appserverprovider.h"
#include "support/scxcimutils.h"
#include "support/startuplog.h"
#include "SCX_Application_Server_Class_Provider.h"

using namespace SCXSystemLib;
using namespace SCXCoreLib;

MI_BEGIN_NAMESPACE

static void EnumerateOneInstance(
    Context& context,
    SCX_Application_Server_Class& inst,
    bool keysOnly,
    SCXCoreLib::SCXHandle<SCXSystemLib::AppServerInstance> asinst)
{
    if (asinst == NULL)
    {
        throw SCXInvalidArgumentException(L"asinst", L"Not a AppServerInstance", SCXSRCLOCATION);
    }

    // Fill in the key
    inst.Name_value( StrToMultibyte(asinst->GetId()).c_str() );

    if ( !keysOnly )
    {
        inst.Caption_value( "SCX Application Server" );
        inst.Description_value( "Represents a JEE Application Server" );
        inst.HttpPort_value( StrToMultibyte(asinst->GetHttpPort()).c_str() );
        inst.HttpsPort_value( StrToMultibyte(asinst->GetHttpsPort()).c_str() );
        inst.Version_value( StrToMultibyte(asinst->GetVersion()).c_str() );
        inst.MajorVersion_value( StrToMultibyte(asinst->GetMajorVersion()).c_str() );
        inst.Port_value( StrToMultibyte(asinst->GetPort()).c_str() );
        inst.Protocol_value( StrToMultibyte(asinst->GetProtocol()).c_str() );
        inst.DiskPath_value( StrToMultibyte(asinst->GetDiskPath()).c_str() );
        inst.Type_value( StrToMultibyte(asinst->GetType()).c_str() );
        inst.IsDeepMonitored_value( asinst->GetIsDeepMonitored() );
        inst.IsRunning_value( asinst->GetIsRunning() );
        inst.Profile_value( StrToMultibyte(asinst->GetProfile()).c_str() );
        inst.Cell_value( StrToMultibyte(asinst->GetCell()).c_str() );
        inst.Node_value( StrToMultibyte(asinst->GetNode()).c_str() );
        inst.Server_value( StrToMultibyte(asinst->GetServer()).c_str() );
    }
}

SCX_Application_Server_Class_Provider::SCX_Application_Server_Class_Provider(
    Module* module) :
    m_Module(module)
{
}

SCX_Application_Server_Class_Provider::~SCX_Application_Server_Class_Provider()
{
}

void SCX_Application_Server_Class_Provider::Load(
        Context& context)
{
    SCX_PEX_BEGIN
    {
        SCXCoreLib::SCXThreadLock lock(SCXCoreLib::ThreadLockHandleGet(L"SCXCore::AppServerProvider::Lock"));
        SCXCore::g_AppServerProvider.Load();

        // Notify that we don't wish to unload
        MI_Result r = context.RefuseUnload();
        if ( MI_RESULT_OK != r )
        {
            SCX_LOGWARNING(SCXCore::g_AppServerProvider.GetLogHandle(),
                SCXCoreLib::StrAppend(L"SCX_Application_Server_Class_Provider::Load() refuses to not unload, error = ", r));
        }

        context.Post(MI_RESULT_OK);
    }
    SCX_PEX_END( L"SCX_Application_Server_Class_Provider::Load", SCXCore::g_AppServerProvider.GetLogHandle() );
}

void SCX_Application_Server_Class_Provider::Unload(
        Context& context)
{
    SCX_PEX_BEGIN
    {
        SCXCoreLib::SCXThreadLock lock(SCXCoreLib::ThreadLockHandleGet(L"SCXCore::AppServerProvider::Lock"));
        SCXCore::g_AppServerProvider.Unload();
        context.Post(MI_RESULT_OK);
    }
    SCX_PEX_END( L"SCX_Application_Server_Class_Provider::Unload", SCXCore::g_AppServerProvider.GetLogHandle() );
}

void SCX_Application_Server_Class_Provider::EnumerateInstances(
    Context& context,
    const String& nameSpace,
    const PropertySet& propertySet,
    bool keysOnly,
    const MI_Filter* filter)
{
    SCXLogHandle& log = SCXCore::g_AppServerProvider.GetLogHandle();

    SCX_PEX_BEGIN
    {
        SCXCoreLib::SCXThreadLock lock(SCXCoreLib::ThreadLockHandleGet(L"SCXCore::AppServerProvider::Lock"));
        SCXCoreLib::SCXHandle<SCXSystemLib::AppServerEnumeration> appServers = SCXCore::g_AppServerProvider.GetAppServers();

        // Update instances (doing full update if enumerating values - not just keys)
        appServers->Update( !keysOnly );

        SCX_LOGTRACE(log, StrAppend(L"Number of Application Servers = ", appServers->Size()));

        for (size_t i = 0; i < appServers->Size(); i++)
        {
            // For each appserver instance, add it to the collection of instances
            SCX_Application_Server_Class inst;
            EnumerateOneInstance( context, inst, keysOnly, appServers->GetInstance(i) );
            context.Post(inst);
        }
        context.Post(MI_RESULT_OK);
    }
    SCX_PEX_END( L"SCX_Application_Server_Class_Provider::EnumerateInstances", log );
}

void SCX_Application_Server_Class_Provider::GetInstance(
    Context& context,
    const String& nameSpace,
    const SCX_Application_Server_Class& instanceName,
    const PropertySet& propertySet)
{
    SCXLogHandle& log = SCXCore::g_AppServerProvider.GetLogHandle();

    SCX_PEX_BEGIN
    {
        if ( !instanceName.Name_exists() )
        {
            context.Post(MI_RESULT_INVALID_PARAMETER);
            return;
        }

        // Global lock for AppServerProvider class
        SCXCoreLib::SCXThreadLock lock(SCXCoreLib::ThreadLockHandleGet(L"SCXCore::AppServerProvider::Lock"));
        SCX_LOGTRACE(log, L"SCX_Application_Server_Class_Provider::GetInstance");

        SCXCoreLib::SCXHandle<SCXSystemLib::AppServerEnumeration> appServers = SCXCore::g_AppServerProvider.GetAppServers();

        // Refresh the collection (both keys and current data)
        appServers->Update();

        // See if we have the requested instance
        SCXCoreLib::SCXHandle<SCXSystemLib::AppServerInstance> appInst = appServers->GetInstance(StrFromMultibyte(instanceName.Name_value().Str()));

        if ( appInst == NULL )
        {
            context.Post(MI_RESULT_NOT_FOUND);
            return;
        }

        SCX_Application_Server_Class inst;
        EnumerateOneInstance( context, inst, false, appInst );
        context.Post(inst);
        context.Post(MI_RESULT_OK);
    }
    SCX_PEX_END( L"SCX_Application_Server_Class_Provider::GetInstances", log );
}

void SCX_Application_Server_Class_Provider::CreateInstance(
    Context& context,
    const String& nameSpace,
    const SCX_Application_Server_Class& newInstance)
{
    context.Post(MI_RESULT_NOT_SUPPORTED);
}

void SCX_Application_Server_Class_Provider::ModifyInstance(
    Context& context,
    const String& nameSpace,
    const SCX_Application_Server_Class& modifiedInstance,
    const PropertySet& propertySet)
{
    context.Post(MI_RESULT_NOT_SUPPORTED);
}

void SCX_Application_Server_Class_Provider::DeleteInstance(
    Context& context,
    const String& nameSpace,
    const SCX_Application_Server_Class& instanceName)
{
    context.Post(MI_RESULT_NOT_SUPPORTED);
}

void SCX_Application_Server_Class_Provider::Invoke_SetDeepMonitoring(
    Context& context,
    const String& nameSpace,
    const SCX_Application_Server_Class& instanceName,
    const SCX_Application_Server_SetDeepMonitoring_Class& in)
{
    SCXLogHandle& log = SCXCore::g_AppServerProvider.GetLogHandle();

    SCX_PEX_BEGIN
    {
        // Global lock for AppServerProvider class
        SCXCoreLib::SCXThreadLock lock(SCXCoreLib::ThreadLockHandleGet(L"SCXCore::AppServerProvider::Lock"));
        SCX_LOGTRACE(log, L"SCX_Application_Server_Class_Provider::Invoke_SetDeepMonitoring");

        // Get the arguments:
        //   id            : string
        //   deep          : boolean
        //   protocol      : string
        //
        // Validate that we have mandatory arguments
        SCX_Application_Server_SetDeepMonitoring_Class inst;
        if ( !in.id_exists() || !in.deep_exists() )
        {
            inst.MIReturn_value( false );
            context.Post(inst);
            context.Post(MI_RESULT_INVALID_PARAMETER);
            return;
        }

        std::wstring id = SCXCoreLib::StrFromMultibyte( in.id_value().Str() );
        bool deep = in.deep_value();

        // Treat the protocol parameter as optional and fall back to HTTP if not specified
        std::wstring protocol = L"HTTP";
        if ( in.protocol_exists() && strlen(in.protocol_value().Str()) > 0 )
            protocol = SCXCoreLib::StrFromMultibyte( in.protocol_value().Str() );

        SCX_LOGTRACE(log, SCXCoreLib::StrAppend(L"SCX_Application_Server_Class_Provider::Invoke_SetDeepMonitoring - id = ", id));
        SCX_LOGTRACE(log, SCXCoreLib::StrAppend(L"SCX_Application_Server_Class_Provider::Invoke_SetDeepMonitoring - deep = ", deep));
        SCX_LOGTRACE(log, SCXCoreLib::StrAppend(L"SCX_Application_Server_Class_Provider::Invoke_SetDeepMonitoring - protocol = ", protocol));

        SCXCoreLib::SCXHandle<SCXSystemLib::AppServerEnumeration> appServers = SCXCore::g_AppServerProvider.GetAppServers();
        appServers->Update(false);

        bool fDeepResult = false;
        SCXHandle<AppServerInstance> appInst = appServers->GetInstance(id);
        if (appInst != NULL)
        {
            appInst->SetIsDeepMonitored(deep, protocol);
            fDeepResult = true;
        }
        else
        {
            inst.MIReturn_value( fDeepResult );
            context.Post(inst);
            context.Post(MI_RESULT_NOT_FOUND);
            return;
        }
        
        inst.MIReturn_value( fDeepResult );
        context.Post(inst);
        context.Post(MI_RESULT_OK);
    }
    SCX_PEX_END( L"SCX_Application_Server_Class_Provider::Invoke_SetDeepMonitoring", log );
}


MI_END_NAMESPACE
