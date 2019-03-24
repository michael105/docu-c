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

