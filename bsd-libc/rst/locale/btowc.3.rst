--------------

BTOWC(3) BSD Library Functions Manual BTOWC(3)

**NAME**

**btowc**, **wctob** — convert between wide and single-byte characters

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <wchar.h>**

*wint_t*

**btowc**\ (*int c*);

*int*

**wctob**\ (*wint_t c*);

**#include <wchar.h>
#include <xlocale.h>**

*wint_t*

**btowc_l**\ (*int c*, *locale_t loc*);

*int*

**wctob_l**\ (*wint_t c*, *locale_t loc*);

**DESCRIPTION**

The **btowc**\ () function converts a single-byte character into a
corresponding wide character. If the character is EOF or not valid in
the initial shift state, **btowc**\ () returns WEOF.

The **wctob**\ () function converts a wide character into a
corresponding single-byte character. If the wide character is WEOF or
not able to be represented as a single byte in the initial shift state,
**wctob**\ () returns EOF.

The \_l-suffixed versions take an explicit locale argument, while the
non-suffixed versions use the current global or per-thread locale.

**SEE ALSO**

mbrtowc(3), multibyte(3), wcrtomb(3)

**STANDARDS**

The **btowc**\ () and **wctob**\ () functions conform to IEEE Std
1003.1-2001 (‘‘POSIX.1’’).

**HISTORY**

The **btowc**\ () and **wctob**\ () functions first appeared in
FreeBSD 5.0.

BSD February 13, 2012 BSD

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

