--------------

FREXP(3) BSD Library Functions Manual FREXP(3)

**NAME**

**frexp**, **frexpf**, **frexpl** — convert floating-point number to
fractional and integral components

**LIBRARY**

Math Library (libm, −lm)

**SYNOPSIS**

**#include <math.h>**

*double*

**frexp**\ (*double value*, *int *exp*);

*float*

**frexpf**\ (*float value*, *int *exp*);

*long double*

**frexpl**\ (*long double value*, *int *exp*);

**DESCRIPTION**

The **frexp**\ (), **frexpf**\ () and **frexpl**\ () functions break a
floating-point number into a normalized fraction and an integral power
of 2. They store the integer in the *int* object pointed to by *exp*.

**RETURN VALUES**

These functions return the value *x*, such that *x* is a *double* with
magnitude in the interval [

1/2, 1 ) or zero, and *value* equals *x* times 2 raised to the power
*\*exp*. If *value* is zero, both parts of the result are zero.

**SEE ALSO**

ldexp(3), math(3), modf(3)

**STANDARDS**

The **frexp**\ (), **frexpf**\ (), and **frexpl**\ () functions conform
to ISO/IEC 9899:1999 (‘‘ISO C99’’).

BSD March 4, 2005 BSD

--------------
