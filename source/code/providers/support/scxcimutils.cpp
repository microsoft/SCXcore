/*----------------------------------------------------------------------------
    Copyright (c) Microsoft Corporation.  All rights reserved.
*/
/**
    \file      scxcimutils.cpp

    \brief     SCX CIM Utility Functions

    \date      2013-03-08 08:26:00
*/
/*----------------------------------------------------------------------------*/

#include <scxcorelib/scxcmn.h>
#include <scxcimutils.h>

namespace CIMUtils
{
    bool ConvertToCIMDatetime( MI_Datetime& outDT, SCXCoreLib::SCXCalendarTime& inTime )
    {
        outDT.isTimestamp = true;

        outDT.u.timestamp.year = inTime.GetYear();
        outDT.u.timestamp.month = inTime.GetMonth();
        outDT.u.timestamp.day = inTime.GetDay();
        outDT.u.timestamp.hour = inTime.GetHour();
        outDT.u.timestamp.minute = inTime.GetMinute();
        outDT.u.timestamp.second = static_cast<MI_Uint32> (inTime.GetSecond());
        outDT.u.timestamp.microseconds = static_cast<MI_Uint32> ((inTime.GetSecond() - static_cast<double>(outDT.u.timestamp.second)) * 1000000.0);
        outDT.u.timestamp.utc = 0;

        return true;
    }
}
