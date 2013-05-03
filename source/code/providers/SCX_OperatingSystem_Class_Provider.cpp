/* @migen@ */
#include <MI.h>
#include "SCX_OperatingSystem_Class_Provider.h"

#include <scxcorelib/scxcmn.h>
#include <scxcorelib/scxfile.h>
#include <scxcorelib/scxlog.h>
#include <scxcorelib/scxmath.h>
#include <scxcorelib/scxnameresolver.h>
#include <scxcorelib/scxprocess.h>
#include <scxcorelib/scxuser.h>
#include <scxsystemlib/osenumeration.h>
#include <scxsystemlib/osinstance.h>
#include <scxsystemlib/memoryenumeration.h>
#include <scxsystemlib/processenumeration.h>
#include <scxsystemlib/scxostypeinfo.h>
#include <scxsystemlib/scxsysteminfo.h>

#include "support/scxcimutils.h"
#include "support/scxrunasconfigurator.h"
#include "support/startuplog.h"
#include "support/osprovider.h"

using namespace SCXSystemLib;
using namespace SCXCoreLib;

namespace
{
    scxlong BytesToKiloBytes(scxulong bytes)
    {
        // This will do - let's just fix the names
        return SCXCoreLib::KiloBytesToMegaBytes(bytes);
    }
}

namespace SCXCore
{
    //
    // RunAs Provider Implementation
    //
    // The RunAs Provider is a separate implementation because we're strongly
    // considering separating the RunAs provider into it's own CIM class.
    //

    class RunAsProvider
    {
    public:
        RunAsProvider() : m_Configurator(NULL) { }
        ~RunAsProvider() { };

        void Load();
        void Unload();

        bool ExecuteCommand(const std::wstring &command, std::wstring &resultOut,
                            std::wstring &resultErr, int& returncode, unsigned timeout = 0,
                            const std::wstring &elevationtype = L"");

        bool ExecuteShellCommand(const std::wstring &command, std::wstring &resultOut,
                                 std::wstring &resultErr, int& returncode, unsigned timeout = 0,
                                 const std::wstring &elevationtype = L"");

        bool ExecuteScript(const std::wstring &script, const std::wstring &arguments,
                           std::wstring &resultOut, std::wstring &resultErr,
                           int& returncode, unsigned timeout = 0, const std::wstring &elevationtype = L"");
        
        SCXLogHandle& GetLogHandle() { return m_log; }

    private:
        void ParseConfiguration() { m_Configurator->Parse(); }

        std::wstring ConstructCommandWithElevation(const std::wstring &command, const std::wstring &elevationtype);
        std::wstring ConstructShellCommandWithElevation(const std::wstring &command, const std::wstring &elevationtype);

        //! Configurator.
        SCXCoreLib::SCXHandle<RunAsConfigurator> m_Configurator;

        SCXCoreLib::SCXLogHandle m_log;
        static int ms_loadCount;
    };


    void RunAsProvider::Load()
    {
        SCXASSERT( ms_loadCount >= 0 );
        if ( 1 == ++ms_loadCount )
        {
            m_log = SCXLogHandleFactory::GetLogHandle(L"scx.core.providers.runasprovider");
            LogStartup();
            SCX_LOGTRACE(m_log, L"RunAsProvider::Load()");

            if ( NULL == m_Configurator )
            {
                m_Configurator = SCXCoreLib::SCXHandle<RunAsConfigurator> (new RunAsConfigurator());
            }

            ParseConfiguration();
        }
    }

    void RunAsProvider::Unload()
    {
        SCX_LOGTRACE(m_log, L"OSProvider::Unload()");

        SCXASSERT( ms_loadCount >= 1 );
        if (0 == --ms_loadCount)
        {
            m_Configurator = NULL;
        }
    }

