--------------

MBRLEN(3) BSD Library Functions Manual MBRLEN(3)

**NAME**

**mbrlen** — get number of bytes in a character (restartable)

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <wchar.h>**

*size_t*

**mbrlen**\ (*const char * restrict s*, *size_t n*,
*mbstate_t * restrict ps*);

**DESCRIPTION**

The **mbrlen**\ () function inspects at most *n* bytes pointed to by *s*
to determine the number of bytes needed to complete the next multibyte
character.

The *mbstate_t* argument, *ps*, is used to keep track of the shift
state. If it is NULL, **mbrlen**\ () uses an internal, static
*mbstate_t* object, which is initialized to the initial conversion state
at program startup.

It is equivalent to:

mbrtowc(NULL, s, n, ps);

Except that when *ps* is a NULL pointer, **mbrlen**\ () uses its own
static, internal *mbstate_t* object to keep track of the shift state.

**RETURN VALUES**

The **mbrlen**\ () functions returns:

0

The next *n* or fewer bytes represent the null wide character (L’\0’).

>0

The next *n* or fewer bytes represent a valid character, **mbrlen**\ ()
returns the number of bytes used to complete the multibyte character.

( *
size_t*)−2

The next *n* contribute to, but do not complete, a valid multibyte
character sequence, and all *n* bytes have been processed.

( *
size_t*)−1

An encoding error has occurred. The next *n* or fewer bytes do not
contribute to a valid multibyte character.

**EXAMPLES**

A function that calculates the number of characters in a multibyte
character string:

| size_t
| nchars(const char \*s)
| {

+-----------------+-----------------+-----------------+-----------------+
|                 | size_t charlen, |                 |                 |
|                 | chars;          |                 |                 |
+-----------------+-----------------+-----------------+-----------------+
|                 | mbstate_t mbs;  |                 |                 |
+-----------------+-----------------+-----------------+-----------------+
|                 | chars = 0;      |                 |                 |
+-----------------+-----------------+-----------------+-----------------+
|                 | memset(&mbs, 0, |                 |                 |
|                 | sizeof(mbs));   |                 |                 |
+-----------------+-----------------+-----------------+-----------------+
|                 | while ((charlen |                 |                 |
|                 | = mbrlen(s,     |                 |                 |
|                 | MB_CUR_MAX,     |                 |                 |
|                 | &mbs)) != 0 &&  |                 |                 |
+-----------------+-----------------+-----------------+-----------------+
|                 | charlen !=      |                 |                 |
|                 | (size_t)-1 &&   |                 |                 |
|                 | charlen !=      |                 |                 |
|                 | (size_t)-2) {   |                 |                 |
+-----------------+-----------------+-----------------+-----------------+
|                 |                 | s += charlen;   |                 |
+-----------------+-----------------+-----------------+-----------------+
|                 |                 | chars++;        |                 |
+-----------------+-----------------+-----------------+-----------------+
|                 | }               |                 |                 |
+-----------------+-----------------+-----------------+-----------------+
|                 | return (chars); |                 |                 |
+-----------------+-----------------+-----------------+-----------------+

}

**ERRORS**

The **mbrlen**\ () function will fail if:

[EILSEQ]

An invalid multibyte sequence was detected.

[EINVAL]

The conversion state is invalid.

**SEE ALSO**

mblen(3), mbrtowc(3), multibyte(3)

**STANDARDS**

The **mbrlen**\ () function conforms to ISO/IEC 9899:1999 (‘‘ISO C99’’).

BSD April 7, 2004 BSD

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

