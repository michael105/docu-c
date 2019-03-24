--------------

ABS(3) BSD Library Functions Manual ABS(3)

**NAME**

**abs** — integer absolute value function

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <stdlib.h>**

*int*

**abs**\ (*int j*);

**DESCRIPTION**

The **abs**\ () function computes the absolute value of the integer *j*.

**RETURN VALUES**

The **abs**\ () function returns the absolute value.

**SEE ALSO**

cabs(3), fabs(3), floor(3), hypot(3), imaxabs(3), labs(3), llabs(3),
math(3)

**STANDARDS**

The **abs**\ () function conforms to ISO/IEC 9899:1999 (‘‘ISO C99’’).

**BUGS**

The absolute value of the most negative integer remains negative.

BSD November 14, 2001 BSD

--------------
