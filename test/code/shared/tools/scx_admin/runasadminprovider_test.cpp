/*--------------------------------------------------------------------------------
    Copyright (c) Microsoft Corporation.  All rights reserved. 
    
*/
/**
    \file        

    \brief       Tests for cim (i.e. openpegasus) configurator functionality which is part of the scx_admin tool

    \date        2008-08-28 16:41:48

*/
/*----------------------------------------------------------------------------*/
#include <scxcorelib/scxcmn.h>
#include <testutils/scxunit.h> /* This will include CPPUNIT helper macros too */
#include <scxcorelib/scxfile.h>

#include "runasadminprovider.h"

/*----------------------------------------------------------------------------*/
/**
   Class for parsing strings with generic configuration

*/
class ConfigurationStringParser : public SCXCore::ConfigurationParser
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

class ConfigurationDummyWriter : public SCXCore::ConfigurationWriter {
public:
    // this function is called from "SCX_RunAsConfigurator::Set"
    // since the latest has to update configuration file.
    // in unit-test we ignore it, so original file is not updated by the test
    void Write() {}
    
};
    
class RunAsAdminProviderTest : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE( RunAsAdminProviderTest );
    CPPUNIT_TEST( TestEmptyConfiguration );
    CPPUNIT_TEST( TestWriteAndRead );
    CPPUNIT_TEST( TestUnsupportedValues );
    CPPUNIT_TEST( TestReset );
    CPPUNIT_TEST( TestResetAllowRootWithNoSSHConfFile );
    CPPUNIT_TEST( TestResetAllowRootWithNoSSHConf );
    CPPUNIT_TEST( TestResetAllowRootWithSSHConfTrue );
    CPPUNIT_TEST( TestResetAllowRootWithSSHConfFalse );
    CPPUNIT_TEST( ResetCWDIsCaseInsensitive );
    CPPUNIT_TEST( ResetChRootPathIsCaseInsensitive );
    CPPUNIT_TEST( ResetAllowRootIsCaseInsensitive );
    CPPUNIT_TEST( CWDIsCaseInsensitive );
    CPPUNIT_TEST( CWDValueIsCaseSensitive );
    CPPUNIT_TEST( ChRootPathIsCaseInsensitive );
    CPPUNIT_TEST( ChRootPathValueIsCaseSensitive );
    CPPUNIT_TEST( AllowRootIsCaseInsensitive );
    CPPUNIT_TEST( AllowRootValueIsCaseInsensitive );
    CPPUNIT_TEST_SUITE_END();

private:
    SCX_RunAsAdminProvider GivenAdminProviderWithEmptyConfiguration()
    {
        return SCX_RunAsAdminProvider(
            SCXCoreLib::SCXHandle<SCXCore::ConfigurationParser>(new ConfigurationStringParser(L"")), 
            SCXCoreLib::SCXHandle<SCXCore::ConfigurationWriter>(new ConfigurationDummyWriter),
            SCXCoreLib::SCXFilePath(m_sshConf)
            );
    }

    SCXCoreLib::SCXFilePath m_sshConf;

    /**
        This method will print the configuration to a stream and then use 
        a RunAsConfigurator to parse the output so that it can be verified.
     */
    SCXCore::RunAsConfigurator GivenAReparsedConfiguration(const SCX_RunAsAdminProvider& conf)
    {
        // print configuration to stream.
        std::wostringstream buf;
        conf.Print(buf);

        // Create a string configuration parser.
        SCXHandle<ConfigurationStringParser> parser( new ConfigurationStringParser(buf.str()));
        
        // Inject the string configuration parser into a RunAsConfigurator and use it to
        // parse the configuration.
        return SCXCore::RunAsConfigurator(parser, 
                                          SCXCoreLib::SCXHandle<SCXCore::ConfigurationWriter>(0))
            .Parse();
    }

