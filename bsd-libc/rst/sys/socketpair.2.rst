--------------

SOCKETPAIR(2) BSD System Calls Manual SOCKETPAIR(2)

**NAME**

**socketpair** — create a pair of connected sockets

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/types.h>
#include <sys/socket.h>**

*int*

**socketpair**\ (*int domain*, *int type*, *int protocol*, *int *sv*);

**DESCRIPTION**

The **socketpair**\ () system call creates an unnamed pair of connected
sockets in the specified communications *domain*, of the specified
*type*, and using the optionally specified *protocol*. The descriptors
used in referencing the new sockets are returned in *sv*\ [0] and
*sv*\ [1]. The two sockets are indistinguishable.

The SOCK_CLOEXEC and SOCK_NONBLOCK flags in the *type* argument apply to
both descriptors.

**RETURN VALUES**

The **socketpair**\ () function returns the value 0 if successful;
otherwise the value −1 is returned and the global variable *errno* is
set to indicate the error.

**ERRORS**

The call succeeds unless:

[EMFILE]

Too many descriptors are in use by this process.

[EAFNOSUPPORT]

The specified address family is not supported on this machine.

[EPROTONOSUPPORT]

The specified protocol is not supported on this machine.

[EOPNOTSUPP]

The specified protocol does not support creation of socket pairs.

[EFAULT]

The address *sv* does not specify a valid part of the process address
space.

**SEE ALSO**

pipe(2), read(2), socket(2), write(2)

**STANDARDS**

The **socketpair**\ () system call conforms to IEEE Std 1003.1-2001
(‘‘POSIX.1’’) and IEEE Std 1003.1-2008 (‘‘POSIX.1’’).

**HISTORY**

The **socketpair**\ () system call appeared in 4.2BSD.

**BUGS**

This call is currently implemented only for the UNIX domain.

BSD February 10, 2018 BSD

--------------
