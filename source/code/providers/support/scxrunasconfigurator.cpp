/*--------------------------------------------------------------------------------
    Copyright (c) Microsoft Corporation.  All rights reserved. 
    
*/
/**
    \file        

    \brief       Implementation of the runas configurator.
    
    \date        2008-08-27 15:57:34

*/
/*----------------------------------------------------------------------------*/

#include <scxcorelib/scxcmn.h>
#include <scxcorelib/scxlog.h>
#include <scxcorelib/scxstream.h>
#include <scxcorelib/stringaid.h>
#include <scxcorelib/scxfile.h>
#include <vector>

#include "scxrunasconfigurator.h"

using namespace SCXCoreLib;

namespace SCXCore
{
    /*----------------------------------------------------------------------------*/
    /**
       Parses a stream of the form 

       # Comment
       key1 = value1
       key2 = value2

       \param[in] configuration Stream with configuration data. Typically as
                  read from a configuration file.
    */
    void ConfigurationParser::ParseStream(std::wistream& configuration)
    {
        SCXCoreLib::SCXLogHandle log = SCXLogHandleFactory::GetLogHandle(L"scx.core.providers.runasprovider.configparser");

        std::vector<std::wstring> lines;
        SCXStream::NLFs nlfs;
        SCXStream::ReadAllLines(configuration, lines, nlfs);
        SCX_LOGTRACE(log, StrAppend(L"Number of lines in configuration: ", lines.size()));

        for (std::vector<std::wstring>::const_iterator it = lines.begin();
             it != lines.end(); it++)
        {
            std::wstring line = StrTrim(*it);
            SCX_LOGTRACE(log, StrAppend(L"Parsing line: ", line));
            if (line.length() == 0 ||
                line.substr(0,1) == L"#") //comment
            {
                continue;
            }
            std::vector<std::wstring> parts;
            StrTokenize(line, parts, L"=");
            if (parts.size() == 2)
            {
                iterator iter = lower_bound(parts[0]);
                if ((end() != iter) && !(key_comp()(parts[0], iter->first)))
                {
                    iter->second = parts[1];
                }
                else
                {
                    insert(iter, std::pair<const std::wstring, std::wstring>(parts[0], parts[1]));
                }
            }
        }
    }

    /*----------------------------------------------------------------------------*/
    /**
       Constructor for the configuration file parser.
    */
    ConfigurationFileParser::ConfigurationFileParser(const SCXCoreLib::SCXFilePath& file) :
        m_file(file)
    {
    }

    /*----------------------------------------------------------------------------*/
    /**
       Parses the configuration file. If the file does not exist this is ignored.
    */
    void ConfigurationFileParser::Parse()
    {
        SCXCoreLib::SCXLogHandle log = SCXLogHandleFactory::GetLogHandle(L"scx.core.providers.runasprovider.configparser");

        try
        {
            ParseStream(*SCXFile::OpenWFstream(m_file, std::ios_base::in));
        }
        catch (SCXException& e)
        {
            SCX_LOGWARNING(log, StrAppend(L"Failed to read file: ", m_file.Get()));
            SCX_LOGWARNING(log, StrAppend(L"Reason for failure: ", e.What()));
        }
    }

    /*----------------------------------------------------------------------------*/
    /**
       Writes configuration of the form 

       # Comment
       key1 = value1
       key2 = value2

       to a stream.

       \param[out] configuration Stream to write configuration data to.
    */
    void ConfigurationWriter::WriteToStream(std::wostream& configuration)
    {
        SCXCoreLib::SCXLogHandle log = SCXLogHandleFactory::GetLogHandle(L"scx.core.providers.runasprovider.configwriter");

        for (const_iterator iter = begin(); iter != end(); ++iter)
        {
            SCX_LOGTRACE(log, StrAppend(L"Writing line: ", iter->first + L" = " + iter->second));
            configuration << iter->first << L" = " << iter->second << std::endl;
        }
    }

    /*----------------------------------------------------------------------------*/
    /**
       Constructor for the configuration file writer.
    */
    ConfigurationFileWriter::ConfigurationFileWriter(const SCXCoreLib::SCXFilePath& file) :
        m_file(file)
    {
    }

    /*----------------------------------------------------------------------------*/
    /**
       Writes the configuration file.
    */
    void ConfigurationFileWriter::Write()
    {
        SCXCoreLib::SCXLogHandle log = SCXLogHandleFactory::GetLogHandle(L"scx.core.providers.runasprovider.configparser");

        WriteToStream(*SCXFile::OpenWFstream(m_file, std::ios_base::out));
    }

