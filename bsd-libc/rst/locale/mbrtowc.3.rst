--------------

MBRTOWC(3) BSD Library Functions Manual MBRTOWC(3)

**NAME**

**mbrtowc**, **mbrtoc16**, **mbrtoc32** — convert a character to a
wide-character code (restartable)

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <wchar.h>**

*size_t*

**mbrtowc**\ (*wchar_t * restrict pc*, *const char * restrict s*,
*size_t n*, *mbstate_t * restrict ps*);

**#include <uchar.h>**

*size_t*

**mbrtoc16**\ (*char16_t * restrict pc*, *const char * restrict s*,
*size_t n*, *mbstate_t * restrict ps*);

*size_t*

**mbrtoc32**\ (*char32_t * restrict pc*, *const char * restrict s*,
*size_t n*, *mbstate_t * restrict ps*);

**DESCRIPTION**

The **mbrtowc**\ (), **mbrtoc16**\ () and **mbrtoc32**\ () functions
inspect at most *n* bytes pointed to by *s* to determine the number of
bytes needed to complete the next multibyte character. If a character
can be completed, and *pc* is not NULL, the wide character which is
represented by *s* is stored in the *wchar_t*, *char16_t* or *char32_t*
it points to.

If *s* is NULL, these functions behave as if *pc* was NULL, *s* was an
empty string ("") and *n* was 1.

The *mbstate_t* argument, *ps*, is used to keep track of the shift
state. If it is NULL, these functions use an internal, static
*mbstate_t* object, which is initialized to the initial conversion state
at program startup.

As a single *char16_t* is not large enough to represent certain
multibyte characters, the **mbrtoc16**\ () function may need to be
invoked multiple times to convert a single multibyte character sequence.

**RETURN VALUES**

The **mbrtowc**\ (), **mbrtoc16**\ () and **mbrtoc32**\ () functions
return:

0

The next *n* or fewer bytes represent the null wide character (L’\0’).

>0

The next *n* or fewer bytes represent a valid character, these functions
return the number of bytes used to complete the multibyte character.

( *
size_t*)−1

An encoding error has occurred. The next *n* or fewer bytes do not
contribute to a valid multibyte character.

( *
size_t*)−2

The next *n* contribute to, but do not complete, a valid multibyte
character sequence, and all *n* bytes have been processed.

The **mbrtoc16**\ () function also returns:

( *
size_t*)−3

The next character resulting from a previous call has been stored. No
bytes from the input have been consumed.

**ERRORS**

The **mbrtowc**\ (), **mbrtoc16**\ () and **mbrtoc32**\ () functions
will fail if:

[EILSEQ]

An invalid multibyte sequence was detected.

[EINVAL]

The conversion state is invalid.

**SEE ALSO**

mbtowc(3), multibyte(3), setlocale(3), wcrtomb(3)

**STANDARDS**

The **mbrtowc**\ (), **mbrtoc16**\ () and **mbrtoc32**\ () functions
conform to ISO/IEC 9899:2011 (‘‘ISO C11’’).

BSD May 21, 2013 BSD

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

