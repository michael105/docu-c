--------------

FWIDE(3) BSD Library Functions Manual FWIDE(3)

**NAME**

**fwide** — get/set orientation of a stream

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <stdio.h>
#include <wchar.h>**

*int*

**fwide**\ (*FILE *stream*, *int mode*);

**DESCRIPTION**

The **fwide**\ () function determines the orientation of the stream
pointed at by *stream*.

If the orientation of *stream* has already been determined,
**fwide**\ () leaves it unchanged. Otherwise, **fwide**\ () sets the
orientation of *stream* according to *mode*.

If *mode* is less than zero, *stream* is set to byte-oriented. If it is
greater than zero, *stream* is set to wide-oriented. Otherwise, *mode*
is zero, and *stream* is unchanged.

**RETURN VALUES**

The **fwide**\ () function returns a value according to orientation
after the call of **fwide**\ (); a value less than zero if
byte-oriented, a value greater than zero if wide-oriented, and zero if
the stream has no orientation.

**SEE ALSO**

ferror(3), fgetc(3), fgetwc(3), fopen(3), fputc(3), fputwc(3),
freopen(3), stdio(3)

**STANDARDS**

The **fwide**\ () function conforms to ISO/IEC 9899:1999 (‘‘ISO C99’’).

BSD October 24, 2001 BSD

--------------
