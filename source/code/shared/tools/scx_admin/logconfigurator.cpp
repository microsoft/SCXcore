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
#include <scxcorelib/scxstream.h>
#include <scxcorelib/scxfile.h>
#include <scxcorelib/scxexception.h>
#include <scxcorelib/scxlogpolicy.h>
#if !defined(SCX_STACK_ONLY)
#include <scxsystemlib/processenumeration.h>
#endif
#include <scxcorelib/scxlogpolicy.h>

#include <signal.h>

#include <iostream>

#include "logconfigurator.h"

using namespace SCXCoreLib;
using namespace std;



/*----------------------------------------------------------------------------*/
/**
    Default Log policy factory

    \returns The default log policy object.
*/
SCXHandle<SCXLogPolicy> DefaultLogPolicyFactory()
{
    return SCXHandle<SCXLogPolicy>(new SCXLogPolicy());
}

//! internal helper function
///    \param[in,out] buf       stream for configuration writing
void BackendSection::PrintModules(std::wostringstream& buf) const
{
    for ( MapModules::const_iterator it = m_mapModules.begin(); it != m_mapModules.end(); it++ ){
        buf << L"MODULE: " << it->first << L" " << SCXLogConfigReader_SeverityToString(it->second) << L"\n";
    }
}

void BackendSectionFile::Print(std::wostringstream& buf) const
{
    buf << L"FILE (\n"
            L"PATH: " << m_strPath << L"\n";

    BackendSection::PrintModules(buf);
    
    buf << L")\n";
}

void BackendSectionStdout::Print(std::wostringstream& buf) const
{
    buf << L"STDOUT (\n";

    BackendSection::PrintModules(buf);
    
    buf << L")\n";
}

///////////////////////////////////////////////////////////////////////////////////////

/// default ctor with dependency injection
SCX_LogConfigurator::SCX_LogConfigurator():
    m_oConfigFileName( DefaultLogPolicyFactory()->GetConfigFileName() )
{
    LoadAndValidate( true );
}

/// ctor with dependency injection
/// \param[in] oConfigFileName - name of the file with configuration
SCX_LogConfigurator::SCX_LogConfigurator(const SCXFilePath& oConfigFileName):
    m_oConfigFileName( oConfigFileName )
{
    LoadAndValidate( true );

}


SCX_LogConfigurator::~SCX_LogConfigurator()
{
}

/*----------------------------------------------------------------------------*/
/**
    helper function to load config file

    \param[in] bCreateImplicitEntries - if bCreateImplicitEntries is set, it emulates core functionality to create a default FILE backend if no config/invalid config is provided

*/ 
bool SCX_LogConfigurator::LoadAndValidate( bool bCreateImplicitEntries )
{
    SCXLogConfigReader<BackendSection, SCX_LogConfigurator> oConfigReader;
    
    bool validConfig = oConfigReader.ParseConfigFile(
        m_oConfigFileName, this);

    if ( !validConfig && bCreateImplicitEntries ) {
            SCXHandle<BackendSection> defaultBackend(
                new BackendSectionFile() );
            
            defaultBackend->SetProperty( L"PATH", DefaultLogPolicyFactory()->GetDefaultLogFileName() );

            SetSeverityThreshold(defaultBackend, L"", DefaultLogPolicyFactory()->GetDefaultSeverityThreshold() );
            Add( defaultBackend );
    }

    return validConfig;
}

/*----------------------------------------------------------------------------*/
/**
    sets given severity to the given module/section
       \param[in] backend - backend to update
       \param[in] module - module to update
       \param[in] newThreshold - new severity
*/ 
bool SCX_LogConfigurator::SetSeverityThreshold(SCXHandle<BackendSection> backend,
                                                  const std::wstring& module,
                                                  SCXLogSeverity newThreshold)
{
    return backend->SetModuleSeverity( module, newThreshold);
}

