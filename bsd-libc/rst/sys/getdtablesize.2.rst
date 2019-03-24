--------------

GETDTABLESIZE(2) BSD System Calls Manual GETDTABLESIZE(2)

**NAME**

**getdtablesize** — get file descriptor limit

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <unistd.h>**

*int*

**getdtablesize**\ (*void*);

**DESCRIPTION**

The **getdtablesize**\ () system call returns the maximum number of file
descriptors that the current process may open. The maximum file
descriptor number that the system may assign is the return value minus
one. Existing file descriptor numbers may be higher if the limit was
lowered after they were opened.

**SEE ALSO**

close(2), closefrom(2), dup(2), getrlimit(2), sysconf(3)

**HISTORY**

The **getdtablesize**\ () system call appeared in 4.2BSD.

BSD April 24, 2013 BSD

--------------
