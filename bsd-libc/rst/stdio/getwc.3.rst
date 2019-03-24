--------------

GETWC(3) BSD Library Functions Manual GETWC(3)

**NAME**

**fgetwc**, **getwc**, **getwchar** — get next wide character from input
stream

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <stdio.h>
#include <wchar.h>**

*wint_t*

**fgetwc**\ (*FILE *stream*);

*wint_t*

**getwc**\ (*FILE *stream*);

*wint_t*

**getwchar**\ (*void*);

**DESCRIPTION**

The **fgetwc**\ () function obtains the next input wide character (if
present) from the stream pointed at by *stream*, or the next character
pushed back on the stream via ungetwc(3).

The **getwc**\ () function acts essentially identically to
**fgetwc**\ ().

The **getwchar**\ () function is equivalent to **getwc**\ () with the
argument stdin.

**RETURN VALUES**

If successful, these routines return the next wide character from the
*stream*. If the stream is at end-of-file or a read error occurs, the
routines return WEOF. The routines feof(3) and ferror(3) must be used to
distinguish between end-of-file and error. If an error occurs, the
global variable *errno* is set to indicate the error. The end-of-file
condition is remembered, even on a terminal, and all subsequent attempts
to read will return WEOF until the condition is cleared with
clearerr(3).

**SEE ALSO**

ferror(3), fopen(3), fread(3), getc(3), putwc(3), stdio(3), ungetwc(3)

**STANDARDS**

The **fgetwc**\ (), **getwc**\ () and **getwchar**\ () functions conform
to ISO/IEC 9899:1999 (‘‘ISO C99’’).

BSD March 3, 2004 BSD

--------------
