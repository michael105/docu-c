--------------

LLABS(3) BSD Library Functions Manual LLABS(3)

**NAME**

**llabs** — returns absolute value

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <stdlib.h>**

*long long*

**llabs**\ (*long long j*);

**DESCRIPTION**

The **llabs**\ () function returns the absolute value of *j*.

**SEE ALSO**

abs(3), fabs(3), hypot(3), imaxabs(3), labs(3), math(3)

**STANDARDS**

The **llabs**\ () function conforms to ISO/IEC 9899:1999 (‘‘ISO C99’’).

**HISTORY**

The **llabs**\ () function first appeared in FreeBSD 5.0.

**BUGS**

The absolute value of the most negative integer remains negative.

BSD November 14, 2001 BSD

--------------
