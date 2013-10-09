/*--------------------------------------------------------------------------------
  Copyright (c) Microsoft Corporation.  All rights reserved.
*/
/**
   \file        appserverinstance.h

   \brief       PAL representation of a Application Server

   \date        11-05-18 12:00:00
*/
/*----------------------------------------------------------------------------*/
#ifndef APPSERVERINSTANCE_H
#define APPSERVERINSTANCE_H

#include <string>

#include <scxsystemlib/entityinstance.h>
#include <scxcorelib/scxlog.h>

namespace SCXSystemLib
{
    /*----------------------------------------------------------------------------*/
    /**
       Class that represents an instances.

       Concrete implementation of an instance of a Application Server

    */
    class AppServerInstance : public EntityInstance
    {
        friend class AppServerEnumeration;

    public:

        AppServerInstance(const std::wstring& id,
                          const std::wstring& type);

        virtual ~AppServerInstance();
        
        /*-------------------------------------------------------------------*/
        //! Check if two application server instances are equal
        //! \param[in]     first            Instance to compare
        //! \param[in]     second           Instance to compare
        //! \returns       true iff the application server instances are equal.
        bool operator==(const AppServerInstance& other) const;

        /*--------------------------------------------------------------------*/
        //! Check if two application server instances are not equal
        //! \param[in]     first            Instance to compare
        //! \param[in]     second           Instance to compare
        //! \returns       true iff the application server instances are equal.
        bool operator!=(const AppServerInstance& other) const;

        std::wstring GetHttpPort() const;
        std::wstring GetHttpsPort() const;
        std::wstring GetVersion() const;
        std::wstring GetMajorVersion() const;
        std::wstring GetDiskPath() const;
        std::wstring GetType() const;
        std::wstring GetProtocol() const;
        std::wstring GetPort() const;
        bool GetIsDeepMonitored() const;
        bool GetIsRunning() const;
        std::wstring GetProfile() const;
        std::wstring GetCell() const;
        std::wstring GetNode() const;
        std::wstring GetServer() const;

        virtual bool IsStillInstalled();

        void SetDiskPath(const std::wstring& diskPath);
        void SetHttpPort(const std::wstring& httpPort);
        void SetHttpsPort(const std::wstring& httpsPort);
        void SetIsDeepMonitored(bool isDeepMonitored, std::wstring protocol);
        void SetIsRunning(bool isRunning);
        void SetServer(const std::wstring& server);
        void SetType(const std::wstring& type);
        void SetVersion(const std::wstring& version);

        virtual void Update();

    protected:

        virtual std::wstring ExtractMajorVersion(const std::wstring& version);

        SCXCoreLib::SCXLogHandle m_log;  //!< Log handle

        std::wstring m_httpPort;
        std::wstring m_httpsPort;
        std::wstring m_version;
        std::wstring m_majorVersion;
        std::wstring m_diskPath;
        std::wstring m_type;
        std::wstring m_protocol;
        std::wstring m_port;
        bool m_isDeepMonitored;
        bool m_isRunning;
        std::wstring m_profile;
        std::wstring m_cell;
        std::wstring m_node;
        std::wstring m_server;

    };

}

#endif /* APPSERVERINSTANCE_H */
/*----------------------------E-N-D---O-F---F-I-L-E---------------------------*/
