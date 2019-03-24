--------------

THR_SUSPEND(2) BSD System Calls Manual THR_SUSPEND(2)

**NAME**

**thr_suspend** — suspend the calling thread

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/thr.h>**

*int*

**thr_suspend**\ (*struct timespec *timeout*);

**DESCRIPTION**

**This function is intended for implementing threading. Normal
applications should use** pthread_cond_timedwait(\ **3**) **together
with** pthread_cond_broadcast(\ **3**) **for typical safe suspension
with cooperation of the thread being suspended, or**
pthread_suspend_np(\ **3**) **and** pthread_resume_np(\ **3**) **in some
specific situations, instead.**

The **thr_suspend**\ () system call puts the calling thread in a
suspended state, where it is not eligible for CPU time. This state is
exited by another thread calling thr_wake(2), when the time interval
specified by *timeout* has elapsed, or by the delivery of a signal to
the suspended thread.

If the *timeout* argument is NULL, the suspended state can be only
terminated by explicit **thr_wake**\ () or signal.

If a wake from thr_wake(2) was delivered before the **thr_suspend**
call, the thread is not put into a suspended state. Instead, the call
returns immediately without an error.

If a thread previously called thr_wake(2) with its own thread
identifier, which resulted in setting the internal kernel flag to
immediately abort interruptible sleeps with an EINTR error (

see thr_wake(2) ), the flag is cleared. As with thr_wake(2) called from
another thread, the next **thr_suspend** call does not result in
suspension.

**RETURN VALUES**

The **thr_suspend**\ () function returns the value 0 if successful;
otherwise the value −1 is returned and the global variable *errno* is
set to indicate the error.

**ERRORS**

The **thr_suspend**\ () operation returns the following errors:

[EFAULT]

The memory pointed to by the *timeout* argument is not valid.

[ETIMEDOUT]

The specified timeout expired.

[ETIMEDOUT]

The *timeout* argument specified a zero time interval.

[EINTR]

The sleep was interrupted by a signal.

**SEE ALSO**

ps(1), thr_wake(2), pthread_resume_np(3), pthread_suspend_np(3)

**STANDARDS**

The **thr_suspend**\ () system call is non-standard.

BSD September 23, 2016 BSD

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

