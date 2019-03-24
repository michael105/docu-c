--------------

GETPAGESIZES(3) BSD Library Functions Manual GETPAGESIZES(3)

**NAME**

**getpagesizes** — get system page sizes

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/mman.h>**

*int*

**getpagesizes**\ (*size_t pagesize[]*, *int nelem*);

**DESCRIPTION**

The **getpagesizes**\ () function retrieves page size information from
the system. When it is called with *pagesize* specified as NULL and
*nelem* specified as 0, it returns the number of distinct page sizes
that are supported by the system. Otherwise, it assigns up to *nelem* of
the system-supported page sizes to consecutive elements of the array
referenced by *pagesize*. These page sizes are expressed in bytes. In
this case, **getpagesizes**\ () returns the number of such page sizes
that it assigned to the array.

**RETURN VALUES**

If successful, the **getpagesizes**\ () function returns either the
number of page sizes that are supported by the system or the number of
supported page sizes that it assigned to the array referenced by
*pagesize*. Otherwise, it returns the value −1 and sets *errno* to
indicate the error.

**ERRORS**

The **getpagesizes**\ () function will succeed unless:

[EINVAL]

The *pagesize* argument is NULL and the *nelem* argument is non-zero.

[EINVAL]

The *nelem* argument is less than zero.

**SEE ALSO**

getpagesize(3)

**HISTORY**

The **getpagesizes**\ () function first appeared in Solaris 9. This
manual page was written in conjunction with a new but compatible
implementation that was first released in FreeBSD 7.3.

**AUTHORS**

This manual page was written by Alan L. Cox <*alc@cs.rice.edu*>.

BSD September 21, 2009 BSD

--------------
