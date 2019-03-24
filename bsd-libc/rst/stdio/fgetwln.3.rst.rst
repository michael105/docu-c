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
