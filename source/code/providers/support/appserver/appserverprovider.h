/*--------------------------------------------------------------------------------
 *        Copyright (c) Microsoft Corporation.  All rights reserved.
 *     
 *        */
 /**
      \file        appserverprovider.h

      \brief       App Server provider

      \date        05-08-03

*/
/*----------------------------------------------------------------------------*/

#ifndef APPSERVERPROVIDER_H
#define APPSERVERPROVIDER_H

#include <scxcorelib/scxcmn.h>
#include <scxcorelib/scxlog.h>

using namespace SCXCoreLib;
using namespace SCXSystemLib;

namespace SCXCore
{
    /*----------------------------------------------------------------------------*/
    /**
       Class representing all external dependencies from the AppServer PAL.

    */
    class AppServerProviderPALDependencies
    {
    public:
        virtual ~AppServerProviderPALDependencies() {};

        virtual SCXCoreLib::SCXHandle<SCXSystemLib::AppServerEnumeration> CreateEnum()
        {
            return SCXHandle<AppServerEnumeration>(new AppServerEnumeration());
        }
    };

    /*----------------------------------------------------------------------------*/
    /**
       Application Server provider

       Provide Application Services capabilities for OMI
    */
    class ApplicationServerProvider
    {
    public:
        ApplicationServerProvider()
            : m_deps(NULL),
              m_appservers(NULL)
        { }
        virtual ~ApplicationServerProvider() { }

        virtual const std::wstring DumpString() const
        {
            return L"ApplicationServerProvider";
        }

        void Load();

        void Unload();

        void UpdateDependencies(SCXCoreLib::SCXHandle<AppServerProviderPALDependencies> deps)
        {
            m_deps = deps;
        }

        SCXCoreLib::SCXHandle<SCXSystemLib::AppServerEnumeration> GetAppServers()
        {
            return m_appservers;
        }

        SCXLogHandle& GetLogHandle()
        {
            return m_log;
        }

    private:
        SCXCoreLib::SCXLogHandle m_log;
        static int ms_loadCount;

        SCXCoreLib::SCXHandle<AppServerProviderPALDependencies> m_deps;

        //! PAL implementation retrieving appserver information for local host
        SCXCoreLib::SCXHandle<SCXSystemLib::AppServerEnumeration> m_appservers;
    };

    extern ApplicationServerProvider g_AppServerProvider;
}

#endif /* APPSERVERPROVIDER_H */

/*----------------------------E-N-D---O-F---F-I-L-E---------------------------*/

