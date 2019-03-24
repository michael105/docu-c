--------------

TIMESPEC_GET(3) BSD Library Functions Manual TIMESPEC_GET(3)

**NAME**

**timespec_get** — get current calendar time

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <time.h>**

*int*

**timespec_get**\ (*struct timespec *ts*, *int base*);

**DESCRIPTION**

The **timespec_get** function sets the interval pointed to by *ts* to
hold the current calendar time based on the specified time base in
*base*.

The base TIME_UTC returns the time since the epoch. This time is
expressed in seconds and nanoseconds since midnight (0 hour), January 1,
1970. In FreeBSD, this corresponds to CLOCK_REALTIME.

**RETURN VALUES**

The **timespec_get** function returns the passed value of *base* if
successful, otherwise 0 on failure.

**SEE ALSO**

gettimeofday(2), clock_gettime(2), time(3)

**STANDARDS**

The **timespec_get** function with a *base* of TIME_UTC conforms to
ISO/IEC 9899:2011 (‘‘ISO C11’’).

**HISTORY**

This interface first appeared in FreeBSD 12.

**AUTHORS**

| Kamil Rytarowski <*kamil@NetBSD.org*>
| Warner Losh <*imp@FreeBSD.org*>

BSD August 10, 2018 BSD

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

