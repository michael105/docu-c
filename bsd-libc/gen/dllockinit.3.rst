--------------

DLLOCKINIT(3) BSD Library Functions Manual DLLOCKINIT(3)

**NAME**

**dllockinit** — register thread locking methods with the dynamic linker

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <dlfcn.h>**

*void*

**dllockinit**\ (*void *context*, *void *(*lock_create)(void *context)*,
*void (*rlock_acquire)(void *lock)*,
*void (*wlock_acquire)(void *lock)*, *void (*lock_release)(void *lock)*,
*void (*lock_destroy)(void *lock)*,
*void (*context_destroy)(void *context)*);

**DESCRIPTION**

**Due to enhancements in the dynamic linker, this interface is no longer
needed. It is deprecated and will be removed from future releases. In
current releases it still exists, but only as a stub which does
nothing.**

Threads packages can call **dllockinit**\ () at initialization time to
register locking functions for the dynamic linker to use. This enables
the dynamic linker to prevent multiple threads from entering its
critical sections simultaneously.

The *context* argument specifies an opaque context for creating locks.
The dynamic linker will pass it to the *lock_create* function when
creating the locks it needs. When the dynamic linker is permanently
finished using the locking functions (e.g., if the program makes a
subsequent call to **dllockinit**\ () to register new locking functions)
it will call *context_destroy* to destroy the context.

The *lock_create* argument specifies a function for creating a
read/write lock. It must return a pointer to the new lock.

The *rlock_acquire* and *wlock_acquire* arguments specify functions
which lock a lock for reading or writing, respectively. The
*lock_release* argument specifies a function which unlocks a lock. Each
of these functions is passed a pointer to the lock.

The *lock_destroy* argument specifies a function to destroy a lock. It
may be NULL if locks do not need to be destroyed. The *context_destroy*
argument specifies a function to destroy the context. It may be NULL if
the context does not need to be destroyed.

Until **dllockinit**\ () is called, the dynamic linker protects its
critical sections using a default locking mechanism which works by
blocking the SIGVTALRM, SIGPROF, and SIGALRM signals. This is sufficient
for many application level threads packages, which typically use one of
these signals to implement preemption. An application which has
registered its own locking methods with **dllockinit**\ () can restore
the default locking by calling **dllockinit**\ () with all arguments
NULL.

**SEE ALSO**

rtld(1), signal(3)

**HISTORY**

The **dllockinit**\ () function first appeared in FreeBSD 4.0.

BSD July 5, 2000 BSD

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

