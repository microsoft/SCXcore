/*--------------------------------------------------------------------------------
 *        Copyright (c) Microsoft Corporation.  All rights reserved.
 *     
 *        */
 /**
      \file        memoryprovider.h

      \brief       Memory provider

      \date        04-18-03

*/
/*----------------------------------------------------------------------------*/

#ifndef MEMORYPROVIDER_H
#define MEMORYPROVIDER_H

#include <scxcorelib/scxcmn.h>
#include <scxcorelib/scxlog.h>
#include <scxsystemlib/memoryenumeration.h>

using namespace SCXCoreLib;
using namespace SCXSystemLib;

namespace SCXCore
{
    class MemoryProvider
    {
    public:
        MemoryProvider() { };
        virtual ~MemoryProvider() { };
        void Load();
        void Unload();

        SCXCoreLib::SCXHandle<SCXSystemLib::MemoryEnumeration> GetMemoryEnumeration() const
        {
            return m_memEnum;
        }

        SCXLogHandle& GetLogHandle() { return m_log; }

        virtual const std::wstring DumpString() const
        {
            return L"MemoryProvider";
        }
        
    private:
        SCXCoreLib::SCXHandle<SCXSystemLib::MemoryEnumeration> m_memEnum;
        SCXCoreLib::SCXLogHandle m_log;
        static int ms_loadCount;
    };

    extern SCXCore::MemoryProvider g_MemoryProvider;
}


#endif /* MEMORYPROVIDER_H */

/*----------------------------E-N-D---O-F---F-I-L-E---------------------------*/

