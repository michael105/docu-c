--------------

BCMP(3) BSD Library Functions Manual BCMP(3)

**NAME**

**bcmp** — compare byte string

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <strings.h>**

*int*

**bcmp**\ (*const void *b1*, *const void *b2*, *size_t len*);

**DESCRIPTION**

The **bcmp**\ () function compares byte string *b1* against byte string
*b2*, returning zero if they are identical, non-zero otherwise. Both
strings are assumed to be *len* bytes long. Zero-length strings are
always identical.

The strings may overlap.

**SEE ALSO**

memcmp(3), strcasecmp(3), strcmp(3), strcoll(3), strxfrm(3),
timingsafe_bcmp(3)

**HISTORY**

A **bcmp**\ () function first appeared in 4.2BSD. Its prototype existed
previously in <*string.h*> before it was moved to <*strings.h*> for IEEE
Std 1003.1-2001 (‘‘POSIX.1’’) compliance.

BSD August 15, 2016 BSD

--------------
