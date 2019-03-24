--------------

POSIX_SPAWNATTR_GETSI... BSD Library Functions Manual
POSIX_SPAWNATTR_GETSI...

**NAME**

**posix_spawnattr_getsigdefault**, **posix_spawnattr_setsigdefault** —
get and set the spawn-sigdefault attribute of a spawn attributes object

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <spawn.h>**

*int*

**posix_spawnattr_getsigdefault**\ (*const posix_spawnattr_t *restrict attr*,
*sigset_t *restrict sigdefault*);

*int*

**posix_spawnattr_setsigdefault**\ (*posix_spawnattr_t *attr*,
*const sigset_t *restrict sigdefault*);

**DESCRIPTION**

The **posix_spawnattr_getsigdefault**\ () function obtains the value of
the spawn-sigdefault attribute from the attributes object referenced by
*attr*.

The **posix_spawnattr_setsigdefault**\ () function sets the
spawn-sigdefault attribute in an initialized attributes object
referenced by *attr*.

The spawn-sigdefault attribute represents the set of signals to be
forced to default signal handling in the new process image (if
POSIX_SPAWN_SETSIGDEF is set in the spawn-flags attribute) by a spawn
operation. The default value of this attribute is an empty signal set.

**RETURN VALUES**

The **posix_spawnattr_getsigdefault**\ () and
**posix_spawnattr_setsigdefault**\ () functions return zero.

**SEE ALSO**

posix_spawn(3), posix_spawnattr_destroy(3),
posix_spawnattr_getsigmask(3), posix_spawnattr_init(3),
posix_spawnattr_setsigmask(3), posix_spawnp(3)

**STANDARDS**

The **posix_spawnattr_getsigdefault**\ () and
**posix_spawnattr_setsigdefault**\ () functions conform to IEEE Std
1003.1-2001 (‘‘POSIX.1’’).

**HISTORY**

The **posix_spawnattr_getsigdefault**\ () and
**posix_spawnattr_setsigdefault**\ () functions first appeared in
FreeBSD 8.0.

**AUTHORS**

Ed Schouten <*ed@FreeBSD.org*>

BSD March 24, 2008 BSD

--------------
