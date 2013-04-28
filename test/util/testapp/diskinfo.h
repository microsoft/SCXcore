/*------------------------------------------------------------------------------
    Copyright (c) Microsoft Corporation.  All rights reserved.

 */
#pragma once

#include <string>

using namespace std;

class DiskInfo
{
public:
    string name;
    string physical;
    unsigned int free_kb;
    unsigned int size_kb;
    unsigned int usage;
};
