--------------

PSELECT(2) BSD System Calls Manual PSELECT(2)

**NAME**

**pselect** — synchronous I/O multiplexing a la POSIX.1g

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/select.h>**

*int*

**pselect**\ (*int nfds*, *fd_set * restrict readfds*,
*fd_set * restrict writefds*, *fd_set * restrict exceptfds*,
*const struct timespec * restrict timeout*,
*const sigset_t * restrict newsigmask*);

**DESCRIPTION**

The **pselect**\ () function was introduced by IEEE Std 1003.1g-2000
(‘‘POSIX.1’’) as a slightly stronger version of select(2). The *nfds*,
*readfds*, *writefds*, and *exceptfds* arguments are all identical to
the analogous arguments of **select**\ (). The *timeout* argument in
**pselect**\ () points to a *const struct timespec* rather than the
(modifiable) *struct timeval* used by **select**\ (); as in
**select**\ (), a null pointer may be passed to indicate that
**pselect**\ () should wait indefinitely. Finally, *newsigmask*
specifies a signal mask which is set while waiting for input. When
**pselect**\ () returns, the original signal mask is restored.

See select(2) for a more detailed discussion of the semantics of this
interface, and for macros used to manipulate the *fd_set* data type.

**RETURN VALUES**

The **pselect**\ () function returns the same values and under the same
conditions as **select**\ ().

**ERRORS**

The **pselect**\ () function may fail for any of the reasons documented
for select(2) and (if a signal mask is provided) sigprocmask(2).

**SEE ALSO**

kqueue(2), poll(2), select(2), sigprocmask(2), sigsuspend(2)

**STANDARDS**

The **pselect**\ () function conforms to IEEE Std 1003.1-2001
(‘‘POSIX.1’’).

**HISTORY**

The **pselect**\ () function first appeared in FreeBSD 5.0.

**AUTHORS**

The first implementation of **pselect**\ () function and this manual
page were written by Garrett Wollman <*wollman@FreeBSD.org*>.

BSD August 16, 2013 BSD

--------------