    /*----------------------------------------------------------------------------*/
    /**
        Execute a command

        \param[in]     command          Command to execute
        \param[out]    resultOut        Result string from stdout
        \param[out]    resultErr        Result string from stderr
        \param[out]    returncode       Return code from command
        \param[in]     timeout          Accepted number of seconds to wait
        \param[in]     elevationtype    Elevation type 
        \returns       true if command succeeded, else false
        \throws SCXAccessViolationException If execution is prohibited by configuration
    */
    bool RunAsProvider::ExecuteCommand(const std::wstring &command, std::wstring &resultOut, std::wstring &resultErr, int& returncode,
                                       unsigned timeout, const std::wstring &elevationtype)
    {
        SCX_LOGTRACE(m_log, L"RunAsProvider ExecuteCommand");

        if ( ! m_Configurator->GetAllowRoot() )
        {
            SCXUser currentUser;
            if (currentUser.IsRoot())
            {
                throw SCXAccessViolationException(L"Configuration prohibits execution with user: root", SCXSRCLOCATION);
            }
        }

        std::istringstream processInput;
        std::ostringstream processOutput;
        std::ostringstream processError;
        
        // Construct the command by considering the elevation type. It simply returns the command
        // when elevation type is not empty or the current user is already privilege.
        // The elevated command will become a shell command by the design.        
        std::wstring elecommand = ConstructCommandWithElevation(command, elevationtype);

        try
        {
            returncode = SCXCoreLib::SCXProcess::Run(elecommand, processInput, processOutput, processError, timeout * 1000, m_Configurator->GetCWD(), m_Configurator->GetChRootPath());
            SCX_LOGHYSTERICAL(m_log, L"\"" + elecommand + L"\" returned " + StrFrom(returncode));
            resultOut = StrFromMultibyte(processOutput.str());
            SCX_LOGHYSTERICAL(m_log, L"stdout: " + resultOut);
            resultErr = StrFromMultibyte(processError.str());
            SCX_LOGHYSTERICAL(m_log, L"stderr: " + resultErr);
        }
        catch (SCXCoreLib::SCXException& e)
        {
            resultOut = StrFromMultibyte(processOutput.str());
            resultErr = StrFromMultibyte(processError.str()) + e.What();
            returncode = -1;
        }

        return (returncode == 0);
    }

    /*----------------------------------------------------------------------------*/
    /**
        Execute a command in the default shell.

        \param[in]     command     Command to execute
        \param[out]    resultOut        Result string from stdout
        \param[out]    resultErr        Result string from stderr
        \param[out]    returncode       Return code from command
        \param[in]     timeout          Accepted number of seconds to wait
        \param[in]     elevationtype    Elevation type
        \returns       true if command succeeded, else false
        \throws SCXAccessViolationException If execution is prohibited by configuration
    */
    bool RunAsProvider::ExecuteShellCommand(const std::wstring &command, std::wstring &resultOut, std::wstring &resultErr, int& returncode,
                                            unsigned timeout, const std::wstring &elevationtype)
    {
        SCX_LOGTRACE(m_log, L"RunAsProvider ExecuteShellCommand");

        if ( ! m_Configurator->GetAllowRoot() )
        {
            SCXUser currentUser;
            if (currentUser.IsRoot())
            {
                throw SCXAccessViolationException(L"Configuration prohibits execution with user: root", SCXSRCLOCATION);
            }
        }

        std::istringstream processInput;
        std::ostringstream processOutput;
        std::ostringstream processError;
       
        // Construct the shell command with the given command and elevation type.
        // Please be noted that the constructed shell command use the single quotes. Hence,
        // the current limitation is that the shell command fails if the given command has 
        // single quote. 
        std::wstring shellcommand = ConstructShellCommandWithElevation(command, elevationtype);

        try
        {
            returncode = SCXCoreLib::SCXProcess::Run(shellcommand, processInput, processOutput, processError, timeout * 1000, m_Configurator->GetCWD(), m_Configurator->GetChRootPath());
            SCX_LOGHYSTERICAL(m_log, L"\"" + shellcommand + L"\" returned " + StrFrom(returncode));
            resultOut = StrFromMultibyte(processOutput.str());
            SCX_LOGHYSTERICAL(m_log, L"stdout: " + resultOut);
            resultErr = StrFromMultibyte(processError.str());
            SCX_LOGHYSTERICAL(m_log, L"stderr: " + resultErr);
        }
        catch (SCXCoreLib::SCXException& e)
        {
            resultOut = L"";
            resultErr = e.What();
            returncode = -1;
        }

        return (returncode == 0);
    }

