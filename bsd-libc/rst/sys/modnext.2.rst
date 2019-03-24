--------------

MODNEXT(2) BSD System Calls Manual MODNEXT(2)

**NAME**

**modnext** — return the modid of the next kernel module

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/param.h>
#include <sys/module.h>**

*int*

**modnext**\ (*int modid*);

*int*

**modfnext**\ (*int modid*);

**DESCRIPTION**

The **modnext**\ () system call returns the modid of the next kernel
module (that is, the one after *modid*) or 0 if *modid* is the last
module in the list.

If the *modid* value is 0, then **modnext**\ () will return the modid of
the first module. The **modfnext**\ () system call must always be given
a valid modid.

**RETURN VALUES**

The **modnext**\ () system call returns the modid of the next module
(see *DESCRIPTION*) or 0. If an error occurs, *errno* is set to indicate
the error.

**ERRORS**

The only error set by **modnext**\ () is ENOENT, which is set when
*modid* refers to a kernel module that does not exist (is not loaded).

**SEE ALSO**

kldfind(2), kldfirstmod(2), kldload(2), kldnext(2), kldstat(2),
kldsym(2), kldunload(2), modfind(2), modstat(2), kld(4), kldstat(8)

**HISTORY**

The **kld** interface first appeared in FreeBSD 3.0.

BSD September 28, 2000 BSD

--------------
