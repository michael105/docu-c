--------------

ISSETUGID(2) BSD System Calls Manual ISSETUGID(2)

**NAME**

**issetugid** — is current process tainted by uid or gid changes

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <unistd.h>**

*int*

**issetugid**\ (*void*);

**DESCRIPTION**

The **issetugid**\ () system call returns 1 if the process environment
or memory address space is considered ‘‘tainted’’, and returns 0
otherwise.

A process is tainted if it was created as a result of an execve(2)
system call which had either of the setuid or setgid bits set (and extra
privileges were given as a result) or if it has changed any of its real,
effective or saved user or group ID’s since it began execution.

This system call exists so that library routines (eg: libc, libtermcap)
can reliably determine if it is safe to use information that was
obtained from the user, in particular the results from getenv(3) should
be viewed with suspicion if it is used to control operation.

A ‘‘tainted’’ status is inherited by child processes as a result of the
fork(2) system call (or other library code that calls fork, such as
popen(3)).

It is assumed that a program that clears all privileges as it prepares
to execute another will also reset the environment, hence the
‘‘tainted’’ status will not be passed on. This is important for programs
such as su(1) which begin setuid but need to be able to create an
untainted process.

**ERRORS**

The **issetugid**\ () system call is always successful, and no return
value is reserved to indicate an error.

**SEE ALSO**

execve(2), fork(2), setegid(2), seteuid(2), setgid(2), setregid(2),
setreuid(2), setuid(2)

**HISTORY**

The **issetugid**\ () system call first appeared in OpenBSD 2.0 and was
also implemented in FreeBSD 3.0.

BSD August 25, 1996 BSD

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