    /*----------------------------------------------------------------------------*/
    /**
        Execute a script

        \param[in]     script           Script to execute
        \param[in]     arguments        Command line arguments to script
        \param[out]    resultOut        Result string from stdout
        \param[out]    resultErr        Result string from stderr
        \param[out]    returncode       Return code from command
        \param[in]     timeout          Accepted number of seconds to wait
        \param[in]     elevationtype    Elevation type

        \returns       true if script succeeded, else false
        \throws SCXAccessViolationException If execution is prohibited by configuration    */
    bool RunAsProvider::ExecuteScript(const std::wstring &script, const std::wstring &arguments, std::wstring &resultOut, std::wstring &resultErr, int& returncode,
                                      unsigned timeout, const std::wstring &elevationtype)
    {
        SCX_LOGTRACE(m_log, L"SCXRunAsProvider ExecuteScript");

        if ( ! m_Configurator->GetAllowRoot() )
        {
            SCXUser currentUser;
            if (currentUser.IsRoot())
            {
                throw SCXAccessViolationException(L"Configuration prohibits execution with user: root", SCXSRCLOCATION);
            }
        }

        std::istringstream processInput;
        std::ostringstream processOutput;
        std::ostringstream processError;

        try
        {
            SCXFilePath scriptfile = SCXFile::CreateTempFile(script);
            SCXFileSystem::Attributes attribs = SCXFileSystem::GetAttributes(scriptfile);
            attribs.insert(SCXFileSystem::eUserExecute);
            SCXFile::SetAttributes(scriptfile, attribs);

            std::wstring command(scriptfile.Get());
            command.append(L" ").append(arguments);

            // Construct the command with the given elevation type.
            command = ConstructCommandWithElevation(command, elevationtype);

            returncode = SCXCoreLib::SCXProcess::Run(command, processInput, processOutput, processError, timeout * 1000, m_Configurator->GetCWD(), m_Configurator->GetChRootPath());
            SCXFile::Delete(scriptfile);

            SCX_LOGHYSTERICAL(m_log, L"\"" + command + L"\" returned " + StrFrom(returncode));
            resultOut = StrFromMultibyte(processOutput.str());
            SCX_LOGHYSTERICAL(m_log, L"stdout: " + resultOut);
            resultErr = StrFromMultibyte(processError.str());
            SCX_LOGHYSTERICAL(m_log, L"stderr: " + resultErr);
        }
        catch (SCXCoreLib::SCXException& e)
        {
            resultOut = L"";
            resultErr = e.What();
            returncode = -1;
        }

        return (returncode == 0);
    }

    std::wstring RunAsProvider::ConstructCommandWithElevation(const std::wstring &command, const std::wstring &elevationtype)
    {
        // Construct the command by considering the elevation type.
        // Noted that SystemInfo GetElevatedCommand function will return a
        // shell command when the elevation type is sudo (it simply returns
        // the command when the current user is already elevated).

        SCXSystemLib::SystemInfo si;
        if (elevationtype == L"sudo")
        {
            return si.GetElevatedCommand(command);
        }

        return command;
    }

    // Construct a shell command for the given command and the elevation type.  
    std::wstring RunAsProvider::ConstructShellCommandWithElevation(const std::wstring &command, const std::wstring &elevationtype)
    {
        SCXSystemLib::SystemInfo si;

        std::wstring newCommand(si.GetShellCommand(command));

        // Only when current user is not priviledged and elevation type is sudo
        // the command need to be elevated.
        // Force a shell command so we get a shell (even if already elevated)
        if (elevationtype == L"sudo")
        {
            newCommand = si.GetElevatedCommand(newCommand);
        }

        return newCommand;
    }

    int RunAsProvider::ms_loadCount = 0;
    static RunAsProvider g_RunAsProvider;
}

MI_BEGIN_NAMESPACE

