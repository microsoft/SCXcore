/*--------------------------------------------------------------------------------
 *        Copyright (c) Microsoft Corporation.  All rights reserved.
 *     
 *        */
 /**
      \file        diskprovider.h

      \brief       Disk provider

      \date        03-21-13

*/
/*----------------------------------------------------------------------------*/

#ifndef DISKPROVIDER_H
#define DISKPROVIDER_H

#include <scxcorelib/scxlog.h>
#include "startuplog.h"
#include <scxsystemlib/diskdepend.h>
#include <scxsystemlib/entityenumeration.h>
#include <scxsystemlib/staticphysicaldiskenumeration.h>
#include <scxsystemlib/statisticalphysicaldiskenumeration.h>
#include <scxcorelib/scxhandle.h>

using namespace SCXCoreLib;
using namespace SCXSystemLib;

namespace SCXCore
{
    /*------------------------------------------------------------------------------*/
    /**
        *   DiskProvider 
        *   Helper class to handle the dependency and Logging
        */
    class DiskProvider
    {
    public:
        DiskProvider()
            : m_staticPhysicaldeps(0),
              m_statisticalPhysicsdeps(0) { };
        virtual ~DiskProvider() { };
        virtual void UpdateDependency(SCXHandle<SCXSystemLib::DiskDepend> staticPhysicaldeps,
                                      SCXHandle<SCXSystemLib::DiskDepend> statisticalPhysicsdeps) 
        { 
            m_staticPhysicaldeps = staticPhysicaldeps;
            m_statisticalPhysicsdeps = statisticalPhysicsdeps;
        }

        SCXLogHandle& GetLogHandle() { return m_log; }
        void Load();
        void UnLoad();

        SCXHandle<SCXSystemLib::StatisticalPhysicalDiskEnumeration> getEnumstatisticalPhysicalDisks() const
        {
            return m_statisticalPhysicalDisks;
        }

        SCXHandle<SCXSystemLib::StaticPhysicalDiskEnumeration> getEnumstaticPhysicalDisks() const
        {
            return m_staticPhysicalDisks;
        }

        private:
            SCXHandle<SCXSystemLib::DiskDepend> m_staticPhysicaldeps, m_statisticalPhysicsdeps;
            SCXCoreLib::SCXLogHandle m_log;
            static int ms_loadCount;

            //!PAL implementation retrieving physical disk information for local host
            SCXHandle<SCXSystemLib::StatisticalPhysicalDiskEnumeration> m_statisticalPhysicalDisks;
            //! PAL implementation retrieving static physical disk information for local host
            SCXHandle<SCXSystemLib::StaticPhysicalDiskEnumeration> m_staticPhysicalDisks;
    };

    extern SCXCore::DiskProvider g_DiskProvider;
}

#endif /* DISKPROVIDER_H */

/*----------------------------E-N-D---O-F---F-I-L-E---------------------------*/
