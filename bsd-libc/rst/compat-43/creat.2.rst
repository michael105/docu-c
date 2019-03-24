--------------

CREAT(2) BSD System Calls Manual CREAT(2)

**NAME**

**creat** — create a new file

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <fcntl.h>**

*int*

**creat**\ (*const char *path*, *mode_t mode*);

**DESCRIPTION**

**This interface is made obsolete by:** open(2).

The **creat**\ () function is the same as:

open(path, O_CREAT \| O_TRUNC \| O_WRONLY, mode);

**SEE ALSO**

open(2)

**HISTORY**

The **creat**\ () function appeared in Version 6 AT&T UNIX.

BSD June 2, 1993 BSD

--------------
