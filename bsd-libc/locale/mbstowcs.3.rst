--------------

MBSTOWCS(3) BSD Library Functions Manual MBSTOWCS(3)

**NAME**

**mbstowcs** — convert a character string to a wide-character string

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <stdlib.h>**

*size_t*

**mbstowcs**\ (*wchar_t * restrict wcstring*,
*const char * restrict mbstring*, *size_t nwchars*);

**DESCRIPTION**

The **mbstowcs**\ () function converts a multibyte character string
*mbstring* beginning in the initial conversion state into a wide
character string *wcstring*. No more than *nwchars* wide characters are
stored. A terminating null wide character is appended if there is room.

**RETURN VALUES**

The **mbstowcs**\ () function returns the number of wide characters
converted, not counting any terminating null wide character, or −1 if an
invalid multibyte character was encountered.

**ERRORS**

The **mbstowcs**\ () function will fail if:

[EILSEQ]

An invalid multibyte sequence was detected.

[EINVAL]

The conversion state is invalid.

**SEE ALSO**

mbsrtowcs(3), mbtowc(3), multibyte(3)

**STANDARDS**

The **mbstowcs**\ () function conforms to ISO/IEC 9899:1999
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

