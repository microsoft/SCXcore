/*----------------------------------------------------------------------------
  Copyright (c) Microsoft Corporation.  All rights reserved.
*/
/**
   \file

   \brief      scx configuration tool for SCX.

   \date       8/22/2008

*/

#include <scxcorelib/scxcmn.h>
#include <scxcorelib/scxexception.h>
#include <scxcorelib/scxfilepath.h>
#include <scxcorelib/stringaid.h>
#include <scxcorelib/scxfilepath.h>
#include <scxcorelib/scxexception.h>
#include <scxcorelib/scxlogpolicy.h>


#include <iostream>

#include "admin_api.h"
#include "buildversion.h"
#include "cimconfigurator.h"
#include "cmdparser.h"
#include "logconfigurator.h"
#if !defined(SCX_STACK_ONLY)
#include "runasadminprovider.h"
#endif
#include "servicecontrol.h"

using namespace SCX_Admin;
using namespace SCXCoreLib;
using namespace std;

// Global Data
static SCX_LogConfigurator     g_oLogConfigurator;      ///< scx core log configurator
static SCX_CimConfigurator     g_oCIMConfigurator;      ///< open-pegasus configurator
static bool                    g_bQuiet = false;        ///< global option: quiet mode

static void usage(const char * name, int exitValue);
static void show_version();
static void ListHandler( const char * name, const Operation& params );
static void LogRotateHandler( const char * name, const Operation& params );
static void LogResetHandler( const char * name, const Operation& params );
static void LogSetHandler( const char * name, const Operation& params );
static void LogProviderReset( const Operation& params );
static void LogProviderSet( const Operation& params );
static void LogProviderRemove( const Operation& params );
static vector<SCX_AdminLogAPI*> GetLogConfigurators( Operation::enumComponentType eComponent );

#if !defined(SCX_STACK_ONLY)
static void ListConfig();
static void SetConfig( const Operation& params );
static void ResetConfig( const Operation& params );
#endif

static void SvcManagement( const Operation& params );

/*----------------------------------------------------------------------------*/
/**
   Log policy specific to scxadmin with its own config file name and default log file name
*/
class SCXAdminLogPolicy : public SCXLogPolicy
{
public:
    /**
       Virtual destructor.
    */
    virtual ~SCXAdminLogPolicy() {}

    /**
       Get the path of the log config file.
       \returns the path of the log config file.
    */
    virtual SCXFilePath GetConfigFileName() const
    {
#if defined(WIN32)
        return SCXFilePath(L"C:\\scxadminlog.conf");
#elif defined(SCX_UNIX)
        return SCXFilePath(L"/etc/opt/microsoft/scx/conf/scxadminlog.conf");
#endif
    }

    /**
       If no config is specified, then log output will be written
       to the file specified by this method.
       \returns Path to the default log file.
    */
    virtual SCXFilePath GetDefaultLogFileName() const
    {
#if defined(WIN32)
        return SCXFilePath(L"C:\\scxadmin.log");
#elif defined(SCX_UNIX)
        return SCXFilePath(L"/var/opt/microsoft/scx/log/scxadmin.log");
#endif
    }
};

/*----------------------------------------------------------------------------*/
/**
    Log policy factory for scxadmin.

    \returns The log policy object.
*/
SCXCoreLib::SCXHandle<SCXCoreLib::SCXLogPolicy> CustomLogPolicyFactory()
{
    return SCXHandle<SCXLogPolicy>(new SCXAdminLogPolicy());
}