static void EnumerateOneInstance(
    Context& context,
    SCX_OperatingSystem_Class& inst,
    bool keysOnly,
    SCXHandle<OSInstance> osinst,
    SCXHandle<MemoryInstance> meminst)
{
    // Get some handles
    SCXHandle<SCXOSTypeInfo> osTypeInfo = SCXCore::g_OSProvider.GetOSTypeInfo();
    SCXLogHandle& log = SCXCore::g_OSProvider.GetLogHandle();

    SCX_LOGTRACE(log, L"OSProvider EnumerateOneInstance()");

    // Fill in the keys
    inst.Name_value( StrToMultibyte(osTypeInfo->GetOSName(true)).c_str() );
    inst.CSCreationClassName_value( "SCX_ComputerSystem" );

    try {
        NameResolver mi;
        inst.CSName_value( StrToMultibyte(mi.GetHostDomainname()).c_str() );
    } catch (SCXException& e) {
        SCX_LOGWARNING(log, StrAppend(
                              StrAppend(L"Can't read host/domainname because ", e.What()),
                              e.Where()));
    }

    inst.CreationClassName_value( "SCX_OperatingSystem" );

    if ( !keysOnly )
    {
        SCXCalendarTime ASCXCalendarTime;
        scxulong Ascxulong, Ascxulong1;
        unsigned short Aunsignedshort;
        vector<string> Avector;
        vector<unsigned short> Aushortvector;
        wstring Awstring;
        signed short Ashort;
        unsigned int Auint;

        /*===================================================================================*/
        /* Defaulted Values (from MOF)                                                       */
        /*===================================================================================*/

        inst.EnabledDefault_value( 2 );
        inst.EnabledState_value( 5 );
        inst.RequestedState_value( 12 );

        /*===================================================================================*/
        /* Properties of CIM_ManagedElement                                                  */
        /*===================================================================================*/

        inst.Caption_value( StrToMultibyte(osTypeInfo->GetCaption()).c_str() );
        inst.Description_value( StrToMultibyte(osTypeInfo->GetDescription()).c_str() );

        /*===================================================================================*/
        /* Properties of CIM_ManagedSystemElement                                            */
        /*===================================================================================*/

        // We don't support the following because there's no way to retrieve on any platforms:
        //      InstallDate
        //      Status
        //      OperationalStatus
        //      StatusDescriptions
        //      HealthState

        /*===================================================================================*/
        /* Properties of CIM_OperatingSystem                                                 */
        /*===================================================================================*/

        // We don't support the following because there's no way to retrieve on any platforms:
        //      EnabledState
        //      OtherEnabledState
        //      RequestedState
        //      EnabledDefault
        //      TimeOfLastStateChange
        //      OverwritePolicy
        //      Distributed

        /* CSCreationClassName is a key property and thus set in AddKeys */
        /* CSName is a key property and thus set in AddKeys */
        /* CreationClassName is a key property and thus set in AddKeys */

        if (osinst->GetOSType(Aunsignedshort))
            inst.OSType_value( Aunsignedshort );

        if (osinst->GetOtherTypeDescription(Awstring))
            inst.OtherTypeDescription_value( StrToMultibyte(Awstring).c_str() );

        if (osinst->GetVersion(Awstring))
            inst.Version_value( StrToMultibyte(Awstring).c_str() );

        if (osinst->GetLastBootUpTime(ASCXCalendarTime))
        {
            MI_Datetime bootTime;
            CIMUtils::ConvertToCIMDatetime( bootTime, ASCXCalendarTime );
            inst.LastBootUpTime_value( bootTime );
        }

        if (osinst->GetLocalDateTime(ASCXCalendarTime))
        {
            MI_Datetime localTime;
            CIMUtils::ConvertToCIMDatetime( localTime, ASCXCalendarTime );
            inst.LocalDateTime_value( localTime );
        }

        if (osinst->GetCurrentTimeZone(Ashort))
            inst.CurrentTimeZone_value( Ashort );

        if (osinst->GetNumberOfLicensedUsers(Auint))
            inst.NumberOfLicensedUsers_value( Auint );

        if (osinst->GetNumberOfUsers(Auint))
            inst.NumberOfUsers_value( Auint );

        if (ProcessEnumeration::GetNumberOfProcesses(Auint))
            inst.NumberOfProcesses_value( Auint );

        if (osinst->GetMaxNumberOfProcesses(Auint))
            inst.MaxNumberOfProcesses_value( Auint );

        if (meminst->GetTotalSwap(Ascxulong))
        {
            inst.TotalSwapSpaceSize_value( BytesToKiloBytes(Ascxulong) );
        }

        if (meminst->GetTotalPhysicalMemory(Ascxulong) && meminst->GetTotalSwap(Ascxulong1))
        {
            inst.TotalVirtualMemorySize_value( BytesToKiloBytes(Ascxulong) + BytesToKiloBytes(Ascxulong1) );
        }

        if (meminst->GetAvailableMemory(Ascxulong))
        {
            Ascxulong = BytesToKiloBytes(Ascxulong);

            if (meminst->GetAvailableSwap(Ascxulong1)) {
                inst.FreeVirtualMemory_value( Ascxulong + BytesToKiloBytes(Ascxulong1) );
            }

            inst.FreePhysicalMemory_value( Ascxulong );
        }

        if (meminst->GetTotalPhysicalMemory(Ascxulong))
            inst.TotalVisibleMemorySize_value( BytesToKiloBytes(Ascxulong) );

        if (meminst->GetTotalSwap(Ascxulong))
            inst.SizeStoredInPagingFiles_value( BytesToKiloBytes(Ascxulong) );

        if (meminst->GetAvailableSwap(Ascxulong))
            inst.FreeSpaceInPagingFiles_value( BytesToKiloBytes(Ascxulong) );

        if (osinst->GetMaxProcessMemorySize(Ascxulong))
            inst.MaxProcessMemorySize_value( Ascxulong );

        if (osinst->GetMaxProcessesPerUser(Auint))
            inst.MaxProcessesPerUser_value( Auint );

        /*===================================================================================*/
        /* Properties of SCX_OperatingSystem (Taken from PG_OperatingSystem)                 */
        /*===================================================================================*/

        SystemInfo sysInfo;
        if (sysInfo.GetNativeBitSize(Aunsignedshort))
        {
            std::ostringstream bitText;
            bitText << Aunsignedshort << " bit";

            inst.OperatingSystemCapability_value( bitText.str().c_str() );
        }

        if (osinst->GetSystemUpTime(Ascxulong))
            inst.SystemUpTime_value( Ascxulong );
    }

    context.Post(inst);
}

