--------------

SETREGID(2) BSD System Calls Manual SETREGID(2)

**NAME**

**setregid** — set real and effective group ID

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <unistd.h>**

*int*

**setregid**\ (*gid_t rgid*, *gid_t egid*);

**DESCRIPTION**

The real and effective group ID’s of the current process are set to the
arguments. If the real group ID is changed, the saved group ID is
changed to the new value of the effective group ID.

Unprivileged users may change the real group ID to the effective group
ID and vice-versa; only the super-user may make other changes.

Supplying a value of -1 for either the real or effective group ID forces
the system to substitute the current ID in place of the -1 argument.

The **setregid**\ () system call was intended to allow swapping the real
and effective group IDs in set-group-ID programs to temporarily
relinquish the set-group-ID value. This system call did not work
correctly, and its purpose is now better served by the use of the
setegid(2) system call.

When setting the real and effective group IDs to the same value, the
standard **setgid**\ () system call is preferred.

**RETURN VALUES**

The **setregid**\ () function returns the value 0 if successful;
otherwise the value −1 is returned and the global variable *errno* is
set to indicate the error.

| **ERRORS**
| [EPERM]

The current process is not the super-user and a change other than
changing the effective group-id to the real group-id was specified.

**SEE ALSO**

getgid(2), issetugid(2), setegid(2), setgid(2), setuid(2)

**HISTORY**

The **setregid**\ () system call appeared in 4.2BSD.

BSD April 16, 1994 BSD

--------------
