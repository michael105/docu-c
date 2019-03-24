--------------

AIO_ERROR(2) BSD System Calls Manual AIO_ERROR(2)

**NAME**

**aio_error** — retrieve error status of asynchronous I/O operation
(REALTIME)

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <aio.h>**

*int*

**aio_error**\ (*const struct aiocb *iocb*);

**DESCRIPTION**

The **aio_error**\ () system call returns the error status of the
asynchronous I/O request associated with the structure pointed to by
*iocb*.

**RETURN VALUES**

If the asynchronous I/O request has completed successfully,
**aio_error**\ () returns 0. If the request has not yet completed,
EINPROGRESS is returned. If the request has completed unsuccessfully the
error status is returned as described in read(2), write(2), or fsync(2).
On failure, **aio_error**\ () returns -1 and sets errno to indicate the
error condition.

**ERRORS**

The **aio_error**\ () system call will fail if:

[EINVAL]

The *iocb* argument does not reference an outstanding asynchronous I/O
request.

**SEE ALSO**

aio_cancel(2), aio_read(2), aio_return(2), aio_suspend(2), aio_write(2),
fsync(2), read(2), write(2), aio(4)

**STANDARDS**

The **aio_error**\ () system call is expected to conform to the IEEE Std
1003.1 (‘‘POSIX.1’’) standard.

**HISTORY**

The **aio_error**\ () system call first appeared in FreeBSD 3.0.

**AUTHORS**

This manual page was written by Wes Peters <*wes@softweyr.com*>.

BSD June 2, 1999 BSD

--------------
