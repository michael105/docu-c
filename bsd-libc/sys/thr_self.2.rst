--------------

THR_SELF(2) BSD System Calls Manual THR_SELF(2)

**NAME**

**thr_self** — return thread identifier for the calling thread

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/thr.h>**

*int*

**thr_self**\ (*long *id*);

**DESCRIPTION**

The **thr_self**\ () system call stores the system-wide thread
identifier for the current kernel-scheduled thread in the variable
pointed by the argument *id*.

The thread identifier is an integer in the range from PID_MAX + 2
(10002) to INT_MAX. The thread identifier is guaranteed to be unique at
any given time, for each running thread in the system. After the thread
exits, the identifier may be reused.

**RETURN VALUES**

If successful, **thr_self**\ () will return zero, otherwise −1 is
returned, and *errno* is set to indicate the error.

**ERRORS**

The **thr_self**\ () operation may return the following errors:

[EFAULT]

The memory pointed to by the *id* argument is not valid.

**SEE ALSO**

thr_exit(2), thr_kill(2), thr_kill2(2), thr_new(2), thr_set_name(2),
\_umtx_op(2), pthread_getthreadid_np(3), pthread_self(3)

**STANDARDS**

The **thr_self**\ () system call is non-standard and is used by 1:1
Threading Library (libthr, −lthr) to implement IEEE Std 1003.1-2001
(‘‘POSIX.1’’) pthread(3) functionality.

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

