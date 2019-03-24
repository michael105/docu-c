--------------

MEMCPY(3) BSD Library Functions Manual MEMCPY(3)

**NAME**

**memcpy** — copy byte string

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <string.h>**

*void \**

**memcpy**\ (*void *dst*, *const void *src*, *size_t len*);

**DESCRIPTION**

The **memcpy**\ () function copies *len* bytes from string *src* to
string *dst*. If *src* and *dst* overlap, the results are not defined.

**RETURN VALUES**

The **memcpy**\ () function returns the original value of *dst*.

**SEE ALSO**

bcopy(3), memccpy(3), memmove(3), strcpy(3), wmemcpy(3)

**STANDARDS**

The **memcpy**\ () function conforms to ISO/IEC 9899:1990 (‘‘ISO C90’’).

**BUGS**

In this implementation **memcpy**\ () is implemented using bcopy(3), and
therefore the strings may overlap. On other systems, copying overlapping
strings may produce surprises. Programs intended to be portable should
use memmove(3) when *src* and *dst* may overlap.

BSD June 4, 1993 BSD

--------------
