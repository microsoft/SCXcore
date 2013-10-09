/*----------------------------------------------------------------------------
    Copyright (c) Microsoft Corporation.  All rights reserved.
*/
/**
    \file      scxcimutils.h

    \brief     SCX CIM Utility Functions

    \date      2013-03-08 08:26:00
*/
/*----------------------------------------------------------------------------*/

#ifndef SCXCIMUTILS_H
#define SCXCIMUTILS_H

#include <scxcorelib/scxcmn.h>

#include <scxcorelib/scxtime.h>
#include <scxcorelib/stringaid.h>

#include <MI.h>

namespace CIMUtils
{
    bool ConvertToCIMDatetime( MI_Datetime& outDT, SCXCoreLib::SCXCalendarTime& inTime );
}


//
// The providers should have an exception handler wrapping all activity.  This
// helps guarantee that the agent won't crash if there's an unhandled exception.
// In the Pegasus model, this was done in the base class.  Since we don't have
// that luxury here, we'll have macros to make it easier.
//
// PEX = Provider Exception
//
// There's an assumption here that, since this is used in the OMI-generated code,
// "context" always exists for posting the result to.
//

#define SCX_PEX_BEGIN \
    try

#define SCX_PEX_END(module, log) \
    catch (const SCXCoreLib::SCXException& e) \
    { \
        SCX_LOGWARNING((log), std::wstring(module).append(L" - "). \
                       append(e.What()).append(L" - ").append(e.Where())); \
        context.Post(MI_RESULT_FAILED); \
    } \
    catch (std::exception &e) { \
        SCX_LOGERROR((log), std::wstring(module).append(L" - ").append(SCXCoreLib::DumpString(e))); \
        context.Post(MI_RESULT_FAILED); \
    } \
    catch (...) \
    { \
        SCX_LOGERROR((log), std::wstring(module).append(L" - Unknown exception")); \
        context.Post(MI_RESULT_FAILED); \
    }

//
// Have a little function to make it easy to break into a provider (as a debugging aid)
//
// The idea here is that we sleep indefinitely; if you break in with a debugger, then
// you can set f_break to true and then step through the code.
//

#define SCX_PROVIDER_WAIT_FOR_ATTACH         \
    {                                        \
        volatile bool f_break = false;       \
        while ( !f_break )                   \
            sleep(1);                        \
    }

#endif // !defined(SCXCIMUTILS_H)
