--------------

CLOCK(3) BSD Library Functions Manual CLOCK(3)

**NAME**

**clock** — determine processor time used

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <time.h>**

*clock_t*

**clock**\ (*void*);

**DESCRIPTION**

The **clock**\ () function determines the amount of processor time used
since the invocation of the calling process, measured in CLOCKS_PER_SECs
of a second.

**RETURN VALUES**

The **clock**\ () function returns the amount of time used unless an
error occurs, in which case the return value is −1.

**SEE ALSO**

getrusage(2), clocks(7)

**STANDARDS**

The **clock**\ () function conforms to ISO/IEC 9899:1990 (‘‘ISO C90’’).
However, Version 2 of the Single UNIX Specification (‘‘SUSv2’’) requires
CLOCKS_PER_SEC to be defined as one million. FreeBSD does not conform to
this requirement; changing the value would introduce binary
incompatibility and one million is still inadequate on modern
processors.

BSD June 4, 1993 BSD

--------------
