--------------

BSTRING(3) BSD Library Functions Manual BSTRING(3)

**NAME**

**bcmp**, **bcopy**, **bzero**, **memccpy**, **memchr**, **memcmp**,
**memcpy**, **memmove**, **memset** — byte string operations

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <string.h>**

*int*

**bcmp**\ (*const void *b1*, *const void *b2*, *size_t len*);

*void*

**bcopy**\ (*const void *src*, *void *dst*, *size_t len*);

*void*

**bzero**\ (*void *b*, *size_t len*);

*void \**

**memchr**\ (*const void *b*, *int c*, *size_t len*);

*int*

**memcmp**\ (*const void *b1*, *const void *b2*, *size_t len*);

*void \**

**memccpy**\ (*void *dst*, *const void *src*, *int c*, *size_t len*);

*void \**

**memcpy**\ (*void *dst*, *const void *src*, *size_t len*);

*void \**

**memmove**\ (*void *dst*, *const void *src*, *size_t len*);

*void \**

**memset**\ (*void *b*, *int c*, *size_t len*);

**DESCRIPTION**

These functions operate on variable length strings of bytes. They do not
check for terminating null bytes as the routines listed in string(3) do.

See the specific manual pages for more information.

**SEE ALSO**

bcmp(3), bcopy(3), bzero(3), memccpy(3), memchr(3), memcmp(3),
memcpy(3), memmove(3), memset(3)

**STANDARDS**

The functions **memchr**\ (), **memcmp**\ (), **memcpy**\ (),
**memmove**\ (), and **memset**\ () conform to ISO/IEC 9899:1990
(‘‘ISO C90’’).

**HISTORY**

The functions **bzero**\ () and **memccpy**\ () appeared in 4.3BSD; the
functions **bcmp**\ (), **bcopy**\ (), appeared in 4.2BSD.

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

