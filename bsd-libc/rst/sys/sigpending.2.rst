--------------

SIGPENDING(2) BSD System Calls Manual SIGPENDING(2)

**NAME**

**sigpending** — get pending signals

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <signal.h>**

*int*

**sigpending**\ (*sigset_t *set*);

**DESCRIPTION**

The **sigpending**\ () system call returns a mask of the signals pending
for delivery to the calling thread or the calling process in the
location indicated by *set*. Signals may be pending because they are
currently masked, or transiently before delivery (although the latter
case is not normally detectable).

**RETURN VALUES**

The **sigpending**\ () function returns the value 0 if successful;
otherwise the value −1 is returned and the global variable *errno* is
set to indicate the error.

**ERRORS**

The **sigpending**\ () system call will fail if:

[EFAULT]

The *set* argument specified an invalid address.

**SEE ALSO**

sigaction(2), sigprocmask(2), sigsuspend(2), sigsetops(3)

**STANDARDS**

The **sigpending**\ () system call is expected to conform to ISO/IEC
9945-1:1990 (‘‘POSIX.1’’).

BSD September 6, 2013 BSD

--------------
