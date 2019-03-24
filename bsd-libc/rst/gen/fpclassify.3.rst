--------------

FPCLASSIFY(3) BSD Library Functions Manual FPCLASSIFY(3)

**NAME**

**fpclassify**, **isfinite**, **isinf**, **isnan**, **isnormal** —
classify a floating-point number

**LIBRARY**

Math Library (libm, −lm)

**SYNOPSIS**

**#include <math.h>**

*int*

**fpclassify**\ (*real-floating x*);

*int*

**isfinite**\ (*real-floating x*);

*int*

**isinf**\ (*real-floating x*);

*int*

**isnan**\ (*real-floating x*);

*int*

**isnormal**\ (*real-floating x*);

**DESCRIPTION**

The **fpclassify**\ () macro takes an argument of *x* and returns one of
the following manifest constants.

FP_INFINITE

Indicates that *x* is an infinite number.

FP_NAN

Indicates that *x* is not a number (NaN).

FP_NORMAL

Indicates that *x* is a normalized number.

FP_SUBNORMAL

Indicates that *x* is a denormalized number.

FP_ZERO

Indicates that *x* is zero (0 or −0).

The **isfinite**\ () macro returns a non-zero value if and only if its
argument has a finite (zero, subnormal, or normal) value. The
**isinf**\ (), **isnan**\ (), and **isnormal**\ () macros return
non-zero if and only if *x* is an infinity, NaN, or a non-zero
normalized number, respectively.

The symbol **isnanf**\ () is provided as an alias to **isnan**\ () for
compatibility, and its use is deprecated. Similarly, **finite**\ () and
**finitef**\ () are deprecated versions of **isfinite**\ ().

**SEE ALSO**

isgreater(3), math(3), signbit(3)

**STANDARDS**

The **fpclassify**\ (), **isfinite**\ (), **isinf**\ (), **isnan**\ (),
and **isnormal**\ () macros conform to ISO/IEC 9899:1999 (‘‘ISO C99’’).

**HISTORY**

The **fpclassify**\ (), **isfinite**\ (), **isinf**\ (), **isnan**\ (),
and **isnormal**\ () macros were added in FreeBSD 5.1. 3BSD introduced
**isinf**\ () and **isnan**\ () functions, which accepted *double*
arguments; these have been superseded by the macros described above.

BSD January 26, 2005 BSD

--------------
