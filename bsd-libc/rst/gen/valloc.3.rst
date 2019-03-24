--------------

VALLOC(3) BSD Library Functions Manual VALLOC(3)

**NAME**

**valloc** — aligned memory allocation function

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <unistd.h>**

*void \**

**valloc**\ (*size_t size*);

**DESCRIPTION**

The **valloc**\ () function is obsoleted by posix_memalign(3), which can
be used to request page-aligned allocations.

The **valloc**\ () function allocates *size* bytes aligned on a page
boundary.

**RETURN VALUES**

The **valloc**\ () function returns a pointer to the allocated space if
successful; otherwise a null pointer is returned.

**SEE ALSO**

posix_memalign(3)

**HISTORY**

The **valloc**\ () function appeared in 3.0BSD.

The **valloc**\ () function correctly allocated memory that could be
deallocated via **free**\ () starting in FreeBSD 7.0.

BSD October 30, 2007 BSD

--------------
