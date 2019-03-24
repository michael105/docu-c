--------------

THR_kill(2) BSD System Calls Manual THR_kill(2)

**NAME**

**thr_kill** — send signal to thread

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/thr.h>**

*int*

**thr_kill**\ (*long id*, *int sig*);

*int*

**thr_kill2**\ (*pid_t pid*, *long id*, *int sig*);

**DESCRIPTION**

The **thr_kill**\ () and **thr_kill2**\ () system calls allow sending a
signal, specified by the *sig* argument, to some threads in a process.
For the **thr_kill**\ () function, signalled threads are always limited
to the current process. For the **thr_kill2**\ () function, the *pid*
argument specifies the process with threads to be signalled.

The *id* argument specifies which threads get the signal. If *id* is
equal to −1, all threads in the specified process are signalled.
Otherwise, only the thread with the thread identifier equal to the
argument is signalled.

The *sig* argument defines the delivered signal. It must be a valid
signal number or zero. In the latter case no signal is actually sent,
and the call is used to verify the liveness of the thread.

The signal is delivered with siginfo si_code set to SI_LWP.

**RETURN VALUES**

If successful, **thr_kill**\ () and **thr_kill2**\ () will return zero,
otherwise −1 is returned, and *errno* is set to indicate the error.

**ERRORS**

The **thr_kill**\ () and **thr_kill2**\ () operations return the
following errors:

[EINVAL]

The *sig* argument is not zero and does not specify valid signal.

[ESRCH]

The specified process or thread was not found.

Additionally, the **thr_kill2**\ () may return the following errors:

[EPERM]

The current process does not have sufficient privilege to check
existence or send a signal to the specified process.

**SEE ALSO**

kill(2), thr_exit(2), thr_new(2), thr_self(2), thr_set_name(2),
\_umtx_op(2), pthread_kill(3), signal(3)

**STANDARDS**

The **thr_kill**\ () and **thr_kill2**\ () system calls are non-standard
and are used by the 1:1 Threading Library (libthr, −lthr) to implement
IEEE Std 1003.1-2001 (‘‘POSIX.1’’) pthread(3) functionality.

BSD June 1, 2016 BSD

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

