--------------

SYSTEM(3) BSD Library Functions Manual SYSTEM(3)

**NAME**

**system** — pass a command to the shell

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <stdlib.h>**

*int*

**system**\ (*const char *string*);

**DESCRIPTION**

The **system**\ () function hands the argument *string* to the command
interpreter sh(1). The calling process waits for the shell to finish
executing the command, ignoring SIGINT and SIGQUIT, and blocking
SIGCHLD.

If *string* is a NULL pointer, **system**\ () will return non-zero if
the command interpreter sh(1) is available, and zero if it is not.

**RETURN VALUES**

The **system**\ () function returns the exit status of the shell as
returned by waitpid(2), or −1 if an error occurred when invoking fork(2)
or waitpid(2). A return value of 127 means the execution of the shell
failed.

**SEE ALSO**

sh(1), execve(2), fork(2), waitpid(2), popen(3), posix_spawn(3)

**STANDARDS**

The **system**\ () function conforms to ISO/IEC 9899:1990 (‘‘ISO C90’’)
and is expected to be IEEE Std 1003.2 (‘‘POSIX.2’’) compatible.

**SECURITY CONSIDERATIONS**

The **system**\ () function is easily misused in a manner that enables a
malicious user to run arbitrary command, because all meta-characters
supported by sh(1) would be honored. User supplied parameters should
always be carefully santized before they appear in *string.*

BSD July 25, 2015 BSD

--------------
