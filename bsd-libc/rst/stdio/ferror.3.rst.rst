--------------

--------------

FERROR(3) BSD Library Functions Manual FERROR(3)

\**NAME*\*

\**clearerr**, \**clearerr_unlocked**, \**feof**, \**feof_unlocked**,
\**ferror**, \**ferror_unlocked**, \**fileno**, \**fileno_unlocked*\* â
check and reset stream status

\**LIBRARY*\*

Standard CÂ Library (libc, âlc)

\**SYNOPSIS*\*

\**#include <stdio.h>*\*

\*void\*

\**clearerr** (*FILEÂ *stream*);

\*void\*

\**clearerr_unlocked** (*FILEÂ *stream*);

\*int\*

\**feof** (*FILEÂ *stream*);

\*int\*

\**feof_unlocked** (*FILEÂ *stream*);

\*int\*

\**ferror** (*FILEÂ *stream*);

\*int\*

\**ferror_unlocked** (*FILEÂ *stream*);

\*int\*

\**fileno** (*FILEÂ *stream*);

\*int\*

\**fileno_unlocked** (*FILEÂ *stream*);

\**DESCRIPTION*\*

The function \**clearerr** () clears the end-of-file and error
indicators for the stream pointed to by \*stream*.

The function \**feof** () tests the end-of-file indicator for the stream
pointed to by \*stream*, returning non-zero if it is set. The
end-of-file indicator may be cleared by explicitly calling
\**clearerr** (), or as a side-effect of other operations, e.g.
\**fseek** ().

The function \**ferror** () tests the error indicator for the stream
pointed to by \*stream*, returning non-zero if it is set.

The function \**fileno** () examines the argument \*stream\* and returns
its integer descriptor.

The \**clearerr_unlocked** (), \**feof_unlocked** (),
\**ferror_unlocked** (), and \**fileno_unlocked** () functions are
equivalent to \**clearerr** (), \**feof** (), \**ferror** (), and
\**fileno** () respectively, except that the caller is responsible for
locking the stream with flockfile(3) before calling them. These
functions may be used to avoid the overhead of locking the stream and to
prevent races when multiple threads are operating on the same stream.

\**ERRORS*\*

These functions should not fail and do not set the external variable
\*errno*.

\**SEE ALSO*\*

open(2), fdopen(3), flockfile(3), stdio(3)

\**STANDARDS*\*

The functions \**clearerr** (), \**feof** (), and \**ferror** () conform
to ISO/IEC 9899:1990 (ââISOÂ C90ââ).

BSD JanuaryÂ 28, 2009 BSD

--------------

--------------
