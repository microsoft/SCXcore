/*------------------------------------------------------------------------------
    Copyright (c) Microsoft Corporation.  All rights reserved.

 */
#pragma once

#include <vector>

using namespace std;

#include "diskinfo.h"

class DiskData
{
public:
    DiskData(void);
    virtual ~DiskData(void);

    int GetDiskInfo(vector<DiskInfo> &disks);
};
