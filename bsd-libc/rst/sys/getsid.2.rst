--------------

GETSID(2) BSD System Calls Manual GETSID(2)

**NAME**

**getsid** — get process session

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <unistd.h>**

*pid_t*

**getsid**\ (*pid_t pid*);

**DESCRIPTION**

The session ID of the process identified by *pid* is returned by
**getsid**\ (). If *pid* is zero, **getsid**\ () returns the session ID
of the current process.

**RETURN VALUES**

Upon successful completion, the **getsid**\ () system call returns the
session ID of the specified process; otherwise, it returns a value of -1
and sets errno to indicate an error.

**ERRORS**

The **getsid**\ () system call will succeed unless:

[ESRCH]

if there is no process with a process ID equal to *pid*.

Note that an implementation may restrict this system call to processes
within the same session ID as the calling process.

**SEE ALSO**

getpgid(2), getpgrp(2), setpgid(2), setsid(2), termios(4)

**HISTORY**

The **getsid**\ () system call appeared in FreeBSD 3.0. The
**getsid**\ () system call is derived from its usage in AT&T System V
UNIX.

BSD August 19, 1997 BSD

--------------
