--------------

POSIX_SPAWNATTR_GETPG... BSD Library Functions Manual
POSIX_SPAWNATTR_GETPG...

**NAME**

**posix_spawnattr_getpgroup**, **posix_spawnattr_setpgroup** — get and
set the spawn-pgroup attribute of a spawn attributes object

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <spawn.h>**

*int*

**posix_spawnattr_getpgroup**\ (*const posix_spawnattr_t *restrict attr*,
*pid_t *restrict pgroup*);

*int*

**posix_spawnattr_setpgroup**\ (*posix_spawnattr_t *attr*,
*pid_t pgroup*);

**DESCRIPTION**

The **posix_spawnattr_getpgroup**\ () function obtains the value of the
spawn-pgroup attribute from the attributes object referenced by *attr*.

The **posix_spawnattr_setpgroup**\ () function sets the spawn-pgroup
attribute in an initialized attributes object referenced by *attr*.

The spawn-pgroup attribute represents the process group to be joined by
the new process image in a spawn operation (if POSIX_SPAWN_SETPGROUP is
set in the spawn-flags attribute). The default value of this attribute
is zero.

**RETURN VALUES**

The **posix_spawnattr_getpgroup**\ () and
**posix_spawnattr_setpgroup**\ () functions return zero.

**SEE ALSO**

posix_spawn(3), posix_spawnattr_destroy(3), posix_spawnattr_init(3),
posix_spawnp(3)

**STANDARDS**

The **posix_spawnattr_getpgroup**\ () and
**posix_spawnattr_setpgroup**\ () functions conform to IEEE Std
1003.1-2001 (‘‘POSIX.1’’).

**HISTORY**

The **posix_spawnattr_getpgroup**\ () and
**posix_spawnattr_setpgroup**\ () functions first appeared in
FreeBSD 8.0.

**AUTHORS**

Ed Schouten <*ed@FreeBSD.org*>

BSD March 24, 2008 BSD

--------------
