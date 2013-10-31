/*--------------------------------------------------------------------------------
    Copyright (c) Microsoft Corporation. All rights reserved. See license.txt for license information.
    
*/
/**
    \file        

    \brief       Implements service start functions for SCX
    
    \date        2008-08-28 08:52
    
*/
/*----------------------------------------------------------------------------*/

#include <scxcorelib/scxcmn.h>
#include <scxcorelib/stringaid.h>
#include <scxcorelib/scxprocess.h>
#include <scxcorelib/scxthread.h>
#if !defined(SCX_STACK_ONLY) 
#include <scxsystemlib/processenumeration.h>
#endif
#include <servicecontrol.h>

#include <signal.h>

/*----------------------------------------------------------------------------*/
/**
   Construcor for generic SCX service controller.
    
    \param       name Process name of service.
    \param       start_command A command that starts the service.
    \param       stop_command A command that stops the service.
*/
SCX_AdminServiceControl::SCX_AdminServiceControl( const std::wstring& name,
                                                  const std::wstring& start_command,
                                                  const std::wstring& stop_command)
    : m_name(name)
    , m_start(start_command)
    , m_stop(stop_command)
{

}
 
/*----------------------------------------------------------------------------*/
/**
   Virtual destructor.
*/
SCX_AdminServiceControl::~SCX_AdminServiceControl()
{

}

/*----------------------------------------------------------------------------*/
/**
   \copydoc SCX_AdminServiceManagementAPI::Start
*/
bool SCX_AdminServiceControl::Start( std::wstring& info ) const
{
    ExecuteCommand(m_start, info);
    return true;
}

/*----------------------------------------------------------------------------*/
/**
   \copydoc SCX_AdminServiceManagementAPI::Stop
*/
bool SCX_AdminServiceControl::Stop( std::wstring& info ) const
{
    static const unsigned int cMaxSleepTime = 10000;
    static const unsigned int cMaxTries = 20;

    unsigned int count = 0;
    ExecuteCommand(m_stop, info);

    // Wait max 10 seconds for process to die
    while (count < cMaxTries && CountProcessesAlive() > 0)
    {
        SCXThread::Sleep(cMaxSleepTime / cMaxTries);
        count++;
    }

    return true;
}

/*----------------------------------------------------------------------------*/
/**
   \copydoc SCX_AdminServiceManagementAPI::Restart
*/
bool SCX_AdminServiceControl::Restart( std::wstring& info ) const
{
    std::wstring infoStart, infoStop;
    try
    {
        Stop(infoStop);
    }
    catch (SCXAdminException& /*ignored*/)
    {
        // This is ignored. Even if the stop command failed we will still try to
        // start it again.
    }

    bool r = Start(infoStart);
    info = SCXCoreLib::StrAppend(infoStop, infoStart);
    return r;
}

/*----------------------------------------------------------------------------*/
/**
   Check if the process name handled is alive

   \returns true if process name is found, else false
*/
unsigned int SCX_AdminServiceControl::CountProcessesAlive( ) const
{
#if !defined(SCX_STACK_ONLY)
    SCXCoreLib::SCXHandle<SCXSystemLib::ProcessEnumeration> procEnum(
        new SCXSystemLib::ProcessEnumeration() );
    procEnum->SampleData();
    procEnum->Update(true);
    std::vector<SCXCoreLib::SCXHandle<SCXSystemLib::ProcessInstance> > procList = procEnum->Find(m_name);
    return static_cast<unsigned int>(procList.size());
#else
    std::wstring info;
#if defined(aix) || defined(hpux) || defined(sun)
    const std::wstring cmd1 = L"/bin/sh -c \"ps -A -o command | grep ";
#else
    const std::wstring cmd1 = L"/bin/sh -c \"ps -A -w -o command | grep ";
#endif
    const std::wstring cmd2 = L" | grep -v grep | wc -l\"";

    std::wstring cmd = cmd1 + m_name + cmd2;
    ExecuteCommand(cmd, info);

    return StrToUInt(info);
#endif
}

/*----------------------------------------------------------------------------*/
/**
    \copydoc SCX_AdminServiceManagementAPI::Status
*/
bool SCX_AdminServiceControl::Status( std::wstring& info ) const
{
    info = SCXCoreLib::StrAppend(m_name, L": is ");
    if (CountProcessesAlive() > 0) 
    {
        info = SCXCoreLib::StrAppend(info, L"running");
    }
    else
    {
        info = SCXCoreLib::StrAppend(info, L"stopped");
    }
    
    return true;
}

