--------------

RMDIR(2) BSD System Calls Manual RMDIR(2)

**NAME**

**rmdir** — remove a directory file

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <unistd.h>**

*int*

**rmdir**\ (*const char *path*);

**DESCRIPTION**

The **rmdir**\ () system call removes a directory file whose name is
given by *path*. The directory must not have any entries other than ‘.’
and ‘..’.

**RETURN VALUES**

The **rmdir**\ () function returns the value 0 if successful; otherwise
the value −1 is returned and the global variable *errno* is set to
indicate the error.

**ERRORS**

The named file is removed unless:

[ENOTDIR]

A component of the path is not a directory.

[ENAMETOOLONG]

A component of a pathname exceeded 255 characters, or an entire path
name exceeded 1023 characters.

[ENOENT]

The named directory does not exist.

[ELOOP]

Too many symbolic links were encountered in translating the pathname.

[ENOTEMPTY]

The named directory contains files other than ‘.’ and ‘..’ in it.

[EACCES]

Search permission is denied for a component of the path prefix.

[EACCES]

Write permission is denied on the directory containing the link to be
removed.

[EPERM]

The directory to be removed has its immutable, undeletable or
append-only flag set, see the chflags(2) manual page for more
information.

[EPERM]

The parent directory of the directory to be removed has its immutable or
append-only flag set.

[EPERM]

The directory containing the directory to be removed is marked sticky,
and neither the containing directory nor the directory to be removed are
owned by the effective user ID.

[EINVAL]

The last component of the path is ‘.’ or ‘..’.

[EBUSY]

The directory to be removed is the mount point for a mounted file
system.

[EIO]

An I/O error occurred while deleting the directory entry or deallocating
the inode.

[EROFS]

The directory entry to be removed resides on a read-only file system.

[EFAULT]

The *path* argument points outside the process’s allocated address
space.

**SEE ALSO**

mkdir(2), unlink(2)

**HISTORY**

The **rmdir**\ () system call appeared in 4.2BSD.

BSD December 9, 2006 BSD

--------------
