/*--------------------------------------------------------------------
    Copyright (c) Microsoft Corporation.  All rights reserved.
*/
/**
   \file        weblogicappservcerinstance.h

   \brief       Representation of a WebLogic Application Server instance

   \date        11-08-18 12:00:00
*/
/*--------------------------------------------------------------------*/
#ifndef WEBLOGICAPPSERVERINSTANCE_H
#define WEBLOGICAPPSERVERINSTANCE_H

#include <string>

#include "appserverinstance.h"

namespace SCXSystemLib {
    /*----------------------------------------------------------------*/
    /**
     Class that represents an instances.

     Concrete implementation of an instance of a WebLogic 
     Application Server

     */
    class WebLogicAppServerInstance : public AppServerInstance {
            friend class AppServerEnumeration;

        public:

            WebLogicAppServerInstance(const std::wstring& id);

            virtual ~WebLogicAppServerInstance();

            virtual void Update();

        protected:

            virtual std::wstring ExtractMajorVersion(
                    const std::wstring& version);

    };

}

#endif /* WEBLOGICAPPSERVERINSTANCE_H */
/*----------------------------E-N-D---O-F---F-I-L-E---------------------------*/
