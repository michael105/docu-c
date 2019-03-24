--------------

--------------

FOPENCOOKIE(3) BSD Library Functions Manual FOPENCOOKIE(3)

\**NAME*\*

\**fopencookie*\* â open a stream

\**LIBRARY*\*

Standard CÂ Library (libc, âlc)

\**SYNOPSIS*\*

\**#include <stdio.h>*\*

\*typedef ssize_t\*

\**(*cookie_read_function_t)** (*voidÂ *cookie*, \*charÂ *buf*,
\*size_tÂ size*);

\*typedef ssize_t\*

\**(*cookie_write_function_t)** (*voidÂ *cookie*, \*constÂ charÂ *buf*,
\*size_tÂ size*);

\*typedef int\*

\**(*cookie_seek_function_t)** (*voidÂ *cookie*, \*off64_tÂ *offset*,
\*intÂ whence*);

\*typedef int\*

\**(*cookie_close_function_t)** (*voidÂ *cookie*);

typedef struct {

+-------------+-------------+-------------+-------------+-------------+
\| \| cookie_read \| \| ead; \| \| \| \| \_function_t \| \| \| \|
+-------------+-------------+-------------+-------------+-------------+
\| \| cookie_writ \| \| rite; \| \| \| \| e_function\_ \| \| \| \| \| \|
t \| \| \| \|
+-------------+-------------+-------------+-------------+-------------+
\| \| cookie_seek \| \| eek; \| \| \| \| \_function_t \| \| \| \|
+-------------+-------------+-------------+-------------+-------------+
\| \| cookie_clos \| \| lose; \| \| \| \| e_function\_ \| \| \| \| \| \|
t \| \| \| \|
+-------------+-------------+-------------+-------------+-------------+

} cookie_io_functions_t;

\*FILE

\**fopencookie** (*voidÂ *cookie*, \*constÂ charÂ *mode*,
\*cookie_io_functions_tÂ io_funcs*);

\**DESCRIPTION*\*

The \**fopencookie*\* function associates a stream with up to four ââI/O
functionsââ. These I/O functions will be used to read, write, seek and
close the new stream.

In general, omitting a function means that any attempt to perform the
associated operation on the resulting stream will fail. If the write
function is omitted, data written to the stream is discarded. If the
close function is omitted, closing the stream will flush any buffered
output and then succeed.

The calling conventions of \*read*, \*write*, and \*close\* must match
those, respectively, of read(2), write(2), and close(2) with the single
exception that they are passed the \*cookie\* argument specified to
\**fopencookie*\* in place of the traditional file descriptor argument.
The \*seek\* function updates the current stream offset using \*ffset\*
and \*whence*. If \*ffset\* is non-NULL, it updates \*ffset\* with the
current stream offset.

\**fopencookie*\* is implemented as a thin shim around the funopen(3)
interface. Limitations, possibilities, and requirements of that
interface apply to \**fopencookie**.

\**RETURN VALUES*\*

Upon successful completion, \**fopencookie*\* returns a FILE pointer.
Otherwise, NULL is returned and the global variable \*errno\* is set to
indicate the error.

\| \**ERRORS*\* \| [EINVAL]

A bogus \*mode\* was provided to \**fopencookie**.

[ENOMEM]

The \**fopencookie*\* function may fail and set \*errno\* for any of the
errors specified for the malloc(3) routine.

\**SEE ALSO*\*

fcntl(2), open(2), fclose(3), fopen(3), fseek(3), funopen(3)

\**HISTORY*\*

The \**funopen** () functions first appeared in 4.4BSD. The
\**fopencookie*\* function first appeared in FreeBSDÂ 11.

\**BUGS*\*

The \**fopencookie*\* function is a nonstandard glibc extension and may
not be portable to systems other than FreeBSD and Linux.

BSD MayÂ 9, 2016 BSD

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

