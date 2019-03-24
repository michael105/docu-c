--------------

SCTP_GENERIC_SENDMSG(2) BSD System Calls Manual SCTP_GENERIC_SENDMSG(2)

**NAME**

**sctp_generic_sendmsg sctp_generic_sendmsg_iov** — send data to a peer

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/sctp.h>**

*int*

**sctp_generic_sendmsg**\ (*int s*, *void *msg*, *int msglen*,
*struct sockaddr *to*, *socklen_t len*, *struct sctp_sndrcvinfo *sinfo*,
*int flags*);

*int*

**sctp_generic_sendmsg_iov**\ (*int s*, *struct iovec *iov*,
*int iovlen*, *struct sockaddr *to*, *struct sctp_sndrcvinfo *sinfo*,
*int flags*);

**DESCRIPTION**

**sctp_generic_sendmsg**\ () and **sctp_generic_sendmsg_iov**\ () are
the true system calls used by the sctp_sendmsg(3) and sctp_send(3)
function calls. These are more efficient since they are true system
calls but they are specific to FreeBSD and can be expected *not* to be
present on any other operating system. For detailed usage please see
either the sctp_send(3) or sctp_sendmsg(3) function calls.

**RETURN VALUES**

The call returns the number of bytes written on success and -1 upon
failure.

| **ERRORS**
| [EBADF]

The argument *s* is not a valid descriptor.

[ENOTSOCK]

The argument *s* is not a socket.

**SEE ALSO**

sctp_send(3), sctp_sendmsg(3), sctp_sendmsgx(3), sctp_sendx(3), sctp(4)

BSD October 30, 2007 BSD

--------------
