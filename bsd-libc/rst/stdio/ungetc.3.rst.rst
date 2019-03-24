--------------

--------------

UNGETC(3) BSD Library Functions Manual UNGETC(3)

\**NAME*\*

\**ungetc*\* â un-get character from input stream

\**LIBRARY*\*

Standard CÂ Library (libc, âlc)

\**SYNOPSIS*\*

\**#include <stdio.h>*\*

\*int\*

\**ungetc** (*intÂ c*, \*FILEÂ *stream*);

\**DESCRIPTION*\*

The \**ungetc** () function pushes the character \*c\* (converted to an
unsigned char) back onto the input stream pointed to by \*stream*. The
pushed-back characters will be returned by subsequent reads on the
stream (in reverse order). A successful intervening call, using the same
stream, to one of the file positioning functions (fseek(3), fsetpos(3),
or rewind(3)) will discard the pushed back characters.

One character of push-back is guaranteed, but as long as there is
sufficient memory, an effectively infinite amount of pushback is
allowed.

If a character is successfully pushed-back, the end-of-file indicator
for the stream is cleared. The file-position indicator is decremented by
each successful call to \**ungetc** (); if its value was 0 before a
call, its value is unspecified after the call.

\**RETURN VALUES*\*

The \**ungetc** () function returns the character pushed-back after the
conversion, or EOF if the operation fails. If the value of the argument
\*c\* character equals EOF, the operation will fail and the stream will
remain unchanged.

\**SEE ALSO*\*

fseek(3), getc(3), setvbuf(3), ungetwc(3)

\**STANDARDS*\*

The \**ungetc** () function conforms to ISO/IEC 9899:1990
(ââISOÂ C90ââ).

BSD JuneÂ 4, 1993 BSD

--------------

--------------
