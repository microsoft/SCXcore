/* @migen@ */
#include <MI.h>
#include "SCX_DiskDrive_Class_Provider.h"
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
    SCX_DiskDrive_Class& inst,
    bool keysOnly,
    SCXHandle<SCXSystemLib::StaticPhysicalDiskInstance> diskInst)
{
    SCXCoreLib::NameResolver nr;
    std::wstring hostname = nr.GetHostDomainname();

    diskInst->Update();
                        
    // Populate the key values
    inst.CreationClassName_value("SCX_DiskDrive");
    inst.SystemCreationClassName_value("SCX_ComputerSystem");

    std::wstring deviceId;
    if (diskInst->GetDiskName(deviceId)) 
    {
        inst.DeviceID_value(StrToMultibyte(deviceId).c_str());
    }
    inst.SystemName_value(StrToMultibyte(hostname).c_str());

    if (!keysOnly) 
    {
        //populate caption and descriptions
        inst.Caption_value("Disk drive information");
        inst.Description_value("Information pertaining to a physical unit of secondary storage");
        
        if (deviceId.size() > 0)
        {
            inst.Name_value(StrToMultibyte(deviceId).c_str());
        }

        scxulong data;
        std::wstring sdata;
        bool healthy;

        if (diskInst->GetHealthState(healthy)) 
        {
            inst.IsOnline_value();
        }

        DiskInterfaceType ifcType;
        if (diskInst->GetInterfaceType(ifcType)) 
        {
            std::string interfaceTypeStringValue ;
            switch (ifcType) 
            {
                case eDiskIfcIDE:
                    interfaceTypeStringValue = "IDE";
                    break;

                case eDiskIfcSCSI:
                    interfaceTypeStringValue = "SCSI";
                    break;

                case eDiskIfcVirtual:
                    interfaceTypeStringValue = "Virtual";
                    break;

                case eDiskIfcUnknown:
                case eDiskIfcMax:
                default:
                    interfaceTypeStringValue = "Unknown";
                    break;
            }

            inst.InterfaceType_value(interfaceTypeStringValue.c_str());
        }

        if (diskInst->GetManufacturer(sdata)) 
        {
            inst.Manufacturer_value(StrToMultibyte(sdata).c_str());
        }

        if (diskInst->GetModel(sdata)) 
        {
            inst.Model_value(StrToMultibyte(sdata).c_str());
        }

        if (diskInst->GetSizeInBytes(data)) 
        {
            inst.MaxMediaSize_value(data);
        }

        if (diskInst->GetTotalCylinders(data)) 
        {
            inst.TotalCylinders_value(data);
        }

        if (diskInst->GetTotalHeads(data)) 
        {
            inst.TotalHeads_value(data);
        }

        if (diskInst->GetTotalSectors(data)) 
        {
            inst.TotalSectors_value(data);
        }
    }
    context.Post(inst);
}

SCX_DiskDrive_Class_Provider::SCX_DiskDrive_Class_Provider(
    Module* module) :
    m_Module(module)
{
}

SCX_DiskDrive_Class_Provider::~SCX_DiskDrive_Class_Provider()
{
}

void SCX_DiskDrive_Class_Provider::Load(
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
                           SCXCoreLib::StrAppend(L"SCX_DiskDrive_Class_Provider::Load() refuses to not unload, error = ", r));
        }

        context.Post(MI_RESULT_OK);
    }
    SCX_PEX_END(  L"SCX_DiskDrive_Class_Provider::Load", SCXCore::g_DiskProvider.GetLogHandle() );
}

void SCX_DiskDrive_Class_Provider::Unload(
        Context& context)
{
    SCX_PEX_BEGIN
    {
        // Global lock for DiskProvider class
        SCXCoreLib::SCXThreadLock lock(SCXCoreLib::ThreadLockHandleGet(L"SCXCore::DiskProvider::Lock"));
        SCXCore::g_DiskProvider.UnLoad();
        context.Post(MI_RESULT_OK);
    }
    SCX_PEX_END( L"SCX_DiskDrive_Class_Provider::Unload",  SCXCore::g_DiskProvider.GetLogHandle() );
}

