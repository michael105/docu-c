--------------

ADJTIME(2) BSD System Calls Manual ADJTIME(2)

**NAME**

**adjtime** — correct the time to allow synchronization of the system
clock

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/time.h>**

*int*

**adjtime**\ (*const struct timeval *delta*,
*struct timeval *olddelta*);

**DESCRIPTION**

The **adjtime**\ () system call makes small adjustments to the system
time, as returned by gettimeofday(2), advancing or retarding it by the
time specified by the timeval *delta*. If *delta* is negative, the clock
is slowed down by incrementing it more slowly than normal until the
correction is complete. If *delta* is positive, a larger increment than
normal is used. The skew used to perform the correction is generally a
fraction of one percent. Thus, the time is always a monotonically
increasing function. A time correction from an earlier call to
**adjtime**\ () may not be finished when **adjtime**\ () is called
again. If *olddelta* is not a null pointer, the structure pointed to
will contain, upon return, the number of microseconds still to be
corrected from the earlier call.

This call may be used by time servers that synchronize the clocks of
computers in a local area network. Such time servers would slow down the
clocks of some machines and speed up the clocks of others to bring them
to the average network time.

The **adjtime**\ () system call is restricted to the super-user.

**RETURN VALUES**

The **adjtime**\ () function returns the value 0 if successful;
otherwise the value −1 is returned and the global variable *errno* is
set to indicate the error.

**ERRORS**

The **adjtime**\ () system call will fail if:

[EFAULT]

An argument points outside the process’s allocated address space.

[EPERM]

The process’s effective user ID is not that of the super-user.

**SEE ALSO**

date(1), gettimeofday(2), timed(8), timedc(8)

R. Gusella

and

S. Zatti , *
TSP: The Time Synchronization Protocol for UNIX 4.3BSD* .

**HISTORY**

The **adjtime**\ () system call appeared in 4.3BSD.

BSD June 4, 1993 BSD

--------------
