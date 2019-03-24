--------------

SEM_GETVALUE(3) BSD Library Functions Manual SEM_GETVALUE(3)

**NAME**

**sem_getvalue** — get the value of a semaphore

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <semaphore.h>**

*int*

**sem_getvalue**\ (*sem_t * restrict sem*, *int * restrict sval*);

**DESCRIPTION**

The **sem_getvalue**\ () function sets the variable pointed to by *sval*
to the current value of the semaphore pointed to by *sem*, as of the
time that the call to **sem_getvalue**\ () is actually run.

**RETURN VALUES**

The **sem_getvalue**\ () function returns the value 0 if successful;
otherwise the value −1 is returned and the global variable *errno* is
set to indicate the error.

**ERRORS**

The **sem_getvalue**\ () function will fail if:

[EINVAL]

The *sem* argument points to an invalid semaphore.

**SEE ALSO**

sem_post(3), sem_trywait(3), sem_wait(3)

**STANDARDS**

The **sem_getvalue**\ () function conforms to ISO/IEC 9945-1:1996
(‘‘POSIX.1’’).

The value of the semaphore is never negative, even if there are threads
blocked on the semaphore. POSIX is somewhat ambiguous in its wording
with regard to what the value of the semaphore should be if there are
blocked waiting threads, but this behavior is conformant, given the
wording of the specification.

BSD February 15, 2000 BSD

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

