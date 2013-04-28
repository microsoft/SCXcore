// main.cpp : Defines the entry point for the application.
//
#include "platform.h"
#include "TempCopyFile.h"
#include "scxProcessGenerator.h"
#include "scxProcess.h"
#include "Usage.h"
#include <errno.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
#ifdef WIN32
    const char *parentName = "scxProcessGenerator.exe";
    const char *childName = "scxProcess.exe";
#else
    const char *parentName = "scxProcessGenerator";
    const char *childName = "scxProcess";
#endif
    int exitCode = 0;
    char *name;

    // Find out which name was used to start the process.
#if defined WIN32
    name = strrchr(argv[0], '\\');
#else
    name = strrchr(argv[0], '/');
#endif
    if (name == NULL)
    {
        name = argv[0];
    }
    else
    {
        name++;
    }

    // Instanciate the appropriate class based on the name.
    if (strcmp(name, parentName) == 0)
    {
        // Make a copy of this program with the child's name.
        TempCopyFile tcp(parentName, childName);
        tcp.Copy();

        scxProcessGenerator pg(childName, argc, argv);
        exitCode = pg.Run();

        if (exitCode != 0)
        {
            Usage();
            if (exitCode == -1)
            {
                // The user asked for usage, so reset exitCode to 0.
                exitCode = 0;
            }
        }
    }
    else if (strcmp(name, childName) == 0)
    {
        // This process does not request Usage.
        scxProcess pr(name, argc, argv);
        exitCode = pr.Run();
    }
    else
    {
        printf("This program was invoked by an invalid name.\n");
        printf("Rename the program to \"scxProcessGenerator\" and try again.\n");

        exitCode = EINVAL;
    }

    return exitCode;
}
