--------------

TCSETSID(3) BSD Library Functions Manual TCSETSID(3)

**NAME**

**tcsetsid** — set session ID associated with a controlling terminal

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/types.h>
#include <termios.h>**

*int*

**tcsetsid**\ (*int fd*, *pid_t pid*);

**DESCRIPTION**

The **tcsetsid**\ () function sets associates a session identified by
*pid* with a controlling terminal specified by *fd*.

This implementation only allows the controlling terminal to be changed
by the session leader itself. This implies that *pid* always has to be
equal to the process ID.

It is unsupported to associate with a terminal that already has an
associated session. Conversely, it is also unsupported to associate to a
terminal when the session is already associated with a different
terminal.

**ERRORS**

If an error occurs, **tcsetsid**\ () returns -1 and the global variable
*errno* is set to indicate the error, as follows:

[EBADF]

The *fd* argument is not a valid file descriptor.

[ENOTTY]

The file descriptor represented by *fd* is not a terminal.

[EINVAL]

The *pid* argument is not equal to the session ID of the calling
process.

[EPERM]

The calling process is not a session leader.

[EPERM]

The session already has an associated terminal or the terminal already
has an associated session.

**SEE ALSO**

getsid(2), setsid(2), tcgetpgrp(3), tcgetsid(3)

**HISTORY**

A **tcsetsid**\ () function first appeared in QNX. It does not comply to
any standard.

BSD May 4, 2009 BSD

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

