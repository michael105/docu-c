--------------

SCTP_GETADDRLEN(3) BSD Library Functions Manual SCTP_GETADDRLEN(3)

**NAME**

**sctp_getaddrlen** — return the address length of an address family

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/sctp.h>**

*int*

**sctp_getaddrlen**\ (*sa_family_t family*);

**DESCRIPTION**

The **sctp_getaddrlen**\ () function returns the size of a specific
address family. This function is provided for application binary
compatibility since it provides the application with the size the
operating system thinks the specific address family is. Note that the
function will actually create an SCTP socket and then gather the
information via a **getsockopt**\ () system calls. If for some reason a
SCTP socket cannot be created or the **getsockopt**\ () call fails, an
error will be returned with *errno* set as specified in the
**socket**\ () or **getsockopt**\ () system call.

**RETURN VALUES**

The call returns the number of bytes that the operating system expects
for the specific address family or -1.

**ERRORS**

The **sctp_getaddrlen**\ () function can return the following errors:

[EINVAL]

The address family specified does NOT exist.

**SEE ALSO**

getsockopt(2), socket(2), sctp(4)

BSD December 15, 2006 BSD

--------------
