--------------

SLEEP(3) BSD Library Functions Manual SLEEP(3)

**NAME**

**sleep** — suspend thread execution for an interval measured in seconds

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <unistd.h>**

*unsigned int*

**sleep**\ (*unsigned int seconds*);

**DESCRIPTION**

The **sleep**\ () function suspends execution of the calling thread
until either *seconds* seconds have elapsed or a signal is delivered to
the thread and its action is to invoke a signal-catching function or to
terminate the thread or process. System activity may lengthen the sleep
by an indeterminate amount.

This function is implemented using nanosleep(2) by pausing for *seconds*
seconds or until a signal occurs. Consequently, in this implementation,
sleeping has no effect on the state of process timers, and there is no
special handling for SIGALRM.

**RETURN VALUES**

If the **sleep**\ () function returns because the requested time has
elapsed, the value returned will be zero. If the **sleep**\ () function
returns due to the delivery of a signal, the value returned will be the
unslept amount (the requested time minus the time actually slept) in
seconds.

**SEE ALSO**

nanosleep(2), usleep(3)

**STANDARDS**

The **sleep**\ () function conforms to ISO/IEC 9945-1:1990
(‘‘POSIX.1’’).

**HISTORY**

A **sleep**\ () function appeared in Version 7 AT&T UNIX.

BSD February 13, 1998 BSD

--------------
