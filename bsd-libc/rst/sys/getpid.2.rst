--------------

GETPID(2) BSD System Calls Manual GETPID(2)

**NAME**

**getpid**, **getppid** — get parent or calling process identification

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <unistd.h>**

*pid_t*

**getpid**\ (*void*);

*pid_t*

**getppid**\ (*void*);

**DESCRIPTION**

The **getpid**\ () system call returns the process ID of the calling
process. Though the ID is guaranteed to be unique, it should *NOT* be
used for constructing temporary file names, for security reasons; see
mkstemp(3) instead.

The **getppid**\ () system call returns the process ID of the parent of
the calling process.

**ERRORS**

The **getpid**\ () and **getppid**\ () system calls are always
successful, and no return value is reserved to indicate an error.

**SEE ALSO**

fork(2), getpgrp(2), kill(2), setpgid(2), setsid(2), exec(3)

**STANDARDS**

The **getpid**\ () and **getppid**\ () system calls are expected to
conform to ISO/IEC 9945-1:1990 (‘‘POSIX.1’’).

**HISTORY**

The **getpid**\ () function appeared in Version 7 AT&T UNIX.

BSD December 15, 2015 BSD

--------------
