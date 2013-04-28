/*------------------------------------------------------------------------------
    Copyright (c) Microsoft Corporation.  All rights reserved.
    
*/
/**
    \file
 
    \brief     LogFile utility header file
 
    \date      2011-3-09
 
*/
/*----------------------------------------------------------------------------*/
#ifndef LOGFILEUTILS_H
#define LOGFILEUTILS_H

#include <sys/stat.h>

#include <string>
#include <vector>
#include <istream>

#include <scxcorelib/scxlog.h>
#include <scxcorelib/scxpersistence.h>
#include <scxcorelib/scxpatternfinder.h>
#include <scxcorelib/scxregex.h>

namespace SCXCore
{
    class LogFileReader
    {
    public:             /* Public only for test purposes ... */
        /**
           Persistable representation of a log file with a current position.
           The persistence key is the logfile path together with the qid.
        */
        class LogFilePositionRecord
        {
        public:
            LogFilePositionRecord(const SCXCoreLib::SCXFilePath& logfile,
                                  const std::wstring& qid,
                                  SCXCoreLib::SCXHandle<SCXCoreLib::SCXPersistMedia> persistMedia = SCXCoreLib::GetPersistMedia());
            const SCXCoreLib::SCXFilePath& GetLogFile() const;
            std::streamoff GetPos() const;
            void SetPos(std::streamoff pos);
            scxulong GetStatStIno() const;
            void SetStatStIno(scxulong st_ino);
            scxulong GetStatStSize() const;
            void SetStatStSize(scxulong st_size);

            void Persist();
            bool Recover();
            bool UnPersist();

        private:
            SCXCoreLib::SCXHandle<SCXCoreLib::SCXPersistMedia> m_PersistMedia; //!< Handle to persistence framework.
            const SCXCoreLib::SCXFilePath m_LogFile; //!< Log file path.
            std::wstring m_IdString; //!< Persistence id string created from file name and qid.
            
            std::streamoff m_Pos;   //!< file end pos
            scxulong m_StIno;       //!< st_ino field of a stat struct.
            scxulong m_StSize;      //!< st_size field of a stat struct.
        };

        /**
           Class with responsibility of maintaining opening a log file at the correct
           position depending on information in a LogFilePositionRecord.
        */
        class LogFileStreamPositioner
        {
        public:
            LogFileStreamPositioner(const SCXCoreLib::SCXFilePath& logfile,
                                    const std::wstring& qid,
                                    SCXCoreLib::SCXHandle<SCXCoreLib::SCXPersistMedia> persistMedia = SCXCoreLib::GetPersistMedia());
            SCXCoreLib::SCXHandle<std::wfstream> GetStream();
            void PersistState();

        private:
            SCXCoreLib::SCXHandle<LogFilePositionRecord> m_Record; //!< Handle to record with persistable data.
            SCXCoreLib::SCXHandle<std::wfstream> m_Stream; //!< Handle to currently open stream.
            SCXCoreLib::SCXLogHandle m_log; //!< Handle to log framework.

            bool IsFileNew() const;
            void UpdateStatData();
        };

    public:
        LogFileReader();
        ~LogFileReader() {}

        bool ReadLogFile(
            const std::wstring& filename,
            const std::wstring& qid,
            const std::vector<SCXCoreLib::SCXRegexWithIndex>& regexps,
            std::vector<std::wstring>& matchedLines);

        // Public solely for unit tests ...
        void SetPersistMedia(SCXCoreLib::SCXHandle<SCXCoreLib::SCXPersistMedia> persistMedia);

    protected:
        /**
            Internal representation of a log file.
        */
        class SCXLogFile
        {
        public:
            std::wstring name;       //!< file name
            std::streamoff pos;      //!< file end pos
            struct stat64 statinfo;  //!< file information
            bool statvalid;          //!< statinfo valid flag
        };

    private:
        std::wstring GetFileName(const std::wstring& query);
        SCXLogFile* GetLogFile(const std::wstring& filename);
        bool CheckFileWrap(const struct stat64& oldstatinfo, const struct stat64& newstatinfo);

        std::vector<SCXLogFile> m_files;   //!< log files

        SCXCoreLib::SCXLogHandle m_log; //!< Handle to log framework.
        SCXCoreLib::SCXHandle<SCXCoreLib::SCXPersistMedia> m_persistMedia; //!< Persist media to use
        SCXCoreLib::SCXPatternFinder m_cqlPatterns; //!< Supported cql patterns finder.
        static const SCXCoreLib::SCXPatternFinder::SCXPatternCookie s_patternID; //!< Supported pattern identifier.
        static const std::wstring s_pattern; //!< The actual pattern supported
        static const std::wstring s_patternParameter; //!< name of parameter in pattern.
    };
}

#endif /* LOGFILEUTILS_H */
/*----------------------------E-N-D---O-F---F-I-L-E---------------------------*/
