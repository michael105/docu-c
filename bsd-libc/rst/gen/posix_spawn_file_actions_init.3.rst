--------------

POSIX_SPAWN_FILE_ACTI... BSD Library Functions Manual
POSIX_SPAWN_FILE_ACTI...

**NAME**

**posix_spawn_file_actions_init**, **posix_spawn_file_actions_destroy**
— initialize and destroy spawn file actions object

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <spawn.h>**

*int*

**posix_spawn_file_actions_init**\ (*posix_spawn_file_actions_t * file_actions*);

*int*

**posix_spawn_file_actions_destroy**\ (*posix_spawn_file_actions_t * file_actions*);

**DESCRIPTION**

The **posix_spawn_file_actions_init**\ () function initialize the object
referenced by **file_actions**\ () to contain no file actions for
**posix_spawn**\ () or **posix_spawnp**\ (). Initializing an already
initialized spawn file actions object may cause memory to be leaked.

The **posix_spawn_file_actions_destroy**\ () function destroy the object
referenced by *file_actions*; the object becomes, in effect,
uninitialized. A destroyed spawn file actions object can be
reinitialized using **posix_spawn_file_actions_init**\ (). The object
should not be used after it has been destroyed.

**RETURN VALUES**

Upon successful completion, these functions return zero; otherwise, an
error number is returned to indicate the error.

**ERRORS**

The **posix_spawn_file_actions_init**\ () function will fail if:

[ENOMEM]

Insufficient memory exists to initialize the spawn file actions object.

**SEE ALSO**

posix_spawn(3), posix_spawn_file_actions_addclose(3),
posix_spawn_file_actions_adddup2(3),
posix_spawn_file_actions_addopen(3), posix_spawnp(3)

**STANDARDS**

The **posix_spawn_file_actions_init**\ () and
**posix_spawn_file_actions_destroy**\ () functions conform to IEEE Std
1003.1-2001 (‘‘POSIX.1’’).

**HISTORY**

The **posix_spawn_file_actions_init**\ () and
**posix_spawn_file_actions_destroy**\ () functions first appeared in
FreeBSD 8.0.

**AUTHORS**

Ed Schouten <*ed@FreeBSD.org*>

BSD March 24, 2008 BSD

--------------
