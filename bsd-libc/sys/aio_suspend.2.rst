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

