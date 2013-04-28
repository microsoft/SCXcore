/*------------------------------------------------------------------------------
    Copyright (c) Microsoft Corporation.  All rights reserved.

 */
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>

#include <stdio.h>
#include <math.h>

#ifndef WIN32
#include <unistd.h> // for sysconf()
#endif

#include "memdata.h"

using namespace std;

#ifndef MIN
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#endif

#ifdef WIN32

const string meminfoFileName = "C:\\meminfo.txt";

#else

const string meminfoFileName = "/proc/meminfo";

#endif
#if defined(hpux)
#include <sys/pstat.h>
#endif
#if defined(sun)
#include <sys/swap.h>
#include <sys/sysinfo.h>
#endif

#if defined(aix)
#include <libperfstat.h>
#endif

MEMData::MEMData(void) : 
    MEMTotalMB(0), MEMUsedPercent(0), MEMUsedMB(0), MEMFreePercent(0), MEMFreeMB(0),
    MEMSwapTotalMB(0), MEMSwapUsedPercent(0), MEMSwapUsedMB(0), MEMSwapFreePercent(0), MEMSwapFreeMB(0)
{
}

MEMData::~MEMData(void)
{
}

#if defined(linux)
static void Tokenize(const string& str, vector<string>& tokens, const string& delimiters = " \n")
{
     // Skip delimiters at beginning.
    string::size_type lastPos = str.find_first_not_of(delimiters, 0);
     // Find first "non-delimiter".
    string::size_type pos = str.find_first_of(delimiters, lastPos);

    while (string::npos != pos || string::npos != lastPos)
    {
         // Found a token, add it to the vector.
        tokens.push_back(str.substr(lastPos, pos - lastPos));
         // Skip delimiters.  Note the "not_of"
        lastPos = str.find_first_not_of(delimiters, pos);
         // Find next "non-delimiter"
        pos = str.find_first_of(delimiters, lastPos);
    }
}

static int ToInt(string str)
{
    int tmp;
    stringstream ss(str);

    ss >> tmp;

    return tmp;
}
#endif

double BytesToMegaBytes(double bytes)
{
    return bytes / 1024.0 / 1024.0;
}

static unsigned int GetPercentage(unsigned int total, unsigned int val)
{
    int ans = 0;

    if ((total > 0))
    {
        ans = MIN(100, (int)(((double)val / (double)total) * 100  + (double)0.5));
    }

    return ans;
}

