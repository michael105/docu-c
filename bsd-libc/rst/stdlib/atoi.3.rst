--------------

ATOI(3) BSD Library Functions Manual ATOI(3)

**NAME**

**atoi** — convert ASCII string to integer

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <stdlib.h>**

*int*

**atoi**\ (*const char *nptr*);

**DESCRIPTION**

The **atoi**\ () function converts the initial portion of the string
pointed to by *nptr* to *int* representation.

It is equivalent to:

(int)strtol(nptr, NULL, 10);

The **atoi**\ () function has been deprecated by **strtol**\ () and
should not be used in new code.

**ERRORS**

The function **atoi**\ () need not affect the value of *errno* on an
error.

**SEE ALSO**

atof(3), atol(3), strtod(3), strtol(3), strtoul(3)

**STANDARDS**

The **atoi**\ () function conforms to ISO/IEC 9945-1:1990 (‘‘POSIX.1’’),
ISO/IEC 9899:1990 (‘‘ISO C90’’), and ISO/IEC 9899:1999 (‘‘ISO C99’’).

BSD June 13, 2018 BSD

--------------
