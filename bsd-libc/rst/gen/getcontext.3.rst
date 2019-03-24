--------------

GETCONTEXT(3) BSD Library Functions Manual GETCONTEXT(3)

**NAME**

**getcontext**, **getcontextx**, **setcontext** — get and set user
thread context

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <ucontext.h>**

*int*

**getcontext**\ (*ucontext_t *ucp*);

*ucontext_t \**

**getcontextx**\ (*void*);

*int*

**setcontext**\ (*const ucontext_t *ucp*);

**DESCRIPTION**

The **getcontext**\ () function saves the current thread’s execution
context in the structure pointed to by *ucp*. This saved context may
then later be restored by calling **setcontext**\ ().

The **getcontextx**\ () function saves the current execution context in
the newly allocated structure *ucontext_t*, which is returned on
success. If architecture defines additional CPU states that can be
stored in extended blocks referenced from the *ucontext_t*, the memory
for them may be allocated and their context also stored. Memory returned
by **getcontextx**\ () function shall be freed using **free**\ (*3*).

The **setcontext**\ () function makes a previously saved thread context
the current thread context, i.e., the current context is lost and
**setcontext**\ () does not return. Instead, execution continues in the
context specified by *ucp*, which must have been previously initialized
by a call to **getcontext**\ (), makecontext(3), or by being passed as
an argument to a signal handler (see sigaction(2)).

If *ucp* was initialized by **getcontext**\ (), then execution continues
as if the original **getcontext**\ () call had just returned (again).

If *ucp* was initialized by makecontext(3), execution continues with the
invocation of the function specified to makecontext(3). When that
function returns, *ucp->uc_link* determines what happens next: if
*ucp->uc_link* is NULL, the process exits; otherwise,
**setcontext**\ (*ucp->uc_link*) is implicitly invoked.

If *ucp* was initialized by the invocation of a signal handler,
execution continues at the point the thread was interrupted by the
signal.

**RETURN VALUES**

If successful, **getcontext**\ () returns zero and **setcontext**\ ()
does not return; otherwise −1 is returned. The **getcontextx**\ ()
returns pointer to the allocated and initialized context on success, and
*NULL* on failure.

**ERRORS**

No errors are defined for **getcontext**\ () or **setcontext**\ (). The
**getcontextx**\ () may return the following errors in *errno*:

[ENOMEM]

No memory was available to allocate for the context or some extended
state.

**SEE ALSO**

sigaction(2), sigaltstack(2), makecontext(3), ucontext(3)

BSD March 13, 2013 BSD

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