SCX_OperatingSystem_Class_Provider::SCX_OperatingSystem_Class_Provider(
    Module* module) :
    m_Module(module)
{
}

SCX_OperatingSystem_Class_Provider::~SCX_OperatingSystem_Class_Provider()
{
}

void SCX_OperatingSystem_Class_Provider::Load(
        Context& context)
{
    SCX_PEX_BEGIN
    {
        SCXThreadLock lock(ThreadLockHandleGet(L"SCXCore::OSProvider::Lock"));
        SCXCore::g_OSProvider.Load();
        SCXCore::g_RunAsProvider.Load();

        // Notify that we don't wish to unload
        MI_Result r = context.RefuseUnload();
        if ( MI_RESULT_OK != r )
        {
            SCX_LOGWARNING(SCXCore::g_OSProvider.GetLogHandle(),
                StrAppend(L"SCX_OperatingSystem_Class_Provider::Load() refuses to not unload, error = ", r));
        }

        context.Post(MI_RESULT_OK);
    }
    SCX_PEX_END( L"SCX_OperatingSystem_Class_Provider::Load", SCXCore::g_OSProvider.GetLogHandle() );
}

void SCX_OperatingSystem_Class_Provider::Unload(
        Context& context)
{
    SCX_PEX_BEGIN
    {
        SCXThreadLock lock(ThreadLockHandleGet(L"SCXCore::OSProvider::Lock"));
        SCXCore::g_OSProvider.Unload();
        SCXCore::g_RunAsProvider.Unload();
        context.Post(MI_RESULT_OK);
    }
    SCX_PEX_END( L"SCX_OperatingSystem_Class_Provider::Unload", SCXCore::g_OSProvider.GetLogHandle() );
}

void SCX_OperatingSystem_Class_Provider::EnumerateInstances(
    Context& context,
    const String& nameSpace,
    const PropertySet& propertySet,
    bool keysOnly,
    const MI_Filter* filter)
{
    SCX_PEX_BEGIN
    {
        SCXThreadLock lock(ThreadLockHandleGet(L"SCXCore::OSProvider::Lock"));

        // Refresh the collection
        SCXHandle<OSEnumeration> osEnum = SCXCore::g_OSProvider.GetOS_Enumerator();
        SCXHandle<MemoryEnumeration> memEnum = SCXCore::g_OSProvider.GetMemory_Enumerator();
        osEnum->Update();
        memEnum->Update();

        SCX_OperatingSystem_Class inst;
        EnumerateOneInstance( context, inst, keysOnly, osEnum->GetTotalInstance(), memEnum->GetTotalInstance() );
        context.Post(MI_RESULT_OK);
    }
    SCX_PEX_END( L"SCX_OperatingSystem_Class_Provider::EnumerateInstances", SCXCore::g_OSProvider.GetLogHandle() );
}

