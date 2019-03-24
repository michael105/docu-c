--------------

SCHED_YIELD(2) BSD System Calls Manual SCHED_YIELD(2)

**NAME**

**sched_yield** — yield processor

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sched.h>**

*int*

**sched_yield**\ (*void*);

**DESCRIPTION**

The **sched_yield**\ () system call forces the running process to
relinquish the processor until it again becomes the head of its process
list. It takes no arguments.

**RETURN VALUES**

The **sched_yield**\ () function returns the value 0 if successful;
otherwise the value −1 is returned and the global variable *errno* is
set to indicate the error.

**ERRORS**

On failure *errno* will be set to the corresponding value:

[ENOSYS]

The system is not configured to support this functionality.

**STANDARDS**

The **sched_yield**\ () system call conforms to IEEE Std 1003.1b-1993
(‘‘POSIX.1’’).

BSD March 12, 1998 BSD

--------------
