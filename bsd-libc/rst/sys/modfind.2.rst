--------------

MODFIND(2) BSD System Calls Manual MODFIND(2)

**NAME**

**modfind** — returns the modid of a kernel module

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/param.h>
#include <sys/module.h>**

*int*

**modfind**\ (*const char *modname*);

**DESCRIPTION**

The **modfind**\ () system call returns the modid of the kernel module
referenced by *modname*.

**RETURN VALUES**

The **modfind**\ () system call returns the modid of the kernel module
referenced by *modname*. Upon error, **modfind**\ () returns -1 and sets
*errno* to indicate the error.

**ERRORS**

*errno* is set to the following if **modfind**\ () fails:

[EFAULT]

The data required for this operation could not be read from the kernel
space.

[ENOENT]

The file specified is not loaded in the kernel.

**SEE ALSO**

kldfind(2), kldfirstmod(2), kldload(2), kldnext(2), kldstat(2),
kldsym(2), kldunload(2), modfnext(2), modnext(2), modstat(2), kld(4),
kldstat(8)

**HISTORY**

The **kld** interface first appeared in FreeBSD 3.0.

BSD September 28, 2000 BSD

--------------
