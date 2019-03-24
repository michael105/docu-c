--------------

CLOSEFROM(2) BSD System Calls Manual CLOSEFROM(2)

**NAME**

**closefrom** — delete open file descriptors

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <unistd.h>**

*void*

**closefrom**\ (*int lowfd*);

**DESCRIPTION**

The **closefrom**\ () system call deletes all open file descriptors
greater than or equal to *lowfd* from the per-process object reference
table. Any errors encountered while closing file descriptors are
ignored.

**SEE ALSO**

close(2)

**HISTORY**

The **closefrom**\ () function first appeared in FreeBSD 8.0.

BSD June 12, 2009 BSD

--------------
