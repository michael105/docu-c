--------------

POSIX_SPAWNATTR_INIT(3) BSD Library Functions Manual
POSIX_SPAWNATTR_INIT(3)

**NAME**

**posix_spawnattr_init**, **posix_spawnattr_destroy** — initialize and
destroy spawn attributes object

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <spawn.h>**

*int*

**posix_spawnattr_init**\ (*posix_spawnattr_t * attr*);

*int*

**posix_spawnattr_destroy**\ (*posix_spawnattr_t * attr*);

**DESCRIPTION**

The **posix_spawnattr_init**\ () function initializes a spawn attributes
object *attr* with the default value for all of the individual
attributes used by the implementation. Initializing an already
initialized spawn attributes object may cause memory to be leaked.

The **posix_spawnattr_destroy**\ () function destroys a spawn attributes
object. A destroyed *attr* attributes object can be reinitialized using
**posix_spawnattr_init**\ (). The object should not be used after it has
been destroyed.

A spawn attributes object is of type *posix_spawnattr_t* (defined in
<*spawn.h*>) and is used to specify the inheritance of process
attributes across a spawn operation.

The resulting spawn attributes object (possibly modified by setting
individual attribute values), is used to modify the behavior of
**posix_spawn**\ () or **posix_spawnp**\ (). After a spawn attributes
object has been used to spawn a process by a call to a
**posix_spawn**\ () or **posix_spawnp**\ (), any function affecting the
attributes object (including destruction) will not affect any process
that has been spawned in this way.

**RETURN VALUES**

Upon successful completion, **posix_spawnattr_init**\ () and
**posix_spawnattr_destroy**\ () return zero; otherwise, an error number
is returned to indicate the error.

**ERRORS**

The **posix_spawnattr_init**\ () function will fail if:

[ENOMEM]

Insufficient memory exists to initialize the spawn attributes object.

**SEE ALSO**

posix_spawn(3), posix_spawnp(3)

**STANDARDS**

The **posix_spawnattr_init**\ () and **posix_spawnattr_destroy**\ ()
functions conform to IEEE Std 1003.1-2001 (‘‘POSIX.1’’).

**HISTORY**

The **posix_spawnattr_init**\ () and **posix_spawnattr_destroy**\ ()
functions first appeared in FreeBSD 8.0.

**AUTHORS**

Ed Schouten <*ed@FreeBSD.org*>

BSD March 24, 2008 BSD

--------------
