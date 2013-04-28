#include "scxProcessGenerator.h"
#include "platform.h"
#include <errno.h>
#include <string.h>
#include <stdio.h>

int scxProcessGenerator::terminate;

scxProcessGenerator::scxProcessGenerator(const char *processName, int argc, char **argv)
{
    argCount = argc;            // From command line.
    argValues = argv;
    totalProcesses = 0;         // Required parameter value.
    turnoverRate = 1;           // Parameters with default values.
    interval = 0;               // Wait 'interval' seconds before creating the next process.
    argMode = 1;
    // Note: We want about 500 characters (give or take a few) in the child's command line parameters.
    stringCount = 25;           // Fixed values.
    minStrLength = 8;
    maxStrLength = 25;
    minArgs = 10;               // The minimum number of arguments in argv.  Must be >= 2.
    maxArgs = stringCount + 2;  // Add 1 each for the filename and sequence number.
    childName = processName;    // Initialization.
    isRunning = 0;
    sequenceNumber = 0;
    terminate = 0;

    // Allocation of objects.
    argList = new char*[maxArgs + 1];   // Add 1 for the terminating NULL pointer.
    sag = new StringArrayGenerator(stringCount, minStrLength, maxStrLength, argMode);

    // Catch the signal.
    signal(SIGINT, SignalHandler);
}

scxProcessGenerator::~scxProcessGenerator(void)
{
    // Make all child processes exit.
    for (int i = 0; i < totalProcesses; i++)
    {
        TerminateChild(i);
    }

    delete[] childHandles;
    delete[] argList;
}

// Generate random numbers in the half-closed interval [range_min, range_max].
// In other words, (min <= random_number < max).
int scxProcessGenerator::RandomNumberRange(int min, int max)
{
    int u = (int)((double)rand() / (RAND_MAX + 1) * (max - min) + min);
    return u;
}

void scxProcessGenerator::BuildArgumentList()
{
    int numberOfArgs;
    char **pArgStrings;

    pArgStrings = sag->BuildStringArray();
    scxItoa(++sequenceNumber, sequenceNumberString, 35, 10);

    // The first 2 arguments are always the process name and a sequence number.
    argList[0] = (char *)childName;
    argList[1] = sequenceNumberString;

    // Figure out how many arguments we will use.
    if (minArgs < 2)
    {
        minArgs = 2;    // We must have the program name and sequence number.
    }
    numberOfArgs = RandomNumberRange(minArgs, maxArgs);

    // Assign the argument strings to the array elements.
    for (int i = 2; i < numberOfArgs; i++)
    {
        argList[i] = pArgStrings[i - 2];
    }

    // There is always at least 1 NULL argument.
    for (int i = numberOfArgs; i <= maxArgs; i++)
    {
        argList[i] = NULL;
    }
}


// Creates a child process with a random number of command
// line arguments and returns its handle to the caller.
void scxProcessGenerator::CreateChild(int idx)
{
    BuildArgumentList();

    pid_t pid = scxSpawn(argList[0], argList);

    if (pid == -1)
    {
        perror("*****  Failure returned by 'scxSpawn'");
        childHandles[idx] = 0;
    }
    else
    {
        // Report the PID and command line.
        printf("Create(%d)", pid);
        for (int i = 0; i < maxArgs; i++)
        {
            if (argList[i] != NULL)
            {
                printf(" %s", argList[i]);
            }
        }
        printf("\n\n");

        childHandles[idx] = pid;
    }
}

// Verifies that all characters in the string are digits.
int scxProcessGenerator::IsAllNumeric(char *str)
{
    for (int i = 0; i < (int)strlen(str); i++)
    {
        if (isdigit(str[i]) == 0)
        {
            return 0;
        }
    }

    return 1;
}

