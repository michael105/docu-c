--------------

BCMP(3) BSD Library Functions Manual BCMP(3)

**NAME**

**bcmp** — compare byte string

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <strings.h>**

*int*

**bcmp**\ (*const void *b1*, *const void *b2*, *size_t len*);

**DESCRIPTION**

The **bcmp**\ () function compares byte string *b1* against byte string
*b2*, returning zero if they are identical, non-zero otherwise. Both
strings are assumed to be *len* bytes long. Zero-length strings are
always identical.

The strings may overlap.

**SEE ALSO**

memcmp(3), strcasecmp(3), strcmp(3), strcoll(3), strxfrm(3),
timingsafe_bcmp(3)

**HISTORY**

A **bcmp**\ () function first appeared in 4.2BSD. Its prototype existed
previously in <*string.h*> before it was moved to <*strings.h*> for IEEE
Std 1003.1-2001 (‘‘POSIX.1’’) compliance.

BSD August 15, 2016 BSD

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

