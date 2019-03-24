--------------

RCMDSH(3) BSD Library Functions Manual RCMDSH(3)

**NAME**

**rcmdsh** — return a stream to a remote command without superuser

**SYNOPSIS**

**#include <unistd.h>**

*int*

**rcmdsh**\ (*char **ahost*, *int inport*, *const char *locuser*,
*const char *remuser*, *const char *cmd*, *const char *rshprog*);

**DESCRIPTION**

The **rcmdsh**\ () function is used by normal users to execute a command
on a remote machine using an authentication scheme based on reserved
port numbers using rshd(8) or the value of *rshprog* (if non-NULL).

The **rcmdsh**\ () function looks up the host *\*ahost* using
gethostbyname(3), returning −1 if the host does not exist. Otherwise
*\*ahost* is set to the standard name of the host and a connection is
established to a server residing at the well-known Internet port
‘‘shell/tcp’’ (or whatever port is used by *rshprog*). The *inport*
argument is ignored; it is only included to provide an interface similar
to rcmd(3).

If the connection succeeds, a socket in the UNIX domain of type
SOCK_STREAM is returned to the caller, and given to the remote command
as stdin, stdout, and stderr.

**RETURN VALUES**

The **rcmdsh**\ () function returns a valid socket descriptor on
success. Otherwise, −1 is returned and a diagnostic message is printed
on the standard error.

**SEE ALSO**

rsh(1), socketpair(2), rcmd(3), rshd(8)

**HISTORY**

The **rcmdsh**\ () function first appeared in OpenBSD 2.0, and made its
way into FreeBSD 4.6.

**BUGS**

If rsh(1) encounters an error, a file descriptor is still returned
instead of −1.

BSD September 1, 1996 BSD

--------------
