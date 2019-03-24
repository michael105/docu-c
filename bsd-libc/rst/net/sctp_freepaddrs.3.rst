--------------

SCTP_FREEPADDRS(3) BSD Library Functions Manual SCTP_FREEPADDRS(3)

**NAME**

**sctp_freepaddrs**, **sctp_freeladdrs** — release the memory returned
from a previous call

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/sctp.h>**

*void*

**sctp_freepaddrs**\ (*struct sockaddr \**);

*void*

**sctp_freeladdrs**\ (*struct sockaddr \**);

**DESCRIPTION**

The **sctp_freepaddrs**\ () and **sctp_freeladdrs**\ () functions are
used to release the memory allocated by previous calls to
**sctp_getpaddrs**\ () or **sctp_getladdrs**\ () respectively.

**RETURN VALUES**

none.

**SEE ALSO**

sctp_getladdrs(3), sctp_getpaddrs(3), sctp(4)

BSD December 15, 2006 BSD

--------------
