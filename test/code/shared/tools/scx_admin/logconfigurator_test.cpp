/*--------------------------------------------------------------------------------
  Copyright (c) Microsoft Corporation.  All rights reserved.

*/
/**
   \file

   \brief      Tests for wsman configurator functionality which is part of the scx_admin tool

   \date        2008-08-28 13:48

*/
/*----------------------------------------------------------------------------*/

#include <scxcorelib/scxcmn.h>
#include <logconfigurator.h> 
#include <testutils/scxunit.h>
#include <scxcorelib/scxexception.h>
#include <scxcorelib/scxfile.h>

#include <testutils/scxtestutils.h>

// using namespace SCXCore;
// using namespace SCXCoreLib;
// using namespace SCXSystemLib;

class LogConfigTest : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE( LogConfigTest );
    CPPUNIT_TEST( testLogRotate );
    CPPUNIT_TEST( testNoConfFile );
    CPPUNIT_TEST( testExistingConfFile );
    CPPUNIT_TEST( testCreatingConfFile );
    CPPUNIT_TEST( testResetLogConf );
    CPPUNIT_TEST( testProvSetThresholdForStdOut );
    CPPUNIT_TEST( testProvSetThresholdForTwoBackends );
    CPPUNIT_TEST( testSetInvalidSeverityThrows );
    CPPUNIT_TEST( testProvResetLogConf );
    CPPUNIT_TEST( testProvRemoveLogfile );
    CPPUNIT_TEST( testProviderLogBackendNameIsCaseInsensitive );
    CPPUNIT_TEST( testProviderLogFilePathIsCaseSensitive );
    CPPUNIT_TEST( testProviderLogModuleIdIsCaseSensitive );
    CPPUNIT_TEST( testProviderLogSeverityIsCaseInsensitive );
    SCXUNIT_TEST_ATTRIBUTE(testLogRotate, SLOW);
    CPPUNIT_TEST_SUITE_END();

private:

    /*
     * This is what we try to parse:
FILE (
PATH: /VAR/Opt/Microsoft/scx/log/scx.log
MODULE:  INFO
MODULE: module ERROR
)

FILE (
PATH: /var/opt/microsoft/scx/log/scx.log
MODULE:  INFO
MODULE: module TRACE
)

STDOUT (
MODULE:  INFO
MODULE: module INFO
)
     */
    std::wstring GetLogLevel(const SCXFilePath& cfgfile,
                             const std::wstring& backendName,
                             const std::wstring& fileBackendPath,
                             const std::wstring& module)
    {
        std::vector<std::wstring> lines;
        SCXStream::NLFs nlfs;
        SCXFile::ReadAllLinesAsUTF8(cfgfile, lines, nlfs);
        
        for (std::vector<std::wstring>::const_iterator iter = lines.begin();
             iter != lines.end();
             ++iter)
        {
            if (StrAppend(backendName, L" (") == *iter)
            {
                if (L"FILE" == backendName)
                {
                    ++iter;
                    if (iter != lines.end() && std::wstring(L"PATH: ").append(fileBackendPath) != *iter)
                    {
                        continue;
                    }
                }
                while (iter != lines.end() && L")" != *iter)
                {
                    std::vector<std::wstring> tokens;
                    StrTokenize(*iter, tokens);
                    if (tokens.size() == 3 && tokens[0] == L"MODULE:" && tokens[1] == module)
                    {
                        return tokens[2];
                    }
                    else if (tokens.size() == 2 && tokens[0] == L"MODULE:" && module == L"")
                    {
                        return tokens[1];
                    }
                    ++iter;
                }
            }
        }
        return L"";
    }

    /**
       Return the content of the file as a string.
     */
    std::string GetFileContent(const SCXFilePath& cfgfile)
    {
        std::string str;
        str.resize( 1024 * 256 );    // should be enough
        size_t size = SCXFile::ReadAvailableBytes( cfgfile, &str[0], str.size() );
        str.resize( size );
        return str;
    }

    
