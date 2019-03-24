--------------

CLOCK_GETTIME(2) BSD System Calls Manual CLOCK_GETTIME(2)

**NAME**

**clock_gettime**, **clock_settime**, **clock_getres** —
get/set/calibrate date and time

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <time.h>**

*int*

**clock_gettime**\ (*clockid_t clock_id*, *struct timespec *tp*);

*int*

**clock_settime**\ (*clockid_t clock_id*, *const struct timespec *tp*);

*int*

**clock_getres**\ (*clockid_t clock_id*, *struct timespec *tp*);

**DESCRIPTION**

The **clock_gettime**\ () and **clock_settime**\ () system calls allow
the calling process to retrieve or set the value used by a clock which
is specified by *clock_id*.

The *clock_id* argument can be a value obtained from
clock_getcpuclockid(3) or pthread_getcpuclockid(3) as well as the
following values:

| CLOCK_REALTIME
| CLOCK_REALTIME_PRECISE
| CLOCK_REALTIME_FAST

Increments as a wall clock should.

| CLOCK_MONOTONIC
| CLOCK_MONOTONIC_PRECISE
| CLOCK_MONOTONIC_FAST

Increments in SI seconds.

| CLOCK_UPTIME
| CLOCK_UPTIME_PRECISE
| CLOCK_UPTIME_FAST

Starts at zero when the kernel boots and increments monotonically in SI
seconds while the machine is running.

CLOCK_VIRTUAL

Increments only when the CPU is running in user mode on behalf of the
calling process.

CLOCK_PROF

Increments when the CPU is running in user or kernel mode.

CLOCK_SECOND

Returns the current second without performing a full time counter query,
using an in-kernel cached value of the current second.

CLOCK_PROCESS_CPUTIME_ID

Returns the execution time of the calling process.

CLOCK_THREAD_CPUTIME_ID

Returns the execution time of the calling thread.

The clock IDs *CLOCK_REALTIME_FAST*, *CLOCK_MONOTONIC_FAST*,
*CLOCK_UPTIME_FAST* are analogs of corresponding IDs without \_FAST
suffix but do not perform a full time counter query, so their accuracy
is one timer tick. Similarly, *CLOCK_REALTIME_PRECISE*,
*CLOCK_MONOTONIC_PRECISE*, *CLOCK_UPTIME_PRECISE* are used to get the
most exact value as possible, at the expense of execution time.

The structure pointed to by *tp* is defined in <*sys/timespec.h*> as:

struct timespec {

+-----------+-----------+-----------+-----------+-----------+-----------+
|           | time_t    | tv_sec;   |           | /\*       |           |
|           |           |           |           | seconds   |           |
|           |           |           |           | \*/       |           |
+-----------+-----------+-----------+-----------+-----------+-----------+
|           | long      | tv_nsec;  |           | /\* and   |           |
|           |           |           |           | nanosecon |           |
|           |           |           |           | ds        |           |
|           |           |           |           | \*/       |           |
+-----------+-----------+-----------+-----------+-----------+-----------+

};

Only the super-user may set the time of day, using only
*CLOCK_REALTIME*. If the system securelevel is greater than 1 (see
init(8)), the time may only be advanced. This limitation is imposed to
prevent a malicious super-user from setting arbitrary time stamps on
files. The system time can still be adjusted backwards using the
adjtime(2) system call even when the system is secure.

The resolution (granularity) of a clock is returned by the
**clock_getres**\ () system call. This value is placed in a (non-NULL)
*\*tp*.

**RETURN VALUES**

Upon successful completion, the value 0 is returned; otherwise the
value −1 is returned and the global variable *errno* is set to indicate
the error.

**ERRORS**

The following error codes may be set in *errno*:

[EINVAL]

The *clock_id* or *timespec* argument was not a valid value.

[EPERM]

A user other than the super-user attempted to set the time.

**SEE ALSO**

date(1), adjtime(2), clock_getcpuclockid(3), ctime(3),
pthread_getcpuclockid(3), timed(8)

**STANDARDS**

The **clock_gettime**\ (), **clock_settime**\ (), and
**clock_getres**\ () system calls conform to IEEE Std 1003.1b-1993
(‘‘POSIX.1’’). The clock IDs *CLOCK_REALTIME_FAST*,
*CLOCK_REALTIME_PRECISE*, *CLOCK_MONOTONIC_FAST*,
*CLOCK_MONOTONIC_PRECISE*, *CLOCK_UPTIME*, *CLOCK_UPTIME_FAST*,
*CLOCK_UPTIME_PRECISE*, *CLOCK_SECOND* are FreeBSD extensions to the
POSIX interface.

BSD March 20, 2017 BSD

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

