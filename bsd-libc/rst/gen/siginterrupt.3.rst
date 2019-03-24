--------------

SIGINTERRUPT(3) BSD Library Functions Manual SIGINTERRUPT(3)

**NAME**

**siginterrupt** — allow signals to interrupt system calls

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <signal.h>**

*int*

**siginterrupt**\ (*int sig*, *int flag*);

**DESCRIPTION**

The **siginterrupt**\ () function is used to change the system call
restart behavior when a system call is interrupted by the specified
signal. If the flag is false (0), then system calls will be restarted if
they are interrupted by the specified signal and no data has been
transferred yet. System call restart has been the default behavior since
4.2BSD, and is the default behaviour for signal(3) on FreeBSD.

If the flag is true (1), then restarting of system calls is disabled. If
a system call is interrupted by the specified signal and no data has
been transferred, the system call will return −1 with the global
variable *errno* set to EINTR. Interrupted system calls that have
started transferring data will return the amount of data actually
transferred. System call interrupt is the signal behavior found on
4.1BSD and AT&T System V UNIX systems.

Note that the new 4.2BSD signal handling semantics are not altered in
any other way. Most notably, signal handlers always remain installed
until explicitly changed by a subsequent sigaction(2) call, and the
signal mask operates as documented in sigaction(2). Programs may switch
between restartable and interruptible system call operation as often as
desired in the execution of a program.

Issuing a **siginterrupt**\ (*3*) call during the execution of a signal
handler will cause the new action to take place on the next signal to be
caught.

**NOTES**

This library routine uses an extension of the sigaction(2) system call
that is not available in 4.2BSD, hence it should not be used if backward
compatibility is needed.

**RETURN VALUES**

The **siginterrupt**\ () function returns the value 0 if successful;
otherwise the value −1 is returned and the global variable *errno* is
set to indicate the error.

**ERRORS**

The **siginterrupt**\ () call fails if:

[EINVAL]

The *sig* argument is not a valid signal number.

**SEE ALSO**

sigaction(2), sigprocmask(2), sigsuspend(2), signal(3)

**HISTORY**

The **siginterrupt**\ () function appeared in 4.3BSD.

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

