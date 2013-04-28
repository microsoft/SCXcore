/*----------------------------------------------------------------------------
  Copyright (c) Microsoft Corporation.  All rights reserved.
*/
/**
   \file

   \brief      scx admin config API for SCX.

   \date       8/27/2008

*/
#ifndef _ADMIN_API_H
#define _ADMIN_API_H

#include <scxcorelib/scxcmn.h>
#include <scxcorelib/scxexception.h>

#include <iostream>

using namespace SCXCoreLib;
/*----------------------------------------------------------------------------*/
/**
   Admin utility implementation exception for all Errors

   Provide human-readable description of the error and notifies
   that operation is "supported-in-general" but cannot be completed at this time
   
*/ 
class SCXAdminException : public SCXException {
public: 
    /*----------------------------------------------------------------------------*/
    /**
       Ctor
       \param[in] description Description of the internal error
       \param[in] l      Source code location object

    */
    SCXAdminException(std::wstring description, 
                             const SCXCodeLocation& l) : SCXException(l),
                                                         m_strDescription(description)
    {}

    /** (overload)
       Format details of violation
       
    */
    std::wstring What() const { return m_strDescription;}

protected:
    //! Description of internal error
    std::wstring   m_strDescription;
};        


/*----------------------------------------------------------------------------*/
/**
   API to Log-Configuration modules

   Allows to manipulate log configurations for different components in unified way.
   As a generic rule, all functions return "true" for successful operation,
   "false" for unsupported funcitons and throw "SCXAdminException" exception 
   for failed operations
   
*/ 
class SCX_AdminLogAPI {
public:
    //! log level for generic configuration
    enum LogLevelEnum{ 
        eLogLevel_Verbose,
        eLogLevel_Intermediate,
        eLogLevel_Errors
    };

    /** Virtual destructor needed */
    virtual ~SCX_AdminLogAPI() {}

   
    /** Instructs component to rotate the log (close/re-open log files).
        \returns "true" if success, "false" if not supported
    */
    virtual bool LogRotate() = 0;
    
    /** Prints current log configuration of the component into provided stream
        \param[in] buf       stream for configuration writing
        \returns "true" if success, "false" if not supported
        \throws SCXAdminException on failure
    */
    virtual bool Print(std::wostringstream& buf) const = 0;
    
    /** Resets configuration of the component to the default level (installation-time)
        \returns "true" if success, "false" if not supported
        \throws SCXAdminException on failure
    */
    virtual bool Reset() = 0;
    
    /** Changes configuration of the component to the provided level
        \param[in] level       new configuration level
        \returns "true" if success, "false" if not supported
        \throws SCXAdminException on failure
    */
    virtual bool Set(LogLevelEnum level) = 0;
};

/*----------------------------------------------------------------------------*/
/**
   API to Provider-Configuration 

   Allows to manipulate configuration options for different providers in unified way.
   As a generic rule, all functions return "true" for successful operation,
   "false" for unsupported funcitons and throw "SCXAdminException" exception 
   for failed operations
   
*/ 
class SCX_AdminProviderConfigAPI {
public:
    /** Virtual destructor needed */
    virtual ~SCX_AdminProviderConfigAPI(){}

    /** Prints current log configuration of the component into provided stream
        \param[in] buf       stream for configuration writing
        \returns "true" if success, "false" if not supported
        \throws SCXAdminException on failure
    */
    virtual bool Print(std::wostringstream& buf) const = 0;
    
    /** Resets configuration of the component to the default level (installation-time)
        \param[in] name       property name for resetting
        \returns "true" if success, "false" if not supported
        \throws SCXAdminException on failure
    */
    virtual bool Reset( const std::wstring& name ) = 0;
    
    /** Changes configuration of the component with provided name/value pair
        \param[in] name       property name for setting
        \param[in] value      new value
        \returns "true" if success, "false" if not supported
        \throws SCXAdminException on failure
    */
    virtual bool Set(const std::wstring& name, const std::wstring& value) = 0;
    
};


/*----------------------------------------------------------------------------*/
/**
   API to Service management (specific to one service) 

   Allows to perform "start/stop/status" operations for given service
   
*/ 
class SCX_AdminServiceManagementAPI {
public:
    /** Virtual destructor needed */
    virtual ~SCX_AdminServiceManagementAPI(){}

    /** Starts the service
        \param[out] info       string that explains details like "started" 
                                or "is already running" in case of success
        \returns "true" if success, "false" if not supported
        \throws SCXAdminException on failure
    */
    virtual bool Start( std::wstring& info ) const = 0;
    
    /** Stop the service
        \param[out] info       string that explains details like "stopped" 
                                or "was not running" in case of success
        \returns "true" if success, "false" if not supported
        \throws SCXAdminException on failure
    */
    virtual bool Stop( std::wstring& info ) const = 0;
    
    /** Restart the service (stop/start sequence)
        \param[out] info       string that explains details like "stopped" 
                                or "was not running" in case of success
        \returns "true" if success, "false" if not supported
        \throws SCXAdminException on failure
    */
    virtual bool Restart( std::wstring& info ) const = 0;

    /** Returns status of the service
        \param[out] info       string that provides status
        \returns "true" if success, "false" if not supported
        \throws SCXAdminException on failure
    */
    virtual bool Status( std::wstring& info ) const = 0;
};

#endif /* _ADMIN_API_H */
