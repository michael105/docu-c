--------------

GETGID(2) BSD System Calls Manual GETGID(2)

**NAME**

**getgid**, **getegid** — get group process identification

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <unistd.h>**

*gid_t*

**getgid**\ (*void*);

*gid_t*

**getegid**\ (*void*);

**DESCRIPTION**

The **getgid**\ () system call returns the real group ID of the calling
process, **getegid**\ () returns the effective group ID of the calling
process.

The real group ID is specified at login time.

The real group ID is the group of the user who invoked the program. As
the effective group ID gives the process additional permissions during
the execution of ‘‘\ *set-group-ID*\ ’’ mode processes, **getgid**\ ()
is used to determine the real-user-id of the calling process.

**ERRORS**

The **getgid**\ () and **getegid**\ () system calls are always
successful, and no return value is reserved to indicate an error.

**SEE ALSO**

getuid(2), issetugid(2), setgid(2), setregid(2)

**STANDARDS**

The **getgid**\ () and **getegid**\ () system calls are expected to
conform to ISO/IEC 9945-1:1990 (‘‘POSIX.1’’).

BSD December 15, 2015 BSD

--------------
