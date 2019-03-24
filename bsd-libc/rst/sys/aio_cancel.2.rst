--------------

AIO_CANCEL(2) BSD System Calls Manual AIO_CANCEL(2)

**NAME**

**aio_cancel** — cancel an outstanding asynchronous I/O operation
(REALTIME)

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <aio.h>**

*int*

**aio_cancel**\ (*int fildes*, *struct aiocb *iocb*);

**DESCRIPTION**

The **aio_cancel**\ () system call cancels the outstanding asynchronous
I/O request for the file descriptor specified in *fildes*. If *iocb* is
specified, only that specific asynchronous I/O request is cancelled.

Normal asynchronous notification occurs for cancelled requests. Requests
complete with an error result of ECANCELED.

**RESTRICTIONS**

The **aio_cancel**\ () system call does not cancel asynchronous I/O
requests for raw disk devices. The **aio_cancel**\ () system call will
always return AIO_NOTCANCELED for file descriptors associated with raw
disk devices.

**RETURN VALUES**

The **aio_cancel**\ () system call returns -1 to indicate an error, or
one of the following:

[AIO_CANCELED]

All outstanding requests meeting the criteria specified were cancelled.

[AIO_NOTCANCELED]

Some requests were not cancelled, status for the requests should be
checked with aio_error(2).

[AIO_ALLDONE]

All of the requests meeting the criteria have finished.

**ERRORS**

An error return from **aio_cancel**\ () indicates:

[EBADF]

The *fildes* argument is an invalid file descriptor.

**SEE ALSO**

aio_error(2), aio_read(2), aio_return(2), aio_suspend(2), aio_write(2),
aio(4)

**STANDARDS**

The **aio_cancel**\ () system call is expected to conform to the IEEE
Std 1003.1 (‘‘POSIX.1’’) standard.

**HISTORY**

The **aio_cancel**\ () system call first appeared in FreeBSD 3.0. The
first functional implementation of **aio_cancel**\ () appeared in
FreeBSD 4.0.

**AUTHORS**

This manual page was originally written by Wes Peters
<*wes@softweyr.com*>. Christopher M Sedore <*cmsedore@maxwell.syr.edu*>
updated it when **aio_cancel**\ () was implemented for FreeBSD 4.0.

BSD January 19, 2000 BSD

--------------