// Parses the arguments passed to the constructor and breaks out
// specific argument values used for the test.
int scxProcessGenerator::Parse(void)
{
    for (int i = 1; i < argCount; i++)
    {
        if (strncmp(argValues[i], "-interval", 2) == 0)
        {
            i++;
            if (IsAllNumeric(argValues[i]))
            {
                interval = atoi(argValues[i]);
                if (interval < 0)
                {
                    interval = 0;
                }
                continue;
            }

            printf("The interval must be an integer value.\n");
            printf("  Found: %s\n", argValues[i]);

            return EINVAL;
        }
        else if (strncmp(argValues[i], "-processes", 2) == 0)
        {
            i++;
            if (IsAllNumeric(argValues[i]))
            {
                totalProcesses = atoi(argValues[i]);
                if (totalProcesses >= 1)
                {
                    continue;
                }
            }

            printf("The number of processes must be an unsigned integer greater than 0.\n");
            printf("  Found: %s\n", argValues[i]);

            return EINVAL;
        }
        else if (strncmp(argValues[i], "-random", 2) == 0)
        {
            argMode = 1;
        }
        else if (strncmp(argValues[i], "-sequencial", 2) == 0)
        {
            argMode = 0;
        }
        else if (strncmp(argValues[i], "-turnover", 2) == 0)
        {
            i++;
            if (IsAllNumeric(argValues[i]))
            {
                turnoverRate = atoi(argValues[i]);
                if (turnoverRate >= 1)
                {
                    continue;
                }
            }

            printf("The turn-over rate must be an unsigned integer greater than 0.\n");
            printf("  Found: %s\n", argValues[i]);

            return EINVAL;
        }
        else if (strncmp(argValues[i], "-help", 2) == 0)
        {
            return 1;
        }
        else
        {
            //               1         2         3         4         6         6         7
            //      123456789012345678901234567890123456789012345678901234567890123456789012
            printf("Found Unknown Argument: %s\n", argValues[i]);

            return EINVAL;
        }
    }

    if (totalProcesses <= 0)
    {
            printf("The -p[rocesses] parameter is required, but was not specified.\n");

            return EINVAL;
    }

    return 0;
}

// Step 1.  Start the first 'totalProcesses' child process.
// Step 2.  Every 'turnoverRate' seconds, exit the oldest child and start a new one.
int scxProcessGenerator::Run(void)
{
    // This avoids threading problems if someone tries to call the Run() method
    // while it is already running in another thread.
    // BUG - This is a half hearted attempt and is subject to race conditions.
    if (isRunning++)
    {
        printf("The Run() method can only be called once per object instance.\n");
        return 0;
    }

    int returnCode = Parse();
    if (returnCode != 0)
    {
        return returnCode;
    }

    // Can't do this before Parse() is called, because totalProcesses is
    // set by the Parse() method.  Until then, totalProcesses is 0.
    childHandles = new pid_t[totalProcesses];

    if (terminate == 0)
    {
        for (int i = 0; i < totalProcesses; i++)
        {
            CreateChild(i);
            if (interval > 0)
            {
                scxSleep(interval);
            }
        }

        while (terminate == 0)
        {
            for (int i = 0; (i < totalProcesses) && (terminate == 0); i++)
            {
                scxSleep(turnoverRate);

                TerminateChild(i);          // Make this child process exit and ...
                CreateChild(i);             // ... start a new one in its place.
            }
        }
    }

    return 0;
}

// The CTRL+C signal handler sets a flag causing the Run() method to exit.
void scxProcessGenerator::SignalHandler(int signal)
{
    terminate = signal;
}

// Sends an interupt to the child process and waits for it to exit.
void scxProcessGenerator::TerminateChild(int idx)
{
    printf("Terminate Child: %d (%d)\n", idx, childHandles[idx]);
    if (childHandles[idx] != 0)
    {
        // Protect against trying to kill the same child twice.
        pid_t handle = childHandles[idx];
        childHandles[idx] = 0;

        // Tell the child process to exit and wait for it to do so.
        scxKill(handle, SIGINT);
        scxWait(handle);
    }
}
