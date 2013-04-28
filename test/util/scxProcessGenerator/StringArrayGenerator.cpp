#include "StringArrayGenerator.h"
#include <stdlib.h>
#include <string.h>

StringArrayGenerator::StringArrayGenerator(int size, int min, int max, int mode)
{
    stringCount = (size < 1) ? 1 : size;
    minLength = (min < 0) ? 0 : min;
    maxLength = (max < minLength) ? minLength : max;
    randomFlag = mode;

    pattern = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyz";

    indexArray = new int[stringCount];
    stringArray = new char *[stringCount];

    for (int i = 0; i < stringCount; i++)
    {
        indexArray[i] = RandomNumberRange(0, strlen(pattern));
        stringArray[i] = new char[maxLength + 1];
    }

    // An argument list actually used by the customer.
    customerStringArray = new char *[14];

    customerStringArray[0] = (char *)"-session";
    customerStringArray[1] = (char *)"1";
    customerStringArray[2] = (char *)"-terminate";
    customerStringArray[3] = (char *)"-bs";
    customerStringArray[4] = (char *)"-glx";
    customerStringArray[5] = (char *)"-notransfills";
    customerStringArray[6] = (char *)"-co";
    customerStringArray[7] = (char *)"/usr/lib/X11/rgb";
    customerStringArray[8] = (char *)"-fp";
    customerStringArray[9] = (char *)"/usr/lib/X11/fonts/hp_roman8/75dpi/,"
                                     "/usr/lib/X11/fonts/iso_8859.1/100dpi/,"
                                     "/usr/lib/X11/fonts/iso_8859.1/75dpi/,"
                                     "/usr/lib/X11/fonts/hp_kana8/,"
                                     "/usr/lib/X11/fonts/iso_8859.2/75dpi/,"
                                     "/usr/lib/X11/fonts/iso_8859.5/75dpi/,"
                                     "/usr/lib/X11/fonts/iso_8859.6/75dpi/,"
                                     "/usr/lib/X11/fonts/iso_8859.7/75dpi/,"
                                     "/usr/lib/X11/fonts/iso_8859.8/75dpi/,"
                                     "/usr/lib/X11/fonts/iso_8859.9/75dpi/,"
                                     "/usr/lib/X11/fonts/misc/,"
                                     "/usr/dt/config/xfonts/C/";
    customerStringArray[10] = (char *)"-sp";
    customerStringArray[11] = (char *)"/dev/null";
    customerStringArray[12] = (char *)"&";
    customerStringArray[13] = NULL;
}

StringArrayGenerator::~StringArrayGenerator(void)
{
    if (indexArray != NULL)
    {
        delete[] indexArray;
    }

    if (stringArray != NULL)
    {
        for (int i = 0; i < stringCount; i++)
        {
            if (stringArray[i] != NULL)
            {
                delete[] stringArray[i];
            }
        }

        delete[] stringArray;
    }

    delete[] customerStringArray;
}

char **StringArrayGenerator::BuildCustomerStringArray(void)
{
    return customerStringArray;
}

char **StringArrayGenerator::BuildStringArray(void)
{
    int patternLength = strlen(pattern);

    for (int i = 0; i < stringCount; i++)
    {
        int stringLength = RandomNumberRange(minLength, maxLength);

        // First, load up stringLength random or sequencial characters.
        for (int j = 0; j < stringLength; j++)
        {
            if (randomFlag)
            {
                stringArray[i][j] = pattern[RandomNumberRange(0, patternLength)];
            }
            else
            {
                stringArray[i][j] = pattern[(indexArray[i] + i) % patternLength];
            }
        }

        // Second, fill the remaining space with NULL characters.
        for (int k = stringLength; k <= maxLength; k++)
        {
            stringArray[i][k] = '\0';
        }

        // If this is sequencial strings, incriment the pointer to the next character position.
        if (!randomFlag)
        {
            indexArray[i] = (indexArray[i] + 1) % patternLength;
        }
    }

    return stringArray;
}

// Generate a random number in the half-closed interval [range_min, range_max].
// In other words, (min <= random_number < max).
int StringArrayGenerator::RandomNumberRange(int min, int max)
{
    int u = (int)((double)rand() / (RAND_MAX + 1) * (max - min) + min);
    return u;
}
