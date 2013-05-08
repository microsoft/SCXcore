/* @migen@ */
#include <MI.h>
#include "SCX_UnixProcessStatisticalInformation_Class_Provider.h"
#include "SCX_UnixProcessStatisticalInformation.h"

#include <scxcorelib/scxcmn.h>
#include <scxcorelib/stringaid.h>
#include <scxcorelib/scxthreadlock.h>
#include <scxcorelib/scxnameresolver.h>
#include <scxsystemlib/scxostypeinfo.h>
#include <scxsystemlib/processinstance.h>
#include "support/scxcimutils.h"
#include "support/processprovider.h"
#include <sstream>

using namespace SCXSystemLib;
using namespace SCXCoreLib;

MI_BEGIN_NAMESPACE

static void EnumerateOneInstance(Context& context,
        SCX_UnixProcessStatisticalInformation_Class& inst, bool keysOnly,
        SCXCoreLib::SCXHandle<SCXSystemLib::ProcessInstance> processinst)
{
    SCXLogHandle& log = SCXCore::g_ProcessProvider.GetLogHandle();

    // Add the key properties first.
    scxulong pid;
    if (processinst->GetPID(pid))
    {
        inst.Handle_value(StrToUTF8(StrFrom(pid)).c_str());
    }

    // Add keys of scoping operating system
    try {
        SCXCoreLib::NameResolver mi;
        inst.CSName_value(StrToMultibyte(mi.GetHostDomainname()).c_str());
    } catch (SCXException& e){
        SCX_LOGWARNING(log, StrAppend(
                    StrAppend(L"Can't read host/domainname because ", e.What()),
                    e.Where()));
    }

    try {
        SCXSystemLib::SCXOSTypeInfo osinfo;
        inst.OSName_value(StrToMultibyte(osinfo.GetOSName(true)).c_str());
    } catch (SCXException& e){
        SCX_LOGWARNING(log, StrAppend(
                    StrAppend(L"Can't read OS name because ", e.What()),
                    e.Where()));
    }

    inst.CSCreationClassName_value("SCX_ComputerSystem");
    inst.OSCreationClassName_value("SCX_OperatingSystem");
    inst.ProcessCreationClassName_value("SCX_UnixProcessStatisticalInformation");

    std::string name;
    if (processinst->GetName(name))
    {
        inst.Name_value(name.c_str());
    }

    if (!keysOnly)
    {
        unsigned int uint = 0;
        scxulong ulong = 0;

        inst.Description_value("A snapshot of a current process");
        inst.Caption_value("Unix process information");

        if (processinst->GetRealData(ulong))
        {
            inst.RealData_value(ulong);
        }

        if (processinst->GetRealStack(ulong))
        {
            inst.RealStack_value(ulong);
        }

        if (processinst->GetVirtualText(ulong))
        {
            inst.VirtualText_value(ulong);
        }

        if (processinst->GetVirtualData(ulong))
        {
            inst.VirtualData_value(ulong);
        }

        if (processinst->GetVirtualStack(ulong))
        {
            inst.VirtualStack_value(ulong);
        }

        if (processinst->GetVirtualMemoryMappedFileSize(ulong))
        {
            inst.VirtualMemoryMappedFileSize_value(ulong);
        }

        if (processinst->GetVirtualSharedMemory(ulong))
        {
            inst.VirtualSharedMemory_value(ulong);
        }

        if (processinst->GetCpuTimeDeadChildren(ulong))
        {
            inst.CpuTimeDeadChildren_value(ulong);
        }

        if (processinst->GetSystemTimeDeadChildren(ulong))
        {
            inst.SystemTimeDeadChildren_value(ulong);
        }

        if (processinst->GetRealText(ulong))
        {
            inst.RealText_value(ulong);
        }

        if (processinst->GetCPUTime(uint))
        {
            inst.CPUTime_value(uint);
        }

        if (processinst->GetBlockWritesPerSecond(ulong))
        {
            inst.BlockWritesPerSecond_value(ulong);
        }

        if (processinst->GetBlockReadsPerSecond(ulong))
        {
            inst.BlockReadsPerSecond_value(ulong);
        }

        if (processinst->GetBlockTransfersPerSecond(ulong))
        {
            inst.BlockTransfersPerSecond_value(ulong);
        }

        if (processinst->GetPercentUserTime(ulong))
        {
            inst.PercentUserTime_value((unsigned char) ulong);
        }

        if (processinst->GetPercentPrivilegedTime(ulong))
        {
            inst.PercentPrivilegedTime_value((unsigned char) ulong);
        }

        if (processinst->GetUsedMemory(ulong))
        {
            inst.UsedMemory_value(ulong);
        }

        if (processinst->GetPercentUsedMemory(ulong))
        {
            inst.PercentUsedMemory_value((unsigned char) ulong);
        }

        if (processinst->GetPagesReadPerSec(ulong))
        {
            inst.PagesReadPerSec_value(ulong);
        }
    }
    context.Post(inst);
}

