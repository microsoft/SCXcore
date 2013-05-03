/*--------------------------------------------------------------------------------
 *        Copyright (c) Microsoft Corporation.  All rights reserved.
 *      
 *           */
 /**
        \file        osprovider.cpp

        \brief       OS provider implementation
                
                \date        04-26-13 
*/
/*----------------------------------------------------------------------------*/

#include <scxsystemlib/osenumeration.h>
#include "startuplog.h"
#include "osprovider.h"

using namespace SCXSystemLib;
using namespace SCXCoreLib;

namespace SCXCore
{
    //
    // OS Provider Implementation
    //

    /*----------------------------------------------------------------------------*/
    /**
       Default constructor
    */
    OSProvider::OSProvider() :
        m_osEnum(NULL),
        m_memEnum(NULL),
        m_OSTypeInfo(NULL)
    {
    }

    /*----------------------------------------------------------------------------*/
    /**
       Destructor
    */
    OSProvider::~OSProvider()
    {
    }

    void OSProvider::Load()
    {
        SCXASSERT( ms_loadCount >= 0 );
        if ( 1 == ++ms_loadCount )
        {
            m_log = SCXLogHandleFactory::GetLogHandle(L"scx.core.providers.osprovider");
            LogStartup();
            SCX_LOGTRACE(m_log, L"OSProvider::Load()");

            // Operating system provider
            SCXASSERT( NULL == m_osEnum );
            m_osEnum = new OSEnumeration();
            m_osEnum->Init();

            // We need the memory provider for some stuff as well
            SCXASSERT( NULL == m_memEnum );
            m_memEnum = new MemoryEnumeration();
            m_memEnum->Init();

            // And OS type information
            SCXASSERT( NULL == m_OSTypeInfo );
            m_OSTypeInfo = new SCXOSTypeInfo();
        }
    }

    void OSProvider::Unload()
    {
        SCX_LOGTRACE(m_log, L"OSProvider::Unload()");

        SCXASSERT( ms_loadCount >= 1 );
        if (0 == --ms_loadCount)
        {
            if (m_osEnum != NULL)
            {
                m_osEnum->CleanUp();
                m_osEnum = NULL;
            }

            if (m_memEnum != NULL)
            {
                m_memEnum->CleanUp();
                m_memEnum = NULL;
            }

            m_OSTypeInfo = NULL;
        }
    }

    int OSProvider::ms_loadCount = 0;
    OSProvider g_OSProvider;
}

/*----------------------------E-N-D---O-F---F-I-L-E---------------------------*/
 
