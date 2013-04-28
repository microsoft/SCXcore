/*--------------------------------------------------------------------------------
  Copyright (c) Microsoft Corporation.  All rights reserved.

*/
/**
   \file

   \brief       Tests for the runas configurator

   \date        2008-08-27 16:04:59

*/
/*----------------------------------------------------------------------------*/

#include <scxcorelib/scxcmn.h>
#include <scxrunasconfigurator.h>
#include <testutils/scxunit.h>

using namespace SCXCoreLib;
using namespace SCXCore;

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

/*----------------------------------------------------------------------------*/
/**
   Class for writing generic configuration to a string.

*/
class ConfigurationStringWriter : public ConfigurationWriter
{
public:
    ConfigurationStringWriter() :
        m_Configuration(L"")
    {};

    void Write()
    {
        std::wostringstream stream(m_Configuration);
        WriteToStream(stream);
        m_Configuration = stream.str();
    };
    
    std::wstring GetString() const
    {
        return m_Configuration;
    }
private:
    std::wstring m_Configuration;
};

class SCXRunAsConfiguratorTest : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE( SCXRunAsConfiguratorTest );
    CPPUNIT_TEST( testEmptyConfiguration );
    CPPUNIT_TEST( testCommentsAreIgnored );
    CPPUNIT_TEST( testInvalidRowsAreIgnored );
    CPPUNIT_TEST( testAllowRoot );
    CPPUNIT_TEST( testGetChRootPath );
    CPPUNIT_TEST( testGetCWD );
    CPPUNIT_TEST( testUnexistingEnvVar );
    CPPUNIT_TEST( testSimpleEnvVarReplacement );
    CPPUNIT_TEST( testRecursiveEnvVarReplacement );
    CPPUNIT_TEST( testEnvVarRecurseLimit );
    CPPUNIT_TEST( testWriteEmptyConfiguration );
    CPPUNIT_TEST( testWriteAndRead );
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp(void)
    {
    }

    void tearDown(void)
    {
    }

    void testEmptyConfiguration()
    {
        RunAsConfigurator p = RunAsConfigurator(
            SCXCoreLib::SCXHandle<ConfigurationParser>(new ConfigurationStringParser(L"")), 
            SCXCoreLib::SCXHandle<ConfigurationWriter>(0)).Parse();
        CPPUNIT_ASSERT(p.GetAllowRoot() == true);
        CPPUNIT_ASSERT(p.GetChRootPath() == SCXFilePath(L""));
        CPPUNIT_ASSERT(p.GetCWD() == SCXFilePath(L"/var/opt/microsoft/scx/tmp/"));
    }

    void testCommentsAreIgnored()
    {
        RunAsConfigurator p = RunAsConfigurator(
            SCXCoreLib::SCXHandle<ConfigurationParser>(new ConfigurationStringParser(L"# AllowRoot = false")), 
            SCXCoreLib::SCXHandle<ConfigurationWriter>(0) ).Parse();
    
        CPPUNIT_ASSERT(p.GetAllowRoot() == true);
    }

    void testInvalidRowsAreIgnored()
    {
        std::wstring configData(L"# The next few lines are invalid\n"
                                L"AllowRoot = false = invalid row\n"
                                L"AllowRoot\n"
                                L"AllowRoot = invalidvalue\n"
                                L"${CWD}\n"
                                L"# Next is the valid line\n"
                                L"AllowRoot = true\n");
        RunAsConfigurator configParser(
            SCXCoreLib::SCXHandle<ConfigurationParser>(new ConfigurationStringParser(configData) ), 
            SCXCoreLib::SCXHandle<ConfigurationWriter>(0));
        configParser.Parse();
        
        CPPUNIT_ASSERT(configParser.GetAllowRoot() == true);
    }

    void testAllowRoot()
    {
        // inline construction was too complicated for old HP compiler - declare a variable
        RunAsConfigurator p1 = RunAsConfigurator(
            SCXCoreLib::SCXHandle<ConfigurationParser>(new ConfigurationStringParser(L"AllowRoot = false")),
            SCXCoreLib::SCXHandle<ConfigurationWriter>(0)).Parse();
        
        CPPUNIT_ASSERT(p1.GetAllowRoot() == false);

        RunAsConfigurator p2 = RunAsConfigurator(
            SCXCoreLib::SCXHandle<ConfigurationParser>(new ConfigurationStringParser(L"AllowRoot = no")), 
            SCXCoreLib::SCXHandle<ConfigurationWriter>(0)).Parse();
        
        CPPUNIT_ASSERT(p2.GetAllowRoot() == false);

        RunAsConfigurator p3 = RunAsConfigurator(
            SCXCoreLib::SCXHandle<ConfigurationParser>(new ConfigurationStringParser(L"AllowRoot = 0")), 
            SCXCoreLib::SCXHandle<ConfigurationWriter>(0)).Parse();
        
        CPPUNIT_ASSERT(p3.GetAllowRoot() == false);
    }

    void testGetChRootPath()
    {
        RunAsConfigurator p = RunAsConfigurator(
                SCXCoreLib::SCXHandle<ConfigurationParser>(new ConfigurationStringParser(L"ChRootPath = /What/ever/")), 
                SCXCoreLib::SCXHandle<ConfigurationWriter>(0)).Parse();
        
        CPPUNIT_ASSERT( p.GetChRootPath() == SCXFilePath(L"/What/ever/"));
    }

    void testGetCWD()
    {
        RunAsConfigurator p = RunAsConfigurator(
                SCXCoreLib::SCXHandle<ConfigurationParser>(new ConfigurationStringParser(L"CWD = /foo/bar/")), 
                SCXCoreLib::SCXHandle<ConfigurationWriter>(0)).Parse();
        
        CPPUNIT_ASSERT( p.GetCWD() == SCXFilePath(L"/foo/bar/"));
    }

    void testUnexistingEnvVar()
    {
        // Test unexisting env var results in empty string.
        RunAsConfigurator p1 = RunAsConfigurator(
            SCXCoreLib::SCXHandle<ConfigurationParser>(new ConfigurationStringParser(L"ChRootPath = $THIS_DOES_NOT_EXIST")), 
            SCXCoreLib::SCXHandle<ConfigurationWriter>(0)).Parse();
        CPPUNIT_ASSERT(p1.GetChRootPath() == L"");
        
        // Test again with different notation
        RunAsConfigurator p2 = RunAsConfigurator(
            SCXCoreLib::SCXHandle<ConfigurationParser>(new ConfigurationStringParser(L"ChRootPath = ${THIS_DOES_NOT_EXIST}")), 
            SCXCoreLib::SCXHandle<ConfigurationWriter>(0)).Parse();
        CPPUNIT_ASSERT(p2.GetChRootPath() == L"");
    }

    void testSimpleEnvVarReplacement()
    {
        putenv(const_cast<char *>("TEST_ENV_VARS_1=testEnvVars_1"));
        RunAsConfigurator p1 = RunAsConfigurator(
            SCXCoreLib::SCXHandle<ConfigurationParser>(new ConfigurationStringParser(L"ChRootPath = $TEST_ENV_VARS_1/")), 
            SCXCoreLib::SCXHandle<ConfigurationWriter>(0)).Parse();
        CPPUNIT_ASSERT(p1.GetChRootPath() == L"testEnvVars_1/");
        
        // Test again with different notation
        RunAsConfigurator p2 = RunAsConfigurator(
            SCXCoreLib::SCXHandle<ConfigurationParser>(new ConfigurationStringParser(L"ChRootPath = ${TEST_ENV_VARS_1}/")), 
            SCXCoreLib::SCXHandle<ConfigurationWriter>(0)).Parse();
        CPPUNIT_ASSERT(p2.GetChRootPath() == L"testEnvVars_1/");
    }

    void testRecursiveEnvVarReplacement()
    {
        putenv(const_cast<char *>("TEST_ENV_VARS_2=/$TEST_ENV_VARS_3/$TEST_ENV_VARS_4/"));
        putenv(const_cast<char *>("TEST_ENV_VARS_3=testEnvVars_3"));
        putenv(const_cast<char *>("TEST_ENV_VARS_4=testEnvVars_4"));
        RunAsConfigurator p1 = RunAsConfigurator(
            SCXCoreLib::SCXHandle<ConfigurationParser>(new ConfigurationStringParser(L"ChRootPath = $TEST_ENV_VARS_2")), 
            SCXCoreLib::SCXHandle<ConfigurationWriter>(0)).Parse();
        CPPUNIT_ASSERT(p1.GetChRootPath() == L"/testEnvVars_3/testEnvVars_4/");
        // Test again with different notation
        putenv(const_cast<char *>("TEST_ENV_VARS_2=/${TEST_ENV_VARS_3}/${TEST_ENV_VARS_4}/"));
        putenv(const_cast<char *>("TEST_ENV_VARS_3=testEnvVars_3"));
        putenv(const_cast<char *>("TEST_ENV_VARS_4=testEnvVars_4"));
        RunAsConfigurator p2 = RunAsConfigurator(
            SCXCoreLib::SCXHandle<ConfigurationParser>(new ConfigurationStringParser(L"ChRootPath = ${TEST_ENV_VARS_2}")), 
            SCXCoreLib::SCXHandle<ConfigurationWriter>(0)).Parse();
        CPPUNIT_ASSERT(p2.GetChRootPath() == L"/testEnvVars_3/testEnvVars_4/");
    }

    void testEnvVarRecurseLimit()
    {
        // Test that we don't recurse too far.
        putenv(const_cast<char *>("TEST_ENV_VARS_5=/$TEST_ENV_VARS_6/"));
        putenv(const_cast<char *>("TEST_ENV_VARS_6=/$TEST_ENV_VARS_5/"));

        RunAsConfigurator p(
                                        SCXCoreLib::SCXHandle<ConfigurationParser>(new ConfigurationStringParser(L"ChRootPath = $TEST_ENV_VARS_5")),
                                        SCXCoreLib::SCXHandle<ConfigurationWriter>(0));

        try {
            p.Parse();
            CPPUNIT_FAIL("\"SCXRunAsConfigurationException\" exception expected");
        } catch(SCXRunAsConfigurationException& e) {
            CPPUNIT_ASSERT(e.What().find(L"recursion") != std::wstring::npos);
        }
    }

    void testWriteEmptyConfiguration()
    {
        SCXHandle<ConfigurationStringWriter> writer( new ConfigurationStringWriter() );
        RunAsConfigurator p = RunAsConfigurator(
            SCXCoreLib::SCXHandle<ConfigurationParser>(new ConfigurationStringParser(L"")), 
            writer).Write();
        CPPUNIT_ASSERT(L"" == writer->GetString());
    }

    void testWriteAndRead()
    {
        SCXHandle<ConfigurationStringWriter> writer( new ConfigurationStringWriter() );
        RunAsConfigurator c1 = RunAsConfigurator(
            SCXCoreLib::SCXHandle<ConfigurationParser>(new ConfigurationStringParser(L"")), 
            writer);
        c1.SetAllowRoot(false);
        c1.SetChRootPath(L"/what/ever/");
        c1.SetCWD(L"/foo/bar/");
        c1.Write();

        SCXHandle<ConfigurationParser> parser( new ConfigurationStringParser(writer->GetString()));
        RunAsConfigurator c2 = RunAsConfigurator(
            parser, 
            SCXCoreLib::SCXHandle<ConfigurationWriter>(0)).Parse();

        CPPUNIT_ASSERT(c2.GetAllowRoot() == false);
        CPPUNIT_ASSERT(c2.GetChRootPath() == SCXFilePath(L"/what/ever/"));
        CPPUNIT_ASSERT(c2.GetCWD() == SCXFilePath(L"/foo/bar/"));
    }

};

CPPUNIT_TEST_SUITE_REGISTRATION( SCXRunAsConfiguratorTest );
