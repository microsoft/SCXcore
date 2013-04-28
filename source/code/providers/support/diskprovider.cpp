/*--------------------------------------------------------------------------------
 *        Copyright (c) Microsoft Corporation.  All rights reserved.
 *      
 *           */
 /**
        \file        diskprovider.cpp

        \brief       Disk provider implementation
                
                \date        03-21-13 
*/
/*----------------------------------------------------------------------------*/

#include "diskprovider.h"
using namespace SCXCoreLib;
using namespace SCXSystemLib;

namespace SCXCore
{
    void DiskProvider::Load()
    {
        if ( 1 == ++ms_loadCount )
        {
            m_log = SCXLogHandleFactory::GetLogHandle(L"scx.core.providers.diskprovider");
            LogStartup();
            SCX_LOGTRACE(m_log, L"DiskProvider::Load");

            // Set up the dependencies;
            m_staticPhysicaldeps = new DiskDependDefault();
            m_staticLogicaldeps = new DiskDependDefault();
            m_statiticalLogicaldeps = new DiskDependDefault();
            m_statisticalPhysicsdeps = new DiskDependDefault();

            // Create the enumeration objects
            m_statisticalPhysicalDisks = new StatisticalPhysicalDiskEnumeration(m_statisticalPhysicsdeps);
            m_statisticalPhysicalDisks->Init();

            m_statisticalLogicalDisks = new StatisticalLogicalDiskEnumeration(m_statiticalLogicaldeps);
            m_statisticalLogicalDisks->Init();

            m_staticPhysicalDisks = new StaticPhysicalDiskEnumeration(m_staticPhysicaldeps);
            m_staticPhysicalDisks->Init();

            m_staticLogicalDisks = new StaticLogicalDiskEnumeration(m_staticLogicaldeps);
            m_staticLogicalDisks->Init();
        }
    }

    void DiskProvider::UnLoad()
    {
        SCX_LOGTRACE(m_log, L"DiskProvider::Unload()");
        if (0 == --ms_loadCount)
        {

            if (m_statisticalPhysicalDisks != NULL)
            {
                m_statisticalPhysicalDisks->CleanUp();
                m_statisticalPhysicalDisks = NULL;
            }

            if (m_statisticalLogicalDisks != NULL)
            {
                m_statisticalLogicalDisks->CleanUp();
                m_statisticalLogicalDisks = NULL;
            }

            if (m_staticPhysicalDisks != NULL)
            {
                m_staticPhysicalDisks->CleanUp();
                m_staticPhysicalDisks = NULL;
            }

            if (m_staticLogicalDisks != NULL)
            {
                m_staticLogicalDisks->CleanUp();
                m_staticLogicalDisks = NULL;
            }
        }
    }

    // Only construct DiskProvider class once - installation date/version never changes!
    SCXCore::DiskProvider g_DiskProvider;
    int SCXCore::DiskProvider::ms_loadCount = 0;
}

 /*----------------------------E-N-D---O-F---F-I-L-E---------------------------*/
