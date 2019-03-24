--------------

GETFSSTAT(2) BSD System Calls Manual GETFSSTAT(2)

**NAME**

**getfsstat** — get list of all mounted file systems

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/param.h>
#include <sys/ucred.h>
#include <sys/mount.h>**

*int*

**getfsstat**\ (*struct statfs *buf*, *long bufsize*, *int mode*);

**DESCRIPTION**

The **getfsstat**\ () system call returns information about all mounted
file systems. The *buf* argument is a pointer to *statfs* structures, as
described in statfs(2).

Fields that are undefined for a particular file system are set to -1.
The buffer is filled with an array of *statfs* structures, one for each
mounted file system up to the byte count specified by *bufsize*. Note,
the *bufsize* argument is the number of bytes that *buf* can hold, not
the count of statfs structures it will hold.

If *buf* is given as NULL, **getfsstat**\ () returns just the number of
mounted file systems.

Normally *mode* should be specified as MNT_WAIT. If *mode* is set to
MNT_NOWAIT, **getfsstat**\ () will return the information it has
available without requesting an update from each file system. Thus, some
of the information will be out of date, but **getfsstat**\ () will not
block waiting for information from a file system that is unable to
respond. It will also skip any file system that is in the process of
being unmounted, even if the unmount would eventually fail.

**RETURN VALUES**

Upon successful completion, the number of *statfs* structures is
returned. Otherwise, -1 is returned and the global variable *errno* is
set to indicate the error.

**ERRORS**

The **getfsstat**\ () system call fails if one or more of the following
are true:

[EFAULT]

The *buf* argument points to an invalid address.

[EINVAL]

*mode* is set to a value other than MNT_WAIT or MNT_NOWAIT.

[EIO]

An I/O error occurred while reading from or writing to the file system.

**SEE ALSO**

statfs(2), fstab(5), mount(8)

**HISTORY**

The **getfsstat**\ () system call first appeared in 4.4BSD.

BSD December 27, 2016 BSD

--------------
