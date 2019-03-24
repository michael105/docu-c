--------------

SETSID(2) BSD System Calls Manual SETSID(2)

**NAME**

**setsid** — create session and set process group ID

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <unistd.h>**

*pid_t*

**setsid**\ (*void*);

**DESCRIPTION**

The **setsid**\ () system call creates a new session. The calling
process is the session leader of the new session, is the process group
leader of a new process group and has no controlling terminal. The
calling process is the only process in either the session or the process
group.

**RETURN VALUES**

Upon successful completion, the **setsid**\ () system call returns the
value of the process group ID of the new process group, which is the
same as the process ID of the calling process. If an error occurs,
**setsid**\ () returns -1 and the global variable *errno* is set to
indicate the error.

**ERRORS**

The **setsid**\ () system call will fail if:

[EPERM]

The calling process is already a process group leader, or the process
group ID of a process other than the calling process matches the process
ID of the calling process.

**SEE ALSO**

setpgid(2), tcgetpgrp(3), tcsetpgrp(3)

**STANDARDS**

The **setsid**\ () system call is expected to be compliant with the
ISO/IEC 9945-1:1990 (‘‘POSIX.1’’) specification.

BSD June 4, 1993 BSD

--------------
