/*--------------------------------------------------------------------------------
  Copyright (c) Microsoft Corporation.  All rights reserved.

*/
/**
   \file

   \brief       Tests for the logfile provider

   \date        2008-08-26 13:19:10

*/
/*----------------------------------------------------------------------------*/

#include <scxcorelib/scxcmn.h>

#include <scxcorelib/scxexception.h>
#include <scxcorelib/scxfile.h>
#include <scxcorelib/scxprocess.h>
#include <scxcorelib/stringaid.h>
#include "source/code/scxcorelib/util/persist/scxfilepersistmedia.h"

#include <support/logfileprovider.h>
#include <support/logfileutils.h>

#include <cppunit/extensions/HelperMacros.h>
#include <testutils/scxunit.h>
#include <testutils/providertestutils.h>
#include <testutils/scxtestutils.h>

#include <stdio.h>  // For fopen() in test testLocale8859_1
#include <sys/wait.h>
#if defined(aix)
#include <unistd.h>
#endif

#include "SCX_LogFile_Class_Provider.h"

// dynamic_cast fix - wi 11220
#ifdef dynamic_cast
#undef dynamic_cast
#endif

using namespace SCXCore;
using namespace SCXCoreLib;

class TestableLogfileProvider : public LogFileProvider
{
public:
    TestableLogfileProvider(SCXCoreLib::SCXHandle<LogFileReader> pLogFileReader) :
        LogFileProvider(pLogFileReader)
    {
        m_pLogFileReader = pLogFileReader;
    }

    void TestSetPersistMedia(SCXCoreLib::SCXHandle<SCXCoreLib::SCXPersistMedia> persistMedia) 
    {
        m_pLogFileReader->SetPersistMedia(persistMedia);
    }

private:
    // No implementation; do not use default constructor for unit tests!
    TestableLogfileProvider();

    SCXCoreLib::SCXHandle<LogFileReader> m_pLogFileReader;
};

const std::wstring testlocalefilename = L"./testfiles/scxlogfilereader-locale";
const std::wstring testlogfilename = L"./logfileproviderTest.log";
const std::wstring testQID = L"TestQID";
const std::wstring testQID2 = L"AnotherTestQID";

