--------------

CLOCK_GETCPUCLOCKID(3) BSD Library Functions Manual
CLOCK_GETCPUCLOCKID(3)

**NAME**

**clock_getcpuclockid** — access a process CPU-time clock

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <time.h>**

*int*

**clock_getcpuclockid**\ (*pid_t pid*, *clockid_t *clock_id*);

**DESCRIPTION**

The **clock_getcpuclockid**\ () returns the clock ID of the CPU-time
clock of the process specified by *pid*. If the process described by
*pid* exists and the calling process has permission, the clock ID of
this clock will be returned in *clock_id*.

If *pid* is zero, the **clock_getcpuclockid**\ () function returns the
clock ID of the CPU-time clock of the process making the call, in
*clock_id*.

**RETURN VALUES**

Upon successful completion, **clock_getcpuclockid**\ () returns zero;
otherwise, an error number is returned to indicate the error.

**ERRORS**

The **clock_getcpuclockid**\ () function will fail if:

[EPERM]

The requesting process does not have permission to access the CPU-time
clock for the process.

[ESRCH]

No process can be found corresponding to the process specified by *pid*.

**SEE ALSO**

clock_gettime(2)

**STANDARDS**

The **clock_getcpuclockid**\ () function conforms to IEEE Std
1003.1-2001 (‘‘POSIX.1’’).

**HISTORY**

The **clock_getcpuclockid**\ () function first appeared in FreeBSD 10.0.

**AUTHORS**

David Xu <*davidxu@FreeBSD.org*>

BSD August 21, 2012 BSD

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

