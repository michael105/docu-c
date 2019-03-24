--------------

RFORK_THREAD(3) BSD Library Functions Manual RFORK_THREAD(3)

**NAME**

**rfork_thread** — create a rfork-based process thread

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <unistd.h>**

*pid_t*

**rfork_thread**\ (*int flags*, *void *stack*, *int (*func)(void *arg)*,
*void *arg*);

**DESCRIPTION**

**The rfork_thread**\ () **function has been deprecated in favor of**
pthread_create(\ **3**)\ **.**

The **rfork_thread**\ () function is a helper function for rfork(2). It
arranges for a new process to be created and the child process will call
the specified function with the specified argument, while running on the
supplied stack.

Using this function should avoid the need to implement complex stack
swap code.

**RETURN VALUES**

Upon successful completion, **rfork_thread**\ () returns the process ID
of the child process to the parent process. Otherwise, a value of -1 is
returned to the parent process, no child process is created, and the
global variable *errno* is set to indicate the error.

The child process context is not aware of a return from the
**rfork_thread**\ () function as it begins executing directly with the
supplied function.

**ERRORS**

See rfork(2) for error return codes.

**SEE ALSO**

fork(2), intro(2), minherit(2), rfork(2), vfork(2), pthread_create(3)

**HISTORY**

The **rfork_thread**\ () function first appeared in FreeBSD 4.3.

BSD February 6, 2011 BSD

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

