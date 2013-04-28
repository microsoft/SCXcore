/*------------------------------------------------------------------------------
    Copyright (c) Microsoft Corporation.  All rights reserved.
    
*/
/**
    \file
 
    \brief     Main implementation file for Log File Provider
 
    \date      2008-0-08 09:35:36
 

*/
/*----------------------------------------------------------------------------*/

#include <scxcorelib/scxcmn.h>
#include <scxcorelib/scxexception.h>
#include <scxcorelib/scxfile.h>
#include <scxcorelib/scxmarshal.h>
#include <scxcorelib/scxprocess.h>
#include <scxsystemlib/scxsysteminfo.h>

#include <errno.h>
#include <stdlib.h>

#include "logfileprovider.h"
#include "logfileutils.h"
#include "startuplog.h"

using namespace SCXCoreLib;
using namespace std;

namespace SCXCore {
    // Static assignments
    int LogFileProvider::ms_loadCount = 0;


    /*----------------------------------------------------------------------------*/
    /**
       Default constructor
    */
    LogFileProvider::LogFileProvider() :
        m_pLogFileReader(NULL)
    {
        // Assuming we have one global object - initialized at load time
    }

    LogFileProvider::LogFileProvider(SCXCoreLib::SCXHandle<LogFileReader> pLogFileReader)
        : m_pLogFileReader(pLogFileReader)
    {
        // Assuming we have one global object - initialized at load time
    }

    /*----------------------------------------------------------------------------*/
    /**
       Destructor
    */
    LogFileProvider::~LogFileProvider()
    {
        // Do not log here since when this destructor is called the objects neccesary for logging might no longer be alive
    }

    void LogFileProvider::Load()
    {
        m_log = SCXLogHandleFactory::GetLogHandle(L"scx.core.providers.logfileprovider");

        SCXASSERT( ms_loadCount >= 0 );
        if ( 1 == ++ms_loadCount )
        {
            m_log = SCXLogHandleFactory::GetLogHandle(L"scx.core.providers.logfileprovider");
            LogStartup();
            SCX_LOGTRACE(m_log, L"LogFileProvider::Load()");

            if (NULL == m_pLogFileReader)
            {
                m_pLogFileReader = new LogFileReader();
            }
        }
    }

    void LogFileProvider::Unload()
    {
        SCX_LOGTRACE(m_log, L"LogFileProvider::Unload()");

        SCXASSERT( ms_loadCount >= 1 );
        if ( 0 == --ms_loadCount )
        {
            m_pLogFileReader = NULL;
        }
    }

    SCXLogHandle& LogFileProvider::GetLogHandle()
    {
        return m_log;
    }

    /**
        Dump object as string (for logging).
    
        \returns       The object represented as a string suitable for logging.
    */
    const std::wstring LogFileProvider::DumpString() const
    {
        return L"LogFileProvider";
    }

    /*----------------------------------------------------------------------------*/
    /**
        Invoke the logfileread CLI (command line) program, with elevation if needed

        \param[in]     filename          Filename to scan for matches
        \param[in]     qid               QID used for state file handling
        \param[in]     regexps           List of regular expressions to look for
        \param[in]     performElevation  Perform elevation when running the command
        \param[out]    matchedLines      Resulting matched lines, if any, from log file

        \returns       Boolean flag to indicate if partial matches were returned
    */
    bool LogFileProvider::InvokeLogFileReader(
        const std::wstring& filename,
        const std::wstring& qid,
        const std::vector<SCXRegexWithIndex>& regexps,
        bool fPerformElevation,
        std::vector<std::wstring>& matchedLines)
    {
        SCX_LOGTRACE(m_log, L"SCXLogFileProvider InvokeLogFileReader");

        // Process of log file was called by something like:
        //
        // bPartial = m_pLFR->ReadLogFile(filename, qid, regexps, matchedLines);
        //
        // Marshal our data to send along to the subprocess
        // (Note that matchedLines is returned, along with partial flag)

        std::stringstream processInput;
        std::stringstream processOutput;
        std::stringstream processError;

        SCX_LOGTRACE(m_log, L"SCXLogFileProvider InvokeLogFileReader - Marshaling");

        Marshal send(processInput);
        send.Write(filename);
        send.Write(qid);
        send.Write(regexps);
        send.Flush();

        // Test to see if we're running under testrunner.  This makes it easy
        // to know where to launch our test program, allowing unit tests to
        // test all the way through to the CLI.

        wstring programName;
        char *testrunFlag = getenv("SCX_TESTRUN_ACTIVE");
        if (NULL != testrunFlag)
        {
            programName = L"scxlogfilereader -t -p";
        }
        else
        {
            programName = L"/opt/microsoft/scx/bin/scxlogfilereader -p";
        }

        // Elevate the command if that's called for
        SCXSystemLib::SystemInfo si;

        if (fPerformElevation)
        {
            programName = si.GetElevatedCommand(programName);
        }

        // Call the log file reader (CLI) program

        SCX_LOGTRACE(m_log,
                     StrAppend(L"SCXLogFileProvider InvokeLogFileReader - Running ",
                               programName));

        try
        {
            int returnCode = SCXProcess::Run(
                programName,
                processInput, processOutput, processError);

            SCX_LOGTRACE(m_log,
                         StrAppend(L"SCXLogFileProvider InvokeLogFileReader - Result ", returnCode));

            switch (returnCode)
            {
                case 0:
                    // Normal exit code
                    break;
                case ENOENT:
                    // Log file didn't exist - scxlogfilereader logged message about it
                    // Nothing to unmarshal at this point ...
                    return false;
                default:
                    wstringstream errorMsg;
                    errorMsg << L"Unexpected return code running '"
                             << programName
                             << L"': "
                             << returnCode;

                    throw SCXInternalErrorException(errorMsg.str(), SCXSRCLOCATION);
            }
        }
        catch (SCXCoreLib::SCXException& e)
        {
            SCX_LOGWARNING(m_log, StrAppend(L"LogFileProvider InvokeLogFileReader - Exception: ", e.What()));
            throw;
        }

        // Unmarshall matchedLines and partialRead flag
        //
        // Note that we can't marshal/unmarshal a bool, so we treat as int

        int wasPartialRead;

        SCX_LOGTRACE(m_log, L"SCXLogFileProvider InvokeLogFileReader - UnMarshaling");

        UnMarshal receive(processOutput);
        receive.Read(wasPartialRead);
        receive.Read(matchedLines);

        SCX_LOGTRACE(m_log, StrAppend(L"SCXLogFileProvider InvokeLogFileReader - Returning: ", (0 != wasPartialRead)));

        return (0 != wasPartialRead);
    }

    LogFileProvider g_LogFileProvider;
}

/*----------------------------E-N-D---O-F---F-I-L-E---------------------------*/
