/*--------------------------------------------------------------------------------
 *        Copyright (c) Microsoft Corporation.  All rights reserved.
*/
/**
      \file        osprovider.h

      \brief       OS provider

      \date        04-22-03
*/
/*----------------------------------------------------------------------------*/

#ifndef OSPROVIDER_H
#define OSPROVIDER_H

#include <scxcorelib/scxcmn.h>
#include <scxcorelib/scxlog.h>
#include <scxsystemlib/memoryenumeration.h>

using namespace SCXCoreLib;
using namespace SCXSystemLib;

namespace SCXCore
{
    class OSProvider
    {
    public:
        OSProvider();
        virtual ~OSProvider();

        void Load();
        void Unload();

        SCXHandle<OSEnumeration> GetOS_Enumerator() { return m_osEnum; }
        SCXHandle<MemoryEnumeration> GetMemory_Enumerator() { return m_memEnum; }
        SCXHandle<SCXOSTypeInfo> GetOSTypeInfo() { return m_OSTypeInfo; }
        SCXLogHandle& GetLogHandle() { return m_log; }
        virtual const std::wstring DumpString() const { return L"OSProvider"; }

    private:
        //! PAL implementation representing os information for local host
        SCXCoreLib::SCXHandle<OSEnumeration> m_osEnum;

        //! PAL implementation representing memory information for local host
        SCXCoreLib::SCXHandle<MemoryEnumeration> m_memEnum;

        //! PAL for providing static OS information
        SCXCoreLib::SCXHandle<SCXOSTypeInfo> m_OSTypeInfo;

        SCXCoreLib::SCXLogHandle m_log;
        static int ms_loadCount;
    };

    extern OSProvider g_OSProvider;
}

#endif /* OSPROVIDER_H */

/*----------------------------E-N-D---O-F---F-I-L-E---------------------------*/

