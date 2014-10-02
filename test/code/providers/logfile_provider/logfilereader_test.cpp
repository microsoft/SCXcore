/*--------------------------------------------------------------------------------
  Copyright (c) Microsoft Corporation.  All rights reserved.

*/
/**
   \file

   \brief       Tests for the logfile reader (CLI program)

   \date        2011-04-18 13:18:00

*/
/*----------------------------------------------------------------------------*/

#include <scxcorelib/scxcmn.h>
#include <cppunit/extensions/HelperMacros.h>
#include <testutils/scxunit.h>
#include <scxcorelib/scxmarshal.h>
#include <scxcorelib/scxprocess.h>
#include <scxcorelib/stringaid.h>

#include <string>

// dynamic_cast fix - wi 11220
#ifdef dynamic_cast
#undef dynamic_cast
#endif

using namespace std;
using namespace SCXCoreLib;

class LogFileReaderTest : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE( LogFileReaderTest );
    CPPUNIT_TEST( testDisplayVersion );
    CPPUNIT_TEST( testDisplayHelp );
    CPPUNIT_TEST( testDisplayShortHelp );
    CPPUNIT_TEST( testInvalidParameter );
    CPPUNIT_TEST( testParameterMarshaling );
    CPPUNIT_TEST( testParameterMarshalingWithManyMatches );

    SCXUNIT_TEST_ATTRIBUTE(testDisplayVersion, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(testDisplayHelp, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(testDisplayShortHelp, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(testInvalidParameter, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(testParameterMarshaling, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(testParameterMarshalingWithManyMatches, SLOW);
    CPPUNIT_TEST_SUITE_END();

private:
    wstring m_imageName;

public:
    LogFileReaderTest()
    {
        // We assume that 'scxlogfilereader' is in the path.  This makes it
        // much easier to compare results, since the path to 'scxlogfilereader'
        // will be part of the output if path information was used to launch
        // the program.
        //
        // Modifed testrun framework to add base target directory to path.

        m_imageName = L"scxlogfilereader";
    }

    void setUp(void)
    {
    }

    void tearDown(void)
    {
    }

    void testDisplayVersion()
    {
        int returnCode;
        std::istringstream processInput;
        std::ostringstream processOutput;
        std::ostringstream processError;

        returnCode = SCXProcess::Run(StrAppend(m_imageName, L" -v"),
                                     processInput, processOutput, processError);

        CPPUNIT_ASSERT_EQUAL(string(""), processError.str());
        CPPUNIT_ASSERT_EQUAL(0, returnCode);

        CPPUNIT_ASSERT_EQUAL(string("Version: "),
                             processOutput.str().substr(0, 9));
    }

    void testDisplayHelp()
    {
        int returnCode;
        std::istringstream processInput;
        std::ostringstream processOutput;
        std::ostringstream processError;

        returnCode = SCXProcess::Run(StrAppend(m_imageName, L" -h"),
                                     processInput, processOutput, processError);

        ostringstream expectedHelpText;
        expectedHelpText << "Usage: scxlogfilereader" << endl << endl
                         << "Options:" << endl
                         << "  -h:\tDisplay detailed help information" << endl
                         << "  -g:\tReset all log file states (for internal use only)" << endl
                         << "     \t(Requires parameter for ResetOnRead: 1/true/0/false)" << endl
                         << "  -i:\tInteractive use (for debugging purposes only)" << endl
                         << "  -m:\tRun marshal unit tests (debugging purposes only)" << endl
                         << "  -p:\tProvider interface (for internal use only)" << endl
                         << "  -r:\tReset log file state (for internal use only)" << endl
                         << "  -t:\tProvide hooks for testrunner environmental setup" << endl
                         << "  -v:\tDisplay version information" << endl;

        CPPUNIT_ASSERT_EQUAL(string(""), processError.str());
        CPPUNIT_ASSERT_EQUAL(0, returnCode);

        CPPUNIT_ASSERT_EQUAL(expectedHelpText.str(), processOutput.str());
    }

    void testDisplayShortHelp()
    {
        int returnCode;
        std::istringstream processInput;
        std::ostringstream processOutput;
        std::ostringstream processError;

        returnCode = SCXProcess::Run(StrAppend(m_imageName, L" -?"),
                                     processInput, processOutput, processError);

        CPPUNIT_ASSERT_EQUAL(string(""), processError.str());
        CPPUNIT_ASSERT_EQUAL(0, returnCode);

        CPPUNIT_ASSERT_EQUAL(
            string("scxlogfilereader: Try 'scxlogfilereader -h' for more information.\n"),
            processOutput.str());
    }

    void testInvalidParameter()
    {
        int returnCode;
        std::istringstream processInput;
        std::ostringstream processOutput;
        std::ostringstream processError;

        // Call with some invalid parameter ('-z' in this case)
        returnCode = SCXProcess::Run(StrAppend(m_imageName, L" -z"),
                                     processInput, processOutput, processError);

        CPPUNIT_ASSERT_EQUAL(string("scxlogfilereader: invalid option -- 'z'\n"),
                             processError.str());
        CPPUNIT_ASSERT_EQUAL(64, returnCode);

        CPPUNIT_ASSERT_EQUAL(
            string("scxlogfilereader: Try 'scxlogfilereader -h' for more information.\n"),
            processOutput.str());
    }

    void internalTestParameterMarshaling(int matchedLinesCount)
    {
        // Marshal specific input for the log file reader

        int returnCode;
        std::stringstream processInput;
        std::stringstream processOutput;
        std::ostringstream processError;

        std::wstring filename(L"This_is_a_random_filename");
        std::wstring qid(L"This_is_a_random_QID");
        vector<SCXRegexWithIndex> regexps;

        for (int i=0; i < 10; i++)
        {
            SCXRegexWithIndex regind;
            regind.regex = new SCXRegex(StrAppend(L"Regular expression number ", i));
            regind.index = i;
            regexps.push_back(regind);
        }

        Marshal send(processInput);
        send.Write(filename);
        send.Write(qid);
        send.Write(regexps);
        send.Write(matchedLinesCount);
        send.Flush();

        // Call the logfilereader with the marshal test flag
        returnCode = SCXProcess::Run(StrAppend(m_imageName, L" -m"),
                                     processInput, processOutput, processError);

        CPPUNIT_ASSERT_EQUAL(0, returnCode);

        // UnMarshal the results and validate

        std::wstring retFilename, retQid;
        vector<SCXRegexWithIndex> retRegexps;
        int wasPartialRead;
        int retMatchedLinesCount;
        vector<std::wstring> matchedLines;

        UnMarshal receive(processOutput);
        receive.Read(retFilename);
        receive.Read(retQid);
        receive.Read(retRegexps);
        receive.Read(retMatchedLinesCount);
        receive.Read(wasPartialRead);
        receive.Read(matchedLines);

        CPPUNIT_ASSERT_EQUAL(StrToMultibyte(filename), StrToMultibyte(retFilename));
        CPPUNIT_ASSERT_EQUAL(StrToMultibyte(qid), StrToMultibyte(retQid));

        CPPUNIT_ASSERT_EQUAL(regexps.size(), retRegexps.size());
        for (size_t i=0; i < regexps.size(); i++)
        {
            CPPUNIT_ASSERT_EQUAL(regexps[i].index, retRegexps[i].index);
            CPPUNIT_ASSERT(regexps[i].regex->Get() == retRegexps[i].regex->Get());
        }

        CPPUNIT_ASSERT_EQUAL(65536, wasPartialRead);

        CPPUNIT_ASSERT_EQUAL(matchedLinesCount, retMatchedLinesCount);
        CPPUNIT_ASSERT_EQUAL(static_cast<size_t> (matchedLinesCount), matchedLines.size());
        for (int i=0; i < matchedLinesCount; i++)
        {
            std::stringstream ss;
            ss << "This is entry number " << i << " in the vector";
            CPPUNIT_ASSERT_EQUAL(ss.str(), StrToMultibyte(matchedLines[i]));
        }
    }

    void testParameterMarshaling()
    {
        // Use a small number of returned matched lines
        internalTestParameterMarshaling(20);
    }

    void testParameterMarshalingWithManyMatches()
    {
        // Use a large number of returned matched lines
        internalTestParameterMarshaling(10000);
    }
};

CPPUNIT_TEST_SUITE_REGISTRATION( LogFileReaderTest );
