--------------

SEM_POST(3) BSD Library Functions Manual SEM_POST(3)

**NAME**

**sem_post** — increment (unlock) a semaphore

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <semaphore.h>**

*int*

**sem_post**\ (*sem_t *sem*);

**DESCRIPTION**

The **sem_post**\ () function increments (unlocks) the semaphore pointed
to by *sem*. If there are threads blocked on the semaphore when
**sem_post**\ () is called, then the highest priority thread that has
been blocked the longest on the semaphore will be allowed to return from
**sem_wait**\ ().

The **sem_post**\ () function is signal-reentrant and may be called
within signal handlers.

**RETURN VALUES**

The **sem_post**\ () function returns the value 0 if successful;
otherwise the value −1 is returned and the global variable *errno* is
set to indicate the error.

**ERRORS**

The **sem_post**\ () function will fail if:

[EINVAL]

The *sem* argument points to an invalid semaphore.

[EOVERFLOW]

The semaphore value would exceed SEM_VALUE_MAX.

**SEE ALSO**

sem_getvalue(3), sem_trywait(3), sem_wait(3)

**STANDARDS**

The **sem_post**\ () function conforms to ISO/IEC 9945-1:1996
(‘‘POSIX.1’’).

BSD January 28, 2015 BSD

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

