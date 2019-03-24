--------------

WCRTOMB(3) BSD Library Functions Manual WCRTOMB(3)

**NAME**

**wcrtomb**, **c16rtomb**, **c32rtomb** — convert a wide-character code
to a character (restartable)

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <wchar.h>**

*size_t*

**wcrtomb**\ (*char * restrict s*, *wchar_t c*,
*mbstate_t * restrict ps*);

**#include <uchar.h>**

*size_t*

**c16rtomb**\ (*char * restrict s*, *char16_t c*,
*mbstate_t * restrict ps*);

*size_t*

**c32rtomb**\ (*char * restrict s*, *char32_t c*,
*mbstate_t * restrict ps*);

**DESCRIPTION**

The **wcrtomb**\ (), **c16rtomb**\ () and **c32rtomb**\ () functions
store a multibyte sequence representing the wide character *c*,
including any necessary shift sequences, to the character array *s*,
storing a maximum of MB_CUR_MAX bytes.

If *s* is NULL, these functions behave as if *s* pointed to an internal
buffer and *c* was a null wide character (L’\0’).

The *mbstate_t* argument, *ps*, is used to keep track of the shift
state. If it is NULL, these functions use an internal, static
*mbstate_t* object, which is initialized to the initial conversion state
at program startup.

As certain multibyte characters may only be represented by a series of
16-bit characters, the **c16rtomb**\ () may need to invoked multiple
times before a multibyte sequence is returned.

**RETURN VALUES**

These functions return the length (in bytes) of the multibyte sequence
needed to represent *c*, or (

*size_t* )−1 if *c* is not a valid wide character code.

**ERRORS**

The **wcrtomb**\ (), **c16rtomb**\ () and **c32rtomb**\ () functions
will fail if:

[EILSEQ]

An invalid wide character code was specified.

[EINVAL]

The conversion state is invalid.

**SEE ALSO**

mbrtowc(3), multibyte(3), setlocale(3), wctomb(3)

**STANDARDS**

The **wcrtomb**\ (), **c16rtomb**\ () and **c32rtomb**\ () functions
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

