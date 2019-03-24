--------------

SYNC(2) BSD System Calls Manual SYNC(2)

**NAME**

**sync** — schedule file system updates

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <unistd.h>**

*void*

**sync**\ (*void*);

**DESCRIPTION**

The **sync**\ () system call forces a write of dirty (modified) buffers
in the block buffer cache out to disk. The kernel keeps this information
in core to reduce the number of disk I/O transfers required by the
system. As information in the cache is lost after a system crash, a
**sync**\ () system call is issued frequently by the kernel process
syncer(4) (about every 30 seconds).

The fsync(2) system call may be used to synchronize individual file
descriptor attributes.

**SEE ALSO**

fsync(2), syncer(4), sync(8)

**HISTORY**

The **sync**\ () function appeared in Version 3 AT&T UNIX.

**BUGS**

The **sync**\ () system call may return before the buffers are
completely flushed.

BSD December 1, 2017 BSD

--------------
