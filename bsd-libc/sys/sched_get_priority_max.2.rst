--------------

SCHED_GET_PRIORITY_MAX(2) BSD System Calls Manual
SCHED_GET_PRIORITY_MAX(2)

**NAME**

**sched_get_priority_max**, **sched_get_priority_min**,
**sched_rr_get_interval** — get scheduling parameter limits

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sched.h>**

*int*

**sched_get_priority_max**\ (*int policy*);

*int*

**sched_get_priority_min**\ (*int policy*);

*int*

**sched_rr_get_interval**\ (*pid_t pid*, *struct timespec *interval*);

**DESCRIPTION**

The **sched_get_priority_max**\ () and **sched_get_priority_min**\ ()
system calls return the appropriate maximum or minimum, respectively,
for the scheduling policy specified by *policy*. The
**sched_rr_get_interval**\ () system call updates the *timespec*
structure referenced by the *interval* argument to contain the current
execution time limit (i.e., time quantum) for the process specified by
*pid*. If *pid* is zero, the current execution time limit for the
calling process is returned.

The value of *policy* should be one of the scheduling policy values
defined in *<sched.h>*:

[SCHED_FIFO]

First-in-first-out fixed priority scheduling with no round robin
scheduling;

[SCHED_OTHER]

The standard time sharing scheduler;

[SCHED_RR]

Round-robin scheduling across same priority processes.

**RETURN VALUES**

If successful, the **sched_get_priority_max**\ () and
**sched_get_priority_min**\ () system calls shall return the appropriate
maximum or minimum values, respectively. If unsuccessful, they shall
return a value of -1 and set *errno* to indicate the error.

The **sched_rr_get_interval**\ () function returns the value 0 if
successful; otherwise the value −1 is returned and the global variable
*errno* is set to indicate the error.

**ERRORS**

On failure *errno* will be set to the corresponding value:

[EINVAL]

The value of the *policy* argument does not represent a defined
scheduling policy.

[ENOSYS]

The **sched_get_priority_max**\ (), **sched_get_priority_min**\ (), and
**sched_rr_get_interval**\ () system calls are not supported by the
implementation.

[ESRCH]

No process can be found corresponding to that specified by *pid*.

**SEE ALSO**

sched_getparam(2), sched_getscheduler(2), sched_setparam(2),
sched_setscheduler(2)

**STANDARDS**

The **sched_get_priority_max**\ (), **sched_get_priority_min**\ (), and
**sched_rr_get_interval**\ () system calls conform to IEEE Std
1003.1b-1993 (‘‘POSIX.1’’).

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