void SCX_OperatingSystem_Class_Provider::GetInstance(
    Context& context,
    const String& nameSpace,
    const SCX_OperatingSystem_Class& instanceName,
    const PropertySet& propertySet)
{
    SCX_PEX_BEGIN
    {
        SCXThreadLock lock(ThreadLockHandleGet(L"SCXCore::OSProvider::Lock"));

        // Was have a nasty 4-part key (on Redhat, it looks like this):
        //   [Key] Name=Red Hat Distribution
        //   [Key] CSCreationClassName=SCX_ComputerSystem
        //   [Key] CSName=jeffcof64-rhel6-01.scx.com
        //   [Key] CreationClassName=SCX_OperatingSystem
        // Considered returning our one instance without validation, but that's not following the rules
        //
        // Look up the values of the two non-fixed keys

        std::string osName = StrToMultibyte(SCXCore::g_OSProvider.GetOSTypeInfo()->GetOSName(true)).c_str();
        std::string csName;
        try {
            NameResolver mi;
            csName = StrToMultibyte(mi.GetHostDomainname()).c_str();
        } catch (SCXException& e) {
            SCX_LOGWARNING(SCXCore::g_OSProvider.GetLogHandle(), StrAppend(
                               StrAppend(L"Can't read host/domainname because ", e.What()),
                               e.Where()));
        }

        // Now compare (case insensitive for the class names, case sensitive for the others)
        if ( 0 != strcasecmp("SCX_ComputerSystem", instanceName.CSCreationClassName_value().Str())
             || 0 != strcasecmp("SCX_OperatingSystem", instanceName.CreationClassName_value().Str())
             || 0 != strcmp(osName.c_str(), instanceName.Name_value().Str())
             || 0 != strcmp(csName.c_str(), instanceName.CSName_value().Str()))
        {
            context.Post(MI_RESULT_NOT_FOUND);
            return;
        }

        //
        // We have a match, so return the instance
        //

        // Refresh the collection
        SCXHandle<OSEnumeration> osEnum = SCXCore::g_OSProvider.GetOS_Enumerator();
        SCXHandle<MemoryEnumeration> memEnum = SCXCore::g_OSProvider.GetMemory_Enumerator();
        osEnum->Update();
        memEnum->Update();

        SCX_OperatingSystem_Class inst;
        EnumerateOneInstance( context, inst, false, osEnum->GetTotalInstance(), memEnum->GetTotalInstance() );
        context.Post(MI_RESULT_OK);
    }
    SCX_PEX_END( L"SCX_OperatingSystem_Class_Provider::GetInstance", SCXCore::g_OSProvider.GetLogHandle() );
}

void SCX_OperatingSystem_Class_Provider::CreateInstance(
    Context& context,
    const String& nameSpace,
    const SCX_OperatingSystem_Class& newInstance)
{
    context.Post(MI_RESULT_NOT_SUPPORTED);
}

void SCX_OperatingSystem_Class_Provider::ModifyInstance(
    Context& context,
    const String& nameSpace,
    const SCX_OperatingSystem_Class& modifiedInstance,
    const PropertySet& propertySet)
{
    context.Post(MI_RESULT_NOT_SUPPORTED);
}

void SCX_OperatingSystem_Class_Provider::DeleteInstance(
    Context& context,
    const String& nameSpace,
    const SCX_OperatingSystem_Class& instanceName)
{
    context.Post(MI_RESULT_NOT_SUPPORTED);
}

void SCX_OperatingSystem_Class_Provider::Invoke_RequestStateChange(
    Context& context,
    const String& nameSpace,
    const SCX_OperatingSystem_Class& instanceName,
    const SCX_OperatingSystem_RequestStateChange_Class& in)
{
    context.Post(MI_RESULT_NOT_SUPPORTED);
}

void SCX_OperatingSystem_Class_Provider::Invoke_Reboot(
    Context& context,
    const String& nameSpace,
    const SCX_OperatingSystem_Class& instanceName,
    const SCX_OperatingSystem_Reboot_Class& in)
{
    context.Post(MI_RESULT_NOT_SUPPORTED);
}

void SCX_OperatingSystem_Class_Provider::Invoke_Shutdown(
    Context& context,
    const String& nameSpace,
    const SCX_OperatingSystem_Class& instanceName,
    const SCX_OperatingSystem_Shutdown_Class& in)
{
    context.Post(MI_RESULT_NOT_SUPPORTED);
}

