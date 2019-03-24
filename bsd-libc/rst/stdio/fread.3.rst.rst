--------------

--------------

FREAD(3) BSD Library Functions Manual FREAD(3)

\**NAME*\*

\**fread**, \**fwrite*\* â binary stream input/output

\**LIBRARY*\*

Standard CÂ Library (libc, âlc)

\**SYNOPSIS*\*

\**#include <stdio.h>*\*

\*size_t\*

\**fread** (*voidÂ *Â restrictÂ ptr*, \*size_tÂ size*, \*size_tÂ nmemb*,
\*FILEÂ *Â restrictÂ stream*);

\*size_t\*

\**fwrite** (*constÂ voidÂ *Â restrictÂ ptr*, \*size_tÂ size*,
\*size_tÂ nmemb*, \*FILEÂ *Â restrictÂ stream*);

\**DESCRIPTION*\*

The function \**fread** () reads \*nmemb\* objects, each \*size\* bytes
long, from the stream pointed to by \*stream*, storing them at the
location given by \*ptr*.

The function \**fwrite** () writes \*nmemb\* objects, each \*size\*
bytes long, to the stream pointed to by \*stream*, obtaining them from
the location given by \*ptr*.

\**RETURN VALUES*\*

The functions \**fread** () and \**fwrite** () advance the file position
indicator for the stream by the number of bytes read or written. They
return the number of objects read or written. If an error occurs, or the
end-of-file is reached, the return value is a short object count (or
zero).

The function \**fread** () does not distinguish between end-of-file and
error, and callers must use feof(3) and ferror(3) to determine which
occurred. The function \**fwrite** () returns a value less than
\*nmemb\* only if a write error has occurred.

\**SEE ALSO*\*

read(2), write(2)

\**STANDARDS*\*

The functions \**fread** () and \**fwrite** () conform to ISO/IEC
9899:1990 (ââISOÂ C90ââ).

BSD MarchÂ 8, 1994 BSD

--------------

--------------
