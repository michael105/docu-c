--------------

MBSINIT(3) BSD Library Functions Manual MBSINIT(3)

**NAME**

**mbsinit** — determine conversion object status

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <wchar.h>**

*int*

**mbsinit**\ (*const mbstate_t *ps*);

**DESCRIPTION**

The **mbsinit**\ () function determines whether the *mbstate_t* object
pointed to by *ps* describes an initial conversion state.

**RETURN VALUES**

The **mbsinit**\ () function returns non-zero if *ps* is NULL or
describes an initial conversion state, otherwise it returns zero.

**SEE ALSO**

mbrlen(3), mbrtowc(3), mbsrtowcs(3), multibyte(3), wcrtomb(3),
wcsrtombs(3)

**STANDARDS**

The **mbsinit**\ () function conforms to ISO/IEC 9899:1999
(‘‘ISO C99’’).

BSD April 8, 2004 BSD

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

