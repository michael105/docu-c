--------------

BZERO(3) BSD Library Functions Manual BZERO(3)

**NAME**

**bzero**, **explicit_bzero** — write zeroes to a byte string

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <strings.h>**

*void*

**bzero**\ (*void *b*, *size_t len*);

*void*

**explicit_bzero**\ (*void *b*, *size_t len*);

**DESCRIPTION**

The **bzero**\ () function writes *len* zero bytes to the string *b*. If
*len* is zero, **bzero**\ () does nothing.

The **explicit_bzero**\ () variant behaves the same, but will not be
removed by a compiler’s dead store optimization pass, making it useful
for clearing sensitive memory such as a password.

**SEE ALSO**

memset(3), swab(3)

**HISTORY**

A **bzero**\ () function appeared in 4.3BSD. Its prototype existed
previously in <*string.h*> before it was moved to <*strings.h*> for IEEE
Std 1003.1-2001 (‘‘POSIX.1’’) compliance.

The **explicit_bzero**\ () function first appeared in OpenBSD 5.5 and
FreeBSD 11.0.

IEEE Std 1003.1-2008 (‘‘POSIX.1’’) removes the specification of
**bzero**\ () and it is marked as LEGACY in IEEE Std 1003.1-2004
(‘‘POSIX.1’’). For portability with other systems new programs should
use memset(3).

BSD August 24, 2015 BSD

--------------