public:
    void setUp(void)
    {
        /* This method will be called once before each test function. */
    }

    void tearDown(void)
    {
        /* This method will be called once after each test function. */
    }

    bool MeetsPrerequisites(std::wstring testName)
    {
        /* Privileges needed for this platform */
        if (0 == geteuid())
        {
            return true;
        }

        std::wstring warnText;

        warnText = L"Platform needs privileges to run " + testName + L" test";

        SCXUNIT_WARNING(warnText);
        return false;
    }

    void testLogRotate(void)
    {
        SCX_LogConfigurator subject;

        if (MeetsPrerequisites(L"testLogRotate"))
        {
            // LogRotate isn't supported by OpenWSMan
            CPPUNIT_ASSERT_MESSAGE("Unexpected return value from method LogRotate()", 
                                   subject.LogRotate() == true);
        }
    }

    // 
    // check if default one
    void testNoConfFile()
    {
        // This file should not exist.
        SelfDeletingFilePath cfgfile(SCXFileSystem::DecodePath("./testfiles/log.conf"));

        SCX_LogConfigurator subject(cfgfile);

        std::wostringstream  buf;
        subject.Print( buf );
        std::wstring str = buf.str();

        // should be some "FILE" default configuration
        CPPUNIT_ASSERT( str.size() > 0 );
        CPPUNIT_ASSERT( str.find(L"FILE")  != str.npos );
    }


    // reading the exisitng one 
    void testExistingConfFile()
    {
        SelfDeletingFilePath cfgfile(SCXFileSystem::DecodePath("./testfiles/log.conf"));

        // Create a simple example file
        std::vector<std::wstring> lines;
        lines.push_back(L"FILE (");
        lines.push_back(L"PATH: /var/log-1");
        lines.push_back(L")");
        lines.push_back(L"");   // Must be here, or else the last newline will be omitted.
        SCXFile::WriteAllLinesAsUTF8(cfgfile, lines, std::ios_base::out);
        
        SCX_LogConfigurator subject(cfgfile);

        std::wostringstream  buf;
        subject.Print( buf );
        
        std::wstring str = buf.str();

        // should be some "FILE" default configuration
        CPPUNIT_ASSERT( str.size() > 0 );                        
        CPPUNIT_ASSERT( str.find(L"FILE")  != str.npos );
        CPPUNIT_ASSERT( str.find(L"/var/log-1")  != str.npos );
        CPPUNIT_ASSERT( str.find(L"INFO")  != str.npos );        // The only severity will be default INFO
    }
    
    // set "verbose" - should create a file
    void testCreatingConfFile()
    {
        // This file should not exist.
        SelfDeletingFilePath cfgfile(SCXFileSystem::DecodePath("./testfiles/log.conf"));

        SCX_LogConfigurator subject(cfgfile);

        CPPUNIT_ASSERT( subject.Set( SCX_AdminLogAPI::eLogLevel_Verbose ) );
        CPPUNIT_ASSERT( SCXFile::Exists(cfgfile) ); // Should be created
    }

    // generic reset
    void testResetLogConf()
    {
        SelfDeletingFilePath cfgfile(SCXFileSystem::DecodePath("./testfiles/log.conf"));

        // Create a simple example file
        std::vector<std::wstring> lines;
        lines.push_back(L"FILE (");
        lines.push_back(L"PATH: /var/log-1");
        lines.push_back(L"MODULE: TRACE");
        lines.push_back(L"MODULE: scxtest.core.common.pal WARNING");
        lines.push_back(L"MODULE: scxtest.core.common.pal.system.common HYSTERICAL");
        lines.push_back(L"MODULE: scxtest.core.common.pal.system.common.entityenumeration INFO");
        lines.push_back(L")");
        lines.push_back(L"");   // Must be here, or else the last newline will be omitted.
        SCXFile::WriteAllLinesAsUTF8(cfgfile, lines, std::ios_base::out);

        {
            SCX_LogConfigurator subject(cfgfile);
            CPPUNIT_ASSERT (subject.Reset() );
        }

        std::string str = GetFileContent(cfgfile);

        CPPUNIT_ASSERT( str.find("HYSTERICAL")  == str.npos );              // Should be gone
        CPPUNIT_ASSERT( str.find("scxtest.core.common.pal")  == str.npos ); // should be gone
        CPPUNIT_ASSERT( str.find("FILE")  != str.npos );                    // should still be there
        CPPUNIT_ASSERT( str.find("/var/log-1")  != str.npos );              // should still be there
    }
    
    // provider set
    void testProvSetThresholdForStdOut()
    {
        SelfDeletingFilePath cfgfile(SCXFileSystem::DecodePath("./testfiles/log.conf"));

        SCX_LogConfigurator subject(cfgfile);

        // set several entries: should create a new file with specific entries:
        subject.Set( L"STDOUT", L"TRACE" );
        subject.Set( L"STDOUT:scxtest.core.common.pal.system.common.entityenumeration", L"INFO" );

        std::string str = GetFileContent(cfgfile);

        // we should not see these entries
        CPPUNIT_ASSERT( str.find("HYSTERICAL")  == str.npos );
        CPPUNIT_ASSERT( str.find("FILE")  == str.npos );
        CPPUNIT_ASSERT( str.find("/var")  == str.npos );

        // but should see these:
        CPPUNIT_ASSERT( L"TRACE" == GetLogLevel(cfgfile, L"STDOUT", L"", L"") );
        CPPUNIT_ASSERT( L"INFO" == GetLogLevel(cfgfile, L"STDOUT", L"", L"scxtest.core.common.pal.system.common.entityenumeration") );
    }

    // provider set
    void testProvSetThresholdForTwoBackends()
    {
        SelfDeletingFilePath cfgfile(SCXFileSystem::DecodePath("./testfiles/log.conf"));

        SCX_LogConfigurator subject(cfgfile);

        // Positive test to set lower case entry: should create a new file with specific entries (upper case):
        subject.Set( L"STDOUT", L"trace" );
        subject.Set( L"STDOUT:scxtest.core.common.pal.system.common.entityenumeration", L"info" );
        subject.Set( L"FILE:/myvar/opt/microsoft/scx/log/scx.log:scxtest.core.common.pal.system.common.entityenumeration", L"info" );

        std::string str = GetFileContent(cfgfile);

        // we should not see these entries
        CPPUNIT_ASSERT( str.find("HYSTERICAL")  == str.npos );
        CPPUNIT_ASSERT( str.find("/var")  == str.npos );

        // but should see these:
        CPPUNIT_ASSERT( L"TRACE" == GetLogLevel(cfgfile, L"STDOUT", L"", L"") );
        CPPUNIT_ASSERT( L"INFO" == GetLogLevel(cfgfile, L"STDOUT", L"", L"scxtest.core.common.pal.system.common.entityenumeration") );
        CPPUNIT_ASSERT( L"INFO" == GetLogLevel(cfgfile, 
                                               L"FILE", L"/myvar/opt/microsoft/scx/log/scx.log",
                                               L"scxtest.core.common.pal.system.common.entityenumeration") );
    }

    // Negative test to set invalid entry: should throw an exception
    void testSetInvalidSeverityThrows()
    {
        SelfDeletingFilePath cfgfile(SCXFileSystem::DecodePath("./testfiles/log.conf"));
        SCX_LogConfigurator invTest(cfgfile);

        invTest.Set( L"STDOUT", L"trace" );

        CPPUNIT_ASSERT_THROW_MESSAGE( "invalid severity string: anything1",
            invTest.Set( L"STDOUT:scxtest.core.common.pal.system.common.entityenumeration", L"anything" ),
            SCXAdminException );

        CPPUNIT_ASSERT_THROW_MESSAGE( "invalid severity string: anything2",
            invTest.Set( L"FILE:/myvar/opt/microsoft/scx/log/scx.log:scxtest.core.common.pal.system.common.entityenumeration", L"anything2" ),
            SCXAdminException );
    }

    // provider set
    void testProvResetLogConf()
    {
        // create a file
        SelfDeletingFilePath cfgfile(SCXFileSystem::DecodePath("./testfiles/log.conf"));

        {
            SCX_LogConfigurator subject(cfgfile);

            subject.Set( L"STDOUT", L"trace" );
            subject.Set( L"STDOUT:scxtest.core.common.pal.system.common.entityenumeration", L"info" );
            subject.Set( L"FILE:/myvar/opt/microsoft/scx/log/scx.log:scxtest.core.common.pal.system.common.entityenumeration", L"info" );
        }
        
        SCX_LogConfigurator subject(cfgfile);

        subject.Reset( L"STDOUT" );
        subject.Reset( L"FILE:/myvar/opt/microsoft/scx/log/scx.log" );

        CPPUNIT_ASSERT_THROW_MESSAGE( "exception is expected since entry does not exist",
            subject.Reset( L"FILE:/var/opt/microsoft/scx/log/scx.log" ),
            SCXAdminException );
        
        std::string str = GetFileContent(cfgfile);

        // we should not see these entries
        CPPUNIT_ASSERT( str.find("HYSTERICAL")  == str.npos );
        CPPUNIT_ASSERT( str.find("/var")  == str.npos );
        CPPUNIT_ASSERT( str.find("MODULE: scxtest.core.common.pal.system.common.entityenumeration INFO")  == str.npos );

        // but should see these:
        CPPUNIT_ASSERT( str.find("STDOUT")  != str.npos );
        CPPUNIT_ASSERT( str.find("FILE")  != str.npos );
        CPPUNIT_ASSERT( str.find("PATH: /myvar/opt/microsoft/scx/log/scx.log")  != str.npos );
    }

    // provider set
    void testProvRemoveLogfile()
    {
        // create a file
        SelfDeletingFilePath cfgfile(SCXFileSystem::DecodePath("./testfiles/log.conf"));

        {
            SCX_LogConfigurator subject(cfgfile);

            subject.Set( L"STDOUT", L"trace" );
            subject.Set( L"STDOUT:scxtest.core.common.pal.system.common.entityenumeration", L"info" );
            subject.Set( L"FILE:/myvar/opt/microsoft/scx/log/scx.log:scxtest.core.common.pal.system.common.entityenumeration", L"info" );
        }
        
        SCX_LogConfigurator subject(cfgfile);

        subject.Remove( L"STDOUT" );

        CPPUNIT_ASSERT_THROW_MESSAGE( "exception is expected since entry does not exist",
            subject.Remove( L"FILE:/var/opt/microsoft/scx/log/scx.log" ),
            SCXAdminException );

        std::string str = GetFileContent(cfgfile);

        // we should not see these entries
        CPPUNIT_ASSERT( str.find("HYSTERICAL")  == str.npos );
        CPPUNIT_ASSERT( str.find("/var")  == str.npos );
        CPPUNIT_ASSERT( str.find("STDOUT")  == str.npos );

        // but should see these:
        CPPUNIT_ASSERT( str.find("FILE")  != str.npos );
        CPPUNIT_ASSERT( str.find("PATH: /myvar/opt/microsoft/scx/log/scx.log")  != str.npos );
        CPPUNIT_ASSERT( str.find("MODULE: scxtest.core.common.pal.system.common.entityenumeration INFO")  != str.npos );
    }

    /**
        The log backend name (FILE or STDOUT) in provider log configuration should be 
        case insensitive.
     */   
    void testProviderLogBackendNameIsCaseInsensitive()
    {
        SelfDeletingFilePath cfgfile(SCXFileSystem::DecodePath("log.conf"));
        cfgfile.SetDirectory(L"./testfiles/");

        SCX_LogConfigurator subject(cfgfile);

        subject.Set( L"STDOUT:module", L"TRACE" );
        subject.Set( L"stdout:module", L"INFO" );

        subject.Set( L"FILE:/var/opt/microsoft/scx/log/scx.log:module", L"TRACE" );
        subject.Set( L"file:/var/opt/microsoft/scx/log/scx.log:module", L"ERROR" );

        CPPUNIT_ASSERT( L"INFO" == GetLogLevel(cfgfile, L"STDOUT", L"", L"module") );
        CPPUNIT_ASSERT( L"ERROR" == GetLogLevel(cfgfile, L"FILE", L"/var/opt/microsoft/scx/log/scx.log", L"module") );
    }

    /**
        The log file backend path in provider log configuration should be 
        case sensitive.
     */   
    void testProviderLogFilePathIsCaseSensitive()
    {
        SelfDeletingFilePath cfgfile(SCXFileSystem::DecodePath("log.conf"));
        cfgfile.SetDirectory(L"./testfiles/");

        SCX_LogConfigurator subject(cfgfile);

        subject.Set( L"FILE:/var/opt/microsoft/scx/log/scx.log:module", L"TRACE" );
        subject.Set( L"FILE:/VAR/Opt/Microsoft/scx/log/scx.log:module", L"ERROR" );

        CPPUNIT_ASSERT( L"TRACE" == GetLogLevel(cfgfile, L"FILE", L"/var/opt/microsoft/scx/log/scx.log", L"module") );
        CPPUNIT_ASSERT( L"ERROR" == GetLogLevel(cfgfile, L"FILE", L"/VAR/Opt/Microsoft/scx/log/scx.log", L"module") );
    }

    /**
        The module id in provider log configuration should be 
        case sensitive.
     */   
    void testProviderLogModuleIdIsCaseSensitive()
    {
        SelfDeletingFilePath cfgfile(SCXFileSystem::DecodePath("log.conf"));
        cfgfile.SetDirectory(L"./testfiles/");

        SCX_LogConfigurator subject(cfgfile);

        subject.Set( L"STDOUT:module", L"TRACE" );
        subject.Set( L"STDOUT:MODULE", L"INFO" );
        subject.Set( L"STDOUT:MoDuLe", L"ERROR" );

        CPPUNIT_ASSERT( L"TRACE" == GetLogLevel(cfgfile, L"STDOUT", L"", L"module") );
        CPPUNIT_ASSERT( L"INFO" == GetLogLevel(cfgfile, L"STDOUT", L"", L"MODULE") );
        CPPUNIT_ASSERT( L"ERROR" == GetLogLevel(cfgfile, L"STDOUT", L"", L"MoDuLe") );
    }

    /**
        The severity threshold in provider log configuration should be 
        case insensitive.
     */   
    void testProviderLogSeverityIsCaseInsensitive()
    {
        SelfDeletingFilePath cfgfile(SCXFileSystem::DecodePath("log.conf"));
        cfgfile.SetDirectory(L"./testfiles/");

        SCX_LogConfigurator subject(cfgfile);

        subject.Set( L"STDOUT:module", L"trace" );
        subject.Set( L"STDOUT:MODULE", L"TrAcE" );
        subject.Set( L"STDOUT:MoDuLe", L"TRACE" );

        CPPUNIT_ASSERT( L"TRACE" == GetLogLevel(cfgfile, L"STDOUT", L"", L"module") );
        CPPUNIT_ASSERT( L"TRACE" == GetLogLevel(cfgfile, L"STDOUT", L"", L"MODULE") );
        CPPUNIT_ASSERT( L"TRACE" == GetLogLevel(cfgfile, L"STDOUT", L"", L"MoDuLe") );
    }
};

CPPUNIT_TEST_SUITE_REGISTRATION( LogConfigTest );
