#include "scxProcess.h"
#include "platform.h"
#include <errno.h>

int scxProcess::terminate;

scxProcess::scxProcess(char *flagFileName, int argc, char **argv)
{
    argCount = argc;
    argValues = argv;
    flagFile = flagFileName;
    terminate = 0;

    signal(SIGINT, SignalHandler);
}

scxProcess::~scxProcess(void)
{
}

int scxProcess::Run(void)
{
    while (FileExists(flagFile) && (terminate == 0))
    {
        scxSleep(1);
    }

    return 0;
}

int scxProcess::FileExists(const char *filename)
{
    int pfh = scxOpen(filename, O_RDONLY);

    if (pfh == -1)
    {
        if (errno == ENOENT)
        {
            // Return false only if the reason that the file
            // wasn't opened is because it doesn't exist.
            return 0;
        }
    }
    else
    {
        // If the file was opened, close it.
        scxClose(pfh);
    }

    return 1;
}

// The CTRL+C signal handler sets a flag causing the Run() method to exit.
void scxProcess::SignalHandler(int signal)
{
    terminate = signal;
}
