/*--------------------------------------------------------------------------------
    Copyright (c) Microsoft Corporation.  All rights reserved.

*/
/**
    \file        appserverinstance.cpp

    \brief       PAL representation of an application server

    \date        11-05-18 12:00:00
*/
/*---------------------------------------------------------------------------*/

#include <scxcorelib/scxcmn.h>

#include <string>
#include <sstream>
#include <vector>

#include <scxcorelib/stringaid.h>
#include <scxcorelib/scxdirectoryinfo.h>
#include <scxcorelib/scxmath.h>

#include "appserverinstance.h"
#include "appserverconstants.h" 

using namespace std;
using namespace SCXCoreLib;

namespace SCXSystemLib
{

    /*------------------------------------------------------------------------*/
    /**
        Constructor

        Parameters:  id -   Identifier for the appserver (i.e. install path 
                            for the appserver)
        Parameters:  type - Type of Application Server (i.e. JBoss, Tomcat, etc..)
    */
    AppServerInstance::AppServerInstance(
            const wstring& id, 
            const wstring& type) : 
        EntityInstance(id, false),
        m_httpPort(L""), 
        m_httpsPort(L""), 
        m_version(L""), 
        m_majorVersion(L""), 
        m_diskPath(id), 
        m_type(type), 
        m_protocol(L""), 
        m_port(L""), 
        m_isDeepMonitored(false),
        m_isRunning(true),
        m_profile(L""), 
        m_cell(L""), 
        m_node(L""), 
        m_server(L"")
    {
        m_log = SCXLogHandleFactory::GetLogHandle(L"scx.core.common.pal.system.appserver.appserverinstance");

        SCX_LOGTRACE(m_log, wstring(L"AppServerInstance default constructor - ").append(id));
    }

    /*----------------------------------------------------------------------*/
    /**
        Destructor
    */
    AppServerInstance::~AppServerInstance()
    {
        SCX_LOGTRACE(m_log, wstring(L"AppServerInstance destructor - ").append(GetId()));
    }
    
    /*--------------------------------------------------------------------*/
    //! Check if two application server instances are equal
    //! \param[in]     first            Instance to compare
    //! \param[in]     second           Instance to compare
    //! \returns       true iff the application server instances are equal.
    bool AppServerInstance::operator==(const AppServerInstance& other) const
    {
        return (this->GetDiskPath() == other.GetDiskPath()) &&
               (this->GetHttpPort() == other.GetHttpPort()) &&
               (this->GetHttpsPort() == other.GetHttpsPort()) &&
               (this->GetPort() == other.GetPort()) &&
               (this->GetProtocol() == other.GetProtocol()) &&
               (this->GetIsDeepMonitored() == other.GetIsDeepMonitored()) &&
               (this->GetIsRunning() == other.GetIsRunning()) &&
               (this->GetType() == other.GetType()) &&
               (this->GetVersion() == other.GetVersion()) &&
               (this->GetProfile() == other.GetProfile()) &&
               (this->GetCell() == other.GetCell()) &&
               (this->GetNode() == other.GetNode()) &&
               (this->GetServer() == other.GetServer());
    }

    /*--------------------------------------------------------------------*/
    //! Check if two application server instances are not equal
    //! \param[in]     first            Instance to compare
    //! \param[in]     second           Instance to compare
    //! \returns       true iff the application server instances are equal.
    bool AppServerInstance::operator!=(const AppServerInstance& other) const
    {
        return !(*this == other);
    }

    /*--------------------------------------------------------------------*/
    /**
        Get HTTP Port

        Retval:      HTTP port of appserver instance
    */
    wstring AppServerInstance::GetHttpPort() const
    {
        return m_httpPort;
    }

    /*--------------------------------------------------------------------*/
    /**
        Get HTTPS Port

        Retval:      HTTPS port of appserver instance
    */
    wstring AppServerInstance::GetHttpsPort() const
    {
        return m_httpsPort;
    }

    /*--------------------------------------------------------------------*/
    /**
        Get appser verversion

        Retval:      version of appserver instance
    */
    wstring AppServerInstance::GetVersion() const
    {
        return m_version;
    }

    /*--------------------------------------------------------------------*/
    /**
        Get appser major verversion

        Retval:      major version of appserver instance
    */
    wstring AppServerInstance::GetMajorVersion() const
    {
        return m_majorVersion;
    }

    /*--------------------------------------------------------------------*/
    /**
        Get disk path

        Retval:      disk path of appserver instance
    */
    wstring AppServerInstance::GetDiskPath() const
    {
        return m_diskPath;
    }

    /*--------------------------------------------------------------------*/
    /**
        Get type

        Retval:      type of appserver instance
    */
    wstring AppServerInstance::GetType() const
    {
        return m_type;
    }

    /*--------------------------------------------------------------------*/
    /**
        Get protocol

        Retval:      protocol to use
    */
    wstring AppServerInstance::GetProtocol() const
    {
        return m_protocol;
    }

