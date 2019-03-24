--------------

MEMMEM(3) BSD Library Functions Manual MEMMEM(3)

**NAME**

**memmem** — locate a byte substring in a byte string

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <string.h>**

*void \**

**memmem**\ (*const void *big*, *size_t big_len*, *const void *little*,
*size_t little_len*);

**DESCRIPTION**

The **memmem**\ () function locates the first occurrence of the byte
string *little* in the byte string *big*.

**RETURN VALUES**

If *little_len* is zero *big* is returned (that is, an empty little is
deemed to match at the beginning of big); if *little* occurs nowhere in
*big*, NULL is returned; otherwise a pointer to the first character of
the first occurrence of *little* is returned.

**SEE ALSO**

memchr(3), strchr(3), strstr(3)

**CONFORMING TO**

**memmem**\ () is a GNU extension.

**HISTORY**

The **memmem**\ () function first appeared in FreeBSD 6.0. It was
replaced with an optimized O(n) implementation from the musl libc
project in FreeBSD 12.0. Pascal Gloor <*pascal.gloor@spale.com*>
provided this man page along with the previous implementation.

**BUGS**

This function was broken in Linux libc up to and including version 5.0.9
and in GNU libc prior to version 2.1. Prior to FreeBSD 11.0 **memmem**
returned NULL when *little_len* equals 0.

BSD March 17, 2017 BSD

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

