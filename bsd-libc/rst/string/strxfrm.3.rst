--------------

STRXFRM(3) BSD Library Functions Manual STRXFRM(3)

**NAME**

**strxfrm** — transform a string under locale

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <string.h>**

*size_t*

**strxfrm**\ (*char * restrict dst*, *const char * restrict src*,
*size_t n*);

*size_t*

**strxfrm_l**\ (*char * restrict dst*, *const char *restrict src*,
*size_t n*, *locale_t loc*);

**DESCRIPTION**

The **strxfrm**\ () function transforms a null-terminated string pointed
to by *src* according to the current locale collation if any, then
copies the transformed string into *dst*. Not more than *n* characters
are copied into *dst*, including the terminating null character added.
If *n* is set to 0 (it helps to determine an actual size needed for
transformation), *dst* is permitted to be a NULL pointer.

Comparing two strings using **strcmp**\ () after **strxfrm**\ () is
equal to comparing two original strings with **strcoll**\ ().

**strxfrm_l**\ () does the same, however takes an explicit locale rather
than the global locale.

**RETURN VALUES**

Upon successful completion, **strxfrm**\ () and **strxfrm_l**\ () return
the length of the transformed string not including the terminating null
character. If this value is *n* or more, the contents of *dst* are
indeterminate.

**SEE ALSO**

setlocale(3), strcmp(3), strcoll(3), wcsxfrm(3)

**STANDARDS**

The **strxfrm**\ () function conforms to ISO/IEC 9899:1990
(‘‘ISO C90’’). The **strxfrm_l**\ () function conforms to IEEE Std
1003.1-2008 (‘‘POSIX.1’’).

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

