--------------

ALARM(3) BSD Library Functions Manual ALARM(3)

**NAME**

**alarm** — set signal timer alarm

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <unistd.h>**

*unsigned int*

**alarm**\ (*unsigned int seconds*);

**DESCRIPTION**

**This interface is made obsolete by** setitimer(\ **2**)\ **.**

The **alarm**\ () function sets a timer to deliver the signal SIGALRM to
the calling process after the specified number of *seconds*. If an alarm
has already been set with **alarm**\ () but has not been delivered,
another call to **alarm**\ () will supersede the prior call. The request
**alarm**\ (*0*) voids the current alarm and the signal SIGALRM will not
be delivered.

Due to setitimer(2) restriction the maximum number of *seconds* allowed
is 100000000.

**RETURN VALUES**

The return value of **alarm**\ () is the amount of time left on the
timer from a previous call to **alarm**\ (). If no alarm is currently
set, the return value is 0.

**SEE ALSO**

setitimer(2), sigaction(2), sigsuspend(2), signal(3), sleep(3),
ualarm(3), usleep(3)

**HISTORY**

An **alarm**\ () function appeared in Version 7 AT&T UNIX.

BSD April 19, 1994 BSD

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

