--------------

GETUID(2) BSD System Calls Manual GETUID(2)

**NAME**

**getuid**, **geteuid** — get user identification

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <unistd.h>**

*uid_t*

**getuid**\ (*void*);

*uid_t*

**geteuid**\ (*void*);

**DESCRIPTION**

The **getuid**\ () system call returns the real user ID of the calling
process. The **geteuid**\ () system call returns the effective user ID
of the calling process.

The real user ID is that of the user who has invoked the program. As the
effective user ID gives the process additional permissions during
execution of ‘‘\ *set-user-ID*\ ’’ mode processes, **getuid**\ () is
used to determine the real-user-id of the calling process.

**ERRORS**

The **getuid**\ () and **geteuid**\ () system calls are always
successful, and no return value is reserved to indicate an error.

**SEE ALSO**

getgid(2), issetugid(2), setgid(2), setreuid(2), setuid(2)

**STANDARDS**

The **geteuid**\ () and **getuid**\ () system calls are expected to
conform to ISO/IEC 9945-1:1990 (‘‘POSIX.1’’).

**HISTORY**

The **getuid**\ () function appeared in Version 1 AT&T UNIX. The
**geteuid**\ () function appeared in Version 4 AT&T UNIX.

BSD December 1, 2017 BSD

--------------
