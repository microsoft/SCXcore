/*--------------------------------------------------------------------------------
 *        Copyright (c) Microsoft Corporation.  All rights reserved.
 *      
 *           */
 /**
        \file        appserverprovider.cpp

        \brief       App Server provider implementation
                
                \date        05-08-13 
*/
/*----------------------------------------------------------------------------*/

#include "../startuplog.h"
#include "appserverenumeration.h"
#include "appserverprovider.h"

using namespace SCXSystemLib;
using namespace SCXCoreLib;

namespace SCXCore
{
    void ApplicationServerProvider::Load()
    {
        SCXASSERT( ms_loadCount >= 0 );
        if ( 1 == ++ms_loadCount )
        {
            m_log = SCXLogHandleFactory::GetLogHandle(L"scx.core.providers.appserverprovider");
            LogStartup();
            SCX_LOGTRACE(m_log, L"ApplicationServerProvider::Load()");

            if ( NULL == m_deps )
            {
                m_deps = new AppServerProviderPALDependencies();
            }

            m_appservers = m_deps->CreateEnum();
            m_appservers->Init();
        }
    }

    void ApplicationServerProvider::Unload()
    {
        SCX_LOGTRACE(m_log, L"ApplicationServerProvider::Unload()");

        SCXASSERT( ms_loadCount >= 1 );
        if ( 0 == --ms_loadCount )
        {
            if (NULL != m_appservers)
            {
                m_appservers->CleanUp();
                m_appservers = NULL;
            }

            m_deps = NULL;
        }
    }

    // Only construct ApplicationServer class once
    int ApplicationServerProvider::ms_loadCount = 0;
    ApplicationServerProvider g_AppServerProvider;
}

/*----------------------------E-N-D---O-F---F-I-L-E---------------------------*/

