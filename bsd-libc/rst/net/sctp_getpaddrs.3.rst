--------------

SCTP_GETPADDRS(3) BSD Library Functions Manual SCTP_GETPADDRS(3)

**NAME**

**sctp_getpaddrs**, **sctp_getladdrs** — return a list of addresses to
the caller

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/sctp.h>**

*int*

**sctp_getpaddrs**\ (*int s*, *sctp_assoc_t asocid*,
*struct sockaddr **addrs*);

*int*

**sctp_getladdrs**\ (*int s*, *sctp_assoc_t asocid*,
*struct sockaddr **addrs*);

**DESCRIPTION**

The **sctp_getpaddrs**\ () function is used to get the list of the peers
addresses. The **sctp_getladdrs**\ () function is used to get the list
of the local addresses. The association of interest is identified by the
*asocid* argument. The addresses are returned in a newly allocated array
of socket addresses returned in the argument *addrs* upon success.

After the caller is finished, the function **sctp_freepaddrs**\ () or
**sctp_freeladdrs**\ () should be used to release the memory allocated
by these calls.

**RETURN VALUES**

The call returns -1 upon failure and a count of the number of addresses
returned in *addrs* upon success.

**ERRORS**

The functions can return the following errors:

[EINVAL]

An address listed has an invalid family or no addresses were provided.

[ENOMEM]

The call cannot allocate memory to hold the socket addresses.

[EBADF]

The argument *s* is not a valid descriptor.

[ENOTSOCK]

The argument *s* is not a socket.

**SEE ALSO**

getsockopt(2), sctp_freeladdrs(3), sctp_freepaddrs(3), sctp(4)

BSD December 15, 2006 BSD

--------------
