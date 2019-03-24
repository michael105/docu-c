--------------

BCOPY(3) BSD Library Functions Manual BCOPY(3)

**NAME**

**bcopy** — copy byte string

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <strings.h>**

*void*

**bcopy**\ (*const void *src*, *void *dst*, *size_t len*);

**DESCRIPTION**

The **bcopy**\ () function copies *len* bytes from string *src* to
string *dst*. The two strings may overlap. If *len* is zero, no bytes
are copied.

**SEE ALSO**

memccpy(3), memcpy(3), memmove(3), strcpy(3), strncpy(3)

**HISTORY**

A **bcopy**\ () function appeared in 4.2BSD. Its prototype existed
previously in <*string.h*> before it was moved to <*strings.h*> for IEEE
Std 1003.1-2001 (‘‘POSIX.1’’) compliance.

IEEE Std 1003.1-2008 (‘‘POSIX.1’’) removes the specification of
**bcopy**\ () and it is marked as LEGACY in IEEE Std 1003.1-2004
(‘‘POSIX.1’’). New programs should use memmove(3). If the input and
output buffer do not overlap, then memcpy(3) is more efficient. Note
that **bcopy**\ () takes *src* and *dst* in the opposite order from
**memmove**\ () and **memcpy**\ ().

BSD August 24, 2015 BSD

--------------
