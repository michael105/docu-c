--------------

FCLOSE(3) BSD Library Functions Manual FCLOSE(3)

**NAME**

**fclose**, **fdclose**, **fcloseall** — close a stream

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <stdio.h>**

*int*

**fclose**\ (*FILE *stream*);

*int*

**fdclose**\ (*FILE *stream*, *int *fdp*);

*void*

**fcloseall**\ (*void*);

**DESCRIPTION**

The **fclose**\ () function dissociates the named *stream* from its
underlying file or set of functions. If the stream was being used for
output, any buffered data is written first, using fflush(3).

The **fdclose**\ () function is equivalent to **fclose**\ () except that
it does not close the underlying file descriptor. If *fdp* is not NULL,
the file descriptor will be written to it. If the *fdp* argument will be
different then NULL the file descriptor will be returned in it, If the
stream does not have an associated file descriptor, *fdp* will be set to
-1. This type of stream is created with functions such as fmemopen(3),
funopen(3), or open_memstream(3).

The **fcloseall**\ () function calls **fclose**\ () on all open streams.

**RETURN VALUES**

**fcloseall**\ () does not return a value.

Upon successful completion the **fclose**\ () and **fdclose**\ ()
functions return 0. Otherwise, EOF is returned and the global variable
*errno* is set to indicate the error.

**ERRORS**

**fdclose**\ () fails if:

[EOPNOTSUPP]

The stream does not have an associated file descriptor.

The **fclose**\ () and **fdclose**\ () functions may also fail and set
*errno* for any of the errors specified for fflush(3).

The **fclose**\ () function may also fail and set errno for any of the
errors specified for close(2).

**NOTES**

The **fclose**\ () and **fdclose**\ () functions do not handle NULL
arguments in the *stream* variable; this will result in a segmentation
violation. This is intentional. It makes it easier to make sure programs
written under FreeBSD are bug free. This behaviour is an implementation
detail, and programs should not rely upon it.

**SEE ALSO**

close(2), fflush(3), fopen(3), setbuf(3)

**STANDARDS**

The **fclose**\ () function conforms to ISO/IEC 9899:1990 (‘‘ISO C90’’).

**HISTORY**

The **fcloseall**\ () function first appeared in FreeBSD 7.0.

The **fdclose**\ () function first appeared in FreeBSD 11.0.

BSD July 4, 2015 BSD

--------------
