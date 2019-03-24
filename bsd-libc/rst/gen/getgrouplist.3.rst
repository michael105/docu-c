--------------

GETGROUPLIST(3) BSD Library Functions Manual GETGROUPLIST(3)

**NAME**

**getgrouplist** — calculate group access list

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <unistd.h>**

*int*

**getgrouplist**\ (*const char *name*, *gid_t basegid*, *gid_t *groups*,
*int *ngroups*);

**DESCRIPTION**

The **getgrouplist**\ () function reads through the group file and
calculates the group access list for the user specified in *name*. The
*basegid* is automatically included in the groups list. Typically this
value is given as the group number from the password file.

The resulting group list is returned in the array pointed to by
*groups*. The caller specifies the size of the *groups* array in the
integer pointed to by *ngroups*; the actual number of groups found is
returned in *ngroups*.

**RETURN VALUES**

The **getgrouplist**\ () function returns 0 on success and −1 if the
size of the group list is too small to hold all the user’s groups. Here,
the group array will be filled with as many groups as will fit.

| **FILES**
| /etc/group

group membership list

**SEE ALSO**

setgroups(2), initgroups(3)

**HISTORY**

The **getgrouplist**\ () function first appeared in 4.4BSD.

BSD October 26, 2014 BSD

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

