#if !defined(hpux)
#pragma once
#endif

#ifndef _INC_STRINGARRAYGENERATOR
#define _INC_STRINGARRAYGENERATOR

class StringArrayGenerator
{
private:
    const char *pattern;
    int stringCount;            // The number of strings go generate.
    int minLength;              // The minimum length of each string.
    int maxLength;              // The maximum length of each string.
    int randomFlag;             // 0 = sequencial, !0 = random
    int *indexArray;
    char **stringArray;
    char **customerStringArray;

    int RandomNumberRange(int min, int max);

public:
    StringArrayGenerator(int size, int min, int max, int mode);
    ~StringArrayGenerator(void);

    char **BuildCustomerStringArray(void);
    char **BuildStringArray(void);
};

#endif  /* _INC_STRINGARRAYGENERATOR */
