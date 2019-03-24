--------------

SIGSETMASK(2) BSD System Calls Manual SIGSETMASK(2)

**NAME**

**sigsetmask**, **sigblock** — manipulate current signal mask

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <signal.h>**

*int*

**sigsetmask**\ (*int mask*);

*int*

**sigblock**\ (*int mask*);

*int*

**sigmask**\ (*int signum*);

**DESCRIPTION**

**This interface is made obsolete by:** sigprocmask(2).

The **sigsetmask**\ () function sets the current signal mask to the
specified *mask*. Signals are blocked from delivery if the corresponding
bit in *mask* is a 1. The **sigblock**\ () function adds the signals in
the specified *mask* to the current signal mask, rather than overwriting
it as **sigsetmask**\ () does. The macro **sigmask**\ () is provided to
construct the mask for a given *signum*.

The system quietly disallows SIGKILL or SIGSTOP to be blocked.

**RETURN VALUES**

The **sigblock**\ () and **sigsetmask**\ () functions return the
previous set of masked signals.

**SEE ALSO**

kill(2), sigaction(2), sigprocmask(2), sigsuspend(2), sigvec(2),
sigsetops(3)

**HISTORY**

The **sigsetmask**\ () and **sigblock**\ () functions first appeared in
4.2BSD and have been deprecated.

BSD June 2, 1993 BSD

--------------
