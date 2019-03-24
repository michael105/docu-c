--------------

PUTWC(3) BSD Library Functions Manual PUTWC(3)

**NAME**

**fputwc**, **putwc**, **putwchar** — output a wide character to a
stream

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <stdio.h>
#include <wchar.h>**

*wint_t*

**fputwc**\ (*wchar_t wc*, *FILE *stream*);

*wint_t*

**putwc**\ (*wchar_t wc*, *FILE *stream*);

*wint_t*

**putwchar**\ (*wchar_t wc*);

**DESCRIPTION**

The **fputwc**\ () function writes the wide character *wc* to the output
stream pointed to by *stream*.

The **putwc**\ () function acts essentially identically to
**fputwc**\ ().

The **putwchar**\ () function is identical to **putwc**\ () with an
output stream of stdout.

**RETURN VALUES**

The **fputwc**\ (), **putwc**\ (), and **putwchar**\ () functions return
the wide character written. If an error occurs, the value WEOF is
returned.

**SEE ALSO**

ferror(3), fopen(3), getwc(3), putc(3), stdio(3)

**STANDARDS**

The **fputwc**\ (), **putwc**\ (), and **putwchar**\ () functions
conform to ISO/IEC 9899:1999 (‘‘ISO C99’’).

BSD March 3, 2004 BSD

--------------
