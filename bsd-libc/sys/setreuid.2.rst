--------------

SETREUID(2) BSD System Calls Manual SETREUID(2)

**NAME**

**setreuid** — set real and effective user ID’s

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <unistd.h>**

*int*

**setreuid**\ (*uid_t ruid*, *uid_t euid*);

**DESCRIPTION**

The real and effective user IDs of the current process are set according
to the arguments. If *ruid* or *euid* is -1, the current uid is filled
in by the system. Unprivileged users may change the real user ID to the
effective user ID and vice-versa; only the super-user may make other
changes.

If the real user ID is changed (i.e. *ruid* is not -1) or the effective
user ID is changed to something other than the real user ID, then the
saved user ID will be set to the effective user ID.

The **setreuid**\ () system call has been used to swap the real and
effective user IDs in set-user-ID programs to temporarily relinquish the
set-user-ID value. This purpose is now better served by the use of the
seteuid(2) system call.

When setting the real and effective user IDs to the same value, the
standard **setuid**\ () system call is preferred.

**RETURN VALUES**

The **setreuid**\ () function returns the value 0 if successful;
otherwise the value −1 is returned and the global variable *errno* is
set to indicate the error.

| **ERRORS**
| [EPERM]

The current process is not the super-user and a change other than
changing the effective user-id to the real user-id was specified.

**SEE ALSO**

getuid(2), issetugid(2), seteuid(2), setuid(2)

**HISTORY**

The **setreuid**\ () system call appeared in 4.2BSD.

BSD February 8, 2001 BSD

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

