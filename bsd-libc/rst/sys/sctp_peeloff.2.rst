--------------

SCTP_PEELOFF(2) BSD System Calls Manual SCTP_PEELOFF(2)

**NAME**

**sctp_peeloff** — detach an association from a one-to-many socket to
its own fd

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/sctp.h>**

*int*

**sctp_peeloff**\ (*int s*, *sctp_assoc_t id*);

**DESCRIPTION**

The **sctp_peeloff**\ () system call attempts detach the association
specified by *id* into its own separate socket.

**RETURN VALUES**

The call returns -1 on failure and the new socket descriptor upon
success.

**ERRORS**

The **sctp_peeloff**\ () system call can return the following errors:

[ENOTCONN]

The *id* given to the call does not map to a valid association.

[E2BIG]

The size of the address list exceeds the amount of data provided.

[EBADF]

The argument *s* is not a valid descriptor.

[ENOTSOCK]

The argument *s* is not a socket.

**SEE ALSO**

sctp(4)

BSD October 30, 2007 BSD

--------------
