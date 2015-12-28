/*--------------------------------------------------------------------------------
  Copyright (c) Microsoft Corporation.  All rights reserved.

*/
/**
   \file

   \brief       Test code for SCX Core Provider

   \date        2015-12-23

   Test support code for SCX Core Provider

*/
/*----------------------------------------------------------------------------*/

#ifndef TESTUTILITIES_H
#define TESTUTILITIES_H

#include <scxcorelib/scxcmn.h>
#include <string>

namespace SCXCore
{
    std::wstring GetActualDistributionName(std::wstring errMsg);
}

#endif // !defined(TESTUTILITIES_H)
