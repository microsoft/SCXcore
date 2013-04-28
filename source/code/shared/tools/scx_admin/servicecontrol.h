/*--------------------------------------------------------------------------------
    Copyright (c) Microsoft Corporation.  All rights reserved. 
    
*/
/**
    \file        

    \brief       Defines the service control classes.
    
    \date        2008-08-28 08:49

*/
/*----------------------------------------------------------------------------*/
#ifndef SERVICECONTROL_H
#define SERVICECONTROL_H

#include "admin_api.h"

/*----------------------------------------------------------------------------*/
/**
    Base class for Admin service controls implementing the service control API.

    Implements the common default behaviour for SCX services.
*/
class SCX_AdminServiceControl : public SCX_AdminServiceManagementAPI
{
public:
    SCX_AdminServiceControl( const std::wstring& name, 
                             const std::wstring& start_command,
                             const std::wstring& stop_command);
    virtual ~SCX_AdminServiceControl();

    virtual bool Start( std::wstring& info ) const;
    virtual bool Stop( std::wstring& info ) const;
    virtual bool Restart( std::wstring& info ) const;
    virtual bool Status( std::wstring& info ) const;

    unsigned int CountProcessesAlive( ) const;

protected:
    std::wstring m_name;  //!< Process name of the service.
    std::wstring m_start; //!< Service start command.
    std::wstring m_stop;  //!< Service stop command.

    void ExecuteCommand( const std::wstring& command, std::wstring& info ) const;

    SCX_AdminServiceControl(); //!< Intentionally protected.
    SCX_AdminServiceControl( SCX_AdminServiceControl& ); //!< Intentionally protected.
    SCX_AdminServiceControl& operator= (SCX_AdminServiceControl& ); //!< Intentionally protected.
};

/*----------------------------------------------------------------------------*/
/**
    Implements the cimom service controller.
*/
class SCX_CimomServiceControl : public SCX_AdminServiceControl
{
public:
    SCX_CimomServiceControl();
    virtual ~SCX_CimomServiceControl();
};

/*----------------------------------------------------------------------------*/
/**
    Implements the provider service controller.
*/
class SCX_ProviderServiceControl : public SCX_AdminServiceControl
{
public:
    SCX_ProviderServiceControl();

    virtual ~SCX_ProviderServiceControl();

    virtual bool Start( std::wstring& info ) const;
    virtual bool Stop( std::wstring& info ) const;
    virtual bool Restart( std::wstring& info ) const;
    virtual bool Status( std::wstring& info ) const;
};
#endif /* SERVICECONTROL_H */
/*----------------------------E-N-D---O-F---F-I-L-E---------------------------*/
