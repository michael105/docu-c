--------------

SIGSETOPS(3) BSD Library Functions Manual SIGSETOPS(3)

**NAME**

**sigemptyset**, **sigfillset**, **sigaddset**, **sigdelset**,
**sigismember** — manipulate signal sets

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <signal.h>**

*int*

**sigemptyset**\ (*sigset_t *set*);

*int*

**sigfillset**\ (*sigset_t *set*);

*int*

**sigaddset**\ (*sigset_t *set*, *int signo*);

*int*

**sigdelset**\ (*sigset_t *set*, *int signo*);

*int*

**sigismember**\ (*const sigset_t *set*, *int signo*);

**DESCRIPTION**

These functions manipulate signal sets stored in a *sigset_t*. Either
**sigemptyset**\ () or **sigfillset**\ () must be called for every
object of type *sigset_t* before any other use of the object.

The **sigemptyset**\ () function initializes a signal set to be empty.

The **sigfillset**\ () function initializes a signal set to contain all
signals.

The **sigaddset**\ () function adds the specified signal *signo* to the
signal set.

The **sigdelset**\ () function deletes the specified signal *signo* from
the signal set.

The **sigismember**\ () function returns whether a specified signal
*signo* is contained in the signal set.

**RETURN VALUES**

The **sigismember**\ () function returns 1 if the signal is a member of
the set, 0 otherwise. The other functions return 0 upon success. A −1
return value indicates an error occurred and the global variable *errno*
is set to indicate the reason.

**ERRORS**

These functions could fail if one of the following occurs:

[EINVAL]

*signo* has an invalid value.

**SEE ALSO**

kill(2), sigaction(2), sigpending(2), sigprocmask(2), sigsuspend(2)

**STANDARDS**

These functions are defined by IEEE Std 1003.1-1988 (‘‘POSIX.1’’).

BSD December 16, 2004 BSD

--------------
