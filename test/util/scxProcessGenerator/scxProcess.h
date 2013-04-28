#if !defined(hpux)
#pragma once
#endif

#ifndef _INC_SCXPROCESS
#define _INC_SCXPROCESS

class scxProcess
{
private:
    int argCount;
    char **argValues;
    char *flagFile;
    static int terminate;      // Set by SignalHandler() to make the Run() method exit.

    int FileExists(const char *filename);
    static void SignalHandler(int signal);

public:
    scxProcess(char *flagFileName, int argc, char **argv);
    ~scxProcess(void);

    int Run(void);
};

#endif  /* _INC_SCXPROCESS */
