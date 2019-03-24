--------------

UNDELETE(2) BSD System Calls Manual UNDELETE(2)

**NAME**

**undelete** — attempt to recover a deleted file

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <unistd.h>**

*int*

**undelete**\ (*const char *path*);

**DESCRIPTION**

The **undelete**\ () system call attempts to recover the deleted file
named by *path*. Currently, this works only when the named object is a
whiteout in a union file system. The system call removes the whiteout
causing any objects in a lower layer of the union stack to become
visible once more.

Eventually, the **undelete**\ () functionality may be expanded to other
file systems able to recover deleted files such as the log-structured
file system.

**RETURN VALUES**

The **undelete**\ () function returns the value 0 if successful;
otherwise the value −1 is returned and the global variable *errno* is
set to indicate the error.

**ERRORS**

The **undelete**\ () succeeds unless:

[ENOTDIR]

A component of the path prefix is not a directory.

[ENAMETOOLONG]

A component of a pathname exceeded 255 characters, or an entire path
name exceeded 1023 characters.

[EEXIST]

The path does not reference a whiteout.

[ENOENT]

The named whiteout does not exist.

[EACCES]

Search permission is denied for a component of the path prefix.

[EACCES]

Write permission is denied on the directory containing the name to be
undeleted.

[ELOOP]

Too many symbolic links were encountered in translating the pathname.

[EPERM]

The directory containing the name is marked sticky, and the containing
directory is not owned by the effective user ID.

[EINVAL]

The last component of the path is ‘..’.

[EIO]

An I/O error occurred while updating the directory entry.

[EROFS]

The name resides on a read-only file system.

[EFAULT]

The *path* argument points outside the process’s allocated address
space.

**SEE ALSO**

unlink(2), mount_unionfs(8)

**HISTORY**

The **undelete**\ () system call first appeared in 4.4BSD−Lite.

BSD January 22, 2006 BSD

--------------

.. Copyright (c) 1990, 1991, 1993
..	The Regents of the University of California.  All rights reserved.
..
.. This code is derived from software contributed to Berkeley by
.. Chris Torek and the American National Standards Committee X3,
.. on Information Processing Systems.
..
.. Redistribution and use in source and binary forms, with or without
.. modification, are permitted provided that the following conditions
.. are met:
.. 1. Redistributions of source code must retain the above copyright
..    notice, this list of conditions and the following disclaimer.
.. 2. Redistributions in binary form must reproduce the above copyright
..    notice, this list of conditions and the following disclaimer in the
..    documentation and/or other materials provided with the distribution.
.. 3. Neither the name of the University nor the names of its contributors
..    may be used to endorse or promote products derived from this software
..    without specific prior written permission.
..
.. THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
.. ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
.. IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
.. ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
.. FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
.. DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
.. OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
.. HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
.. LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
.. OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
.. SUCH DAMAGE.

