--------------

SIGINTERRUPT(3) BSD Library Functions Manual SIGINTERRUPT(3)

**NAME**

**siginterrupt** — allow signals to interrupt system calls

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <signal.h>**

*int*

**siginterrupt**\ (*int sig*, *int flag*);

**DESCRIPTION**

The **siginterrupt**\ () function is used to change the system call
restart behavior when a system call is interrupted by the specified
signal. If the flag is false (0), then system calls will be restarted if
they are interrupted by the specified signal and no data has been
transferred yet. System call restart has been the default behavior since
4.2BSD, and is the default behaviour for signal(3) on FreeBSD.

If the flag is true (1), then restarting of system calls is disabled. If
a system call is interrupted by the specified signal and no data has
been transferred, the system call will return −1 with the global
variable *errno* set to EINTR. Interrupted system calls that have
started transferring data will return the amount of data actually
transferred. System call interrupt is the signal behavior found on
4.1BSD and AT&T System V UNIX systems.

Note that the new 4.2BSD signal handling semantics are not altered in
any other way. Most notably, signal handlers always remain installed
until explicitly changed by a subsequent sigaction(2) call, and the
signal mask operates as documented in sigaction(2). Programs may switch
between restartable and interruptible system call operation as often as
desired in the execution of a program.

Issuing a **siginterrupt**\ (*3*) call during the execution of a signal
handler will cause the new action to take place on the next signal to be
caught.

**NOTES**

This library routine uses an extension of the sigaction(2) system call
that is not available in 4.2BSD, hence it should not be used if backward
compatibility is needed.

**RETURN VALUES**

The **siginterrupt**\ () function returns the value 0 if successful;
otherwise the value −1 is returned and the global variable *errno* is
set to indicate the error.

**ERRORS**

The **siginterrupt**\ () call fails if:

[EINVAL]

The *sig* argument is not a valid signal number.

**SEE ALSO**

sigaction(2), sigprocmask(2), sigsuspend(2), signal(3)

**HISTORY**

The **siginterrupt**\ () function appeared in 4.3BSD.

BSD June 4, 1993 BSD

--------------
