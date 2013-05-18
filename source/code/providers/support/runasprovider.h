/*--------------------------------------------------------------------------------
 *        Copyright (c) Microsoft Corporation.  All rights reserved.
 *     
 *        */
 /**
      \file        runasprovider.h

      \brief       RunAs provider

      \date        05-15-03

*/
/*----------------------------------------------------------------------------*/

#ifndef RUNASPROVIDER_H
#define RUNASPROVIDER_H

#include <scxcorelib/scxcmn.h>
#include <scxcorelib/scxlog.h>

using namespace SCXCoreLib;

namespace SCXCore
{
    //
    // RunAs Provider
    //
    // The RunAs Provider is a separate implementation because we're strongly
    // considering separating the RunAs provider into it's own CIM class.
    //

    class RunAsProvider
    {
    public:
        RunAsProvider() : m_Configurator(NULL) { }
        ~RunAsProvider() { };

        void Load();
        void Unload();

        bool ExecuteCommand(const std::wstring &command, std::wstring &resultOut,
                            std::wstring &resultErr, int& returncode, unsigned timeout = 0,
                            const std::wstring &elevationtype = L"");

        bool ExecuteShellCommand(const std::wstring &command, std::wstring &resultOut,
                                 std::wstring &resultErr, int& returncode, unsigned timeout = 0,
                                 const std::wstring &elevationtype = L"");

        bool ExecuteScript(const std::wstring &script, const std::wstring &arguments,
                           std::wstring &resultOut, std::wstring &resultErr,
                           int& returncode, unsigned timeout = 0, const std::wstring &elevationtype = L"");
        
        SCXLogHandle& GetLogHandle() { return m_log; }
        
        void SetConfigurator(SCXCoreLib::SCXHandle<RunAsConfigurator> configurator)
        {
            m_Configurator = configurator;
        }

    private:
        void ParseConfiguration() { m_Configurator->Parse(); }

        std::wstring ConstructCommandWithElevation(const std::wstring &command, const std::wstring &elevationtype);
        std::wstring ConstructShellCommandWithElevation(const std::wstring &command, const std::wstring &elevationtype);

        //! Configurator.
        SCXCoreLib::SCXHandle<RunAsConfigurator> m_Configurator;

        SCXCoreLib::SCXLogHandle m_log;
        static int ms_loadCount;
    };

    extern RunAsProvider g_RunAsProvider;
}

#endif /* RUNASPROVIDER_H */

/*----------------------------E-N-D---O-F---F-I-L-E---------------------------*/

