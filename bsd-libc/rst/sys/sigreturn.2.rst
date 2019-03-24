--------------

SIGRETURN(2) BSD System Calls Manual SIGRETURN(2)

**NAME**

**sigreturn** — return from signal

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <signal.h>**

*int*

**sigreturn**\ (*const ucontext_t *scp*);

**DESCRIPTION**

The **sigreturn**\ () system call allows users to atomically unmask,
switch stacks, and return from a signal context. The thread’s signal
mask and stack status are restored from the context structure pointed to
by *scp*. The system call does not return; the users stack pointer,
frame pointer, argument pointer, and processor status longword are
restored from the context. Execution resumes at the specified pc. This
system call is used by the trampoline code and longjmp(3) when returning
from a signal to the previously executing program.

**RETURN VALUES**

If successful, the system call does not return. Otherwise, a value of -1
is returned and *errno* is set to indicate the error.

**ERRORS**

The **sigreturn**\ () system call will fail and the thread context will
remain unchanged if one of the following occurs.

[EFAULT]

The *scp* argument points to memory that is not a valid part of the
process address space.

[EINVAL]

The process status longword is invalid or would improperly raise the
privilege level of the process.

**SEE ALSO**

sigaction(2), setjmp(3), ucontext(3)

**HISTORY**

The **sigreturn**\ () system call appeared in 4.3BSD.

BSD September 6, 2013 BSD

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