SCX_UnixProcessStatisticalInformation_Class_Provider::SCX_UnixProcessStatisticalInformation_Class_Provider(
    Module* module) :
    m_Module(module)
{
}

SCX_UnixProcessStatisticalInformation_Class_Provider::~SCX_UnixProcessStatisticalInformation_Class_Provider()
{
}

void SCX_UnixProcessStatisticalInformation_Class_Provider::Load(
        Context& context)
{
    SCX_PEX_BEGIN
    {
        // Global lock for ProcessProvider class
        SCXCoreLib::SCXThreadLock lock(SCXCoreLib::ThreadLockHandleGet(L"SCXCore::ProcessProvider::Lock"));
        SCXCore::g_ProcessProvider.Load();

        // Notify that we don't wish to unload
        MI_Result r = context.RefuseUnload();
        if ( MI_RESULT_OK != r )
        {
            SCX_LOGWARNING(SCXCore::g_ProcessProvider.GetLogHandle(),
                    SCXCoreLib::StrAppend(L"SCX_UnixProcessStatisticalInformation_Class_Provider::Load() refuses to not unload, error = ", r));
        }

        context.Post(MI_RESULT_OK);
    }
    SCX_PEX_END( L"SCX_UnixProcessStatisticalInformation_Class_Provider::Load", SCXCore::g_ProcessProvider.GetLogHandle() );
}

void SCX_UnixProcessStatisticalInformation_Class_Provider::Unload(
        Context& context)
{
    SCX_PEX_BEGIN
    {
        // Global lock for ProcessProvider class
        SCXCoreLib::SCXThreadLock lock(SCXCoreLib::ThreadLockHandleGet(L"SCXCore::ProcessProvider::Lock"));
        SCXCore::g_ProcessProvider.Unload();

        context.Post(MI_RESULT_OK);
    }
    SCX_PEX_END( L"SCX_UnixProcessStatisticalInformation_Class_Provider::Unload", SCXCore::g_ProcessProvider.GetLogHandle() );
}

void SCX_UnixProcessStatisticalInformation_Class_Provider::EnumerateInstances(
    Context& context,
    const String& nameSpace,
    const PropertySet& propertySet,
    bool keysOnly,
    const MI_Filter* filter)
{
    SCX_PEX_BEGIN
    {
        // Global lock for ProcessProvider class
        SCXCoreLib::SCXThreadLock lock(SCXCoreLib::ThreadLockHandleGet(L"SCXCore::ProcessProvider::Lock"));

        SCX_LOGTRACE(SCXCore::g_ProcessProvider.GetLogHandle(), L"Process Provider EnumerateInstances");
        SCXHandle<SCXSystemLib::ProcessEnumeration> processEnum = SCXCore::g_ProcessProvider.GetProcessEnumerator();
        processEnum->Update();

        SCX_LOGTRACE(SCXCore::g_ProcessProvider.GetLogHandle(), StrAppend(L"Number of Processes = ", processEnum->Size()));

        for(size_t i = 0; i < processEnum->Size(); i++)
        {
            SCX_UnixProcessStatisticalInformation_Class proc;
            EnumerateOneInstance(context, proc, keysOnly, processEnum->GetInstance(i));
        }
        context.Post(MI_RESULT_OK);
    }
    SCX_PEX_END( L"SCX_UnixProcessStatisticalInformation_Class_Provider::EnumerateInstances", SCXCore::g_ProcessProvider.GetLogHandle() );
}

