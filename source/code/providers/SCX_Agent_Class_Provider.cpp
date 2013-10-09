/*--------------------------------------------------------------------------------
    Copyright (c) Microsoft Corporation.  All rights reserved.
*/
/**
    \file        SCX_Agent_Class_Provider.cpp

    \brief       Provider support using OMI framework.
    
    \date        03-13-2013 13:27:47
*/
/*----------------------------------------------------------------------------*/

/* @migen@ */
#include <MI.h>
#include "SCX_Agent_Class_Provider.h"

#include <scxcorelib/scxcmn.h>

#include <scxcorelib/scxnameresolver.h>
#include <scxcorelib/stringaid.h>
#include <scxsystemlib/cpuenumeration.h>
#include <scxsystemlib/scxostypeinfo.h>
#include <scxsystemlib/scxsysteminfo.h>

#include "support/metaprovider.h"
#include "support/scxcimutils.h"

#include "buildversion.h"

#include <errno.h>
#include <sstream>
#include <iostream>


using namespace SCXCoreLib;
using namespace SCXSystemLib;
using namespace std;


MI_BEGIN_NAMESPACE

static void EnumerateOneInstance(
    Context& context,
    SCX_Agent_Class& inst,
    bool keysOnly)
{
    // Fill in the key
    inst.Name_value("scx");

    if ( !keysOnly )
    {
        inst.Caption_value("SCX Agent meta-information");

        //
        // Populate properties regarding the agent's build number
        // 
        stringstream ss;

        ss << SCX_BUILDVERSION_MAJOR << "." << SCX_BUILDVERSION_MINOR << "." << SCX_BUILDVERSION_PATCH << "-" << SCX_BUILDVERSION_BUILDNR;

        inst.VersionString_value( ss.str().c_str() );
        inst.MajorVersion_value( static_cast<unsigned short>(SCX_BUILDVERSION_MAJOR) );
        inst.MinorVersion_value( static_cast<unsigned short>(SCX_BUILDVERSION_MINOR) );
        inst.RevisionNumber_value( static_cast<unsigned short>(SCX_BUILDVERSION_PATCH) );
        inst.BuildNumber_value( static_cast<unsigned short>(SCX_BUILDVERSION_BUILDNR) );

        string strDesc;
        strDesc = StrToMultibyte(StrAppend(StrAppend(SCX_BUILDVERSION_STATUS, L" - "), SCX_BUILDVERSION_DATE));
        inst.Description_value( strDesc.c_str() );

        string installVersion;
        MI_Datetime installTime;
        if ( SCXCore::g_MetaProvider.GetInstallInfoData(installVersion, installTime) )
        {
            inst.KitVersionString_value( installVersion.c_str() );
            // provide standard property as "date-time"
            inst.InstallDate_value( installTime );
        }

        // 
        // Populate the build date - the value is looked up by constructor
        //
        string buildTime;
        if ( SCXCore::g_MetaProvider.GetBuildTime(buildTime) )
        {
            inst.BuildDate_value( buildTime.c_str() );
        }

        // 
        // Populate the hostname date - the value is cached internally in the MachnieInfo code.
        //
        try {
            NameResolver mi;
            inst.Hostname_value( StrToMultibyte(mi.GetHostDomainname()).c_str() );
        } catch (SCXException& e) {
            SCX_LOGWARNING( SCXCore::g_MetaProvider.GetLogHandle(), StrAppend(
                                StrAppend(L"Can't read host/domainname because ", e.What()),
                                e.Where()));
        }


        // 
        // Populate name, version and alias for the OS 
        //

        // Keep an instance of class with static information about OS type
        static SCXSystemLib::SCXOSTypeInfo  osTypeInfo;
        inst.OSName_value( StrToMultibyte(osTypeInfo.GetOSName()).c_str() );
        inst.OSVersion_value( StrToMultibyte(osTypeInfo.GetOSVersion()).c_str() );
        inst.OSAlias_value( StrToMultibyte(osTypeInfo.GetOSAlias()).c_str() );
        inst.OSType_value( StrToMultibyte(osTypeInfo.GetOSFamilyString()).c_str() );
        inst.Architecture_value( StrToMultibyte(osTypeInfo.GetArchitectureString()).c_str() );

        // 
        // This property contains the architecture as uname reports it
        // 
        inst.UnameArchitecture_value( StrToMultibyte(osTypeInfo.GetUnameArchitectureString()).c_str() );

        // 
        // Set property indicating what the lowest log level currently in effect for 
        // the agent is
        // 
        inst.MinActiveLogSeverityThreshold_value(
            StrToMultibyte(SCXCoreLib::SCXLogHandleFactory::GetLogConfigurator()->GetMinActiveSeverityThreshold()).c_str() );

        //
        // Populate the type of machine this is (Physical, Virtual, or Unknown)
        //
        try {
            SystemInfo sysInfo;

            eVmType vmType;
            sysInfo.GetVirtualMachineState(vmType);

            string vmText;
            switch (vmType)
            {
                case eVmDetected:
                    vmText = "Virtual";
                    break;

                case eVmNotDetected:
                    vmText = "Physical";
                    break;

                case eVmUnknown:
                default:
                    vmText = "Unknown";
                    break;
            }

            inst.MachineType_value( vmText.c_str() );
        } catch (SCXException& e) {
            SCX_LOGWARNING(SCXCore::g_MetaProvider.GetLogHandle(), StrAppend(
                               StrAppend(L"Can't read virtual machine state because ", e.What()),
                               e.Where()));
        }

        //
        // Populate the number of physical and logical processors
        //
        try {
            scxulong count;
            if (SCXSystemLib::CPUEnumeration::GetProcessorCountPhysical(count, SCXCore::g_MetaProvider.GetLogHandle()))
            {
                inst.PhysicalProcessors_value(count);
            }
        } catch (SCXException& e) {
            SCX_LOGWARNING(SCXCore::g_MetaProvider.GetLogHandle(), StrAppend(
                               StrAppend(L"Can't read physical processor count because ", e.What()),
                               e.Where()));
        }

        try {
            scxulong count;
            if (SCXSystemLib::CPUEnumeration::GetProcessorCountLogical(count))
            {
                inst.LogicalProcessors_value(count);
            }
        } catch (SCXException& e) {
            SCX_LOGWARNING(SCXCore::g_MetaProvider.GetLogHandle(), StrAppend(
                               StrAppend(L"Can't read logical processor count because ", e.What()),
                               e.Where()));
        }
    }

    context.Post(inst);
}

