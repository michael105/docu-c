--------------

CLOCK_GETCPUCLOCKID(3) BSD Library Functions Manual
CLOCK_GETCPUCLOCKID(3)

**NAME**

**clock_getcpuclockid** — access a process CPU-time clock

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <time.h>**

*int*

**clock_getcpuclockid**\ (*pid_t pid*, *clockid_t *clock_id*);

**DESCRIPTION**

The **clock_getcpuclockid**\ () returns the clock ID of the CPU-time
clock of the process specified by *pid*. If the process described by
*pid* exists and the calling process has permission, the clock ID of
this clock will be returned in *clock_id*.

If *pid* is zero, the **clock_getcpuclockid**\ () function returns the
clock ID of the CPU-time clock of the process making the call, in
*clock_id*.

**RETURN VALUES**

Upon successful completion, **clock_getcpuclockid**\ () returns zero;
otherwise, an error number is returned to indicate the error.

**ERRORS**

The **clock_getcpuclockid**\ () function will fail if:

[EPERM]

The requesting process does not have permission to access the CPU-time
clock for the process.

[ESRCH]

No process can be found corresponding to the process specified by *pid*.

**SEE ALSO**

clock_gettime(2)

**STANDARDS**

The **clock_getcpuclockid**\ () function conforms to IEEE Std
1003.1-2001 (‘‘POSIX.1’’).

**HISTORY**

The **clock_getcpuclockid**\ () function first appeared in FreeBSD 10.0.

**AUTHORS**

David Xu <*davidxu@FreeBSD.org*>

BSD August 21, 2012 BSD

--------------
