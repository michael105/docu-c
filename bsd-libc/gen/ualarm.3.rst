--------------

UALARM(3) BSD Library Functions Manual UALARM(3)

**NAME**

**ualarm** — schedule signal after specified time

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <unistd.h>**

*useconds_t*

**ualarm**\ (*useconds_t microseconds*, *useconds_t interval*);

**DESCRIPTION**

**This is a simplified interface to** setitimer(\ **2**)\ **.**

The **ualarm**\ () function waits a count of *microseconds* before
asserting the terminating signal SIGALRM. System activity or time used
in processing the call may cause a slight delay.

If the *interval* argument is non-zero, the SIGALRM signal will be sent
to the process every *interval* microseconds after the timer expires
(e.g. after *microseconds* number of microseconds have passed).

Due to setitimer(2) restriction the maximum number of *microseconds* and
*interval* is limited to 100000000000000 (in case this value fits in the
unsigned integer).

**RETURN VALUES**

When the signal has successfully been caught, **ualarm**\ () returns the
amount of time left on the clock.

**NOTES**

A microsecond is 0.000001 seconds.

**SEE ALSO**

getitimer(2), setitimer(2), sigaction(2), sigsuspend(2), alarm(3),
signal(3), sleep(3), usleep(3)

**HISTORY**

The **ualarm**\ () function appeared in 4.3BSD.

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

