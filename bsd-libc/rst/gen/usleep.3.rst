--------------

USLEEP(3) BSD Library Functions Manual USLEEP(3)

**NAME**

**usleep** — suspend process execution for an interval measured in
microseconds

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <unistd.h>**

*int*

**usleep**\ (*useconds_t microseconds*);

**DESCRIPTION**

The **usleep**\ () function suspends execution of the calling process
until either *microseconds* microseconds have elapsed or a signal is
delivered to the process and its action is to invoke a signal-catching
function or to terminate the process. System activity may lengthen the
sleep by an indeterminate amount.

This function is implemented using nanosleep(2) by pausing for
*microseconds* microseconds or until a signal occurs. Consequently, in
this implementation, sleeping has no effect on the state of process
timers, and there is no special handling for SIGALRM.

**RETURN VALUES**

The **usleep**\ () function returns the value 0 if successful; otherwise
the value −1 is returned and the global variable *errno* is set to
indicate the error.

**ERRORS**

The **usleep**\ () function will fail if:

[EINTR]

A signal was delivered to the process and its action was to invoke a
signal-catching function.

**SEE ALSO**

nanosleep(2), sleep(3)

**HISTORY**

The **usleep**\ () function appeared in 4.3BSD.

BSD February 13, 1998 BSD

--------------
