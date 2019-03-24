--------------

READLINK(2) BSD System Calls Manual READLINK(2)

**NAME**

**readlink**, **readlinkat** — read value of a symbolic link

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <unistd.h>**

*ssize_t*

**readlink**\ (*const char *restrict path*, *char *restrict buf*,
*size_t bufsiz*);

*ssize_t*

**readlinkat**\ (*int fd*, *const char *restrict path*,
*char *restrict buf*, *size_t bufsize*);

**DESCRIPTION**

The **readlink**\ () system call places the contents of the symbolic
link *path* in the buffer *buf*, which has size *bufsiz*. The
**readlink**\ () system call does not append a NUL character to *buf*.

The **readlinkat**\ () system call is equivalent to **readlink**\ ()
except in the case where *path* specifies a relative path. In this case
the symbolic link whose content is read relative to the directory
associated with the file descriptor *fd* instead of the current working
directory. If **readlinkat**\ () is passed the special value AT_FDCWD in
the *fd* parameter, the current working directory is used and the
behavior is identical to a call to **readlink**\ ().

**RETURN VALUES**

The call returns the count of characters placed in the buffer if it
succeeds, or a −1 if an error occurs, placing the error code in the
global variable *errno*.

**ERRORS**

The **readlink**\ () system call will fail if:

[ENOTDIR]

A component of the path prefix is not a directory.

[ENAMETOOLONG]

A component of a pathname exceeded 255 characters, or an entire path
name exceeded 1023 characters.

[ENOENT]

The named file does not exist.

[EACCES]

Search permission is denied for a component of the path prefix.

[ELOOP]

Too many symbolic links were encountered in translating the pathname.

[EINVAL]

The named file is not a symbolic link.

[EIO]

An I/O error occurred while reading from the file system.

[EFAULT]

The *buf* argument extends outside the process’s allocated address
space.

In addition to the errors returned by the **readlink**\ (), the
**readlinkat**\ () may fail if:

[EBADF]

The *path* argument does not specify an absolute path and the *fd*
argument is neither AT_FDCWD nor a valid file descriptor open for
searching.

[ENOTDIR]

The *path* argument is not an absolute path and *fd* is neither AT_FDCWD
nor a file descriptor associated with a directory.

**SEE ALSO**

lstat(2), stat(2), symlink(2), symlink(7)

**STANDARDS**

The **readlinkat**\ () system call follows The Open Group Extended API
Set 2 specification.

**HISTORY**

The **readlink**\ () system call appeared in 4.2BSD. The
**readlinkat**\ () system call appeared in FreeBSD 8.0.

BSD April 10, 2008 BSD

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