    /*--------------------------------------------------------------------*/
    /**
        Get port

        Retval:      port to use
    */
    wstring AppServerInstance::GetPort() const
    {
        return m_port;
    }

    /*--------------------------------------------------------------------*/
    /**
        Get profile

        Retval:      profile name
    */
    wstring AppServerInstance::GetProfile() const
    {
        return m_profile;
    }

    /*--------------------------------------------------------------------*/
    /**
        Get cell

        Retval:      cell name
    */
    wstring AppServerInstance::GetCell() const
    {
        return m_cell;
    }

    /*--------------------------------------------------------------------*/
    /**
        Get node

        Retval:      node name
    */
    wstring AppServerInstance::GetNode() const
    {
        return m_node;
    }

    /*--------------------------------------------------------------------*/
    /**
        Get server

        Retval:      server name
    */
    wstring AppServerInstance::GetServer() const
    {
        return m_server;
    }

    /*--------------------------------------------------------------------*/
    /**
        Get IsDeepMonitored

        Retval:      is deep monitoring enabled for this app server
    */
    bool AppServerInstance::GetIsDeepMonitored() const
    {
        return m_isDeepMonitored;
    }

    /*--------------------------------------------------------------------*/
    /**
        Get IsRunning

        Retval:      is this app server process running
    */
    bool AppServerInstance::GetIsRunning() const
    {
        return m_isRunning;
    }

    /*--------------------------------------------------------------------*/
    /**
        Set disk path

        \param[in]     diskPath   Disk Path
    */
    void AppServerInstance::SetDiskPath(const wstring& diskPath)
    {
        m_diskPath = diskPath;
    }

    /*--------------------------------------------------------------------*/
    /**
        Set HTTP port

        \param[in]     httpPort   HTTP port
    */
    void AppServerInstance::SetHttpPort(const wstring& httpPort)
    {
        m_httpPort = httpPort;
    }

    /*----------------------------------------------------------------------------*/
    /**
        Set HTTPS port

        \param[in]     httpsPort   HTTPS port
    */
    void AppServerInstance::SetHttpsPort(const wstring& httpsPort)
    {
        m_httpsPort = httpsPort;
    }

    /*----------------------------------------------------------------------------*/
    /**
        Set IsDeepMonitored

        \param[in]     isDeepMonitored   Should this app server be deep monitored
    */
    void AppServerInstance::SetIsDeepMonitored(bool isDeepMonitored, wstring protocol)
    {
        m_isDeepMonitored = isDeepMonitored;

        // Only check protocol when enabeling deep monitoring
        if (isDeepMonitored)
        {
            if (L"HTTPS" == protocol)
            {
                m_protocol = L"HTTPS";
                m_port = m_httpsPort;
            }
            else // Treat all non-HTTPS string as HTTP
            {
                m_protocol = L"HTTP";
                m_port = m_httpPort;
            }
        }
    }

    /*--------------------------------------------------------------------*/
    /**
        Set IsRunning

        \param[in]     isRunning   is this app server process running
    */
    void AppServerInstance::SetIsRunning(bool isRunning)
    {
        m_isRunning = isRunning;
    }

    /*----------------------------------------------------------------------------*/
    /**
        Set type

        \param[in]     type   type
    */
    void AppServerInstance::SetType(const wstring& type)
    {
        m_type = type;
    }

    /*----------------------------------------------------------------------------*/
    /**
        Set Server

        \param[in]     type   Server
    */
    void AppServerInstance::SetServer(const wstring& server)
    {
        m_server = server;
    }
    
    /*--------------------------------------------------------------------*/
    /**
        Set Version

        \param[in]     version   version of the application server
    */
    void AppServerInstance::SetVersion(const wstring& version)
    {
        m_version = version;
        m_majorVersion = ExtractMajorVersion(version);
    }

    /*--------------------------------------------------------------------*/
    /**
        Update values

    */
    void AppServerInstance::Update()
    {
        SCX_LOGTRACE(m_log, wstring(L"AppServerInstance::Update() - ").append(GetId()));
    }

    /*--------------------------------------------------------------------*/
    /**
        Extract the major version number from the complete version

        \param[in]     version   version of the application server
        Retval:        major version number
    */
    wstring AppServerInstance::ExtractMajorVersion(const wstring& version)
    {
        vector<wstring> parts;

        StrTokenizeStr(version, parts, L".");

        if (parts.size() > 0)
        {
            return parts[0];
        }

        return L"";
    }
    

    /*--------------------------------------------------------------------*/
    /**
        Check if the application server is still installed.
        
        By default, this will just check that the base directory
        exists on disk.  Additionaly checking may be done by overriding
        logic per application server.

    */
    bool AppServerInstance::IsStillInstalled()
    {
        return SCXDirectory::Exists(SCXFilePath(m_diskPath));
    }
}

/*----------------------------E-N-D---O-F---F-I-L-E---------------------------*/
