--------------

FPUTWS(3) BSD Library Functions Manual FPUTWS(3)

**NAME**

**fputws** — output a line of wide characters to a stream

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <stdio.h>
#include <wchar.h>**

*int*

**fputws**\ (*const wchar_t * restrict ws*, *FILE * restrict fp*);

**DESCRIPTION**

The **fputws**\ () function writes the wide character string pointed to
by *ws* to the stream pointed to by *fp*.

**RETURN VALUES**

The **fputws**\ () function returns 0 on success and −1 on error.

**ERRORS**

The **fputws**\ () function will fail if:

[EBADF]

The *fp* argument supplied is not a writable stream.

The **fputws**\ () function may also fail and set *errno* for any of the
errors specified for the routine write(2).

**SEE ALSO**

ferror(3), fputs(3), putwc(3), stdio(3)

**STANDARDS**

The **fputws**\ () function conforms to IEEE Std 1003.1-2001
(‘‘POSIX.1’’).

BSD August 6, 2002 BSD

--------------
