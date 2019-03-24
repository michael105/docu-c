--------------

RAISE(3) BSD Library Functions Manual RAISE(3)

**NAME**

**raise** — send a signal to the current thread

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <signal.h>**

*int*

**raise**\ (*int sig*);

**DESCRIPTION**

The **raise**\ () function sends the signal *sig* to the current thread.

**RETURN VALUES**

The **raise**\ () function returns the value 0 if successful; otherwise
the value −1 is returned and the global variable *errno* is set to
indicate the error.

**ERRORS**

The **raise**\ () function may fail and set *errno* for any of the
errors specified for the library functions getpid(2) and kill(2).

**SEE ALSO**

kill(2)

**STANDARDS**

The **raise**\ () function conforms to ISO/IEC 9899:1990 (‘‘ISO C90’’).

BSD May 7, 2010 BSD

--------------