void SCX_DiskDrive_Class_Provider::EnumerateInstances(
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
        SCXHandle<SCXSystemLib::StaticPhysicalDiskEnumeration> diskEnum = SCXCore::g_DiskProvider.getEnumstaticPhysicalDisks();
        diskEnum->Update(!keysOnly);
        
        for(size_t i = 0; i < diskEnum->Size(); i++) 
        {
            SCX_DiskDrive_Class inst;
            SCXHandle<SCXSystemLib::StaticPhysicalDiskInstance> diskInst = diskEnum->GetInstance(i);
            EnumerateOneInstance(context, inst, keysOnly, diskInst);
        }

        // Enumerate Total instance
        SCXHandle<SCXSystemLib::StaticPhysicalDiskInstance> totalInst = diskEnum->GetTotalInstance();
        if (totalInst != NULL)
        {
            // There will always be one total instance
            SCX_DiskDrive_Class inst;
            EnumerateOneInstance(context, inst, keysOnly, totalInst);
        }

        context.Post(MI_RESULT_OK);
    }
    SCX_PEX_END( L"SCX_DiskDrive_Class_Provider::EnumerateInstances",
                     SCXCore::g_DiskProvider.GetLogHandle() );
}

void SCX_DiskDrive_Class_Provider::GetInstance(
    Context& context,
    const String& nameSpace,
    const SCX_DiskDrive_Class& instanceName,
    const PropertySet& propertySet)
{
    SCX_PEX_BEGIN
    {
        // Global lock for DiskProvider class
        SCXCoreLib::SCXThreadLock lock(SCXCoreLib::ThreadLockHandleGet(L"SCXCore::DiskProvider::Lock"));

        // We have 4-part key:
        //   [Key] SystemCreationClassName=SCX_ComputerSystem
        //   [Key] SystemName=jeffcof64-rhel6-01.scx.com
        //   [Key] CreationClassName=SCX_DiskDrive
        //   [Key] DeviceID=sda

        if (!instanceName.SystemCreationClassName_exists() || !instanceName.SystemName_exists() ||
            !instanceName.CreationClassName_exists() || !instanceName.DeviceID_exists())
        {
            context.Post(MI_RESULT_INVALID_PARAMETER);
            return;
        }

        std::string csName;
        try {
            NameResolver mi;
            csName = StrToMultibyte(mi.GetHostDomainname()).c_str();
        } catch (SCXException& e) {
            SCX_LOGWARNING(SCXCore::g_DiskProvider.GetLogHandle(), StrAppend(
                               StrAppend(L"Can't read host/domainname because ", e.What()),
                               e.Where()));
        }

        // Now compare (case insensitive for the class names, case sensitive for the others)
        if ( 0 != strcasecmp("SCX_ComputerSystem", instanceName.SystemCreationClassName_value().Str())
             || 0 != strcasecmp("SCX_DiskDrive", instanceName.CreationClassName_value().Str())
             || 0 != strcmp(csName.c_str(), instanceName.SystemName_value().Str()))
        {
            context.Post(MI_RESULT_NOT_FOUND);
            return;
        }

        //  Prepare Disk Drive Enumeration
        SCXHandle<SCXSystemLib::StaticPhysicalDiskEnumeration> diskEnum = SCXCore::g_DiskProvider.getEnumstaticPhysicalDisks();
        diskEnum->Update(true);

        const std::string deviceId = (instanceName.DeviceID_value()).Str();
        if (deviceId.size() == 0)
        {
            context.Post(MI_RESULT_INVALID_PARAMETER);
            return;
        }
        
        SCXHandle<SCXSystemLib::StaticPhysicalDiskInstance> diskInst;
        diskInst = diskEnum->GetInstance(StrFromUTF8(deviceId));
        
        if (diskInst == NULL)
        {
            context.Post(MI_RESULT_NOT_FOUND);
            return;
        }

        SCX_DiskDrive_Class inst;
        EnumerateOneInstance(context, inst, false, diskInst);
        context.Post(MI_RESULT_OK);
    }
    SCX_PEX_END( L"SCX_DiskDrive_Class_Provider::GetInstance",
                     SCXCore::g_DiskProvider.GetLogHandle() );
}

void SCX_DiskDrive_Class_Provider::CreateInstance(
    Context& context,
    const String& nameSpace,
    const SCX_DiskDrive_Class& newInstance)
{
    context.Post(MI_RESULT_NOT_SUPPORTED);
}

void SCX_DiskDrive_Class_Provider::ModifyInstance(
    Context& context,
    const String& nameSpace,
    const SCX_DiskDrive_Class& modifiedInstance,
    const PropertySet& propertySet)
{
    context.Post(MI_RESULT_NOT_SUPPORTED);
}

void SCX_DiskDrive_Class_Provider::DeleteInstance(
    Context& context,
    const String& nameSpace,
    const SCX_DiskDrive_Class& instanceName)
{
    context.Post(MI_RESULT_NOT_SUPPORTED);
}

void SCX_DiskDrive_Class_Provider::Invoke_RequestStateChange(
    Context& context,
    const String& nameSpace,
    const SCX_DiskDrive_Class& instanceName,
    const SCX_DiskDrive_RequestStateChange_Class& in)
{
    context.Post(MI_RESULT_NOT_SUPPORTED);
}

