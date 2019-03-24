--------------

DIV(3) BSD Library Functions Manual DIV(3)

**NAME**

**div** — return quotient and remainder from division

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <stdlib.h>**

*div_t*

**div**\ (*int num*, *int denom*);

**DESCRIPTION**

The **div**\ () function computes the value *num/denom* and returns the
quotient and remainder in a structure named *div_t* that contains two
*int* members named *quot* and *rem*.

**SEE ALSO**

imaxdiv(3), ldiv(3), lldiv(3)

**STANDARDS**

The **div**\ () function conforms to ISO/IEC 9899:1999 (‘‘ISO C99’’).

BSD November 14, 2001 BSD

--------------
