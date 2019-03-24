--------------

CONNECT(2) BSD System Calls Manual CONNECT(2)

**NAME**

**connect** — initiate a connection on a socket

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/socket.h>**

*int*

**connect**\ (*int s*, *const struct sockaddr *name*,
*socklen_t namelen*);

**DESCRIPTION**

The *s* argument is a socket. If it is of type SOCK_DGRAM, this call
specifies the peer with which the socket is to be associated; this
address is that to which datagrams are to be sent, and the only address
from which datagrams are to be received. If the socket is of type
SOCK_STREAM, this call attempts to make a connection to another socket.
The other socket is specified by *name*, which is an address in the
communications space of the socket. *namelen* indicates the amount of
space pointed to by *name*, in bytes; the *sa_len* member of *name* is
ignored. Each communications space interprets the *name* argument in its
own way. Generally, stream sockets may successfully **connect**\ () only
once; datagram sockets may use **connect**\ () multiple times to change
their association. Datagram sockets may dissolve the association by
connecting to an invalid address, such as a null address.

**RETURN VALUES**

The **connect**\ () function returns the value 0 if successful;
otherwise the value −1 is returned and the global variable *errno* is
set to indicate the error.

**ERRORS**

The **connect**\ () system call fails if:

[EBADF]

The *s* argument is not a valid descriptor.

[EINVAL]

The *namelen* argument is not a valid length for the address family.

[ENOTSOCK]

The *s* argument is a descriptor for a file, not a socket.

[EADDRNOTAVAIL]

The specified address is not available on this machine.

[EAFNOSUPPORT]

Addresses in the specified address family cannot be used with this
socket.

[EISCONN]

The socket is already connected.

[ETIMEDOUT]

Connection establishment timed out without establishing a connection.

[ECONNREFUSED]

The attempt to connect was forcefully rejected.

[ECONNRESET]

The connection was reset by the remote host.

[ENETUNREACH]

The network is not reachable from this host.

[EHOSTUNREACH]

The remote host is not reachable from this host.

[EADDRINUSE]

The address is already in use.

[EFAULT]

The *name* argument specifies an area outside the process address space.

[EINPROGRESS]

The socket is non-blocking and the connection cannot be completed
immediately. It is possible to select(2) for completion by selecting the
socket for writing.

[EINTR]

The connection attempt was interrupted by the delivery of a signal. The
connection will be established in the background, as in the case of
EINPROGRESS.

[EALREADY]

A previous connection attempt has not yet been completed.

[EACCES]

An attempt is made to connect to a broadcast address (obtained through
the INADDR_BROADCAST constant or the INADDR_NONE return value) through a
socket that does not provide broadcast functionality.

[EAGAIN]

An auto-assigned port number was requested but no auto-assigned ports
are available. Increasing the port range specified by sysctl(3) MIB
variables *net.inet.ip.portrange.first* and *net.inet.ip.portrange.last*
may alleviate the problem.

The following errors are specific to connecting names in the UNIX
domain. These errors may not apply in future versions of the UNIX IPC
domain.

[ENOTDIR]

A component of the path prefix is not a directory.

[ENAMETOOLONG]

A component of a pathname exceeded 255 characters, or an entire path
name exceeded 1023 characters.

[ENOENT]

The named socket does not exist.

[EACCES]

Search permission is denied for a component of the path prefix.

[EACCES]

Write access to the named socket is denied.

[ELOOP]

Too many symbolic links were encountered in translating the pathname.

[EPERM]

Write access to the named socket is denied.

**SEE ALSO**

accept(2), getpeername(2), getsockname(2), select(2), socket(2),
sysctl(3), sysctl(8)

**HISTORY**

The **connect**\ () system call appeared in 4.2BSD.

BSD August 18, 2016 BSD

--------------
