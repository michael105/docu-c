--------------

KLDLOAD(2) BSD System Calls Manual KLDLOAD(2)

**NAME**

**kldload** — load KLD files into the kernel

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/param.h>
#include <sys/linker.h>**

*int*

**kldload**\ (*const char *file*);

**DESCRIPTION**

The **kldload**\ () system call loads a kld file into the kernel using
the kernel linker.

**RETURN VALUES**

The **kldload**\ () system call returns the fileid of the kld file which
was loaded into the kernel. If an error occurs, **kldload**\ () will
return -1 and set *errno* to indicate the error.

**ERRORS**

The named file is loaded unless:

[EPERM]

You do not have access to read the file or link it with the kernel. You
should be the root user to be able to use the **kld** system calls.

[EFAULT]

Bad address encountered when adding kld info into the kernel space.

[ENOMEM]

There is no memory to load the file into the kernel.

[ENOENT]

The file was not found.

[ENOEXEC]

The file format of *file* was unrecognized.

[EEXIST]

The supplied *file* has already been loaded.

**SEE ALSO**

kldfind(2), kldfirstmod(2), kldnext(2), kldstat(2), kldsym(2),
kldunload(2), modfind(2), modfnext(2), modnext(2), modstat(2), kld(4),
kldload(8)

**HISTORY**

The **kld** interface first appeared in FreeBSD 3.0.

BSD March 3, 1999 BSD

--------------
