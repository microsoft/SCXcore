/* @migen@ */
#include <MI.h>
#include "SCX_UnixProcess_Class_Provider.h"
#include "SCX_UnixProcess.h"

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

namespace SCXCore
{
    ProcessProvider g_ProcessProvider;
    int ProcessProvider::ms_loadCount = 0;
}

MI_BEGIN_NAMESPACE

static void EnumerateOneInstance(Context& context,
        SCX_UnixProcess_Class& inst, bool keysOnly,
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
    inst.CreationClassName_value("SCX_UnixProcess");


    if (!keysOnly)
    {
        std::string name("");
        std::vector<std::string> params;
        std::wstring str(L"");
        unsigned int uint = 0;
        unsigned short ushort = 0;
        scxulong ulong = 0;
        SCXCoreLib::SCXCalendarTime ctime;
        int ppid = 0;

        inst.Description_value("A snapshot of a current process");
        inst.Caption_value("Unix process information");

        if (processinst->GetOtherExecutionDescription(str))
        {
            inst.OtherExecutionDescription_value(StrToUTF8(str).c_str());
        }

        if (processinst->GetKernelModeTime(ulong))
        {
            inst.KernelModeTime_value(ulong);
        }

        if (processinst->GetUserModeTime(ulong))
        {
            inst.UserModeTime_value(ulong);
        }

        if (processinst->GetWorkingSetSize(ulong))
        {
            inst.WorkingSetSize_value(ulong);
        }

        if (processinst->GetProcessSessionID(ulong))
        {
            inst.ProcessSessionID_value(ulong);
        }

        if (processinst->GetProcessTTY(name))
        {
            inst.ProcessTTY_value(name.c_str());
        }

        if (processinst->GetModulePath(name))
        {
            inst.ModulePath_value(name.c_str());
        }

        if (processinst->GetParameters(params))
        {
            std::vector<mi::String> strArrary;
            for (std::vector<std::string>::const_iterator iter = params.begin();
                    iter != params.end(); ++iter)
            {
               strArrary.push_back((*iter).c_str());
            }
            mi::StringA props(&strArrary[0], static_cast<MI_Uint32>(params.size()));
            inst.Parameters_value(props);
        } 

        if (processinst->GetProcessWaitingForEvent(name))
        {
            inst.ProcessWaitingForEvent_value(name.c_str());
        }

        if (processinst->GetName(name))
        {
            inst.Name_value(name.c_str());
        }

        if (processinst->GetPriority(uint))
        {
            inst.Priority_value(uint);
        }

        if (processinst->GetExecutionState(ushort))
        {
            inst.ExecutionState_value(ushort);
        }

        if (processinst->GetCreationDate(ctime))
        {
            MI_Datetime creationDate; 
            CIMUtils::ConvertToCIMDatetime(creationDate, ctime);
            inst.CreationDate_value(creationDate);
        }

        if (processinst->GetTerminationDate(ctime))
        {
            MI_Datetime terminationDate; 
            CIMUtils::ConvertToCIMDatetime(terminationDate, ctime);
            inst.TerminationDate_value(terminationDate);
        }

        if (processinst->GetParentProcessID(ppid))
        {
            inst.ParentProcessID_value(StrToUTF8(StrFrom(ppid)).c_str());
        }

        if (processinst->GetRealUserID(ulong))
        {
            inst.RealUserID_value(ulong);
        }

        if (processinst->GetProcessGroupID(ulong))
        {
            inst.ProcessGroupID_value( ulong);
        }

        if (processinst->GetProcessNiceValue(uint))
        {
            inst.ProcessNiceValue_value(uint);
        }

    }
    context.Post(inst);
}

SCX_UnixProcess_Class_Provider::SCX_UnixProcess_Class_Provider(
    Module* module) :
    m_Module(module)
{
}

SCX_UnixProcess_Class_Provider::~SCX_UnixProcess_Class_Provider()
{
}

