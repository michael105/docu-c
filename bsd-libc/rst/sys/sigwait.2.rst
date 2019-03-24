--------------

SIGWAIT(2) BSD System Calls Manual SIGWAIT(2)

**NAME**

**sigwait** — select a set of signals

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <signal.h>**

*int*

**sigwait**\ (*const sigset_t * restrict set*, *int * restrict sig*);

**DESCRIPTION**

The **sigwait**\ () system call selects a set of signals, specified by
*set*. If none of the selected signals are pending, **sigwait**\ ()
waits until one or more of the selected signals has been generated. Then
**sigwait**\ () atomically clears one of the selected signals from the
set of pending signals (for the process or for the current thread) and
sets the location pointed to by *sig* to the signal number that was
cleared.

The signals specified by *set* should be blocked at the time of the call
to **sigwait**\ ().

If more than one thread is using **sigwait**\ () to wait for the same
signal, no more than one of these threads will return from
**sigwait**\ () with the signal number. If more than a single thread is
blocked in **sigwait**\ () for a signal when that signal is generated
for the process, it is unspecified which of the waiting threads returns
from **sigwait**\ (). If the signal is generated for a specific thread,
as by **pthread_kill**\ (), only that thread will return.

Should any of the multiple pending signals in the range SIGRTMIN to
SIGRTMAX be selected, it will be the lowest numbered one. The selection
order between realtime and non-realtime signals, or between multiple
pending non-realtime signals, is unspecified.

**IMPLEMENTATION NOTES**

The **sigwait**\ () function is implemented as a wrapper around the
**\__sys_sigwait**\ () system call, which retries the call on EINTR
error.

**RETURN VALUES**

If successful, **sigwait**\ () returns 0 and sets the location pointed
to by *sig* to the cleared signal number. Otherwise, an error number is
returned.

**ERRORS**

The **sigwait**\ () system call will fail if:

[EINVAL]

The *set* argument specifies one or more invalid signal numbers.

**SEE ALSO**

sigaction(2), sigpending(2), sigqueue(2), sigsuspend(2),
sigtimedwait(2), sigwaitinfo(2), pause(3), pthread_sigmask(3)

**STANDARDS**

The **sigwait**\ () function conforms to ISO/IEC 9945-1:1996
(‘‘POSIX.1’’).

BSD September 6, 2013 BSD

--------------
