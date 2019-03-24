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
