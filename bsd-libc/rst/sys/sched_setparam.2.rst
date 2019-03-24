--------------

SCHED_SETPARAM(2) BSD System Calls Manual SCHED_SETPARAM(2)

**NAME**

**sched_setparam**, **sched_getparam** — set/get scheduling parameters

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sched.h>**

*int*

**sched_setparam**\ (*pid_t pid*, *const struct sched_param *param*);

*int*

**sched_getparam**\ (*pid_t pid*, *struct sched_param *param*);

**DESCRIPTION**

The **sched_setparam**\ () system call sets the scheduling parameters of
the process specified by *pid* to the values specified by the
*sched_param* structure pointed to by *param*. The value of the
*sched_priority* member in the *param* structure must be any integer
within the inclusive priority range for the current scheduling policy of
the process specified by *pid*. Higher numerical values for the priority
represent higher priorities.

In this implementation, if the value of *pid* is negative the system
call will fail.

If a process specified by *pid* exists and if the calling process has
permission, the scheduling parameters are set for the process whose
process ID is equal to *pid*.

If *pid* is zero, the scheduling parameters are set for the calling
process.

In this implementation, the policy of when a process can affect the
scheduling parameters of another process is specified in IEEE Std
1003.1b-1993 (‘‘POSIX.1’’) as a write-style operation.

The target process, whether it is running or not running, will resume
execution after all other runnable processes of equal or greater
priority have been scheduled to run.

If the priority of the process specified by the *pid* argument is set
higher than that of the lowest priority running process and if the
specified process is ready to run, the process specified by the *pid*
argument will preempt a lowest priority running process. Similarly, if
the process calling **sched_setparam**\ () sets its own priority lower
than that of one or more other nonempty process lists, then the process
that is the head of the highest priority list will also preempt the
calling process. Thus, in either case, the originating process might not
receive notification of the completion of the requested priority change
until the higher priority process has executed.

In this implementation, when the current scheduling policy for the
process specified by *pid* is normal timesharing (SCHED_OTHER, aka
SCHED_NORMAL when not POSIX-source) or the idle policy (SCHED_IDLE when
not POSIX-source) then the behavior is as if the process had been
running under SCHED_RR with a priority lower than any actual realtime
priority.

The **sched_getparam**\ () system call will return the scheduling
parameters of a process specified by *pid* in the *sched_param*
structure pointed to by *param*.

If a process specified by *pid* exists and if the calling process has
permission, the scheduling parameters for the process whose process ID
is equal to *pid* are returned.

In this implementation, the policy of when a process can obtain the
scheduling parameters of another process are detailed in IEEE Std
1003.1b-1993 (‘‘POSIX.1’’) as a read-style operation.

If *pid* is zero, the scheduling parameters for the calling process will
be returned. In this implementation, the *sched_getparam* system call
will fail if *pid* is negative.

**RETURN VALUES**

Upon successful completion, the value 0 is returned; otherwise the
value −1 is returned and the global variable *errno* is set to indicate
the error.

**ERRORS**

On failure *errno* will be set to the corresponding value:

[ENOSYS]

The system is not configured to support this functionality.

[EPERM]

The requesting process doesn not have permission as detailed in IEEE Std
1003.1b-1993 (‘‘POSIX.1’’).

[ESRCH]

No process can be found corresponding to that specified by *pid*.

[EINVAL]

For **sched_setparam**\ (): one or more of the requested scheduling
parameters is outside the range defined for the scheduling policy of the
specified *pid*.

**SEE ALSO**

sched_get_priority_max(2), sched_get_priority_min(2),
sched_getscheduler(2), sched_rr_get_interval(2), sched_setscheduler(2),
sched_yield(2)

**STANDARDS**

The **sched_setparam**\ () and **sched_getparam**\ () system calls
conform to IEEE Std 1003.1b-1993 (‘‘POSIX.1’’).

BSD March 12, 1998 BSD

--------------

.. Copyright (c) 1990, 1991, 1993
..	The Regents of the University of California.  All rights reserved.
..
.. This code is derived from software contributed to Berkeley by
.. Chris Torek and the American National Standards Committee X3,
.. on Information Processing Systems.
..
.. Redistribution and use in source and binary forms, with or without
.. modification, are permitted provided that the following conditions
.. are met:
.. 1. Redistributions of source code must retain the above copyright
..    notice, this list of conditions and the following disclaimer.
.. 2. Redistributions in binary form must reproduce the above copyright
..    notice, this list of conditions and the following disclaimer in the
..    documentation and/or other materials provided with the distribution.
.. 3. Neither the name of the University nor the names of its contributors
..    may be used to endorse or promote products derived from this software
..    without specific prior written permission.
..
.. THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
.. ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
.. IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
.. ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
.. FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
.. DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
.. OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
.. HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
.. LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
.. OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
.. SUCH DAMAGE.

