--------------

TCGETSID(3) BSD Library Functions Manual TCGETSID(3)

**NAME**

**tcgetsid** — get session ID associated with a controlling terminal

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/types.h>
#include <termios.h>**

*pid_t*

**tcgetsid**\ (*int fd*);

**DESCRIPTION**

The **tcgetsid**\ () function returns the process group ID of the
session leader for a controlling terminal specified by *fd*.

**ERRORS**

If an error occurs, **tcgetsid**\ () returns -1 and the global variable
*errno* is set to indicate the error, as follows:

[EBADF]

The *fd* argument is not a valid file descriptor.

[ENOTTY]

The calling process does not have a controlling terminal or the
underlying terminal device represented by *fd* is not the controlling
terminal.

**SEE ALSO**

getsid(2), setsid(2), tcgetpgrp(3), tcsetsid(3)

**STANDARDS**

The **tcgetsid**\ () function conforms to X/Open Portability Guide
Issue 4, Version 2 (‘‘XPG4.2’’).

BSD April 15, 2008 BSD

--------------
