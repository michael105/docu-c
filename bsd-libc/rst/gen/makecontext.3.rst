--------------

MAKECONTEXT(3) BSD Library Functions Manual MAKECONTEXT(3)

**NAME**

**makecontext**, **swapcontext** — modify and exchange user thread
contexts

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <ucontext.h>**

*void*

**makecontext**\ (*ucontext_t *ucp*, *void *\ (*\*func*)(\ *void*),
*int argc*, *...*);

*int*

**swapcontext**\ (*ucontext_t *oucp*, *const ucontext_t *ucp*);

**DESCRIPTION**

The **makecontext**\ () function modifies the user thread context
pointed to by *ucp*, which must have previously been initialized by a
call to getcontext(3) and had a stack allocated for it. The context is
modified so that it will continue execution by invoking **func**\ ()
with the arguments provided. The *argc* argument must be equal to the
number of additional arguments of type *int* provided to
**makecontext**\ () and also equal to the number of arguments of type
*int* to **func**\ (); otherwise , the behavior is undefined.

The *ucp->uc_link* argument must be initialized before calling
**makecontext**\ () and determines the action to take when **func**\ ()
returns: if equal to NULL, the process exits; otherwise,
**setcontext**\ (*ucp->uc_link*) is implicitly invoked.

The **swapcontext**\ () function saves the current thread context in
*\*oucp* and makes *\*ucp* the currently active context.

**RETURN VALUES**

If successful, **swapcontext**\ () returns zero; otherwise −1 is
returned and the global variable *errno* is set appropriately.

**ERRORS**

The **swapcontext**\ () function will fail if:

[ENOMEM]

There is not enough stack space in *ucp* to complete the operation.

**SEE ALSO**

setcontext(3), ucontext(3)

BSD January 31, 2018 BSD

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

