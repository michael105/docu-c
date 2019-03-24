--------------

KILLPG(2) BSD System Calls Manual KILLPG(2)

**NAME**

**killpg** — send signal to a process group

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/types.h>
#include <signal.h>**

*int*

**killpg**\ (*pid_t pgrp*, *int sig*);

**DESCRIPTION**

The **killpg**\ () function sends the signal *sig* to the process group
*pgrp*. See sigaction(2) for a list of signals. If *pgrp* is 0,
**killpg**\ () sends the signal to the sending process’s process group.

The sending process must be able to **kill**\ () at least one process in
the receiving process group.

**RETURN VALUES**

The **killpg**\ () function returns the value 0 if successful; otherwise
the value −1 is returned and the global variable *errno* is set to
indicate the error.

**ERRORS**

The **killpg**\ () function will fail and no signal will be sent if:

[EINVAL]

The *sig* argument is not a valid signal number.

[ESRCH]

No process can be found in the process group specified by *pgrp*.

[EPERM]

**kill**\ () returns EPERM for all processes in the process group.

**SEE ALSO**

getpgrp(2), kill(2), sigaction(2)

**HISTORY**

The **killpg**\ () function appeared in 4.0BSD.

BSD March 15, 2012 BSD

--------------