/*----------------------------------------------------------------------------*/
/**
   scx_admin(main) function.

   \param argc size of \a argv[]
   \param argv array of string pointers from the command line.
   \returns 0 on success, otherwise, 1 on error.

   Usage: 
   Result Code
   \n  0  success
   \n >1  an error occured while executing the command.

*/
int scx_admin(int argc, const char *argv[])
{
    bool bOverrideStatus = false;

    // If no arguments, show usage help.
    if(1 == argc)
    {
        usage(argv[0], 0);
    }

    std::vector< Operation > operations;
    std::wstring error_msg;

    // should be ok to parse        
    if ( !ParseAllParameters( argc-1, argv+1, operations, error_msg ) ){
        wcout << error_msg << L"\n";
        usage(argv[0], 1);
    }

    for ( unsigned int i = 0; i < operations.size(); i++ ){
        switch ( operations[i].m_eType ) {
            default:
            case Operation::eOpType_Unknown:
                wcout << L"not supported yet...\n";
                return 1;

            case Operation::eOpType_Svc_Restart:
            case Operation::eOpType_Svc_Start:
            case Operation::eOpType_Svc_Stop:
                SvcManagement( operations[i] );
                break;

            case Operation::eOpType_Svc_Status:
                SvcManagement( operations[i] );
                bOverrideStatus = true;
                break;

#if !defined(SCX_STACK_ONLY)

            case Operation::eOpType_Config_List:
                ListConfig();
                break;
                
            case Operation::eOpType_Config_Set:
                SetConfig( operations[i] );
                break;
                
            case Operation::eOpType_Config_Reset:
                ResetConfig( operations[i] );
                break;

#endif
                
            case Operation::eOpType_Log_Prov_Reset:
                LogProviderReset( operations[i] );
                break;
            case Operation::eOpType_Log_Prov_Set:
                LogProviderSet( operations[i] );
                break;
            case Operation::eOpType_Log_Prov_Remove:
                LogProviderRemove( operations[i] );
                break;
                
            case Operation::eOpType_Global_Usage:
                usage(argv[0], 0);
                break;
                
            case Operation::eOpType_GlobalOption_Quiet:
                g_bQuiet = true;
                break;
                
            case Operation::eOpType_Log_List:
                ListHandler(argv[0], operations[i] );
                break;
                
            case Operation::eOpType_Log_Rotate:
                LogRotateHandler(argv[0], operations[i] );
                break;
                
            case Operation::eOpType_Log_Reset:
                LogResetHandler(argv[0], operations[i] );
                break;
                
            case Operation::eOpType_Log_Set:
                LogSetHandler(argv[0], operations[i] );
                break;

            case Operation::eOpType_Show_Version:
                show_version();
                break;
        }
    }

    // If we're supposed to override status with state if cimom, do so
    if (bOverrideStatus)
    {
        static SCX_CimomServiceControl  s_CIM;
        return (0 == s_CIM.CountProcessesAlive());
    }

    return 0;
}

/*----------------------------------------------------------------------------*/
/**
   Output a usage message.
   
   \param name Application name (derived from argv[0]).
   \param exitValue Value to return after writing the usage message.
   \return Does not return.
*/
static void usage(char const * const name, int exitValue)
{
    (void) name;

    /*
     * We can't dump 'name' anymore since it will contain a . since it's now hidden
     * (scxadmin is now staged as hidden since we have a helper script to launch it)
     */

    if ( !g_bQuiet) wcout << L"Usage: scxadmin" << L"\n" <<
        "Generic options (for all commands)\n" <<
        "  [-quiet]\tSet quiet mode (no output)\n" <<
        "\n" <<
        "\tGeneral Options\n" <<
        "scxadmin -version\n" <<
        "\n" <<
        "\tService Management\n" <<
        "scxadmin {-start|-stop|-restart|-status}  [all|cimom|provider]\n" <<
        "\n" <<
#if !defined(SCX_STACK_ONLY)
        "\tProviders Management\n" <<
        "scxadmin -config-list {RunAs} \n" <<
        "scxadmin -config-set {RunAs} {CWD=<directory>|ChRootPath=<directory>|AllowRoot={true|false}}\n" <<
        "scxadmin -config-reset {RunAs} [CWD|ChRootPath|AllowRoot]\n" <<
        "\n" <<
#endif
        "\tLog Configuration Management\n" <<
        "scxadmin {-log-list|-log-rotate|-log-reset} [all|cimom|provider]\n" <<
        "scxadmin -log-set [all|cimom|provider] {verbose|intermediate|errors}\n" <<
        "scxadmin -log-set provider {{FILE:<path>|STDOUT}:<module-id>={SUPPRESS|ERROR|WARNING|INFO|TRACE|HYSTERICAL}}\n" <<
        "scxadmin {-log-reset|-log-remove} provider [{FILE:<path>|STDOUT}]\n" <<
        "\n";

    exit(exitValue);
} 

/*----------------------------------------------------------------------------*/
/**
   Output the version string
*/
static void show_version()
{
    if ( !g_bQuiet)
    {
        wcout << L"Version: " << SCX_BUILDVERSION_MAJOR << L"." << SCX_BUILDVERSION_MINOR
              << L"." << SCX_BUILDVERSION_PATCH << L"-" << SCX_BUILDVERSION_BUILDNR
              << L" (" << SCX_BUILDVERSION_STATUS << L" - " << SCX_BUILDVERSION_DATE << "L)\n";
    }

    return;
}

/*----------------------------------------------------------------------------*/
/**
    Handler "-log-list" operation
   \param params - current operation with detailed parameters
*/ 
static void ListHandler( const char * , const Operation& params )
{
    vector<SCX_AdminLogAPI*> logConfigs = GetLogConfigurators( params.m_eComponent );
    std::wostringstream buf;
    
    // print all entries
    for ( unsigned int i = 0; i < logConfigs.size(); i++ ){
        try {
            if ( !logConfigs[i]->Print( buf ) && logConfigs.size() == 1 ){
                if ( !g_bQuiet) wcout << L"operation is not supported\n";
                exit(1);
            }
        } catch ( SCXException& e ) {
            if ( !g_bQuiet) wcout << e.What() << L"\n";
            exit(1);
        }
        buf << L"\n";
    }

    if ( !g_bQuiet) wcout << buf.str() << L"\n";
}

