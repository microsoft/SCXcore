/*----------------------------------------------------------------------------
  Copyright (c) Microsoft Corporation.  All rights reserved.
*/
/**
   \file

   \brief      runas configuration tool for SCX.

   \date       2008-08-28 17:13:43

*/

#include "runasadminprovider.h"
#include <scxcorelib/scxstream.h>
#include <scxcorelib/scxfile.h>
#include <scxcorelib/stringaid.h>

/*----------------------------------------------------------------------------*/
/**
   Default Constructor for SCX_RunAsAdminProvider class
*/
SCX_RunAsAdminProvider::SCX_RunAsAdminProvider() :
    m_Configurator( 
        SCXCoreLib::SCXHandle<SCXCore::ConfigurationParser>(new SCXCore::ConfigurationFileParser(L"/etc/opt/microsoft/scx/conf/scxrunas.conf")),
        SCXCoreLib::SCXHandle<SCXCore::ConfigurationWriter>(new SCXCore::ConfigurationFileWriter(L"/etc/opt/microsoft/scx/conf/scxrunas.conf"))),
    m_AllowRootDefault(true)
{
    m_Configurator.Parse();

#if defined(hpux)
    m_AllowRootDefault = GetSSHDConfPermitRootSetting(L"/opt/ssh/etc/sshd_config");
#elif defined(macos)
    m_AllowRootDefault = GetSSHDConfPermitRootSetting(L"/etc/sshd_config");
#elif defined(sun)
# if (PF_MAJOR == 5) && (PF_MINOR == 8)
    m_AllowRootDefault = GetSSHDConfPermitRootSetting(L"/usr/local/etc/sshd_config");
# else
    m_AllowRootDefault = GetSSHDConfPermitRootSetting(L"/etc/ssh/sshd_config");
# endif
#else
    m_AllowRootDefault = GetSSHDConfPermitRootSetting(L"/etc/ssh/sshd_config");
#endif
}

/*----------------------------------------------------------------------------*/
/**
   Constructor for SCX_RunAsAdminProvider class
*/
SCX_RunAsAdminProvider::SCX_RunAsAdminProvider( SCXCoreLib::SCXHandle<SCXCore::ConfigurationParser> parser,
                                                SCXCoreLib::SCXHandle<SCXCore::ConfigurationWriter> writer,
                                                const SCXCoreLib::SCXFilePath& sshdConfPath) :
    m_Configurator( parser, writer ),
    m_AllowRootDefault(true)
{
    m_Configurator.Parse();
    m_AllowRootDefault = GetSSHDConfPermitRootSetting(sshdConfPath);
}

/*----------------------------------------------------------------------------*/
/**
   Destructor for SCX_RunAsConfigurator class
*/
SCX_RunAsAdminProvider::~SCX_RunAsAdminProvider()
{
}

/*----------------------------------------------------------------------------*/
/**
    Prints current log configuration of the component into provided stream
    \param[in] buf       stream for configuration writing
    \returns "true" if success, "false" if not supported
    throws "SCXAdminException" exception if failed
*/
bool SCX_RunAsAdminProvider::Print(std::wostringstream& buf) const
{
    buf << L"CWD = " << m_Configurator.GetCWD().Get() << std::endl
        << L"ChRootPath = " << m_Configurator.GetChRootPath().Get() << std::endl
        << L"AllowRoot = " << (m_Configurator.GetAllowRoot() == true ? L"true" : L"false") << std::endl;
       
    return true;
}


/*----------------------------------------------------------------------------*/
/**
    Resets configuration of the component to the default level (installation-time)
    \param[in] name       property name for resetting
    \returns "true" if success, "false" if not supported
    throws "SCXAdminException" exception if failed
*/
bool SCX_RunAsAdminProvider::Reset( const std::wstring& name )
{
    std::wstring lowerName = SCXCoreLib::StrToLower(name);
    if (L"allowroot" == lowerName)
    {
        m_Configurator.SetAllowRoot(m_AllowRootDefault);
        m_Configurator.Write();
        return true;
    }
    else if (L"chrootpath" == lowerName)
    {
        m_Configurator.ResetChRootPath();
        m_Configurator.Write();
        return true;
    }
    else if (L"cwd" == lowerName)
    {
        m_Configurator.ResetCWD();
        m_Configurator.Write();
        return true;
    }
    else if (L"" == name)
    {
        m_Configurator.SetAllowRoot(m_AllowRootDefault);
        m_Configurator.ResetChRootPath();
        m_Configurator.ResetCWD();
        m_Configurator.Write();
        return true;
    }

    throw SCXAdminException(L"unknown property name " + name, SCXSRCLOCATION);
}


/*----------------------------------------------------------------------------*/
/**
    Changes configuration of the component with provided name/value pair
    \param[in] name       property name for setting
    \param[in] value      new value
    \returns "true" if success, "false" if not supported
    throws "SCXAdminException" exception if failed
*/
bool SCX_RunAsAdminProvider::Set(const std::wstring& name, const std::wstring& value)
{
    std::wstring lowerName = SCXCoreLib::StrToLower(name);
    std::wstring lowerValue = SCXCoreLib::StrToLower(value);
    if (L"allowroot" == lowerName)
    {
        if (L"true" == lowerValue ||
            L"false" == lowerValue)
        {           
            m_Configurator.SetAllowRoot(L"true" == lowerValue);
            m_Configurator.Write();
            return true;
        }
    }
    else if (L"chrootpath" == lowerName)
    {
        m_Configurator.SetChRootPath(value);
        m_Configurator.Write();
        return true;
    }
    else if (L"cwd" == lowerName)
    {
        m_Configurator.SetCWD(value);
        m_Configurator.Write();
        return true;
    }
    throw SCXAdminException(L"unknown property name " + name + L" or invalid value " + value, SCXSRCLOCATION);
}


/*----------------------------------------------------------------------------*/
/**
    Parses the supplied sshd_config file for the setting of "PermitRoot" and
    returns the value.
    \param[in] sshdConfPath       path to sshd_config file
    \returns false if PermitRoot is set to no.
*/
bool SCX_RunAsAdminProvider::GetSSHDConfPermitRootSetting(const SCXCoreLib::SCXFilePath& sshdConfPath) const
{
    SCXCoreLib::SCXStream::NLFs nlfs;
    std::vector<std::wstring> lines;
    SCXCoreLib::SCXFile::ReadAllLines(sshdConfPath, lines, nlfs);

    const std::wstring delimiters(L" \t");
    for (std::vector<std::wstring>::const_iterator iter = lines.begin();
         iter != lines.end();
         ++iter)
    {
        std::vector<std::wstring> tokens;
        SCXCoreLib::StrTokenize(*iter, tokens, delimiters);
        if (tokens.size() == 2 && tokens[0] == L"PermitRootLogin" && tokens[1] == L"no")
        {
            return false;
        }
    }
    return true;
}
