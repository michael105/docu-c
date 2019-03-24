--------------

--------------

GETC(3) BSD Library Functions Manual GETC(3)

\**NAME*\*

\**fgetc**, \**getc**, \**getc_unlocked**, \**getchar**,
\**getchar_unlocked**, \**getw*\* â get next character or word from
input stream

\**LIBRARY*\*

Standard CÂ Library (libc, âlc)

\**SYNOPSIS*\*

\**#include <stdio.h>*\*

\*int\*

\**fgetc** (*FILEÂ *stream*);

\*int\*

\**getc** (*FILEÂ *stream*);

\*int\*

\**getc_unlocked** (*FILEÂ *stream*);

\*int\*

\**getchar** (*void*);

\*int\*

\**getchar_unlocked** (*void*);

\*int\*

\**getw** (*FILEÂ *stream*);

\**DESCRIPTION*\*

The \**fgetc** () function obtains the next input character (if present)
from the stream pointed at by \*stream*, or the next character pushed
back on the stream via ungetc(3).

The \**getc** () function acts essentially identically to \**fgetc** (),
but is a macro that expands in-line.

The \**getchar** () function is equivalent to \**getc** (*stdin*).

The \**getw** () function obtains the next \*int\* (if present) from the
stream pointed at by \*stream*.

The \**getc_unlocked** () and \**getchar_unlocked** () functions are
equivalent to \**getc** () and \**getchar** () respectively, except that
the caller is responsible for locking the stream with flockfile(3)
before calling them. These functions may be used to avoid the overhead
of locking the stream for each character, and to avoid input being
dispersed among multiple threads reading from the same stream.

\**RETURN VALUES*\*

If successful, these routines return the next requested object from the
\*stream*. Character values are returned as an \*unsigned char\*
converted to an \*int*. If the stream is at end-of-file or a read error
occurs, the routines return EOF. The routines feof(3) and ferror(3) must
be used to distinguish between end-of-file and error. If an error
occurs, the global variable \*errno\* is set to indicate the error. The
end-of-file condition is remembered, even on a terminal, and all
subsequent attempts to read will return EOF until the condition is
cleared with clearerr(3).

\**SEE ALSO*\*

ferror(3), flockfile(3), fopen(3), fread(3), getwc(3), putc(3),
ungetc(3)

\**STANDARDS*\*

The \**fgetc** (), \**getc** (), and \**getchar** () functions conform
to ISO/IEC 9899:1990 (ââISOÂ C90ââ). The \**getc_unlocked** () and
\**getchar_unlocked** () functions conform to IEEE Std 1003.1-2001
(ââPOSIX.1ââ).

\**BUGS*\*

Since EOF is a valid integer value, feof(3) and ferror(3) must be used
to check for failure after calling \**getw** (). The size and byte order
of an \*int\* varies from one machine to another, and \**getw** () is
not recommended for portable applications.

BSD JanuaryÂ 10, 2003 BSD

--------------

--------------
