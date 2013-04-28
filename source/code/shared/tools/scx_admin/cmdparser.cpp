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


#include <iostream>

#include "cmdparser.h"

using namespace SCXCoreLib;
using namespace std;

namespace SCX_Admin {


/*----------------------------------------------------------------------------*/
/**
   checks if given command line parameter matches this Argument
   it updates "out" parameters only if it matches
   
    \param[in] str command line parameter
    \param[in,out] pos new position 
    \param[in,out] op operation to update with new value/name/type
    \returns true if matches
*/ 
bool Argument::DoesMatch( std::wstring str, int& pos, Operation& op )
{
    switch( m_eType ){
        case eString:
            if ( StrToLower(m_strString) == StrToLower( str ) ){
                pos ++;
                return true;
            }
            break;

        case eComponent:
            if ( Str2Component( StrToLower(str) ) == Operation::eCompType_Unknown )
                break;

            op.m_eComponent = Str2Component( StrToLower(str) );
            pos++;
            return true;

        case eLogLevel:
            str = StrToLower(str);
            if ( L"verbose" == str )
                op.m_eLogLevel = SCX_AdminLogAPI::eLogLevel_Verbose;
            else if ( L"intermediate" == str )
                op.m_eLogLevel = SCX_AdminLogAPI::eLogLevel_Intermediate;
            else if ( L"errors" == str )
                op.m_eLogLevel = SCX_AdminLogAPI::eLogLevel_Errors;
            else
                break;

            pos++;
            return true;
            

        case ePair:
            {   
                vector <  std::wstring > tokens;
                
                StrTokenizeStr(str, tokens, L"=" );
                if ( tokens.size() == 2 ){
                    op.m_strName = tokens[0];
                    op.m_strValue = tokens[1];
                    pos++;
                    return true;
                }
            }
            break;

        case eName:
            op.m_strName = str;
            pos++;
            return true;

        default:
            return false;
    }

    // does not match; return true if optional
    return m_bOptional;
}


/**
   helper function to convert string to component type (scope)
   
    \param[in] str string representation of the scope
    \returns "unknown" if does not match anything or component type
*/ 
Operation::enumComponentType Argument::Str2Component( std::wstring str )
{
    str = StrToLower(str);
    if ( L"all" == str )
        return Operation::eCompType_All;
    else if ( L"cimom" == str )
        return Operation::eCompType_CIMom;
    else if ( L"provider" == str )
        return Operation::eCompType_Provider;

    return Operation::eCompType_Unknown;
}

/**
    this funciton tries to match first "n" cmd parameters with arguments
    skipping optional parameters if needed
    returns true, advances pos and fills in operation if match was found
    
    \param[in] argc - number of arguments
    \param[in] argv - array of arguments
    \param[in,out] pos - current position in the array
    \param[in,out] op - operation to update
    
    \returns true, advances pos and fills in operation if match was found
    
*/
bool Command::DoesMatch( int argc, const char *argv[], int& pos, Operation& op )
{
    // check all arguments that are required for given command
    int new_pos = pos;
    Operation new_op;
    new_op.m_eType = m_eOperationType;
    new_op.m_eComponent = Operation::eCompType_Default;
    
    for ( unsigned int i = 0; i < m_aArguments.size(); i++ ){
        if ( new_pos >= argc && HasMandatoryAfter( i ) )
            return false;   // some parameter is missing

        if ( new_pos >= argc )
            break;  // completed with default params.

        if ( !m_aArguments[i].DoesMatch( StrFromMultibyte(argv[new_pos]), new_pos, new_op ) )
            return false;

    }

    pos = new_pos;
    op = new_op;

    return true;
    
}


/**
    checks if there are any mandatory arguments in array strating with given position
    called when end of command line parameters list is reached
    \param[in] pos - position in the array
    \returns true if found
*/    
    
bool Command::HasMandatoryAfter( unsigned int pos ) const
{
    for ( ; pos < m_aArguments.size(); pos++ ){
        if ( !m_aArguments[pos].m_bOptional )
            return true;
    }
    return false;
}

/*----------------------------------------------------------------------------*/
/**
   internal function that fills in array of supported commands
   it also sets link between "command" and "operation"
   so several commands may result in the same operation: -h == -? == -help
    \param[in,out] commands     array of commands
   
*/ 
static void InitParser( std::vector< Command >& commands )
{
    std::vector< Argument > args;

    // "-quiet"
    args.push_back( Argument( Argument::eString, false, L"-quiet" ) );
    commands.push_back( Command( args, Operation::eOpType_GlobalOption_Quiet ) );
    args.clear();

    args.push_back( Argument( Argument::eString, false, L"-q" ) );
    commands.push_back( Command( args, Operation::eOpType_GlobalOption_Quiet ) );
    args.clear();

    // usage
    args.push_back( Argument( Argument::eString, false, L"-help" ) );
    commands.push_back( Command( args, Operation::eOpType_Global_Usage ) );
    args.clear();

    args.push_back( Argument( Argument::eString, false, L"-h" ) );
    commands.push_back( Command( args, Operation::eOpType_Global_Usage ) );
    args.clear();

    args.push_back( Argument( Argument::eString, false, L"-?" ) );
    commands.push_back( Command( args, Operation::eOpType_Global_Usage ) );
    args.clear();

    args.push_back( Argument( Argument::eString, false, L"-usage" ) );
    commands.push_back( Command( args, Operation::eOpType_Global_Usage ) );
    args.clear();

    // -log-set (provider)
    args.push_back( Argument( Argument::eString, false, L"-log-set" ) );
    args.push_back( Argument( Argument::eString, false, L"provider" ) );
    args.push_back( Argument( Argument::ePair, false ) );
    commands.push_back( Command( args, Operation::eOpType_Log_Prov_Set ) );
    args.clear();

    // -log-reset (provider)
    args.push_back( Argument( Argument::eString, false, L"-log-reset" ) );
    args.push_back( Argument( Argument::eString, false, L"provider" ) );
    args.push_back( Argument( Argument::eName, false ) );
    commands.push_back( Command( args, Operation::eOpType_Log_Prov_Reset ) );
    args.clear();

    // -log-remove (provider)
    args.push_back( Argument( Argument::eString, false, L"-log-remove" ) );
    args.push_back( Argument( Argument::eString, false, L"provider" ) );
    args.push_back( Argument( Argument::eName, true ) );
    commands.push_back( Command( args, Operation::eOpType_Log_Prov_Remove) );
    args.clear();
    
    // -log-list
    args.push_back( Argument( Argument::eString, false, L"-log-list" ) );
    args.push_back( Argument( Argument::eComponent, true ) );
    commands.push_back( Command( args, Operation::eOpType_Log_List ) );
    args.clear();

    // -log-rotate
    args.push_back( Argument( Argument::eString, false, L"-log-rotate" ) );
    args.push_back( Argument( Argument::eComponent, true ) );
    commands.push_back( Command( args, Operation::eOpType_Log_Rotate ) );
    args.clear();
    
    // -log-reset
    args.push_back( Argument( Argument::eString, false, L"-log-reset" ) );
    args.push_back( Argument( Argument::eComponent, true ) );
    commands.push_back( Command( args, Operation::eOpType_Log_Reset ) );
    args.clear();
    
    // -log-set
    args.push_back( Argument( Argument::eString, false, L"-log-set" ) );
    args.push_back( Argument( Argument::eComponent, true ) );
    args.push_back( Argument( Argument::eLogLevel, false ) );
    commands.push_back( Command( args, Operation::eOpType_Log_Set ) );
    args.clear();

#if !defined(SCX_STACK_ONLY)

    // -config-list
    args.push_back( Argument( Argument::eString, false, L"-config-list" ) );
    args.push_back( Argument( Argument::eString, false, L"runas" ) );
    commands.push_back( Command( args, Operation::eOpType_Config_List) );
    args.clear();

    // -config-set
    args.push_back( Argument( Argument::eString, false, L"-config-set" ) );
    args.push_back( Argument( Argument::eString, false, L"runas" ) );
    args.push_back( Argument( Argument::ePair, false ) );
    commands.push_back( Command( args, Operation::eOpType_Config_Set) );
    args.clear();

    // -config-reset
    args.push_back( Argument( Argument::eString, false, L"-config-reset" ) );
    args.push_back( Argument( Argument::eString, false, L"runas" ) );
    args.push_back( Argument( Argument::eName, true ) );
    commands.push_back( Command( args, Operation::eOpType_Config_Reset) );
    args.clear();

#endif

    // -start
    args.push_back( Argument( Argument::eString, false, L"-start" ) );
    args.push_back( Argument( Argument::eComponent, true ) );
    commands.push_back( Command( args, Operation::eOpType_Svc_Start) );
    args.clear();

    // -stop
    args.push_back( Argument( Argument::eString, false, L"-stop" ) );
    args.push_back( Argument( Argument::eComponent, true ) );
    commands.push_back( Command( args, Operation::eOpType_Svc_Stop) );
    args.clear();

    // -restart
    args.push_back( Argument( Argument::eString, false, L"-restart" ) );
    args.push_back( Argument( Argument::eComponent, true ) );
    commands.push_back( Command( args, Operation::eOpType_Svc_Restart) );
    args.clear();

    // -status
    args.push_back( Argument( Argument::eString, false, L"-status" ) );
    args.push_back( Argument( Argument::eComponent, true ) );
    commands.push_back( Command( args, Operation::eOpType_Svc_Status) );
    args.clear();

    // -version
    args.push_back( Argument( Argument::eString, false, L"-version" ) );
    commands.push_back( Command( args, Operation::eOpType_Show_Version ) );
    args.clear();

    args.push_back( Argument( Argument::eString, false, L"-v" ) );
    commands.push_back( Command( args, Operation::eOpType_Show_Version ) );
    args.clear();
}

/*----------------------------------------------------------------------------*/
/**
    parses command line options and returns array of operation.
    \param[in] argc      number of arguments
    \param[in] argv      pointer to arguments
    \param[out] operations    array of required operations
    \param[out] error_msg     human readable error message in case of parsing error
    \returns "true" if success, "false" if failed to parse command line arguments
   
   
*/ 
bool ParseAllParameters( int argc, const char *argv[], std::vector< Operation >& operations, std::wstring& error_msg )
{
    std::vector< Command > commands;

    InitParser( commands );

    int pos = 0;
    
    while ( pos < argc ) {

        unsigned int i = 0;
        for ( ; i < commands.size(); i++ ){
            
            Operation op;
            
            if ( commands[i].DoesMatch( argc, argv, pos, op) ){
                operations.push_back( op );
                break;
            }
        }

        if ( i == commands.size() ){
            error_msg = L"unknown option (or invalid command parameters) ";
            error_msg += StrFromMultibyte( argv[pos] );
            return false;
        }
    }

    return true;
}

}

