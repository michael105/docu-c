--------------

KLDFIRSTMOD(2) BSD System Calls Manual KLDFIRSTMOD(2)

**NAME**

**kldfirstmod** — return first module id from the kld file specified

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/param.h>
#include <sys/linker.h>**

*int*

**kldfirstmod**\ (*int fileid*);

**DESCRIPTION**

The **kldfirstmod**\ () system call returns the module id pertaining to
the first module referenced by *fileid*.

**RETURN VALUES**

The **kldfirstmod**\ () will return the id of the first module
referenced by *fileid* or 0 if there are no references.

| **ERRORS**
| [ENOENT]

The kld file referenced by *fileid* was not found.

**SEE ALSO**

kldfind(2), kldload(2), kldnext(2), kldstat(2), kldsym(2), kldunload(2),
modfind(2), modfnext(2), modnext(2), modstat(2), kld(4), kldstat(8)

**HISTORY**

The **kld** interface first appeared in FreeBSD 3.0.

BSD March 3, 1999 BSD

--------------
