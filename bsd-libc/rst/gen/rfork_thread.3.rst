--------------

RFORK_THREAD(3) BSD Library Functions Manual RFORK_THREAD(3)

**NAME**

**rfork_thread** — create a rfork-based process thread

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <unistd.h>**

*pid_t*

**rfork_thread**\ (*int flags*, *void *stack*, *int (*func)(void *arg)*,
*void *arg*);

**DESCRIPTION**

**The rfork_thread**\ () **function has been deprecated in favor of**
pthread_create(\ **3**)\ **.**

The **rfork_thread**\ () function is a helper function for rfork(2). It
arranges for a new process to be created and the child process will call
the specified function with the specified argument, while running on the
supplied stack.

Using this function should avoid the need to implement complex stack
swap code.

**RETURN VALUES**

Upon successful completion, **rfork_thread**\ () returns the process ID
of the child process to the parent process. Otherwise, a value of -1 is
returned to the parent process, no child process is created, and the
global variable *errno* is set to indicate the error.

The child process context is not aware of a return from the
**rfork_thread**\ () function as it begins executing directly with the
supplied function.

**ERRORS**

See rfork(2) for error return codes.

**SEE ALSO**

fork(2), intro(2), minherit(2), rfork(2), vfork(2), pthread_create(3)

**HISTORY**

The **rfork_thread**\ () function first appeared in FreeBSD 4.3.

BSD February 6, 2011 BSD

--------------
