--------------

FWIDE(3) BSD Library Functions Manual FWIDE(3)

**NAME**

**fwide** — get/set orientation of a stream

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <stdio.h>
#include <wchar.h>**

*int*

**fwide**\ (*FILE *stream*, *int mode*);

**DESCRIPTION**

The **fwide**\ () function determines the orientation of the stream
pointed at by *stream*.

If the orientation of *stream* has already been determined,
**fwide**\ () leaves it unchanged. Otherwise, **fwide**\ () sets the
orientation of *stream* according to *mode*.

If *mode* is less than zero, *stream* is set to byte-oriented. If it is
greater than zero, *stream* is set to wide-oriented. Otherwise, *mode*
is zero, and *stream* is unchanged.

**RETURN VALUES**

The **fwide**\ () function returns a value according to orientation
after the call of **fwide**\ (); a value less than zero if
byte-oriented, a value greater than zero if wide-oriented, and zero if
the stream has no orientation.

**SEE ALSO**

ferror(3), fgetc(3), fgetwc(3), fopen(3), fputc(3), fputwc(3),
freopen(3), stdio(3)

**STANDARDS**

The **fwide**\ () function conforms to ISO/IEC 9899:1999 (‘‘ISO C99’’).

BSD October 24, 2001 BSD

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

