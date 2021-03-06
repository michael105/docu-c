--------------

MEMCCPY(3) BSD Library Functions Manual MEMCCPY(3)

**NAME**

**memccpy** — copy string until character found

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <string.h>**

*void \**

**memccpy**\ (*void *dst*, *const void *src*, *int c*, *size_t len*);

**DESCRIPTION**

The **memccpy**\ () function copies bytes from string *src* to string
*dst*. If the character *c* (as converted to an *unsigned char*) occurs
in the string *src*, the copy stops and a pointer to the byte after the
copy of *c* in the string *dst* is returned. Otherwise, *len* bytes are
copied, and a NULL pointer is returned.

**SEE ALSO**

bcopy(3), memcpy(3), memmove(3), strcpy(3)

**HISTORY**

The **memccpy**\ () function first appeared in 4.4BSD.

BSD June 9, 1993 BSD

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

