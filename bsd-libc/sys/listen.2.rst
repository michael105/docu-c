--------------

LISTEN(2) BSD System Calls Manual LISTEN(2)

**NAME**

**listen** — listen for connections on a socket

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/socket.h>**

*int*

**listen**\ (*int s*, *int backlog*);

**DESCRIPTION**

To accept connections, a socket is first created with socket(2), a
willingness to accept incoming connections and a queue limit for
incoming connections are specified with **listen**\ (), and then the
connections are accepted with accept(2). The **listen**\ () system call
applies only to sockets of type SOCK_STREAM or SOCK_SEQPACKET.

The *backlog* argument defines the maximum length the queue of pending
connections may grow to. The real maximum queue length will be 1.5 times
more than the value specified in the *backlog* argument. A subsequent
**listen**\ () system call on the listening socket allows the caller to
change the maximum queue length using a new *backlog* argument. If a
connection request arrives with the queue full the client may receive an
error with an indication of ECONNREFUSED, or, in the case of TCP, the
connection will be silently dropped.

Current queue lengths of listening sockets can be queried using
netstat(1) command.

Note that before FreeBSD 4.5 and the introduction of the syncache, the
*backlog* argument also determined the length of the incomplete
connection queue, which held TCP sockets in the process of completing
TCP’s 3-way handshake. These incomplete connections are now held
entirely in the syncache, which is unaffected by queue lengths. Inflated
*backlog* values to help handle denial of service attacks are no longer
necessary.

The sysctl(3) MIB variable *kern.ipc.soacceptqueue* specifies a hard
limit on *backlog*; if a value greater than *kern.ipc.soacceptqueue* or
less than zero is specified, *backlog* is silently forced to
*kern.ipc.soacceptqueue*.

**INTERACTION WITH ACCEPT FILTERS**

When accept filtering is used on a socket, a second queue will be used
to hold sockets that have connected, but have not yet met their accept
filtering criteria. Once the criteria has been met, these sockets will
be moved over into the completed connection queue to be accept(2)ed. If
this secondary queue is full and a new connection comes in, the oldest
socket which has not yet met its accept filter criteria will be
terminated.

This secondary queue, like the primary listen queue, is sized according
to the *backlog* argument.

**RETURN VALUES**

The **listen**\ () function returns the value 0 if successful; otherwise
the value −1 is returned and the global variable *errno* is set to
indicate the error.

**ERRORS**

The **listen**\ () system call will fail if:

[EBADF]

The argument *s* is not a valid descriptor.

[EDESTADDRREQ]

The socket is not bound to a local address, and the protocol does not
support listening on an unbound socket.

[EINVAL]

The socket is already connected, or in the process of being connected.

[ENOTSOCK]

The argument *s* is not a socket.

[EOPNOTSUPP]

The socket is not of a type that supports the operation **listen**\ ().

**SEE ALSO**

netstat(1), accept(2), connect(2), socket(2), sysctl(3), sysctl(8),
accept_filter(9)

**HISTORY**

The **listen**\ () system call appeared in 4.2BSD. The ability to
configure the maximum *backlog* at run-time, and to use a negative
*backlog* to request the maximum allowable value, was introduced in
FreeBSD 2.2. The *kern.ipc.somaxconn* sysctl(3) has been replaced with
*kern.ipc.soacceptqueue* in FreeBSD 10.0 to prevent confusion about its
actual functionality. The original sysctl(3) *kern.ipc.somaxconn* is
still available but hidden from a sysctl(3) -a output so that existing
applications and scripts continue to work.

BSD August 18, 2016 BSD

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

