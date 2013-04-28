#if !defined(hpux)
#pragma once
#endif

#ifndef _INC_SCXPROCESSGENERATOR
#define _INC_SCXPROCESSGENERATOR

#include "platform.h"
#include "StringArrayGenerator.h"
#include <string.h>

class scxProcessGenerator
{
private:
    int argCount;
    char **argValues;
    static int terminate;       // Set by SignalHandler() to make the Run() method exit.
    int totalProcesses;         // The total number of process to keep running.
    int turnoverRate;           // The rate (in seconds) that a process is exited and replaced.
    int interval;               // The time (in seconds) to wait before creating the next process.
    int argMode;                // Child argument strings are; 1 for random arg strings, 0 for sequencial arg strings.
    StringArrayGenerator *sag;
    int stringCount;
    int minStrLength;
    int maxStrLength;
    int minArgs;
    int maxArgs;
    char **argList;
    const char *childName;
    pid_t *childHandles;
    int sequenceNumber;
    char sequenceNumberString[35];
    int isRunning;

    void BuildArgumentList(void);
    void CreateChild(int idx);
    int IsAllNumeric(char *str);
    int Parse(void);
    int RandomNumberRange(int min, int max);
    static void SignalHandler(int signal);
    void TerminateChild(int idx);

public:
    scxProcessGenerator(const char *processName, int argc, char **argv);
    ~scxProcessGenerator(void);

    int Run(void);
};

#endif  /* _INC_SCXPROCESSGENERATOR */
