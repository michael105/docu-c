--------------

POSIX_FALLOCATE(2) BSD System Calls Manual POSIX_FALLOCATE(2)

**NAME**

**posix_fallocate** — pre-allocate storage for a range in a file

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <fcntl.h>**

*int*

**posix_fallocate**\ (*int fd*, *off_t offset*, *off_t len*);

**DESCRIPTION**

Required storage for the range *offset* to *offset + len* in the file
referenced by *fd* is guaranteed to be allocated upon successful return.
That is, if **posix_fallocate**\ () returns successfully, subsequent
writes to the specified file data will not fail due to lack of free
space on the file system storage media. Any existing file data in the
specified range is unmodified. If *offset + len* is beyond the current
file size, then **posix_fallocate**\ () will adjust the file size to
*offset + len*. Otherwise, the file size will not be changed.

Space allocated by **posix_fallocate**\ () will be freed by a successful
call to creat(2) or open(2) that truncates the size of the file. Space
allocated via **posix_fallocate**\ () may be freed by a successful call
to ftruncate(2) that reduces the file size to a size smaller than
*offset + len*.

**RETURN VALUES**

If successful, **posix_fallocate**\ () returns zero. It returns an error
on failure, without setting *errno*.

**ERRORS**

Possible failure conditions:

[EBADF]

The *fd* argument is not a valid file descriptor.

[EBADF]

The *fd* argument references a file that was opened without write
permission.

[EFBIG]

The value of *offset + len* is greater than the maximum file size.

[EINTR]

A signal was caught during execution.

[EINVAL]

The *len* argument was less than or equal to zero, the *offset* argument
was less than zero, or the operation is not supported by the file
system.

[EIO]

An I/O error occurred while reading from or writing to a file system.

[ENODEV]

The *fd* argument does not refer to a regular file.

[ENOSPC]

There is insufficient free space remaining on the file system storage
media.

[ENOTCAPABLE]

The file descriptor *fd* has insufficient rights.

[ESPIPE]

The *fd* argument is associated with a pipe or FIFO.

**SEE ALSO**

creat(2), ftruncate(2), open(2), unlink(2)

**STANDARDS**

The **posix_fallocate**\ () system call conforms to IEEE Std 1003.1-2004
(‘‘POSIX.1’’).

**HISTORY**

The **posix_fallocate**\ () function appeared in FreeBSD 9.0.

**AUTHORS**

**posix_fallocate**\ () and this manual page were initially written by
Matthew Fleming <*mdf@FreeBSD.org*>.

BSD November 4, 2017 BSD

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

