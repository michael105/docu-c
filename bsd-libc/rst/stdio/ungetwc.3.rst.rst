--------------

--------------

UNGETWC(3) BSD Library Functions Manual UNGETWC(3)

\**NAME*\*

\**ungetwc*\* â un-get wide character from input stream

\**LIBRARY*\*

Standard CÂ Library (libc, âlc)

\**SYNOPSIS*\*

\**#include <stdio.h> #include <wchar.h>*\*

\*wint_t\*

\**ungetwc** (*wint_tÂ wc*, \*FILEÂ *stream*);

\**DESCRIPTION*\*

The \**ungetwc** () function pushes the wide character \*wc\* (converted
to an \*wchar_t*) back onto the input stream pointed to by \*stream*.
The pushed-backed wide characters will be returned by subsequent reads
on the stream (in reverse order). A successful intervening call, using
the same stream, to one of the file positioning functions fseek(3),
fsetpos(3), or rewind(3) will discard the pushed back wide characters.

One wide character of push-back is guaranteed, but as long as there is
sufficient memory, an effectively infinite amount of pushback is
allowed.

If a character is successfully pushed-back, the end-of-file indicator
for the stream is cleared.

\**RETURN VALUES*\*

The \**ungetwc** () function returns the wide character pushed-back
after the conversion, or WEOF if the operation fails. If the value of
the argument \*c\* character equals WEOF, the operation will fail and
the stream will remain unchanged.

\**SEE ALSO*\*

fseek(3), getwc(3)

\**STANDARDS*\*

The \**ungetwc** () function conforms to ISO/IEC 9899:1999
(ââISOÂ C99ââ).

BSD MarchÂ 3, 2004 BSD

--------------

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

