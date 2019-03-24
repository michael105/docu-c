--------------

UALARM(3) BSD Library Functions Manual UALARM(3)

**NAME**

**ualarm** — schedule signal after specified time

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <unistd.h>**

*useconds_t*

**ualarm**\ (*useconds_t microseconds*, *useconds_t interval*);

**DESCRIPTION**

**This is a simplified interface to** setitimer(\ **2**)\ **.**

The **ualarm**\ () function waits a count of *microseconds* before
asserting the terminating signal SIGALRM. System activity or time used
in processing the call may cause a slight delay.

If the *interval* argument is non-zero, the SIGALRM signal will be sent
to the process every *interval* microseconds after the timer expires
(e.g. after *microseconds* number of microseconds have passed).

Due to setitimer(2) restriction the maximum number of *microseconds* and
*interval* is limited to 100000000000000 (in case this value fits in the
unsigned integer).

**RETURN VALUES**

When the signal has successfully been caught, **ualarm**\ () returns the
amount of time left on the clock.

**NOTES**

A microsecond is 0.000001 seconds.

**SEE ALSO**

getitimer(2), setitimer(2), sigaction(2), sigsuspend(2), alarm(3),
signal(3), sleep(3), usleep(3)

**HISTORY**

The **ualarm**\ () function appeared in 4.3BSD.

BSD April 19, 1994 BSD

--------------