int MEMData::UpdateData(void)
{
#if defined(linux)
    ifstream meminfoFile;
    string line;
    int found = 0;

    meminfoFile.open(meminfoFileName.c_str());

    if (meminfoFile.fail())
    {
        return 1;
    }

/*
MemTotal:       516428 kB
MemFree:         52400 kB
SwapTotal:      779112 kB
SwapFree:       779028 kB
*/

    while (getline(meminfoFile, line) && found < 4)
    {
        vector<string> tokens;

        Tokenize(line, tokens);

        if (tokens[0].compare("MemTotal:") == 0)
        {
            MEMTotalMB = ToInt(tokens[1])/1024;
        }
        else if (tokens[0].compare("MemFree:") == 0)
        {
            MEMFreeMB = ToInt(tokens[1])/1024;
        }
        else if (tokens[0].compare("SwapTotal:") == 0)
        {
            MEMSwapTotalMB = ToInt(tokens[1])/1024;
        }
        else if (tokens[0].compare("SwapFree:") == 0)
        {
            MEMSwapFreeMB = ToInt(tokens[1])/1024;
        }
    }

    MEMUsedMB = MEMTotalMB - MEMFreeMB;
    MEMUsedPercent = GetPercentage(MEMTotalMB, MEMUsedMB);
    MEMFreePercent = 100-MEMUsedPercent;

    MEMSwapUsedMB = MEMSwapTotalMB - MEMSwapFreeMB;
    MEMSwapUsedPercent = GetPercentage(MEMSwapTotalMB, MEMSwapUsedMB);
    MEMSwapFreePercent = 100-MEMSwapUsedPercent;

#elif defined(sun)
        long pageSizeL = sysconf(_SC_PAGESIZE);
		//Calculating pageSize in Megabytes to fix Solaris SPARC memory calculation issue
		double pageSizeMB=BytesToMegaBytes(pageSizeL);

        long physPagesL = sysconf(_SC_PHYS_PAGES);        
        //MEMTotalMB = BytesToMegaBytes(physPagesL * pageSizeL); - Fix Sparc Memory calculation issue
		MEMTotalMB = physPagesL * pageSizeMB;

        long availPhysPagesL = sysconf(_SC_AVPHYS_PAGES);        
        //MEMFreeMB = BytesToMegaBytes(availPhysPagesL * pageSizeL); - Fix Sparc Memory calculation issue
		MEMFreeMB = availPhysPagesL * pageSizeMB;

        MEMUsedMB = MEMTotalMB - MEMFreeMB;
        MEMUsedPercent = GetPercentage(MEMTotalMB, MEMUsedMB);
        MEMFreePercent = 100-MEMUsedPercent;

        struct anoninfo swapinfo;

        MEMSwapTotalMB = BytesToMegaBytes(swapinfo.ani_max * pageSizeL);
        MEMSwapFreeMB = BytesToMegaBytes((swapinfo.ani_max - swapinfo.ani_resv) * pageSizeL);
        MEMSwapUsedMB = BytesToMegaBytes(swapinfo.ani_resv * pageSizeL);
        MEMSwapUsedPercent = GetPercentage(MEMSwapTotalMB, MEMSwapUsedMB);
        MEMSwapFreePercent = 100-MEMSwapUsedPercent;


#elif defined(hpux)
        /*
          HP kindly provides an easy way to read all kind of system and kernel data.
          This is collectively known as the pstat interface.
          It's supposed to be relatively upgrade friendly, even without recompilation.
          What is lacking however, is documentation. There is a whitepaper on pstat that
          you can look for at HP's site, which is very readable. But the exact semantics of
          each and every parameter is subject to experimentation and guesswork. I read
          somewhere that, to truly understand them you would need to have access to the
          kernel source. Needless to say, we don't. I've written a document called
          "Memory monitoring on HPUX.docx" that summarizes the needs and what's available.
        */
        struct pst_static psts;
        struct pst_dynamic pstd;
        struct pst_vminfo pstv;

        /* Get information the system static variables (guaranteed to remain constant until reboot) */
        if (pstat_getstatic(&psts, sizeof(psts), 1, 0) < 0) {
            return -1;
        }

        /* Get information about the system dynamic variables */
        if (pstat_getdynamic(&pstd, sizeof(pstd), 1, 0) != 1) {
            return -1;
        }

        /* Get information about the system virtual memory variables */
        if (pstat_getvminfo(&pstv, sizeof(pstv), 1, 0) != 1) {
            return -1;
        }

        // These are the system variables that we use together with ALL the documentation that HP provide
        // psts.page_size       - page size in bytes/page
        // psts.physical_memory - system physical memory in 4K pages
        // pstd.psd_rm          - total real memory
        // pstd.psd_free        - free memory pages
        // pstv.psv_swapspc_max - max pages of on-disk backing store
        // pstv.psv_swapspc_cnt - pages of on-disk backing store
        // pstv.psv_swapmem_max - max pages of in-memory backing store
        // pstv.psv_swapmem_cnt - pages of in-memory backing store
        // pstv.psv_swapmem_on  - in-memory backing store enabled

        // For usedMemory we use a measure of all real (physical) memory assigned to processes
        // For availableMemory we use the size of unassigned memory
        MEMTotalMB = BytesToMegaBytes(psts.physical_memory * (double)psts.page_size);
        MEMFreeMB = BytesToMegaBytes(pstd.psd_free * (double)psts.page_size);

        // totalSwap is the total size of all external swap devices plus swap memory, if enabled
        // availableSwap is the size of remaining device swap (with reserved memory subtracted)
        // plus remaining swap memory, if that was enabled in system configuration.
        // usedSwap is the difference between those. This is consistent with the 'total'
        // numbers when you do 'swapinfo -t'.
        MEMSwapTotalMB = BytesToMegaBytes(pstv.psv_swapspc_max + pstv.psv_swapmem_on * pstv.psv_swapmem_max * psts.page_size);
        MEMSwapFreeMB = BytesToMegaBytes(pstv.psv_swapspc_cnt + pstv.psv_swapmem_on * pstv.psv_swapmem_cnt * psts.page_size);

        MEMUsedMB = MEMTotalMB - MEMFreeMB;
        MEMUsedPercent = GetPercentage(MEMTotalMB, MEMUsedMB);
        MEMFreePercent = 100-MEMUsedPercent;

        MEMSwapUsedMB = MEMSwapTotalMB - MEMSwapFreeMB;
        MEMSwapUsedPercent = GetPercentage(MEMSwapTotalMB, MEMSwapUsedMB);
        MEMSwapFreePercent = 100-MEMSwapUsedPercent;

#elif defined(aix)

   int retcode;
   perfstat_memory_total_t mem;
   
   retcode = perfstat_memory_total(NULL, &mem, sizeof(perfstat_memory_total_t), 1);

   if (retcode != 1)
   {
	   return -1;
   }

   // All memory data given in 4KB pages

   MEMTotalMB = (mem.real_total / 1024) * 4;
   MEMFreeMB = (mem.real_free / 1024) * 4;
   MEMUsedMB = MEMTotalMB - MEMFreeMB;
   MEMUsedPercent = GetPercentage(MEMTotalMB, MEMUsedMB);
   MEMFreePercent = 100-MEMUsedPercent;

   MEMSwapTotalMB = (mem.pgsp_total / 1024) * 4;
   MEMSwapFreeMB = (mem.pgsp_free / 1024) * 4;
   MEMSwapUsedMB = MEMSwapTotalMB - MEMSwapFreeMB;
   MEMSwapUsedPercent = GetPercentage(MEMSwapTotalMB, MEMSwapUsedMB);
   MEMSwapFreePercent = 100-MEMSwapUsedPercent;

#else
#error "Not implemented for this platform."
#endif
    return 0;
}
