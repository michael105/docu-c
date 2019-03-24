--------------

--------------

FSEEK(3) BSD Library Functions Manual FSEEK(3)

\**NAME*\*

\**fgetpos**, \**fseek**, \**fseeko**, \**fsetpos**, \**ftell**,
\**ftello**, \**rewind*\* â reposition a stream

\**LIBRARY*\*

Standard CÂ Library (libc, âlc)

\**SYNOPSIS*\*

\**#include <stdio.h>*\*

\*int\*

\**fseek** (*FILEÂ *stream*, \*longÂ offset*, \*intÂ whence*);

\*long\*

\**ftell** (*FILEÂ *stream*);

\*void\*

\**rewind** (*FILEÂ *stream*);

\*int\*

\**fgetpos** (*FILEÂ *Â restrictÂ stream*, \*fpos_tÂ *Â restrictÂ pos*);

\*int\*

\**fsetpos** (*FILEÂ *stream*, \*constÂ fpos_tÂ *pos*);

\**#include <sys/types.h>*\*

\*int\*

\**fseeko** (*FILEÂ *stream*, \*off_tÂ offset*, \*intÂ whence*);

\*off_t\*

\**ftello** (*FILEÂ *stream*);

\**DESCRIPTION*\*

The \**fseek** () function sets the file position indicator for the
stream pointed to by \*stream*. The new position, measured in bytes, is
obtained by adding \*offset\* bytes to the position specified by
\*whence*. If \*whence\* is set to SEEK_SET, SEEK_CUR, or SEEK_END, the
offset is relative to the start of the file, the current position
indicator, or end-of-file, respectively. A successful call to the
\**fseek** () function clears the end-of-file indicator for the stream
and undoes any effects of the ungetc(3) and ungetwc(3) functions on the
same stream.

The \**ftell** () function obtains the current value of the file
position indicator for the stream pointed to by \*stream*.

The \**rewind** () function sets the file position indicator for the
stream pointed to by \*stream\* to the beginning of the file. It is
equivalent to:

(void)fseek(stream, 0L, SEEK_SET)

except that the error indicator for the stream is also cleared (see
clearerr(3)).

Since \**rewind** () does not return a value, an application wishing to
detect errors should clear \*errno*, then call \**rewind** (), and if
\*errno\* is non-zero, assume an error has occurred.

The \**fseeko** () function is identical to \**fseek** (), except it
takes an \*off_t\* argument instead of a \*long*. Likewise, the
\**ftello** () function is identical to \**ftell** (), except it returns
an \*off_t*.

The \**fgetpos** () and \**fsetpos** () functions are alternate
interfaces for retrieving and setting the current position in the file,
similar to \**ftell** () and \**fseek** (), except that the current
position is stored in an opaque object of type \*fpos_t\* pointed to by
\*pos*. These functions provide a portable way to seek to offsets larger
than those that can be represented by a \*long int*. They may also store
additional state information in the \*fpos_t\* object to facilitate
seeking within files containing multibyte characters with
state-dependent encodings. Although \*fpos_t\* has traditionally been an
integral type, applications cannot assume that it is; in particular,
they must not perform arithmetic on objects of this type.

If the stream is a wide character stream (see fwide(3)), the position
specified by the combination of \*offset\* and \*whence\* must contain
the first byte of a multibyte sequence.

\**RETURN VALUES*\*

The \**rewind** () function returns no value.

The \**fgetpos** (), \**fseek** (), \**fseeko** (), and \**fsetpos** ()
functions return the valueÂ 0 if successful; otherwise the valueÂ â1 is
returned and the global variable \*errno\* is set to indicate the error.

Upon successful completion, \**ftell** () and \**ftello** () return the
current offset. Otherwise, â1 is returned and the global variable
\*errno\* is set to indicate the error.

\| \**ERRORS*\* \| [EBADF]

The \*stream\* argument is not a seekable stream.

[EINVAL]

The \*whence\* argument is invalid or the resulting file-position
indicator would be set to a negative value.

[EOVERFLOW]

The resulting file offset would be a value which cannot be represented
correctly in an object of type \*off_t\* for \**fseeko** () and
\**ftello** () or \*long\* for \**fseek** () and \**ftell** ().

[ESPIPE]

The file descriptor underlying stream is associated with a pipe or FIFO
or file-position indicator value is unspecified (see ungetc(3)).

The functions \**fgetpos** (), \**fseek** (), \**fseeko** (),
\**fsetpos** (), \**ftell** (), \**ftello** (), and \**rewind** () may
also fail and set \*errno\* for any of the errors specified for the
routines fflush(3), fstat(2), lseek(2), and malloc(3).

\**SEE ALSO*\*

lseek(2), clearerr(3), fwide(3), ungetc(3), ungetwc(3)

\**STANDARDS*\*

The \**fgetpos** (), \**fsetpos** (), \**fseek** (), \**ftell** (), and
\**rewind** () functions conform to ISO/IEC 9899:1990 (ââISOÂ C90ââ).

The \**fseeko** () and \**ftello** () functions conform to IEEE Std
1003.1-2001 (ââPOSIX.1ââ).

BSD MarchÂ 19, 2004 BSD

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

