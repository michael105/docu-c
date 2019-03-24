--------------

ALARM(3) BSD Library Functions Manual ALARM(3)

**NAME**

**alarm** — set signal timer alarm

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <unistd.h>**

*unsigned int*

**alarm**\ (*unsigned int seconds*);

**DESCRIPTION**

**This interface is made obsolete by** setitimer(\ **2**)\ **.**

The **alarm**\ () function sets a timer to deliver the signal SIGALRM to
the calling process after the specified number of *seconds*. If an alarm
has already been set with **alarm**\ () but has not been delivered,
another call to **alarm**\ () will supersede the prior call. The request
**alarm**\ (*0*) voids the current alarm and the signal SIGALRM will not
be delivered.

Due to setitimer(2) restriction the maximum number of *seconds* allowed
is 100000000.

**RETURN VALUES**

The return value of **alarm**\ () is the amount of time left on the
timer from a previous call to **alarm**\ (). If no alarm is currently
set, the return value is 0.

**SEE ALSO**

setitimer(2), sigaction(2), sigsuspend(2), signal(3), sleep(3),
ualarm(3), usleep(3)

**HISTORY**

An **alarm**\ () function appeared in Version 7 AT&T UNIX.

BSD April 19, 1994 BSD

--------------
