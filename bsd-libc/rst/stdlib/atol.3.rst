--------------

ATOL(3) BSD Library Functions Manual ATOL(3)

**NAME**

**atol**, **atoll** — convert ASCII string to *long* or *long long*
integer

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <stdlib.h>**

*long*

**atol**\ (*const char *nptr*);

*long long*

**atoll**\ (*const char *nptr*);

**DESCRIPTION**

The **atol**\ () function converts the initial portion of the string
pointed to by *nptr* to *long* integer representation.

It is equivalent to:

strtol(nptr, (char \**)NULL, 10);

The **atoll**\ () function converts the initial portion of the string
pointed to by *nptr* to *long long* integer representation.

It is equivalent to:

strtoll(nptr, (char \**)NULL, 10);

**COMPATIBILITY**

The FreeBSD implementations of the **atol**\ () and **atoll**\ ()
functions are thin wrappers around **strtol**\ () and **strtoll**\ ()
respectively, so these functions will affect the value of *errno* in the
same way that the **strtol**\ () and **strtoll**\ () functions are able
to. This behavior of **atol**\ () and **atoll**\ () is not required by
ISO/IEC 9899:1990 (‘‘ISO C90’’) or ISO/IEC 9899:1999 (‘‘ISO C99’’), but
it is allowed by all of ISO/IEC 9899:1990 (‘‘ISO C90’’), ISO/IEC
9899:1999 (‘‘ISO C99’’) and IEEE Std 1003.1-2001 (‘‘POSIX.1’’).

**ERRORS**

The functions **atol**\ () and **atoll**\ () may affect the value of
*errno* on an error.

**SEE ALSO**

atof(3), atoi(3), strtod(3), strtol(3), strtoul(3)

**STANDARDS**

The **atol**\ () function conforms to ISO/IEC 9899:1990 (‘‘ISO C90’’).
The **atoll**\ () function conforms to ISO/IEC 9899:1999 (‘‘ISO C99’’).

BSD May 14, 2013 BSD

--------------
