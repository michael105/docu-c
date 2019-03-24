--------------

SETRUID(3) BSD Library Functions Manual SETRUID(3)

**NAME**

**setruid**, **setrgid** — set user and group ID

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <unistd.h>**

*int*

**setruid**\ (*uid_t ruid*);

*int*

**setrgid**\ (*gid_t rgid*);

**DESCRIPTION**

The **setruid**\ () function (**setrgid**\ ()) sets the real user ID
(group ID) of the current process.

**RETURN VALUES**

Upon successful completion, the value 0 is returned; otherwise the
value −1 is returned and the global variable *errno* is set to indicate
the error.

**COMPATIBILITY**

The use of these calls is not portable. Their use is discouraged; they
will be removed in the future.

**ERRORS**

The functions fail if:

[EPERM]

The user is not the super user and the ID specified is not the real or
effective ID.

**SEE ALSO**

getgid(2), getuid(2), setegid(2), seteuid(2), setgid(2), setuid(2)

**HISTORY**

The **setruid**\ () and **setrgid**\ () syscalls appeared in 4.2BSD and
were dropped in 4.4BSD.

BSD June 2, 1993 BSD

--------------
