--------------

LABS(3) BSD Library Functions Manual LABS(3)

**NAME**

**labs** — return the absolute value of a long integer

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <stdlib.h>**

*long*

**labs**\ (*long j*);

**DESCRIPTION**

The **labs**\ () function returns the absolute value of the long integer
*j*.

**SEE ALSO**

abs(3), cabs(3), floor(3), imaxabs(3), llabs(3), math(3)

**STANDARDS**

The **labs**\ () function conforms to ISO/IEC 9899:1990 (‘‘ISO C90’’).

**BUGS**

The absolute value of the most negative integer remains negative.

BSD November 14, 2001 BSD

--------------
