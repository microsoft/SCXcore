#include "platform.h"

// Wrappers used to map Unix/Linux calls to WIN32 calls.
#if defined(WIN32)
#include <share.h>

int scxClose(int fd)
{
    return _close(fd);
}

int scxKill(pid_t pid, int sig)
{
    sig;
    return TerminateProcess((HANDLE)pid, 0);
}

char *scxItoa(int value, char *str, int size, int radix)
{
    _itoa_s(value, str, size, radix);
    return str;
}

int scxOpen(const char *filename, int oflag)
{
    return scxOpen(filename, oflag, _S_IREAD | _S_IWRITE);
}

int scxOpen(const char *filename, int oflag, int pmode)
{
    int pfh;
    int shflag = _SH_DENYNO;

    _sopen_s(&pfh, filename, _O_BINARY | oflag, shflag, pmode & ~S_IEXEC);
    return pfh;
}

int scxRead(int fd, void *buffer, unsigned int count)
{
    return _read(fd, buffer, count);
}

void scxSleep(int seconds)
{
    Sleep(1000 * seconds);
}

pid_t scxSpawn(const char *filename, char *const *argv)
{
    return _spawnv(_P_NOWAIT, filename, argv);
}

int scxUnlink(const char *pathname)
{
    return _unlink(pathname);
}

pid_t scxWait(pid_t procHandle)
{
    return _cwait(NULL, procHandle, 0);
}

int scxWrite(int fd, const void *buffer, unsigned int count)
{
    return _write(fd, buffer, count);
}

#else // !defined(WIN32)

#include <errno.h>
#include <stdio.h>

// This wrapper implements the WIN32 itoa function
// which has no equivalent on Unix/Linux platforms.
char *scxItoa(int value, char *str, int size, int radix)
{
    sprintf(str, "%d", value);
    return str;
}

// This wrapper implements the WIN32 spawnv function
// which has no equivalent on Unix/Linux platforms.
pid_t scxSpawn(const char *filename, char *const *argv)
{
    // Use fork() to create a child process.  Then, in the
    // child, use execve() to run the child program.
    pid_t cpid = 0;

    cpid = fork();
    if (cpid == -1)         // Code executed by parent.
    {
        perror("fork");     // Error forking child.
    }
    else if (cpid == 0)     // Code executed by child.
    {
        char *envp = NULL;

        execve(filename, argv, &envp);

        // If execve returned, there was an error and the child program is not
        // running.  The only realistic thing to do, in this case, is exit.
        exit(errno);
    }

    // Code executed by parent.
    return (pid_t)cpid;
}

pid_t scxWait(pid_t procHandle)
{
    return waitpid(procHandle, NULL, 0);
}

#endif // defined(WIN32)
