/*--------------------------------------------------------------------------------
 Copyright (c) Microsoft Corporation.  All rights reserved.

 */
/**
 \file

 \brief       Means of persisting application server instances to disk

 \date        11-05-18 12:00:00

 */
/*-----------------------------------------------------------------*/

#include <scxcorelib/scxcmn.h>

#include <algorithm>
#include <functional>
#include <string>
#include <vector>

#include <scxcorelib/scxfile.h>
#include <scxcorelib/stringaid.h>

#include "appserverconstants.h"
#include "appserverinstance.h"
#include "weblogicappserverinstance.h"
#include "websphereappserverinstance.h"
#include "tomcatappserverinstance.h"
#include "jbossappserverinstance.h"
#include "persistappserverinstances.h"

#include "source/code/scxcorelib/util/persist/scxfilepersistdatareader.h"
#include "source/code/scxcorelib/util/persist/scxfilepersistdatawriter.h"
#include "source/code/scxcorelib/util/persist/scxfilepersistmedia.h"

using namespace std;
using namespace SCXCoreLib;
using namespace SCXSystemLib;

namespace SCXSystemLib
{

    /*-----------------------------------------------------------------*/
    /**
       Constructor (no arg)
     */
    PersistAppServerInstances::PersistAppServerInstances()
    {
        m_log = SCXLogHandleFactory::GetLogHandle(L"scx.core.common.pal.system.appserver.persistappserverinstances");
        m_pmedia = GetPersistMedia();

        SCX_LOGTRACE(m_log, wstring(L"PersistAppServerInstances default constructor"));
    }

    /*-----------------------------------------------------------------*/
    /**
       Destructor
     */
    PersistAppServerInstances::~PersistAppServerInstances()
    {
        SCX_LOGTRACE(m_log, wstring(L"PersistAppServerInstances destructor"));
    }

    /*-----------------------------------------------------------------*/
    /**
       Erase all application server instances from disk.
    */
    void PersistAppServerInstances::EraseFromDisk(void)
    {
        try
        {
            m_pmedia->UnPersist(APP_SERVER_PROVIDER);
        }
        catch(PersistDataNotFoundException& pdnfe)
        {
            SCX_LOGTRACE(m_log, pdnfe.What());
        }
    }

    /*-----------------------------------------------------------------*/
    /**
       Read a list of application server instances from disk.

       \param[out] instances - vector of Application Server Instances 
                               to insert the values read from disk into 
       
    */
    void PersistAppServerInstances::ReadFromDisk(
            vector<SCXHandle<AppServerInstance> >& instances)
    {
        try
        {
            SCXHandle<SCXPersistDataReader> preader = 
                    m_pmedia->CreateReader(APP_SERVER_PROVIDER);

            preader->ConsumeStartGroup(APP_SERVER_METADATA, true);
            wstring sizeFromCache = preader->ConsumeValue(APP_SERVER_NUMBER);
            preader->ConsumeEndGroup(true); // Closing APP_SERVER_NUMBER

            unsigned int size = StrToUInt(sizeFromCache);
            
            while(ReadFromDiskHelper(preader, instances))
            {
            }

            // If the size read does not match the actual number
            // of instances read (for instance, some has truncated
            // the cache), then the cache probably has been corrupted.
            // For this case, throw away all the cache information.
            if (instances.size() != size)
            {
                instances.clear();
            }

            RemoveNonExistentInstances(instances);
        }
        // Could have gotten here is the cache does not
        // exist or is corrupt.  If it does not exist, then
        // the exception is thrown when doing the first read
        // and nothing has been added to the array. In this case,
        // the goal is to not surface the error.
        //
        // If corruption has occurred, then the cache should be 
        // deleted (which should happen when we re-persist the current
        // state.
        catch(SCXNotSupportedException& snse)
        {
            SCX_LOGTRACE(m_log, snse.What());
            instances.clear();
        }
        catch(PersistDataNotFoundException& pdnfe)
        {
            SCX_LOGTRACE(m_log, pdnfe.What());
            instances.clear();
        }
        catch(PersistUnexpectedDataException& pude)
        {
            SCX_LOGTRACE(m_log, pude.What());
            instances.clear();
        }
    }