void SCX_UnixProcess_Class_Provider::Load(
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
                    SCXCoreLib::StrAppend(L"SCX_UnixProcess_Class_Provider::Load() refuses to not unload, error = ", r));
        }

        context.Post(MI_RESULT_OK);
    }
    SCX_PEX_END( L"SCX_UnixProcess_Class_Provider::Load", SCXCore::g_ProcessProvider.GetLogHandle() );
}

void SCX_UnixProcess_Class_Provider::Unload(
        Context& context)
{
    SCX_PEX_BEGIN
    {
        // Global lock for ProcessProvider class
        SCXCoreLib::SCXThreadLock lock(SCXCoreLib::ThreadLockHandleGet(L"SCXCore::ProcessProvider::Lock"));
        SCXCore::g_ProcessProvider.Unload();

        context.Post(MI_RESULT_OK);
    }
    SCX_PEX_END( L"SCX_UnixProcess_Class_Provider::Unload", SCXCore::g_ProcessProvider.GetLogHandle() );
}

void SCX_UnixProcess_Class_Provider::EnumerateInstances(
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
            SCX_UnixProcess_Class proc;
            EnumerateOneInstance(context, proc, keysOnly, processEnum->GetInstance(i));
        }
        context.Post(MI_RESULT_OK);
    }
    SCX_PEX_END( L"SCX_UnixProcess_Class_Provider::EnumerateInstances", SCXCore::g_ProcessProvider.GetLogHandle() );
}

void SCX_UnixProcess_Class_Provider::GetInstance(
    Context& context,
    const String& nameSpace,
    const SCX_UnixProcess_Class& instanceName,
    const PropertySet& propertySet)
{
    SCX_PEX_BEGIN
    {
        // Global lock for ProcessProvider class
        SCXCoreLib::SCXThreadLock lock(SCXCoreLib::ThreadLockHandleGet(L"SCXCore::ProcessProvider::Lock"));

        // We have 6-part key:
        //   [Key] CSCreationClassName=SCX_ComputerSystem
        //   [Key] CSName=jeffcof64-rhel6-01.scx.com
        //   [Key] OSCreationClassName=SCX_OperatingSystem
        //   [Key] OSName=Red Hat Distribution
        //   [Key] CreationClassName=SCX_UnixProcess
        //   [Key] Handle=54321

        if (!instanceName.CSCreationClassName_exists() || !instanceName.CSName_exists() ||
            !instanceName.OSCreationClassName_exists() || !instanceName.OSName_exists() ||
            !instanceName.CreationClassName_exists() || !instanceName.Handle_exists())
        {
            context.Post(MI_RESULT_INVALID_PARAMETER);
            return;
        }

        std::string csName;
        try {
            NameResolver mi;
            csName = StrToMultibyte(mi.GetHostDomainname()).c_str();
        } catch (SCXException& e) {
            SCX_LOGWARNING(SCXCore::g_ProcessProvider.GetLogHandle(), StrAppend(
                               StrAppend(L"Can't read host/domainname because ", e.What()),
                               e.Where()));
        }

        std::string osName;
        try {
            SCXSystemLib::SCXOSTypeInfo osinfo;
            osName = StrToMultibyte(osinfo.GetOSName(true)).c_str();
        } catch (SCXException& e){
            SCX_LOGWARNING(SCXCore::g_ProcessProvider.GetLogHandle(), StrAppend(
                        StrAppend(L"Can't read OS name because ", e.What()),
                        e.Where()));
        }

        // Now compare (case insensitive for the class names, case sensitive for the others)
        if ( 0 != strcasecmp("SCX_ComputerSystem", instanceName.CSCreationClassName_value().Str())
             || 0 != strcmp(csName.c_str(), instanceName.CSName_value().Str())
             || 0 != strcasecmp("SCX_OperatingSystem", instanceName.OSCreationClassName_value().Str())
             || 0 != strcmp(osName.c_str(), instanceName.OSName_value().Str())
             || 0 != strcasecmp("SCX_UnixProcess", instanceName.CreationClassName_value().Str()))
        {
            context.Post(MI_RESULT_NOT_FOUND);
            return;
        }

        if (!strlen(instanceName.Handle_value().Str()) )
        {
            context.Post(MI_RESULT_INVALID_PARAMETER);
            return;
        }

        SCX_LOGTRACE(SCXCore::g_ProcessProvider.GetLogHandle(), L"Process Provider GetInstances");
        SCXHandle<SCXSystemLib::ProcessEnumeration> processEnum = SCXCore::g_ProcessProvider.GetProcessEnumerator();
        processEnum->Update();

        SCXCoreLib::SCXHandle<SCXSystemLib::ProcessInstance> processInst = processEnum->GetInstance(
            StrFromMultibyte(instanceName.Handle_value().Str()));

        if (processInst == NULL)
        {
            // Didn't find a match.
            context.Post(MI_RESULT_NOT_FOUND);
            return;
        }

        // Found a Match. Enumerate the properties for the instance.
        SCX_UnixProcess_Class proc;
        EnumerateOneInstance(context, proc, false, processInst);

        context.Post(MI_RESULT_OK);
    }
    SCX_PEX_END( L"SCX_UnixProcess_Class_Provider::GetInstances", SCXCore::g_ProcessProvider.GetLogHandle() );


}

