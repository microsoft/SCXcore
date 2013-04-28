/*--------------------------------------------------------------------------------
 *        Copyright (c) Microsoft Corporation.  All rights reserved.
 *     
 *        */
 /**
      \file        diskprovider.h

      \brief       Disk provider

      \date        03-21-03

*/
/*----------------------------------------------------------------------------*/

#ifndef DISKPROVIDER_H
#define DISKPROVIDER_H

#include <scxcorelib/scxlog.h>
#include "startuplog.h"
#include <scxsystemlib/diskdepend.h>
#include <scxsystemlib/entityenumeration.h>
#include <scxsystemlib/staticphysicaldiskenumeration.h>
#include <scxsystemlib/staticlogicaldiskenumeration.h>
#include <scxsystemlib/statisticalphysicaldiskenumeration.h>
#include <scxsystemlib/statisticallogicaldiskenumeration.h>
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
              m_staticLogicaldeps(0),
              m_statiticalLogicaldeps(0),
              m_statisticalPhysicsdeps(0) { };
        virtual ~DiskProvider() { };
        virtual void UpdateDependency(SCXHandle<SCXSystemLib::DiskDepend> staticPhysicaldeps,
                                      SCXHandle<SCXSystemLib::DiskDepend> staticLogicaldeps,
                                      SCXHandle<SCXSystemLib::DiskDepend> statisticalPhysicsdeps,
                                      SCXHandle<SCXSystemLib::DiskDepend> statiticalLogicaldeps) 
        { 
            m_staticPhysicaldeps = staticPhysicaldeps;
            m_staticLogicaldeps = staticLogicaldeps;
            m_statisticalPhysicsdeps = statisticalPhysicsdeps;
            m_statiticalLogicaldeps = statiticalLogicaldeps;
        }

        SCXLogHandle& GetLogHandle() { return m_log; }
        void Load();
        void UnLoad();

        SCXHandle<SCXSystemLib::StatisticalLogicalDiskEnumeration> getEnumstatisticalLogicalDisks() const
        {
            return m_statisticalLogicalDisks;
        }

        SCXHandle<SCXSystemLib::StatisticalPhysicalDiskEnumeration> getEnumstatisticalPhysicalDisks() const
        {
            return m_statisticalPhysicalDisks;
        }

        SCXHandle<SCXSystemLib::StaticLogicalDiskEnumeration> getEnumstaticLogicalDisks() const
        {
            return m_staticLogicalDisks;
        }

        SCXHandle<SCXSystemLib::StaticPhysicalDiskEnumeration> getEnumstaticPhysicalDisks() const
        {
            return m_staticPhysicalDisks;
        }

        private:
            SCXHandle<SCXSystemLib::DiskDepend> m_staticPhysicaldeps, m_staticLogicaldeps, m_statiticalLogicaldeps, m_statisticalPhysicsdeps;
            SCXCoreLib::SCXLogHandle m_log;
            static int ms_loadCount;

            //! PAL implementation retrieving logical disk information for local host
            SCXHandle<SCXSystemLib::StatisticalLogicalDiskEnumeration> m_statisticalLogicalDisks;
            //!PAL implementation retrieving physical disk information for local host
            SCXHandle<SCXSystemLib::StatisticalPhysicalDiskEnumeration> m_statisticalPhysicalDisks;
            //! PAL implementation retrieving static logical disk information for local host
            SCXHandle<SCXSystemLib::StaticLogicalDiskEnumeration> m_staticLogicalDisks;
            //! PAL implementation retrieving static physical disk information for local host
            SCXHandle<SCXSystemLib::StaticPhysicalDiskEnumeration> m_staticPhysicalDisks;
    };

    extern SCXCore::DiskProvider g_DiskProvider;
}

#endif /* DISKPROVIDER_H */

/*----------------------------E-N-D---O-F---F-I-L-E---------------------------*/
