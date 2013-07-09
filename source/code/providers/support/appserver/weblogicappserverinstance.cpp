/*--------------------------------------------------------------------------------
 Copyright (c) Microsoft Corporation.  All rights reserved.

 */
/**
 \file        weblogicappserverinstances.cpp

 \brief       PAL representation of a WebLogic application server

 \date        11-08-18 12:00:00
 */
/*----------------------------------------------------------------------------*/

#include <scxcorelib/scxcmn.h>
#include <string>
#include <scxcorelib/stringaid.h>

#include "appserverconstants.h"
#include "appserverinstance.h"
#include "weblogicappserverinstance.h"

using namespace std;
using namespace SCXCoreLib;

namespace SCXSystemLib {

    /*----------------------------------------------------------------------------*/
    /**
     Constructor

     \param[in]  id            Identifier for the appserver (= install 
     path for the appserver)
     \param[in]  deps          Dependency instance to use
     */
    WebLogicAppServerInstance::WebLogicAppServerInstance(const wstring& id) :
        AppServerInstance(id, APP_SERVER_TYPE_WEBLOGIC) {
        SCX_LOGTRACE(m_log, wstring(L"WebLogicAppServerInstance default constructor - ").append(GetId()));
    }

    /*----------------------------------------------------------------------------*/
    /**
     Destructor
     */
    WebLogicAppServerInstance::~WebLogicAppServerInstance()
    {
        SCX_LOGTRACE(m_log, wstring(L"WebLogicAppServerInstance destructor - ").append(GetId()));
    }

    /*----------------------------------------------------------------------------*/
    /**
        Update values

    */
    void WebLogicAppServerInstance::Update()
    {
        SCX_LOGTRACE(m_log, wstring(L"WebLogicAppServerInstance::Update() - ").append(GetId()));
    }

    
    /**
        Extract the major version number from the complete version

        \param[in]     version   version of the application server
        Retval:        major version number
    */
    wstring WebLogicAppServerInstance::ExtractMajorVersion(const wstring& version)
    {
        vector<wstring> parts;

        StrTokenizeStr(version, parts, L".");
        wstring returnValue = L"";
        
        if (parts.size() >= 3)
        {
            // version consists of:
            //
            //      major.minor.revision
            //
            // i.e. 10.3.2 maps to
            //
            //      major:    10
            //      minor:    3
            //      revision: 2
            unsigned int major = StrToUInt(parts[0]);
            unsigned int minor = StrToUInt(parts[1]);
            unsigned int revision = StrToUInt(parts[2]);
            
            switch (major)
            {
              case 1:
              case 2:
              case 3:
              case 4:
              case 5:
              case 6:
              case 7:
              case 8:
              case 9:
                  returnValue = parts[0];
                  break;
              case 10:
                  if (WEBLOGIC_VERSION_MINOR == minor)
                  {
                      if (0 == revision)
                      {
                           returnValue = WEBLOGIC_BRANDED_VERSION_10;                         
                      }
                      else
                      {
                           returnValue = WEBLOGIC_BRANDED_VERSION_11;
                      }                      
                  }
                  else if (minor < WEBLOGIC_VERSION_MINOR)
                  {
                      returnValue = WEBLOGIC_BRANDED_VERSION_10;
                  }
                  else //if (minor > WEBLOGIC_VERSION_MINOR)
                  {
                      returnValue = WEBLOGIC_BRANDED_VERSION_11;
                  }
                  
                  break;
                case 12:
                    returnValue = parts[0];
                    break;
                default:
                    returnValue = WEBLOGIC_BRANDED_VERSION_11;
            }
        }

        return returnValue;
    }
}

/*----------------------------E-N-D---O-F---F-I-L-E---------------------------*/
