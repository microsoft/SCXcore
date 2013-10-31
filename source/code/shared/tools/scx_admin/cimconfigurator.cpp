/*----------------------------------------------------------------------------
  Copyright (c) Microsoft Corporation. All rights reserved. See license.txt for license information.
*/
/**
   \file

   \brief      scx cim configuration tool for SCX.  Configuration options in OMI.

   \date       8/27/2008

*/

#include <scxcorelib/scxcmn.h>
#include <scxcorelib/scxexception.h>
#include <scxcorelib/scxstream.h>
#include <scxcorelib/stringaid.h>

#include <iostream>

#include "cimconfigurator.h"

using namespace SCXCoreLib;
using namespace std;


// Note: Currently, OMI logging is not very configurable (command-line options
// only, nothing in .conf file).  This is currently a placeholder, but doesn't
// do much.
//
// For the time being, to get OMI-related logging (what little there is), we
// would need to stop the server and restart it from the command line,
// specifying --loglevel 4.


namespace SCXCoreLib
{
    /*----------------------------------------------------------------------------*/
    /**
       Constructor for SCX_CimConfigurator class
    */
    SCX_CimConfigurator::SCX_CimConfigurator()
    {
    }


    /*----------------------------------------------------------------------------*/
    /**
       Destructor for SCX_CimConfigurator class
    */
    SCX_CimConfigurator::~SCX_CimConfigurator()
    {
    }


    /*----------------------------------------------------------------------------*/
    /**
       Performs log rotation for the CIM server

       \returns           TRUE if supported (and suceeded), FALSE if unsupported

       \throws            Exception if supported, but error occurred
    */
    bool SCX_CimConfigurator::LogRotate()
    {
        // OpenPegasus doesn't support log rotation at this time
        // (to the best of my knowledge) without server restart

        return false;
    }


    /*----------------------------------------------------------------------------*/
    /**
       Prints the current state of the CIM server

       \param[out]  buf   Output of current log settings
       \returns           TRUE if supported (and suceeded), FALSE if unsupported

       \throws            Exception if supported, but error occurred
    */
    bool SCX_CimConfigurator::Print(std::wostringstream& buf) const
    {
        (void) buf;

        return false;
    }


    /*----------------------------------------------------------------------------*/
    /**
       Resets the logging level for the CIM server

       \returns           TRUE if supported (and suceeded), FALSE if unsupported

       \throws            Exception if supported, but error occurred
    */
    bool SCX_CimConfigurator::Reset()
    {
        return false;
    }


    /*----------------------------------------------------------------------------*/
    /**
       Sets the current logging configuration for CIM server

       \param       level   Current logging level (0->None, 1->Some, 2->All)
       \returns             TRUE if supported (and suceeded), FALSE if unsupported

       \throws              Exception if supported, but error occurred
    */
    bool SCX_CimConfigurator::Set(LogLevelEnum level)
    {
        (void) level;

        return false;
    }
}
