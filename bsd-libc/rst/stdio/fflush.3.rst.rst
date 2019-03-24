--------------

--------------

FFLUSH(3) BSD Library Functions Manual FFLUSH(3)

\**NAME*\*

\**fflush**, \**fpurge*\* â flush a stream

\**LIBRARY*\*

Standard CÂ Library (libc, âlc)

\**SYNOPSIS*\*

\**#include <stdio.h>*\*

\*int\*

\**fflush** (*FILEÂ *stream*);

\*int\*

\**fpurge** (*FILEÂ *stream*);

\**DESCRIPTION*\*

The function \**fflush** () forces a write of all buffered data for the
given output or update \*stream\* via the streamâs underlying write
function. The open status of the stream is unaffected.

If the \*stream\* argument is NULL, \**fflush** () flushes \*all\* open
output streams.

The function \**fpurge** () erases any input or output buffered in the
given \*stream*. For output streams this discards any unwritten output.
For input streams this discards any input read from the underlying
object but not yet obtained via getc(3); this includes any text pushed
back via ungetc(3).

\**RETURN VALUES*\*

Upon successful completion 0 is returned. Otherwise, EOF is returned and
the global variable \*errno\* is set to indicate the error.

\| \**ERRORS*\* \| [EBADF]

The \*stream\* argument is not an open stream.

The function \**fflush** () may also fail and set \*errno\* for any of
the errors specified for the routine write(2), except that in case of
\*stream\* being a read-only descriptor, \**fflush** () returns 0.

\**SEE ALSO*\*

write(2), fclose(3), fopen(3), setbuf(3)

\**STANDARDS*\*

The \**fflush** () function conforms to ISO/IEC 9899:1990
(ââISOÂ C90ââ).

BSD DecemberÂ 25, 2017 BSD

--------------

--------------
