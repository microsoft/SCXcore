/*----------------------------------------------------------------------------
  Copyright (c) Microsoft Corporation. All rights reserved. See license.txt for license information.
*/
/**
   \file

   \brief      SCX RunAs configuration tool for SCX.

   \date       2008-08-28 16:34:24

*/
#ifndef _RUNAS_CONFIGURATOR_H
#define _RUNAS_CONFIGURATOR_H

#include "scxrunasconfigurator.h"
#include "admin_api.h"


/*----------------------------------------------------------------------------*/
/**
   Class wrapping the configuration capabilities of the runas provider.

*/
class SCX_RunAsAdminProvider : public SCX_AdminProviderConfigAPI {
public:
    SCX_RunAsAdminProvider();
    SCX_RunAsAdminProvider( SCXCoreLib::SCXHandle<SCXCore::ConfigurationParser> parser,
                            SCXCoreLib::SCXHandle<SCXCore::ConfigurationWriter> writer,
                            const SCXCoreLib::SCXFilePath& sshdConfPath);
    ~SCX_RunAsAdminProvider();

    bool Print(std::wostringstream& buf) const;
    bool Reset( const std::wstring& name );
    bool Set(const std::wstring& name, const std::wstring& value);

private:
    bool GetSSHDConfPermitRootSetting(const SCXCoreLib::SCXFilePath& sshdConfPath) const;

    SCXCore::RunAsConfigurator m_Configurator; //!< Does the actual configuration.
    bool m_AllowRootDefault; //!< Value that AllowRoot should get after a call to reset.
};

#endif /* _RUNAS_CONFIGURATOR_H */
