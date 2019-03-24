--------------

POSIX_SPAWNATTR_GETSC... BSD Library Functions Manual
POSIX_SPAWNATTR_GETSC...

**NAME**

**posix_spawnattr_getschedparam**, **posix_spawnattr_setschedparam** —
get and set the spawn-schedparam attribute of a spawn attributes object

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <spawn.h>**

*int*

**posix_spawnattr_getschedparam**\ (*const posix_spawnattr_t *restrict attr*,
*struct sched_param *restrict schedparam*);

*int*

**posix_spawnattr_setschedparam**\ (*posix_spawnattr_t *attr*,
*const struct sched_param *restrict schedparam*);

**DESCRIPTION**

The **posix_spawnattr_getschedparam**\ () function obtains the value of
the spawn-schedparam attribute from the attributes object referenced by
*attr*.

The **posix_spawnattr_setschedparam**\ () function sets the
spawn-schedparam attribute in an initialized attributes object
referenced by *attr*.

The spawn-schedparam attribute represents the scheduling parameters to
be assigned to the new process image in a spawn operation (if
POSIX_SPAWN_SETSCHEDULER or POSIX_SPAWN_SETSCHEDPARAM is set in the
spawn-flags attribute). The default value of this attribute is
unspecified.

**RETURN VALUES**

The **posix_spawnattr_getschedparam**\ () and
**posix_spawnattr_setschedparam**\ () functions return zero.

**SEE ALSO**

posix_spawn(3), posix_spawnattr_destroy(3),
posix_spawnattr_getschedpolicy(3), posix_spawnattr_init(3),
posix_spawnattr_setschedpolicy(3), posix_spawnp(3)

**STANDARDS**

The **posix_spawnattr_getschedparam**\ () and
**posix_spawnattr_setschedparam**\ () functions conform to IEEE Std
1003.1-2001 (‘‘POSIX.1’’).

**HISTORY**

The **posix_spawnattr_getschedparam**\ () and
**posix_spawnattr_setschedparam**\ () functions first appeared in
FreeBSD 8.0.

**AUTHORS**

Ed Schouten <*ed@FreeBSD.org*>

BSD March 24, 2008 BSD

--------------
