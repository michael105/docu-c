--------------

FGETS(3) BSD Library Functions Manual FGETS(3)

**NAME**

**fgets**, **gets**, **gets_s** — get a line from a stream

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <stdio.h>**

*char \**

**fgets**\ (*char * restrict str*, *int size*,
*FILE * restrict stream*);

*char \**

**gets_s**\ (*char *str*, *rsize_t size*);

*char \**

**gets**\ (*char *str*);

**DESCRIPTION**

The **fgets**\ () function reads at most one less than the number of
characters specified by *size* from the given *stream* and stores them
in the string *str*. Reading stops when a newline character is found, at
end-of-file or error. The newline, if any, is retained. If any
characters are read and there is no error, a ‘\0’ character is appended
to end the string.

The **gets_s**\ () function is equivalent to **fgets**\ () with a
*stream* of stdin, except that the newline character (if any) is not
stored in the string.

The **gets**\ () function is equivalent to **fgets**\ () with an
infinite *size* and a *stream* of stdin, except that the newline
character (if any) is not stored in the string. It is the caller’s
responsibility to ensure that the input line, if any, is sufficiently
short to fit in the string.

**RETURN VALUES**

Upon successful completion, **fgets**\ (), **gets_s**\ (), and
**gets**\ () return a pointer to the string. If end-of-file occurs
before any characters are read, they return NULL and the buffer contents
remain unchanged. If an error occurs, they return NULL and the buffer
contents are indeterminate. The **fgets**\ (), **gets_s**\ (), and
**gets**\ () functions do not distinguish between end-of-file and error,
and callers must use feof(3) and ferror(3) to determine which occurred.

| **ERRORS**
| [EBADF]

The given *stream* is not a readable stream.

The function **fgets**\ () may also fail and set *errno* for any of the
errors specified for the routines fflush(3), fstat(2), read(2), or
malloc(3).

The function **gets**\ () and **gets_s**\ () may also fail and set
*errno* for any of the errors specified for the routine getchar(3).

**SEE ALSO**

feof(3), ferror(3), fgetln(3), fgetws(3), getline(3)

**STANDARDS**

The functions **fgets**\ () and **gets**\ () conform to ISO/IEC
9899:1999 (‘‘ISO C99’’). **gets_s**\ () conforms to ISO/IEC 9899:2011
(‘‘ISO C11’’) K.3.7.4.1. **gets**\ () has been removed from ISO/IEC
9899:2011 (‘‘ISO C11’’).

**SECURITY CONSIDERATIONS**

The **gets**\ () function cannot be used securely. Because of its lack
of bounds checking, and the inability for the calling program to
reliably determine the length of the next incoming line, the use of this
function enables malicious users to arbitrarily change a running
program’s functionality through a buffer overflow attack. It is strongly
suggested that the **fgets**\ () function be used in all cases.

BSD April 3, 2018 BSD

--------------
