--------------

--------------

FGETWLN(3) BSD Library Functions Manual FGETWLN(3)

\**NAME*\*

\**fgetwln*\* â get a line of wide characters from a stream

\**LIBRARY*\*

Standard CÂ Library (libc, âlc)

\**SYNOPSIS*\*

\**#include <stdio.h> #include <wchar.h>*\*

\*wchar_t

\**fgetwln** (*FILEÂ *Â restrictÂ stream*, \*size_tÂ *Â restrictÂ len*);

\**DESCRIPTION*\*

The \**fgetwln** () function returns a pointer to the next line from the
stream referenced by \*stream*. This line is \*not\* a standard wide
character string as it does not end with a terminating null wide
character. The length of the line, including the final newline, is
stored in the memory location to which \*len\* points. (Note, however,
that if the line is the last in a file that does not end in a newline,
the returned text will not contain a newline.)

\**RETURN VALUES*\*

Upon successful completion a pointer is returned; this pointer becomes
invalid after the next I/O operation on \*stream\* (whether successful
or not) or as soon as the stream is closed. Otherwise, NULL is returned.
The \**fgetwln** () function does not distinguish between end-of-file
and error; the routines feof(3) and ferror(3) must be used to determine
which occurred. If an error occurs, the global variable \*errno\* is set
to indicate the error. The end-of-file condition is remembered, even on
a terminal, and all subsequent attempts to read will return NULL until
the condition is cleared with clearerr(3).

The text to which the returned pointer points may be modified, provided
that no changes are made beyond the returned size. These changes are
lost as soon as the pointer becomes invalid.

\| \**ERRORS*\* \| [EBADF]

The argument \*stream\* is not a stream open for reading.

The \**fgetwln** () function may also fail and set \*errno\* for any of
the errors specified for the routines mbrtowc(3), realloc(3), or
read(2).

\**SEE ALSO*\*

ferror(3), fgetln(3), fgetws(3), fopen(3)

BSD JulyÂ 16, 2004 BSD

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

