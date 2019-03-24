--------------

FGETWS(3) BSD Library Functions Manual FGETWS(3)

**NAME**

**fgetws** — get a line of wide characters from a stream

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <stdio.h>
#include <wchar.h>**

*wchar_t \**

**fgetws**\ (*wchar_t * restrict ws*, *int n*, *FILE * restrict fp*);

**DESCRIPTION**

The **fgetws**\ () function reads at most one less than the number of
characters specified by *n* from the given *fp* and stores them in the
wide character string *ws*. Reading stops when a newline character is
found, at end-of-file or error. The newline, if any, is retained. If any
characters are read and there is no error, a ‘\0’ character is appended
to end the string.

**RETURN VALUES**

Upon successful completion, **fgetws**\ () returns *ws*. If end-of-file
occurs before any characters are read, **fgetws**\ () returns NULL and
the buffer contents remain unchanged. If an error occurs, **fgetws**\ ()
returns NULL and the buffer contents are indeterminate. The
**fgetws**\ () function does not distinguish between end-of-file and
error, and callers must use feof(3) and ferror(3) to determine which
occurred.

**ERRORS**

The **fgetws**\ () function will fail if:

[EBADF]

The given *fp* argument is not a readable stream.

[EILSEQ]

The data obtained from the input stream does not form a valid multibyte
character.

The function **fgetws**\ () may also fail and set *errno* for any of the
errors specified for the routines fflush(3), fstat(2), read(2), or
malloc(3).

**SEE ALSO**

feof(3), ferror(3), fgets(3)

**STANDARDS**

The **fgetws**\ () function conforms to IEEE Std 1003.1-2001
(‘‘POSIX.1’’).

BSD August 6, 2002 BSD

--------------
