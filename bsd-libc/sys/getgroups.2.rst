--------------

GETGROUPS(2) BSD System Calls Manual GETGROUPS(2)

**NAME**

**getgroups** — get group access list

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <unistd.h>**

*int*

**getgroups**\ (*int gidsetlen*, *gid_t *gidset*);

**DESCRIPTION**

The **getgroups**\ () system call gets the current group access list of
the user process and stores it in the array *gidset*. The *gidsetlen*
argument indicates the number of entries that may be placed in *gidset*.
The **getgroups**\ () system call returns the actual number of groups
returned in *gidset*. At least one and as many as {NGROUPS_MAX}+1 values
may be returned. If *gidsetlen* is zero, **getgroups**\ () returns the
number of supplementary group IDs associated with the calling process
without modifying the array pointed to by *gidset*.

The value of {NGROUPS_MAX} should be obtained using sysconf(3) to avoid
hard-coding it into the executable.

**RETURN VALUES**

A successful call returns the number of groups in the group set. A value
of -1 indicates that an error occurred, and the error code is stored in
the global variable *errno*.

**ERRORS**

The possible errors for **getgroups**\ () are:

[EINVAL]

The argument *gidsetlen* is smaller than the number of groups in the
group set.

[EFAULT]

The argument *gidset* specifies an invalid address.

**SEE ALSO**

setgroups(2), initgroups(3), sysconf(3)

**STANDARDS**

The **getgroups**\ () system call conforms to IEEE Std 1003.1-2008
(‘‘POSIX.1’’).

**HISTORY**

The **getgroups**\ () system call appeared in 4.2BSD.

BSD January 21, 2011 BSD

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

