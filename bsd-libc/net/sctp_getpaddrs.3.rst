--------------

SCTP_GETPADDRS(3) BSD Library Functions Manual SCTP_GETPADDRS(3)

**NAME**

**sctp_getpaddrs**, **sctp_getladdrs** — return a list of addresses to
the caller

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/sctp.h>**

*int*

**sctp_getpaddrs**\ (*int s*, *sctp_assoc_t asocid*,
*struct sockaddr **addrs*);

*int*

**sctp_getladdrs**\ (*int s*, *sctp_assoc_t asocid*,
*struct sockaddr **addrs*);

**DESCRIPTION**

The **sctp_getpaddrs**\ () function is used to get the list of the peers
addresses. The **sctp_getladdrs**\ () function is used to get the list
of the local addresses. The association of interest is identified by the
*asocid* argument. The addresses are returned in a newly allocated array
of socket addresses returned in the argument *addrs* upon success.

After the caller is finished, the function **sctp_freepaddrs**\ () or
**sctp_freeladdrs**\ () should be used to release the memory allocated
by these calls.

**RETURN VALUES**

The call returns -1 upon failure and a count of the number of addresses
returned in *addrs* upon success.

**ERRORS**

The functions can return the following errors:

[EINVAL]

An address listed has an invalid family or no addresses were provided.

[ENOMEM]

The call cannot allocate memory to hold the socket addresses.

[EBADF]

The argument *s* is not a valid descriptor.

[ENOTSOCK]

The argument *s* is not a socket.

**SEE ALSO**

getsockopt(2), sctp_freeladdrs(3), sctp_freepaddrs(3), sctp(4)

BSD December 15, 2006 BSD

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

