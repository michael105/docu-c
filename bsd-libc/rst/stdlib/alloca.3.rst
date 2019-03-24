--------------

ALLOCA(3) BSD Library Functions Manual ALLOCA(3)

**NAME**

**alloca** — memory allocator

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <stdlib.h>**

*void \**

**alloca**\ (*size_t size*);

**DESCRIPTION**

The **alloca**\ () function allocates *size* bytes of space in the stack
frame of the caller. This temporary space is automatically freed on
return.

**RETURN VALUES**

The **alloca**\ () function returns a pointer to the beginning of the
allocated space.

**SEE ALSO**

brk(2), calloc(3), getpagesize(3), malloc(3), realloc(3)

**HISTORY**

The **alloca**\ () function appeared in Version 32V AT&T UNIX.

**BUGS**

The **alloca**\ () function is machine and compiler dependent; its use
is discouraged.

The **alloca**\ () function is slightly unsafe because it cannot ensure
that the pointer returned points to a valid and usable block of memory.
The allocation made may exceed the bounds of the stack, or even go
further into other objects in memory, and **alloca**\ () cannot
determine such an error. Avoid **alloca**\ () with large unbounded
allocations.

BSD September 5, 2006 BSD

--------------
