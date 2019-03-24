--------------

POSIX_SPAWNATTR_GETSI... BSD Library Functions Manual
POSIX_SPAWNATTR_GETSI...

**NAME**

**posix_spawnattr_getsigmask**, **posix_spawnattr_setsigmask** — get and
set the spawn-sigmask attribute of a spawn attributes object

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <spawn.h>**

*int*

**posix_spawnattr_getsigmask**\ (*const posix_spawnattr_t *restrict attr*,
*sigset_t *restrict sigmask*);

*int*

**posix_spawnattr_setsigmask**\ (*posix_spawnattr_t *attr*,
*const sigset_t *restrict sigmask*);

**DESCRIPTION**

The **posix_spawnattr_getsigmask**\ () function obtains the value of the
spawn-sigmask attribute from the attributes object referenced by *attr*.

The **posix_spawnattr_setsigmask**\ () function sets the spawn-sigmask
attribute in an initialized attributes object referenced by *attr*.

The spawn-sigmask attribute represents the signal mask in effect in the
new process image of a spawn operation (if POSIX_SPAWN_SETSIGMASK is set
in the spawn-flags attribute). The default value of this attribute is
unspecified.

**RETURN VALUES**

The **posix_spawnattr_getsigmask**\ () and
**posix_spawnattr_setsigmask**\ () functions return zero.

**SEE ALSO**

posix_spawn(3), posix_spawnattr_destroy(3),
posix_spawnattr_getsigmask(3), posix_spawnattr_init(3),
posix_spawnattr_setsigmask(3), posix_spawnp(3)

**STANDARDS**

The **posix_spawnattr_getsigmask**\ () and
**posix_spawnattr_setsigmask**\ () functions conform to IEEE Std
1003.1-2001 (‘‘POSIX.1’’).

**HISTORY**

The **posix_spawnattr_getsigmask**\ () and
**posix_spawnattr_setsigmask**\ () functions first appeared in
FreeBSD 8.0.

**AUTHORS**

Ed Schouten <*ed@FreeBSD.org*>

BSD March 24, 2008 BSD

--------------
