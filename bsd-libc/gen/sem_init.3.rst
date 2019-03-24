--------------

SEM_INIT(3) BSD Library Functions Manual SEM_INIT(3)

**NAME**

**sem_init** — initialize an unnamed semaphore

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <semaphore.h>**

*int*

**sem_init**\ (*sem_t *sem*, *int pshared*, *unsigned int value*);

**DESCRIPTION**

The **sem_init**\ () function initializes the unnamed semaphore pointed
to by *sem* to have the value *value*.

A non-zero value for *pshared* specifies a shared semaphore that can be
used by multiple processes, the semaphore should be located in shared
memory region (see mmap(2), shm_open(2), and shmget(2)), any process
having read and write access to address *sem* can perform semaphore
operations on *sem*.

Following a successful call to **sem_init**\ (), *sem* can be used as an
argument in subsequent calls to sem_wait(3), sem_trywait(3),
sem_post(3), and sem_destroy(3). The *sem* argument is no longer valid
after a successful call to sem_destroy(3).

**RETURN VALUES**

The **sem_init**\ () function returns the value 0 if successful;
otherwise the value −1 is returned and the global variable *errno* is
set to indicate the error.

**ERRORS**

The **sem_init**\ () function will fail if:

[EINVAL]

The *value* argument exceeds SEM_VALUE_MAX.

[ENOSPC]

Memory allocation error.

**SEE ALSO**

sem_destroy(3), sem_getvalue(3), sem_post(3), sem_trywait(3),
sem_wait(3)

**STANDARDS**

The **sem_init**\ () function conforms to ISO/IEC 9945-1:1996
(‘‘POSIX.1’’).

BSD January 9, 2010 BSD

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

