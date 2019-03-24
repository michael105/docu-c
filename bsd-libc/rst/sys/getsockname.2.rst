--------------

GETSOCKNAME(2) BSD System Calls Manual GETSOCKNAME(2)

**NAME**

**getsockname** — get socket name

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/types.h>
#include <sys/socket.h>**

*int*

**getsockname**\ (*int s*, *struct sockaddr * restrict name*,
*socklen_t * restrict namelen*);

**DESCRIPTION**

The **getsockname**\ () system call returns the current *name* for the
specified socket. The *namelen* argument should be initialized to
indicate the amount of space pointed to by *name*. On return it contains
the actual size of the name returned (in bytes).

**RETURN VALUES**

The **getsockname**\ () function returns the value 0 if successful;
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

[ENOBUFS]

Insufficient resources were available in the system to perform the
operation.

[EFAULT]

The *name* argument points to memory not in a valid part of the process
address space.

**SEE ALSO**

bind(2), getpeername(2), socket(2)

**HISTORY**

The **getsockname**\ () system call appeared in 4.2BSD.

**BUGS**

Names bound to sockets in the UNIX domain are inaccessible;
**getsockname**\ () returns a zero length name.

BSD June 4, 1993 BSD

--------------
