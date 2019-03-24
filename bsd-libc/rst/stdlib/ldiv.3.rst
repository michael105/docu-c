--------------

LDIV(3) BSD Library Functions Manual LDIV(3)

**NAME**

**ldiv** — return quotient and remainder from division

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <stdlib.h>**

*ldiv_t*

**ldiv**\ (*long num*, *long denom*);

**DESCRIPTION**

The **ldiv**\ () function computes the value *num*/*denom* and returns
the quotient and remainder in a structure named *ldiv_t* that contains
two *long* members named *quot* and *rem*.

**SEE ALSO**

div(3), imaxdiv(3), lldiv(3), math(3)

**STANDARDS**

The **ldiv**\ () function conforms to ISO/IEC 9899:1999 (‘‘ISO C99’’).

BSD November 14, 2001 BSD

--------------
