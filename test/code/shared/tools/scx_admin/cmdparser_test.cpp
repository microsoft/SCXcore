/*--------------------------------------------------------------------------------
  Copyright (c) Microsoft Corporation.  All rights reserved.

*/
/**
   \file

   \brief      Tests for configurator functionality which is part of the scx_admin tool

   \date        2008-08-28 13:48

*/
/*----------------------------------------------------------------------------*/

#include <scxcorelib/scxcmn.h>
#include <cmdparser.h> 
#include <testutils/scxunit.h>
#include <scxcorelib/scxexception.h>
#include <scxcorelib/scxfile.h>


using namespace SCX_Admin;
// using namespace SCXCoreLib;
// using namespace SCXSystemLib;


class CmdParserTest : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE( CmdParserTest );
    CPPUNIT_TEST( testQuiet );
    CPPUNIT_TEST( testLogList );
    CPPUNIT_TEST( testLogRotate );
    CPPUNIT_TEST( testLogReset );
    CPPUNIT_TEST( testLogSet );
    CPPUNIT_TEST( testLogSetProv );
    CPPUNIT_TEST( testLogResetProv );
    CPPUNIT_TEST( testLogRemoveProv );
#if !defined(SCX_STACK_ONLY)
    CPPUNIT_TEST( testConfigList );
    CPPUNIT_TEST( testConfigSet );
    CPPUNIT_TEST( testConfigReset );
    CPPUNIT_TEST( testProviderNameIsCaseSensitive );
    CPPUNIT_TEST( testProviderParametersPreservesCase );
#endif
    CPPUNIT_TEST( testStartStop );
    CPPUNIT_TEST( testStatus );
    CPPUNIT_TEST( testProviderService );
    CPPUNIT_TEST( testShowVersion );
    CPPUNIT_TEST( testArgumentIsCaseInsensitive );
    CPPUNIT_TEST( testServiceIsCaseInsensitive );
    CPPUNIT_TEST( testGenericLogLevelIsCaseInsensitive );
    CPPUNIT_TEST( testLogSetProviderArgumentPreservesCase );
    CPPUNIT_TEST_SUITE_END();