    /** Default value for allow root. */
    const bool RunAsConfigurator::s_AllowRootDefault(true);
    /** Default value for chrootpath. */
    const SCXCoreLib::SCXFilePath RunAsConfigurator::s_ChRootPathDefault(L"");
    /** Default value for CWD. */
    const SCXCoreLib::SCXFilePath RunAsConfigurator::s_CWDDefault(L"/var/opt/microsoft/scx/tmp/");

    /*----------------------------------------------------------------------------*/
    /**
       Constructor for the run as configurator.
    */
    RunAsConfigurator::RunAsConfigurator() :
        m_Parser(new ConfigurationFileParser(L"/etc/opt/microsoft/scx/conf/scxrunas.conf")),
        m_Writer(new ConfigurationFileWriter(L"/etc/opt/microsoft/scx/conf/scxrunas.conf")),
        m_AllowRoot(s_AllowRootDefault),
        m_ChRootPath(s_ChRootPathDefault),
        m_CWD(s_CWDDefault)
    {
    }

    /*----------------------------------------------------------------------------*/
    /**
       Constructor for the run as configurator.
    */
    RunAsConfigurator::RunAsConfigurator(SCXCoreLib::SCXHandle<ConfigurationParser> parser,
                                         SCXCoreLib::SCXHandle<ConfigurationWriter> writer) :
        m_Parser(parser),
        m_Writer(writer),
        m_AllowRoot(s_AllowRootDefault),
        m_ChRootPath(s_ChRootPathDefault),
        m_CWD(s_CWDDefault)
    {
    }

    /*----------------------------------------------------------------------------*/
    /**
       Parse configuration stream.

       \returns this
    */
    const RunAsConfigurator& RunAsConfigurator::Parse()
    {
        m_Parser->Parse();

        SCXCoreLib::SCXLogHandle log = SCXLogHandleFactory::GetLogHandle(L"scx.core.providers.runasprovider.configurator");

        ConfigurationParser::const_iterator allowRoot = m_Parser->find(L"AllowRoot");
        if (allowRoot != m_Parser->end() && (
                allowRoot->second == L"false" ||
                allowRoot->second == L"no" ||
                allowRoot->second == L"0"))
        {
            m_AllowRoot = false;
        }

        ConfigurationParser::const_iterator chRootPath = m_Parser->find(L"ChRootPath");
        if (chRootPath != m_Parser->end())
        {
            m_ChRootPath = ResolveEnvVars(chRootPath->second);
            if (L"" == m_ChRootPath)
            {
                SCX_LOGINFO(log, L"ChRootPath has been resolved to empty string");
            }
        }

        ConfigurationParser::const_iterator cwd = m_Parser->find(L"CWD");
        if (cwd != m_Parser->end())
        {
            m_CWD = ResolveEnvVars(cwd->second);
            if (L"" == m_CWD)
            {
                SCX_LOGINFO(log, L"CWD has been resolved to empty string");
            }
        }

        return *this;
    }

    /*----------------------------------------------------------------------------*/
    /**
       Write configuration stream.

       \returns this
    */
    const RunAsConfigurator& RunAsConfigurator::Write()
    {
        Write(*m_Writer);
        return *this;
    }

    /*----------------------------------------------------------------------------*/
    /**
       Write configuration stream using supplied writer.

       \param writer ConfigurationWriter to use for writing.
    */
    void RunAsConfigurator::Write(ConfigurationWriter& writer) const
    {
        writer.clear();
        
        if (m_AllowRoot != s_AllowRootDefault)
        {
            writer.insert(std::pair<const std::wstring, std::wstring>(L"AllowRoot",
                                                                      m_AllowRoot ? L"true" : L"false"));
        }
        if (m_ChRootPath != s_ChRootPathDefault)
        {
            writer.insert(std::pair<const std::wstring, std::wstring>(L"ChRootPath", m_ChRootPath.Get()));
        }
        if (m_CWD != s_CWDDefault)
        {
            writer.insert(std::pair<const std::wstring, std::wstring>(L"CWD", m_CWD.Get()));
        }

        writer.Write();
    }

