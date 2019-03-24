--------------

MEMCHR(3) BSD Library Functions Manual MEMCHR(3)

**NAME**

**memchr** — locate byte in byte string

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <string.h>**

*void \**

**memchr**\ (*const void *b*, *int c*, *size_t len*);

*void \**

**memrchr**\ (*const void *b*, *int c*, *size_t len*);

**DESCRIPTION**

The **memchr**\ () function locates the first occurrence of *c*
(converted to an *unsigned char*) in string *b*.

The **memrchr**\ () function behaves like **memchr**\ (), except that it
locates the last occurrence of *c* in string *b*.

**RETURN VALUES**

The **memchr**\ () and **memrchr**\ () functions return a pointer to the
byte located, or NULL if no such byte exists within *len* bytes.

**SEE ALSO**

memmem(3), strchr(3), strcspn(3), strpbrk(3), strrchr(3), strsep(3),
strspn(3), strstr(3), strtok(3), wmemchr(3)

**STANDARDS**

The **memchr**\ () function conforms to ISO/IEC 9899:1990 (‘‘ISO C90’’).

The **memrchr**\ () function is a GNU extension and conforms to no
standard.

**HISTORY**

The **memrchr**\ () function first appeared in GNU libc 2.1.91, this
implementation first appeared in FreeBSD 6.4, coming from OpenBSD 4.3.

BSD April 9, 2008 BSD

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

