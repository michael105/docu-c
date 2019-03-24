--------------

--------------

FPUTS(3) BSD Library Functions Manual FPUTS(3)

\**NAME*\*

\**fputs**, \**puts*\* â output a line to a stream

\**LIBRARY*\*

Standard CÂ Library (libc, âlc)

\**SYNOPSIS*\*

\**#include <stdio.h>*\*

\*int\*

\**fputs** (*constÂ charÂ *str*, \*FILEÂ *stream*);

\*int\*

\**puts** (*constÂ charÂ *str*);

\**DESCRIPTION*\*

The function \**fputs** () writes the string pointed to by \*str\* to
the stream pointed to by \*stream*.

The function \**puts** () writes the string \*str*, and a terminating
newline character, to the stream stdout.

\**RETURN VALUES*\*

The functions \**fputs** () and \**puts** () return a nonnegative
integer on success and EOF on error.

\| \**ERRORS*\* \| [EBADF]

The \*stream\* argument is not a writable stream.

The functions \**fputs** () and \**puts** () may also fail and set
\*errno\* for any of the errors specified for the routines write(2).

\**SEE ALSO*\*

ferror(3), fputws(3), putc(3), stdio(3)

\**STANDARDS*\*

The functions \**fputs** () and \**puts** () conform to ISO/IEC
9899:1990 (ââISOÂ C90ââ).

BSD JuneÂ 4, 1993 BSD

--------------

--------------
