/*--------------------------------------------------------------------------------
 *        Copyright (c) Microsoft Corporation.  All rights reserved.
 *      
 *           */
 /**
        \file        memoryprovider.cpp

        \brief       Memory provider implementation
                
                \date        04-18-13 
*/
/*----------------------------------------------------------------------------*/

#include "startuplog.h"
#include "memoryprovider.h"

using namespace SCXSystemLib;
using namespace SCXCoreLib;

namespace SCXCore
{
    void MemoryProvider::Load()
    {
        if ( 1 == ++ms_loadCount )
        {
            m_log = SCXLogHandleFactory::GetLogHandle(L"scx.core.providers.memoryprovider");
            LogStartup();
            SCX_LOGTRACE(m_log, L"MemoryProvider::Load()");

            m_memEnum = new MemoryEnumeration();
            m_memEnum->Init();
        }
    }

    void MemoryProvider::Unload()
    {
        SCX_LOGTRACE(m_log, L"MemoryProvider::Unload()");
        if (0 == --ms_loadCount)
        {
            if (m_memEnum != NULL)
            {
                m_memEnum->CleanUp();
                m_memEnum == NULL;
            }
        }
    }

    SCXCore::MemoryProvider g_MemoryProvider;
    int SCXCore::MemoryProvider::ms_loadCount = 0;
}

/*----------------------------E-N-D---O-F---F-I-L-E---------------------------*/

