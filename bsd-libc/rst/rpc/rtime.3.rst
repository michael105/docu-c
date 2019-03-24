--------------

RTIME(3) BSD Library Functions Manual RTIME(3)

**NAME**

**rtime** — get remote time

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/types.h>
#include <sys/time.h>
#include <netinet/in.h>**

*int*

**rtime**\ (*struct sockaddr_in *addrp*, *struct timeval *timep*,
*struct timeval *timeout*);

**DESCRIPTION**

The **rtime**\ () function consults the Internet Time Server at the
address pointed to by *addrp* and returns the remote time in the
*timeval* struct pointed to by *timep*. Normally, the UDP protocol is
used when consulting the Time Server. The *timeout* argument specifies
how long the routine should wait before giving up when waiting for a
reply. If *timeout* is specified as NULL, however, the routine will
instead use TCP and block until a reply is received from the time
server.

**RETURN VALUES**

The **rtime**\ () function returns the value 0 if successful; otherwise
the value −1 is returned and the global variable *errno* is set to
indicate the error.

**SEE ALSO**

timed(8)

BSD November 22, 1987 BSD

--------------
