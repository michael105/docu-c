--------------

REVOKE(2) BSD System Calls Manual REVOKE(2)

**NAME**

**revoke** — revoke file access

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <unistd.h>**

*int*

**revoke**\ (*const char *path*);

**DESCRIPTION**

The **revoke**\ () system call invalidates all current open file
descriptors in the system for the file named by *path*. Subsequent
operations on any such descriptors fail, with the exceptions that a
**read**\ () from a character device file which has been revoked returns
a count of zero (end of file), and a **close**\ () system call will
succeed. If the file is a special file for a device which is open, the
device close function is called as if all open references to the file
had been closed using a special close method which does not block.

Access to a file may be revoked only by its owner or the super user. The
**revoke**\ () system call is currently supported only for block and
character special device files. It is normally used to prepare a
terminal device for a new login session, preventing any access by a
previous user of the terminal.

**RETURN VALUES**

The **revoke**\ () function returns the value 0 if successful; otherwise
the value −1 is returned and the global variable *errno* is set to
indicate the error.

**ERRORS**

Access to the named file is revoked unless one of the following:

[ENOTDIR]

A component of the path prefix is not a directory.

[ENAMETOOLONG]

A component of a pathname exceeded 255 characters, or an entire path
name exceeded 1024 characters.

[ENOENT]

The named file or a component of the path name does not exist.

[EACCES]

Search permission is denied for a component of the path prefix.

[ELOOP]

Too many symbolic links were encountered in translating the pathname.

[EFAULT]

The *path* argument points outside the process’s allocated address
space.

[EINVAL]

The implementation does not support the **revoke**\ () operation on the
named file.

[EPERM]

The caller is neither the owner of the file nor the super user.

**SEE ALSO**

revoke(1), close(2)

**HISTORY**

The **revoke**\ () system call first appeared in 4.3BSD−Reno.

**BUGS**

The non-blocking close method is only correctly implemented for terminal
devices.

BSD Jan 25, 2016 BSD

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

