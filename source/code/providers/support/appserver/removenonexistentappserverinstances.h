/*--------------------------------------------------------------------------------
  Copyright (c) Microsoft Corporation. All rights reserved. See license.txt for license information.
*/
/**
   \file        removenonexistentappserverinstances.h

   \brief       Remove AppServerInstances from an array if they are no 
                longer on disk

   \date        11-05-27 12:00:00

*/
/*----------------------------------------------------------------------------*/
#ifndef REMOVENONEXISTENTAPPSERVERINSTANCES_H
#define REMOVENONEXISTENTAPPSERVERINSTANCES_H

#include <string>
#include <scxcorelib/scxcmn.h>

namespace SCXSystemLib
{
    /*--------------------------------------------------------*/
    /**
       Class that represents an how to persist application server instances 
    */
    class IRemoveNonexistentAppServerInstances
    {
    public:
        virtual ~IRemoveNonexistentAppServerInstances() {};

        
        /*--------------------------------------------------------*/
        /**
           Given a list of instances, remove the instances that are
           can no longer be found on disk
        */
        virtual void RemoveNonexistentInstances(
                std::vector<SCXCoreLib::SCXHandle<AppServerInstance> >& instances) = 0;

    };

    /*--------------------------------------------------------*/
    /**
       Class that represents an how to persist application server instances 
    */
    class RemoveNonexistentAppServerInstances :
        public IRemoveNonexistentAppServerInstances
    {

        public:
    
            /*
             * Default no-arg constructor, uses the
             * default/production values
             */
            RemoveNonexistentAppServerInstances();

            /*
             * Destructor
             */
            virtual ~RemoveNonexistentAppServerInstances();

            /*--------------------------------------------------------*/
            /**
               Given a list of instances, remove the instances that are
               can no longer be found on disk
            */
            virtual void RemoveNonexistentInstances(
                    std::vector<SCXCoreLib::SCXHandle<AppServerInstance> >& instances);

        private:
            /*--------------------------------------------------------*/
            /**
               Predicate Helper method for deciding which instances to remove
            */
            static bool RemoveNonExistentInstanceHelper(
                    SCXCoreLib::SCXHandle<AppServerInstance>);
    };

}

#endif /* REMOVENONEXISTENTAPPSERVERINSTANCES_H */
/*----------------------------E-N-D---O-F---F-I-L-E---------------------------*/
