/*----------------------------------------------------------------------------
  Copyright (c) Microsoft Corporation. All rights reserved. See license.txt for license information.
*/
/**
   \file

   \brief      scx cim configuration tool for SCX.

   \date       8/27/2008

*/
#ifndef _CIM_CONFIGURATOR_H
#define _CIM_CONFIGURATOR_H

#include <scxcorelib/scxcmn.h>
#include "admin_api.h"

#include <iostream>

namespace SCXCoreLib
{
    /**
       Class for administration of Pegasus via scxadmin tool
     */
    class SCX_CimConfigurator : public SCX_AdminLogAPI {
    public:
        SCX_CimConfigurator();
        ~SCX_CimConfigurator();

        bool LogRotate();
        bool Print(std::wostringstream& buf) const;
        bool Reset();
        bool Set(LogLevelEnum level);
    };
}

#endif /* _CIM_CONFIGURATOR_H */