void SCX_OperatingSystem_Class_Provider::Invoke_ExecuteCommand(
    Context& context,
    const String& nameSpace,
    const SCX_OperatingSystem_Class& instanceName,
    const SCX_OperatingSystem_ExecuteCommand_Class& in)
{
    SCXCoreLib::SCXLogHandle log = SCXCore::g_RunAsProvider.GetLogHandle();

    SCX_PEX_BEGIN
    {
        SCXCoreLib::SCXThreadLock lock(SCXCoreLib::ThreadLockHandleGet(L"SCXCore::RunAsProvider::Lock"));
        SCX_LOGTRACE( log, L"SCX_OperatingSystem_Class_Provider::Invoke_ExecuteCommand" )

        // Parameters (from MOF file):
        //   [IN] string Command, 
        //   [OUT] sint32 ReturnCode, 
        //   [OUT] string StdOut, 
        //   [OUT] string StdErr, 
        //   [IN] uint32 timeout,
        //   [IN] string ElevationType (optional)

        // Validate that we have mandatory arguments
        if ( !in.Command_exists() || 0 == strlen(in.Command_value().Str()) || !in.timeout_exists() )
        {
            SCX_LOGTRACE( log, L"Missing arguments to Invoke_ExecuteCommand method" );
            context.Post(MI_RESULT_INVALID_PARAMETER);
            return;
        }

        std::wstring command = StrFromMultibyte( in.Command_value().Str() );
        std::wstring return_out, return_err;

        std::wstring elevation = L"";
        if ( in.ElevationType_exists() )
        {
            elevation = StrToLower( StrFromMultibyte(in.ElevationType_value().Str()) );

            if (elevation != L"sudo" && elevation != L"")
            {
                SCX_LOGTRACE( log, L"Wrong elevation type " + elevation);
                context.Post(MI_RESULT_INVALID_PARAMETER);
                return;
            }
        }

        std::wstring returnOut, returnErr;
        int returnCode;
        bool cmdok;

        SCX_LOGTRACE( log, L"SCX_OperatingSystem_Class_Provider::Invoke_ExecuteCommand - Executing command: " + command);
        cmdok = SCXCore::g_RunAsProvider.ExecuteCommand(command, returnOut, returnErr, returnCode, in.timeout_value(), elevation);

        // Pass the results back up the chain

        SCX_OperatingSystem_ExecuteCommand_Class inst;

        inst.ReturnCode_value( returnCode );
        inst.StdOut_value( StrToMultibyte(returnOut).c_str() );
        inst.StdErr_value( StrToMultibyte(returnErr).c_str() );
        inst.MIReturn_value( cmdok );
        context.Post(inst);
        context.Post(MI_RESULT_OK);
    }
    SCX_PEX_END( L"SCX_OperatingSystem_Class_Provider::Invoke_ExecuteCommand", log );
}

void SCX_OperatingSystem_Class_Provider::Invoke_ExecuteShellCommand(
    Context& context,
    const String& nameSpace,
    const SCX_OperatingSystem_Class& instanceName,
    const SCX_OperatingSystem_ExecuteShellCommand_Class& in)
{
    SCXCoreLib::SCXLogHandle log = SCXCore::g_RunAsProvider.GetLogHandle();

    SCX_PEX_BEGIN
    {
        SCXCoreLib::SCXThreadLock lock(SCXCoreLib::ThreadLockHandleGet(L"SCXCore::RunAsProvider::Lock"));
        SCX_LOGTRACE( log, L"SCX_OperatingSystem_Class_Provider::Invoke_ExecuteShellCommand" )

        // Parameters (from MOF file):
        //   [IN] string Command, 
        //   [OUT] sint32 ReturnCode, 
        //   [OUT] string StdOut, 
        //   [OUT] string StdErr, 
        //   [IN] uint32 timeout,
        //   [IN] string ElevationType (optional)

        // Validate that we have mandatory arguments
        if ( !in.Command_exists() || 0 == strlen(in.Command_value().Str()) || !in.timeout_exists() )
        {
            SCX_LOGTRACE( log, L"Missing arguments to Invoke_ExecuteShellCommand method" );
            context.Post(MI_RESULT_INVALID_PARAMETER);
            return;
        }

        std::wstring command = StrFromMultibyte( in.Command_value().Str() );
        std::wstring return_out, return_err;

        std::wstring elevation = L"";
        if ( in.ElevationType_exists() )
        {
            elevation = StrToLower( StrFromMultibyte(in.ElevationType_value().Str()) );

            if (elevation != L"sudo" && elevation != L"")
            {
                SCX_LOGTRACE( log, L"Wrong elevation type " + elevation);
                context.Post(MI_RESULT_INVALID_PARAMETER);
                return;
            }
        }

        std::wstring returnOut, returnErr;
        int returnCode;
        bool cmdok;

        SCX_LOGTRACE( log, L"SCX_OperatingSystem_Class_Provider::Invoke_ExecuteShellCommand - Executing command: " + command);
        cmdok = SCXCore::g_RunAsProvider.ExecuteShellCommand(command, returnOut, returnErr, returnCode, in.timeout_value(), elevation);

        // Pass the results back up the chain

        SCX_OperatingSystem_ExecuteShellCommand_Class inst;

        inst.ReturnCode_value( returnCode );
        inst.StdOut_value( StrToMultibyte(returnOut).c_str() );
        inst.StdErr_value( StrToMultibyte(returnErr).c_str() );
        inst.MIReturn_value( cmdok );
        context.Post(inst);
        context.Post(MI_RESULT_OK);
    }
    SCX_PEX_END( L"SCX_OperatingSystem_Class_Provider::Invoke_ExecuteShellCommand", log );
}

