--------------

ATOF(3) BSD Library Functions Manual ATOF(3)

**NAME**

**atof** — convert ASCII string to double

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <stdlib.h>**

*double*

**atof**\ (*const char *nptr*);

**DESCRIPTION**

The **atof**\ () function converts the initial portion of the string
pointed to by *nptr* to *double* representation.

It is equivalent to:

strtod(nptr, (char \**)NULL);

The decimal point character is defined in the program’s locale (category
LC_NUMERIC).

**IMPLEMENTATION NOTES**

The **atof**\ () function is not thread-safe and also not
async-cancel-safe.

The **atof**\ () function has been deprecated by **strtod**\ () and
should not be used in new code.

**ERRORS**

The function **atof**\ () need not affect the value of *errno* on an
error.

**SEE ALSO**

atoi(3), atol(3), strtod(3), strtol(3), strtoul(3)

**STANDARDS**

The **atof**\ () function conforms to ISO/IEC 9945-1:1990 (‘‘POSIX.1’’),
ISO/IEC 9899:1990 (‘‘ISO C90’’), and ISO/IEC 9899:1999 (‘‘ISO C99’’).

BSD June 4, 1993 BSD

--------------
