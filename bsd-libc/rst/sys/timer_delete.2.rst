--------------

TIMER_DELETE(2) BSD System Calls Manual TIMER_DELETE(2)

**NAME**

**timer_delete** — delete a per-process timer (REALTIME)

**LIBRARY**

POSIX Real-time Library (librt, −lrt)

**SYNOPSIS**

**#include <time.h>**

*int*

**timer_delete**\ (*timer_t timerid*);

**DESCRIPTION**

The **timer_delete**\ () system call deletes the specified timer,
*timerid*, previously created by the timer_create(2) system call. If the
timer is armed when **timer_delete**\ () is called, the behavior is as
if the timer is automatically disarmed before removal. Pending signals
for the deleted timer are cleared.

**RETURN VALUES**

Upon successful completion, the value 0 is returned; otherwise the
value −1 is returned and the global variable *errno* is set to indicate
the error.

**ERRORS**

The **timer_delete**\ () system call will fail if:

[EINVAL]

The timer ID specified by *timerid* is not a valid timer ID.

**SEE ALSO**

timer_create(2)

**STANDARDS**

The **timer_delete**\ () system call conforms to IEEE Std 1003.1-2004
(‘‘POSIX.1’’).

**HISTORY**

Support for POSIX per-process timer first appeared in FreeBSD 7.0.

BSD September 11, 2000 BSD

--------------
