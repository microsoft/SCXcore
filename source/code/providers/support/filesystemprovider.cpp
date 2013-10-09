/*--------------------------------------------------------------------------------
 *        Copyright (c) Microsoft Corporation.  All rights reserved.
 *      
 *           */
 /**
        \file        filesystemprovider.cpp

        \brief       FileSystem provider implementation

        \date        08-30-13 
*/
/*----------------------------------------------------------------------------*/

#include "filesystemprovider.h"
using namespace SCXCoreLib;
using namespace SCXSystemLib;

namespace SCXCore
{
    void FileSystemProvider::Load()
    {
        if ( 1 == ++ms_loadCount )
        {
            m_log = SCXLogHandleFactory::GetLogHandle(L"scx.core.providers.filesystemprovider");
            LogStartup();
            SCX_LOGTRACE(m_log, L"FileSystemProvider::Load");

            // Set up the dependencies;
            m_staticLogicaldeps = new DiskDependDefault();
            m_statisticalLogicaldeps = new DiskDependDefault();

            // Create the enumeration objects
            m_statisticalLogicalDisks = new StatisticalLogicalDiskEnumeration(m_statisticalLogicaldeps);
            m_statisticalLogicalDisks->Init();

            m_staticLogicalDisks = new StaticLogicalDiskEnumeration(m_staticLogicaldeps);
            m_staticLogicalDisks->Init();
        }
    }

    void FileSystemProvider::UnLoad()
    {
        SCX_LOGTRACE(m_log, L"FileSystemProvider::Unload()");
        if (0 == --ms_loadCount)
        {
            if (m_statisticalLogicalDisks != NULL)
            {
                m_statisticalLogicalDisks->CleanUp();
                m_statisticalLogicalDisks = NULL;
            }

            if (m_staticLogicalDisks != NULL)
            {
                m_staticLogicalDisks->CleanUp();
                m_staticLogicalDisks = NULL;
            }
        }
    }

    // Only construct FileSystemProvider class once - installation date/version never changes!
    SCXCore::FileSystemProvider g_FileSystemProvider;
    int SCXCore::FileSystemProvider::ms_loadCount = 0;
}

 /*----------------------------E-N-D---O-F---F-I-L-E---------------------------*/
