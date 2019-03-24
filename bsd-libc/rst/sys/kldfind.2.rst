--------------

KLDFIND(2) BSD System Calls Manual KLDFIND(2)

**NAME**

**kldfind** — returns the fileid of a kld file

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/param.h>
#include <sys/linker.h>**

*int*

**kldfind**\ (*const char *file*);

**DESCRIPTION**

The **kldfind**\ () system call returns the fileid of the kld file
referenced by *file*.

**RETURN VALUES**

The **kldfind**\ () system call returns the fileid of the kld file
referenced by *file*. Upon error, **kldfind**\ () returns -1 and sets
*errno* to indicate the error.

**ERRORS**

*errno* is set to the following if **kldfind**\ () fails:

[EFAULT]

The data required for this operation could not be read from the kernel
space.

[ENOENT]

The file specified is not loaded in the kernel.

**SEE ALSO**

kldfirstmod(2), kldload(2), kldnext(2), kldstat(2), kldsym(2),
kldunload(2), modfind(2), modfnext(2), modnext(2), modstat(2), kld(4),
kldstat(8)

**HISTORY**

The **kld** interface first appeared in FreeBSD 3.0.

BSD March 3, 1999 BSD

--------------
