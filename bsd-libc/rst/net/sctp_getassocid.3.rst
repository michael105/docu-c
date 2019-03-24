--------------

SCTP_GETASSOCID(3) BSD Library Functions Manual SCTP_GETASSOCID(3)

**NAME**

**sctp_getassocid** — return an association id for a specified socket
address

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/sctp.h>**

*sctp_assoc_t*

**sctp_getassocid**\ (*int s*, *struct sockaddr *addr*);

**DESCRIPTION**

The **sctp_getassocid**\ () call attempts to look up the specified
socket address *addr* and find the respective association
identification.

**RETURN VALUES**

The call returns the association id upon success and 0 is returned upon
failure.

**ERRORS**

The **sctp_getassocid**\ () function can return the following errors:

[ENOENT]

The address does not have an association setup to it.

[EBADF]

The argument *s* is not a valid descriptor.

[ENOTSOCK]

The argument *s* is not a socket.

**SEE ALSO**

sctp(4)

BSD December 15, 2006 BSD

--------------
