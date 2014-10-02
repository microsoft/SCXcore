/*------------------------------------------------------------------------------
    Copyright (c) Microsoft Corporation. All rights reserved. See license.txt for license information.
    
*/
/**
    \file      logfileprovider.h
 
    \brief     LogFile provider header file
 
    \date      2008-0-08 09:35:36
 
*/
/*----------------------------------------------------------------------------*/
#ifndef LOGFILEPROVIDER_H
#define LOGFILEPROVIDER_H

#include "logfileutils.h"

namespace SCXCore
{
    /*----------------------------------------------------------------------------*/
    /**
       LogFile provider
    */
    class LogFileProvider
    {
    public:
        LogFileProvider();
        LogFileProvider(SCXCoreLib::SCXHandle<LogFileReader> pReader);
        ~LogFileProvider();

        const std::wstring DumpString() const;
        void Load();
        void Unload();

        SCXCoreLib::SCXLogHandle& GetLogHandle();

        bool InvokeLogFileReader(const std::wstring& filename,
                                 const std::wstring& qid,
                                 const std::vector<SCXCoreLib::SCXRegexWithIndex>& regexps,
                                 bool fPerformElevation,
                                 std::vector<std::wstring>& matchedLines);

        int InvokeResetStateFile(const std::wstring& filename,
                                 const std::wstring& qid,
                                 int resetOnRead,
                                 bool fPerformElevation);

    private:
        SCXCoreLib::SCXHandle<LogFileReader> m_pLogFileReader;
        SCXCoreLib::SCXLogHandle m_log;
        static int ms_loadCount;
    };

    extern LogFileProvider g_LogFileProvider;
}

#endif /* LOGFILEPROVIDER_H */
/*----------------------------E-N-D---O-F---F-I-L-E---------------------------*/
