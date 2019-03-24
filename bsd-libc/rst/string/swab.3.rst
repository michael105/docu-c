--------------

SWAB(3) BSD Library Functions Manual SWAB(3)

**NAME**

**swab** — swap adjacent bytes

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <unistd.h>**

*void*

**swab**\ (*const void * restrict src*, *void * restrict dst*,
*ssize_t len*);

**DESCRIPTION**

The function **swab**\ () copies *len* bytes from the location
referenced by *src* to the location referenced by *dst*, swapping
adjacent bytes.

The argument *len* must be an even number. If *len* is less than zero,
nothing will be done.

**SEE ALSO**

bzero(3), memset(3)

**HISTORY**

A **swab**\ () function appeared in Version 7 AT&T UNIX.

BSD March 4, 2012 BSD

--------------
