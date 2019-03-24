--------------

SETRESUID(2) BSD System Calls Manual SETRESUID(2)

**NAME**

**getresgid**, **getresuid**, **setresgid**, **setresuid** — get or set
real, effective and saved user or group ID

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/types.h>
#include <unistd.h>**

*int*

**getresgid**\ (*gid_t *rgid*, *gid_t *egid*, *gid_t *sgid*);

*int*

**getresuid**\ (*uid_t *ruid*, *uid_t *euid*, *uid_t *suid*);

*int*

**setresgid**\ (*gid_t rgid*, *gid_t egid*, *gid_t sgid*);

*int*

**setresuid**\ (*uid_t ruid*, *uid_t euid*, *uid_t suid*);

**DESCRIPTION**

The **setresuid**\ () system call sets the real, effective and saved
user IDs of the current process. The analogous **setresgid**\ () sets
the real, effective and saved group IDs.

Privileged processes may set these IDs to arbitrary values. Unprivileged
processes are restricted in that each of the new IDs must match one of
the current IDs.

Passing -1 as an argument causes the corresponding value to remain
unchanged.

The **getresgid**\ () and **getresuid**\ () calls retrieve the real,
effective, and saved group and user IDs of the current process,
respectively.

**RETURN VALUES**

Upon successful completion, the value 0 is returned; otherwise the
value −1 is returned and the global variable *errno* is set to indicate
the error.

| **ERRORS**
| [EPERM]

The calling process was not privileged and tried to change one or more
IDs to a value which was not the current real ID, the current effective
ID nor the current saved ID.

[EFAULT]

An address passed to **getresgid**\ () or **getresuid**\ () was invalid.

**SEE ALSO**

getegid(2), geteuid(2), getgid(2), getuid(2), issetugid(2), setgid(2),
setregid(2), setreuid(2), setuid(2)

**HISTORY**

These functions first appeared in HP-UX.

BSD February 7, 2015 BSD

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

