--------------

SCTP_GENERIC_SENDMSG(2) BSD System Calls Manual SCTP_GENERIC_SENDMSG(2)

**NAME**

**sctp_generic_sendmsg sctp_generic_sendmsg_iov** — send data to a peer

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/sctp.h>**

*int*

**sctp_generic_sendmsg**\ (*int s*, *void *msg*, *int msglen*,
*struct sockaddr *to*, *socklen_t len*, *struct sctp_sndrcvinfo *sinfo*,
*int flags*);

*int*

**sctp_generic_sendmsg_iov**\ (*int s*, *struct iovec *iov*,
*int iovlen*, *struct sockaddr *to*, *struct sctp_sndrcvinfo *sinfo*,
*int flags*);

**DESCRIPTION**

**sctp_generic_sendmsg**\ () and **sctp_generic_sendmsg_iov**\ () are
the true system calls used by the sctp_sendmsg(3) and sctp_send(3)
function calls. These are more efficient since they are true system
calls but they are specific to FreeBSD and can be expected *not* to be
present on any other operating system. For detailed usage please see
either the sctp_send(3) or sctp_sendmsg(3) function calls.

**RETURN VALUES**

The call returns the number of bytes written on success and -1 upon
failure.

| **ERRORS**
| [EBADF]

The argument *s* is not a valid descriptor.

[ENOTSOCK]

The argument *s* is not a socket.

**SEE ALSO**

sctp_send(3), sctp_sendmsg(3), sctp_sendmsgx(3), sctp_sendx(3), sctp(4)

BSD October 30, 2007 BSD

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

