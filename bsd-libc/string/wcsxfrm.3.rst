--------------

WCSXFRM(3) BSD Library Functions Manual WCSXFRM(3)

**NAME**

**wcsxfrm** — transform a wide string under locale

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <wchar.h>**

*size_t*

**wcsxfrm**\ (*wchar_t * restrict dst*, *const wchar_t * restrict src*,
*size_t n*);

**DESCRIPTION**

The **wcsxfrm**\ () function transforms a null-terminated wide character
string pointed to by *src* according to the current locale collation
order then copies the transformed string into *dst*. No more than *n*
wide characters are copied into *dst*, including the terminating null
character added. If *n* is set to 0 (it helps to determine an actual
size needed for transformation), *dst* is permitted to be a NULL
pointer.

Comparing two strings using **wcscmp**\ () after **wcsxfrm**\ () is
equivalent to comparing two original strings with **wcscoll**\ ().

**RETURN VALUES**

Upon successful completion, **wcsxfrm**\ () returns the length of the
transformed string not including the terminating null character. If this
value is *n* or more, the contents of *dst* are indeterminate.

**SEE ALSO**

setlocale(3), strxfrm(3), wcscmp(3), wcscoll(3)

**STANDARDS**

The **wcsxfrm**\ () function conforms to ISO/IEC 9899:1999
(‘‘ISO C99’’).

**BUGS**

The current implementation of **wcsxfrm**\ () only works in single-byte
LC_CTYPE locales, and falls back to using **wcsncpy**\ () in locales
with extended character sets.

Comparing two strings using **wcscmp**\ () after **wcsxfrm**\ () is
*not* always equivalent to comparison with **wcscoll**\ ();
**wcsxfrm**\ () only stores information about primary collation weights
into *dst*, whereas **wcscoll**\ () compares characters using both
primary and secondary weights.

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

