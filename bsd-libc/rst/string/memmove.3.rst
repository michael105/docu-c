--------------

MEMMOVE(3) BSD Library Functions Manual MEMMOVE(3)

**NAME**

**memmove** — copy byte string

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <string.h>**

*void \**

**memmove**\ (*void *dst*, *const void *src*, *size_t len*);

**DESCRIPTION**

The **memmove**\ () function copies *len* bytes from string *src* to
string *dst*. The two strings may overlap; the copy is always done in a
non-destructive manner.

**RETURN VALUES**

The **memmove**\ () function returns the original value of *dst*.

**SEE ALSO**

bcopy(3), memccpy(3), memcpy(3), strcpy(3), wmemmove(3)

**STANDARDS**

The **memmove**\ () function conforms to ISO/IEC 9899:1990
(‘‘ISO C90’’).

BSD June 4, 1993 BSD

--------------
