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

.. Copyright (c) 1990, 1991, 1993
..	The Regents of the University of California.  All rights reserved.
..
.. This code is derived from software contributed to Berkeley by
.. Chris Torek and the American National Standards Committee X3,
.. on Information Processing Systems.
..
.. Redistribution and use in source and binary forms, with or without
.. modification, are permitted provided that the following conditions
.. are met:
.. 1. Redistributions of source code must retain the above copyright
..    notice, this list of conditions and the following disclaimer.
.. 2. Redistributions in binary form must reproduce the above copyright
..    notice, this list of conditions and the following disclaimer in the
..    documentation and/or other materials provided with the distribution.
.. 3. Neither the name of the University nor the names of its contributors
..    may be used to endorse or promote products derived from this software
..    without specific prior written permission.
..
.. THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
.. ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
.. IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
.. ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
.. FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
.. DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
.. OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
.. HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
.. LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
.. OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
.. SUCH DAMAGE.

