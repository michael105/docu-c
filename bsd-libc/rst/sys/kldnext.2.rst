--------------

KLDNEXT(2) BSD System Calls Manual KLDNEXT(2)

**NAME**

**kldnext** — return the fileid of the next kld file

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/param.h>
#include <sys/linker.h>**

*int*

**kldnext**\ (*int fileid*);

**DESCRIPTION**

The **kldnext**\ () system call returns the fileid of the next kld file
(that is, the one after *fileid*) or 0 if *fileid* is the last file
loaded. To get the fileid of the first kld file, pass *fileid* of 0 to
**kldnext**\ ().

**RETURN VALUES**

The **kldnext**\ () system call returns the fileid of the next kld file
or 0 if successful. Otherwise **kldnext**\ () returns the value −1 and
sets the global variable *errno* to indicate the error.

**ERRORS**

The only error set by **kldnext**\ () is ENOENT, which is set when
*fileid* refers to a kld file that does not exist (is not loaded).

**SEE ALSO**

kldfind(2), kldfirstmod(2), kldload(2), kldstat(2), kldsym(2),
kldunload(2), modfind(2), modfnext(2), modnext(2), modstat(2), kld(4),
kldstat(8)

**HISTORY**

The **kld** interface first appeared in FreeBSD 3.0.

BSD February 22, 2006 BSD

--------------
