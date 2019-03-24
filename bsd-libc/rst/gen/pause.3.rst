--------------

PAUSE(3) BSD Library Functions Manual PAUSE(3)

**NAME**

**pause** — stop until signal

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <unistd.h>**

*int*

**pause**\ (*void*);

**DESCRIPTION**

**Pause is made obsolete by** sigsuspend(2).

The **pause**\ () function forces a process to pause until a signal is
received from either the kill(2) function or an interval timer. (See
setitimer(2).) Upon termination of a signal handler started during a
**pause**\ (), the **pause**\ () call will return.

**RETURN VALUES**

Always returns −1.

**ERRORS**

The **pause**\ () function always returns:

[EINTR]

The call was interrupted.

**SEE ALSO**

kill(2), select(2), sigsuspend(2)

**HISTORY**

A **pause**\ () syscall appeared in Version 6 AT&T UNIX.

BSD June 4, 1993 BSD

--------------
