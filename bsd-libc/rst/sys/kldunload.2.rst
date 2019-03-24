--------------

KLDUNLOAD(2) BSD System Calls Manual KLDUNLOAD(2)

**NAME**

**kldunload**, **kldunloadf** — unload kld files

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/param.h>
#include <sys/linker.h>**

*int*

**kldunload**\ (*int fileid*);

*int*

**kldunloadf**\ (*int fileid*, *int flags*);

**DESCRIPTION**

The **kldunload**\ () system call unloads a kld file from the kernel
that was previously linked via kldload(2).

The **kldunloadf**\ () system call accepts an additional flags argument,
which may be one of LINKER_UNLOAD_NORMAL, giving the same behavior as
**kldunload**\ (), or LINKER_UNLOAD_FORCE, which causes the unload to
ignore a failure to quiesce the module.

**RETURN VALUES**

Upon successful completion, the value 0 is returned; otherwise the
value −1 is returned and the global variable *errno* is set to indicate
the error.

**ERRORS**

The file referred to by *fileid* is unloaded unless:

[EPERM]

You do not have access to unlink the file from the kernel.

[ENOENT]

The file was not found.

[EBUSY]

You attempted to unload a file linked by the kernel.

[EINVAL]

The **kldunloadf**\ () system call was passed invalid flags.

**SEE ALSO**

kldfind(2), kldfirstmod(2), kldload(2), kldnext(2), kldstat(2),
kldsym(2), modfind(2), modfnext(2), modnext(2), modstat(2), kld(4),
kldunload(8)

**HISTORY**

The **kld** interface first appeared in FreeBSD 3.0.

BSD December 25, 2008 BSD

--------------