/*----------------------------------------------------------------------------*/
/**
    creates a new backend section of required type (FILE/STDOUT)
       \param[in] name - name of backend section from config file
*/ 
SCXHandle<BackendSection> SCX_LogConfigurator::Create(const std::wstring& name)
{
    SCXHandle<BackendSection> backend(0);
    if (L"FILE (" == name)
    {
        backend = new BackendSectionFile();
    }
    if (L"STDOUT (" == name)
    {
        backend = new BackendSectionStdout();
    }

    if ( backend != NULL )
        SetSeverityThreshold(backend, L"", DefaultLogPolicyFactory()->GetDefaultSeverityThreshold());
    
    return backend;
}

/*----------------------------------------------------------------------------*/
/**
    adds a new backend, after "reader" verifies that it's initialized properly
       \param[in] backend - new backend to add
*/ 
void SCX_LogConfigurator::Add( SCXHandle<BackendSection> backend )
{
    m_mapConfig[backend->GetID()] = backend;
}


/*----------------------------------------------------------------------------*/
/**
    saves the changes; may throw exception in case of error
    \returns true if ok
    throws SCXAdminException in case of error
    
*/ 
bool SCX_LogConfigurator::Save()
{
    std::wostringstream buf;
    Print( buf );

    try {
        SCXHandle<std::fstream> fs = SCXFile::OpenFstream(m_oConfigFileName, std::ios_base::out);

        (*fs) << StrToMultibyte(buf.str());
    } catch ( SCXException& e ) {
      throw SCXAdminException(L"unable to update file;\n" + e.What(), SCXSRCLOCATION);
    }

    return true;
}

bool SCX_LogConfigurator::LogRotate()
{
#if !defined(SCX_STACK_ONLY) 
    SCXSystemLib::ProcessEnumeration::SendSignalByName( L"scxcimprovagt", SIGCONT);
#else
#if defined(linux)
    system("ps -A -o pid,comm | awk '$2~/scxcimprovagt/{print $1}' | xargs -r kill -s SIGCONT");
#else
    system("ps -A -o pid,comm | awk '$2~/scxcimprovagt/{print $1}' | xargs kill -s SIGCONT");
#endif
#endif
    return true;
}

bool SCX_LogConfigurator::Print(std::wostringstream& buf) const
{
    // print all entries
    for ( MapBackends::const_iterator it = m_mapConfig.begin(); it != m_mapConfig.end(); it++ ){
        it->second->Print( buf );
        buf << L"\n";
    }

    return true;
}

bool SCX_LogConfigurator::Reset()
{
    for ( MapBackends::iterator it = m_mapConfig.begin(); it != m_mapConfig.end(); it++ ){
        it->second->Clear();
    }

    Save();
    return true;
}


/*----------------------------------------------------------------------------*/
/**
    Maps the admin-API logLevel to logfile-native level and saves file
    
    \param       [in] logLevel - The level to set, defined in the admin API 
    \returns     true if success, false if not supported

    Implementation of method in the Admin API.
    
*/
bool SCX_LogConfigurator::Set(LogLevelEnum logLevel)
{
    for ( MapBackends::iterator it = m_mapConfig.begin(); it != m_mapConfig.end(); it++ ){
        it->second->Clear();
        it->second->SetModuleSeverity( L"", 
            logLevel == eLogLevel_Errors ? eWarning :
            logLevel == eLogLevel_Intermediate ? eInfo :
                logLevel == eLogLevel_Verbose ? eTrace : eWarning );
    }

    Save();
    return true;
}

