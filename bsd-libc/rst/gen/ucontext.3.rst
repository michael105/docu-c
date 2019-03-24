--------------

UCONTEXT(3) BSD Library Functions Manual UCONTEXT(3)

**NAME**

**ucontext** — user thread context

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <ucontext.h>**

**DESCRIPTION**

The *ucontext_t* type is a structure type suitable for holding the
context for a user thread of execution. A thread’s context includes its
stack, saved registers, and list of blocked signals.

The *ucontext_t* structure contains at least these fields:

*ucontext_t \*uc_link*

context to assume when this one returns

*sigset_t uc_sigmask*

signals being blocked

*stack_t uc_stack*

stack area

*mcontext_t uc_mcontext*

saved registers

The *uc_link* field points to the context to resume when this context’s
entry point function returns. If *uc_link* is equal to NULL, then the
process exits when this context returns.

The *uc_mcontext* field is machine-dependent and should be treated as
opaque by portable applications.

The following functions are defined to manipulate *ucontext_t*
structures:

*int* **getcontext**\ (*ucontext_t \**); *
ucontext_t \** **getcontextx**\ (*void*); *
int* **setcontext**\ (*const ucontext_t \**); *
void* **makecontext**\ (*ucontext_t \**, *void* (*\**)(\ *void*), *int*,
*...*); *
int* **swapcontext**\ (*ucontext_t \**, *const ucontext_t \**);

**SEE ALSO**

sigaltstack(2), getcontext(3), getcontextx(3), makecontext(3)

BSD September 10, 2002 BSD

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

