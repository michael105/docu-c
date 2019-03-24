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
