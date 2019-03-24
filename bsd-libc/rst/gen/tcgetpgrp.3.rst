--------------

TCGETPGRP(3) BSD Library Functions Manual TCGETPGRP(3)

**NAME**

**tcgetpgrp** — get foreground process group ID

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/types.h>
#include <unistd.h>**

*pid_t*

**tcgetpgrp**\ (*int fd*);

**DESCRIPTION**

The **tcgetpgrp**\ () function returns the value of the process group ID
of the foreground process group associated with the terminal device. If
there is no foreground process group, **tcgetpgrp**\ () returns an
invalid process ID.

**ERRORS**

If an error occurs, **tcgetpgrp**\ () returns -1 and the global variable
*errno* is set to indicate the error, as follows:

[EBADF]

The *fd* argument is not a valid file descriptor.

[ENOTTY]

The calling process does not have a controlling terminal or the
underlying terminal device represented by *fd* is not the controlling
terminal.

**SEE ALSO**

setpgid(2), setsid(2), tcsetpgrp(3)

**STANDARDS**

The **tcgetpgrp**\ () function is expected to be compliant with the IEEE
Std 1003.1-1988 (‘‘POSIX.1’’) specification.

BSD June 4, 1993 BSD

--------------
