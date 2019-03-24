--------------

FERROR(3) BSD Library Functions Manual FERROR(3)

**NAME**

**clearerr**, **clearerr_unlocked**, **feof**, **feof_unlocked**,
**ferror**, **ferror_unlocked**, **fileno**, **fileno_unlocked** — check
and reset stream status

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <stdio.h>**

*void*

**clearerr**\ (*FILE *stream*);

*void*

**clearerr_unlocked**\ (*FILE *stream*);

*int*

**feof**\ (*FILE *stream*);

*int*

**feof_unlocked**\ (*FILE *stream*);

*int*

**ferror**\ (*FILE *stream*);

*int*

**ferror_unlocked**\ (*FILE *stream*);

*int*

**fileno**\ (*FILE *stream*);

*int*

**fileno_unlocked**\ (*FILE *stream*);

**DESCRIPTION**

The function **clearerr**\ () clears the end-of-file and error
indicators for the stream pointed to by *stream*.

The function **feof**\ () tests the end-of-file indicator for the stream
pointed to by *stream*, returning non-zero if it is set. The end-of-file
indicator may be cleared by explicitly calling **clearerr**\ (), or as a
side-effect of other operations, e.g. **fseek**\ ().

The function **ferror**\ () tests the error indicator for the stream
pointed to by *stream*, returning non-zero if it is set.

The function **fileno**\ () examines the argument *stream* and returns
its integer descriptor.

The **clearerr_unlocked**\ (), **feof_unlocked**\ (),
**ferror_unlocked**\ (), and **fileno_unlocked**\ () functions are
equivalent to **clearerr**\ (), **feof**\ (), **ferror**\ (), and
**fileno**\ () respectively, except that the caller is responsible for
locking the stream with flockfile(3) before calling them. These
functions may be used to avoid the overhead of locking the stream and to
prevent races when multiple threads are operating on the same stream.

**ERRORS**

These functions should not fail and do not set the external variable
*errno*.

**SEE ALSO**

open(2), fdopen(3), flockfile(3), stdio(3)

**STANDARDS**

The functions **clearerr**\ (), **feof**\ (), and **ferror**\ () conform
to ISO/IEC 9899:1990 (‘‘ISO C90’’).

BSD January 28, 2009 BSD

--------------
