/*------------------------------------------------------------------------------
    Copyright (c) Microsoft Corporation.  All rights reserved.

 */
#include <stdio.h>

#ifdef WIN32

// Test code to make it compile on win32 

#define MOUNTED "C:\\AUTOEXEC.BAT"
typedef unsigned long fsblkcnt_t;
struct mntent 
{
    char *mnt_dir;
    char *mnt_fsname;
};
static bool first = true;
static struct mntent* getmntent(FILE*) { static struct mntent m = { "/", "/dev/hda" };  if (first) { first = false; return &m; } else { return NULL; } }
static FILE* setmntent(char *f, char *s) { first = true; return fopen(f,s); }
struct statvfs {
    unsigned long  f_frsize;   /* fragment size */
    fsblkcnt_t     f_bfree;    /* # free blocks */
    fsblkcnt_t     f_bavail;   /* # free blocks for non-root */
    fsblkcnt_t     f_blocks;   /* size of fs in f_frsize units */
};
static int statvfs(const char *path, struct statvfs *buf) { path; buf->f_bfree = 100; buf->f_bavail = 100; buf->f_blocks = 200; buf->f_frsize = 0; return 0; }

#else

#if defined(sun)
#include <sys/mntent.h>
#include <sys/mnttab.h>
#else
#include <mntent.h>
#endif

#include <sys/statvfs.h>

#endif

#include "diskdata.h"

#ifndef MIN
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#endif

// Make all numbers in kilobytes
const int BLOCKSIZE = 1024;

DiskData::DiskData(void)
{
}

DiskData::~DiskData(void)
{
}

// Get info on all monuted disks.
// Fills the vector with one entry per mountpoint
// Return 0 if OK, else 1
int DiskData::GetDiskInfo(vector<DiskInfo> &disks)
{
    // Open file with mounted disks
#if defined(sun)
    
    FILE *mounts = 0;
    mounts = ::fopen("/etc/mnttab", "r");
    if(mounts == 0)
    {
		//error, no mounts found
        return 1;
    }
#else
	FILE *mounts = setmntent(MOUNTED, "r");
#endif

    if(mounts)
    {

        // Loop over all mounts
#if defined(sun)
		struct mnttab entry;
		while (getmntent(mounts, &entry) == 0)
		{            
            string name = entry.mnt_special;
#else
		struct mntent *mount;
        while ((mount = getmntent(mounts)) != NULL)  
		{
			string name = mount->mnt_fsname;           
#endif        


            // Check if mount is a physical device
            if(name.substr(0, 5).compare("/dev/") == 0)
            {
                DiskInfo disk;
                struct statvfs buf;

#if defined(sun)
				disk.name = entry.mnt_mountp;
#else
				disk.name = mount->mnt_dir;
#endif
                // Remove /dev/ prefix for physical device name
                disk.physical = name.substr(5);

                // Get info about the mounted file system
#if defined(sun)
				if (statvfs(entry.mnt_mountp, &buf) == 0)
#else		
				if (statvfs(mount->mnt_dir, &buf) == 0)
#endif
                {                    
                    fsblkcnt_t blocks = buf.f_blocks;

                    if(buf.f_frsize > 0)
                    {
                        blocks = blocks * (buf.f_frsize / BLOCKSIZE) ;
                    }
                    disk.size_kb = (unsigned int)blocks;

                    blocks = buf.f_bavail;
                    if(buf.f_frsize > 0)
                    {
                        blocks = blocks * (buf.f_frsize / BLOCKSIZE) ;
                    }
                    disk.free_kb = (unsigned int)blocks;

                    if (buf.f_blocks == 0)
                    {
                        disk.usage = 0;
                    }
                    else
                    {
                        // Calculate disk usage percentage
                        disk.usage = MIN(100, (int)((double(buf.f_blocks - buf.f_bfree) / double(buf.f_blocks - buf.f_bfree + buf.f_bavail)) * 100  + (double)0.5));
                    }

                }

                disks.push_back(disk);

            }
        }

        fclose(mounts);

        // OK
        return 0;
    }   
    // Error, return non-zero value
    return 1;
}
