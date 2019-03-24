--------------

SETRESUID(2) BSD System Calls Manual SETRESUID(2)

**NAME**

**getresgid**, **getresuid**, **setresgid**, **setresuid** — get or set
real, effective and saved user or group ID

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/types.h>
#include <unistd.h>**

*int*

**getresgid**\ (*gid_t *rgid*, *gid_t *egid*, *gid_t *sgid*);

*int*

**getresuid**\ (*uid_t *ruid*, *uid_t *euid*, *uid_t *suid*);

*int*

**setresgid**\ (*gid_t rgid*, *gid_t egid*, *gid_t sgid*);

*int*

**setresuid**\ (*uid_t ruid*, *uid_t euid*, *uid_t suid*);

**DESCRIPTION**

The **setresuid**\ () system call sets the real, effective and saved
user IDs of the current process. The analogous **setresgid**\ () sets
the real, effective and saved group IDs.

Privileged processes may set these IDs to arbitrary values. Unprivileged
processes are restricted in that each of the new IDs must match one of
the current IDs.

Passing -1 as an argument causes the corresponding value to remain
unchanged.

The **getresgid**\ () and **getresuid**\ () calls retrieve the real,
effective, and saved group and user IDs of the current process,
respectively.

**RETURN VALUES**

Upon successful completion, the value 0 is returned; otherwise the
value −1 is returned and the global variable *errno* is set to indicate
the error.

| **ERRORS**
| [EPERM]

The calling process was not privileged and tried to change one or more
IDs to a value which was not the current real ID, the current effective
ID nor the current saved ID.

[EFAULT]

An address passed to **getresgid**\ () or **getresuid**\ () was invalid.

**SEE ALSO**

getegid(2), geteuid(2), getgid(2), getuid(2), issetugid(2), setgid(2),
setregid(2), setreuid(2), setuid(2)

**HISTORY**

These functions first appeared in HP-UX.

BSD February 7, 2015 BSD

--------------
