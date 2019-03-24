--------------

LLDIV(3) BSD Library Functions Manual LLDIV(3)

**NAME**

**lldiv** — returns quotient and remainder

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <stdlib.h>**

*lldiv_t*

**lldiv**\ (*long long numer*, *long long denom*);

**DESCRIPTION**

The **lldiv**\ () function computes the value of *numer* divided by
*denom* and returns the stored result in the form of the *lldiv_t* type.

The *lldiv_t* type is defined as:

typedef struct {

+-----------------------+-----------------------+-----------------------+
|                       | long long quot; /\*   |                       |
|                       | Quotient. \*/         |                       |
+-----------------------+-----------------------+-----------------------+
|                       | long long rem; /\*    |                       |
|                       | Remainder. \*/        |                       |
+-----------------------+-----------------------+-----------------------+

} lldiv_t;

**SEE ALSO**

div(3), imaxdiv(3), ldiv(3), math(3)

**STANDARDS**

The **lldiv**\ () function conforms to ISO/IEC 9899:1999 (‘‘ISO C99’’).

**HISTORY**

The **lldiv**\ () function first appeared in FreeBSD 5.0.

BSD November 14, 2001 BSD

--------------
