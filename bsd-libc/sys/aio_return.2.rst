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