private:
    std::vector< Operation > GivenParsedParameters(int argc, const char** argv)
    {
        std::vector< Operation > operations;
        std::wstring error_msg;

        CPPUNIT_ASSERT( ParseAllParameters( argc, argv, operations, error_msg ) );

        // no error message
        CPPUNIT_ASSERT( error_msg.empty() );

        return operations;
    }

    std::wstring GivenParseFailure(int argc, const char** argv)
    {
        std::vector< Operation > operations;
        std::wstring error_msg;
        
        CPPUNIT_ASSERT( ! ParseAllParameters( argc, argv, operations, error_msg ) );

        return error_msg;
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

    typedef const char* PCHAR;
    
    void testQuiet(void)
    {
        PCHAR   argv[] = {"-q"};

        std::vector< Operation > operations = GivenParsedParameters(DIM(argv), argv);

        // should return only one operation
        CPPUNIT_ASSERT_EQUAL(static_cast<size_t>(1), operations.size() );
        CPPUNIT_ASSERT( operations[0].m_eType == Operation::eOpType_GlobalOption_Quiet );
    }

    void testLogList()
    {
        PCHAR   argv[] = {"-log-list"};

        std::vector< Operation > operations = GivenParsedParameters(DIM(argv), argv);
        // should return only one operation
        CPPUNIT_ASSERT_EQUAL( static_cast<size_t>(1), operations.size() );
        CPPUNIT_ASSERT( operations[0].m_eType == Operation::eOpType_Log_List);
        CPPUNIT_ASSERT( operations[0].m_eComponent == Operation::eCompType_Default);

        PCHAR   argv2[] = {"-log-list", "CImoM"};

        operations = GivenParsedParameters(DIM(argv2), argv2);
        // should return only one operation
        CPPUNIT_ASSERT_EQUAL( static_cast<size_t>(1), operations.size() );
        CPPUNIT_ASSERT( operations[0].m_eType == Operation::eOpType_Log_List);
        CPPUNIT_ASSERT( operations[0].m_eComponent == Operation::eCompType_CIMom);
    }

    void testLogRotate()
    {
        PCHAR   argv[] = {"-log-rotate"};

        std::vector< Operation > operations = GivenParsedParameters(DIM(argv), argv);
        // should return only one operation
        CPPUNIT_ASSERT_EQUAL( static_cast<size_t>(1), operations.size() );
        CPPUNIT_ASSERT( operations[0].m_eType == Operation::eOpType_Log_Rotate);
        CPPUNIT_ASSERT( operations[0].m_eComponent == Operation::eCompType_Default);

        PCHAR   argv2[] = {"-log-rotate", "provIder"};

        operations = GivenParsedParameters(DIM(argv2), argv2);
        // should return only one operation
        CPPUNIT_ASSERT_EQUAL( static_cast<size_t>(1), operations.size() );
        CPPUNIT_ASSERT( operations[0].m_eType == Operation::eOpType_Log_Rotate);
        CPPUNIT_ASSERT( operations[0].m_eComponent == Operation::eCompType_Provider);
    }

    void testLogReset()
    {
        PCHAR   argv[] = {"-log-reset"};

        std::vector< Operation > operations = GivenParsedParameters(DIM(argv), argv);
        // should return only one operation
        CPPUNIT_ASSERT_EQUAL( static_cast<size_t>(1), operations.size() );
        CPPUNIT_ASSERT( operations[0].m_eType == Operation::eOpType_Log_Reset);
        CPPUNIT_ASSERT( operations[0].m_eComponent == Operation::eCompType_Default);

        PCHAR   argv2[] = {"-log-reset", "alL"};

        operations = GivenParsedParameters(DIM(argv2), argv2);
        // should return only one operation
        CPPUNIT_ASSERT_EQUAL( static_cast<size_t>(1), operations.size() );
        CPPUNIT_ASSERT( operations[0].m_eType == Operation::eOpType_Log_Reset);
        CPPUNIT_ASSERT( operations[0].m_eComponent == Operation::eCompType_All);
    }
    
    void testLogSet()
    {
        PCHAR   argv[] = {"-log-set", "verbose"};

        std::vector< Operation > operations = GivenParsedParameters(DIM(argv), argv);
        // should return only one operation
        CPPUNIT_ASSERT_EQUAL( static_cast<size_t>(1), operations.size() );
        CPPUNIT_ASSERT( operations[0].m_eType == Operation::eOpType_Log_Set);
        CPPUNIT_ASSERT( operations[0].m_eComponent == Operation::eCompType_Default);
        CPPUNIT_ASSERT( operations[0].m_eLogLevel == SCX_AdminLogAPI::eLogLevel_Verbose);

        PCHAR   argv3[] = {"-log-set", "provider", "erroRs"};

        operations = GivenParsedParameters(DIM(argv3), argv3);
        // should return only one operation
        CPPUNIT_ASSERT_EQUAL( static_cast<size_t>(1), operations.size() );
        CPPUNIT_ASSERT( operations[0].m_eType == Operation::eOpType_Log_Set);
        CPPUNIT_ASSERT( operations[0].m_eComponent == Operation::eCompType_Provider);
        CPPUNIT_ASSERT( operations[0].m_eLogLevel == SCX_AdminLogAPI::eLogLevel_Errors);
    }
    
    void testLogSetProv()
    {
        PCHAR   argv[] = {"-log-set", "provider", "FILE:/var/opt/microsoft/scx/log/scx.log=TRACE"};

        std::vector< Operation > operations = GivenParsedParameters(DIM(argv), argv);
        // should return only one operation
        CPPUNIT_ASSERT_EQUAL( static_cast<size_t>(1), operations.size() );
        CPPUNIT_ASSERT( operations[0].m_eType == Operation::eOpType_Log_Prov_Set);
        CPPUNIT_ASSERT( operations[0].m_strName == L"FILE:/var/opt/microsoft/scx/log/scx.log");
        CPPUNIT_ASSERT( operations[0].m_strValue == L"TRACE");

        PCHAR   argv2[] = {"-log-set", "provider", "FILE:/var/opt/microsoft/scx/log/scx.log"};

        std::wstring error_msg = GivenParseFailure(DIM(argv2), argv2);
        CPPUNIT_ASSERT( ! error_msg.empty() );
    }

    void testLogResetProv()
    {
        PCHAR   argv[] = {"-log-reset", "provider"};

        std::vector< Operation > operations = GivenParsedParameters(DIM(argv), argv);
        // should return only one operation
        CPPUNIT_ASSERT_EQUAL( static_cast<size_t>(1), operations.size() );
        CPPUNIT_ASSERT( operations[0].m_eType == Operation::eOpType_Log_Reset);
        CPPUNIT_ASSERT( operations[0].m_eComponent == Operation::eCompType_Provider);

        PCHAR   argv2[] = {"-log-reset", "provider", "FILE:/var/opt/microsoft/scx/log/scx.log"};

        operations = GivenParsedParameters(DIM(argv2), argv2);
        // should return only one operation
        CPPUNIT_ASSERT_EQUAL( static_cast<size_t>(1), operations.size() );
        CPPUNIT_ASSERT( operations[0].m_eType == Operation::eOpType_Log_Prov_Reset);
        CPPUNIT_ASSERT( operations[0].m_strName == L"FILE:/var/opt/microsoft/scx/log/scx.log");
    }
    
    void testLogRemoveProv()
    {
        PCHAR   argv[] = {"-log-remove", "provider"};

        std::vector< Operation > operations = GivenParsedParameters(DIM(argv), argv);
        // should return only one operation
        CPPUNIT_ASSERT_EQUAL( static_cast<size_t>(1), operations.size() );
        CPPUNIT_ASSERT( operations[0].m_eType == Operation::eOpType_Log_Prov_Remove);
        CPPUNIT_ASSERT( operations[0].m_strName == L"");

        PCHAR   argv2[] = {"-log-remove", "provider", "STDOUT"};

        operations = GivenParsedParameters(DIM(argv2), argv2);
        // should return only one operation
        CPPUNIT_ASSERT_EQUAL( static_cast<size_t>(1), operations.size() );
        CPPUNIT_ASSERT( operations[0].m_eType == Operation::eOpType_Log_Prov_Remove);
        CPPUNIT_ASSERT( operations[0].m_strName == L"STDOUT");
    }
    
#if !defined(SCX_STACK_ONLY)

    void testConfigList()
    {
        PCHAR   argv[] = {"-config-list", "rUnas"};

        std::vector< Operation > operations = GivenParsedParameters(DIM(argv), argv);
        // should return only one operation
        CPPUNIT_ASSERT_EQUAL( static_cast<size_t>(1), operations.size() );
        CPPUNIT_ASSERT( operations[0].m_eType == Operation::eOpType_Config_List);
    }
    
    void testConfigSet()
    {
        PCHAR   argv[] = {"-config-set", "rUnas", "cwd=/opt"};

        std::vector< Operation > operations = GivenParsedParameters(DIM(argv), argv);
        // should return only one operation
        CPPUNIT_ASSERT_EQUAL( static_cast<size_t>(1), operations.size() );
        CPPUNIT_ASSERT( operations[0].m_eType == Operation::eOpType_Config_Set);
        CPPUNIT_ASSERT( operations[0].m_strName == L"cwd" );
        CPPUNIT_ASSERT( operations[0].m_strValue == L"/opt" );
    }
    
    void testConfigReset()
    {
        PCHAR   argv[] = {"-config-reset", "rUnas", "allowRoot"};

        std::vector< Operation > operations = GivenParsedParameters(DIM(argv), argv);
        // should return only one operation
        CPPUNIT_ASSERT_EQUAL( static_cast<size_t>(1), operations.size() );
        CPPUNIT_ASSERT( operations[0].m_eType == Operation::eOpType_Config_Reset);
        CPPUNIT_ASSERT( operations[0].m_strName == L"allowRoot" );
    }

    /**
        Tests that the provider name (runas) for provider config
        is case insensitive.
     */
    void testProviderNameIsCaseSensitive()
    {
        PCHAR   argv[] = {"-config-list", "runas",
                          "-config-list", "RUNAS",
                          "-config-list", "RuNaS"};
        std::vector<Operation> operations = GivenParsedParameters(DIM(argv), argv);
        // should return three operations
        CPPUNIT_ASSERT_EQUAL( static_cast<size_t>(3), operations.size() );
        for (std::vector<Operation>::const_iterator iter = operations.begin();
             iter != operations.end();
             ++iter)
        {
            CPPUNIT_ASSERT( iter->m_eType == Operation::eOpType_Config_List);
        }
    }

    /**
        The cmdparser should not alter the case of the parameters for 
        provider configuration. It is up to the speciffic provider
        to descide if the parameter should be case sensitive or not.
     */
    void testProviderParametersPreservesCase()
    {
        PCHAR   argv[] = {"-config-set", "runas", "SomeParameter=/some/dir/",
                          "-config-set", "runas", "someparameter=/Some/Dir/"};
        std::vector<Operation> operations = GivenParsedParameters(DIM(argv), argv);
        // should return two operations
        CPPUNIT_ASSERT_EQUAL( static_cast<size_t>(2), operations.size() );
        CPPUNIT_ASSERT( operations[0].m_strName == L"SomeParameter" );
        CPPUNIT_ASSERT( operations[0].m_strValue == L"/some/dir/" );
        CPPUNIT_ASSERT( operations[1].m_strName == L"someparameter" );
        CPPUNIT_ASSERT( operations[1].m_strValue == L"/Some/Dir/" );
    }

#endif

    void testStartStop()
    {
        PCHAR   argv[] = {"-start", "all"};

        std::vector< Operation > operations = GivenParsedParameters(DIM(argv), argv);
        // should return only one operation
        CPPUNIT_ASSERT_EQUAL( static_cast<size_t>(1), operations.size() );
        CPPUNIT_ASSERT( operations[0].m_eType == Operation::eOpType_Svc_Start);
        CPPUNIT_ASSERT( operations[0].m_eComponent == Operation::eCompType_All);

        PCHAR   argv2[] = {"-stop", "-start" };
        
        operations = GivenParsedParameters(DIM(argv2), argv2);
        // should return two operations
        CPPUNIT_ASSERT_EQUAL( static_cast<size_t>(2), operations.size() );
        CPPUNIT_ASSERT( operations[0].m_eType == Operation::eOpType_Svc_Stop);
        CPPUNIT_ASSERT( operations[0].m_eComponent == Operation::eCompType_Default);
        CPPUNIT_ASSERT( operations[1].m_eType == Operation::eOpType_Svc_Start);
        CPPUNIT_ASSERT( operations[1].m_eComponent == Operation::eCompType_Default);
    }

    void testStatus()
    {
        PCHAR   argv[] = {"-status", "-status", "all" };

        std::vector< Operation > operations = GivenParsedParameters(DIM(argv), argv);
        // should return three operations
        CPPUNIT_ASSERT_EQUAL( static_cast<size_t>(2), operations.size() );
        CPPUNIT_ASSERT( operations[0].m_eType == Operation::eOpType_Svc_Status);
        CPPUNIT_ASSERT( operations[0].m_eComponent == Operation::eCompType_Default);
        CPPUNIT_ASSERT( operations[1].m_eType == Operation::eOpType_Svc_Status);
        CPPUNIT_ASSERT( operations[1].m_eComponent == Operation::eCompType_All);
    }

    void testProviderService()
    {
        PCHAR   argv[] = {"-status", "provider", "-restart", "provider", "-start", "provider", "-stop", "provider"};
        std::vector< Operation > operations = GivenParsedParameters(DIM(argv), argv);
        // should return three operations
        CPPUNIT_ASSERT_EQUAL( static_cast<size_t>(4), operations.size() );
        CPPUNIT_ASSERT( operations[0].m_eType == Operation::eOpType_Svc_Status);
        CPPUNIT_ASSERT( operations[0].m_eComponent == Operation::eCompType_Provider);
        CPPUNIT_ASSERT( operations[1].m_eType == Operation::eOpType_Svc_Restart);
        CPPUNIT_ASSERT( operations[1].m_eComponent == Operation::eCompType_Provider);
        CPPUNIT_ASSERT( operations[2].m_eType == Operation::eOpType_Svc_Start);
        CPPUNIT_ASSERT( operations[2].m_eComponent == Operation::eCompType_Provider);
        CPPUNIT_ASSERT( operations[3].m_eType == Operation::eOpType_Svc_Stop);
        CPPUNIT_ASSERT( operations[3].m_eComponent == Operation::eCompType_Provider);
    }

    void testShowVersion()
    {
        PCHAR   argv[] = {"-version", "-v" };

        std::vector< Operation > operations = GivenParsedParameters(DIM(argv), argv);
        // should return two operations
        CPPUNIT_ASSERT_EQUAL( static_cast<size_t>(2), operations.size() );
        CPPUNIT_ASSERT( operations[0].m_eType == Operation::eOpType_Show_Version);
        CPPUNIT_ASSERT( operations[0].m_eComponent == Operation::eCompType_Default);
        CPPUNIT_ASSERT( operations[1].m_eType == Operation::eOpType_Show_Version);
        CPPUNIT_ASSERT( operations[1].m_eComponent == Operation::eCompType_Default);
    }

    /**
        Tests that the "-*" arguemnts like -version and -start are case insensitive.
     */
    void testArgumentIsCaseInsensitive()
    {
        PCHAR   argv[] = {"-VERSION", "-V", "-version", "-v", "-VerSIon" };

        std::vector< Operation > operations = GivenParsedParameters(DIM(argv), argv);
        // should return five operations
        CPPUNIT_ASSERT_EQUAL( static_cast<size_t>(5), operations.size() );
        for (std::vector<Operation>::const_iterator iter = operations.begin();
             iter != operations.end();
             ++iter)
        {
            CPPUNIT_ASSERT( iter->m_eType == Operation::eOpType_Show_Version);
        }
    }

    /**
        Tests that service names (cimom, ...) for service control
        are case insensitive.
     */
    void testServiceIsCaseInsensitive()
    {
        PCHAR   argv[] = {"-start", "cimom", "-start", "CIMOM", "-start", "CiMoM"};

        std::vector<Operation> operations = GivenParsedParameters(DIM(argv), argv);
        // should return three operations
        CPPUNIT_ASSERT_EQUAL( static_cast<size_t>(3), operations.size() );
        for (std::vector<Operation>::const_iterator iter = operations.begin();
             iter != operations.end();
             ++iter)
        {
            CPPUNIT_ASSERT( iter->m_eComponent == Operation::eCompType_CIMom);
        }
    }

    /**
        The log level parameters should be case insensitive.
     */
    void testGenericLogLevelIsCaseInsensitive()
    {
        PCHAR   argv[] = {"-log-set", "all", "verbose",
                          "-log-set", "all", "VERBOSE",
                          "-log-set", "all", "VeRbOsE"};

        std::vector<Operation> operations = GivenParsedParameters(DIM(argv), argv);
        // should return three operations
        CPPUNIT_ASSERT_EQUAL( static_cast<size_t>(3), operations.size() );
        for (std::vector<Operation>::const_iterator iter = operations.begin();
             iter != operations.end();
             ++iter)
        {
            CPPUNIT_ASSERT( iter->m_eLogLevel == SCX_AdminLogAPI::eLogLevel_Verbose );
        }
    }

    /**
        The cmdparser should not alter the case of the parameters for 
        log set provider configuration. It is up to the speciffic configurator
        to descide if the parameter should be case sensitive or not.
     */
    void testLogSetProviderArgumentPreservesCase()
    {
        PCHAR   argv[] = {"-log-set", "provider", "stdout:some.module=info",
                          "-log-set", "provider", "STDOUT:sOmE.MoDuLe=INFO"};
        std::vector<Operation> operations = GivenParsedParameters(DIM(argv), argv);
        // should return two operations
        CPPUNIT_ASSERT_EQUAL( static_cast<size_t>(2), operations.size() );
        CPPUNIT_ASSERT( operations[0].m_strName == L"stdout:some.module" );
        CPPUNIT_ASSERT( operations[0].m_strValue == L"info" );
        CPPUNIT_ASSERT( operations[1].m_strName == L"STDOUT:sOmE.MoDuLe" );
        CPPUNIT_ASSERT( operations[1].m_strValue == L"INFO" );
    }

};

CPPUNIT_TEST_SUITE_REGISTRATION( CmdParserTest );

