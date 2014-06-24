/*----------------------------------------------------------------------------
  Copyright (c) Microsoft Corporation. All rights reserved. See license.txt for license information.
*/
/**
   \file

   \brief      Operations Manager pre-execution program (used by OMI)

   \date       06-20-2014


   \note       This code (originally developed by Microsoft and inserted into
               OpenPegasus) was lifted from Pegasus to put into OMI, then
               lifted from prior versions of OMI to put into this stand-alone
               program.
*/

#include <errno.h>
#include <iostream>
#include <pwd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

const static bool g_bDebug = false;


static int _createDir(
    std::string baseDir,
    uid_t uid,
    gid_t gid)
{
    struct passwd pwbuf;
    char buf[1024];
    struct passwd* pw = NULL;

#if defined(sun)
    if ((pw = getpwuid_r(uid, &pwbuf, buf, sizeof(buf))) == NULL)
#else
    if (getpwuid_r(uid, &pwbuf, buf, sizeof(buf), &pw) != 0 || !pw)
#endif
    {
        std::cerr << "Error executing getpwuid_r: errno=" << errno << std::endl;
        return errno;
    }

    // Try to create a new subdir from the user name
    std::string dirName = baseDir;
    dirName += pw->pw_name;

    if (mkdir(dirName.c_str(), 0700) == 0)
    {
        // Try to change ownership of the new subdir
        if (chown(dirName.c_str(), uid, gid) == 0)
        {
            if (g_bDebug)
            {
                std::cout << "Created directory: " << dirName.c_str() << std::endl;
            }
        }
        else
        {
            int saved_errno = errno;
            std::cerr << "Failed to change owner for directory " << dirName.c_str()
                      << ", errno=" << saved_errno
                      << " (" << strerror(saved_errno) << ")" << std::endl;
            return saved_errno;
        }
    }
    else
    {
        // If creation of dir failed, only log if the failure was not that it 
        // already existed
        if (errno != EEXIST)
        {
            int saved_errno = errno;
            std::cerr << "Failed to create directory " << dirName.c_str()
                      << ", errno=" << saved_errno
                      << " (" << strerror(saved_errno) << ")" << std::endl;
            return saved_errno;
        }
    }

    return 0;
}

/*----------------------------------------------------------------------------*/
/**
   main function.

   \param argc size of \a argv[]
   \param argv array of string pointers from the command line.
   \returns 0 on success, otherwise, 1 on error.

   Usage: omi_preexec full-path user-id group-id

   Specifically, we expect argc==4 with the following arguments set:

   argv[0]=<FULLPROGRAMPATH>
   argv[1]=<FULLPROGRAMPATH>
   argv[2]=<UID>
   argv[3]=<GID>

   Result Code
   \n -1  an exception has occured
   \n  0  success
   \n >1  an error occured while executing the command.

   Specifically, this program is executed by OMI whenever a non-privileged user
   is executing a provider (just the first time for that UID/GID combination).
   However, we will be called once for that combination UID/GID each time the
   OMI server is started.

   This program will create subdirectories necessary for proper OM execution
   (primarily for log/state files).

*/

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        std::cerr << "Invaid number of parameters: " << argc << std::endl;
        return 1;
    }

    int uid = atoi( argv[2] );
    int gid = atoi( argv[3] );

    // If spawning a non-root process, create subdir for scx log & persist 
    // with new uid as owner, if not already existing, so that we have 
    // somewhere that this subprocess have permission to write to.
    if (uid != 0)
    {
        int rc;

        if (0 != (rc = _createDir("/var/opt/microsoft/scx/lib/state/", uid, gid)))
        {
            return rc;
        }

        if (0 != (rc = _createDir("/var/opt/microsoft/scx/log/", uid, gid)))
        {
            return rc;
        }
    }

    return 0;
}
