/*--------------------------------------------------------------------------------
  Copyright (c) Microsoft Corporation.  All rights reserved.

*/
/**
   \file

   \brief       Tests for the runas provider

   \date        2008-05-07 12:02

   Only tests the functionality of the provider class.
   The actual data gathering is tested by a separate class.

*/
/*----------------------------------------------------------------------------*/

#include <scxcorelib/scxcmn.h>
#include <scxcorelib/scxdirectoryinfo.h>
#include <scxcorelib/scxexception.h>
#include <scxcorelib/stringaid.h>
#include <testutils/scxunit.h>

#include "source/code/providers/runas_provider/runasprovider.h"

#include <list>
#include <unistd.h>     // For getpid()

using namespace SCXCore;
using namespace SCXCoreLib;
using namespace SCXProviderLib;

// if you want to see extra information from executed commands/scripts
// set "c_EnableDebugOutput" to 1
const int c_EnableDebugOutput = 0;

class TestableRunAsProvider : public RunAsProvider
{
public:
    TestableRunAsProvider(SCXCoreLib::SCXHandle<RunAsConfigurator> configurator = 
                SCXCoreLib::SCXHandle<RunAsConfigurator>(new RunAsConfigurator())) :
        RunAsProvider(configurator)
    {
    }

    void TestDoInit()
    {
        DoInit();
    }

    void TestDoEnumInstanceNames(const SCXProviderLib::SCXCallContext& callContext,
                                 SCXProviderLib::SCXInstanceCollection &names)
    {
        DoEnumInstanceNames(callContext, names);
    }

    void TestDoEnumInstances(const SCXProviderLib::SCXCallContext& callContext,
                             SCXProviderLib::SCXInstanceCollection &instances)
    {
        DoEnumInstances(callContext, instances);
    }

    void TestDoGetInstance(const SCXProviderLib::SCXCallContext& callContext,
                           SCXProviderLib::SCXInstance& instance)
    {
        DoGetInstance(callContext, instance);
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
};

/*----------------------------------------------------------------------------*/
/**
   Class for parsing strings with generic configuration

*/
class ConfigurationStringParser : public ConfigurationParser
{
public:
    ConfigurationStringParser(const std::wstring& configuration) :
        m_Configuration(configuration)
    {};

    void Parse()
    {
        std::wistringstream stream(m_Configuration);
        ParseStream(stream);
    };
private:
    std::wstring m_Configuration;
};

class SCXRunAsProviderTest : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE( SCXRunAsProviderTest );
    CPPUNIT_TEST( testDoEnumInstanceNames );
    CPPUNIT_TEST( testDoEnumInstances );
    CPPUNIT_TEST( testDoGetInstance );
    CPPUNIT_TEST( testDoInvokeMethodNoParams );
    CPPUNIT_TEST( testDoInvokeMethodPartParams );
    CPPUNIT_TEST( testDoInvokeMethodCommandOK );
    CPPUNIT_TEST( testDoInvokeMethodCommandOKWithEmptyElevationType );
    CPPUNIT_TEST( testDoInvokeMethodCommandOKWithElevationType );
    CPPUNIT_TEST( testDoInvokeMethodCommandOKWithUppercaseElevationType );
    CPPUNIT_TEST( testDoInvokeMethodCommandOKWithInvalideElevationType );
    CPPUNIT_TEST( testDoInvokeMethodCommandFailed );
    CPPUNIT_TEST( testDoInvokeMethodShellCommandOK );
    CPPUNIT_TEST( testDoInvokeMethodShellCommandOKWithSudoElevationType );
    CPPUNIT_TEST( testDoInvokeMethodShellCommandOKWithEmptyElevationType );
    CPPUNIT_TEST( testDoInvokeMethodShellCommandOKWithInvalideElevationType );
    CPPUNIT_TEST( testDoInvokeMethodScriptOK );
    CPPUNIT_TEST( testDoInvokeMethodScriptOKWithSudoElevation );
    CPPUNIT_TEST( testDoInvokeMethodScriptOKWithUpperCaseSudoElevation );
    CPPUNIT_TEST( testDoInvokeMethodScriptOKWithEmptyElevation );
    CPPUNIT_TEST( testDoInvokeMethodScriptFailed );
    CPPUNIT_TEST( testDoInvokeMethodScriptNonSH );
    CPPUNIT_TEST( testDoInvokeMethodScriptNoHashBang );
    CPPUNIT_TEST( testChRoot );
    CPPUNIT_TEST( testCWD );

