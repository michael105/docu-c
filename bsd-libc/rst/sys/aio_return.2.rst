--------------

AIO_RETURN(2) BSD System Calls Manual AIO_RETURN(2)

**NAME**

**aio_return** — retrieve return status of asynchronous I/O operation
(REALTIME)

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <aio.h>**

*ssize_t*

**aio_return**\ (*struct aiocb *iocb*);

**DESCRIPTION**

The **aio_return**\ () system call returns the final status of the
asynchronous I/O request associated with the structure pointed to by
*iocb*.

The **aio_return**\ () system call should only be called once, to obtain
the final status of an asynchronous I/O operation once it has completed
(aio_error(2) returns something other than EINPROGRESS).

**RETURN VALUES**

If the asynchronous I/O request has completed, the status is returned as
described in read(2), write(2), or fsync(2). Otherwise,
**aio_return**\ () returns −1 and sets *errno* to indicate the error
condition.

**ERRORS**

The **aio_return**\ () system call will fail if:

[EINVAL]

The *iocb* argument does not reference a completed asynchronous I/O
request.

**SEE ALSO**

aio_cancel(2), aio_error(2), aio_suspend(2), aio_waitcomplete(2),
aio_write(2), fsync(2), read(2), write(2), aio(4)

**STANDARDS**

The **aio_return**\ () system call is expected to conform to the IEEE
Std 1003.1 (‘‘POSIX.1’’) standard.

**HISTORY**

The **aio_return**\ () system call first appeared in FreeBSD 3.0.

**AUTHORS**

This manual page was written by Wes Peters <*wes@softweyr.com*>.

BSD March 21, 2016 BSD

--------------
