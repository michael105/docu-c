--------------

WCSRTOMBS(3) BSD Library Functions Manual WCSRTOMBS(3)

**NAME**

**wcsrtombs**, **wcsnrtombs** — convert a wide-character string to a
character string (restartable)

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <wchar.h>**

*size_t*

**wcsrtombs**\ (*char * restrict dst*, *const wchar_t ** restrict src*,
*size_t len*, *mbstate_t * restrict ps*);

*size_t*

**wcsnrtombs**\ (*char * restrict dst*, *const wchar_t ** restrict src*,
*size_t nwc*, *size_t len*, *mbstate_t * restrict ps*);

**DESCRIPTION**

The **wcsrtombs**\ () function converts a string of wide characters
indirectly pointed to by *src* to a corresponding multibyte character
string stored in the array pointed to by *dst*. No more than *len* bytes
are written to *dst*.

If *dst* is NULL, no characters are stored.

If *dst* is not NULL, the pointer pointed to by *src* is updated to
point to the character after the one that conversion stopped at. If
conversion stops because a null character is encountered, *\*src* is set
to NULL.

The *mbstate_t* argument, *ps*, is used to keep track of the shift
state. If it is NULL, **wcsrtombs**\ () uses an internal, static
*mbstate_t* object, which is initialized to the initial conversion state
at program startup.

The **wcsnrtombs**\ () function behaves identically to
**wcsrtombs**\ (), except that conversion stops after reading at most
*nwc* characters from the buffer pointed to by *src*.

**RETURN VALUES**

The **wcsrtombs**\ () and **wcsnrtombs**\ () functions return the number
of bytes stored in the array pointed to by *dst* (not including any
terminating null), if successful, otherwise it returns (

*size_t* )−1.

**ERRORS**

The **wcsrtombs**\ () and **wcsnrtombs**\ () functions will fail if:

[EILSEQ]

An invalid wide character was encountered.

[EINVAL]

The conversion state is invalid.

**SEE ALSO**

mbsrtowcs(3), wcrtomb(3), wcstombs(3)

**STANDARDS**

The **wcsrtombs**\ () function conforms to ISO/IEC 9899:1999
(‘‘ISO C99’’).

The **wcsnrtombs**\ () function is an extension to the standard.

BSD July 21, 2004 BSD

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