    /*----------------------------------------------------------------------------*/
    /**
       Return if configuration says that root access is allowed.

       \returns Value of AllowRoot.
    */
    bool RunAsConfigurator::GetAllowRoot() const
    {
        return m_AllowRoot;
    }

    /*----------------------------------------------------------------------------*/
    /**
       Set configuration if root access is allowed.

       \param[in] allowRoot Value of AllowRoot.
    */
    void RunAsConfigurator::SetAllowRoot(bool allowRoot)
    {
        m_AllowRoot = allowRoot;
    }

    /*----------------------------------------------------------------------------*/
    /**
       Get the path configured as chroot path. Empty string means no chroot.

       \returns Value of ChRootPath.
    */
    const SCXCoreLib::SCXFilePath& RunAsConfigurator::GetChRootPath() const
    {
        return m_ChRootPath;
    }

    /*----------------------------------------------------------------------------*/
    /**
       Set the path configured as chroot path. Empty string means no chroot.

       \param[in] path Value of ChRootPath.
    */
    void RunAsConfigurator::SetChRootPath(const SCXCoreLib::SCXFilePath& path)
    {
        m_ChRootPath = path;
    }

    /*----------------------------------------------------------------------------*/
    /**
       Reset the path configured as chroot path to default.

    */
    void RunAsConfigurator::ResetChRootPath()
    {
        m_ChRootPath = s_ChRootPathDefault;
    }

    /*----------------------------------------------------------------------------*/
    /**
       Get the path configured as CWD.

       \returns Value of CWD.
    */
    const SCXCoreLib::SCXFilePath& RunAsConfigurator::GetCWD() const
    {
        return m_CWD;
    }

    /*----------------------------------------------------------------------------*/
    /**
       Set the path configured as CWD.

       \param[in] path Value of CWD.
    */
    void RunAsConfigurator::SetCWD(const SCXCoreLib::SCXFilePath& path)
    {
        m_CWD = path;
    }

    /*----------------------------------------------------------------------------*/
    /**
       Reset the path configured as CWD to default.

    */
    void RunAsConfigurator::ResetCWD()
    {
        m_CWD = s_CWDDefault;
    }

    /*----------------------------------------------------------------------------*/
    /**
       Recursively translate all environment variables with their actual values.

       \param[in] input String to remove environment variables from.
       \returns String where all environment variables have been translated.
       \throws SCXRunAsConfigurationException if a loop in environmen variables is suspected.
    */
    const std::wstring RunAsConfigurator::ResolveEnvVars(const std::wstring& input) const
    {
        static const std::wstring allowedVarNameChars(L"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz_");
        
        // We need to know when we run into an infinite loop.
        int numberOfVariableSubstitutionsAllowed = 100;
        std::wstring output(input);
        for (std::wstring::size_type varstart = output.find(L'$');
             varstart != std::wstring::npos;
             varstart = output.find(L'$', varstart))
        {
            std::wstring variableName;
            std::wstring::size_type varend;
            if (L'{' == output[varstart + 1])
            {
                varend = output.find(L'}', varstart + 2);
                if (varend == std::wstring::npos)
                {
                    throw SCXRunAsConfigurationException(
                        std::wstring(L"Configuration value ")
                        .append(input)
                        .append(L" seems to be malformed. '{' and '}' are not matching."), SCXSRCLOCATION);
                }
                variableName = output.substr(varstart + 2, varend - 2 - varstart);
            }
            else
            {
                varend = output.find_first_not_of(allowedVarNameChars, varstart + 1);
                if (varend == std::wstring::npos)
                {
                    varend = output.size();
                }
                --varend; // Index of the last character in the variable name.

                variableName = output.substr(varstart + 1, varend - varstart);
            }

            const char *variableValuePtr = ::getenv(StrToMultibyte(variableName).c_str());
            if (0 == variableValuePtr)
            {
                output.erase(varstart, varend - varstart + 1);
            }
            else
            {
                output.replace(varstart, varend - varstart + 1, StrFromMultibyte(variableValuePtr));
            }

            --numberOfVariableSubstitutionsAllowed;
            if (0 == numberOfVariableSubstitutionsAllowed)
            {
                throw SCXRunAsConfigurationException(
                    std::wstring(L"Configuration value ")
                    .append(input)
                    .append(L" seems to contain environment variables that form an infinite recursion loop."), SCXSRCLOCATION);
            }
        }
        return output;
    }

} // SCXCoreLib
/*----------------------------E-N-D---O-F---F-I-L-E---------------------------*/
