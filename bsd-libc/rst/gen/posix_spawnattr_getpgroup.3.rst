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

