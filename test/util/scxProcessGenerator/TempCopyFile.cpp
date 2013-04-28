#include "platform.h"
#include "TempCopyFile.h"
#include <errno.h>

TempCopyFile::TempCopyFile(const char *src, const char *dst)
{
    sourceFile = src;
    destFile = dst;
}

TempCopyFile::~TempCopyFile(void)
{
    scxUnlink(destFile);
}

int TempCopyFile::Copy(void)
{
    int f1;
    int flags1 = O_RDONLY;

    int f2;
    int flags2 = O_WRONLY | O_TRUNC | O_CREAT;
    // On Unix/Linux platforms, these mode constants apply to the user only.
    int mode2  = S_IREAD | S_IWRITE | S_IEXEC;

    f1 = scxOpen(sourceFile, flags1);
    if (f1 == -1)
    {
        return errno;
    }

    f2 = scxOpen(destFile, flags2, mode2);
    if (f2 == -1)
    {
        scxClose(f1);
        return errno;
    }

    char buffer[1024];
    int charsRead = scxRead(f1, buffer, 1024);
    while (charsRead > 0)
    {
        scxWrite(f2, buffer, charsRead);
        charsRead = scxRead(f1, buffer, 1024);
    }

    scxClose(f1);
    scxClose(f2);

    return 0;
}