/*----------------------------------------------------------------------------*/
/**
    Helper method to execute start/stop commands.
    
    \param[in]  command Command to execute.
    \param[out] info Descriptive string of progress/completion.
    \throws     SCXAdminException if the command return value isn't zero.
    
*/
void SCX_AdminServiceControl::ExecuteCommand( const std::wstring& command, std::wstring& info ) const
{
    std::istringstream mystdin;
    std::ostringstream mystdout;
    std::ostringstream mystderr;
    int r = -1;

    try {
        r = SCXCoreLib::SCXProcess::Run(command, mystdin, mystdout, mystderr);
        info = SCXCoreLib::StrAppend(SCXCoreLib::StrFromMultibyte(mystdout.str()),
                                     SCXCoreLib::StrFromMultibyte(mystderr.str()));
    } catch (SCXCoreLib::SCXException& e) {
        std::wstring msg = SCXCoreLib::StrAppend(L"Exception: ", e.What());
        throw SCXAdminException(msg, SCXSRCLOCATION);
    }
    if (0 != r)
    {
        std::wstring msg(info);
        msg.append(L"\nRETURN CODE: ");
        msg = SCXCoreLib::StrAppend(msg, r);
        throw SCXAdminException(msg, SCXSRCLOCATION);
    }
}

/*----------------------------------------------------------------------------*/
/**
   Default costructor for Cimom service controller.
*/
SCX_CimomServiceControl::SCX_CimomServiceControl()
#if defined(aix)
    : SCX_AdminServiceControl(L"omiserver", L"/usr/bin/startsrc -s scx-cimd", L"/usr/bin/stopsrc -c -s scx-cimd")
#elif defined(hpux)
    : SCX_AdminServiceControl(L"omiserver", L"/sbin/init.d/scx-cimd start", L"/sbin/init.d/scx-cimd stop")
#elif defined(linux)
    : SCX_AdminServiceControl(L"omiserver", L"/etc/init.d/scx-cimd start", L"/etc/init.d/scx-cimd stop")
#elif defined(macos)
    : SCX_AdminServiceControl(L"omiserver", L"launchctl load -w /Library/LaunchDaemons/com.microsoft.scx-cimd.plist", L"launchctl unload -w /Library/LaunchDaemons/com.microsoft.scx-cimd.plist")
#elif defined(sun)
#if (PF_MAJOR == 5) && (PF_MINOR > 9)
    : SCX_AdminServiceControl(L"omiserver", L"/usr/sbin/svcadm -v enable -s svc:/application/management/scx-cimd", L"/usr/sbin/svcadm -v disable -s svc:/application/management/scx-cimd")
#else
    : SCX_AdminServiceControl(L"omiserver", L"/etc/init.d/scx-cimd start", L"/etc/init.d/scx-cimd stop")
#endif
#else
    : SCX_AdminServiceControl(L"omiserver", L"", L"")
#endif
{

}

/*----------------------------------------------------------------------------*/
/**
   Virtual destructor. 
*/
SCX_CimomServiceControl::~SCX_CimomServiceControl()
{

}

/*----------------------------------------------------------------------------*/
/**
   Default costructor for provider service controller.
*/
SCX_ProviderServiceControl::SCX_ProviderServiceControl()
    : SCX_AdminServiceControl(L"omiagent", L"", L"")
{

}

/*----------------------------------------------------------------------------*/
/**
   Virtual destructor.
*/
SCX_ProviderServiceControl::~SCX_ProviderServiceControl()
{

}

/*----------------------------------------------------------------------------*/
/**
   \copydoc SCX_AdminServiceManagementAPI::Start
*/
bool SCX_ProviderServiceControl::Start( std::wstring& info ) const
{
    info = SCXCoreLib::StrAppend(m_name, L": Cannot be started explicitly - start cimom");
    return false;
}

