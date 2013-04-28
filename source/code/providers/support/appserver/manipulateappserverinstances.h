/*--------------------------------------------------------------------------------
  Copyright (c) Microsoft Corporation.  All rights reserved.

*/
/**
   \file        manipulateappserverinstances.h

   \brief       Manipulates vectors of application server instances

   \date        11-05-26 12:00:00

*/
/*----------------------------------------------------------------------------*/
#ifndef MANIPULATEAPPSERVERINSTANCES_H
#define MANIPULATEAPPSERVERINSTANCES_H

#include <vector>

#include <scxcorelib/scxcmn.h>

#include "appserverinstance.h"
#include "removenonexistentappserverinstances.h"

namespace SCXSystemLib
{
    /*---------------------------------------------------------------------*/
    /**
       Class that with static methods for manipulate vectors of application
       server instances
    */
    class ManipulateAppServerInstances
    {

        public:
    
            /*
             * Default no-arg constructor
             */
            ManipulateAppServerInstances();

            /*
             * Destructor
             */
            virtual ~ManipulateAppServerInstances();

            static void UpdateInstancesWithRunningProcesses(
                    std::vector<SCXCoreLib::SCXHandle<AppServerInstance> >& previouslyKnownInstances,
                    std::vector<SCXCoreLib::SCXHandle<AppServerInstance> >& runningProcesses,
                    SCXCoreLib::SCXHandle<SCXSystemLib::IRemoveNonexistentAppServerInstances> remover = 
                            SCXCoreLib::SCXHandle<SCXSystemLib::IRemoveNonexistentAppServerInstances>( new SCXSystemLib::RemoveNonexistentAppServerInstances()));
            
            
            /*---------------------------------------------------------------*/
            /**
               Given a list of running processes, merge this with the results 
               of the cache and return this in the third parameter. The 
               resulting output should be returned to the provider caller as 
               well as persisted to disk.
            */
            static void MergeProcessesAndCache(
                    std::vector<SCXCoreLib::SCXHandle<AppServerInstance> >& processes,
                    std::vector<SCXCoreLib::SCXHandle<AppServerInstance> >& cache,
                    std::vector<SCXCoreLib::SCXHandle<AppServerInstance> >& result);

            /*---------------------------------------------------------------*/
            /*
             * Delegate method used comparing AppServerInstances based-on
             * their path on disk.  Other properties like running state and
             * port are not used because only the path on disk is important
             * for removing duplicates between the process list and the cache.
             */
            static bool PathCompare (
                    SCXCoreLib::SCXHandle<AppServerInstance> i,
                    SCXCoreLib::SCXHandle<AppServerInstance> j);

            /*---------------------------------------------------------------*/
            /*
             * Delegate method used for ordering the AppServerInstances
             * by the path 
             */
            static bool PathOrdering (
                    SCXCoreLib::SCXHandle<AppServerInstance> i,
                    SCXCoreLib::SCXHandle<AppServerInstance> j);
            
            /*---------------------------------------------------------------*/
            /*
             * Delegate method used for ordering the AppServerInstances
             * by the path 
             */
            static SCXCoreLib::SCXHandle<AppServerInstance> SetIsRunningToFalse(
                    SCXCoreLib::SCXHandle<AppServerInstance> i);
            
    };

}

#endif /* MANIPULATEAPPSERVERINSTANCES_H */
/*----------------------------E-N-D---O-F---F-I-L-E---------------------------*/
