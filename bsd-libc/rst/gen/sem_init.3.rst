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