    /*--------------------------------------------------------*/
    /**
       Helper method for reading instances from disk
       
       \param[in] preader - handle to the physical media reader
       \param[out] instances - vector of Application Server Instances 
                               to insert the values read from disk into 

    */
    bool PersistAppServerInstances::ReadFromDiskHelper(
            SCXHandle<SCXPersistDataReader>& preader,
            vector<SCXHandle<AppServerInstance> >& instances)
    {
        
        bool isThereAnElement = preader->ConsumeStartGroup(APP_SERVER_INSTANCE, false);
        
        if (isThereAnElement)
        {
            wstring id, diskPath, httpPort, httpsPort, protocol, isDeepMonitored, type, version, profile, cell, node, server;
            diskPath = preader->ConsumeValue(APP_SERVER_DISK_PATH);
            try
            {
                id = preader->ConsumeValue(APP_SERVER_ID);
            }
            catch(PersistUnexpectedDataException)
            {
                // To be backward compatible, we default to disk path if id is not in the persited data
                id = diskPath;
                SCX_LOGTRACE(m_log, L"Id not found in persited data, defaulting to disk path");
            }
            httpPort = preader->ConsumeValue(APP_SERVER_HTTP_PORT);
            httpsPort = preader->ConsumeValue(APP_SERVER_HTTPS_PORT);
            try
            {
                protocol = preader->ConsumeValue(APP_SERVER_PROTOCOL);
            }
            catch(PersistUnexpectedDataException)
            {
                // To be backward compatible, we default to HTTP if protocol is not in the persited data
                protocol = PROTOCOL_HTTP;
                SCX_LOGTRACE(m_log, L"Protocol not found in persited data, defaulting to HTTP");
            }
            isDeepMonitored = preader->ConsumeValue(APP_SERVER_IS_DEEP_MONITORED);
            type = preader->ConsumeValue(APP_SERVER_TYPE);
            version = preader->ConsumeValue(APP_SERVER_VERSION);
            try
            {
                profile = preader->ConsumeValue(APP_SERVER_PROFILE);
                cell = preader->ConsumeValue(APP_SERVER_CELL);
                node = preader->ConsumeValue(APP_SERVER_NODE);
                server = preader->ConsumeValue(APP_SERVER_SERVER);
            }
            catch(PersistUnexpectedDataException)
            {
                // To be backward compatible, we default profile, cell, node & server to 
                // empty strings if they are not in the persited data
                profile = L"";
                cell = L"";
                node = L"";
                server = L"";
                SCX_LOGTRACE(m_log, L"WebSphere properties not found in persited data, defaulting to empty strings");
            }
            preader->ConsumeEndGroup(true);

            SCXHandle<AppServerInstance> instance;

            bool badType = false;

            if (APP_SERVER_TYPE_JBOSS == type)
            {
                instance = new  JBossAppServerInstance(diskPath);
            } 
            else if (APP_SERVER_TYPE_TOMCAT == type)
            {
                instance = new  TomcatAppServerInstance(diskPath, diskPath);
            }
            else if (APP_SERVER_TYPE_WEBLOGIC == type)
            {
                instance = new  WebLogicAppServerInstance(diskPath);
                instance->SetServer(server);
            }
            else if (APP_SERVER_TYPE_WEBSPHERE == type)
            {
                instance = new  WebSphereAppServerInstance(diskPath, cell, node, profile, server);
            }
            else
            {
                SCX_LOGWARNING(m_log, wstring(L"Unknown application server type read from cache: ").append(type));
                badType = true;
            }

            if (!badType)
            {
                instance->SetHttpPort(httpPort);
                instance->SetHttpsPort(httpsPort);
            
                // This value is a bool, but when written to disk it is 
                // serialized as an integer.
                instance->SetIsDeepMonitored(L"1" == isDeepMonitored, protocol);
            
                // If read from cache, then by default this representation
                // of the instance is not running
                instance->SetIsRunning(false);
                instance->SetVersion(version);
                instances.push_back(instance);
            }
        }
        
        return isThereAnElement;
    }

    /*--------------------------------------------------------*/
    /**
       Given a list of instances, remove the instances that are
       can no longer be found on disk
       
       \param[in/out] instances - vector of Application Server Instances 
                                  to be manipulated
       \param[in] remover - predicate object for removing non-existent
                            application server instances. 

    */
    void PersistAppServerInstances::RemoveNonExistentInstances(
            vector<SCXHandle<AppServerInstance> >& instances,
            RemoveNonexistentAppServerInstances remover )
    {
        remover.RemoveNonexistentInstances(instances);
    }

    
    /*-----------------------------------------------------------------*/
    /**
       Write the given list of application server instances to disk.
       
       \param[in] instances - vector of Application Server Instances 
                              to write to disk
       
    */
    void PersistAppServerInstances::WriteToDisk(
            vector<SCXHandle<AppServerInstance> >& instances)
    {
        SCXHandle<SCXPersistDataWriter> pwriter= 
                m_pmedia->CreateWriter(APP_SERVER_PROVIDER);

        pwriter->WriteStartGroup(APP_SERVER_METADATA);
        pwriter->WriteValue(APP_SERVER_NUMBER, 
                StrFrom(instances.size()));
        pwriter->WriteEndGroup(); // Closing APP_METADATA

        int index = 0; 
        for(
                vector<SCXHandle<AppServerInstance> >::iterator instance = instances.begin();
                instance != instances.end();
                ++instance, ++index)
        {
            pwriter->WriteStartGroup(APP_SERVER_INSTANCE);

            pwriter->WriteValue(APP_SERVER_DISK_PATH, (*instance)->GetDiskPath());
            pwriter->WriteValue(APP_SERVER_ID, (*instance)->GetId());
            pwriter->WriteValue(APP_SERVER_HTTP_PORT, (*instance)->GetHttpPort());
            pwriter->WriteValue(APP_SERVER_HTTPS_PORT, (*instance)->GetHttpsPort());
            pwriter->WriteValue(APP_SERVER_PROTOCOL, (*instance)->GetProtocol());
            pwriter->WriteValue(APP_SERVER_IS_DEEP_MONITORED, 
                    StrFrom((*instance)->GetIsDeepMonitored()));
            pwriter->WriteValue(APP_SERVER_TYPE, (*instance)->GetType());
            pwriter->WriteValue(APP_SERVER_VERSION, (*instance)->GetVersion());
            pwriter->WriteValue(APP_SERVER_PROFILE, (*instance)->GetProfile());
            pwriter->WriteValue(APP_SERVER_CELL, (*instance)->GetCell());
            pwriter->WriteValue(APP_SERVER_NODE, (*instance)->GetNode());
            pwriter->WriteValue(APP_SERVER_SERVER, (*instance)->GetServer());

            pwriter->WriteEndGroup(); // Closing this instance
        }
        
        pwriter->DoneWriting();
    }
}

/*----------------------------E-N-D---O-F---F-I-L-E---------------------------*/
