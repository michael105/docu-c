--------------

TCSETPGRP(3) BSD Library Functions Manual TCSETPGRP(3)

**NAME**

**tcsetpgrp** — set foreground process group ID

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/types.h>
#include <unistd.h>**

*int*

**tcsetpgrp**\ (*int fd*, *pid_t pgrp_id*);

**DESCRIPTION**

If the process has a controlling terminal, the **tcsetpgrp**\ ()
function sets the foreground process group ID associated with the
terminal device to *pgrp_id*. The terminal device associated with *fd*
must be the controlling terminal of the calling process and the
controlling terminal must be currently associated with the session of
the calling process. The value of *pgrp_id* must be the same as the
process group ID of a process in the same session as the calling
process.

**RETURN VALUES**

The **tcsetpgrp**\ () function returns the value 0 if successful;
otherwise the value −1 is returned and the global variable *errno* is
set to indicate the error.

**ERRORS**

The **tcsetpgrp**\ () function will fail if:

[EBADF]

The *fd* argument is not a valid file descriptor.

[EINVAL]

An invalid value of *pgrp_id* was specified.

[ENOTTY]

The calling process does not have a controlling terminal, or the file
represented by *fd* is not the controlling terminal, or the controlling
terminal is no longer associated with the session of the calling
process.

[EPERM]

The *pgrp_id* argument does not match the process group ID of a process
in the same session as the calling process.

**SEE ALSO**

setpgid(2), setsid(2), tcgetpgrp(3)

**STANDARDS**

The **tcsetpgrp**\ () function is expected to be compliant with the IEEE
Std 1003.1-1988 (‘‘POSIX.1’’) specification.

BSD June 4, 1993 BSD

--------------
