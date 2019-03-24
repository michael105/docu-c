--------------

POSIX_FADVISE(2) BSD System Calls Manual POSIX_FADVISE(2)

**NAME**

**posix_fadvise** — give advice about use of file data

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <fcntl.h>**

*int*

**posix_fadvise**\ (*int fd*, *off_t offset*, *off_t len*,
*int advice*);

**DESCRIPTION**

The **posix_fadvise**\ () system call allows a process to describe to
the system its data access behavior for an open file descriptor *fd*.
The advice covers the data starting at offset *offset* and continuing
for *len* bytes. If *len* is zero, all data from *offset* to the end of
the file is covered.

The behavior is specified by the *advice* parameter and may be one of:

POSIX_FADV_NORMAL

Tells the system to revert to the default data access behavior.

POSIX_FADV_RANDOM

Is a hint that file data will be accessed randomly, and prefetching is
likely not advantageous.

POSIX_FADV_SEQUENTIAL

Tells the system that file data will be accessed sequentially. This
currently does nothing as the default behavior uses heuristics to detect
sequential behavior.

POSIX_FADV_WILLNEED

Tells the system that the specified data will be accessed in the near
future. The system may initiate an asynchronous read of the data if it
is not already present in memory.

POSIX_FADV_DONTNEED

Tells the system that the specified data will not be accessed in the
near future. The system may decrease the in-memory priority of clean
data within the specified range and future access to this data may
require a read operation.

POSIX_FADV_NOREUSE

Tells the system that the specified data will only be accessed once and
then not reused. The system may decrease the in-memory priority of data
once it has been read or written. Future access to this data may require
a read operation.

**RETURN VALUES**

If successful, **posix_fadvise**\ () returns zero. It returns an error
on failure, without setting *errno*.

**ERRORS**

Possible failure conditions:

[EBADF]

The *fd* argument is not a valid file descriptor.

[EINVAL]

The *advice* argument is not valid.

[EINVAL]

The *offset* or *len* arguments are negative, or *offset* + *len* is
greater than the maximum file size.

[ENODEV]

The *fd* argument does not refer to a regular file.

[ESPIPE]

The *fd* argument is associated with a pipe or FIFO.

**SEE ALSO**

madvise(2)

**STANDARDS**

The **posix_fadvise**\ () interface conforms to IEEE Std 1003.1-2001
(‘‘POSIX.1’’).

**HISTORY**

The **posix_fadvise**\ () system call first appeared in FreeBSD 9.1.

BSD October 3, 2015 BSD

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

