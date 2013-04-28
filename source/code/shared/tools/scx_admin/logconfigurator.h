/*----------------------------------------------------------------------------
  Copyright (c) Microsoft Corporation.  All rights reserved.
*/
/**
   \file

   \brief      scx configuration tool for SCX.

   \date       8/22/2008

*/
#ifndef LOG_CONFIG_READER_H
#define LOG_CONFIG_READER_H

#include <scxcorelib/scxcmn.h>
#include <scxcorelib/scxexception.h>
#include <scxcorelib/scxfilepath.h>
#include <scxcorelib/stringaid.h>
#include <scxcorelib/scxfilepath.h>
#include <scxcorelib/scxlog.h>
#include "source/code/scxcorelib/util/log/scxlogconfigreader.h"
#include "admin_api.h"


#include <iostream>

/*----------------------------------------------------------------------------*/
/**
   helper abstract class to store information about 
   "backend" section in config file
   
*/ 
class BackendSection {
public:
    //! map to store module/severity information
    typedef std::map< std::wstring, SCXCoreLib::SCXLogSeverity > MapModules;

    virtual ~BackendSection(){}

    /** adds/updates severity for given module
       \param[in] strModule - module name
       \param[in] sev - new severity
        \returns "true" if success, "false" if failed
    */ 
    bool SetModuleSeverity( std::wstring strModule, SCXCoreLib::SCXLogSeverity sev ) {m_mapModules[strModule]=sev; return true;}

    /// removes all "module" entries from the section
    void Clear() {m_mapModules.clear();}

    /** updates special backend-specific property
       \param[in] name - property name
       \param[in] value - new value
        \returns "true" if success, "false" if failed
    */ 
    virtual bool SetProperty( std::wstring name, std::wstring value ) = 0;
    
    //! checks if backend section is initialized and all mandatory parameters were set
    //! \returns "true" if backend section is initialized and all mandatory parameters were set
    virtual bool IsInitialized() const = 0;
    
    //! \returns "id" of the section, compatible with command line argument
    virtual std::wstring GetID() const = 0;
    
    //! prints content of the section to the provided stream
    ///    \param[out] buf       stream for configuration writing
    virtual void    Print(std::wostringstream& buf) const = 0;

protected:
    void    PrintModules(std::wostringstream& buf) const;
    
protected:
    // data
    MapModules m_mapModules;    ///< module/severity map
};

/*----------------------------------------------------------------------------*/
/**
   helper class to store information about "FILE backend" section in config file
   
*/ 
class BackendSectionFile : public BackendSection {
public:
    virtual bool SetProperty( std::wstring name, std::wstring value )
    { 
        if ( name == L"PATH" ){
            m_strPath = value;
            return true;
        }
        return false;
    }
    
    virtual bool IsInitialized() const { return !m_mapModules.empty() && !m_strPath.empty();}
    virtual std::wstring GetID() const {return std::wstring(L"FILE.") + m_strPath;}
    virtual void    Print(std::wostringstream& buf) const;
protected:
    // data
    std::wstring m_strPath;     ///< log file name from FILE backend
};

/*----------------------------------------------------------------------------*/
/**
   helper class to store information about "STDOUT backend" section in config file
   
*/ 
class BackendSectionStdout : public BackendSection {
public:
    virtual bool SetProperty( std::wstring , std::wstring )
    { 
        return false;
    }
    
    virtual bool IsInitialized() const { return !m_mapModules.empty();}
    virtual std::wstring GetID() const {return std::wstring(L"STDOUT");}
    virtual void    Print(std::wostringstream& buf) const;
};


/*----------------------------------------------------------------------------*/
/**
   Implementation of admin-log API for scx core log configuration
   
*/ 
class SCX_LogConfigurator : public SCX_AdminLogAPI {
    
public:
    /// type to store all backends; maps backend id to backend pointer 
    typedef std::map< std::wstring, SCXCoreLib::SCXHandle<BackendSection> > MapBackends;
    SCX_LogConfigurator();
    SCX_LogConfigurator(const SCXFilePath& oConfigFileName);
    ~SCX_LogConfigurator();

    virtual bool LogRotate();
    virtual bool Print(std::wostringstream& buf) const;
    virtual bool Reset();
    virtual bool Set(LogLevelEnum level);

    // "provider-specific" functions:
    void    Set( const std::wstring& name, const std::wstring& value );
    void    Reset( const std::wstring& name );
    void    Remove( const std::wstring& name );

    // funcitons that are used by SCXLogConfigReader
    bool    SetSeverityThreshold(SCXCoreLib::SCXHandle<BackendSection> backend,
                                  const std::wstring& module,
                                  SCXCoreLib::SCXLogSeverity newThreshold);
    SCXCoreLib::SCXHandle<BackendSection>   Create(const std::wstring& name);
    void Add( SCXCoreLib::SCXHandle<BackendSection> backend );

private:
    bool    LoadAndValidate( bool bCreateImplicitEntries );
    bool    Save();
    void    GetEntryModuleID( 
                const std::wstring& name, 
                std::wstring& entryID, 
                std::wstring& moduleID, 
                SCXHandle<BackendSection> &new_backend );

    MapBackends m_mapConfig;        ///< all sections
    SCXFilePath m_oConfigFileName;  ///< file name to store configuration
};

#endif