SCX_Agent_Class_Provider::SCX_Agent_Class_Provider(
    Module* module) :
    m_Module(module)
{
}

SCX_Agent_Class_Provider::~SCX_Agent_Class_Provider()
{
}

void SCX_Agent_Class_Provider::Load(
        Context& context)
{
    SCX_PEX_BEGIN
    {
        // Global lock for MetaProvider class
        SCXCoreLib::SCXThreadLock lock(SCXCoreLib::ThreadLockHandleGet(L"SCXCore::MetaProvider::Lock"));
        SCXCore::g_MetaProvider.Load();

        // Notify that we don't wish to unload
        MI_Result r = context.RefuseUnload();
        if ( MI_RESULT_OK != r )
        {
            SCX_LOGWARNING(SCXCore::g_MetaProvider.GetLogHandle(),
                SCXCoreLib::StrAppend(L"SCX_Agent_Class_Provider::Load() refuses to not unload, error = ", r));
        }

        context.Post(MI_RESULT_OK);
    }
    SCX_PEX_END( L"SCX_Agent_Class_Provider::Load", SCXCore::g_MetaProvider.GetLogHandle() );
}

void SCX_Agent_Class_Provider::Unload(
        Context& context)
{
    SCX_PEX_BEGIN
    {
        // Global lock for MetaProvider class
        SCXCoreLib::SCXThreadLock lock(SCXCoreLib::ThreadLockHandleGet(L"SCXCore::MetaProvider::Lock"));
        SCXCore::g_MetaProvider.Unload();
        context.Post(MI_RESULT_OK);
    }
    SCX_PEX_END( L"SCX_Agent_Class_Provider::Unload", SCXCore::g_MetaProvider.GetLogHandle() );
}

void SCX_Agent_Class_Provider::EnumerateInstances(
    Context& context,
    const String& nameSpace,
    const PropertySet& propertySet,
    bool keysOnly,
    const MI_Filter* filter)
{
    SCX_PEX_BEGIN
    {
        // Global lock for MetaProvider class
        SCXCoreLib::SCXThreadLock lock(SCXCoreLib::ThreadLockHandleGet(L"SCXCore::MetaProvider::Lock"));

        SCX_Agent_Class inst;
        EnumerateOneInstance( context, inst, keysOnly );
        context.Post(MI_RESULT_OK);
    }
    SCX_PEX_END( L"SCX_Agent_Class_Provider::EnumerateInstances", SCXCore::g_MetaProvider.GetLogHandle() );
}

void SCX_Agent_Class_Provider::GetInstance(
    Context& context,
    const String& nameSpace,
    const SCX_Agent_Class& instanceName,
    const PropertySet& propertySet)
{
    SCX_PEX_BEGIN
    {
        // Global lock for MetaProvider class
        SCXCoreLib::SCXThreadLock lock(SCXCoreLib::ThreadLockHandleGet(L"SCXCore::MetaProvider::Lock"));

        // SCX_Agent has one fixed key: Name=scx
        if ( !instanceName.Name_exists() )
        {
            context.Post(MI_RESULT_INVALID_PARAMETER);
            return;
        }

        if (0 != strcasecmp("scx", instanceName.Name_value().Str()))
        {
            context.Post(MI_RESULT_NOT_FOUND);
            return;
        }

        SCX_Agent_Class inst;
        EnumerateOneInstance( context, inst, false );
        context.Post(MI_RESULT_OK);
    }
    SCX_PEX_END( L"SCX_Agent_Class_Provider::GetInstance", SCXCore::g_MetaProvider.GetLogHandle() );
}

void SCX_Agent_Class_Provider::CreateInstance(
    Context& context,
    const String& nameSpace,
    const SCX_Agent_Class& newInstance)
{
    context.Post(MI_RESULT_NOT_SUPPORTED);
}

void SCX_Agent_Class_Provider::ModifyInstance(
    Context& context,
    const String& nameSpace,
    const SCX_Agent_Class& modifiedInstance,
    const PropertySet& propertySet)
{
    context.Post(MI_RESULT_NOT_SUPPORTED);
}

void SCX_Agent_Class_Provider::DeleteInstance(
    Context& context,
    const String& nameSpace,
    const SCX_Agent_Class& instanceName)
{
    context.Post(MI_RESULT_NOT_SUPPORTED);
}


MI_END_NAMESPACE
