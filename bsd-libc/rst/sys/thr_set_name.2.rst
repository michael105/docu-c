--------------

THR_SET_NAME(2) BSD System Calls Manual THR_SET_NAME(2)

**NAME**

**thr_set_name** — set user-visible thread name

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/thr.h>**

*int*

**thr_set_name**\ (*long id*, *const char *name*);

**DESCRIPTION**

The **thr_set_name**\ () system call sets the user-visible name for the
thread with the identifier *id* in the current process to the
NUL-terminated string *name*. The name will be silently truncated to fit
into a buffer of MAXCOMLEN + 1 bytes. The thread name can be seen in the
output of the ps(1) and top(1) commands, in the kernel debuggers and
kernel tracing facility outputs, and in userland debuggers and program
core files, as notes.

**RETURN VALUES**

If successful, **thr_set_name**\ () returns zero; otherwise, −1 is
returned, and *errno* is set to indicate the error.

**ERRORS**

The **thr_set_name**\ () system call may return the following errors:

[EFAULT]

The memory pointed to by the *name* argument is not valid.

[ESRCH]

The thread with the identifier *id* does not exist in the current
process.

**SEE ALSO**

ps(1), thr_exit(2), thr_kill(2), thr_kill2(2), thr_new(2), thr_self(2),
\_umtx_op(2), pthread_set_name_np(3), ddb(4), ktr(9)

**STANDARDS**

The **thr_set_name**\ () system call is non-standard and is used by the
1:1 Threading Library (libthr, −lthr).

BSD December 2, 2016 BSD

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

