--------------

POSIX_SPAWNATTR_GETFL... BSD Library Functions Manual
POSIX_SPAWNATTR_GETFL...

**NAME**

**posix_spawnattr_getflags**, **posix_spawnattr_setflags** — get and set
the spawn-flags attribute of a spawn attributes object

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <spawn.h>**

*int*

**posix_spawnattr_getflags**\ (*const posix_spawnattr_t *restrict attr*,
*short *restrict flags*);

*int*

**posix_spawnattr_setflags**\ (*posix_spawnattr_t *attr*,
*short flags*);

**DESCRIPTION**

The **posix_spawnattr_getflags**\ () function obtains the value of the
spawn-flags attribute from the attributes object referenced by *attr*.

The **posix_spawnattr_setflags**\ () function sets the spawn-flags
attribute in an initialized attributes object referenced by *attr*.

The spawn-flags attribute is used to indicate which process attributes
are to be changed in the new process image when invoking
**posix_spawn**\ () or **posix_spawnp**\ (). It is the bitwise-inclusive
OR of zero or more of the following flags (see **posix_spawn**\ ()):

| POSIX_SPAWN_RESETIDS
| POSIX_SPAWN_SETPGROUP
| POSIX_SPAWN_SETSIGDEF
| POSIX_SPAWN_SETSIGMASK
| POSIX_SPAWN_SETSCHEDPARAM
| POSIX_SPAWN_SETSCHEDULER

These flags are defined in <*spawn.h*>. The default value of this
attribute is as if no flags were set.

**RETURN VALUES**

The **posix_spawnattr_getflags**\ () and
**posix_spawnattr_setflags**\ () functions return zero.

**SEE ALSO**

posix_spawn(3), posix_spawnattr_destroy(3), posix_spawnattr_init(3),
posix_spawnp(3)

**STANDARDS**

The **posix_spawnattr_getflags**\ () and
**posix_spawnattr_setflags**\ () functions conform to IEEE Std
1003.1-2001 (‘‘POSIX.1’’).

**HISTORY**

The **posix_spawnattr_getflags**\ () and
**posix_spawnattr_setflags**\ () functions first appeared in
FreeBSD 8.0.

**AUTHORS**

Ed Schouten <*ed@FreeBSD.org*>

BSD March 24, 2008 BSD

--------------
