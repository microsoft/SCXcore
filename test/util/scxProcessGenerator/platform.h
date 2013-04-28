#if !defined(hpux)
#pragma once
#endif

#ifndef _INC_PLATFORM
#define _INC_PLATFORM

// The platform.h and platform.cpp files provide cross platform
// compatability between the WIN32 and the Unix/Linux platforms.
#include <ctype.h>
#include <fcntl.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

// These prototypes have platform dependent differences.
#if defined(WIN32)

#include <io.h>
#include <process.h>
#include <windows.h>

typedef intptr_t pid_t;

int scxClose(int fd);
int scxKill(pid_t pid, int sig);
int scxOpen(const char *filename, int oflag);
int scxOpen(const char *filename, int oflag, int pmode);
int scxRead(int fd, void *buffer, unsigned int count);
void scxSleep(int seconds);
int scxUnlink(const char *pathname);
int scxWrite(int fd, const void *buffer, unsigned int count);

#else

#include <sys/wait.h>
#include <unistd.h>

#define scxClose    close
#define scxKill     kill
#define scxOpen     open
#define scxRead     read
#define scxSleep    sleep
#define scxUnlink   unlink
#define scxWrite    write

#endif

// These prototypes should be identical accross all platforms.
char *scxItoa(int value, char *str, int size, int radix);
pid_t scxSpawn(const char *filename, char * const *argv);
pid_t scxWait(pid_t procHandle);

#endif  /* _INC_PLATFORM */
