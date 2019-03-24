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
