--------------

IMAXDIV(3) BSD Library Functions Manual IMAXDIV(3)

**NAME**

**imaxdiv** — returns quotient and remainder

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <inttypes.h>**

*imaxdiv_t*

**imaxdiv**\ (*intmax_t numer*, *intmax_t denom*);

**DESCRIPTION**

The **imaxdiv**\ () function computes the value of *numer* divided by
*denom* and returns the stored result in the form of the *imaxdiv_t*
type.

The *imaxdiv_t* type is defined as:

typedef struct {

+-----------------------+-----------------------+-----------------------+
|                       | intmax_t quot; /\*    |                       |
|                       | Quotient. \*/         |                       |
+-----------------------+-----------------------+-----------------------+
|                       | intmax_t rem; /\*     |                       |
|                       | Remainder. \*/        |                       |
+-----------------------+-----------------------+-----------------------+

} imaxdiv_t;

**SEE ALSO**

div(3), ldiv(3), lldiv(3), math(3)

**STANDARDS**

The **imaxdiv**\ () function conforms to ISO/IEC 9899:1999
(‘‘ISO C99’’).

**HISTORY**

The **imaxdiv**\ () function first appeared in FreeBSD 5.0.

BSD November 14, 2001 BSD

--------------
