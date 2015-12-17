/*------------------------------------------------------------------------------
    Copyright (c) Microsoft Corporation. All rights reserved. See license.txt for license information.
*/
/**
    \file      startuplog.h

    \brief     Declaration of the "log once" functionality for startup logging

    \date      08-10-21 17:56:06
*/
/*----------------------------------------------------------------------------*/
#ifndef INITLOG_H
#define INITLOG_H

#include <scxcorelib/scxcmn.h>
#include <scxcorelib/scxfilepath.h>

namespace SCXCore {
    static const SCXCoreLib::SCXFilePath SCXConfFile(L"/etc/opt/microsoft/scx/conf/scxconfig.conf");
    void LogStartup(void);
}

#endif /* INITLOG_H */
/*----------------------------E-N-D---O-F---F-I-L-E---------------------------*/
