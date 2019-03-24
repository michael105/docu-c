--------------

BINDRESVPORT(3) BSD Library Functions Manual BINDRESVPORT(3)

**NAME**

**bindresvport**, **bindresvport_sa** — bind a socket to a privileged IP
port

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/types.h>
#include <rpc/rpc.h>**

*int*

**bindresvport**\ (*int sd*, *struct sockaddr_in *sin*);

*int*

**bindresvport_sa**\ (*int sd*, *struct sockaddr *sa*);

**DESCRIPTION**

The **bindresvport**\ () and **bindresvport_sa**\ () functions are used
to bind a socket descriptor to a privileged IP port, that is, a port
number in the range 0-1023.

If *sin* is a pointer to a *struct sockaddr_in* then the appropriate
fields in the structure should be defined. Note that *sin->sin_family*
must be initialized to the address family of the socket, passed by *sd*.
If *sin->sin_port* is ‘0’ then an anonymous port (in the range 600-1023)
will be chosen, and if bind(2) is successful, the *sin->sin_port* will
be updated to contain the allocated port.

If *sin* is the NULL pointer, an anonymous port will be allocated (as
above). However, there is no way for **bindresvport**\ () to return the
allocated port in this case.

Only root can bind to a privileged port; this call will fail for any
other users.

Function prototype of **bindresvport**\ () is biased to AF_INET socket.
The **bindresvport_sa**\ () function acts exactly the same, with more
neutral function prototype. Note that both functions behave exactly the
same, and both support AF_INET6 sockets as well as AF_INET sockets.

**RETURN VALUES**

The **bindresvport**\ () function returns the value 0 if successful;
otherwise the value −1 is returned and the global variable *errno* is
set to indicate the error.

| **ERRORS**
| [EPFNOSUPPORT]

If second argument was supplied, and address family did not match
between arguments.

The **bindresvport**\ () function may also fail and set *errno* for any
of the errors specified for the calls bind(2), getsockopt(2), or
setsockopt(2).

**SEE ALSO**

bind(2), getsockopt(2), setsockopt(2), ip(4)

BSD November 22, 1987 BSD

--------------
