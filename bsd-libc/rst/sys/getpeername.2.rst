--------------

GETPEERNAME(2) BSD System Calls Manual GETPEERNAME(2)

**NAME**

**getpeername** — get name of connected peer

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/types.h>
#include <sys/socket.h>**

*int*

**getpeername**\ (*int s*, *struct sockaddr * restrict name*,
*socklen_t * restrict namelen*);

**DESCRIPTION**

The **getpeername**\ () system call returns the name of the peer
connected to socket *s*. The *namelen* argument should be initialized to
indicate the amount of space pointed to by *name*. On return it contains
the actual size of the name returned (in bytes). The name is truncated
if the buffer provided is too small.

**RETURN VALUES**

The **getpeername**\ () function returns the value 0 if successful;
otherwise the value −1 is returned and the global variable *errno* is
set to indicate the error.

**ERRORS**

The call succeeds unless:

[EBADF]

The argument *s* is not a valid descriptor.

[ECONNRESET]

The connection has been reset by the peer.

[EINVAL]

The value of the *namelen* argument is not valid.

[ENOTSOCK]

The argument *s* is a file, not a socket.

[ENOTCONN]

The socket is not connected.

[ENOBUFS]

Insufficient resources were available in the system to perform the
operation.

[EFAULT]

The *name* argument points to memory not in a valid part of the process
address space.

**SEE ALSO**

accept(2), bind(2), getsockname(2), socket(2)

**HISTORY**

The **getpeername**\ () system call appeared in 4.2BSD.

BSD June 4, 1993 BSD

--------------
