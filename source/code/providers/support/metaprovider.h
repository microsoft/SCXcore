/*--------------------------------------------------------------------------------
 *        Copyright (c) Microsoft Corporation.  All rights reserved.
 *     
 *        */
 /**
      \file        metaprovider.h

      \brief       Meta provider (SCX_Agent)

      \date        04-01-03

*/
/*----------------------------------------------------------------------------*/

#ifndef METAPROVIDER_H
#define METAPROVIDER_H

#include <scxcorelib/scxcmn.h>

#include <scxcorelib/scxlog.h>
#include <scxcorelib/scxtime.h>

#include <MI.h>

namespace SCXCore
{
    /*----------------------------------------------------------------------------*/
    /**
       Meta provider

       Provide base system information to the SCX_Agent provider.
    */
    class MetaProvider
    {
    public:
        MetaProvider()
            : m_buildTimeOK(false),
              m_readInstallInfoFile(false)
        { }
        virtual ~MetaProvider() { };

        virtual const std::wstring DumpString() const
        {
            return L"MetaProvider";
        }

        void Load();
        void Unload();
        bool GetInstallInfoData(std::string& installVersion, MI_Datetime& installTime);
        bool GetBuildTime(std::string& buildTime);

        SCXCoreLib::SCXLogHandle& GetLogHandle()
        {
            return m_log;
        }

    private:
        void ReadInstallInfoFile();
        void GetReleaseDate();

        //! Set to true if build time could be parsed OK
        bool m_buildTimeOK;
        //! build time set at compile time
        SCXCoreLib::SCXCalendarTime m_buildTime;

        //! Set to true if all info could be read from the install info file
        bool m_readInstallInfoFile;
        //! Install time read from install info file
        SCXCoreLib::SCXCalendarTime m_installTime;
        //! Install version read from install info file
        std::wstring m_installVersion;

        SCXCoreLib::SCXLogHandle m_log;
        static int ms_loadCount;
    };

    extern SCXCore::MetaProvider g_MetaProvider;
}

#endif // #ifndef METAPROVIDER_H
