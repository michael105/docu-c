--------------

SOCKETPAIR(2) BSD System Calls Manual SOCKETPAIR(2)

**NAME**

**socketpair** — create a pair of connected sockets

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/types.h>
#include <sys/socket.h>**

*int*

**socketpair**\ (*int domain*, *int type*, *int protocol*, *int *sv*);

**DESCRIPTION**

The **socketpair**\ () system call creates an unnamed pair of connected
sockets in the specified communications *domain*, of the specified
*type*, and using the optionally specified *protocol*. The descriptors
used in referencing the new sockets are returned in *sv*\ [0] and
*sv*\ [1]. The two sockets are indistinguishable.

The SOCK_CLOEXEC and SOCK_NONBLOCK flags in the *type* argument apply to
both descriptors.

**RETURN VALUES**

The **socketpair**\ () function returns the value 0 if successful;
otherwise the value −1 is returned and the global variable *errno* is
set to indicate the error.

**ERRORS**

The call succeeds unless:

[EMFILE]

Too many descriptors are in use by this process.

[EAFNOSUPPORT]

The specified address family is not supported on this machine.

[EPROTONOSUPPORT]

The specified protocol is not supported on this machine.

[EOPNOTSUPP]

The specified protocol does not support creation of socket pairs.

[EFAULT]

The address *sv* does not specify a valid part of the process address
space.

**SEE ALSO**

pipe(2), read(2), socket(2), write(2)

**STANDARDS**

The **socketpair**\ () system call conforms to IEEE Std 1003.1-2001
(‘‘POSIX.1’’) and IEEE Std 1003.1-2008 (‘‘POSIX.1’’).

**HISTORY**

The **socketpair**\ () system call appeared in 4.2BSD.

**BUGS**

This call is currently implemented only for the UNIX domain.

BSD February 10, 2018 BSD

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

