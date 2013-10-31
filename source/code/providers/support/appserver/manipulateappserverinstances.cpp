/*--------------------------------------------------------------------------------
    Copyright (c) Microsoft Corporation. All rights reserved. See license.txt for license information.
*/
/**
   \file        manipulateappserverinstances.cpp

   \brief       Manipulates vectors of application server instances

   \date        11-05-26 12:00:00
*/
/*----------------------------------------------------------------------------*/
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>

#include <scxcorelib/scxcmn.h>

#include <scxcorelib/stringaid.h>

#include "appserverinstance.h"
#include "manipulateappserverinstances.h"

using namespace std;
using namespace SCXCoreLib;
using namespace SCXSystemLib;

namespace SCXSystemLib
{

    /*-----------------------------------------------------------------*/
    /**
       Merge the processes and cache to a single list and remove
       duplicates. This is done by using some of the STL vector methods.
       First, merge both of the arrays. The processes should be first. 
       Next sort the items based-on the path. At this point, the duplicates
       (duplicates by means of the same path)

        \param[in] processes - vector of Application Server Instances of 
                                running processes
        \param[in] cache - vector of Application Server Instances from the cache
        \param[out] result - vector where the merged results will be placed.

    */
    void ManipulateAppServerInstances::MergeProcessesAndCache(
            vector<SCXHandle<AppServerInstance> >& processes,
            vector<SCXHandle<AppServerInstance> >& cache,
            vector<SCXHandle<AppServerInstance> >& result)
    {
        result.clear();
        
        result.insert( result.end(), processes.begin(), processes.end() );
        result.insert( result.end(), cache.begin(), cache.end() );
        
        sort(result.begin(), result.end(), PathOrdering);
        vector<SCXHandle<AppServerInstance> >::iterator tmp =
                unique(result.begin(), result.end(), PathCompare);
        result.resize(tmp-result.begin());
    }

    /*-----------------------------------------------------------------*/
    /**
       Given the current list of instances as well as a list of the recently
       discovered processes, merge these together to provide an updated list of
       the running processes.

       Assumption #1: Disk Path is the unique identifier of an instance
       Assumption #2: the runningProcesses all have IsRunning set to true
       Assumption #3: 'someone else' has already called update on the instances

       The steps for doing so are as follows:

       1) Remove any previously known instance that is no longer on disk
       2) Cycle through the remaining known instances and set IsRunning to false
       3) Add the list of running process to the front of the known instances
       4) Sort the list based on disk path so that it is guaranteed that
       the process item is followed by it's previously known state (if there
       was one)
       5) If the next item has the same path, then next item is the previously
       known state of the current one (and implicitly this item is from the list
       of running processes). It also means that the Deep Monitored flag should
       be copied from the previous known state to the current one.
       6) Remove the duplicates (i.e. previously known states) from the list

        \param[in/out]  previouslyKnownInstances - vector of previously known
                                                   Application Server Instances
        \param[in]      runningProcesses - vector of Application Server Instances
                                           representing a list of running processes
        \param[in]      remover - predicate object for removing non-existent
                                  application server instances. 
    */
    void ManipulateAppServerInstances::UpdateInstancesWithRunningProcesses(
            vector<SCXHandle<AppServerInstance> >& previouslyKnownInstances,
            vector<SCXHandle<AppServerInstance> >& runningProcesses,
            SCXHandle<IRemoveNonexistentAppServerInstances> remover)
    {
        SCXLogHandle logger = SCXLogHandleFactory::GetLogHandle(L"scx.core.common.pal.system.appserver.appserverenumeration");
        SCX_LOGTRACE(logger, L"Removing nonexistent instances");

        remover->RemoveNonexistentInstances(previouslyKnownInstances);

        SCX_LOGTRACE(logger,
                StrAppend(L"size after removing non-existent instances: ",
                        previouslyKnownInstances.size()));

        // Set all items previously known to be not running
        SCX_LOGTRACE(logger, L"Marking previously known to not running");

        transform(
                previouslyKnownInstances.begin(),
                previouslyKnownInstances.end(),
                previouslyKnownInstances.begin(),
                SetIsRunningToFalse);

        SCX_LOGTRACE(logger, L"Merging running processes to the front of the known instances");

        // Insert the running process to the front of the known instance list
        previouslyKnownInstances.insert( 
                previouslyKnownInstances.begin(),
                runningProcesses.begin(),
                runningProcesses.end() );

        SCX_LOGTRACE(logger, L"Sort the list of known instances (with processes)");

        // Sort the list 
        sort(
                previouslyKnownInstances.begin(), 
                previouslyKnownInstances.end(), 
                PathOrdering);

        SCX_LOGTRACE(logger, L"Setting Deep Monitored flags");

        // Copy the state of the Deep Monitored flag from the previous entry
        // (this is a little confusing because we have a pointer to a pointer 
        // [e.g. an iterator to a SCXHandle] and we are doing pointer arithmetic
        // on the iterator)
        for( vector< SCXHandle<AppServerInstance> >::iterator p =
                previouslyKnownInstances.begin(); 
                previouslyKnownInstances.end() != p; 
                ++p)
        {
          if ( (p+1 != previouslyKnownInstances.end()) && 
                  ((*p)->GetDiskPath() == (*(p+1))->GetDiskPath()) )
          {
              (*p)->SetIsDeepMonitored((*(p+1))->GetIsDeepMonitored(), (*(p+1))->GetProtocol());
          }
        }
        

        // remove duplicate entries
        SCX_LOGTRACE(logger, L"Removing duplicate instances");

        vector<SCXHandle<AppServerInstance> >::iterator newLastElement =
                unique(
                        previouslyKnownInstances.begin(), 
                        previouslyKnownInstances.end(), 
                        PathCompare);

        previouslyKnownInstances.resize(
                newLastElement-previouslyKnownInstances.begin());
        
        SCX_LOGTRACE(logger,
                StrAppend(L"size after removing duplicates: ",
                        previouslyKnownInstances.size()));

    }