void SCX_UnixProcessStatisticalInformation_Class_Provider::GetInstance(
    Context& context,
    const String& nameSpace,
    const SCX_UnixProcessStatisticalInformation_Class& instanceName,
    const PropertySet& propertySet)
{
    SCXLogHandle& log = SCXCore::g_ProcessProvider.GetLogHandle();

    SCX_PEX_BEGIN
    {
        // Global lock for ProcessProvider class
        SCXCoreLib::SCXThreadLock lock(SCXCoreLib::ThreadLockHandleGet(L"SCXCore::ProcessProvider::Lock"));

        // We have 7-part key:
        //   [Key] Name=udevd
        //   [Key] CSCreationClassName=SCX_ComputerSystem
        //   [Key] CSName=jeffcof64-rhel6-01.scx.com
        //   [Key] OSCreationClassName=SCX_OperatingSystem
        //   [Key] OSName=Red Hat Distribution
        //   [Key] Handle=54321
        //   [Key] ProcessCreationClassName=SCX_UnixProcessStatisticalInformation

        if ( !instanceName.Handle_exists() ||
             !instanceName.Name_exists() || 
             !instanceName.CSCreationClassName_exists() ||
             !instanceName.CSName_exists() ||
             !instanceName.OSCreationClassName_exists() ||
             !instanceName.OSName_exists() ||
             !instanceName.ProcessCreationClassName_exists() ) 
        {
            context.Post(MI_RESULT_INVALID_PARAMETER);
            return;
        }

        SCXCoreLib::NameResolver mi;
        std::string csName;
        try {
            csName = StrToMultibyte(mi.GetHostDomainname()).c_str();
        } catch (SCXException& e){
            SCX_LOGWARNING(log, StrAppend(
                        StrAppend(L"Can't read host/domainname because ", e.What()),
                        e.Where()));
        }

        SCXSystemLib::SCXOSTypeInfo osinfo;
        std::string osName;
        try {
            osName = StrToMultibyte(osinfo.GetOSName(true)).c_str();
        } catch (SCXException& e){
            SCX_LOGWARNING(log, StrAppend(
                        StrAppend(L"Can't read OS name because ", e.What()),
                        e.Where()));
        }

        SCX_LOGTRACE(log, L"Process Provider GetInstances");
        SCXHandle<SCXSystemLib::ProcessEnumeration> processEnum = SCXCore::g_ProcessProvider.GetProcessEnumerator();
        processEnum->Update();

        SCXCoreLib::SCXHandle<SCXSystemLib::ProcessInstance> processInst =
            processEnum->GetInstance(StrFromMultibyte(instanceName.Handle_value().Str()));

        std::string name;
        if (processInst != NULL)
        {
            processInst->GetName(name);
        }

        if ( (processInst == NULL) || 
             (0 != strcmp(name.c_str(), instanceName.Name_value().Str())) || 
             (0 != strcmp(csName.c_str(), instanceName.CSName_value().Str())) || 
             (0 != strcmp(osName.c_str(), instanceName.OSName_value().Str())) ||
             (0 != strcasecmp("SCX_ComputerSystem", instanceName.CSCreationClassName_value().Str())) ||
             (0 != strcasecmp("SCX_OperatingSystem", instanceName.OSCreationClassName_value().Str())) ||
             (0 != strcasecmp("SCX_UnixProcessStatisticalInformation", instanceName.ProcessCreationClassName_value().Str())) )
        {
            // Didn't find a match.
            context.Post(MI_RESULT_NOT_FOUND);
            return;
        }

        // Found a Match. Enumerate the properties for the instance.
        SCX_UnixProcessStatisticalInformation_Class proc;
        EnumerateOneInstance(context, proc, false, processInst);

        context.Post(MI_RESULT_OK);
    }
    SCX_PEX_END( L"SCX_UnixProcessStatisticalInformation_Class_Provider::GetInstances", log );
}

void SCX_UnixProcessStatisticalInformation_Class_Provider::CreateInstance(
    Context& context,
    const String& nameSpace,
    const SCX_UnixProcessStatisticalInformation_Class& newInstance)
{
    context.Post(MI_RESULT_NOT_SUPPORTED);
}

void SCX_UnixProcessStatisticalInformation_Class_Provider::ModifyInstance(
    Context& context,
    const String& nameSpace,
    const SCX_UnixProcessStatisticalInformation_Class& modifiedInstance,
    const PropertySet& propertySet)
{
    context.Post(MI_RESULT_NOT_SUPPORTED);
}

void SCX_UnixProcessStatisticalInformation_Class_Provider::DeleteInstance(
    Context& context,
    const String& nameSpace,
    const SCX_UnixProcessStatisticalInformation_Class& instanceName)
{
    context.Post(MI_RESULT_NOT_SUPPORTED);
}


MI_END_NAMESPACE
