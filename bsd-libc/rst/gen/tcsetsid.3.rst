--------------

TCSETSID(3) BSD Library Functions Manual TCSETSID(3)

**NAME**

**tcsetsid** — set session ID associated with a controlling terminal

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/types.h>
#include <termios.h>**

*int*

**tcsetsid**\ (*int fd*, *pid_t pid*);

**DESCRIPTION**

The **tcsetsid**\ () function sets associates a session identified by
*pid* with a controlling terminal specified by *fd*.

This implementation only allows the controlling terminal to be changed
by the session leader itself. This implies that *pid* always has to be
equal to the process ID.

It is unsupported to associate with a terminal that already has an
associated session. Conversely, it is also unsupported to associate to a
terminal when the session is already associated with a different
terminal.

**ERRORS**

If an error occurs, **tcsetsid**\ () returns -1 and the global variable
*errno* is set to indicate the error, as follows:

[EBADF]

The *fd* argument is not a valid file descriptor.

[ENOTTY]

The file descriptor represented by *fd* is not a terminal.

[EINVAL]

The *pid* argument is not equal to the session ID of the calling
process.

[EPERM]

The calling process is not a session leader.

[EPERM]

The session already has an associated terminal or the terminal already
has an associated session.

**SEE ALSO**

getsid(2), setsid(2), tcgetpgrp(3), tcgetsid(3)

**HISTORY**

A **tcsetsid**\ () function first appeared in QNX. It does not comply to
any standard.

BSD May 4, 2009 BSD

--------------
