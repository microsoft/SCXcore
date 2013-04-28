/*------------------------------------------------------------------------------
    Copyright (c) Microsoft Corporation.  All rights reserved.

 */
#pragma once
 
#include <string>

using namespace std;
 
class MEMData
{
public:
    MEMData(void);
    virtual ~MEMData(void);
 
    int UpdateData(void);

    unsigned int MEMTotalMB;
    unsigned int MEMUsedPercent;
    unsigned int MEMUsedMB;
    unsigned int MEMFreePercent;
    unsigned int MEMFreeMB;

    unsigned int MEMSwapTotalMB;
    unsigned int MEMSwapUsedPercent;
    unsigned int MEMSwapUsedMB;
    unsigned int MEMSwapFreePercent;
    unsigned int MEMSwapFreeMB;
};
