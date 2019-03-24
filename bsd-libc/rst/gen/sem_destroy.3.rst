--------------

SEM_DESTROY(3) BSD Library Functions Manual SEM_DESTROY(3)

**NAME**

**sem_destroy** — destroy an unnamed semaphore

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <semaphore.h>**

*int*

**sem_destroy**\ (*sem_t *sem*);

**DESCRIPTION**

The **sem_destroy**\ () function destroys the unnamed semaphore pointed
to by *sem*. After a successful call to **sem_destroy**\ (), *sem* is
unusable until re-initialized by another call to sem_init(3).

**RETURN VALUES**

The **sem_destroy**\ () function returns the value 0 if successful;
otherwise the value −1 is returned and the global variable *errno* is
set to indicate the error.

**ERRORS**

The **sem_destroy**\ () function will fail if:

[EINVAL]

The *sem* argument points to an invalid semaphore.

[EBUSY]

There are currently threads blocked on the semaphore that *sem* points
to.

**SEE ALSO**

sem_init(3)

**STANDARDS**

The **sem_destroy**\ () function conforms to ISO/IEC 9945-1:1996
(‘‘POSIX.1’’).

POSIX does not define the behavior of **sem_destroy**\ () if called
while there are threads blocked on *sem*, but this implementation is
guaranteed to return −1 and set *errno* to EBUSY if there are threads
blocked on *sem*.

BSD February 15, 2000 BSD

--------------
