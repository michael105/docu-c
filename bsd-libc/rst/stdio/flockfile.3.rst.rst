--------------

--------------

FLOCKFILE(3) BSD Library Functions Manual FLOCKFILE(3)

\**NAME*\*

\**flockfile**, \**ftrylockfile**, \**funlockfile*\* â stdio locking
functions

\**LIBRARY*\*

Standard CÂ Library (libc, âlc)

\**SYNOPSIS*\*

\**#include <stdio.h>*\*

\*void\*

\**flockfile** (*FILEÂ *stream*);

\*int\*

\**ftrylockfile** (*FILEÂ *stream*);

\*void\*

\**funlockfile** (*FILEÂ *stream*);

\**DESCRIPTION*\*

These functions provide explicit application-level locking of stdio
streams. They can be used to avoid output from multiple threads being
interspersed, input being dispersed among multiple readers, and to avoid
the overhead of locking the stream for each operation.

The \**flockfile** () function acquires an exclusive lock on the
specified stream. If another thread has already locked the stream,
\**flockfile** () will block until the lock is released.

The \**ftrylockfile** () function is a non-blocking version of
\**flockfile** (); if the lock cannot be acquired immediately,
\**ftrylockfile** () returns non-zero instead of blocking.

The \**funlockfile** () function releases the lock on a stream acquired
by an earlier call to \**flockfile** () or \**ftrylockfile** ().

These functions behave as if there is a lock count associated with each
stream. Each time \**flockfile** () is called on the stream, the count
is incremented, and each time \**funlockfile** () is called on the
stream, the count is decremented. The lock is only actually released
when the count reaches zero.

\**RETURN VALUES*\*

The \**flockfile** () and \**funlockfile** () functions return no value.

The \**ftrylockfile** () function returns zero if the stream was
successfully locked, non-zero otherwise.

\**SEE ALSO*\*

getc_unlocked(3), putc_unlocked(3)

\**STANDARDS*\*

The \**flockfile** (), \**ftrylockfile** () and \**funlockfile** ()
functions conform to IEEE Std 1003.1-2001 (ââPOSIX.1ââ).

BSD JanuaryÂ 10, 2003 BSD

--------------

--------------
