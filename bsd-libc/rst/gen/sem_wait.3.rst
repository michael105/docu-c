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
