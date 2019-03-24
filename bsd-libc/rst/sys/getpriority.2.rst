--------------

GETPRIORITY(2) BSD System Calls Manual GETPRIORITY(2)

**NAME**

**getpriority**, **setpriority** — get/set program scheduling priority

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/time.h>
#include <sys/resource.h>**

*int*

**getpriority**\ (*int which*, *int who*);

*int*

**setpriority**\ (*int which*, *int who*, *int prio*);

**DESCRIPTION**

The scheduling priority of the process, process group, or user, as
indicated by *which* and *who* is obtained with the **getpriority**\ ()
system call and set with the **setpriority**\ () system call. The
*which* argument is one of PRIO_PROCESS, PRIO_PGRP, or PRIO_USER, and
*who* is interpreted relative to *which* (a process identifier for
PRIO_PROCESS, process group identifier for PRIO_PGRP, and a user ID for
PRIO_USER). A zero value of *who* denotes the current process, process
group, or user. The *prio* argument is a value in the range -20 to 20.
The default priority is 0; lower priorities cause more favorable
scheduling.

The **getpriority**\ () system call returns the highest priority (lowest
numerical value) enjoyed by any of the specified processes. The
**setpriority**\ () system call sets the priorities of all of the
specified processes to the specified value. Only the super-user may
lower priorities.

**RETURN VALUES**

Since **getpriority**\ () can legitimately return the value -1, it is
necessary to clear the external variable *errno* prior to the call, then
check it afterward to determine if a -1 is an error or a legitimate
value.

The **setpriority**\ () function returns the value 0 if successful;
otherwise the value −1 is returned and the global variable *errno* is
set to indicate the error.

**ERRORS**

The **getpriority**\ () and **setpriority**\ () system calls will fail
if:

[ESRCH]

No process was located using the *which* and *who* values specified.

[EINVAL]

The *which* argument was not one of PRIO_PROCESS, PRIO_PGRP, or
PRIO_USER.

In addition to the errors indicated above, **setpriority**\ () will fail
if:

[EPERM]

A process was located, but neither its effective nor real user ID
matched the effective user ID of the caller.

[EACCES]

A non super-user attempted to lower a process priority.

**SEE ALSO**

nice(1), fork(2), renice(8)

**HISTORY**

The **getpriority**\ () system call appeared in 4.2BSD.

BSD June 4, 1993 BSD

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

