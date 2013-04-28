/*----------------------------------------------------------------------------
  Copyright (c) Microsoft Corporation.  All rights reserved.
*/
/**
   \file

   \brief      scx admin config API for SCX.

   \date       8/27/2008

*/
#ifndef _CMD_PARSER_H
#define _CMD_PARSER_H

#include <scxcorelib/scxcmn.h>
#include <scxcorelib/scxexception.h>

#include <iostream>
#include <vector>
#include <string>
#include "admin_api.h"

/// helper define that returns number of elements in static array
#define DIM(x) (sizeof(x)/sizeof((x)[0]))


namespace SCX_Admin {

/*----------------------------------------------------------------------------*/
/**
   struct to store output result from "parse" function
   that's the direct translation from one command line command
   with all required options set (including default values)
   
*/ 
struct Operation {
    //! operation type
    enum enumOperationType {
        eOpType_Unknown,
        eOpType_GlobalOption_Quiet,
        eOpType_Global_Usage,
        
#if !defined(SCX_STACK_ONLY)
        eOpType_Config_List,
        eOpType_Config_Set,
        eOpType_Config_Reset,
#endif        
        eOpType_Log_List,
        eOpType_Log_Rotate,
        eOpType_Log_Reset,
        eOpType_Log_Set,
        eOpType_Log_Prov_Reset,
        eOpType_Log_Prov_Set,
        eOpType_Log_Prov_Remove,

        eOpType_Show_Version,

        eOpType_Svc_Start,
        eOpType_Svc_Stop,
        eOpType_Svc_Restart,
        eOpType_Svc_Status
    };

    //! scope
    enum enumComponentType {
        eCompType_Unknown,
        eCompType_Default,  // not set explicitly
        eCompType_All,
        eCompType_CIMom,
        eCompType_Provider
    };

    //! default ctor
    Operation() : m_eType(eOpType_Unknown), m_eComponent(eCompType_Unknown), m_eLogLevel(SCX_AdminLogAPI::eLogLevel_Verbose) {}
    
    // data
    enumOperationType   m_eType;        ///< operation type
    enumComponentType   m_eComponent;   ///< operation scope
    // name/value pair or just name
    std::wstring        m_strName;      ///< name in "name/value" pair (optional)
    std::wstring        m_strValue;     ///< value in "name/value" pair (optional)
    SCX_AdminLogAPI::LogLevelEnum   m_eLogLevel;    ///< required log level (optional)
    
};

/*----------------------------------------------------------------------------*/
/**
   helper class to encode information about one command line argument
   
*/ 
class Argument {
public:
    /// command line argument type 
    enum enumArgType { eString, eComponent, eLogLevel, ePair, eName };

    /**
       default ctor
        \param[in] eType  type of argument
        \param[in] bOptional flag if argument is optional
        \param[in] str  string value of argument (for string type)
       
    */ 
    Argument( enumArgType eType, bool bOptional, std::wstring str = std::wstring() ) : 
        m_eType(eType), m_bOptional(bOptional), m_strString(str) {}

    bool DoesMatch( std::wstring str, int& pos, Operation& op );
    static  Operation::enumComponentType Str2Component( std::wstring str );
    
    
    enumArgType     m_eType;        ///< type of argument
    bool            m_bOptional;    ///< flag if givne parameter is optional
    std::wstring    m_strString;    ///< exact string value, like "-log-list"; for "string" type only
};


/*----------------------------------------------------------------------------*/
/**
   helper class to store information about one command line command.
   it usually consists of several arguments, some of them may be optional
   
*/ 
class Command {
public:
    /// ctor to create a new command with given arguments
    Command( const std::vector< Argument >& aArguments, Operation::enumOperationType eOperationType ):
        m_aArguments(aArguments), m_eOperationType(eOperationType) {}

    bool DoesMatch( int argc, const char *argv[], int& pos, Operation& op );
    bool HasMandatoryAfter( unsigned int pos ) const;

    std::vector< Argument > m_aArguments;               ///< arguments
    Operation::enumOperationType   m_eOperationType;    ///< resulting operation type
};


bool ParseAllParameters( int argc, const char *argv[], std::vector< Operation >& operations, std::wstring& error_msg );


}
#endif /* _ADMIN_API_H */

