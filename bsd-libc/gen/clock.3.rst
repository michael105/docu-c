--------------

CLOCK(3) BSD Library Functions Manual CLOCK(3)

**NAME**

**clock** — determine processor time used

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <time.h>**

*clock_t*

**clock**\ (*void*);

**DESCRIPTION**

The **clock**\ () function determines the amount of processor time used
since the invocation of the calling process, measured in CLOCKS_PER_SECs
of a second.

**RETURN VALUES**

The **clock**\ () function returns the amount of time used unless an
error occurs, in which case the return value is −1.

**SEE ALSO**

getrusage(2), clocks(7)

**STANDARDS**

The **clock**\ () function conforms to ISO/IEC 9899:1990 (‘‘ISO C90’’).
However, Version 2 of the Single UNIX Specification (‘‘SUSv2’’) requires
CLOCKS_PER_SEC to be defined as one million. FreeBSD does not conform to
this requirement; changing the value would introduce binary
incompatibility and one million is still inadequate on modern
processors.

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

