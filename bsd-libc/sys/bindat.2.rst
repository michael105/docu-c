--------------

BINDAT(2) BSD System Calls Manual BINDAT(2)

**NAME**

**bindat** — assign a local protocol address to a socket

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/types.h>
#include <sys/socket.h>**

**#include <fcntl.h>**

*int*

**bindat**\ (*int fd*, *int s*, *const struct sockaddr *addr*,
*socklen_t addrlen*);

**DESCRIPTION**

The **bindat**\ () system call assigns the local protocol address to a
socket. When passed the special value AT_FDCWD in the *fd* parameter,
the behavior is identical to a call to bind(2). Otherwise,
**bindat**\ () works like the bind(2) system call with two exceptions:

1.

It is limited to sockets in the PF_LOCAL domain.

2.

If the file path stored in the *sun_path* field of the sockaddr_un
structure is a relative path, it is located relative to the directory
associated with the file descriptor *fd*.

**RETURN VALUES**

The **bindat**\ () function returns the value 0 if successful; otherwise
the value −1 is returned and the global variable *errno* is set to
indicate the error.

**ERRORS**

The **bindat**\ () system call may fail with the same errors as the
bind(2) system call or with the following errors:

[EBADF]

The *sun_path* field does not specify an absolute path and the *fd*
argument is neither AT_FDCWD nor a valid file descriptor.

[ENOTDIR]

The *sun_path* field is not an absolute path and *fd* is neither
AT_FDCWD nor a file descriptor associated with a directory.

**SEE ALSO**

bind(2), connectat(2), socket(2), unix(4)

**AUTHORS**

The **bindat** was developed by Pawel Jakub Dawidek
<*pawel@dawidek.net*> under sponsorship from the FreeBSD Foundation.

BSD February 13, 2013 BSD

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

