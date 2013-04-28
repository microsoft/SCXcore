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
#include <cppunit/extensions/HelperMacros.h>
#include <testutils/scxunit.h>
#include <scxcorelib/scxexception.h>
#include <scxcorelib/scxfile.h>
#include <sys/wait.h>
#if defined(aix)
#include <unistd.h>
#endif
#include "source/code/scxcorelib/util/persist/scxfilepersistmedia.h"

#include <support/logfileprovider.h>
#include <support/logfileutils.h>

// dynamic_cast fix - wi 11220
#ifdef dynamic_cast
#undef dynamic_cast
#endif

// ========================== UGLY HACK UGLY HACK UGLY HACK ==========================
// We have added NO_OMI_COMPATIBLE_TEST.  This test is only partially ported for use with
// OMI.  Obviously, more changes will be coming.  When this test is fully converted, all
// of the "#ifdef NO_OMI_COMPATIBLE_TEST" constructs should be removed.
// ========================== UGLY HACK UGLY HACK UGLY HACK ==========================

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

#ifdef NO_OMI_COMPATIBLE_TEST
    void TestDoInit()
    {
        DoInit();
    }

    void TestDoInvokeMethod(const SCXProviderLib::SCXCallContext& callContext,
                            const std::wstring& methodname, const SCXProviderLib::SCXArgs& args,
                            SCXProviderLib::SCXArgs& outargs, SCXProviderLib::SCXProperty& result)
    {
        DoInvokeMethod(callContext, methodname, args, outargs, result);
    }

    void TestDoCleanup()
    {
        DoCleanup();
    }
#endif

    void TestSetPersistMedia(SCXCoreLib::SCXHandle<SCXCoreLib::SCXPersistMedia> persistMedia) 
    {
        m_pLogFileReader->SetPersistMedia(persistMedia);
    }