void SCX_UnixProcess_Class_Provider::CreateInstance(
    Context& context,
    const String& nameSpace,
    const SCX_UnixProcess_Class& newInstance)
{
    context.Post(MI_RESULT_NOT_SUPPORTED);
}

void SCX_UnixProcess_Class_Provider::ModifyInstance(
    Context& context,
    const String& nameSpace,
    const SCX_UnixProcess_Class& modifiedInstance,
    const PropertySet& propertySet)
{
    context.Post(MI_RESULT_NOT_SUPPORTED);
}

void SCX_UnixProcess_Class_Provider::DeleteInstance(
    Context& context,
    const String& nameSpace,
    const SCX_UnixProcess_Class& instanceName)
{
    context.Post(MI_RESULT_NOT_SUPPORTED);
}

void SCX_UnixProcess_Class_Provider::Invoke_RequestStateChange(
    Context& context,
    const String& nameSpace,
    const SCX_UnixProcess_Class& instanceName,
    const SCX_UnixProcess_RequestStateChange_Class& in)
{
    context.Post(MI_RESULT_NOT_SUPPORTED);
}

void SCX_UnixProcess_Class_Provider::Invoke_TopResourceConsumers(
    Context& context,
    const String& nameSpace,
    const SCX_UnixProcess_Class& instanceName,
    const SCX_UnixProcess_TopResourceConsumers_Class& in)
{
    SCXCoreLib::SCXLogHandle log = SCXCore::g_ProcessProvider.GetLogHandle();
    SCX_PEX_BEGIN
    {
        // Global lock for ProcessProvider class
        SCXCoreLib::SCXThreadLock lock(SCXCoreLib::ThreadLockHandleGet(L"SCXCore::ProcessProvider::Lock"));
        SCX_LOGTRACE( log, L"SCX_UnixProcess_Class_Provider::Invoke_TopResourceConsumers" );

        // Validate that we have mandatory arguments
        if ( !in.count_exists() || !in.resource_exists() )
        {
            SCX_LOGTRACE( log, L"Missing arguments to Invoke_TopResourceConsumers method" );
            context.Post(MI_RESULT_INVALID_PARAMETER);
            return;
        }
        std::wstring return_str;
        std::wstring resourceStr = StrFromUTF8(in.resource_value().Str());
        SCXCore::g_ProcessProvider.GetTopResourceConsumers(resourceStr, (unsigned short)in.count_value(), return_str);

        SCX_UnixProcess_TopResourceConsumers_Class inst;
        inst.MIReturn_value(StrToMultibyte(return_str).c_str());

        context.Post(inst);
        context.Post(MI_RESULT_OK);
    }
    SCX_PEX_END( L"SCX_UnixProcess_Class_Provider::Invoke_TopResourceConsumers", log );
}


MI_END_NAMESPACE
