/*--------------------------------------------------------------------------------
    Copyright (c) Microsoft Corporation. All rights reserved. See license.txt for license information.
*/
/**
   \file        removenonexistentappserverinstances.cpp

   \brief       Means of removing non-existent application server instances 
                from an array if the instances are no longer on disk

   \date        11-05-27 12:00:00

 */
/*-----------------------------------------------------------------*/

#include <scxcorelib/scxcmn.h>

#include <algorithm>
#include <functional>
#include <string>
#include <vector>

#include <scxcorelib/stringaid.h>

#include "appserverinstance.h"
#include "removenonexistentappserverinstances.h"

using namespace std;
using namespace SCXCoreLib;
using namespace SCXSystemLib;

namespace SCXSystemLib
{

    /*-----------------------------------------------------------------*/
    /**
       Constructor (no arg)
     */
    RemoveNonexistentAppServerInstances::RemoveNonexistentAppServerInstances()
    {
    }

    /*-----------------------------------------------------------------*/
    /**
       Destructor
     */
    RemoveNonexistentAppServerInstances::~RemoveNonexistentAppServerInstances()
    {
    }

    /*--------------------------------------------------------*/
    /**
       Given a list of instances, remove the instances that are
       can no longer be found on disk
       
       \param[in/out] instances - vector of Application Server Instances 
                                  to be manipulated
       
    */
    void RemoveNonexistentAppServerInstances::RemoveNonexistentInstances(
            vector<SCXHandle<AppServerInstance> >& instances)
    {
        vector<SCXHandle<AppServerInstance> >::iterator 
        tmp = remove_if(
                instances.begin(), 
                instances.end(), 
                RemoveNonExistentInstanceHelper);
        instances.resize(tmp-instances.begin());
    }

    /*--------------------------------------------------------*/
    /**
       Predicate Helper method for deciding which instances to remove
       
       \param[in] instance - Application Server Instance to check
       \return - true if the file does NOT exist on disk (i.e. should the 
                 file be removed)
       
    */
    bool RemoveNonexistentAppServerInstances::RemoveNonExistentInstanceHelper(
            SCXHandle<AppServerInstance> instance)
    {
        return !instance->IsStillInstalled();
    }

}

/*----------------------------E-N-D---O-F---F-I-L-E---------------------------*/
