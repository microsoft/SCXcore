#include "Usage.h"
#include <stdio.h>

void Usage(void)
{
    //               1         2         3         4         6         6         7
    //      123456789012345678901234567890123456789012345678901234567890123456789012
    //printf("\nUsage: scxProcessGenerator -p[rocesses] n1 [-t[urnover] n2]\n");
    //printf("                           [-r[andom] | -s[equencial]]\n\n");
    //printf("  where;\n");
    //printf("    -p[rocesses] n1  - Specifies the total number of processes that\n");
    //printf("                       are started and running at any given time.\n");
    //printf("                       The valid range is 1 to INT_MAX.  This is a\n");
    //printf("                       required parameter.\n");
    //printf("    -t[urnover] n2   - Specifies the rate (in seconds) at which the\n");
    //printf("                       oldest process exits and a new one is created\n");
    //printf("                       to take its place.  The valid range is 1 to\n");
    //printf("                       INT_MAX.  The default value is 1.\n");
    printf("\nUsage: scxProcessGenerator -p[rocesses] n1 [-i[nterval] n2]\n");
    printf("                           [-t[urnover] n3] [-r[andom] | -s[equencial]]\n\n");
    printf("  where;\n");
    printf("    -p[rocesses] n1  - Specifies the maximum number of processes to\n");
    printf("                       be created.  After reaching this value, the\n");
    printf("                       oldest process exits and a new one is created\n");
    printf("                       in its place.  The valid range is 1 to INT_MAX.\n");
    printf("                       This is a required parameter.\n");
    printf("    -i[nterval] n2   - Specifies the time (in seconds) to wait before\n");
    printf("                       the next process is created, until the maximum\n");
    printf("                       number of processes has been reached.  When the\n");
    printf("                       maximum number of processes is reached, the\n");
    printf("                       'turnovr' value is used.  The valid range is 0\n");
    printf("                       to INT_MAX.  The default value is 0.\n");
    printf("    -t[urnover] n3   - Specifies the rate (in seconds) at which the\n");
    printf("                       oldest process exits and is replaced by a new\n");
    printf("                       one.  The valid range is 1 to INT_MAX.  The\n");
    printf("                       default value is 1.\n");

    printf("    -r[andom]        - Sets generation of argument strings for child\n");
    printf("                       processes to be strings of random characters.\n");
    printf("                       This is the default.\n");
    printf("    -s[equencial]    - Sets generation of argument strings for child\n");
    printf("                       processes to be strings of sequencial characters.\n");
    printf("                       The default is -random.\n\n");

    printf("Note: The last instance of a given argument on the command line is the\n");
    printf("      value that is used.  The -random and -sequencial arguments toggle\n");
    printf("      each other.\n");
}
