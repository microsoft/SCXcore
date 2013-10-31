/*--------------------------------------------------------------------------------
  Copyright (c) Microsoft Corporation. All rights reserved. See license.txt for license information.
*/
/**
   \file        persistappserverinstances.h

   \brief       Persist instances of discovered application servers

   \date        11-05-19 12:00:00
*/
/*----------------------------------------------------------------------------*/
#ifndef PERSISTAPPSERVERINSTANCES_H
#define PERSISTAPPSERVERINSTANCES_H

#include <string>

#include <scxcorelib/scxcmn.h>
#include <scxcorelib/scxlog.h>

#include "source/code/scxcorelib/util/persist/scxfilepersistmedia.h"

#include "appserverinstance.h"
#include "removenonexistentappserverinstances.h"

namespace SCXSystemLib
{
    const static std::wstring APP_SERVER_NUMBER = L"NumberOfAppServers";
    const static std::wstring APP_SERVER_INSTANCE = L"AppServerInstance";
    const static std::wstring APP_SERVER_PROVIDER = L"AppServerProvider";
    const static std::wstring APP_SERVER_METADATA = L"MetaData";
    const static std::wstring APP_SERVER_ID = L"Id";
    const static std::wstring APP_SERVER_DISK_PATH = L"DiskPath";
    const static std::wstring APP_SERVER_HTTP_PORT = L"HttpPort";
    const static std::wstring APP_SERVER_HTTPS_PORT = L"HttpsPort";
    const static std::wstring APP_SERVER_PROTOCOL = L"Protocol";
    const static std::wstring APP_SERVER_IS_DEEP_MONITORED= L"IsDeepMonitored";
    const static std::wstring APP_SERVER_IS_RUNNING = L"IsRunning";
    const static std::wstring APP_SERVER_TYPE = L"Type";
    const static std::wstring APP_SERVER_VERSION = L"Version";
    const static std::wstring APP_SERVER_PROFILE = L"Profile";
    const static std::wstring APP_SERVER_CELL = L"Cell";
    const static std::wstring APP_SERVER_NODE = L"Node";
    const static std::wstring APP_SERVER_SERVER = L"Server";

    /*--------------------------------------------------------*/
    /**
       Class that represents an how to persist application server instances 
    */
    class PersistAppServerInstances
    {

        public:
    
            /*
             * Default no-arg constructor, uses the
             * default/production values
             */
            PersistAppServerInstances();

            /*
             * Constructor where the location of the persisted
             * directory can be overriden
             * 
             * \param[in] directory  Location to read/write persisted data to
             * 
             */
            PersistAppServerInstances(const SCXCoreLib::SCXFilePath& directory);

            /*
             * Destructor
             */
            virtual ~PersistAppServerInstances();

            /*--------------------------------------------------------*/
            /**
               Remove all Application Server Instances from disk
            */
            void EraseFromDisk(void);

            /*--------------------------------------------------------*/
            /**
               Read list of Application Server Instances from disk
            */
            void ReadFromDisk(
                    std::vector<SCXCoreLib::SCXHandle<AppServerInstance> >& instances);

            /*--------------------------------------------------------*/
            /**
               Given a list of instances, remove the instances that are
               can no longer be found on disk
            */
            virtual void RemoveNonExistentInstances(
                    std::vector<SCXCoreLib::SCXHandle<AppServerInstance> >& instances,
                    SCXSystemLib::RemoveNonexistentAppServerInstances remover = SCXSystemLib::RemoveNonexistentAppServerInstances());

            /*--------------------------------------------------------*/
            /**
               Write a list of Application Server Instances to disk
            */
            void WriteToDisk(
                    std::vector<SCXCoreLib::SCXHandle<AppServerInstance> >& instances);

        protected:
            //!< Log handle
            SCXCoreLib::SCXLogHandle m_log;

            // Handle to the persistence of the media
            SCXCoreLib::SCXHandle<SCXCoreLib::SCXPersistMedia> m_pmedia;

        private:
            /*--------------------------------------------------------*/
            /**
               Helper method for reading instances from disk
            */
            bool ReadFromDiskHelper(
                    SCXCoreLib::SCXHandle<SCXCoreLib::SCXPersistDataReader>& preader,
                    std::vector<SCXCoreLib::SCXHandle<AppServerInstance> >& instances);

    };

}

#endif /* PERSISTAPPSERVERINSTANCES_H */
/*----------------------------E-N-D---O-F---F-I-L-E---------------------------*/
