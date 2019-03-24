--------------

IMAXABS(3) BSD Library Functions Manual IMAXABS(3)

**NAME**

**imaxabs** — returns absolute value

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <inttypes.h>**

*intmax_t*

**imaxabs**\ (*intmax_t j*);

**DESCRIPTION**

The **imaxabs**\ () function returns the absolute value of *j*.

**SEE ALSO**

abs(3), fabs(3), hypot(3), labs(3), llabs(3), math(3)

**STANDARDS**

The **imaxabs**\ () function conforms to ISO/IEC 9899:1999
(‘‘ISO C99’’).

**HISTORY**

The **imaxabs**\ () function first appeared in FreeBSD 5.0.

**BUGS**

The absolute value of the most negative integer remains negative.

BSD November 14, 2001 BSD

--------------