public:
    RunAsAdminProviderTest() : m_sshConf(L"./sshd.conf")
    {}

    void setUp(void)
    {
        CPPUNIT_ASSERT( ! SCXCoreLib::SCXFile::Exists(m_sshConf) );
    }

    void tearDown(void)
    {
        SCXCoreLib::SCXFile::Delete(m_sshConf);
    }

    void TestEmptyConfiguration()
    {
        SCX_RunAsAdminProvider conf = GivenAdminProviderWithEmptyConfiguration();
        std::wostringstream buf;
        CPPUNIT_ASSERT(conf.Print(buf));
        CPPUNIT_ASSERT(L"CWD = /var/opt/microsoft/scx/tmp/\nChRootPath = \nAllowRoot = true\n" == buf.str());
    }

    void TestWriteAndRead()
    {
        SCX_RunAsAdminProvider conf = GivenAdminProviderWithEmptyConfiguration();

        CPPUNIT_ASSERT(conf.Set(L"AllowRoot", L"false"));
        CPPUNIT_ASSERT(conf.Set(L"ChRootPath", L"/what/ever/"));
        CPPUNIT_ASSERT(conf.Set(L"CWD", L"/foo/bar/"));
        std::wostringstream buf;
        CPPUNIT_ASSERT(conf.Print(buf));
        
        SCXHandle<ConfigurationStringParser> parser( new ConfigurationStringParser(buf.str()));
        SCXCore::RunAsConfigurator c2 = SCXCore::RunAsConfigurator(
            parser, 
            SCXCoreLib::SCXHandle<SCXCore::ConfigurationWriter>(0)).Parse();

        CPPUNIT_ASSERT(c2.GetAllowRoot() == false);
        CPPUNIT_ASSERT(c2.GetChRootPath() == SCXFilePath(L"/what/ever/"));
        CPPUNIT_ASSERT(c2.GetCWD() == SCXFilePath(L"/foo/bar/"));
    }

    void TestUnsupportedValues()
    {
        SCX_RunAsAdminProvider conf = GivenAdminProviderWithEmptyConfiguration();

        CPPUNIT_ASSERT_THROW_MESSAGE( "exception is expected for unsupported property",
            conf.Set(L"AllowRoot", L"blaha"),
            SCXAdminException );
        
        CPPUNIT_ASSERT_THROW_MESSAGE( "exception is expected for unsupported property",
            conf.Set(L"NotSupported", L"/what/ever/"),
            SCXAdminException );
    }
    void TestReset()
    {
        SCX_RunAsAdminProvider conf = GivenAdminProviderWithEmptyConfiguration();

        CPPUNIT_ASSERT(conf.Set(L"ChRootPath", L"/what/ever/"));
        CPPUNIT_ASSERT(conf.Set(L"CWD", L"/foo/bar/"));
        CPPUNIT_ASSERT(conf.Set(L"AllowRoot", L"false"));

        CPPUNIT_ASSERT(conf.Reset(L"ChRootPath"));
        CPPUNIT_ASSERT(conf.Reset(L"CWD"));
        CPPUNIT_ASSERT(conf.Reset(L"AllowRoot"));

        CPPUNIT_ASSERT_THROW_MESSAGE( "exception is expected for unsupported property",
            conf.Reset(L"NotSupported"),
            SCXAdminException );
        
        std::wostringstream buf;
        CPPUNIT_ASSERT(conf.Print(buf));
        CPPUNIT_ASSERT(L"CWD = /var/opt/microsoft/scx/tmp/\nChRootPath = \nAllowRoot = true\n" == buf.str());
    }

    void TestResetAllowRootWithNoSSHConfFile()
    {
        SCX_RunAsAdminProvider conf = GivenAdminProviderWithEmptyConfiguration();

        CPPUNIT_ASSERT(conf.Set(L"AllowRoot", L"false"));
        CPPUNIT_ASSERT(conf.Reset(L"AllowRoot"));
        std::wostringstream buf;
        CPPUNIT_ASSERT(conf.Print(buf));
        CPPUNIT_ASSERT(L"CWD = /var/opt/microsoft/scx/tmp/\nChRootPath = \nAllowRoot = true\n" == buf.str());
    }

    void TestResetAllowRootWithNoSSHConf()
    {
        // This tests an ssh configuration whith no PermitRootLogin setting.
        std::vector<std::wstring> lines;
        lines.push_back(L"something 42");
        lines.push_back(L"# PermitRootLogin no");
        lines.push_back(L"something else");
        lines.push_back(L"");
        SCXFile::WriteAllLines(m_sshConf, lines, std::ios_base::out);
        
        SCX_RunAsAdminProvider conf = GivenAdminProviderWithEmptyConfiguration();

        CPPUNIT_ASSERT(conf.Set(L"AllowRoot", L"false"));
        CPPUNIT_ASSERT(conf.Reset(L"AllowRoot"));
        std::wostringstream buf;
        CPPUNIT_ASSERT(conf.Print(buf));
        CPPUNIT_ASSERT(L"CWD = /var/opt/microsoft/scx/tmp/\nChRootPath = \nAllowRoot = true\n" == buf.str());
    }

    void TestResetAllowRootWithSSHConfTrue()
    {
        std::vector<std::wstring> lines;
        lines.push_back(L"PermitRootLogin yes");
        lines.push_back(L"");
        SCXFile::WriteAllLines(m_sshConf, lines, std::ios_base::out);
        
        SCX_RunAsAdminProvider conf = GivenAdminProviderWithEmptyConfiguration();

        CPPUNIT_ASSERT(conf.Set(L"AllowRoot", L"false"));
        CPPUNIT_ASSERT(conf.Reset(L"AllowRoot"));
        std::wostringstream buf;
        CPPUNIT_ASSERT(conf.Print(buf));
        CPPUNIT_ASSERT(L"CWD = /var/opt/microsoft/scx/tmp/\nChRootPath = \nAllowRoot = true\n" == buf.str());
    }

    void TestResetAllowRootWithSSHConfFalse()
    {
        std::vector<std::wstring> lines;
        lines.push_back(L"PermitRootLogin no");
        lines.push_back(L"");
        SCXFile::WriteAllLines(m_sshConf, lines, std::ios_base::out);
        
        SCX_RunAsAdminProvider conf = GivenAdminProviderWithEmptyConfiguration();

        CPPUNIT_ASSERT(conf.Set(L"AllowRoot", L"false"));
        CPPUNIT_ASSERT(conf.Reset(L"AllowRoot"));
        std::wostringstream buf;
        CPPUNIT_ASSERT(conf.Print(buf));
        CPPUNIT_ASSERT(L"CWD = /var/opt/microsoft/scx/tmp/\nChRootPath = \nAllowRoot = false\n" == buf.str());
    }

    /**
        The CWD parameter to the reset command should be
        case insensitive.
     */   
    void ResetCWDIsCaseInsensitive()
    {
        std::vector<std::wstring> parameters;
        parameters.push_back(L"CWD");
        parameters.push_back(L"cwd");
        parameters.push_back(L"CwD");

        for (std::vector<std::wstring>::const_iterator iter = parameters.begin();
             iter != parameters.end();
             ++iter)
        {
            SCX_RunAsAdminProvider conf = GivenAdminProviderWithEmptyConfiguration();
            conf.Set(L"CWD", L"/foo/bar/");
            conf.Reset(*iter);
            SCXCore::RunAsConfigurator c = GivenAReparsedConfiguration(conf);
            CPPUNIT_ASSERT(c.GetCWD() != SCXFilePath(L"/foo/bar/"));
        }
    }

    /**
        The ChRootPath parameter to the reset command should be
        case insensitive.
     */   
    void ResetChRootPathIsCaseInsensitive()
    {
        std::vector<std::wstring> parameters;
        parameters.push_back(L"ChRootPath");
        parameters.push_back(L"chrootpath");
        parameters.push_back(L"CHROOTPATH");

        for (std::vector<std::wstring>::const_iterator iter = parameters.begin();
             iter != parameters.end();
             ++iter)
        {
            SCX_RunAsAdminProvider conf = GivenAdminProviderWithEmptyConfiguration();
            conf.Set(L"ChRootPath", L"/foo/bar/");
            conf.Reset(*iter);
            SCXCore::RunAsConfigurator c = GivenAReparsedConfiguration(conf);
            CPPUNIT_ASSERT(c.GetChRootPath() != SCXFilePath(L"/foo/bar/"));
        }
    }

    /**
        The AllowRoot parameter to the reset command should be
        case insensitive.
     */   
    void ResetAllowRootIsCaseInsensitive()
    {
        std::vector<std::wstring> parameters;
        parameters.push_back(L"AllowRoot");
        parameters.push_back(L"allowroot");
        parameters.push_back(L"ALLOWROOT");

        for (std::vector<std::wstring>::const_iterator iter = parameters.begin();
             iter != parameters.end();
             ++iter)
        {
            SCX_RunAsAdminProvider conf = GivenAdminProviderWithEmptyConfiguration();
            conf.Set(L"AllowRoot", L"false");
            conf.Reset(*iter);
            SCXCore::RunAsConfigurator c = GivenAReparsedConfiguration(conf);
            CPPUNIT_ASSERT(c.GetAllowRoot() == true);
        }
    }

    /**
        The CWD parameter (the name) to the set command should be
        case insensitive.
     */   
    void CWDIsCaseInsensitive()
    {
        std::vector<std::wstring> parameters;
        parameters.push_back(L"CWD");
        parameters.push_back(L"cwd");
        parameters.push_back(L"CwD");

        for (std::vector<std::wstring>::const_iterator iter = parameters.begin();
             iter != parameters.end();
             ++iter)
        {
            SCX_RunAsAdminProvider conf = GivenAdminProviderWithEmptyConfiguration();
            conf.Set(*iter, L"/foo/bar/");
            SCXCore::RunAsConfigurator c = GivenAReparsedConfiguration(conf);
            CPPUNIT_ASSERT(c.GetCWD() == SCXFilePath(L"/foo/bar/"));
        }
    }

    /**
        The value of the CWD setting should becase sensitive.
     */   
    void CWDValueIsCaseSensitive()
    {
        SCX_RunAsAdminProvider conf = GivenAdminProviderWithEmptyConfiguration();
        conf.Set(L"CWD", L"/FoO/bAr/");
        SCXCore::RunAsConfigurator c = GivenAReparsedConfiguration(conf);
        CPPUNIT_ASSERT(c.GetCWD() == SCXFilePath(L"/FoO/bAr/"));
    }

    /**
        The ChRootPath parameter (the name) to the set command should be
        case insensitive.
     */
    void ChRootPathIsCaseInsensitive()
    {
        std::vector<std::wstring> parameters;
        parameters.push_back(L"ChRootPath");
        parameters.push_back(L"chrootpath");
        parameters.push_back(L"CHROOTPATH");

        for (std::vector<std::wstring>::const_iterator iter = parameters.begin();
             iter != parameters.end();
             ++iter)
        {
            SCX_RunAsAdminProvider conf = GivenAdminProviderWithEmptyConfiguration();
            conf.Set(*iter, L"/foo/bar/");
            SCXCore::RunAsConfigurator c = GivenAReparsedConfiguration(conf);
            CPPUNIT_ASSERT(c.GetChRootPath() == SCXFilePath(L"/foo/bar/"));
        }
    }

    /**
        The value of the ChRootPath setting should becase sensitive.
     */   
    void ChRootPathValueIsCaseSensitive()
    {
        SCX_RunAsAdminProvider conf = GivenAdminProviderWithEmptyConfiguration();
        conf.Set(L"ChRootPath", L"/FoO/bAr/");
        SCXCore::RunAsConfigurator c = GivenAReparsedConfiguration(conf);
        CPPUNIT_ASSERT(c.GetChRootPath() == SCXFilePath(L"/FoO/bAr/"));
    }

    /**
        The AllowRoot parameter (the name) to the set command should be
        case insensitive.
     */   
    void AllowRootIsCaseInsensitive()
    {
        std::vector<std::wstring> parameters;
        parameters.push_back(L"AllowRoot");
        parameters.push_back(L"allowroot");
        parameters.push_back(L"ALLOWROOT");

        for (std::vector<std::wstring>::const_iterator iter = parameters.begin();
             iter != parameters.end();
             ++iter)
        {
            SCX_RunAsAdminProvider conf = GivenAdminProviderWithEmptyConfiguration();
            conf.Set(*iter, L"false");
            SCXCore::RunAsConfigurator c = GivenAReparsedConfiguration(conf);
            CPPUNIT_ASSERT(c.GetAllowRoot() == false);
        }
    }

    /**
        The value of the AllowRoot setting should becase insensitive.
     */   
    void AllowRootValueIsCaseInsensitive()
    {
        std::vector<std::wstring> parameters;
        parameters.push_back(L"false");
        parameters.push_back(L"FALSE");
        parameters.push_back(L"FaLsE");

        for (std::vector<std::wstring>::const_iterator iter = parameters.begin();
             iter != parameters.end();
             ++iter)
        {
            SCX_RunAsAdminProvider conf = GivenAdminProviderWithEmptyConfiguration();
            conf.Set(L"AllowRoot", *iter);
            SCXCore::RunAsConfigurator c = GivenAReparsedConfiguration(conf);
            CPPUNIT_ASSERT(c.GetAllowRoot() == false);
        }
    }
};

CPPUNIT_TEST_SUITE_REGISTRATION( RunAsAdminProviderTest ); 
