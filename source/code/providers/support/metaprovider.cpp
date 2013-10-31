/*--------------------------------------------------------------------------------
 *        Copyright (c) Microsoft Corporation. All rights reserved. See license.txt for license information.
 *     
 *        */
 /**
      \file        metaprovider.h

      \brief       Meta provider (SCX_Agent)

      \date        04-01-03
*/
/*----------------------------------------------------------------------------*/

#include <scxcorelib/scxcmn.h>
#include <scxcorelib/scxlocale.h>
#include <scxcorelib/scxstream.h>

#include "metaprovider.h"
#include "scxcimutils.h"
#include "startuplog.h"

#include "buildversion.h"

#include <fstream>

#if defined(sun)
#include <sys/systeminfo.h>
#include <scxcorelib/scxlocale.h>
#endif


using namespace SCXCoreLib;
//using namespace SCXSystemLib;
using namespace std;

namespace SCXCore
{
    /** Installation information file name */
#if defined (macos)
    static const string installInfoFileName = "/private/etc/opt/microsoft/scx/conf/installinfo.txt";
#else
    static const string installInfoFileName = "/etc/opt/microsoft/scx/conf/installinfo.txt";
#endif

    //
    // Meta provider class implementation
    //

    void MetaProvider::Load()
    {
        // Not strictly necessary to worry about multithreaded use, but here for consistency
        // (Note: This is thread-safe due to upper-level lock in all relevant OMI calls)
        if ( 1 == ++ms_loadCount )
        {
            m_log = SCXCoreLib::SCXLogHandleFactory::GetLogHandle(L"scx.core.providers.metaprovider");
            LogStartup();
            SCX_LOGTRACE(m_log, L"MetaProvider::Load()");

            /* The seems like a suitable place to report the active locale */
            SCX_LOGINFO(m_log, SCXCoreLib::StrAppend(L"Active locale setting is ",
                        SCXCoreLib::SCXLocaleContext::GetActiveLocale()));

            ReadInstallInfoFile();
            GetReleaseDate();
        }
    }

    void MetaProvider::Unload()
    {
        // (Note: This is thread-safe due to upper-level lock in all relevant OMI calls)
        SCX_LOGTRACE(m_log, L"MetaProvider::Unload()");
        --ms_loadCount;
    }

    bool MetaProvider::GetInstallInfoData(string& installVersion, MI_Datetime& installTime)
    {
        if ( m_readInstallInfoFile )
        {
            installVersion = StrToMultibyte(m_installVersion);
            CIMUtils::ConvertToCIMDatetime( installTime, m_installTime );

            return true;
        }

        return false;
    }

    bool MetaProvider::GetBuildTime( string& buildTime )
    {
        if (m_buildTimeOK)
        {
            buildTime = StrToMultibyte( m_buildTime.ToExtendedISO8601() );
            return true;
        }

        return false;
    }

    /*----------------------------------------------------------------------------*/
    /**
       Read installation information from file

       This method reads some proprietary information the SCX installer saves 
       in well-known location. Called from constructor since this reads in 
       information that should not change.

    */
    void MetaProvider::ReadInstallInfoFile()
    {
        std::wifstream infofile( installInfoFileName.c_str() );

        m_readInstallInfoFile = false;

        if (SCXStream::IsGood(infofile))
        {
            vector<wstring> lines;
            SCXStream::NLFs nlfs;

            // Read all lines from install info file
            // First line should be install date on ISO8601 format
            // Second line should be install version string
            // Example:
            // 2008-03-17T17:28:32.0Z
            // 1.0.1-70
            SCXStream::ReadAllLines(infofile, lines, nlfs);
            if (lines.size() == 2)
            {
                SCX_LOGTRACE(m_log, StrAppend(L"Read time from installinfo file: ", lines[0]));
                SCX_LOGTRACE(m_log, StrAppend(L"Read install version from installinfo file: ", lines[1]));

                m_installVersion = lines[1];
                try
                {
                    m_installTime = SCXCalendarTime::FromISO8601(lines[0]);
                    m_readInstallInfoFile = true;
                }
                catch (SCXCoreLib::SCXException &e)
                {
                    SCX_LOGERROR(m_log, StrAppend(StrAppend(StrAppend(L"Failed to convert install time string to SCXCalenderTime: ", lines[0]), L" - "), e.What()));
                }
            }
            else
            {
                SCX_LOGERROR(m_log, StrAppend(L"Wrong number of rows in install info file. Expected 2, got: ", lines.size()));
            }
        }
        else
        {
            std::wstring errStr = L"Failed to open installinfo file " + StrFromMultibyte(installInfoFileName);
            SCX_LOGERROR(m_log, errStr);
        }
    }


    /*----------------------------------------------------------------------------*/
    /**
       Convert build date string to SCXCalendarTime

       At compile time the build timestamp is provided by preprocessor in 
       SCX_BUILDVERSION_DATE. This method converts time format to SCXCalendarTime.

    */
    void MetaProvider::GetReleaseDate()
    {
        m_buildTimeOK = false;

        wstring buildDate(SCX_BUILDVERSION_DATE);

        if (buildDate.length() == 8)
        {
            wstring buildYear = buildDate.substr(0, 4);
            wstring buildMonth = buildDate.substr(4, 2);
            wstring buildDay = buildDate.substr(6, 2);

            try
            {
                m_buildTime = SCXCalendarTime(StrToUInt(buildYear),StrToUInt(buildMonth),StrToUInt(buildDay));
                m_buildTimeOK = true;
                SCX_LOGTRACE(m_log, StrAppend(L"Build time: ", buildDate));
            }
            catch (SCXCoreLib::SCXException& e)
            {
                SCX_LOGERROR(m_log, StrAppend(L"Failed to convert build time string to SCXCalenderTime: ", buildDate));
            }
        }
        else
        {
            SCX_LOGWARNING(m_log, StrAppend(L"Build time string is not correct length: ", buildDate));
        }
    }

    // Only construct MetaProvider class once - installation date/version never changes!
    int SCXCore::MetaProvider::ms_loadCount = 0;
    SCXCore::MetaProvider g_MetaProvider;

    /*----------------------------------------------------------------------------*/
    /**
       Log the startup message once regardless of how many times called
       
       This function will be called from all provider ctors except RunAs to 
       provide one initial log, regardless of how many times called.
       
    */
    void LogStartup(void) 
    {
        static bool bLoggedInitMessage = false;
        if (!bLoggedInitMessage) 
        {
            SCXCoreLib::SCXLogHandle log = SCXLogHandleFactory::GetLogHandle(L"scx.core.providers");
            SCX_LOGINFO(log, L"SCX Provider Module loaded");
            
#if defined(sun)
            // Log any errors encountered during SCXLocaleContext initialization.
            for (size_t i = 0; i < SCXLocaleContext::GetErrors().size(); i++)
            {
                SCX_LOGWARNING(log, SCXLocaleContext::GetErrors()[i]);
            }
            
#endif /* defined(sun) */
            
            bLoggedInitMessage = true;
        }
    }
}

 /*----------------------------E-N-D---O-F---F-I-L-E---------------------------*/
