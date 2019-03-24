--------------

SEM_WAIT(3) BSD Library Functions Manual SEM_WAIT(3)

**NAME**

**sem_wait**, **sem_trywait** — decrement (lock) a semaphore

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <semaphore.h>**

*int*

**sem_wait**\ (*sem_t *sem*);

*int*

**sem_trywait**\ (*sem_t *sem*);

**DESCRIPTION**

The **sem_wait**\ () function decrements (locks) the semaphore pointed
to by *sem*, but blocks if the value of *sem* is zero, until the value
is non-zero and the value can be decremented.

The **sem_trywait**\ () function decrements (locks) the semaphore
pointed to by *sem* only if the value is non-zero. Otherwise, the
semaphore is not decremented and an error is returned.

**RETURN VALUES**

Upon successful completion, the value 0 is returned; otherwise the
value −1 is returned and the global variable *errno* is set to indicate
the error.

**ERRORS**

The **sem_wait**\ () and **sem_trywait**\ () functions will fail if:

[EINVAL]

The *sem* argument points to an invalid semaphore.

Additionally, **sem_wait**\ () will fail if:

[EINTR]

A signal interrupted this function.

Additionally, **sem_trywait**\ () will fail if:

[EAGAIN]

The semaphore value was zero, and thus could not be decremented.

**SEE ALSO**

sem_getvalue(3), sem_post(3), sem_timedwait(3)

**STANDARDS**

The **sem_wait**\ () and **sem_trywait**\ () functions conform to
ISO/IEC 9945-1:1996 (‘‘POSIX.1’’).

BSD April 16, 2013 BSD

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