void SCX_OperatingSystem_Class_Provider::Invoke_ExecuteScript(
    Context& context,
    const String& nameSpace,
    const SCX_OperatingSystem_Class& instanceName,
    const SCX_OperatingSystem_ExecuteScript_Class& in)
{
    SCXCoreLib::SCXLogHandle log = SCXCore::g_RunAsProvider.GetLogHandle();

    SCX_PEX_BEGIN
    {
        SCXCoreLib::SCXThreadLock lock(SCXCoreLib::ThreadLockHandleGet(L"SCXCore::RunAsProvider::Lock"));
        SCX_LOGTRACE( log, L"SCX_OperatingSystem_Class_Provider::Invoke_ExecuteScript" )

        // Parameters (from MOF file):
        //   [IN] string Script, 
        //   [IN] string Arguments, 
        //   [OUT] sint32 ReturnCode, 
        //   [OUT] string StdOut, 
        //   [OUT] string StdErr, 
        //   [IN] uint32 timeout, 
        //   [IN] string ElevationType (optional)

        // Validate that we have mandatory arguments
        if ( !in.Script_exists() || 0 == strlen(in.Script_value().Str())
             || !in.Arguments_exists() || !in.timeout_exists() )
        {
            SCX_LOGTRACE( log, L"Missing arguments to Invoke_ExecuteScript method" );
            context.Post(MI_RESULT_INVALID_PARAMETER);
            return;
        }

        std::wstring elevation = L"";
        if ( in.ElevationType_exists() )
        {
            elevation = StrToLower( StrFromMultibyte(in.ElevationType_value().Str()) );

            if (elevation != L"sudo" && elevation != L"")
            {
                SCX_LOGTRACE( log, L"Wrong elevation type " + elevation);
                context.Post(MI_RESULT_INVALID_PARAMETER);
                return;
            }
        }

        std::wstring strScript = StrFromMultibyte(in.Script_value().Str());
        std::wstring strArgs = StrFromMultibyte(in.Arguments_value().Str());
        std::wstring returnOut, returnErr;
        int returnCode;

        // Historically, sometimes WSman/Pegasus removed '\r' characters, sometimes not.
        // (Depended on the product.)  Do so here to play it safe.

        std::wstring::size_type pos_slash_r = strScript.find( '\r' );

        while ( std::wstring::npos != pos_slash_r ){
            strScript.erase( pos_slash_r, 1 );
            pos_slash_r = strScript.find( '\r' );
        }

        SCX_LOGTRACE( log, L"SCX_OperatingSystem_Class_Provider::Invoke_ExecuteScript - Executing script: " + strScript);
        bool cmdok = SCXCore::g_RunAsProvider.ExecuteScript(strScript, strArgs, returnOut, returnErr, returnCode, in.timeout_value(), elevation);

        SCX_OperatingSystem_ExecuteScript_Class inst;

        inst.ReturnCode_value( returnCode );
        inst.StdOut_value( StrToMultibyte(returnOut).c_str() );
        inst.StdErr_value( StrToMultibyte(returnErr).c_str() );
        inst.MIReturn_value( cmdok );
        context.Post(inst);
        context.Post(MI_RESULT_OK);
    }
    SCX_PEX_END( L"SCX_OperatingSystem_Class_Provider::Invoke_ExecuteShellCommand", log );
}

MI_END_NAMESPACE