private:
    // No implementation; do not use default constructor for unit tests!
    TestableLogfileProvider();

    SCXCoreLib::SCXHandle<LogFileReader> m_pLogFileReader;
};

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

    SCXUNIT_TEST_ATTRIBUTE(testLogFilePositionRecordPersistable, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(testLogFilePositionRecordUnpersist, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(testDoInvokeMethod, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(testDoInvokeMethodWithNonexistantLogfile, SLOW);
    CPPUNIT_TEST_SUITE_END();

private:
    SCXHandle<SCXPersistMedia> m_pmedia;
    SCXCoreLib::SCXHandle<TestableLogfileProvider> lp;
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

        lp = new TestableLogfileProvider(m_pReader);
        lp->TestSetPersistMedia(m_pmedia);
#ifdef NO_OMI_COMPATIBLE_TEST
        lp->TestDoInit();
#endif
    }

    void tearDown(void)
    {
#ifdef NO_OMI_COMPATIBLE_TEST
        lp->TestDoCleanup();
#endif
        lp = 0;

        SCXHandle<LogFileReader::LogFilePositionRecord> r(
            new LogFileReader::LogFilePositionRecord(testlogfilename, testQID, m_pmedia) );
        r->UnPersist();
        SCXFile::Delete(testlogfilename);
        SCXHandle<LogFileReader::LogFilePositionRecord> r2( 
            new LogFileReader::LogFilePositionRecord(testlogfilename, testQID2, m_pmedia) );
        r2->UnPersist();
    }

    void callDumpStringForCoverage()
    {
        CPPUNIT_ASSERT(lp->DumpString().find(L"LogFileProvider") != std::wstring::npos);
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

    void testDoInvokeMethod ()
    {
#ifdef NO_OMI_COMPATIBLE_TEST
        // We REALLY REALLY REALLY want to bring this test back.  It has historically
        // been insanely useful in verifying correct behavior.  But this is very tied
        // to the old Pegasus design and will take some rework to make happen (sigh).

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

        const std::wstring methodName = L"GetMatchedRows";
        const std::wstring invalidRegexpStr = L"InvalidRegexp;0";
        const std::wstring OKRegexpStr = L"1;";
        const std::wstring moreRowsStr = L"MoreRowsAvailable;true";

        SCXInstance objectPath;
        objectPath.SetCimClassName(L"SCX_LogFile");
        SCXCallContext context(objectPath, eDirectSupport);
        SCXArgs args;

        SCXProperty filenameprop(L"filename", testlogfilename);
        args.AddProperty(filenameprop);

        std::vector<SCXProperty> regexps;
        // Add an invalid regular expression
        SCXProperty regexp1prop(L"regexp1", L"[a");
        regexps.push_back(regexp1prop);
        SCXProperty regexp2prop(L"regexp2", L".*");
        regexps.push_back(regexp2prop);
        SCXProperty regexpsprop(L"regexps", regexps);
        args.AddProperty(regexpsprop);

        {
            SCXArgs outargs;
            SCXProperty result;

            SCXInstance objectPath2;
            objectPath2.SetCimClassName(L"SCX_LogFileRecord");
            SCXCallContext context2(objectPath2, eDirectSupport);

            // Call with wrong class
            CPPUNIT_ASSERT_THROW(lp->TestDoInvokeMethod(context2, methodName, args, outargs, result), SCXNotSupportedException);
        
            // Call with wrong method name
            CPPUNIT_ASSERT_THROW(lp->TestDoInvokeMethod(context, L"UnknownMethod", args, outargs, result), SCXProvCapNotRegistered);

            // Call with missing arguments
            SCXUNIT_RESET_ASSERTION();
            CPPUNIT_ASSERT_THROW(lp->TestDoInvokeMethod(context, methodName, args, outargs, result), SCXInternalErrorException);
            SCXUNIT_ASSERTIONS_FAILED(1);
        }

        SCXProperty qidprop(L"qid", testQID);
        args.AddProperty(qidprop);

        // Create a log file with one row in it
        SCXHandle<std::wfstream> stream = SCXFile::OpenWFstream(testlogfilename, std::ios_base::out);
        
        *stream << L"This is the first row." << std::endl;

        {
            SCXArgs outargs;
            SCXProperty result;

            // First call should only return 1 status row
            lp->TestDoInvokeMethod(context, methodName, args, outargs, result); 

            CPPUNIT_ASSERT_EQUAL(1, (int) outargs.NumberOfProperties());
            CPPUNIT_ASSERT_EQUAL(1, (int) outargs.GetProperty(0)->GetVectorValue().size());
            CPPUNIT_ASSERT(outargs.GetProperty(0)->GetVectorValue()[0].GetStrValue() == invalidRegexpStr);
        }

        SCXArgs args2;
        args2.AddProperty(filenameprop);
        args2.AddProperty(regexpsprop);
        SCXProperty qid2prop(L"qid", testQID2);
        args2.AddProperty(qid2prop);

        {
            SCXArgs outargs;
            SCXProperty result;

            // First call with new QID should only return 1 status row
            lp->TestDoInvokeMethod(context, methodName, args2, outargs, result);

            CPPUNIT_ASSERT(1 == outargs.NumberOfProperties());

            // Build an output stream in case of problems ...
            std::ostringstream msg;
            msg << " Size: " << outargs.GetProperty(0)->GetVectorValue().size() << std::endl;
            for (unsigned int i = 0; i < outargs.GetProperty(0)->GetVectorValue().size(); i++)
                msg << i << ": " << SCXCoreLib::StrToMultibyte(outargs.GetProperty(0)->GetVectorValue()[i].GetStrValue()) << std::endl;

            CPPUNIT_ASSERT_MESSAGE(msg.str().c_str(), 1 == outargs.GetProperty(0)->GetVectorValue().size());
            CPPUNIT_ASSERT(outargs.GetProperty(0)->GetVectorValue()[0].GetStrValue() == invalidRegexpStr);
        }

        // Add another row to the log file
        const std::wstring secondRow(L"This is the second row.");
        *stream << secondRow << std::endl;

        {
            SCXArgs outargs;
            SCXProperty result;

            // Should get 1 new row + 1 status row
            lp->TestDoInvokeMethod(context, methodName, args, outargs, result); 

            CPPUNIT_ASSERT(1 == outargs.NumberOfProperties());
            CPPUNIT_ASSERT(2 == outargs.GetProperty(0)->GetVectorValue().size());
            CPPUNIT_ASSERT(outargs.GetProperty(0)->GetVectorValue()[0].GetStrValue() == invalidRegexpStr);
            CPPUNIT_ASSERT(outargs.GetProperty(0)->GetVectorValue()[1].GetStrValue() == StrAppend(OKRegexpStr, secondRow));
        }

        // Add yet another row to the log file
        const std::wstring thirdRow(L"This is the third row.");
        *stream << thirdRow << std::endl;

        {
            SCXArgs outargs;
            SCXProperty result;

            // Using new QID - should get 2 new rows + 1 status row
            lp->TestDoInvokeMethod(context, methodName, args2, outargs, result);    

            CPPUNIT_ASSERT(1 == outargs.NumberOfProperties());
            CPPUNIT_ASSERT(3 == outargs.GetProperty(0)->GetVectorValue().size());
            CPPUNIT_ASSERT(outargs.GetProperty(0)->GetVectorValue()[0].GetStrValue() == invalidRegexpStr);
            CPPUNIT_ASSERT(outargs.GetProperty(0)->GetVectorValue()[1].GetStrValue() == StrAppend(OKRegexpStr, secondRow));
            CPPUNIT_ASSERT(outargs.GetProperty(0)->GetVectorValue()[2].GetStrValue() == StrAppend(OKRegexpStr, thirdRow));
        }

        {
            SCXArgs outargs;
            SCXProperty result;

            // Should get 1 new row + 1 status row
            lp->TestDoInvokeMethod(context, methodName, args, outargs, result); 

            CPPUNIT_ASSERT(1 == outargs.NumberOfProperties());
            CPPUNIT_ASSERT(2 == outargs.GetProperty(0)->GetVectorValue().size());
            CPPUNIT_ASSERT(outargs.GetProperty(0)->GetVectorValue()[0].GetStrValue() == invalidRegexpStr);
            CPPUNIT_ASSERT(outargs.GetProperty(0)->GetVectorValue()[1].GetStrValue() == StrAppend(OKRegexpStr, thirdRow));
        }

        // Add another 800 rows to the log file
        for (int i=0; i<800; i++)
        {
            *stream << L"This is another row." << std::endl;
        }

        {
            SCXArgs outargs;
            SCXProperty result;

            // Should get the first 500 rows + 2 status rows
            lp->TestDoInvokeMethod(context, methodName, args, outargs, result); 

            CPPUNIT_ASSERT(1 == outargs.NumberOfProperties());
            CPPUNIT_ASSERT(502 == outargs.GetProperty(0)->GetVectorValue().size());
            CPPUNIT_ASSERT(outargs.GetProperty(0)->GetVectorValue()[0].GetStrValue() == moreRowsStr);
        }

        {
            SCXArgs outargs;
            SCXProperty result;

            // Should get the next 300 rows + 1 status row
            lp->TestDoInvokeMethod(context, methodName, args, outargs, result); 

            CPPUNIT_ASSERT(1 == outargs.NumberOfProperties());
            CPPUNIT_ASSERT(301 == outargs.GetProperty(0)->GetVectorValue().size());
            CPPUNIT_ASSERT(outargs.GetProperty(0)->GetVectorValue()[0].GetStrValue() != moreRowsStr);
        }

        SCXArgs args3;
        args3.AddProperty(filenameprop);
        std::vector<SCXProperty> regexps2;
        SCXProperty regexp3prop(L"regexp3", L"warning");
        regexps2.push_back(regexp3prop);
        SCXProperty regexp4prop(L"regexp4", L"error");
        regexps2.push_back(regexp4prop);
        SCXProperty regexps2prop(L"regexps", regexps2);
        args3.AddProperty(regexps2prop);
        args3.AddProperty(qidprop);

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

        {
            SCXArgs outargs;
            SCXProperty result;

            // Should match 4 rows and no status rows
            lp->TestDoInvokeMethod(context, methodName, args3, outargs, result);    

            CPPUNIT_ASSERT(1 == outargs.NumberOfProperties());

            // Build an output stream in case of problems ...
            std::ostringstream msg;
            msg << " Size: " << outargs.GetProperty(0)->GetVectorValue().size() << std::endl;
            for (unsigned int i = 0; i < outargs.GetProperty(0)->GetVectorValue().size(); i++)
                msg << i << ": " << SCXCoreLib::StrToMultibyte(outargs.GetProperty(0)->GetVectorValue()[i].GetStrValue()) << std::endl;

            CPPUNIT_ASSERT_MESSAGE(msg.str().c_str(), 4 == outargs.GetProperty(0)->GetVectorValue().size());
            CPPUNIT_ASSERT(outargs.GetProperty(0)->GetVectorValue()[0].GetStrValue() == StrAppend(L"0;", warningRow));
            CPPUNIT_ASSERT(outargs.GetProperty(0)->GetVectorValue()[1].GetStrValue() == StrAppend(L"1;", errorRow));
            CPPUNIT_ASSERT(outargs.GetProperty(0)->GetVectorValue()[2].GetStrValue() == StrAppend(L"0 1;", errandwarnRow));
            CPPUNIT_ASSERT(outargs.GetProperty(0)->GetVectorValue()[3].GetStrValue() == StrAppend(L"0;", warningRow));
        }
#endif
    }

    void testDoInvokeMethodWithNonexistantLogfile()
    {
#ifdef NO_OMI_COMPATIBLE_TEST
        const std::wstring methodName = L"GetMatchedRows";
        const std::wstring OKRegexpStr = L"1;";

        SCXInstance objectPath;
        objectPath.SetCimClassName(L"SCX_LogFile");
        SCXCallContext context(objectPath, eDirectSupport);
        SCXArgs args;

        SCXProperty filenameprop(L"filename", testlogfilename + L".wyzzy.nosuchfile");
        args.AddProperty(filenameprop);

        std::vector<SCXProperty> regexps;
        SCXProperty regexp1prop(L"regexp1", L".*");
        regexps.push_back(regexp1prop);
        SCXProperty regexpsprop(L"regexps", regexps);
        args.AddProperty(regexpsprop);

        SCXProperty qidprop(L"qid", testQID);
        args.AddProperty(qidprop);

        {
            SCXArgs outargs;
            SCXProperty result;

            // This call should return no status rows since the logfile doesn't exist
            lp->TestDoInvokeMethod(context, methodName, args, outargs, result); 

            CPPUNIT_ASSERT_EQUAL(1, (int) outargs.NumberOfProperties());
            CPPUNIT_ASSERT_EQUAL(0, (int) outargs.GetProperty(0)->GetVectorValue().size());
        }
#endif
    }
};

CPPUNIT_TEST_SUITE_REGISTRATION( LogFileProviderTest );