/*----------------------------------------------------------------------------*/
/**
    helper function to parse section/module names encoded in command line parameter
    and creates a new backend section
       \param[in] name - encoded name, like FILE:/var/myfile:core.pal
       \param[out] entryID - backend entry id
       \param[out] moduleID - module id
       \param[out] new_backend - newly created section
       throws SCXAdminException in case of error
*/ 
void SCX_LogConfigurator::GetEntryModuleID( 
    const std::wstring& name, 
    std::wstring& entryID, 
    std::wstring& moduleID, 
    SCXHandle<BackendSection> &new_backend )
{
    vector <  wstring >  tokens;
    StrTokenizeStr(name, tokens, L":", true);

    if ( tokens.size() < 1 || tokens.size() > 3 )
        throw SCXAdminException( wstring(L"invalid entry id ") + name, SCXSRCLOCATION );

    tokens[0] = StrToUpper(tokens[0]);

    if ( tokens[0] == L"FILE" ){
        if ( tokens.size() < 2 )
            throw SCXAdminException( wstring(L"missing parameter for FILE entry id: path is expected "), SCXSRCLOCATION );

        entryID = wstring(L"FILE.") + tokens[1];
        
        if ( tokens.size() > 2 )
            moduleID = tokens[2];

        new_backend = Create(L"FILE (");
        new_backend->SetProperty( L"PATH", tokens[1] );
        
    } else if ( tokens[0] == L"STDOUT" ){
        entryID = tokens[0];
        
        if ( tokens.size() > 1 )
            moduleID = tokens[1];

        new_backend = Create(L"STDOUT (");
    } else {
        throw SCXAdminException( wstring(L"unknown entry id ") + name, SCXSRCLOCATION );
    }
    
}

/*----------------------------------------------------------------------------*/
/**
    sets given severity to the given module/section
       \param[in] name - property name
       \param[in] value - property value
*/ 
void SCX_LogConfigurator::Set( const std::wstring& name, const std::wstring& value )
{
    m_mapConfig.clear();

    LoadAndValidate(false);  // do not create the default 
    
    // parse the name to get backen/module pair:
    wstring entryID, moduleID;
    SCXHandle<BackendSection> new_backend;

    GetEntryModuleID( name, entryID, moduleID, new_backend );
    
    MapBackends::iterator it = m_mapConfig.find( entryID );
    if ( it != m_mapConfig.end() )
        new_backend = it->second;
    else
        m_mapConfig[entryID] = new_backend;

    SCXLogSeverity severity = SCXLogConfigReader_TranslateSeverityString( StrToUpper(value) );
    if (severity == eNotSet)
    {
        throw SCXAdminException( L"invalid severity string: " + value, SCXSRCLOCATION );
    }

    SetSeverityThreshold(new_backend, moduleID, severity );

    Save();
}

/*----------------------------------------------------------------------------*/
/**
    resets given section to default level (info)

    \param[in] name - property name

*/ 
void SCX_LogConfigurator::Reset( const std::wstring& name )
{
    LoadAndValidate(true);  // create the default one if needed
    
    // parse the name to get backen/module pair:
    wstring entryID, moduleID;
    SCXHandle<BackendSection> new_backend;
    GetEntryModuleID( name, entryID, moduleID, new_backend );
    
    MapBackends::iterator it = m_mapConfig.find( entryID );
    if ( it != m_mapConfig.end() )
        new_backend = it->second;
    else
        throw SCXAdminException(wstring(L" entry ") + name + L" was not found", SCXSRCLOCATION );

    new_backend->Clear();

    Save();

}

/*----------------------------------------------------------------------------*/
/**
    removes section from config file
       \param[in] name - property name
*/ 
void SCX_LogConfigurator::Remove( const std::wstring& name )
{
    LoadAndValidate(true);  // create the default one if needed
    
    // parse the name to get backen/module pair:
    wstring entryID, moduleID;
    SCXHandle<BackendSection> new_backend;

    GetEntryModuleID( name, entryID, moduleID, new_backend );
    
    MapBackends::iterator it = m_mapConfig.find( entryID );
    if ( it == m_mapConfig.end() )
        throw SCXAdminException(wstring(L" entry ") + name + L" was not found", SCXSRCLOCATION );

    m_mapConfig.erase( it );

    Save();
}

/*----------------------------E-N-D---O-F---F-I-L-E---------------------------*/
