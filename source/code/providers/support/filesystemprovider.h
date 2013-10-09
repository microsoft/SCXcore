/*--------------------------------------------------------------------------------
 *        Copyright (c) Microsoft Corporation.  All rights reserved.
 *     
 *        */
 /**
      \file        filesystemprovider.h

      \brief       FileSystem provider

      \date        08-30-13
*/
/*----------------------------------------------------------------------------*/

#ifndef FILESYSTEMPROVIDER_H
#define FILESYSTEMPROVIDER_H

#include <scxcorelib/scxlog.h>
#include "startuplog.h"
#include <scxsystemlib/diskdepend.h>
#include <scxsystemlib/entityenumeration.h>
#include <scxsystemlib/staticlogicaldiskenumeration.h>
#include <scxsystemlib/statisticallogicaldiskenumeration.h>
#include <scxcorelib/scxhandle.h>

using namespace SCXCoreLib;
using namespace SCXSystemLib;

namespace SCXCore
{
    /*------------------------------------------------------------------------------*/
    /**
        *   FileSystemProvider 
        *   Helper class to handle the dependency and Logging
        */
    class FileSystemProvider
    {
    public:
        FileSystemProvider()
            : m_staticLogicaldeps(0),
              m_statisticalLogicaldeps(0) { };
        virtual ~FileSystemProvider() { };
        virtual void UpdateDependency(SCXHandle<SCXSystemLib::DiskDepend> staticLogicaldeps,
                                      SCXHandle<SCXSystemLib::DiskDepend> statisticalLogicaldeps) 
        { 
            m_staticLogicaldeps = staticLogicaldeps;
            m_statisticalLogicaldeps = statisticalLogicaldeps;
        }

        SCXLogHandle& GetLogHandle() { return m_log; }
        void Load();
        void UnLoad();

        SCXHandle<SCXSystemLib::StatisticalLogicalDiskEnumeration> getEnumstatisticalLogicalDisks() const
        {
            return m_statisticalLogicalDisks;
        }

        SCXHandle<SCXSystemLib::StaticLogicalDiskEnumeration> getEnumstaticLogicalDisks() const
        {
            return m_staticLogicalDisks;
        }

        private:
            SCXHandle<SCXSystemLib::DiskDepend> m_staticLogicaldeps, m_statisticalLogicaldeps;
            SCXCoreLib::SCXLogHandle m_log;
            static int ms_loadCount;

            //! PAL implementation retrieving logical disk information for local host
            SCXHandle<SCXSystemLib::StatisticalLogicalDiskEnumeration> m_statisticalLogicalDisks;
            //! PAL implementation retrieving static logical disk information for local host
            SCXHandle<SCXSystemLib::StaticLogicalDiskEnumeration> m_staticLogicalDisks;
    };

    extern SCXCore::FileSystemProvider g_FileSystemProvider;
}

#endif /* FILESYSTEMPROVIDER_H */

/*----------------------------E-N-D---O-F---F-I-L-E---------------------------*/
