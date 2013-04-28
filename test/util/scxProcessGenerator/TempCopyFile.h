#if !defined(hpux)
#pragma once
#endif

#ifndef _INC_TEMPCOPYFILE
#define _INC_TEMPCOPYFILE

class TempCopyFile
{
private:
    const char *sourceFile;
    const char *destFile;

public:
    TempCopyFile(const char *src, const char *dst);
    ~TempCopyFile(void);

    int Copy(void);
};

#endif  /* _INC_TEMPCOPYFILE */