/*----------------------------------------------------------------------------*/
/**
    Handler "-log-rotate" operation
   \param params - current operation with detailed parameters
*/ 
static void LogRotateHandler( const char * , const Operation& params )
{
    vector<SCX_AdminLogAPI*> logConfigs = GetLogConfigurators( params.m_eComponent );
    
    // print all/selected entries
    for ( unsigned int i = 0; i < logConfigs.size(); i++ ){
        try {
            if ( !logConfigs[i]->LogRotate() && logConfigs.size() == 1 ){
                if ( !g_bQuiet) wcout << L"operation is not supported\n";
                exit(1);
            }
        } catch (SCXException& e ) {
            if ( !g_bQuiet) wcout << e.What() << L"\n";
            exit(1);
        }
    }
}

/*----------------------------------------------------------------------------*/
/**
    Handler "-log-reset" operation
   \param params - current operation with detailed parameters
*/ 
static void LogResetHandler( const char * , const Operation& params )
{
    vector<SCX_AdminLogAPI*> logConfigs = GetLogConfigurators( params.m_eComponent );
    
    // reset log-level for all/selected entries
    for ( unsigned int i = 0; i < logConfigs.size(); i++ ){
        try {
            if ( !logConfigs[i]->Reset() && logConfigs.size() == 1 ){
                if ( !g_bQuiet) wcout << L"operation is not supported\n";
                exit(1);
            }
        } catch (SCXException& e ) {
            if ( !g_bQuiet) wcout << e.What() << L"\n";
            exit(1);
        }
    }
}

/*----------------------------------------------------------------------------*/
/**
    Handler "-log-set" operation
   \param params - current operation with detailed parameters
*/ 
static void LogSetHandler( const char * , const Operation& params )
{
    vector<SCX_AdminLogAPI*> logConfigs = GetLogConfigurators( params.m_eComponent );
    
    // set log-level for all/selected entries
    for ( unsigned int i = 0; i < logConfigs.size(); i++ ){
        try {
            if ( !logConfigs[i]->Set(params.m_eLogLevel) && logConfigs.size() == 1 ){
                if ( !g_bQuiet) wcout << L"operation is not supported\n";
                exit(1);
            }
        } catch (SCXException& e ) {
            if ( !g_bQuiet) wcout << e.What() << L"\n";
            exit(1);
        }
    }
}

/*----------------------------------------------------------------------------*/
/**
    Handler "-log-reset provider" operation (provider specific)
   \param params - current operation with detailed parameters
*/ 
static void LogProviderReset( const Operation& params )
{
    try {
        g_oLogConfigurator.Reset(params.m_strName);
    } catch (SCXException& e ) {
        if ( !g_bQuiet) wcout << e.What() << L"\n";
        exit(1);
    }
}

/*----------------------------------------------------------------------------*/
/**
    Handler "-log-set provider" operation (provider specific)
   \param params - current operation with detailed parameters
*/ 
static void LogProviderSet( const Operation& params )
{
    try {
        g_oLogConfigurator.Set(params.m_strName, params.m_strValue);
    } catch (SCXException& e ) {
        if ( !g_bQuiet) wcout << e.What() << L"\n";
        exit(1);
    }
    
}

/*----------------------------------------------------------------------------*/
/**
    Handler "-log-remove provider" operation (provider specific)
   \param params - current operation with detailed parameters
*/ 
static void LogProviderRemove( const Operation& params )
{
    try {
        g_oLogConfigurator.Remove(params.m_strName);
    } catch (SCXException& e ) {
        if ( !g_bQuiet) wcout << e.What() << L"\n";
        exit(1);
    }
}

/*----------------------------------------------------------------------------*/
/**
    helper function that returns array of logs based on the scope of operation
   \param eComponent - required component
   \returns array of log configurator
    
*/ 
static vector<SCX_AdminLogAPI*> GetLogConfigurators( Operation::enumComponentType eComponent )
{
    vector<SCX_AdminLogAPI*> res;

    switch ( eComponent ){
        case Operation::eCompType_All:
        case Operation::eCompType_Default:
            res.push_back( &g_oCIMConfigurator );
            res.push_back( &g_oLogConfigurator );
            break;

        case Operation::eCompType_CIMom:
            res.push_back( &g_oCIMConfigurator );
            break;
            
        case Operation::eCompType_Provider:
            res.push_back( &g_oLogConfigurator );
            break;

        case Operation::eCompType_Unknown:
            break;
           
    }

    return res;
}

