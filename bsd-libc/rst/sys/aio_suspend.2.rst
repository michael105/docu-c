--------------

AIO_SUSPEND(2) BSD System Calls Manual AIO_SUSPEND(2)

**NAME**

**aio_suspend** — suspend until asynchronous I/O operations or timeout
complete (REALTIME)

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <aio.h>**

*int*

**aio_suspend**\ (*const struct aiocb *const iocbs[]*, *int niocb*,
*const struct timespec *timeout*);

**DESCRIPTION**

The **aio_suspend**\ () system call suspends the calling process until
at least one of the specified asynchronous I/O requests have completed,
a signal is delivered, or the *timeout* has passed.

The *iocbs* argument is an array of *niocb* pointers to asynchronous I/O
requests. Array members containing null pointers will be silently
ignored.

If *timeout* is not a null pointer, it specifies a maximum interval to
suspend. If *timeout* is a null pointer, the suspend blocks
indefinitely. To effect a poll, the *timeout* should point to a
zero-value timespec structure.

**RETURN VALUES**

If one or more of the specified asynchronous I/O requests have
completed, **aio_suspend**\ () returns 0. Otherwise it returns -1 and
sets *errno* to indicate the error, as enumerated below.

**ERRORS**

The **aio_suspend**\ () system call will fail if:

[EAGAIN]

the *timeout* expired before any I/O requests completed.

[EINVAL]

The *iocbs* argument contains more asynchronous I/O requests than the
*vfs.aio.max_aio_queue_per_proc* sysctl(8) variable, or at least one of
the requests is not valid.

[EINTR]

the suspend was interrupted by a signal.

**SEE ALSO**

aio_cancel(2), aio_error(2), aio_return(2), aio_waitcomplete(2),
aio_write(2), aio(4)

**STANDARDS**

The **aio_suspend**\ () system call is expected to conform to the IEEE
Std 1003.1 (‘‘POSIX.1’’) standard.

**HISTORY**

The **aio_suspend**\ () system call first appeared in FreeBSD 3.0.

**AUTHORS**

This manual page was written by Wes Peters <*wes@softweyr.com*>.

BSD Oct 23, 2017 BSD

--------------
