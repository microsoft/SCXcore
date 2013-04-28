/*--------------------------------------------------------------------------------
    Copyright (c) Microsoft Corporation.  All rights reserved. 
    
*/
/**
    \file        

    \brief       Implements a configuration parser for the runas provider.
    
    \date        2008-08-27 15:51:24

*/
/*----------------------------------------------------------------------------*/
#ifndef SCXRUNASCONFIGURATOR_H
#define SCXRUNASCONFIGURATOR_H

#include <map>
#include <scxcorelib/scxfilepath.h>
#include <scxcorelib/scxhandle.h>
#include <scxcorelib/scxexception.h>

namespace SCXCore
{
    /*----------------------------------------------------------------------------*/
    /**
       Class for parsing generic configuration streams of the form:

       # Comment
       key1 = value1
       key2 = value2
    */
    class ConfigurationParser : public std::map<std::wstring, std::wstring>
    {
    public:
        /**
           Parses configuration.
         */
        virtual void Parse() = 0;
        /**
           Virtual destructor.
        */
        virtual ~ConfigurationParser() {};
    protected:
        virtual void ParseStream(std::wistream& configuration);
    };

    /*----------------------------------------------------------------------------*/
    /**
       Class for parsing files with generic configuration

    */
    class ConfigurationFileParser : public ConfigurationParser
    {
    public:
        ConfigurationFileParser(const SCXCoreLib::SCXFilePath& file);

        /**
           Parses the configuration file. If the file does not exist this is ignored.
        */
        void Parse();
    private:
        //! Path to file containing configuration.
        SCXCoreLib::SCXFilePath m_file;
    };

    /*----------------------------------------------------------------------------*/
    /**
       Class for writing generic configuration streams of the form:

       # Comment
       key1 = value1
       key2 = value2
    */
    class ConfigurationWriter : public std::map<std::wstring, std::wstring>
    {
    public:
        /**
           Writes configuration.
         */
        virtual void Write() = 0;
        /**
           Virtual destructor.
        */
        virtual ~ConfigurationWriter() {};
    protected:
        virtual void WriteToStream(std::wostream& configuration);
    };

    /*----------------------------------------------------------------------------*/
    /**
       Class for writing files with generic configuration

    */
    class ConfigurationFileWriter : public ConfigurationWriter
    {
    public:
        ConfigurationFileWriter(const SCXCoreLib::SCXFilePath& file);

        /**
           Writes the configuration file.
        */
        void Write();
    private:
        //! Path to configuration file.
        SCXCoreLib::SCXFilePath m_file;
    };

    /*----------------------------------------------------------------------------*/
    /**
       Class for parsing and writing configuration for the RunAs provider.
    */
    class RunAsConfigurator
    {
    public:
        RunAsConfigurator();
        RunAsConfigurator(SCXCoreLib::SCXHandle<ConfigurationParser> parser,
                          SCXCoreLib::SCXHandle<ConfigurationWriter> writer);
        const RunAsConfigurator& Parse();
        const RunAsConfigurator& Write();
        void Write(ConfigurationWriter& writer) const;

        bool GetAllowRoot() const;
        void SetAllowRoot(bool allowRoot);
        const SCXCoreLib::SCXFilePath& GetChRootPath() const;
        void SetChRootPath(const SCXCoreLib::SCXFilePath& path);
        void ResetChRootPath();
        const SCXCoreLib::SCXFilePath& GetCWD() const;
        void SetCWD(const SCXCoreLib::SCXFilePath& path);
        void ResetCWD();

    private:
        static const bool s_AllowRootDefault;
        static const SCXCoreLib::SCXFilePath s_ChRootPathDefault;
        static const SCXCoreLib::SCXFilePath s_CWDDefault;

        const std::wstring ResolveEnvVars(const std::wstring& input) const;

        //! Handles the actual parsing.
        SCXCoreLib::SCXHandle<ConfigurationParser> m_Parser;    
        //! Handles the actual writing of configuration.
        SCXCoreLib::SCXHandle<ConfigurationWriter> m_Writer;    
        //! Value of AllowRoot configuration.
        bool m_AllowRoot;
        //! Value of ChRootPath configuration.
        SCXCoreLib::SCXFilePath m_ChRootPath;
        //! Value of CWD configuration.
        SCXCoreLib::SCXFilePath m_CWD;
    };

    /*----------------------------------------------------------------------------*/
    /**
       Exeception for problems with RunAs configuration.
    */
    class SCXRunAsConfigurationException : public SCXCoreLib::SCXException {
    public: 
        /*----------------------------------------------------------------------------*/
        /**
           Ctor
           \param[in] reason Description of the error
           \param[in] l      Source code location object

        */
        SCXRunAsConfigurationException(std::wstring reason, const SCXCoreLib::SCXCodeLocation& l) : 
            SCXException(l), m_Reason(reason)
        { };

        std::wstring What() const {
            return L"Error parsing RunAs configuration: " + m_Reason;
        }

    protected:
        //! Description of error
        std::wstring   m_Reason;
    };        
} // SCXCore

#endif /* SCXRUNASCONFIGURATOR_H */
/*----------------------------E-N-D---O-F---F-I-L-E---------------------------*/
