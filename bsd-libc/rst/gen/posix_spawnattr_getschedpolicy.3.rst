--------------

POSIX_SPAWNATTR_GETSC... BSD Library Functions Manual
POSIX_SPAWNATTR_GETSC...

**NAME**

**posix_spawnattr_getschedpolicy**, **posix_spawnattr_setschedpolicy** —
get and set the spawn-schedpolicy attribute of a spawn attributes object

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <spawn.h>**

*int*

**posix_spawnattr_getschedpolicy**\ (*const posix_spawnattr_t *restrict attr*,
*int *restrict schedpolicy*);

*int*

**posix_spawnattr_setschedpolicy**\ (*posix_spawnattr_t *attr*,
*int schedpolicy*);

**DESCRIPTION**

The **posix_spawnattr_getschedpolicy**\ () function obtains the value of
the spawn-schedpolicy attribute from the attributes object referenced by
*attr*.

The **posix_spawnattr_setschedpolicy**\ () function sets the
spawn-schedpolicy attribute in an initialized attributes object
referenced by *attr*.

The spawn-schedpolicy attribute represents the scheduling policy to be
assigned to the new process image in a spawn operation (if
POSIX_SPAWN_SETSCHEDULER is set in the spawn-flags attribute). The
default value of this attribute is unspecified.

**RETURN VALUES**

The **posix_spawnattr_getschedpolicy**\ () and
**posix_spawnattr_setschedpolicy**\ () functions return zero.

**SEE ALSO**

posix_spawn(3), posix_spawnattr_destroy(3),
posix_spawnattr_getschedparam(3), posix_spawnattr_init(3),
posix_spawnattr_setschedparam(3), posix_spawnp(3)

**STANDARDS**

The **posix_spawnattr_getschedpolicy**\ () and
**posix_spawnattr_setschedpolicy**\ () functions conform to IEEE Std
1003.1-2001 (‘‘POSIX.1’’).

**HISTORY**

The **posix_spawnattr_getschedpolicy**\ () and
**posix_spawnattr_setschedpolicy**\ () functions first appeared in
FreeBSD 8.0.

**AUTHORS**

Ed Schouten <*ed@FreeBSD.org*>

BSD March 24, 2008 BSD

--------------
