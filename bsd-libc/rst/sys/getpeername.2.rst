--------------

GETPEERNAME(2) BSD System Calls Manual GETPEERNAME(2)

**NAME**

**getpeername** — get name of connected peer

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/types.h>
#include <sys/socket.h>**

*int*

**getpeername**\ (*int s*, *struct sockaddr * restrict name*,
*socklen_t * restrict namelen*);

**DESCRIPTION**

The **getpeername**\ () system call returns the name of the peer
connected to socket *s*. The *namelen* argument should be initialized to
indicate the amount of space pointed to by *name*. On return it contains
the actual size of the name returned (in bytes). The name is truncated
if the buffer provided is too small.

**RETURN VALUES**

The **getpeername**\ () function returns the value 0 if successful;
otherwise the value −1 is returned and the global variable *errno* is
set to indicate the error.

**ERRORS**

The call succeeds unless:

[EBADF]

The argument *s* is not a valid descriptor.

[ECONNRESET]

The connection has been reset by the peer.

[EINVAL]

The value of the *namelen* argument is not valid.

[ENOTSOCK]

The argument *s* is a file, not a socket.

[ENOTCONN]

The socket is not connected.

[ENOBUFS]

Insufficient resources were available in the system to perform the
operation.

[EFAULT]

The *name* argument points to memory not in a valid part of the process
address space.

**SEE ALSO**

accept(2), bind(2), getsockname(2), socket(2)

**HISTORY**

The **getpeername**\ () system call appeared in 4.2BSD.

BSD June 4, 1993 BSD

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

