--------------

RTPRIO(2) BSD System Calls Manual RTPRIO(2)

**NAME**

**rtprio**, **rtprio_thread** — examine or modify realtime or idle
priority

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/types.h>
#include <sys/rtprio.h>**

*int*

**rtprio**\ (*int function*, *pid_t pid*, *struct rtprio *rtp*);

*int*

**rtprio_thread**\ (*int function*, *lwpid_t lwpid*,
*struct rtprio *rtp*);

**DESCRIPTION**

The **rtprio**\ () system call is used to lookup or change the realtime
or idle priority of a process, or the calling thread. The
**rtprio_thread**\ () system call is used to lookup or change the
realtime or idle priority of a thread.

The *function* argument specifies the operation to be performed.
RTP_LOOKUP to lookup the current priority, and RTP_SET to set the
priority.

For the **rtprio**\ () system call, the *pid* argument specifies the
process to operate on, 0 for the calling thread. When *pid* is non-zero,
the system call reports the highest priority in the process, or sets all
threads’ priority in the process, depending on value of the *function*
argument.

For the **rtprio_thread**\ () system call, the *lwpid* specifies the
thread to operate on, 0 for the calling thread.

The *\*rtp* argument is a pointer to a struct rtprio which is used to
specify the priority and priority type. This structure has the following
form:

struct rtprio {

+-----------------+-----------------+-----------------+-----------------+
|                 | u_short         | type;           |                 |
+-----------------+-----------------+-----------------+-----------------+
|                 | u_short prio;   |                 |                 |
+-----------------+-----------------+-----------------+-----------------+

};

The value of the *type* field may be RTP_PRIO_REALTIME for realtime
priorities, RTP_PRIO_NORMAL for normal priorities, and RTP_PRIO_IDLE for
idle priorities. The priority specified by the *prio* field ranges
between 0 and RTP_PRIO_MAX (usually 31). 0 is the highest possible
priority.

Realtime and idle priority is inherited through fork() and exec().

A realtime thread can only be preempted by a thread of equal or higher
priority, or by an interrupt; idle priority threads will run only when
no other real/normal priority thread is runnable. Higher real/idle
priority threads preempt lower real/idle priority threads. Threads of
equal real/idle priority are run round-robin.

**RETURN VALUES**

The **rtprio**\ () and **rtprio_thread**\ () functions return the
value 0 if successful; otherwise the value −1 is returned and the global
variable *errno* is set to indicate the error.

**ERRORS**

The **rtprio**\ () and **rtprio_thread**\ () system calls will fail if:

[EFAULT]

The rtp pointer passed to **rtprio**\ () or **rtprio_thread**\ () was
invalid.

[EINVAL]

The specified *prio* was out of range.

[EPERM]

The calling thread is not allowed to set the realtime priority. Only
root is allowed to change the realtime priority of any thread, and
non-root may only change the idle priority of threads the user owns,
when the sysctl(8) variable *security.bsd.unprivileged_idprio* is set to
non-zero.

[ESRCH]

The specified process or thread was not found or visible.

**SEE ALSO**

nice(1), ps(1), rtprio(1), setpriority(2), nice(3), renice(8),
p_cansee(9)

**AUTHORS**

The original author was Henrik Vestergaard Draboel
<*hvd@terry.ping.dk*>. This implementation in FreeBSD was substantially
rewritten by David Greenman. The **rtprio_thread**\ () system call was
implemented by David Xu.

BSD December 27, 2011 BSD

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

