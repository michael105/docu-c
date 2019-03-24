--------------

MODF(3) BSD Library Functions Manual MODF(3)

**NAME**

**modf**, **modff**, **modfl** — extract signed integral and fractional
values from floating-point number

**LIBRARY**

Math Library (libm, −lm)

**SYNOPSIS**

**#include <math.h>**

*double*

**modf**\ (*double value*, *double *iptr*);

*float*

**modff**\ (*float value*, *float *iptr*);

*long double*

**modfl**\ (*long double value*, *long double *iptr*);

**DESCRIPTION**

The **modf**\ (), **modff**\ (), and **modfl**\ () functions break the
argument *value* into integral and fractional parts, each of which has
the same sign as the argument. It stores the integral part as a floating
point number in the object pointed to by *iptr*.

**RETURN VALUES**

These functions return the signed fractional part of *value*.

**SEE ALSO**

frexp(3), ldexp(3), math(3)

**STANDARDS**

The **modf**\ (), **modff**\ (), and **modfl**\ () functions conform to
ISO/IEC 9899:1999 (‘‘ISO C99’’).

BSD March 29, 2008 BSD

--------------