class LogFileProviderTest : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE( LogFileProviderTest );
    CPPUNIT_TEST( callDumpStringForCoverage );
    CPPUNIT_TEST( testLogFilePositionRecordCreateNewRecord );
    CPPUNIT_TEST( testLogFilePositionRecordPersistable );
    CPPUNIT_TEST( testLogFilePositionRecordUnpersist );
    CPPUNIT_TEST( testLogFilePositionRecordConflictingPaths );
    CPPUNIT_TEST( testLogFileStreamPositionerOpenNew );
    CPPUNIT_TEST( testLogFileStreamPositionerReOpen );
    // testTellgBehavior() exists to investigate WI 15418, and eventually WI 16772
    //CPPUNIT_TEST( testTellgBehavior );
    CPPUNIT_TEST( testLogFileStreamPersistSmallerFile );
    CPPUNIT_TEST( testLogFileStreamPositionerNoFile );
    CPPUNIT_TEST( testLogFileStreamPositionerFileRotateSize );
    CPPUNIT_TEST( testLogFileStreamPositionerFileRotateInode );
    CPPUNIT_TEST( testLogFileStreamPositionerFileDisappearsAndReappears );
    CPPUNIT_TEST( testDoInvokeMethod );
    CPPUNIT_TEST( testDoInvokeMethodWithNonexistantLogfile );
    CPPUNIT_TEST( testInvokeResetStateFile );
    CPPUNIT_TEST( testInvokeResetStateFileWithResetFlag );
    CPPUNIT_TEST( testInvokeResetAllStateFiles );
    CPPUNIT_TEST( testInvokeResetAllStateFilesWithResetFlag );
    CPPUNIT_TEST( testLocale8859_1 );

    SCXUNIT_TEST_ATTRIBUTE(testLogFilePositionRecordPersistable, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(testLogFilePositionRecordUnpersist, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(testDoInvokeMethod, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(testDoInvokeMethodWithNonexistantLogfile, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(testInvokeResetStateFile, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(testInvokeResetStateFileWithResetFlag, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(testInvokeResetAllStateFiles, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(testInvokeResetAllStateFilesWithResetFlag, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(testLocale8859_1, SLOW);
    CPPUNIT_TEST_SUITE_END();

private:
    SCXHandle<SCXPersistMedia> m_pmedia;
    SCXCoreLib::SCXHandle<TestableLogfileProvider> m_logFileProv;
    SCXCoreLib::SCXHandle<LogFileReader> m_pReader;

public:
    LogFileProviderTest() : m_pReader(new LogFileReader()) { }

    void setUp(void)
    {
        m_pmedia = GetPersistMedia();
        SCXFilePersistMedia* m = dynamic_cast<SCXFilePersistMedia*> (m_pmedia.GetData());
        CPPUNIT_ASSERT(m != 0);
        m->SetBasePath(L"./");

        SCXHandle<LogFileReader::LogFilePositionRecord> r( 
            new LogFileReader::LogFilePositionRecord(testlogfilename, testQID, m_pmedia) );
        r->UnPersist();
        SCXHandle<LogFileReader::LogFilePositionRecord> r2(
            new LogFileReader::LogFilePositionRecord(testlogfilename, testQID2, m_pmedia) );
        r2->UnPersist();

        m_logFileProv = new TestableLogfileProvider(m_pReader);
        m_logFileProv->TestSetPersistMedia(m_pmedia);

        std::wstring errMsg;
        TestableContext context;
        SetUpAgent<mi::SCX_LogFile_Class_Provider>(context, CALL_LOCATION(errMsg));
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, true, context.WasRefuseUnloadCalled() );

        // Delete the locale file if it exists
        SCXCoreLib::SelfDeletingFilePath localeFile( testlocalefilename );
    }

    void tearDown(void)
    {
        std::wstring errMsg;
        TestableContext context;
        TearDownAgent<mi::SCX_LogFile_Class_Provider>(context, CALL_LOCATION(errMsg));
        CPPUNIT_ASSERT_EQUAL_MESSAGE(ERROR_MESSAGE, false, context.WasRefuseUnloadCalled() );

        m_logFileProv = 0;
        SCXHandle<LogFileReader::LogFilePositionRecord> r(
            new LogFileReader::LogFilePositionRecord(testlogfilename, testQID, m_pmedia) );
        r->UnPersist();
        SCXFile::Delete(testlogfilename);
        SCXHandle<LogFileReader::LogFilePositionRecord> r2( 
            new LogFileReader::LogFilePositionRecord(testlogfilename, testQID2, m_pmedia) );
        r2->UnPersist();

        // Delete the locale file if it exists
        SCXCoreLib::SelfDeletingFilePath localeFile( testlocalefilename );
    }

    void callDumpStringForCoverage()
    {
        CPPUNIT_ASSERT(m_logFileProv->DumpString().find(L"LogFileProvider") != std::wstring::npos);
    }

    void testLogFilePositionRecordCreateNewRecord()
    {
        LogFileReader::LogFilePositionRecord r(L"/This/is/a/file/path.log", testQID);
        CPPUNIT_ASSERT(0 == r.GetPos());
        CPPUNIT_ASSERT(0 == r.GetStatStIno());
        CPPUNIT_ASSERT(0 == r.GetStatStSize());
    }

    void testLogFilePositionRecordPersistable()
    {
        pid_t pid = fork();
        CPPUNIT_ASSERT(-1 != pid);
        if (0 == pid)
        {
            // Child process will do the writing.
            LogFileReader::LogFilePositionRecord r(L"/This/is/a/file/path.log", testQID, m_pmedia);
            r.SetPos(1337);
            r.SetStatStIno(17);
            r.SetStatStSize(4711);
            CPPUNIT_ASSERT_NO_THROW(r.Persist());
            exit(0);
        }

        // Parent process will do the reading after child has finished.
        waitpid(pid, 0, 0);

        LogFileReader::LogFilePositionRecord r(L"/This/is/a/file/path.log", testQID, m_pmedia);
        CPPUNIT_ASSERT(r.Recover());
        CPPUNIT_ASSERT(1337 == r.GetPos());
        CPPUNIT_ASSERT(17 == r.GetStatStIno());
        CPPUNIT_ASSERT(4711 == r.GetStatStSize());
        
        CPPUNIT_ASSERT(r.UnPersist());
    }

    void testLogFilePositionRecordUnpersist()
    {
        LogFileReader::LogFilePositionRecord r(L"/This/is/a/file/path.log", testQID, m_pmedia);
        CPPUNIT_ASSERT( ! r.Recover() );
        CPPUNIT_ASSERT( ! r.UnPersist() );
        CPPUNIT_ASSERT_NO_THROW(r.Persist());
        CPPUNIT_ASSERT( r.Recover() );
        CPPUNIT_ASSERT( r.UnPersist() );
        CPPUNIT_ASSERT( ! r.Recover() );
    }

    void testLogFilePositionRecordConflictingPaths()
    {
        {
            LogFileReader::LogFilePositionRecord r1(L"/This/is/a/file_path.log", testQID, m_pmedia);
            LogFileReader::LogFilePositionRecord r2(L"/This_is/a_file/path.log", testQID, m_pmedia);

            r1.SetPos(1337);
            r1.SetStatStIno(17);
            r1.SetStatStSize(4711);
            CPPUNIT_ASSERT_NO_THROW(r1.Persist());

            r2.SetPos(1338);
            r2.SetStatStIno(18);
            r2.SetStatStSize(4712);
            CPPUNIT_ASSERT_NO_THROW(r2.Persist());
        }
        
        LogFileReader::LogFilePositionRecord r1(L"/This/is/a/file_path.log", testQID, m_pmedia);
        LogFileReader::LogFilePositionRecord r2(L"/This_is/a_file/path.log", testQID, m_pmedia);

        CPPUNIT_ASSERT_NO_THROW(r1.Recover());
        CPPUNIT_ASSERT(1337 == r1.GetPos());
        CPPUNIT_ASSERT(17 == r1.GetStatStIno());
        CPPUNIT_ASSERT(4711 == r1.GetStatStSize());

        CPPUNIT_ASSERT_NO_THROW(r2.Recover());
        CPPUNIT_ASSERT(1338 == r2.GetPos());
        CPPUNIT_ASSERT(18 == r2.GetStatStIno());
        CPPUNIT_ASSERT(4712 == r2.GetStatStSize());

        CPPUNIT_ASSERT(r1.UnPersist());
        CPPUNIT_ASSERT(r2.UnPersist());
    }

    void testLogFileStreamPositionerOpenNew()
    {
        std::wstring firstRow(L"This is the first row.");
        std::wstring secondRow(L"This is the second row.");
        {
            SCXHandle<std::wfstream> stream = SCXFile::OpenWFstream(testlogfilename, std::ios_base::out);
        
            *stream << firstRow << std::endl
                    << secondRow << std::endl;
        }

        LogFileReader::LogFileStreamPositioner p(testlogfilename, testQID, m_pmedia);

        // Fist time the file is opened, the position should be at the end of the file.
        SCXHandle<std::wfstream> stream = p.GetStream();
        CPPUNIT_ASSERT( (scxulong) (stream->tellg()) > (scxulong) (firstRow.size() + secondRow.size()) );
        CPPUNIT_ASSERT( ! SCXStream::IsGood(*stream));
    }
    
    void testLogFileStreamPositionerReOpen()
    {
        std::wstring firstRow(L"This is the first row.");
        std::wstring secondRow(L"This is the second row.");

        SCXHandle<std::wfstream> outstream = SCXFile::OpenWFstream(testlogfilename, std::ios_base::out);
        *outstream << firstRow << std::endl;
        
        {
            LogFileReader::LogFileStreamPositioner p(testlogfilename, testQID, m_pmedia);
            SCXHandle<std::wfstream> stream = p.GetStream();
            p.PersistState();
        }

        // Write some more to the file.
        *outstream << secondRow << std::endl;
        

        LogFileReader::LogFileStreamPositioner p(testlogfilename, testQID, m_pmedia);
        SCXHandle<std::wfstream> stream = p.GetStream();
        std::wstring line;
        getline(*stream, line);
        CPPUNIT_ASSERT(secondRow == line);
    }

    void testTellgBehavior()
    {
        std::wstring firstRow(L"This is the first row.");       // 23 bytes
        std::wstring secondRow(L"This is the second row.");     // 24 bytes

        // Write the file

        {
            SCXHandle<std::wfstream> outstream = SCXFile::OpenWFstream(testlogfilename, std::ios_base::out);
            *outstream << firstRow << std::endl;
        }

        // Read it in a separate stream

        LogFileReader::LogFileStreamPositioner p(testlogfilename, testQID, m_pmedia);
        SCXHandle<std::wfstream> stream = p.GetStream();
        p.PersistState();

        // Verify that we're at EOF

        CPPUNIT_ASSERT(!SCXStream::IsGood(*stream));
        std::cout << std::endl;
        std::cout << "stream->tellg(): " << stream->tellg() << std::endl;

        // Now append some data to the file (in a separate process)

        pid_t pid = fork();
        CPPUNIT_ASSERT(-1 != pid);
        if (0 == pid)
        {
            // Child process will do the appending.
            SCXHandle<std::wfstream> outstream = SCXFile::OpenWFstream(testlogfilename,
                    std::ios_base::out | std::ios_base::app);
            *outstream << secondRow << std::endl;
            exit(0);
        }

        // Parent process will do the reading after child has finished.
        waitpid(pid, 0, 0);

        CPPUNIT_ASSERT(!SCXStream::IsGood(*stream));
        std::cout << "stream->tellg(): " << stream->tellg() << std::endl;
    }

    void testLogFileStreamPersistSmallerFile()
    {
        std::wstring firstRow(L"This is the first row.");       // 23 bytes
        std::wstring secondRow(L"This is the second row.");     // 24 bytes

        // Write the file (23 + 24 bytes = 47 bytes)

        {
            SCXHandle<std::wfstream> outstream = SCXFile::OpenWFstream(testlogfilename, std::ios_base::out);
            *outstream << firstRow << std::endl << secondRow << std::endl;
        }
        
        // Persist the size and state information

        {
            LogFileReader::LogFileStreamPositioner p(testlogfilename, testQID, m_pmedia);
            SCXHandle<std::wfstream> stream = p.GetStream();
            p.PersistState();
        }

        // Verify the persisted size and state information

        {
            LogFileReader::LogFilePositionRecord r(testlogfilename, testQID, m_pmedia);
            CPPUNIT_ASSERT(r.Recover());
            CPPUNIT_ASSERT(47 == r.GetPos());
            CPPUNIT_ASSERT(0 != r.GetStatStIno());
            CPPUNIT_ASSERT(47 == r.GetStatStSize());
        }

        // Rewrite the file now to a smaller size (23 bytes)

        {
            SCXHandle<std::wfstream> outstream = SCXFile::OpenWFstream(testlogfilename, std::ios_base::out);
            *outstream << firstRow << std::endl;
        }

        // Reread the file twice:
        //   First time, we should get the new data
        //   Second time, we should not
        //
        // NOTE: We must use SCXStream::ReadLine() to read the stream.  This is
        //      how the "real" provider does it, and we leave the stream in a
        //      "bad" state otherwise.  Always test if the stream is "good"
        //      prior to trying to read it.

        {
            std::wstring line;
            SCXStream::NLF nlf;

            LogFileReader::LogFileStreamPositioner p(testlogfilename, testQID, m_pmedia);
            SCXHandle<std::wfstream> stream = p.GetStream();

            CPPUNIT_ASSERT(SCXStream::IsGood(*stream));
            SCXStream::ReadLine(*stream, line, nlf);
            CPPUNIT_ASSERT(firstRow == line);

            // Be sure we're now at EOF (no more lines in the file)
            CPPUNIT_ASSERT(!SCXStream::IsGood(*stream));

            p.PersistState();
        }

        {
            LogFileReader::LogFileStreamPositioner p(testlogfilename, testQID, m_pmedia);
            SCXHandle<std::wfstream> stream = p.GetStream();

            // Be sure that there's nothing further in the stream
            CPPUNIT_ASSERT(!SCXStream::IsGood(*stream));
        }
    }

    void testLogFileStreamPositionerNoFile()
    {
        CPPUNIT_ASSERT_THROW(LogFileReader::LogFileStreamPositioner p(testlogfilename, testQID, m_pmedia), SCXFilePathNotFoundException);
    }

    void testLogFileStreamPositionerFileRotateSize()
    {
        std::wstring firstRow(L"This is the first row.");
        std::wstring secondRow(L"This is the second row.");
        {
            SCXHandle<std::wfstream> stream = SCXFile::OpenWFstream(testlogfilename, std::ios_base::out);
            *stream << firstRow << std::endl
                    << secondRow << std::endl;
        }

        {
            LogFileReader::LogFileStreamPositioner p(testlogfilename, testQID, m_pmedia);
            SCXHandle<std::wfstream> stream = p.GetStream();
            p.PersistState();
        }

        // Rewrite the file. This should make it a new file
        {
            SCXFile::Delete(testlogfilename);
            SCXHandle<std::wfstream> stream = SCXFile::OpenWFstream(testlogfilename, std::ios_base::out);
            *stream << firstRow << std::endl;
        }

        LogFileReader::LogFileStreamPositioner p(testlogfilename, testQID, m_pmedia);
        SCXHandle<std::wfstream> stream = p.GetStream();
        // This time we should be positioned at the top of the file.
        CPPUNIT_ASSERT( 0 == stream->tellg() );
        
        std::wstring line;
        getline(*stream, line);
        CPPUNIT_ASSERT(firstRow == line);
    }

    void testLogFileStreamPositionerFileRotateInode()
    {
        std::wstring firstRow(L"This is the first row.");
        std::wstring secondRow(L"This is the second row.");
        {
            SCXHandle<std::wfstream> stream = SCXFile::OpenWFstream(testlogfilename, std::ios_base::out);
            *stream << firstRow << std::endl
                    << secondRow << std::endl;
        }

        {
            LogFileReader::LogFileStreamPositioner p(testlogfilename, testQID, m_pmedia);
            SCXHandle<std::wfstream> stream = p.GetStream();
            p.PersistState();
            // If we move the file while it is open it should retain its inode number.
            SCXFile::Move(testlogfilename, L"./logfileproviderTest2.log");
        }

        // Rewrite the file. This should generate a new inode number.
        {
            SCXHandle<std::wfstream> stream = SCXFile::OpenWFstream(testlogfilename, std::ios_base::out);
            *stream << firstRow << std::endl
                    << secondRow << std::endl;
        }

        SCXFile::Delete(L"./logfileproviderTest2.log"); // clean up.

        LogFileReader::LogFileStreamPositioner p(testlogfilename, testQID, m_pmedia);
        SCXHandle<std::wfstream> stream = p.GetStream();
        // This time we should be positioned at the top of the file.
        CPPUNIT_ASSERT( 0 == stream->tellg() );
        
        std::wstring line;
        getline(*stream, line);
        CPPUNIT_ASSERT(firstRow == line);
        getline(*stream, line);
        CPPUNIT_ASSERT(secondRow == line);
    }

    void testLogFileStreamPositionerFileDisappearsAndReappears()
    {
        std::wstring firstRow(L"This is the first row.");
        std::wstring secondRow(L"This is the second row.");
        {
            SCXHandle<std::wfstream> stream = SCXFile::OpenWFstream(testlogfilename, std::ios_base::out);
            *stream << firstRow << std::endl
                    << secondRow << std::endl;
        }

        {
            LogFileReader::LogFileStreamPositioner p(testlogfilename, testQID, m_pmedia);
            p.PersistState();
        }

        // Delete the file
        SCXFile::Delete(testlogfilename);

        CPPUNIT_ASSERT_THROW(LogFileReader::LogFileStreamPositioner p(testlogfilename, testQID, m_pmedia), SCXFilePathNotFoundException);

        // Rewrite the file. This should make it a new file
        {
            SCXHandle<std::wfstream> stream = SCXFile::OpenWFstream(testlogfilename, std::ios_base::out);
            *stream << firstRow << std::endl;
        }

        LogFileReader::LogFileStreamPositioner p(testlogfilename, testQID, m_pmedia);
        SCXHandle<std::wfstream> stream = p.GetStream();
        // This time we should be positioned at the top of the file.
        CPPUNIT_ASSERT( 0 == stream->tellg() );
        
        std::wstring line;
        getline(*stream, line);
        CPPUNIT_ASSERT(firstRow == line);
    }

    std::string DumpProperty_MIStringA(const TestableInstance::PropertyInfo &property, std::wstring errMsg)
    {
        std::wstringstream ret;
        if (property.exists)
        {
            std::vector<std::wstring> rows = property.GetValue_MIStringA(CALL_LOCATION(errMsg));
            ret << L" Size: " << rows.size() << std::endl;
            size_t i;
            for(i = 0; i < rows.size(); i++)
            {
               ret << L"  " << i << L": " << rows[i] << std::endl;
            }
        }
        else
        {
            ret << L" Property not set" << std::endl;
        }
        return SCXCoreLib::StrToMultibyte(ret.str());
    }

    void testDoInvokeMethod ()
    {
        // This test is a little convoluted, but it's a very useful test, so it remains.
        //
        // First, to make this fly:
        //  1. setUp() function (for all tests) resets the environment (clears
        //     the state files) and sets the state file path.  Note that the
        //     state path only happens in the context of this process.
        //
        //  2. logfileprovider (DoInvokeMethod()) ultimately calls code that is
        //     sensitive to if the testrunner is currently running (when tests
        //     are run, createEnv.sh runs, and that sets SCX_TESTRUN_ACTIVE in
        //     the environment).  If running in the context of testrunner, it
        //     invokes the scxlogfilereader CLI program from the build path
        //     (rather than the installed path) AND it passes a special flag,
        //     -t (for test).
        //
        //  3. When run, scxlogfilereader will note if -t is passed and, if so,
        //     it will set the state path to the current default directory.
        //
        // All these things work in concert to allow this test to work properly.
        //
        // Ultimately, this set is an end-to-end functional test of the logfile
        // provider (as such, it will actually invoke the scxlogfilereader CLI
        // program multiple times). It tests that new log files never have lines
        // returned, and that as log files grow, additional lines are returned.
        // Finally, it tests for proper handling of invalid regular expressions.

        const std::wstring invalidRegexpStr = L"InvalidRegexp;0";
        const std::wstring OKRegexpStr = L"1;";
        const std::wstring moreRowsStr = L"MoreRowsAvailable;true";

        std::wstring errMsg;
        TestableContext context;
        mi::SCX_LogFile_Class instanceName;
        mi::StringA regexps;
        regexps.PushBack("[a");// Invalid regular expression.
        regexps.PushBack(".*");
        mi::Module Module;
        mi::SCX_LogFile_Class_Provider agent(&Module);
        
        // Call with missing filename.
        mi::SCX_LogFile_GetMatchedRows_Class paramNoFilename;
        paramNoFilename.regexps_value(regexps);
        paramNoFilename.qid_value(SCXCoreLib::StrToMultibyte(testQID).c_str());
        context.Reset();
        agent.Invoke_GetMatchedRows(context, NULL, instanceName, paramNoFilename);
        CPPUNIT_ASSERT_EQUAL(MI_RESULT_INVALID_PARAMETER, context.GetResult());
        
        // Call with missing regular expression.
        mi::SCX_LogFile_GetMatchedRows_Class paramNoRegEx;
        paramNoRegEx.filename_value(SCXCoreLib::StrToMultibyte(testlogfilename).c_str());
        paramNoRegEx.qid_value(SCXCoreLib::StrToMultibyte(testQID).c_str());
        context.Reset();
        agent.Invoke_GetMatchedRows(context, NULL, instanceName, paramNoRegEx);
        CPPUNIT_ASSERT_EQUAL(MI_RESULT_INVALID_PARAMETER, context.GetResult());
        
        // Call with missing qid.
        mi::SCX_LogFile_GetMatchedRows_Class paramNoQid;
        paramNoQid.filename_value(SCXCoreLib::StrToMultibyte(testlogfilename).c_str());
        paramNoQid.regexps_value(regexps);
        context.Reset();
        agent.Invoke_GetMatchedRows(context, NULL, instanceName, paramNoQid);
        CPPUNIT_ASSERT_EQUAL(MI_RESULT_INVALID_PARAMETER, context.GetResult());

        // Create a log file with one row in it.
        SCXHandle<std::wfstream> stream = SCXFile::OpenWFstream(testlogfilename, std::ios_base::out);
        *stream << L"This is the first row." << std::endl;

        mi::SCX_LogFile_GetMatchedRows_Class param;
        param.filename_value(SCXCoreLib::StrToMultibyte(testlogfilename).c_str());
        param.regexps_value(regexps);
        param.qid_value(SCXCoreLib::StrToMultibyte(testQID).c_str());
        context.Reset();
        agent.Invoke_GetMatchedRows(context, NULL, instanceName, param);
        CPPUNIT_ASSERT_EQUAL(MI_RESULT_OK, context.GetResult());
        CPPUNIT_ASSERT_EQUAL(1u, context.Size());
        CPPUNIT_ASSERT_EQUAL(2u, context[0].GetNumberOfProperties());
        // First call should return only one status row.
        CPPUNIT_ASSERT_EQUAL(1u, context[0].GetProperty("rows", CALL_LOCATION(errMsg)).
            GetValue_MIStringA(CALL_LOCATION(errMsg)).size());
        CPPUNIT_ASSERT_EQUAL(invalidRegexpStr,
            context[0].GetProperty("rows", CALL_LOCATION(errMsg)).GetValue_MIStringA(CALL_LOCATION(errMsg))[0]);

        mi::SCX_LogFile_GetMatchedRows_Class param2;
        param2.filename_value(SCXCoreLib::StrToMultibyte(testlogfilename).c_str());
        param2.regexps_value(regexps);
        param2.qid_value(SCXCoreLib::StrToMultibyte(testQID2).c_str());
        context.Reset();
        agent.Invoke_GetMatchedRows(context, NULL, instanceName, param2);
        CPPUNIT_ASSERT_EQUAL(MI_RESULT_OK, context.GetResult());
        CPPUNIT_ASSERT_EQUAL(1u, context.Size());
        CPPUNIT_ASSERT_EQUAL(2u, context[0].GetNumberOfProperties());
        // First call with new QID should return only one status row.
        CPPUNIT_ASSERT_EQUAL_MESSAGE(DumpProperty_MIStringA(context[0].GetProperty(
            "rows", CALL_LOCATION(errMsg)), CALL_LOCATION(errMsg)),
            1u, context[0].GetProperty("rows", CALL_LOCATION(errMsg)).GetValue_MIStringA(CALL_LOCATION(errMsg)).size());
        CPPUNIT_ASSERT_EQUAL(invalidRegexpStr,
            context[0].GetProperty("rows", CALL_LOCATION(errMsg)).GetValue_MIStringA(CALL_LOCATION(errMsg))[0]);

        // Add another row to the log file.
        const std::wstring secondRow(L"This is the second row.");
        *stream << secondRow << std::endl;

        context.Reset();
        agent.Invoke_GetMatchedRows(context, NULL, instanceName, param);
        CPPUNIT_ASSERT_EQUAL(MI_RESULT_OK, context.GetResult());
        CPPUNIT_ASSERT_EQUAL(1u, context.Size());
        CPPUNIT_ASSERT_EQUAL(2u, context[0].GetNumberOfProperties());
        // Should get 1 new row and one status row.
        CPPUNIT_ASSERT_EQUAL(2u, context[0].GetProperty("rows", CALL_LOCATION(errMsg)).
            GetValue_MIStringA(CALL_LOCATION(errMsg)).size());
        CPPUNIT_ASSERT_EQUAL(invalidRegexpStr,
            context[0].GetProperty("rows", CALL_LOCATION(errMsg)).GetValue_MIStringA(CALL_LOCATION(errMsg))[0]);
        CPPUNIT_ASSERT_EQUAL(StrAppend(OKRegexpStr, secondRow),
            context[0].GetProperty("rows", CALL_LOCATION(errMsg)).GetValue_MIStringA(CALL_LOCATION(errMsg))[1]);

        // Add yet another row to the log file.
        const std::wstring thirdRow(L"This is the third row.");
        *stream << thirdRow << std::endl;

        context.Reset();
        agent.Invoke_GetMatchedRows(context, NULL, instanceName, param2);
        CPPUNIT_ASSERT_EQUAL(MI_RESULT_OK, context.GetResult());
        CPPUNIT_ASSERT_EQUAL(1u, context.Size());
        CPPUNIT_ASSERT_EQUAL(2u, context[0].GetNumberOfProperties());
        // Using new QID should get two new rows and one status row.
        CPPUNIT_ASSERT_EQUAL(3u, context[0].GetProperty("rows", CALL_LOCATION(errMsg)).
            GetValue_MIStringA(CALL_LOCATION(errMsg)).size());
        CPPUNIT_ASSERT_EQUAL(invalidRegexpStr,
            context[0].GetProperty("rows", CALL_LOCATION(errMsg)).GetValue_MIStringA(CALL_LOCATION(errMsg))[0]);
        CPPUNIT_ASSERT_EQUAL(StrAppend(OKRegexpStr, secondRow),
            context[0].GetProperty("rows", CALL_LOCATION(errMsg)).GetValue_MIStringA(CALL_LOCATION(errMsg))[1]);
        CPPUNIT_ASSERT_EQUAL(StrAppend(OKRegexpStr, thirdRow),
            context[0].GetProperty("rows", CALL_LOCATION(errMsg)).GetValue_MIStringA(CALL_LOCATION(errMsg))[2]);

        context.Reset();
        agent.Invoke_GetMatchedRows(context, NULL, instanceName, param);
        CPPUNIT_ASSERT_EQUAL(MI_RESULT_OK, context.GetResult());
        CPPUNIT_ASSERT_EQUAL(1u, context.Size());
        CPPUNIT_ASSERT_EQUAL(2u, context[0].GetNumberOfProperties());
        // Should get one new row and one status row.
        CPPUNIT_ASSERT_EQUAL(2u, context[0].GetProperty("rows", CALL_LOCATION(errMsg)).
            GetValue_MIStringA(CALL_LOCATION(errMsg)).size());
        CPPUNIT_ASSERT_EQUAL(invalidRegexpStr,
            context[0].GetProperty("rows", CALL_LOCATION(errMsg)).GetValue_MIStringA(CALL_LOCATION(errMsg))[0]);
        CPPUNIT_ASSERT_EQUAL(StrAppend(OKRegexpStr, thirdRow),
            context[0].GetProperty("rows", CALL_LOCATION(errMsg)).GetValue_MIStringA(CALL_LOCATION(errMsg))[1]);

        // Add another 800 rows to the log file.
        for (int i=0; i<800; i++)
        {
            *stream << L"This is another row." << std::endl;
        }

        size_t rowCnt = 0;
        context.Reset();
        agent.Invoke_GetMatchedRows(context, NULL, instanceName, param);
        CPPUNIT_ASSERT_EQUAL(MI_RESULT_OK, context.GetResult());
        CPPUNIT_ASSERT_EQUAL(1u, context.Size());
        CPPUNIT_ASSERT_EQUAL(2u, context[0].GetNumberOfProperties());
        rowCnt = context[0].GetProperty("rows", CALL_LOCATION(errMsg)).GetValue_MIStringA(CALL_LOCATION(errMsg)).size();
        // Should get first 500 rows and two status rows.
        CPPUNIT_ASSERT_EQUAL(502u, rowCnt);
        CPPUNIT_ASSERT_EQUAL(moreRowsStr,
            context[0].GetProperty("rows", CALL_LOCATION(errMsg)).GetValue_MIStringA(CALL_LOCATION(errMsg))[rowCnt - 1]);

        context.Reset();
        agent.Invoke_GetMatchedRows(context, NULL, instanceName, param);
        CPPUNIT_ASSERT_EQUAL(MI_RESULT_OK, context.GetResult());
        CPPUNIT_ASSERT_EQUAL(1u, context.Size());
        CPPUNIT_ASSERT_EQUAL(2u, context[0].GetNumberOfProperties());
        rowCnt = context[0].GetProperty("rows", CALL_LOCATION(errMsg)).GetValue_MIStringA(CALL_LOCATION(errMsg)).size();
        // Should get next 300 rows and one status row.
        CPPUNIT_ASSERT_EQUAL(301u, rowCnt);
        CPPUNIT_ASSERT(moreRowsStr !=
            context[0].GetProperty("rows", CALL_LOCATION(errMsg)).GetValue_MIStringA(CALL_LOCATION(errMsg))[rowCnt - 1]);


        mi::StringA regexps2;
        regexps2.PushBack("warning");
        regexps2.PushBack("error");
        mi::SCX_LogFile_GetMatchedRows_Class param3;
        param3.filename_value(SCXCoreLib::StrToMultibyte(testlogfilename).c_str());
        param3.regexps_value(regexps2);
        param3.qid_value(SCXCoreLib::StrToMultibyte(testQID).c_str());

        const std::wstring normalRow = L"Just a normal row with no problem";
        const std::wstring warningRow = L"A row with a warning in it";
        const std::wstring errorRow = L"A row with an error in it";
        const std::wstring errandwarnRow = L"A row with both a warning and an error in it";

        *stream << normalRow << std::endl
                << normalRow << std::endl
                << warningRow << std::endl
                << normalRow << std::endl
                << errorRow << std::endl
                << normalRow << std::endl
                << normalRow << std::endl
                << errandwarnRow << std::endl
                << normalRow << std::endl
                << warningRow << std::endl
                << normalRow << std::endl;

        context.Reset();
        agent.Invoke_GetMatchedRows(context, NULL, instanceName, param3);
        CPPUNIT_ASSERT_EQUAL(MI_RESULT_OK, context.GetResult());
        CPPUNIT_ASSERT_EQUAL(1u, context.Size());
        CPPUNIT_ASSERT_EQUAL(2u, context[0].GetNumberOfProperties());
        // Should match 4 rows and no status row.
        CPPUNIT_ASSERT_EQUAL_MESSAGE(DumpProperty_MIStringA(context[0].GetProperty(
            "rows", CALL_LOCATION(errMsg)), CALL_LOCATION(errMsg)),
            4u, context[0].GetProperty("rows", CALL_LOCATION(errMsg)).GetValue_MIStringA(CALL_LOCATION(errMsg)).size());
        CPPUNIT_ASSERT_EQUAL(StrAppend(L"0;", warningRow),
            context[0].GetProperty("rows", CALL_LOCATION(errMsg)).GetValue_MIStringA(CALL_LOCATION(errMsg))[0]);
        CPPUNIT_ASSERT_EQUAL(StrAppend(L"1;", errorRow),
            context[0].GetProperty("rows", CALL_LOCATION(errMsg)).GetValue_MIStringA(CALL_LOCATION(errMsg))[1]);
        CPPUNIT_ASSERT_EQUAL(StrAppend(L"0 1;", errandwarnRow),
            context[0].GetProperty("rows", CALL_LOCATION(errMsg)).GetValue_MIStringA(CALL_LOCATION(errMsg))[2]);
        CPPUNIT_ASSERT_EQUAL(StrAppend(L"0;", warningRow),
            context[0].GetProperty("rows", CALL_LOCATION(errMsg)).GetValue_MIStringA(CALL_LOCATION(errMsg))[3]);
    }

    void testDoInvokeMethodWithNonexistantLogfile()
    {
        std::wstring errMsg;
        TestableContext context;
        mi::SCX_LogFile_Class instanceName;
        mi::SCX_LogFile_GetMatchedRows_Class param;
        param.filename_value(".wyzzy.nosuchfile");
        mi::StringA regexps;
        regexps.PushBack(".*");
        param.regexps_value(regexps);
        param.qid_value(SCXCoreLib::StrToMultibyte(testQID).c_str());

        mi::Module Module;
        mi::SCX_LogFile_Class_Provider agent(&Module);
        agent.Invoke_GetMatchedRows(context, NULL, instanceName, param);
        CPPUNIT_ASSERT_EQUAL(MI_RESULT_OK, context.GetResult());
        CPPUNIT_ASSERT_EQUAL(1u, context.Size());
        CPPUNIT_ASSERT_EQUAL(2u, context[0].GetNumberOfProperties());
        // No status rows since the log file doesn't exist.
        CPPUNIT_ASSERT_EQUAL(0u, context[0].GetProperty("rows", CALL_LOCATION(errMsg)).
            GetValue_MIStringA(CALL_LOCATION(errMsg)).size());
    }

    void testInvokeResetStateFile()
    {
        std::wstring errMsg;
        TestableContext context;
        mi::SCX_LogFile_Class instanceName;
        mi::StringA regexps;
        regexps.PushBack(".*");
        mi::Module Module;
        mi::SCX_LogFile_Class_Provider agent(&Module);

        // Create a log file with one row in it.
        SCXHandle<std::wfstream> stream = SCXFile::OpenWFstream(testlogfilename, std::ios_base::out);
        *stream << L"This is the first row." << std::endl;

        mi::SCX_LogFile_GetMatchedRows_Class gmr_param;
        gmr_param.filename_value(SCXCoreLib::StrToMultibyte(testlogfilename).c_str());
        gmr_param.regexps_value(regexps);
        gmr_param.qid_value(SCXCoreLib::StrToMultibyte(testQID).c_str());
        context.Reset();
        agent.Invoke_GetMatchedRows(context, NULL, instanceName, gmr_param);
        CPPUNIT_ASSERT_EQUAL(MI_RESULT_OK, context.GetResult());
        CPPUNIT_ASSERT_EQUAL(1u, context.Size());
        CPPUNIT_ASSERT_EQUAL(2u, context[0].GetNumberOfProperties());
        // First call should return no status rows (treated as new file)
        CPPUNIT_ASSERT_EQUAL(0u, context[0].GetProperty("rows", CALL_LOCATION(errMsg)).
            GetValue_MIStringA(CALL_LOCATION(errMsg)).size());

        // Add another row to the log file.
        *stream << L"This is the second row." << std::endl;

        context.Reset();
        agent.Invoke_GetMatchedRows(context, NULL, instanceName, gmr_param);
        CPPUNIT_ASSERT_EQUAL(MI_RESULT_OK, context.GetResult());
        CPPUNIT_ASSERT_EQUAL(1u, context.Size());
        CPPUNIT_ASSERT_EQUAL(2u, context[0].GetNumberOfProperties());
        // Should get 1 new row
        CPPUNIT_ASSERT_EQUAL(1u, context[0].GetProperty("rows", CALL_LOCATION(errMsg)).
            GetValue_MIStringA(CALL_LOCATION(errMsg)).size());

        // Add another row to the log file.
        *stream << L"This is the third row." << std::endl;

        // Invoke ResetStateFile (without resetOnRead)
        mi::SCX_LogFile_ResetStateFile_Class rsf_param;
        rsf_param.filename_value(SCXCoreLib::StrToMultibyte(testlogfilename).c_str());
        rsf_param.qid_value(SCXCoreLib::StrToMultibyte(testQID).c_str());
        context.Reset();
        agent.Invoke_ResetStateFile(context, NULL, instanceName, rsf_param);
        CPPUNIT_ASSERT_EQUAL(MI_RESULT_OK, context.GetResult());
        CPPUNIT_ASSERT_EQUAL(0u, context.Size());

        // Finally, add one last row to the log file.
        *stream << L"This is the forth row" << std::endl;

        context.Reset();
        agent.Invoke_GetMatchedRows(context, NULL, instanceName, gmr_param);
        CPPUNIT_ASSERT_EQUAL(MI_RESULT_OK, context.GetResult());
        CPPUNIT_ASSERT_EQUAL(1u, context.Size());
        CPPUNIT_ASSERT_EQUAL(2u, context[0].GetNumberOfProperties());
        // Should now get 1 new row (first time read since we initialized)
        CPPUNIT_ASSERT_EQUAL_MESSAGE(DumpProperty_MIStringA(context[0].GetProperty(
                                                                "rows", CALL_LOCATION(errMsg)), CALL_LOCATION(errMsg)),
                                     1u, context[0].GetProperty("rows", CALL_LOCATION(errMsg)).
                                     GetValue_MIStringA(CALL_LOCATION(errMsg)).size());
    }

    void testInvokeResetStateFileWithResetFlag()
    {
        std::wstring errMsg;
        TestableContext context;
        mi::SCX_LogFile_Class instanceName;
        mi::StringA regexps;
        regexps.PushBack(".*");
        mi::Module Module;
        mi::SCX_LogFile_Class_Provider agent(&Module);

        // Create a log file with one row in it.
        SCXHandle<std::wfstream> stream = SCXFile::OpenWFstream(testlogfilename, std::ios_base::out);
        *stream << L"This is the first row." << std::endl;

        mi::SCX_LogFile_GetMatchedRows_Class gmr_param;
        gmr_param.filename_value(SCXCoreLib::StrToMultibyte(testlogfilename).c_str());
        gmr_param.regexps_value(regexps);
        gmr_param.qid_value(SCXCoreLib::StrToMultibyte(testQID).c_str());
        context.Reset();
        agent.Invoke_GetMatchedRows(context, NULL, instanceName, gmr_param);
        CPPUNIT_ASSERT_EQUAL(MI_RESULT_OK, context.GetResult());
        CPPUNIT_ASSERT_EQUAL(1u, context.Size());
        CPPUNIT_ASSERT_EQUAL(2u, context[0].GetNumberOfProperties());
        // First call should return no status rows (treated as new file)
        CPPUNIT_ASSERT_EQUAL(0u, context[0].GetProperty("rows", CALL_LOCATION(errMsg)).
            GetValue_MIStringA(CALL_LOCATION(errMsg)).size());

        // Add another row to the log file.
        *stream << L"This is the second row." << std::endl;

        context.Reset();
        agent.Invoke_GetMatchedRows(context, NULL, instanceName, gmr_param);
        CPPUNIT_ASSERT_EQUAL(MI_RESULT_OK, context.GetResult());
        CPPUNIT_ASSERT_EQUAL(1u, context.Size());
        CPPUNIT_ASSERT_EQUAL(2u, context[0].GetNumberOfProperties());
        // Should get 1 new row
        CPPUNIT_ASSERT_EQUAL(1u, context[0].GetProperty("rows", CALL_LOCATION(errMsg)).
            GetValue_MIStringA(CALL_LOCATION(errMsg)).size());

        // Add another row to the log file.
        *stream << L"This is the third row." << std::endl;

        // Invoke ResetStateFile (with resetOnRead)
        mi::SCX_LogFile_ResetStateFile_Class rsf_param;
        rsf_param.filename_value(SCXCoreLib::StrToMultibyte(testlogfilename).c_str());
        rsf_param.qid_value(SCXCoreLib::StrToMultibyte(testQID).c_str());
        rsf_param.resetOnRead_value(true);
        context.Reset();
        agent.Invoke_ResetStateFile(context, NULL, instanceName, rsf_param);
        CPPUNIT_ASSERT_EQUAL(MI_RESULT_OK, context.GetResult());
        CPPUNIT_ASSERT_EQUAL(0u, context.Size());

        // Add another row to the log file.
        *stream << L"This is the forth row" << std::endl;

        context.Reset();
        agent.Invoke_GetMatchedRows(context, NULL, instanceName, gmr_param);
        CPPUNIT_ASSERT_EQUAL(MI_RESULT_OK, context.GetResult());
        CPPUNIT_ASSERT_EQUAL(1u, context.Size());
        CPPUNIT_ASSERT_EQUAL(2u, context[0].GetNumberOfProperties());
        // Should not get any rows due to resetOnRead flag
        CPPUNIT_ASSERT_EQUAL(0u, context[0].GetProperty("rows", CALL_LOCATION(errMsg)).
            GetValue_MIStringA(CALL_LOCATION(errMsg)).size());

        // Finally, add one last row to the log file.
        *stream << L"This is the fifth row" << std::endl;

        context.Reset();
        agent.Invoke_GetMatchedRows(context, NULL, instanceName, gmr_param);
        CPPUNIT_ASSERT_EQUAL(MI_RESULT_OK, context.GetResult());
        CPPUNIT_ASSERT_EQUAL(1u, context.Size());
        CPPUNIT_ASSERT_EQUAL(2u, context[0].GetNumberOfProperties());
        // Should now get 1 new row (first time read since we initialized)
        CPPUNIT_ASSERT_EQUAL_MESSAGE(DumpProperty_MIStringA(context[0].GetProperty(
                                                                "rows", CALL_LOCATION(errMsg)), CALL_LOCATION(errMsg)),
                                     1u, context[0].GetProperty("rows", CALL_LOCATION(errMsg)).
                                     GetValue_MIStringA(CALL_LOCATION(errMsg)).size());
    }

    void InvokeProcess_scxlogfilereader(const std::wstring parameters)
    {
        std::stringstream processInput;
        std::stringstream processOutput;
        std::stringstream processError;

        // Test to see if we're running under testrunner.  This makes it easy
        // to know where to launch our test program, allowing unit tests to
        // test all the way through to the CLI.

        std::wstring programName = L"testfiles/scxlogfilereader-test " + parameters;

        int returnCode;
        returnCode = SCXProcess::Run(
            programName,
            processInput, processOutput, processError);
        CPPUNIT_ASSERT_EQUAL("", processOutput.str());
        CPPUNIT_ASSERT_EQUAL("", processError.str());
        CPPUNIT_ASSERT_EQUAL(0, returnCode);
    }

    void testInvokeResetAllStateFiles()
    {
        // ResetStateFile() resets a specific file while ResetAllStateFiles()
        // resets all state files that exist in the user directory. We can have
        // something super sophisticated that has multiple state files and
        // validates each of them, but given the code implementation, verifying
        // one state file is good enough, and test team will do further testing.

        std::wstring errMsg;
        TestableContext context;
        mi::SCX_LogFile_Class instanceName;
        mi::StringA regexps;
        regexps.PushBack(".*");
        mi::Module Module;
        mi::SCX_LogFile_Class_Provider agent(&Module);

        // Create a log file with one row in it.
        SCXHandle<std::wfstream> stream = SCXFile::OpenWFstream(testlogfilename, std::ios_base::out);
        *stream << L"This is the first row." << std::endl;

        mi::SCX_LogFile_GetMatchedRows_Class gmr_param;
        gmr_param.filename_value(SCXCoreLib::StrToMultibyte(testlogfilename).c_str());
        gmr_param.regexps_value(regexps);
        gmr_param.qid_value(SCXCoreLib::StrToMultibyte(testQID).c_str());
        context.Reset();
        agent.Invoke_GetMatchedRows(context, NULL, instanceName, gmr_param);
        CPPUNIT_ASSERT_EQUAL(MI_RESULT_OK, context.GetResult());
        CPPUNIT_ASSERT_EQUAL(1u, context.Size());
        CPPUNIT_ASSERT_EQUAL(2u, context[0].GetNumberOfProperties());
        // First call should return no status rows (treated as new file)
        CPPUNIT_ASSERT_EQUAL(0u, context[0].GetProperty("rows", CALL_LOCATION(errMsg)).
            GetValue_MIStringA(CALL_LOCATION(errMsg)).size());

        // Add another row to the log file.
        *stream << L"This is the second row." << std::endl;

        context.Reset();
        agent.Invoke_GetMatchedRows(context, NULL, instanceName, gmr_param);
        CPPUNIT_ASSERT_EQUAL(MI_RESULT_OK, context.GetResult());
        CPPUNIT_ASSERT_EQUAL(1u, context.Size());
        CPPUNIT_ASSERT_EQUAL(2u, context[0].GetNumberOfProperties());
        // Should get 1 new row
        CPPUNIT_ASSERT_EQUAL(1u, context[0].GetProperty("rows", CALL_LOCATION(errMsg)).
            GetValue_MIStringA(CALL_LOCATION(errMsg)).size());

        // Add another row to the log file.
        *stream << L"This is the third row." << std::endl;

        // Reset the log files (without resetOnRead)
        InvokeProcess_scxlogfilereader(L"-t -g 0");

        // Finally, add one last row to the log file.
        *stream << L"This is the forth row" << std::endl;

        context.Reset();
        agent.Invoke_GetMatchedRows(context, NULL, instanceName, gmr_param);
        CPPUNIT_ASSERT_EQUAL(MI_RESULT_OK, context.GetResult());
        CPPUNIT_ASSERT_EQUAL(1u, context.Size());
        CPPUNIT_ASSERT_EQUAL(2u, context[0].GetNumberOfProperties());
        // Should now get 1 new row (first time read since we initialized)
        CPPUNIT_ASSERT_EQUAL_MESSAGE(DumpProperty_MIStringA(context[0].GetProperty(
                                                                "rows", CALL_LOCATION(errMsg)), CALL_LOCATION(errMsg)),
                                     1u, context[0].GetProperty("rows", CALL_LOCATION(errMsg)).
                                     GetValue_MIStringA(CALL_LOCATION(errMsg)).size());
    }

    void testInvokeResetAllStateFilesWithResetFlag()
    {
        std::wstring errMsg;
        TestableContext context;
        mi::SCX_LogFile_Class instanceName;
        mi::StringA regexps;
        regexps.PushBack(".*");
        mi::Module Module;
        mi::SCX_LogFile_Class_Provider agent(&Module);

        // Create a log file with one row in it.
        SCXHandle<std::wfstream> stream = SCXFile::OpenWFstream(testlogfilename, std::ios_base::out);
        *stream << L"This is the first row." << std::endl;

        mi::SCX_LogFile_GetMatchedRows_Class gmr_param;
        gmr_param.filename_value(SCXCoreLib::StrToMultibyte(testlogfilename).c_str());
        gmr_param.regexps_value(regexps);
        gmr_param.qid_value(SCXCoreLib::StrToMultibyte(testQID).c_str());
        context.Reset();
        agent.Invoke_GetMatchedRows(context, NULL, instanceName, gmr_param);
        CPPUNIT_ASSERT_EQUAL(MI_RESULT_OK, context.GetResult());
        CPPUNIT_ASSERT_EQUAL(1u, context.Size());
        CPPUNIT_ASSERT_EQUAL(2u, context[0].GetNumberOfProperties());
        // First call should return no status rows (treated as new file)
        CPPUNIT_ASSERT_EQUAL(0u, context[0].GetProperty("rows", CALL_LOCATION(errMsg)).
            GetValue_MIStringA(CALL_LOCATION(errMsg)).size());

        // Add another row to the log file.
        *stream << L"This is the second row." << std::endl;

        context.Reset();
        agent.Invoke_GetMatchedRows(context, NULL, instanceName, gmr_param);
        CPPUNIT_ASSERT_EQUAL(MI_RESULT_OK, context.GetResult());
        CPPUNIT_ASSERT_EQUAL(1u, context.Size());
        CPPUNIT_ASSERT_EQUAL(2u, context[0].GetNumberOfProperties());
        // Should get 1 new row
        CPPUNIT_ASSERT_EQUAL(1u, context[0].GetProperty("rows", CALL_LOCATION(errMsg)).
            GetValue_MIStringA(CALL_LOCATION(errMsg)).size());

        // Add another row to the log file.
        *stream << L"This is the third row." << std::endl;

        // Reset the log files (with resetOnRead)
        InvokeProcess_scxlogfilereader(L"-t -g 1");

        // Add another row to the log file.
        *stream << L"This is the forth row" << std::endl;

        context.Reset();
        agent.Invoke_GetMatchedRows(context, NULL, instanceName, gmr_param);
        CPPUNIT_ASSERT_EQUAL(MI_RESULT_OK, context.GetResult());
        CPPUNIT_ASSERT_EQUAL(1u, context.Size());
        CPPUNIT_ASSERT_EQUAL(2u, context[0].GetNumberOfProperties());
        // Should not get any rows due to resetOnRead flag
        CPPUNIT_ASSERT_EQUAL(0u, context[0].GetProperty("rows", CALL_LOCATION(errMsg)).
            GetValue_MIStringA(CALL_LOCATION(errMsg)).size());

        // Finally, add one last row to the log file.
        *stream << L"This is the fifth row" << std::endl;

        context.Reset();
        agent.Invoke_GetMatchedRows(context, NULL, instanceName, gmr_param);
        CPPUNIT_ASSERT_EQUAL(MI_RESULT_OK, context.GetResult());
        CPPUNIT_ASSERT_EQUAL(1u, context.Size());
        CPPUNIT_ASSERT_EQUAL(2u, context[0].GetNumberOfProperties());
        // Should now get 1 new row (first time read since we initialized)
        CPPUNIT_ASSERT_EQUAL_MESSAGE(DumpProperty_MIStringA(context[0].GetProperty(
                                                                "rows", CALL_LOCATION(errMsg)), CALL_LOCATION(errMsg)),
                                     1u, context[0].GetProperty("rows", CALL_LOCATION(errMsg)).
                                     GetValue_MIStringA(CALL_LOCATION(errMsg)).size());
    }

    void testLocale8859_1()
    {
        const std::wstring regexpStr = L"0;";
#if defined(aix) || defined(sun)
        const char *localeString = "en_US.ISO8859-1";
#else
        const char *localeString = "en_US.iso88591";
#endif

        // See if we have the locale that we need
        try {
            std::locale newLocale(localeString);
        }
        catch (...)
        {
            std::wstring warnText;
            warnText = L"Unable to run LogFileProviderTest::testLocale8859_1 since locale "
                + SCXCoreLib::StrFromUTF8(localeString) + L" is not installed";
            SCXUNIT_WARNING(warnText);
            return;
        }

        // Tell scxlogfilereader to deal with en_US.iso88591 locale
        {
            std::fstream localeFile( SCXCoreLib::StrToMultibyte(testlocalefilename).c_str(), std::fstream::out );
            localeFile << localeString;
        }

        std::wstring errMsg;
        TestableContext context;
        mi::SCX_LogFile_Class instanceName;
        mi::StringA regexps;
        regexps.PushBack(".*");
        mi::Module Module;
        mi::SCX_LogFile_Class_Provider agent(&Module);

        // Create a log file with one row in it.
        SCXHandle<std::wfstream> stream = SCXFile::OpenWFstream(testlogfilename, std::ios_base::out);
        *stream << L"This is the first row." << std::endl;

        {
            mi::SCX_LogFile_GetMatchedRows_Class param;
            param.filename_value(SCXCoreLib::StrToMultibyte(testlogfilename).c_str());
            param.regexps_value(regexps);
            param.qid_value(SCXCoreLib::StrToMultibyte(testQID).c_str());
            agent.Invoke_GetMatchedRows(context, NULL, instanceName, param);
        }
        CPPUNIT_ASSERT_EQUAL(MI_RESULT_OK, context.GetResult());
        CPPUNIT_ASSERT_EQUAL(1u, context.Size());
        CPPUNIT_ASSERT_EQUAL(2u, context[0].GetNumberOfProperties());
        // First call should not return any rows of data (no state file)
        CPPUNIT_ASSERT_EQUAL(0u, context[0].GetProperty("rows", CALL_LOCATION(errMsg)).
            GetValue_MIStringA(CALL_LOCATION(errMsg)).size());

        // Verify a second row just to insure the state file exists and everything is working
        std::wstring second_row(L"This is the second row.");
        *stream << second_row << std::endl;
        stream->close();  // Don't need this stream anymore

        context.Reset();
        {
            mi::SCX_LogFile_GetMatchedRows_Class param;
            param.filename_value(SCXCoreLib::StrToMultibyte(testlogfilename).c_str());
            param.regexps_value(regexps);
            param.qid_value(SCXCoreLib::StrToMultibyte(testQID).c_str());
            agent.Invoke_GetMatchedRows(context, NULL, instanceName, param);
        }
        CPPUNIT_ASSERT_EQUAL(MI_RESULT_OK, context.GetResult());
        CPPUNIT_ASSERT_EQUAL(1u, context.Size());
        CPPUNIT_ASSERT_EQUAL(2u, context[0].GetNumberOfProperties());
        // Second call should return the second row of data
        CPPUNIT_ASSERT_EQUAL(1u, context[0].GetProperty("rows", CALL_LOCATION(errMsg)).
            GetValue_MIStringA(CALL_LOCATION(errMsg)).size());
        CPPUNIT_ASSERT_EQUAL(SCXCoreLib::StrAppend(regexpStr, second_row),
            context[0].GetProperty("rows", CALL_LOCATION(errMsg)).GetValue_MIStringA(CALL_LOCATION(errMsg))[0]);

        // Append a utf8859-1 line to the file
        //
        // It's a little tricky to do this for two reasons:
        //
        // 1. The compiler doesn't like some of the bytes.  So build a string
        //    using '~' as iso8859-1 bytes, and then substitute them after we
        //    have remainder of string constructed.
        //
        //    The actual string we want to test against is:
        //      "16.04.2013 14.20.08.766  INFO  TransactionInterceptor.invoke() - Betriebsbezeichnung 'Ges.f.Betoninstandsetzung u. Straßenunterhaltung GmbH & Co. KG' ist ungültig (name1)"
        //
        // 2. We specifically want to test with an en_US.iso88591 format file.
        //    Thus, we can't use wide streams (or SCX functions).  So we use
        //    8-bit (not wstring) characters and use stdio.

        std::string iso8859_1_Row("16.04.2013 14.20.08.766  INFO  TransactionInterceptor.invoke() - Betriebsbezeichnung 'Ges.f.Betoninstandsetzung u. Stra~enunterhaltung GmbH & Co. KG' ist ung~ltig (name1)");
        CPPUNIT_ASSERT_EQUAL('~', iso8859_1_Row[119]);
        iso8859_1_Row[119] = (char) 0xDF; // ß
        CPPUNIT_ASSERT_EQUAL('~', iso8859_1_Row[157]);
        iso8859_1_Row[157] = (char) 0xFC; // ü

        std::string addl_Row("This is a fourth row of data");

        // Write out the file using stdio
        FILE *f = fopen( SCXCoreLib::StrToMultibyte(testlogfilename).c_str(), "a" );
        CPPUNIT_ASSERT( f != NULL );
        CPPUNIT_ASSERT_EQUAL( 1u, fwrite(iso8859_1_Row.c_str(), iso8859_1_Row.size(), 1u, f) );
        CPPUNIT_ASSERT_EQUAL( 1u, fwrite("\n", 1u, 1u, f) ); // Write a \n at the end of our file
        CPPUNIT_ASSERT_EQUAL( 1u, fwrite(addl_Row.c_str(), addl_Row.size(), 1u, f) );
        CPPUNIT_ASSERT_EQUAL( 1u, fwrite("\n", 1u, 1u, f) ); // Write a \n at the end of our file
        CPPUNIT_ASSERT_EQUAL( 0, fclose(f) );

        context.Reset();
        {
            mi::SCX_LogFile_GetMatchedRows_Class param;
            param.filename_value(SCXCoreLib::StrToMultibyte(testlogfilename).c_str());
            param.regexps_value(regexps);
            param.qid_value(SCXCoreLib::StrToMultibyte(testQID).c_str());
            agent.Invoke_GetMatchedRows(context, NULL, instanceName, param);
            // context.Print();
        }
        CPPUNIT_ASSERT_EQUAL(MI_RESULT_OK, context.GetResult());
        CPPUNIT_ASSERT_EQUAL(1u, context.Size());
        CPPUNIT_ASSERT_EQUAL(2u, context[0].GetNumberOfProperties());
        // This call should return the iso8859-1 data we just wrote, but in UTF-8 format (and not garbled)
        CPPUNIT_ASSERT_EQUAL(2u, context[0].GetProperty("rows", CALL_LOCATION(errMsg)).
            GetValue_MIStringA(CALL_LOCATION(errMsg)).size());
        std::vector<std::wstring> rows = context[0].GetProperty("rows", CALL_LOCATION(errMsg)).GetValue_MIStringA(CALL_LOCATION(errMsg));
        // Note that OMI always returns data in UTF-8 format.  So convert our 8859-1 line to UTF-8 (as a wstring).
        // Note that StrFromMultibyte is locale-sensitive.  So set our locale and then convert using that.
        const char *sLoc = setlocale(LC_CTYPE, localeString);

        std::wstring wide_utf32_Row( SCXCoreLib::StrFromMultibyte(iso8859_1_Row, false) );

        // Reset locale. 
        setlocale(LC_CTYPE, sLoc);

        // Compare the lines we got back with the lines we expect
        CPPUNIT_ASSERT_EQUAL(SCXCoreLib::StrAppend(regexpStr, wide_utf32_Row), rows[0]);
        CPPUNIT_ASSERT_EQUAL(SCXCoreLib::StrAppend(regexpStr, SCXCoreLib::StrFromMultibyte(addl_Row)), rows[1]);
    }
};

CPPUNIT_TEST_SUITE_REGISTRATION( LogFileProviderTest );
