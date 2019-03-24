--------------

SETFIB(2) BSD System Calls Manual SETFIB(2)

**NAME**

**setfib** — set the default FIB (routing table) for the calling process

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/socket.h>**

*int*

**setfib**\ (*int fib*);

**DESCRIPTION**

The **setfib**\ () system call sets the associated fib for all sockets
opened subsequent to the call, to be that of the argument *fib*. The
*fib* argument must be greater than or equal to 0 and less than the
current system maximum which may be retrieved by the *net.fibs* sysctl.
The system maximum is set in the kernel configuration file with

**options ROUTETABLES=**\ *N*

or in */boot/loader.conf* with

net.fibs="*N*"

where *N* is an integer. This maximum is capped at 65536 due to the
implementation storing the fib number in a 16-bit field in the mbuf(9)
packet header, however it is not suggested that one use such a large
number as memory is allocated for every FIB regardless of whether it is
used, and there are places where all FIBs are iterated over.

The default fib of the process will be applied to all protocol families
that support multiple fibs, and ignored by those that do not. The
default fib for a process may be overridden for a socket with the use of
the SO_SETFIB socket option.

**RETURN VALUES**

The **setfib**\ () function returns the value 0 if successful; otherwise
the value −1 is returned and the global variable *errno* is set to
indicate the error.

**ERRORS**

The **setfib**\ () system call will fail and no action will be taken and
return EINVAL if the *fib* argument is greater than the current system
maximum.

**SEE ALSO**

setfib(1), setsockopt(2)

**STANDARDS**

The **setfib**\ () system call is a FreeBSD extension however similar
extensions have been added to many other UNIX style kernels.

**HISTORY**

The **setfib**\ () function appeared in FreeBSD 7.1.

BSD March 19, 2012 BSD

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

