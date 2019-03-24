--------------

AIO_WAITCOMPLETE(2) BSD System Calls Manual AIO_WAITCOMPLETE(2)

**NAME**

**aio_waitcomplete** — wait for the next completion of an aio request

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <aio.h>**

*ssize_t*

**aio_waitcomplete**\ (*struct aiocb **iocbp*,
*struct timespec *timeout*);

**DESCRIPTION**

The **aio_waitcomplete**\ () system call waits for completion of an
asynchronous I/O request. Upon completion, **aio_waitcomplete**\ ()
returns the result of the function and sets *iocbp* to point to the
structure associated with the original request. If an asynchronous I/O
request is completed before **aio_waitcomplete**\ () is called, it
returns immediately with the completed request.

If *timeout* is a non-NULL pointer, it specifies a maximum interval to
wait for a asynchronous I/O request to complete. If *timeout* is a NULL
pointer, **aio_waitcomplete**\ () waits indefinitely. To effect a poll,
the *timeout* argument should be non-NULL, pointing to a zero-valued
timeval structure.

The **aio_waitcomplete**\ () system call also serves the function of
**aio_return**\ (), thus **aio_return**\ () should not be called for the
control block returned in *iocbp*.

**RETURN VALUES**

If an asynchronous I/O request has completed, *iocbp* is set to point to
the control block passed with the original request, and the status is
returned as described in read(2), write(2), or fsync(2). On failure,
**aio_waitcomplete**\ () returns -1, sets iocbp to NULL and sets *errno*
to indicate the error condition.

**ERRORS**

The **aio_waitcomplete**\ () system call fails if:

[EINVAL]

The specified time limit is invalid.

[EAGAIN]

The process has not yet called **aio_read**\ () or **aio_write**\ ().

[EINTR]

A signal was delivered before the timeout expired and before any
asynchronous I/O requests completed.

| [EWOULDBLOCK]
| [EINPROGRESS]

The specified time limit expired before any asynchronous I/O requests
completed.

**SEE ALSO**

aio_cancel(2), aio_error(2), aio_read(2), aio_return(2), aio_suspend(2),
aio_write(2), fsync(2), read(2), write(2), aio(4)

**STANDARDS**

The **aio_waitcomplete**\ () system call is a FreeBSD-specific
extension.

**HISTORY**

The **aio_waitcomplete**\ () system call first appeared in FreeBSD 4.0.

**AUTHORS**

The **aio_waitcomplete**\ () system call and this manual page were
written by Christopher M Sedore <*cmsedore@maxwell.syr.edu*>.

BSD March 21, 2016 BSD

--------------
