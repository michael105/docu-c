--------------

WCSCOLL(3) BSD Library Functions Manual WCSCOLL(3)

**NAME**

**wcscoll** — compare wide strings according to current collation

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <wchar.h>**

*int*

**wcscoll**\ (*const wchar_t *s1*, *const wchar_t *s2*);

**DESCRIPTION**

The **wcscoll**\ () function compares the null-terminated strings *s1*
and *s2* according to the current locale collation order. In the ‘‘C’’
locale, **wcscoll**\ () is equivalent to **wcscmp**\ ().

**RETURN VALUES**

The **wcscoll**\ () function returns an integer greater than, equal to,
or less than 0, if *s1* is greater than, equal to, or less than *s2*.

No return value is reserved to indicate errors; callers should set
*errno* to 0 before calling **wcscoll**\ (). If it is non-zero upon
return from **wcscoll**\ (), an error has occurred.

**ERRORS**

The **wcscoll**\ () function will fail if:

[EILSEQ]

An invalid wide character code was specified.

[ENOMEM]

Cannot allocate enough memory for temporary buffers.

**SEE ALSO**

setlocale(3), strcoll(3), wcscmp(3), wcsxfrm(3)

**STANDARDS**

The **wcscoll**\ () function conforms to ISO/IEC 9899:1999
(‘‘ISO C99’’).

**BUGS**

The current implementation of **wcscoll**\ () only works in single-byte
LC_CTYPE locales, and falls back to using **wcscmp**\ () in locales with
extended character sets.

BSD October 4, 2002 BSD

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