    /*
       Delegate method used comparing AppServerInstances based-on
       their path on disk.  Other properties like running state and
       port are not used because only the path on disk is important
       for removing duplicates between the process list and the cache.

        \param[in]  i - handle to a AppServerInstance
        \param[in]  j - handle to another AppServerInstance
        \returns    true if a string comparision determines that 
                    path on disk for element i is equal to the 
                    path on disk for element j

     */
    bool ManipulateAppServerInstances::PathCompare (
            SCXHandle<AppServerInstance> i, 
            SCXHandle<AppServerInstance> j) 
    { 
      return i->GetDiskPath() == j->GetDiskPath();
    }

    /*
       Delegate method used for ordering the AppServerInstances
       by their path.

        \param[in]  i - handle to a AppServerInstance
        \param[in]  j - handle to another AppServerInstance
        \returns    true if a string comparision determines that 
                    path on disk for element i is less than the
                    path on disk for element j
     */
    bool ManipulateAppServerInstances::PathOrdering (
            SCXHandle<AppServerInstance> i, 
            SCXHandle<AppServerInstance> j) 
    { 
        bool result = false;

        // In general, the sorting is done by comparing/deciding
        // the paths of the application server instances. In the
        // event that the paths are equal, then the sorting is
        // done by the IsRunning property (the running ones should
        // be in front).
        if (i->GetDiskPath() == j->GetDiskPath())
        {
            result = i->GetIsRunning();
        }
        else
        {
            result = i->GetDiskPath() < j->GetDiskPath();
        }

        return result;
    }

    /*
       Delegate method setting the IsRunning flag to false
       
        \param[in]  i - handle to a AppServerInstance
        \returns    a copy of the input element with the IsRunning flag
                    set to false
     */
    SCXHandle<AppServerInstance> ManipulateAppServerInstances::SetIsRunningToFalse(
            SCXHandle<AppServerInstance> i) 
    { 
      i->SetIsRunning(false);
      return i;
    }

}

/*----------------------------E-N-D---O-F---F-I-L-E---------------------------*/