    SCXUNIT_TEST_ATTRIBUTE(testDoInvokeMethodCommandOK, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(testDoInvokeMethodCommandOKWithEmptyElevationType, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(testDoInvokeMethodCommandOKWithElevationType, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(testDoInvokeMethodCommandOKWithUppercaseElevationType, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(testDoInvokeMethodCommandOKWithInvalideElevationType, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(testDoInvokeMethodCommandFailed, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(testDoInvokeMethodShellCommandOK, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(testDoInvokeMethodShellCommandOKWithSudoElevationType, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(testDoInvokeMethodShellCommandOKWithEmptyElevationType, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(testDoInvokeMethodShellCommandOKWithInvalideElevationType, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(testDoInvokeMethodScriptOK, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(testDoInvokeMethodScriptOKWithSudoElevation, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(testDoInvokeMethodScriptOKWithUpperCaseSudoElevation, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(testDoInvokeMethodScriptOKWithEmptyElevation, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(testDoInvokeMethodScriptFailed, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(testDoInvokeMethodScriptNonSH, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(testDoInvokeMethodScriptNoHashBang, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(testChRoot, SLOW);
    SCXUNIT_TEST_ATTRIBUTE(testCWD, SLOW);
    CPPUNIT_TEST_SUITE_END();

private:
    /* Add any data commonly used in several tests as members here. */
    SCXCoreLib::SCXHandle<TestableRunAsProvider> pp;

public:
    void setUp(void)
    {
        // The default CWD may not exist so we use the current instead.
        SCXCoreLib::SCXHandle<RunAsConfigurator> configurator(
            new RunAsConfigurator(SCXCoreLib::SCXHandle<ConfigurationParser>(new ConfigurationStringParser(L"CWD = ./\n")), 
            SCXCoreLib::SCXHandle<ConfigurationWriter>(0)) );

        if (0 == geteuid() && ! configurator->GetAllowRoot())
        {
            configurator->SetAllowRoot(true);
        }

        pp = new TestableRunAsProvider(configurator);
        pp->TestDoInit();
    }

    void tearDown(void)
    {
        /* This method will be called once after each test function. */
        pp->TestDoCleanup();
        pp = 0;
        system("rm -rf testChRoot > /dev/null 2>&1");
    }

    void testDoEnumInstanceNames()
    {
        // unsupported method - should throw exception
        SCXInstanceCollection instances;
        
        SCXInstance objectPath;
        objectPath.SetCimClassName(L"SCX_OperatingSystem");
        SCXCallContext context(objectPath, eDirectSupport);
        
        CPPUNIT_ASSERT_THROW_MESSAGE( "\"unsupported\" exception expected", 
            pp->TestDoEnumInstanceNames(context, instances), 
            SCXCoreLib::SCXNotSupportedException);

    }

    void testDoEnumInstances()
    {
        // unsupported method - should throw exception
        SCXInstanceCollection instances;
        SCXInstance objectPath;
        objectPath.SetCimClassName(L"SCX_OperatingSystem");
        SCXCallContext context(objectPath, eDirectSupport);
        
        CPPUNIT_ASSERT_THROW_MESSAGE( "\"unsupported\" exception expected", 
            pp->TestDoEnumInstances(context, instances),
            SCXCoreLib::SCXNotSupportedException);
    }


    void testDoGetInstance()
    {
        // unsupported method - should throw exception
        SCXProperty key(L"Handle", StrFrom(getpid()));
        SCXInstance instance;
        SCXInstance objectPath;

        objectPath.AddProperty(key);
        objectPath.SetCimClassName(L"SCX_OperatingSystem");

        SCXCallContext context(objectPath, eDirectSupport);

        // Get the testrunner process instance
        CPPUNIT_ASSERT_THROW_MESSAGE( "\"unsupported\" exception expected", 
            pp->TestDoGetInstance(context, instance),
            SCXCoreLib::SCXNotSupportedException);
        
    }

    void testDoInvokeMethodNoParams ()
    {
        SCXArgs args;
        SCXArgs out;        // Not used
        SCXProperty result;
        SCXInstance objectPath;
        objectPath.SetCimClassName(L"SCX_OperatingSystem");

        SCXCallContext context(objectPath, eDirectSupport);

        CPPUNIT_ASSERT_THROW_MESSAGE( "\"SCXInternalErrorException\" exception expected", 
            pp->TestDoInvokeMethod(context, L"ExecuteCommand", args, out, result),
            SCXCoreLib::SCXInternalErrorException);

        // Verify that throwing this exception also asserts.
        SCXUNIT_ASSERTIONS_FAILED(1);
    }
    
    void testDoInvokeMethodPartParams ()
    {
        SCXArgs args;
        SCXArgs out;        // Not used
        SCXProperty result;
        SCXInstance objectPath;
        objectPath.SetCimClassName(L"SCX_OperatingSystem");

        SCXCallContext context(objectPath, eDirectSupport);

        SCXProperty cmd(L"Command", L"ls");

        args.AddProperty(cmd);
        
        CPPUNIT_ASSERT_THROW_MESSAGE( "\"SCXInternalErrorException\" exception expected", 
            pp->TestDoInvokeMethod(context, L"ExecuteCommand", args, out, result),
            SCXCoreLib::SCXInternalErrorException);
        
        // Verify that throwing this exception also asserts.
        SCXUNIT_ASSERTIONS_FAILED(1);
    }


    void testDoInvokeMethodCommandOK ()
    {
        SCXArgs args;
        SCXArgs out;
        SCXProperty result;
        SCXInstance objectPath;
        objectPath.SetCimClassName(L"SCX_OperatingSystem");

        SCXCallContext context(objectPath, eDirectSupport);

        SCXProperty cmd(L"Command", L"echo Testing");

        SCXProperty timeout(L"timeout", static_cast<unsigned int>(100));

        args.AddProperty(cmd);
        args.AddProperty(timeout);

        pp->TestDoInvokeMethod(context, L"ExecuteCommand", args, out, result);

        // Print out results. Saved for debug.
        if ( c_EnableDebugOutput ) {
            std::wcout << std::endl << out.GetProperty(L"StdOut")->GetStrValue() << std::endl <<
                (int)out.GetProperty(L"StdOut")->GetType(); 
         }

        CPPUNIT_ASSERT( !out.GetProperty(L"StdOut")->GetStrValue().empty());
        CPPUNIT_ASSERT( out.GetProperty(L"StdErr")->GetStrValue().empty());
        CPPUNIT_ASSERT_EQUAL( out.GetProperty(L"ReturnCode")->GetIntValue(), 0);
        CPPUNIT_ASSERT( out.GetProperty(L"StdOut")->GetStrValue() == L"Testing\n" );
    }

    void testDoInvokeMethodCommandOKWithEmptyElevationType ()
    {
        SCXArgs args;
        SCXArgs out;
        SCXProperty result;
        SCXInstance objectPath;
        objectPath.SetCimClassName(L"SCX_OperatingSystem");

        SCXCallContext context(objectPath, eDirectSupport);

        SCXProperty cmd(L"Command", L"echo Testing");

        SCXProperty timeout(L"timeout", static_cast<unsigned int>(100));

        SCXProperty elevation(L"ElevationType", L"");

        args.AddProperty(cmd);
        args.AddProperty(timeout);
        args.AddProperty(elevation);

        pp->TestDoInvokeMethod(context, L"ExecuteCommand", args, out, result);

        // Print out results. Saved for debug.
        if ( c_EnableDebugOutput ) {
             std::wcout << std::endl << out.GetProperty(L"StdOut")->GetStrValue() << std::endl <<
                 (int)out.GetProperty(L"StdOut")->GetType();
        }

        CPPUNIT_ASSERT( !out.GetProperty(L"StdOut")->GetStrValue().empty());
        CPPUNIT_ASSERT( out.GetProperty(L"StdErr")->GetStrValue().empty());
        CPPUNIT_ASSERT_EQUAL( out.GetProperty(L"ReturnCode")->GetIntValue(), 0);
        CPPUNIT_ASSERT( out.GetProperty(L"StdOut")->GetStrValue() == L"Testing\n" );

    }
    
    void testDoInvokeMethodCommandOKWithElevationType ()
    {
        SCXArgs args;
        SCXArgs out;
        SCXProperty result;
        SCXInstance objectPath;
        objectPath.SetCimClassName(L"SCX_OperatingSystem");

        SCXCallContext context(objectPath, eDirectSupport);

        SCXProperty cmd(L"Command", L"echo Testing");

        SCXProperty timeout(L"timeout", static_cast<unsigned int>(100));

        SCXProperty elevation(L"ElevationType", L"sudo");

        args.AddProperty(cmd);
        args.AddProperty(timeout);
        args.AddProperty(elevation);

        pp->TestDoInvokeMethod(context, L"ExecuteCommand", args, out, result);

        // Print out results. Saved for debug.
        if ( c_EnableDebugOutput ) {
            std::wcout << std::endl << out.GetProperty(L"StdOut")->GetStrValue() << std::endl <<
                (int)out.GetProperty(L"StdOut")->GetType();
        }

        CPPUNIT_ASSERT( !out.GetProperty(L"StdOut")->GetStrValue().empty());
        CPPUNIT_ASSERT( out.GetProperty(L"StdErr")->GetStrValue().empty());
        CPPUNIT_ASSERT_EQUAL( out.GetProperty(L"ReturnCode")->GetIntValue(), 0);
        CPPUNIT_ASSERT( out.GetProperty(L"StdOut")->GetStrValue() == L"Testing\n" );
    }

    void testDoInvokeMethodCommandOKWithUppercaseElevationType ()
    {
        SCXArgs args;
        SCXArgs out;
        SCXProperty result;
        SCXInstance objectPath;
        objectPath.SetCimClassName(L"SCX_OperatingSystem");

        SCXCallContext context(objectPath, eDirectSupport);

        SCXProperty cmd(L"Command", L"echo Testing");

        SCXProperty timeout(L"timeout", static_cast<unsigned int>(100));

        SCXProperty elevation(L"ElevationType", L"SUdo");

        args.AddProperty(cmd);
        args.AddProperty(timeout);
        args.AddProperty(elevation);

        pp->TestDoInvokeMethod(context, L"ExecuteCommand", args, out, result);

        // Print out results. Saved for debug.
        if ( c_EnableDebugOutput ) {
            std::wcout << std::endl << out.GetProperty(L"StdOut")->GetStrValue() << std::endl <<
                (int)out.GetProperty(L"StdOut")->GetType();
        }

        CPPUNIT_ASSERT( !out.GetProperty(L"StdOut")->GetStrValue().empty());
        CPPUNIT_ASSERT( out.GetProperty(L"StdErr")->GetStrValue().empty());
        CPPUNIT_ASSERT_EQUAL( out.GetProperty(L"ReturnCode")->GetIntValue(), 0);
        CPPUNIT_ASSERT( out.GetProperty(L"StdOut")->GetStrValue() == L"Testing\n" );
    }

    void testDoInvokeMethodCommandOKWithInvalideElevationType ()
    {
        SCXArgs args;
        SCXArgs out;
        SCXProperty result;
        SCXInstance objectPath;
        objectPath.SetCimClassName(L"SCX_OperatingSystem");

        SCXCallContext context(objectPath, eDirectSupport);

        SCXProperty cmd(L"Command", L"echo Testing");

        SCXProperty timeout(L"timeout", static_cast<unsigned int>(100));

        SCXProperty elevation(L"ElevationType", L"aaaaaa");

        args.AddProperty(cmd);
        args.AddProperty(timeout);
        args.AddProperty(elevation);

         CPPUNIT_ASSERT_THROW_MESSAGE( "\"SCXInternalErrorException\" exception expected",
            pp->TestDoInvokeMethod(context, L"ExecuteCommand", args, out, result),
            SCXCoreLib::SCXInternalErrorException);

        // Verify that throwing this exception also asserts.
        SCXUNIT_ASSERTIONS_FAILED(1);
    }

    void testDoInvokeMethodCommandFailed ()
    {
        SCXArgs args;
        SCXArgs out;
        SCXProperty result;
        SCXInstance objectPath;
        objectPath.SetCimClassName(L"SCX_OperatingSystem");

        SCXCallContext context(objectPath, eDirectSupport);

        SCXProperty cmd(L"Command", L"/non-existing-directory/non-existing-command");

        SCXProperty timeout(L"timeout", static_cast<unsigned int>(100));

        args.AddProperty(cmd);
        args.AddProperty(timeout);

        pp->TestDoInvokeMethod(context, L"ExecuteCommand", args, out, result);

        // Print out results. Saved for debug.
        if ( c_EnableDebugOutput ) {
            std::wcout << std::endl << out.GetProperty(L"StdOut")->GetStrValue() << std::endl <<
                (int)out.GetProperty(L"StdOut")->GetType() << std::endl <<
                out.GetProperty(L"StdErr")->GetStrValue() << std::endl << L"error code: " <<
                out.GetProperty(L"ReturnCode")->GetIntValue();
        }

        CPPUNIT_ASSERT( out.GetProperty(L"StdOut")->GetStrValue().empty());
        CPPUNIT_ASSERT( !out.GetProperty(L"StdErr")->GetStrValue().empty());
        CPPUNIT_ASSERT( out.GetProperty(L"ReturnCode")->GetIntValue() != 0);

    }

    void testDoInvokeMethodShellCommandOK ()
    {
        SCXArgs args;
        SCXArgs out;
        SCXProperty result;
        SCXInstance objectPath;
        objectPath.SetCimClassName(L"SCX_OperatingSystem");

        SCXCallContext context(objectPath, eDirectSupport);

        SCXProperty cmd(L"Command", L"echo 'a\nb\nc' | grep b");
        SCXProperty timeout(L"timeout", static_cast<unsigned int>(100));

        args.AddProperty(cmd);
        args.AddProperty(timeout);

        pp->TestDoInvokeMethod(context, L"ExecuteShellCommand", args, out, result);

        CPPUNIT_ASSERT_EQUAL(std::string("b\n"),
            StrToMultibyte(out.GetProperty(L"StdOut")->GetStrValue()) );
        CPPUNIT_ASSERT( out.GetProperty(L"StdErr")->GetStrValue().empty() );
        CPPUNIT_ASSERT_EQUAL( 0, out.GetProperty(L"ReturnCode")->GetIntValue() );

    }

    void testDoInvokeMethodShellCommandOKWithSudoElevationType ()
    {
        SCXArgs args;
        SCXArgs out;
        SCXProperty result;
        SCXInstance objectPath;
        objectPath.SetCimClassName(L"SCX_OperatingSystem");

        SCXCallContext context(objectPath, eDirectSupport);

        SCXProperty cmd(L"Command", L"echo 'a\nb\nc' | grep b");
        SCXProperty timeout(L"timeout", static_cast<unsigned int>(100));
        SCXProperty elevation(L"ElevationType", L"sudo");

        args.AddProperty(cmd);
        args.AddProperty(timeout);
        args.AddProperty(elevation);
           

        pp->TestDoInvokeMethod(context, L"ExecuteShellCommand", args, out, result);

        CPPUNIT_ASSERT( out.GetProperty(L"StdOut")->GetStrValue() == L"b\n" );
        CPPUNIT_ASSERT( out.GetProperty(L"StdErr")->GetStrValue().empty());
        CPPUNIT_ASSERT_EQUAL( out.GetProperty(L"ReturnCode")->GetIntValue(), 0);
    }


    void testDoInvokeMethodShellCommandOKWithEmptyElevationType ()
    {
        try {
            SCXArgs args;
            SCXArgs out;
            SCXProperty result;
            SCXInstance objectPath;
            objectPath.SetCimClassName(L"SCX_OperatingSystem");

            SCXCallContext context(objectPath, eDirectSupport);

            SCXProperty cmd(L"Command", L"echo 'a\nb\nc' | grep b");
            SCXProperty timeout(L"timeout", static_cast<unsigned int>(100));
            SCXProperty elevation(L"ElevationType", L"");

            args.AddProperty(cmd);
            args.AddProperty(timeout);
            args.AddProperty(elevation);

            pp->TestDoInvokeMethod(context, L"ExecuteShellCommand", args, out, result);

            CPPUNIT_ASSERT( out.GetProperty(L"StdOut")->GetStrValue() == L"b\n" );
            CPPUNIT_ASSERT( out.GetProperty(L"StdErr")->GetStrValue().empty());
            CPPUNIT_ASSERT_EQUAL( out.GetProperty(L"ReturnCode")->GetIntValue(), 0);

        } catch (SCXException& e) {
            std::wcout << L"\nException in testDoInvokeMethod: " << e.What()
                       << L" @ " << e.Where() << std::endl;
            CPPUNIT_ASSERT(!"Exception");
        }
    }

    void testDoInvokeMethodShellCommandOKWithInvalideElevationType ()
    {
        SCXArgs args;
        SCXArgs out;
        SCXProperty result;
        SCXInstance objectPath;
        objectPath.SetCimClassName(L"SCX_OperatingSystem");

        SCXCallContext context(objectPath, eDirectSupport);

        SCXProperty cmd(L"Command", L"echo \"a\nb\nc\" | grep b");

        SCXProperty timeout(L"timeout", static_cast<unsigned int>(100));

        SCXProperty elevation(L"ElevationType", L"aaaaa");

        args.AddProperty(cmd);
        args.AddProperty(timeout);
        args.AddProperty(elevation);
        
        CPPUNIT_ASSERT_THROW_MESSAGE( "\"SCXInternalErrorException\" exception expected",
            pp->TestDoInvokeMethod(context, L"ExecuteShellCommand", args, out, result),
            SCXCoreLib::SCXInternalErrorException);

        // Verify that throwing this exception also asserts.
        SCXUNIT_ASSERTIONS_FAILED(1);
    }

    void testDoInvokeMethodScriptOK ()
    {
        SCXArgs args;
        SCXArgs out;
        SCXProperty result;
        SCXInstance objectPath;
        objectPath.SetCimClassName(L"SCX_OperatingSystem");

        SCXCallContext context(objectPath, eDirectSupport);

        SCXProperty cmd(L"Script", 
             L"#!/bin/sh\n"
             L"# write something to stdout stream\n"
             L"echo \"$3-$2-$1\"\n"
             L"# and now create stderr output\n"
             L"echo \"-$2-\">&2\n"
             L"exit 0\n" );
        SCXProperty arguments(L"Arguments", L"unit test run");
        SCXProperty timeout(L"timeout", static_cast<unsigned int>(100));

        args.AddProperty(cmd);
        args.AddProperty(timeout);
        args.AddProperty(arguments);

        pp->TestDoInvokeMethod(context, L"ExecuteScript", args, out, result);

        // Print out results. Saved for debug.
        if ( c_EnableDebugOutput ) {
             std::wcout << std::endl << out.GetProperty(L"StdOut")->GetStrValue() << std::endl <<
                 (int)out.GetProperty(L"StdOut")->GetType() << std::endl <<
                 out.GetProperty(L"StdErr")->GetStrValue() << std::endl << L"error code: " <<
                 out.GetProperty(L"ReturnCode")->GetIntValue();
        } 

        CPPUNIT_ASSERT( !out.GetProperty(L"StdOut")->GetStrValue().empty());
        CPPUNIT_ASSERT( !out.GetProperty(L"StdErr")->GetStrValue().empty());
        CPPUNIT_ASSERT_EQUAL( out.GetProperty(L"ReturnCode")->GetIntValue(), 0);
        CPPUNIT_ASSERT( out.GetProperty(L"StdOut")->GetStrValue() == L"run-test-unit\n" );
        CPPUNIT_ASSERT( out.GetProperty(L"StdErr")->GetStrValue() == L"-test-\n" );
    }

    void testDoInvokeMethodScriptOKWithSudoElevation ()
    {
        SCXArgs args;
        SCXArgs out;
        SCXProperty result;
        SCXInstance objectPath;
        objectPath.SetCimClassName(L"SCX_OperatingSystem");

        SCXCallContext context(objectPath, eDirectSupport);

        SCXProperty cmd(L"Script",
             L"#!/bin/sh\n"
             L"# write something to stdout stream\n"
             L"echo \"$3-$2-$1\"\n"
             L"# and now create stderr output\n"
             L"echo \"-$2-\">&2\n"
             L"exit 0\n" );
        SCXProperty arguments(L"Arguments", L"unit test run");
        SCXProperty timeout(L"timeout", static_cast<unsigned int>(100));
        SCXProperty elevation(L"ElevationType", L"sudo");

        args.AddProperty(cmd);
        args.AddProperty(timeout);
        args.AddProperty(arguments);
        args.AddProperty(elevation);

        pp->TestDoInvokeMethod(context, L"ExecuteScript", args, out, result);

        // Print out results. Saved for debug.
        if ( c_EnableDebugOutput ) {
             std::wcout << std::endl << out.GetProperty(L"StdOut")->GetStrValue() << std::endl <<
                 (int)out.GetProperty(L"StdOut")->GetType() << std::endl <<
                 out.GetProperty(L"StdErr")->GetStrValue() << std::endl << L"error code: " <<
                 out.GetProperty(L"ReturnCode")->GetIntValue();
         }

         CPPUNIT_ASSERT( !out.GetProperty(L"StdOut")->GetStrValue().empty());
         CPPUNIT_ASSERT( !out.GetProperty(L"StdErr")->GetStrValue().empty());
         CPPUNIT_ASSERT_EQUAL( out.GetProperty(L"ReturnCode")->GetIntValue(), 0);
         CPPUNIT_ASSERT( out.GetProperty(L"StdOut")->GetStrValue() == L"run-test-unit\n" );
         CPPUNIT_ASSERT( out.GetProperty(L"StdErr")->GetStrValue() == L"-test-\n" );
    }

    void testDoInvokeMethodScriptOKWithUpperCaseSudoElevation ()
    {
        SCXArgs args;
        SCXArgs out;
        SCXProperty result;
        SCXInstance objectPath;
        objectPath.SetCimClassName(L"SCX_OperatingSystem");

        SCXCallContext context(objectPath, eDirectSupport);

        SCXProperty cmd(L"Script",
             L"#!/bin/sh\n"
             L"# write something to stdout stream\n"
             L"echo \"$3-$2-$1\"\n"
             L"# and now create stderr output\n"
             L"echo \"-$2-\">&2\n"
             L"exit 0\n" );
        SCXProperty arguments(L"Arguments", L"unit test run");
        SCXProperty timeout(L"timeout", static_cast<unsigned int>(100));
        SCXProperty elevation(L"ElevationType", L"SUDO");

        args.AddProperty(cmd);
        args.AddProperty(timeout);
        args.AddProperty(arguments);
        args.AddProperty(elevation);

        pp->TestDoInvokeMethod(context, L"ExecuteScript", args, out, result);

        // Print out results. Saved for debug.
        if ( c_EnableDebugOutput ) {
             std::wcout << std::endl << out.GetProperty(L"StdOut")->GetStrValue() << std::endl <<
                 (int)out.GetProperty(L"StdOut")->GetType() << std::endl <<
                 out.GetProperty(L"StdErr")->GetStrValue() << std::endl << L"error code: " <<
                 out.GetProperty(L"ReturnCode")->GetIntValue();
         }

         CPPUNIT_ASSERT( !out.GetProperty(L"StdOut")->GetStrValue().empty());
         CPPUNIT_ASSERT( !out.GetProperty(L"StdErr")->GetStrValue().empty());
         CPPUNIT_ASSERT_EQUAL( out.GetProperty(L"ReturnCode")->GetIntValue(), 0);
         CPPUNIT_ASSERT( out.GetProperty(L"StdOut")->GetStrValue() == L"run-test-unit\n" );
         CPPUNIT_ASSERT( out.GetProperty(L"StdErr")->GetStrValue() == L"-test-\n" );
    }

    void testDoInvokeMethodScriptOKWithEmptyElevation ()
    {
         SCXArgs args;
         SCXArgs out;
         SCXProperty result;
         SCXInstance objectPath;
         objectPath.SetCimClassName(L"SCX_OperatingSystem");

         SCXCallContext context(objectPath, eDirectSupport);

         SCXProperty cmd(L"Script",
              L"#!/bin/sh\n"
              L"# write something to stdout stream\n"
              L"echo \"$3-$2-$1\"\n"
              L"# and now create stderr output\n"
              L"echo \"-$2-\">&2\n"
              L"exit 0\n" );
         SCXProperty arguments(L"Arguments", L"unit test run");
         SCXProperty timeout(L"timeout", static_cast<unsigned int>(100));
         SCXProperty elevation(L"ElevationType", L"");

         args.AddProperty(cmd);
         args.AddProperty(timeout);
         args.AddProperty(arguments);
         args.AddProperty(elevation);

         pp->TestDoInvokeMethod(context, L"ExecuteScript", args, out, result);

         // Print out results. Saved for debug.
         if ( c_EnableDebugOutput ) {
              std::wcout << std::endl << out.GetProperty(L"StdOut")->GetStrValue() << std::endl <<
                  (int)out.GetProperty(L"StdOut")->GetType() << std::endl <<
                  out.GetProperty(L"StdErr")->GetStrValue() << std::endl << L"error code: " <<
                  out.GetProperty(L"ReturnCode")->GetIntValue();
         }

         CPPUNIT_ASSERT( !out.GetProperty(L"StdOut")->GetStrValue().empty());
         CPPUNIT_ASSERT( !out.GetProperty(L"StdErr")->GetStrValue().empty());
         CPPUNIT_ASSERT_EQUAL( out.GetProperty(L"ReturnCode")->GetIntValue(), 0);
         CPPUNIT_ASSERT( out.GetProperty(L"StdOut")->GetStrValue() == L"run-test-unit\n" );
         CPPUNIT_ASSERT( out.GetProperty(L"StdErr")->GetStrValue() == L"-test-\n" );
    }

    void testDoInvokeMethodScriptFailed ()
    {
        try {
            SCXArgs args;
            SCXArgs out;
            SCXProperty result;
            SCXInstance objectPath;
            objectPath.SetCimClassName(L"SCX_OperatingSystem");

            SCXCallContext context(objectPath, eDirectSupport);

            SCXProperty cmd(L"Script", 
                L"#!/bin/sh\n"
                L"no_exisiting_command_echo \"$3-$2-$1\"\n"
                L"# generate error code we can check later\n"
                L"exit 7\n" );
            SCXProperty arguments(L"Arguments", L"unit test run");
            SCXProperty timeout(L"timeout", static_cast<unsigned int>(100));

            args.AddProperty(cmd);
            args.AddProperty(timeout);
            args.AddProperty(arguments);

            pp->TestDoInvokeMethod(context, L"ExecuteScript", args, out, result);

            // Print out results. Saved for debug.
            if ( c_EnableDebugOutput ) {
                std::wcout << std::endl << out.GetProperty(L"StdOut")->GetStrValue() << std::endl <<
                    (int)out.GetProperty(L"StdOut")->GetType() << std::endl <<
                    out.GetProperty(L"StdErr")->GetStrValue() << std::endl << L"error code: " <<
                    out.GetProperty(L"ReturnCode")->GetIntValue();
            }

            CPPUNIT_ASSERT( out.GetProperty(L"StdOut")->GetStrValue().empty());
            CPPUNIT_ASSERT( !out.GetProperty(L"StdErr")->GetStrValue().empty());
            CPPUNIT_ASSERT_EQUAL( out.GetProperty(L"ReturnCode")->GetIntValue(), 7);

        } catch (SCXException& e) {
            std::wcout << L"\nException in testDoInvokeMethod: " << e.What()
                       << L" @ " << e.Where() << std::endl;
            CPPUNIT_ASSERT(!"Exception");
        } 
    }

    void testDoInvokeMethodScriptNonSH ()
    {
        try {
            SCXArgs args;
            SCXArgs out;
            SCXProperty result;
            SCXInstance objectPath;
            objectPath.SetCimClassName(L"SCX_OperatingSystem");

            SCXCallContext context(objectPath, eDirectSupport);

            /* 
               Try to find bash.
             */
            std::list<std::wstring> bashPaths;
            bashPaths.push_back(L"/bin/bash");
            bashPaths.push_back(L"/usr/bin/bash");
            bashPaths.push_back(L"/usr/local/bin/bash");
            std::wstring bash = L"";
            for (std::list<std::wstring>::const_iterator iter = bashPaths.begin();
                 iter != bashPaths.end();
                 ++iter)
            {
                if (SCXFile::Exists(*iter))
                {
                    bash = *iter;
                    bash.append(L"\n");
                }
            }

            CPPUNIT_ASSERT(L"" != bash);


            // This script will return what shell it is run in.
            SCXProperty cmd(L"Script", 
                            std::wstring(L"#!")
                            .append(bash).append(L"echo $BASH\n" ));

            SCXProperty arguments(L"Arguments", L"");
            SCXProperty timeout(L"timeout", static_cast<unsigned int>(100));

            args.AddProperty(cmd);
            args.AddProperty(timeout);
            args.AddProperty(arguments);

            pp->TestDoInvokeMethod(context, L"ExecuteScript", args, out, result);

            CPPUNIT_ASSERT(bash == out.GetProperty(L"StdOut")->GetStrValue());
            CPPUNIT_ASSERT_EQUAL( out.GetProperty(L"ReturnCode")->GetIntValue(), 0);

        } catch (SCXException& e) {
            std::wcout << L"\nException in testDoInvokeMethodScriptNonSH: " << e.What()
                       << L" @ " << e.Where() << std::endl;
            CPPUNIT_ASSERT(!"Exception");
        } 
    }

    void testDoInvokeMethodScriptNoHashBang ()
    {
        try {
            SCXArgs args;
            SCXArgs out;
            SCXProperty result;
            SCXInstance objectPath;
            objectPath.SetCimClassName(L"SCX_OperatingSystem");

            SCXCallContext context(objectPath, eDirectSupport);

            SCXProperty cmd(L"Script", 
                L"# write something to stdout stream\n"
                L"echo \"$3-$2-$1\"\n"
                L"# and now create stderr output\n"
                L"echo \"-$2-\">&2\n"
                L"exit 0\n" );
            SCXProperty arguments(L"Arguments", L"unit test run");
            SCXProperty timeout(L"timeout", static_cast<unsigned int>(100));

            args.AddProperty(cmd);
            args.AddProperty(timeout);
            args.AddProperty(arguments);

            pp->TestDoInvokeMethod(context, L"ExecuteScript", args, out, result);

            // Print out results. Saved for debug.
            if ( c_EnableDebugOutput ) {
                std::wcout << std::endl << out.GetProperty(L"StdOut")->GetStrValue() << std::endl <<
                    (int)out.GetProperty(L"StdOut")->GetType() << std::endl <<
                    out.GetProperty(L"StdErr")->GetStrValue() << std::endl << L"error code: " <<
                    out.GetProperty(L"ReturnCode")->GetIntValue();
            }

            CPPUNIT_ASSERT( !out.GetProperty(L"StdOut")->GetStrValue().empty());
            CPPUNIT_ASSERT( !out.GetProperty(L"StdErr")->GetStrValue().empty());
            CPPUNIT_ASSERT_EQUAL( out.GetProperty(L"ReturnCode")->GetIntValue(), 0);
            CPPUNIT_ASSERT( out.GetProperty(L"StdOut")->GetStrValue() == L"run-test-unit\n" );
            CPPUNIT_ASSERT( out.GetProperty(L"StdErr")->GetStrValue() == L"-test-\n" );

        } catch (SCXException& e) {
            std::wcout << L"\nException in testDoInvokeMethodScriptNoHashBang: " << e.What()
                       << L" @ " << e.Where() << std::endl;
            CPPUNIT_ASSERT(!"Exception");
        } 
    }

    void testChRoot()
    {
        // I want to create my own RunAsProvider.
        pp->TestDoCleanup();
        pp = 0;
        SCXCoreLib::SCXHandle<RunAsConfigurator> configParser(
            new RunAsConfigurator(
                SCXCoreLib::SCXHandle<ConfigurationParser>(new ConfigurationStringParser(L"ChRootPath = ./testChRoot\nCWD = ./\n")),
                SCXCoreLib::SCXHandle<ConfigurationWriter>(0) ) );
        configParser->Parse();
        if (0 == geteuid() && ! configParser->GetAllowRoot())
        {
            configParser->SetAllowRoot(true);
        }
        pp = new TestableRunAsProvider(configParser);
        pp->TestDoInit();

        system("rm -rf testChRoot > /dev/null 2>&1");

        // Create an environment to chroot to.
        SCXDirectory::CreateDirectory(L"testChRoot/");

        // Write our script out
        {
            std::ofstream ofs("testChRoot/setup.sh");
            ofs << "BASE=testChRoot" << std::endl;
            ofs << "FILESET=\"\\" << std::endl;
            ofs << "    /bin/touch \\" << std::endl;
            ofs << "    /lib64/ld-linux-x86-64.so.2 \\" << std::endl;
            ofs << "    /lib64/libc.so.6 \\" << std::endl;
            ofs << "    /lib/`uname -i`-linux-gnu/libc.so.6 \\" << std::endl;
            ofs << "    /lib64/libpthread.so.0 \\" << std::endl;
            ofs << "    /lib64/librt.so.1 \\" << std::endl;
            ofs << "    /lib/`uname -i`-linux-gnu/librt.so.1 \\" << std::endl;
            ofs << "    /lib64/tls/libc.so.6 \\" << std::endl;
            ofs << "    /lib/ld-linux.so.2 \\" << std::endl;
            ofs << "    /lib/libc.so.6 \\" << std::endl;
            ofs << "    /lib/libpthread.so.0 \\" << std::endl;
            ofs << "    /lib/`uname -i`-linux-gnu/libpthread.so.0 \\" << std::endl;
            ofs << "    /lib/librt.so.1 \\" << std::endl;
            ofs << "    /usr/lib/dld.sl \\" << std::endl;
            ofs << "    /usr/lib/hpux32/dld.so \\" << std::endl;
            ofs << "    /usr/lib/hpux32/libc.so.1 \\" << std::endl;
            ofs << "    /usr/lib/hpux32/libdl.so.1 \\" << std::endl;
            ofs << "    /usr/lib/hpux32/uld.so \\" << std::endl;
            ofs << "    /usr/lib/ld.so.1 \\" << std::endl;
            ofs << "    /usr/lib/libc.2 \\" << std::endl;
            ofs << "    /usr/lib/libc.a \\" << std::endl;
            ofs << "    /usr/lib/libcmd.so.1 \\" << std::endl;
            ofs << "    /usr/lib/libcrypt.a \\" << std::endl;
            ofs << "    /usr/lib/libc.so.1 \\" << std::endl;
            ofs << "    /usr/lib/libdld.2 \\" << std::endl;
            ofs << "    /usr/lib/libdl.so.1 \\" << std::endl;
            ofs << "    \"" << std::endl;
            ofs << "" << std::endl;
            ofs << "" << std::endl;
            ofs << "rm -rf ${BASE} >/dev/null 2>&1" << std::endl;
            ofs << "for f in ${FILESET} ; do" << std::endl;
            ofs << "    test -r $f && mkdir -p ${BASE}/$(dirname $f) && cp -p $f ${BASE}/$f" << std::endl;
            ofs << "done" << std::endl;
            ofs << "exit 0" << std::endl;
        }

        int err = system("chmod u+x testChRoot/setup.sh && bash -c ./testChRoot/setup.sh");
        if (err)
        {
            std::ostringstream os;
            os << "Unexpected error in setup: " << strerror(err & 127);
            CPPUNIT_FAIL(os.str().c_str());
        }

        try {
            SCXArgs args;
            SCXArgs out;        // Not used
            SCXProperty result;
            SCXInstance objectPath;
            objectPath.SetCimClassName(L"SCX_OperatingSystem");

            SCXCallContext context(objectPath, eDirectSupport);

            SCXProperty cmd(L"Command", L"/bin/touch /ExecuteCommandWasHere");

            SCXProperty timeout(L"timeout", static_cast<unsigned int>(100));

            args.AddProperty(cmd);
            args.AddProperty(timeout);

            pp->TestDoInvokeMethod(context, L"ExecuteCommand", args, out, result);
            
            if (out.GetProperty(L"ReturnCode")->GetIntValue() != 0)
            {
                // Probably failed to chroot because of permissions.
                if (out.GetProperty(L"StdErr")->GetStrValue().find(L"Failed to chroot") == 0)
                {
                    SCXUNIT_WARNING(out.GetProperty(L"StdErr")->GetStrValue());
                }
                else
                {
                    std::wcout << std::endl << out.GetProperty(L"StdErr")->GetStrValue() << std::endl;
                    CPPUNIT_FAIL("Unexpected error in chroot");
                }
                return;
            }

            CPPUNIT_ASSERT( SCXFile::Exists(L"testChRoot/ExecuteCommandWasHere") );
        } catch (SCXException& e) {
            std::wcout << L"\nException in testChRoot: " << e.What()
                       << L" @ " << e.Where() << std::endl;
            CPPUNIT_ASSERT(!"Exception");
        }
    }

    void testCWD()
    {
        // I want to create my own RunAsProvider.
        pp->TestDoCleanup();
        pp = 0;
        SCXCoreLib::SCXHandle<RunAsConfigurator> configParser(
            new RunAsConfigurator(
                SCXCoreLib::SCXHandle<ConfigurationParser>(new ConfigurationStringParser(L"CWD = ./testCWD/\n")), 
                SCXCoreLib::SCXHandle<ConfigurationWriter>(0) ) );
        configParser->Parse();
        if (0 == geteuid() && ! configParser->GetAllowRoot())
        {
            configParser->SetAllowRoot(true);
        }
        pp = new TestableRunAsProvider(configParser);
        pp->TestDoInit();

        system("rm -rf testCWD > /dev/null 2>&1");
        SCXDirectory::CreateDirectory(L"testCWD/");

        try {
            SCXArgs args;
            SCXArgs out;        // Not used
            SCXProperty result;
            SCXInstance objectPath;
            objectPath.SetCimClassName(L"SCX_OperatingSystem");

            SCXCallContext context(objectPath, eDirectSupport);

            SCXProperty cmd(L"Command", L"/bin/touch ./ExecuteCommandWasHere");

            SCXProperty timeout(L"timeout", static_cast<unsigned int>(100));

            args.AddProperty(cmd);
            args.AddProperty(timeout);

            pp->TestDoInvokeMethod(context, L"ExecuteCommand", args, out, result);
            
            if (out.GetProperty(L"ReturnCode")->GetIntValue() != 0)
            {
                std::wcout << std::endl << out.GetProperty(L"StdErr")->GetStrValue() << std::endl;
                CPPUNIT_FAIL("Unexpected error in chdir");
            }

            CPPUNIT_ASSERT( SCXFile::Exists(L"testCWD/ExecuteCommandWasHere") );
        } catch (SCXException& e) {
            std::wcout << L"\nException in testCWD: " << e.What()
                       << L" @ " << e.Where() << std::endl;
            CPPUNIT_ASSERT(!"Exception");
        }
        system("rm -rf testCWD > /dev/null 2>&1");
    }
};

CPPUNIT_TEST_SUITE_REGISTRATION( SCXRunAsProviderTest );
