--------------

BZERO(3) BSD Library Functions Manual BZERO(3)

**NAME**

**bzero**, **explicit_bzero** — write zeroes to a byte string

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <strings.h>**

*void*

**bzero**\ (*void *b*, *size_t len*);

*void*

**explicit_bzero**\ (*void *b*, *size_t len*);

**DESCRIPTION**

The **bzero**\ () function writes *len* zero bytes to the string *b*. If
*len* is zero, **bzero**\ () does nothing.

The **explicit_bzero**\ () variant behaves the same, but will not be
removed by a compiler’s dead store optimization pass, making it useful
for clearing sensitive memory such as a password.

**SEE ALSO**

memset(3), swab(3)

**HISTORY**

A **bzero**\ () function appeared in 4.3BSD. Its prototype existed
previously in <*string.h*> before it was moved to <*strings.h*> for IEEE
Std 1003.1-2001 (‘‘POSIX.1’’) compliance.

The **explicit_bzero**\ () function first appeared in OpenBSD 5.5 and
FreeBSD 11.0.

IEEE Std 1003.1-2008 (‘‘POSIX.1’’) removes the specification of
**bzero**\ () and it is marked as LEGACY in IEEE Std 1003.1-2004
(‘‘POSIX.1’’). For portability with other systems new programs should
use memset(3).

BSD August 24, 2015 BSD

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

