--------------

SIGSETMASK(2) BSD System Calls Manual SIGSETMASK(2)

**NAME**

**sigsetmask**, **sigblock** — manipulate current signal mask

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <signal.h>**

*int*

**sigsetmask**\ (*int mask*);

*int*

**sigblock**\ (*int mask*);

*int*

**sigmask**\ (*int signum*);

**DESCRIPTION**

**This interface is made obsolete by:** sigprocmask(2).

The **sigsetmask**\ () function sets the current signal mask to the
specified *mask*. Signals are blocked from delivery if the corresponding
bit in *mask* is a 1. The **sigblock**\ () function adds the signals in
the specified *mask* to the current signal mask, rather than overwriting
it as **sigsetmask**\ () does. The macro **sigmask**\ () is provided to
construct the mask for a given *signum*.

The system quietly disallows SIGKILL or SIGSTOP to be blocked.

**RETURN VALUES**

The **sigblock**\ () and **sigsetmask**\ () functions return the
previous set of masked signals.

**SEE ALSO**

kill(2), sigaction(2), sigprocmask(2), sigsuspend(2), sigvec(2),
sigsetops(3)

**HISTORY**

The **sigsetmask**\ () and **sigblock**\ () functions first appeared in
4.2BSD and have been deprecated.

BSD June 2, 1993 BSD

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

