--------------

ISGREATER(3) BSD Library Functions Manual ISGREATER(3)

**NAME**

**isgreater**, **isgreaterequal**, **isless**, **islessequal**,
**islessgreater**, **isunordered** — compare two floating-point numbers

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <math.h>**

*int*

**isgreater**\ (*real-floating x*, *real-floating y*);

*int*

**isgreaterequal**\ (*real-floating x*, *real-floating y*);

*int*

**isless**\ (*real-floating x*, *real-floating y*);

*int*

**islessequal**\ (*real-floating x*, *real-floating y*);

*int*

**islessgreater**\ (*real-floating x*, *real-floating y*);

*int*

**isunordered**\ (*real-floating x*, *real-floating y*);

**DESCRIPTION**

Each of the macros **isgreater**\ (), **isgreaterequal**\ (),
**isless**\ (), **islessequal**\ (), and **islessgreater**\ () take
arguments *x* and *y* and return a non-zero value if and only if its
nominal relation on *x* and *y* is true. These macros always return zero
if either argument is not a number (NaN), but unlike the corresponding C
operators, they never raise a floating point exception.

The **isunordered**\ () macro takes arguments *x* and *y* and returns
non-zero if and only if any of *x* or *y* are NaNs. For any pair of
floating-point values, one of the relationships (less, greater, equal,
unordered) holds.

**SEE ALSO**

fpclassify(3), math(3), signbit(3)

**STANDARDS**

The **isgreater**\ (), **isgreaterequal**\ (), **isless**\ (),
**islessequal**\ (), **islessgreater**\ (), and **isunordered**\ ()
macros conform to ISO/IEC 9899:1999 (‘‘ISO C99’’).

**HISTORY**

The relational macros described above first appeared in FreeBSD 5.1.

BSD February 12, 2003 BSD

--------------
