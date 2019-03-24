--------------

GETSID(2) BSD System Calls Manual GETSID(2)

**NAME**

**getsid** — get process session

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <unistd.h>**

*pid_t*

**getsid**\ (*pid_t pid*);

**DESCRIPTION**

The session ID of the process identified by *pid* is returned by
**getsid**\ (). If *pid* is zero, **getsid**\ () returns the session ID
of the current process.

**RETURN VALUES**

Upon successful completion, the **getsid**\ () system call returns the
session ID of the specified process; otherwise, it returns a value of -1
and sets errno to indicate an error.

**ERRORS**

The **getsid**\ () system call will succeed unless:

[ESRCH]

if there is no process with a process ID equal to *pid*.

Note that an implementation may restrict this system call to processes
within the same session ID as the calling process.

**SEE ALSO**

getpgid(2), getpgrp(2), setpgid(2), setsid(2), termios(4)

**HISTORY**

The **getsid**\ () system call appeared in FreeBSD 3.0. The
**getsid**\ () system call is derived from its usage in AT&T System V
UNIX.

BSD August 19, 1997 BSD

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

