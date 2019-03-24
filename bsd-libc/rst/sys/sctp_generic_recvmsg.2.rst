--------------

SCTP_GENERIC_RECVMSG(2) BSD System Calls Manual SCTP_GENERIC_RECVMSG(2)

**NAME**

**sctp_generic_recvmsg** — receive data from a peer

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/sctp.h>**

*int*

**sctp_generic_recvmsg**\ (*int s*, *struct iovec *iov*, *int iovlen*,
*struct sockaddr *from*, *socklen_t *fromlen*,
*struct sctp_sndrcvinfo *sinfo*, *int *msgflags*);

**DESCRIPTION**

**sctp_generic_recvmsg**\ () is the true system call used by the
sctp_recvmsg(3) function call. This call is more efficient since it is a
true system call but it is specific to FreeBSD and can be expected *not*
to be present on any other operating system. For detailed usage please
see the sctp_recvmsg(3) function call.

**RETURN VALUES**

The call returns the number of bytes read on success and -1 upon
failure.

| **ERRORS**
| [EBADF]

The argument *s* is not a valid descriptor.

[ENOTSOCK]

The argument *s* is not a socket.

**SEE ALSO**

sctp_recvmsg(3), sctp(4)

BSD October 30, 2007 BSD

--------------
