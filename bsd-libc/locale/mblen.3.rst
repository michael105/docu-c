--------------

MBLEN(3) BSD Library Functions Manual MBLEN(3)

**NAME**

**mblen** — get number of bytes in a character

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <stdlib.h>**

*int*

**mblen**\ (*const char *mbchar*, *size_t nbytes*);

**DESCRIPTION**

The **mblen**\ () function computes the length in bytes of a multibyte
character *mbchar* according to the current conversion state. Up to
*nbytes* bytes are examined.

A call with a null *mbchar* pointer returns nonzero if the current
locale requires shift states, zero otherwise; if shift states are
required, the shift state is reset to the initial state.

**RETURN VALUES**

If *mbchar* is NULL, the **mblen**\ () function returns nonzero if shift
states are supported, zero otherwise.

Otherwise, if *mbchar* is not a null pointer, **mblen**\ () either
returns 0 if *mbchar* represents the null wide character, or returns the
number of bytes processed in *mbchar*, or returns −1 if no multibyte
character could be recognized or converted. In this case,
**mblen**\ ()’s internal conversion state is undefined.

**ERRORS**

The **mblen**\ () function will fail if:

[EILSEQ]

An invalid multibyte sequence was detected.

[EINVAL]

The internal conversion state is not valid.

**SEE ALSO**

mbrlen(3), mbtowc(3), multibyte(3)

**STANDARDS**

The **mblen**\ () function conforms to ISO/IEC 9899:1999 (‘‘ISO C99’’).

BSD April 11, 2004 BSD

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