void SCX_DiskDrive_Class_Provider::Invoke_SetPowerState(
    Context& context,
    const String& nameSpace,
    const SCX_DiskDrive_Class& instanceName,
    const SCX_DiskDrive_SetPowerState_Class& in)
{
    context.Post(MI_RESULT_NOT_SUPPORTED);
}

void SCX_DiskDrive_Class_Provider::Invoke_Reset(
    Context& context,
    const String& nameSpace,
    const SCX_DiskDrive_Class& instanceName,
    const SCX_DiskDrive_Reset_Class& in)
{
    context.Post(MI_RESULT_NOT_SUPPORTED);
}

void SCX_DiskDrive_Class_Provider::Invoke_EnableDevice(
    Context& context,
    const String& nameSpace,
    const SCX_DiskDrive_Class& instanceName,
    const SCX_DiskDrive_EnableDevice_Class& in)
{
    context.Post(MI_RESULT_NOT_SUPPORTED);
}

void SCX_DiskDrive_Class_Provider::Invoke_OnlineDevice(
    Context& context,
    const String& nameSpace,
    const SCX_DiskDrive_Class& instanceName,
    const SCX_DiskDrive_OnlineDevice_Class& in)
{
    context.Post(MI_RESULT_NOT_SUPPORTED);
}

void SCX_DiskDrive_Class_Provider::Invoke_QuiesceDevice(
    Context& context,
    const String& nameSpace,
    const SCX_DiskDrive_Class& instanceName,
    const SCX_DiskDrive_QuiesceDevice_Class& in)
{
    context.Post(MI_RESULT_NOT_SUPPORTED);
}

void SCX_DiskDrive_Class_Provider::Invoke_SaveProperties(
    Context& context,
    const String& nameSpace,
    const SCX_DiskDrive_Class& instanceName,
    const SCX_DiskDrive_SaveProperties_Class& in)
{
    context.Post(MI_RESULT_NOT_SUPPORTED);
}

void SCX_DiskDrive_Class_Provider::Invoke_RestoreProperties(
    Context& context,
    const String& nameSpace,
    const SCX_DiskDrive_Class& instanceName,
    const SCX_DiskDrive_RestoreProperties_Class& in)
{
    context.Post(MI_RESULT_NOT_SUPPORTED);
}

void SCX_DiskDrive_Class_Provider::Invoke_LockMedia(
    Context& context,
    const String& nameSpace,
    const SCX_DiskDrive_Class& instanceName,
    const SCX_DiskDrive_LockMedia_Class& in)
{
    context.Post(MI_RESULT_NOT_SUPPORTED);
}

void SCX_DiskDrive_Class_Provider::Invoke_RemoveByName(
    Context& context,
    const String& nameSpace,
    const SCX_DiskDrive_Class& instanceName,
    const SCX_DiskDrive_RemoveByName_Class& in)
{
    SCX_PEX_BEGIN
    {
        // Global lock for DiskProvider class
        SCXCoreLib::SCXThreadLock lock(SCXCoreLib::ThreadLockHandleGet(L"SCXCore::DiskProvider::Lock"));
        
        SCXHandle<SCXSystemLib::StaticPhysicalDiskEnumeration> diskEnum = SCXCore::g_DiskProvider.getEnumstaticPhysicalDisks();
        diskEnum->Update(true);
        
        SCX_DiskDrive_RemoveByName_Class inst;
        if (!in.Name_exists() || strlen(in.Name_value().Str()) == 0)
        {
            inst.MIReturn_value(0);
            context.Post(inst);
            context.Post(MI_RESULT_INVALID_PARAMETER);
            return;
        }
        std::wstring name = StrFromMultibyte(in.Name_value().Str());

        SCXHandle<SCXSystemLib::StaticPhysicalDiskInstance> diskInst;
        if ( (diskInst = diskEnum->GetInstance(name)) == NULL )
        {
            inst.MIReturn_value(0);
            context.Post(inst);
            context.Post(MI_RESULT_NOT_FOUND);
            return;
        }

        SCX_DiskDrive_Class ddInst;
        EnumerateOneInstance(context, ddInst, false, diskInst);

        bool cmdok = SCXCore::g_DiskProvider.getEnumstatisticalPhysicalDisks()->RemoveInstanceById(name) && 
                             SCXCore::g_DiskProvider.getEnumstaticPhysicalDisks()->RemoveInstanceById(name);

        inst.MIReturn_value(cmdok);
        context.Post(inst);
        context.Post(MI_RESULT_OK);
    }
    SCX_PEX_END( L"SCX_DiskDrive_Class_Provider::Invoke_RemoveByName", SCXCore::g_DiskProvider.GetLogHandle() );
}


MI_END_NAMESPACE
