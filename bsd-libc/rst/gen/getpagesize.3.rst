--------------

GETPAGESIZE(3) BSD Library Functions Manual GETPAGESIZE(3)

**NAME**

**getpagesize** — get system page size

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <unistd.h>**

*int*

**getpagesize**\ (*void*);

**DESCRIPTION**

The **getpagesize**\ () function returns the number of bytes in a page.
Page granularity is the granularity of many of the memory management
calls.

The page size is a system page size and may not be the same as the
underlying hardware page size.

**SEE ALSO**

pagesize(1), sbrk(2)

**HISTORY**

The **getpagesize**\ () function appeared in 4.2BSD.

BSD April 26, 2017 BSD

--------------
