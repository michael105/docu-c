--------------

DAEMON(3) BSD Library Functions Manual DAEMON(3)

**NAME**

**daemon** — run in the background

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <stdlib.h>**

*int*

**daemon**\ (*int nochdir*, *int noclose*);

*int*

**daemonfd**\ (*int chdirfd*, *int nullfd*);

**DESCRIPTION**

The **daemon**\ () function is for programs wishing to detach themselves
from the controlling terminal and run in the background as system
daemons.

Unless the argument *nochdir* is non-zero, **daemon**\ () changes the
current working directory to the root (*/*).

Unless the argument *noclose* is non-zero, **daemon**\ () will redirect
standard input, standard output, and standard error to */dev/null*.

The **daemonfd**\ () function is equivalent to the **daemon**\ ()
function except that arguments are the descriptors for the current
working directory and to the descriptor to */dev/null*.

If *chdirfd* is equal to (-1) the current working directory is not
changed.

If *nullfd* is equals to (-1) the redirection of standard input,
standard output, and standard error is not closed.

**RETURN VALUES**

The **daemon**\ () and **daemonfd**\ () functions return the value 0 if
successful; otherwise the value −1 is returned and the global variable
*errno* is set to indicate the error.

**ERRORS**

The **daemon**\ () and **daemonfd**\ () function may fail and set
*errno* for any of the errors specified for the library functions
fork(2) open(2,) and setsid(2).

**SEE ALSO**

fork(2), setsid(2), sigaction(2)

**HISTORY**

The **daemon**\ () function first appeared in 4.4BSD. The
**daemonfd**\ () function first appeared in FreeBSD 12.0.

**CAVEATS**

Unless the *noclose* argument is non-zero, **daemon**\ () will close the
first three file descriptors and redirect them to */dev/null*. Normally,
these correspond to standard input, standard output, and standard error.
However, if any of those file descriptors refer to something else, they
will still be closed, resulting in incorrect behavior of the calling
program. This can happen if any of standard input, standard output, or
standard error have been closed before the program was run. Programs
using **daemon**\ () should therefore either call **daemon**\ () before
opening any files or sockets, or verify that any file descriptors
obtained have values greater than 2.

The **daemon**\ () function temporarily ignores SIGHUP while calling
setsid(2) to prevent a parent session group leader’s calls to fork(2)
and then \_exit(2) from prematurely terminating the child process.

BSD December 23, 2017 BSD

--------------
