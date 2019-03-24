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

.. Copyright (c) 1990, 1991, 1993
..	The Regents of the University of California.  All rights reserved.
..
.. This code is derived from software contributed to Berkeley by
.. Chris Torek and the American National Standards Committee X3,
.. on Information Processing Systems.
..
.. Redistribution and use in source and binary forms, with or without
.. modification, are permitted provided that the following conditions
.. are met:
.. 1. Redistributions of source code must retain the above copyright
..    notice, this list of conditions and the following disclaimer.
.. 2. Redistributions in binary form must reproduce the above copyright
..    notice, this list of conditions and the following disclaimer in the
..    documentation and/or other materials provided with the distribution.
.. 3. Neither the name of the University nor the names of its contributors
..    may be used to endorse or promote products derived from this software
..    without specific prior written permission.
..
.. THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
.. ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
.. IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
.. ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
.. FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
.. DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
.. OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
.. HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
.. LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
.. OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
.. SUCH DAMAGE.

