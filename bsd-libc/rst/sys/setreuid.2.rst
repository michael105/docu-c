--------------

SETREUID(2) BSD System Calls Manual SETREUID(2)

**NAME**

**setreuid** — set real and effective user ID’s

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <unistd.h>**

*int*

**setreuid**\ (*uid_t ruid*, *uid_t euid*);

**DESCRIPTION**

The real and effective user IDs of the current process are set according
to the arguments. If *ruid* or *euid* is -1, the current uid is filled
in by the system. Unprivileged users may change the real user ID to the
effective user ID and vice-versa; only the super-user may make other
changes.

If the real user ID is changed (i.e. *ruid* is not -1) or the effective
user ID is changed to something other than the real user ID, then the
saved user ID will be set to the effective user ID.

The **setreuid**\ () system call has been used to swap the real and
effective user IDs in set-user-ID programs to temporarily relinquish the
set-user-ID value. This purpose is now better served by the use of the
seteuid(2) system call.

When setting the real and effective user IDs to the same value, the
standard **setuid**\ () system call is preferred.

**RETURN VALUES**

The **setreuid**\ () function returns the value 0 if successful;
otherwise the value −1 is returned and the global variable *errno* is
set to indicate the error.

| **ERRORS**
| [EPERM]

The current process is not the super-user and a change other than
changing the effective user-id to the real user-id was specified.

**SEE ALSO**

getuid(2), issetugid(2), seteuid(2), setuid(2)

**HISTORY**

The **setreuid**\ () system call appeared in 4.2BSD.

BSD February 8, 2001 BSD

--------------