/*----------------------------------------------------------------------------*/
/**
    helper function that returns array of service managers based on the scope of operation
   \param eComponent - required component
   \param eOperation - performed operation
   \returns array of services
    
*/ 
static vector<SCX_AdminServiceManagementAPI*> GetSvcManagers( Operation::enumComponentType eComponent, Operation::enumOperationType eOperation )
{
    vector<SCX_AdminServiceManagementAPI*> res;
    static SCX_CimomServiceControl  s_CIM;
    static SCX_ProviderServiceControl s_Provider;

    switch ( eComponent ){
        case Operation::eCompType_All:
        case Operation::eCompType_Default:
            res.push_back( &s_CIM );
            if (eOperation == Operation::eOpType_Svc_Status) {
                res.push_back( &s_Provider );
            }
            break;

        case Operation::eCompType_CIMom:
            res.push_back( &s_CIM );
            break;
            
        case Operation::eCompType_Provider:
            res.push_back( &s_Provider );
            break;

        case Operation::eCompType_Unknown:
            break;
           
    }

    return res;
}

#if !defined(SCX_STACK_ONLY)
/*----------------------------------------------------------------------------*/
/**
    Handler "-config-list" operation
*/ 
void ListConfig()
{
    SCX_RunAsAdminProvider   oCfg;

    std::wostringstream buf;
    
    try {
        if ( !oCfg.Print( buf ) ){
            if ( !g_bQuiet) wcout << L"operation is not supported\n";
            exit(1);
        }
    } catch ( SCXException& e ) {
        if ( !g_bQuiet) wcout << e.What() << L"\n";
        exit(1);
    }
    buf << L"\n";

    if ( !g_bQuiet) wcout << buf.str() << L"\n";
    
}

/*----------------------------------------------------------------------------*/
/**
    Handler "-config-set" operation
   \param params - current operation with detailed parameters
*/ 
static void SetConfig( const Operation& params )
{
    SCX_RunAsAdminProvider   oCfg;

    try {
        if ( !oCfg.Set( params.m_strName, params.m_strValue ) ){
            if ( !g_bQuiet) wcout << L"operation is not supported\n";
            exit(1);
        }
    } catch ( SCXException& e ) {
        if ( !g_bQuiet) wcout << e.What() << L"\n";
        exit(1);
    }
    if ( !g_bQuiet) wcout << L"Remember to restart cimom for changes to take effect" << std::endl;
}

/*----------------------------------------------------------------------------*/
/**
    Handler "-config-reset" operation
   \param params - current operation with detailed parameters
*/ 
static void ResetConfig( const Operation& params )
{
    SCX_RunAsAdminProvider   oCfg;

    try {
        if ( !oCfg.Reset( params.m_strName ) ){
            if ( !g_bQuiet) wcout << L"operation is not supported\n";
            exit(1);
        }
    } catch ( SCXException& e ) {
        if ( !g_bQuiet) wcout << e.What() << L"\n";
        exit(1);
    }
    if ( !g_bQuiet) wcout << L"Remember to restart cimom for changes to take effect" << std::endl;
}

#endif

/*----------------------------------------------------------------------------*/
/**
    Handler for service management operations:
    -status, -start, -stop, -restart
   \param params - current operation with detailed parameters
*/ 
static void SvcManagement( const Operation& params )
{
    vector<SCX_AdminServiceManagementAPI*> mgrs = GetSvcManagers( params.m_eComponent, params.m_eType );

    // print all/selected entries
    for ( unsigned int i = 0; i < mgrs .size(); i++ ){
        try {
            bool bRes = false;
            std::wstring buf;

            switch ( (int)params.m_eType ){
            case Operation::eOpType_Svc_Restart:
                bRes = mgrs[i]->Restart( buf );
                break;
            case Operation::eOpType_Svc_Start:
                bRes = mgrs[i]->Start( buf );
                break;
            case Operation::eOpType_Svc_Stop:
                bRes = mgrs[i]->Stop( buf );
                break;
            case Operation::eOpType_Svc_Status:
                bRes = mgrs[i]->Status( buf );
                break;
            }

            if ( !bRes&& mgrs.size() == 1 ){
                if ( !g_bQuiet) wcout << L"operation is not supported\n";
                exit(1);
            }
            
            if ( !g_bQuiet) 
                wcout << buf << L"\n";
            
        } catch (SCXException& e ) {
            if ( !g_bQuiet) wcout << e.What() << L"\n";
            // It's hard to get the "real" return code, so just return generic error
            exit(1);
        }
    }
}

/*----------------------------------------------------------------------------*/
/**
    main function of the tool
   \param argc size of \a argv[]
   \param argv array of string pointers from the command line.
   \returns 0 on success, otherwise, 1 on error.
*/ 
int main(int argc, const char *argv[])
{
    return scx_admin(argc, argv );
}