/*----------------------------------------------------------------------------*/
/**
   \copydoc SCX_AdminServiceManagementAPI::Stop
*/
bool SCX_ProviderServiceControl::Stop( std::wstring& info ) const
{
    info = SCXCoreLib::StrAppend(m_name, L": ");
#if !defined(SCX_STACK_ONLY)
    SCXCoreLib::SCXHandle<SCXSystemLib::ProcessEnumeration> procEnum(
        new SCXSystemLib::ProcessEnumeration() );
    procEnum->SampleData();
    procEnum->Update(true);
    std::vector<SCXCoreLib::SCXHandle<SCXSystemLib::ProcessInstance> > procList = procEnum->Find(m_name);
    std::vector<SCXSystemLib::scxpid_t> pids;
    for (std::vector<SCXCoreLib::SCXHandle<SCXSystemLib::ProcessInstance> >::iterator it = procList.begin(); it != procList.end(); it++)
    {
        if ((*it)->SendSignal(SIGTERM))
        {
            pids.push_back((*it)->getpid());
        }
    }
    info = SCXCoreLib::StrAppend(info, procList.size());
    time_t timeout = time(0) + 5; // 5s should be more than enough for cimprovagt to stop.
    while ( ! pids.empty() && timeout >= time(0))
    {
        procEnum->SampleData();
        procEnum->Update(true);
        std::vector<SCXSystemLib::scxpid_t>::iterator it = pids.begin(); 
        while (it != pids.end())
        {
            SCXCoreLib::SCXHandle<SCXSystemLib::ProcessInstance> inst = procEnum->Find(*it);
            if (0 == inst)
            {
                it = pids.erase(it);
            }
            else
            {
                it++;
            }
        }
        if ( ! pids.empty())
        {
            SCXThread::Sleep(100);
        }
    }
    for (std::vector<SCXSystemLib::scxpid_t>::iterator it = pids.begin(); it != pids.end(); it++)
    {
        SCXCoreLib::SCXHandle<SCXSystemLib::ProcessInstance> inst = procEnum->Find(*it);
        inst->SendSignal(SIGKILL);
    }
#else
    info = SCXCoreLib::StrAppend(info, CountProcessesAlive());

    const std::wstring cmd1 = L"/bin/sh -c \"ps -A -o pid,command | awk '$2~/";
#if defined(linux)
    const std::wstring cmd2 = L"/{print $1}' | xargs -r kill";
#else
    const std::wstring cmd2 = L"/{print $1}' | xargs kill";
#endif

    std::wstring cmd = cmd1 + m_name + cmd2 + L"\"";
    std::wstring tmpstr;

    ExecuteCommand(cmd, tmpstr);

    time_t timeout = time(0) + 5; // 5s should be more than enough for cimprovagt to stop.
    while (CountProcessesAlive() > 0 && timeout >= time(0))
    {
        SCXThread::Sleep(100);
    }

    if (CountProcessesAlive() > 0)
    {
        cmd = cmd + m_name + cmd2 + L" -9\"";
        ExecuteCommand(cmd, tmpstr);
    }
#endif
    info = SCXCoreLib::StrAppend(info, L" instances stopped");
    return true;
}

/*----------------------------------------------------------------------------*/
/**
   \copydoc SCX_AdminServiceManagementAPI::Restart
*/
bool SCX_ProviderServiceControl::Restart( std::wstring& info ) const
{
    if ( ! Stop(info))
    {
        return false;
    }
    info = SCXCoreLib::StrAppend(info, L"\n");
    info = SCXCoreLib::StrAppend(info, m_name);
    info = SCXCoreLib::StrAppend(info, L": not started (will be started automatically by cimom when needed)\n");
    return true;
}

/*----------------------------------------------------------------------------*/
/**
    \copydoc SCX_AdminServiceManagementAPI::Status
*/
bool SCX_ProviderServiceControl::Status( std::wstring& info ) const
{
    unsigned int count = CountProcessesAlive();

    info = SCXCoreLib::StrAppend(m_name, L": ");
    if (0 == count)
    {
        info = SCXCoreLib::StrAppend(info, L"is stopped");
    }
    else
    {
        info = SCXCoreLib::StrAppend(info, count);
        info = SCXCoreLib::StrAppend(info, L" instance");
        if (count > 1)
        {
            info = SCXCoreLib::StrAppend(info, L"s");
        }
        info = SCXCoreLib::StrAppend(info, L" running");
    }
    
    return true;
}
/*----------------------------E-N-D---O-F---F-I-L-E---------------------------*/
