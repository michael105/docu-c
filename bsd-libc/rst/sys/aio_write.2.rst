--------------

AIO_WRITE(2) BSD System Calls Manual AIO_WRITE(2)

**NAME**

**aio_write** — asynchronous write to a file (REALTIME)

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <aio.h>**

*int*

**aio_write**\ (*struct aiocb *iocb*);

**DESCRIPTION**

The **aio_write**\ () system call allows the calling process to write
*iocb->aio_nbytes* from the buffer pointed to by *iocb->aio_buf* to the
descriptor *iocb->aio_fildes*. The call returns immediately after the
write request has been enqueued to the descriptor; the write may or may
not have completed at the time the call returns. If the request could
not be enqueued, generally due to invalid arguments, the call returns
without having enqueued the request.

If O_APPEND is set for *iocb->aio_fildes*, **aio_write**\ () operations
append to the file in the same order as the calls were made. If O_APPEND
is not set for the file descriptor, the write operation will occur at
the absolute position from the beginning of the file plus
*iocb->aio_offset*.

If \_POSIX_PRIORITIZED_IO is defined, and the descriptor supports it,
then the enqueued operation is submitted at a priority equal to that of
the calling process minus *iocb->aio_reqprio*.

The *iocb* pointer may be subsequently used as an argument to
**aio_return**\ () and **aio_error**\ () in order to determine return or
error status for the enqueued operation while it is in progress.

If the request is successfully enqueued, the value of *iocb->aio_offset*
can be modified during the request as context, so this value must not be
referenced after the request is enqueued.

The *iocb->aio_sigevent* structure can be used to request notification
of the operation’s completion as described in aio(4).

**RESTRICTIONS**

The Asynchronous I/O Control Block structure pointed to by *iocb* and
the buffer that the *iocb->aio_buf* member of that structure references
must remain valid until the operation has completed.

The asynchronous I/O control buffer *iocb* should be zeroed before the
**aio_write**\ () system call to avoid passing bogus context information
to the kernel.

Modifications of the Asynchronous I/O Control Block structure or the
buffer contents are not allowed while the request is queued.

If the file offset in *iocb->aio_offset* is past the offset maximum for
*iocb->aio_fildes*, no I/O will occur.

**RETURN VALUES**

The **aio_write**\ () function returns the value 0 if successful;
otherwise the value −1 is returned and the global variable *errno* is
set to indicate the error.

**ERRORS**

The **aio_write**\ () system call will fail if:

[EAGAIN]

The request was not queued because of system resource limitations.

[EINVAL]

The asynchronous notification method in
*iocb->aio_sigevent.sigev_notify* is invalid or not supported.

[EOPNOTSUPP]

Asynchronous write operations on the file descriptor *iocb->aio_fildes*
are unsafe and unsafe asynchronous I/O operations are disabled.

The following conditions may be synchronously detected when the
**aio_write**\ () system call is made, or asynchronously, at any time
thereafter. If they are detected at call time, **aio_write**\ () returns
-1 and sets *errno* appropriately; otherwise the **aio_return**\ ()
system call must be called, and will return -1, and **aio_error**\ ()
must be called to determine the actual value that would have been
returned in *errno*.

[EBADF]

The *iocb->aio_fildes* argument is invalid, or is not opened for
writing.

[EINVAL]

The offset *iocb->aio_offset* is not valid, the priority specified by
*iocb->aio_reqprio* is not a valid priority, or the number of bytes
specified by *iocb->aio_nbytes* is not valid.

If the request is successfully enqueued, but subsequently canceled or an
error occurs, the value returned by the **aio_return**\ () system call
is per the write(2) system call, and the value returned by the
**aio_error**\ () system call is either one of the error returns from
the write(2) system call, or one of:

[EBADF]

The *iocb->aio_fildes* argument is invalid for writing.

[ECANCELED]

The request was explicitly canceled via a call to **aio_cancel**\ ().

[EINVAL]

The offset *iocb->aio_offset* would be invalid.

**SEE ALSO**

aio_cancel(2), aio_error(2), aio_return(2), aio_suspend(2),
aio_waitcomplete(2), sigevent(3), siginfo(3), aio(4)

**STANDARDS**

The **aio_write**\ () system call is expected to conform to the IEEE Std
1003.1 (‘‘POSIX.1’’) standard.

**HISTORY**

The **aio_write**\ () system call first appeared in FreeBSD 3.0.

**AUTHORS**

This manual page was written by Wes Peters <*wes@softweyr.com*>.

**BUGS**

Invalid information in *iocb->_aiocb_private* may confuse the kernel.

BSD August 19, 2016 BSD

--------------
