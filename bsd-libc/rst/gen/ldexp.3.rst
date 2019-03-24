--------------

LDEXP(3) BSD Library Functions Manual LDEXP(3)

**NAME**

**ldexp**, **ldexpf**, **ldexpl** — multiply floating-point number by
integral power of 2

**LIBRARY**

Math Library (libm, −lm)

**SYNOPSIS**

**#include <math.h>**

*double*

**ldexp**\ (*double x*, *int exp*);

*float*

**ldexpf**\ (*float x*, *int exp*);

*long double*

**ldexpl**\ (*long double x*, *int exp*);

**DESCRIPTION**

The **ldexp**\ (), **ldexpf**\ (), and **ldexpl**\ () functions multiply
a floating-point number by an integral power of 2.

**RETURN VALUES**

These functions return the value of *x* times 2 raised to the power
*exp*.

**SEE ALSO**

frexp(3), math(3), modf(3)

**STANDARDS**

The **ldexp**\ (), **ldexpf**\ (), and **ldexpl**\ () functions conform
to ISO/IEC 9899:1999 (‘‘ISO C99’’).

BSD March 4, 2005 BSD

--------------
