--------------

GETNETGRENT(3) BSD Library Functions Manual GETNETGRENT(3)

**NAME**

**getnetgrent**, **innetgr**, **setnetgrent**, **endnetgrent** —
netgroup database operations

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <netdb.h>**

*int*

**getnetgrent**\ (*char **host*, *char **user*, *char **domain*);

*int*

**getnetgrent_r**\ (*char **host*, *char **user*, *char **domain*,
*char *buf*, *size_t bufsize*);

*int*

**innetgr**\ (*const char *netgroup*, *const char *host*,
*const char *user*, *const char *domain*);

*void*

**setnetgrent**\ (*const char *netgroup*);

*void*

**endnetgrent**\ (*void*);

**DESCRIPTION**

These functions operate on the netgroup database file */etc/netgroup*
which is described in netgroup(5). The database defines a set of
netgroups, each made up of one or more triples:

(host, user, domain)

that defines a combination of host, user and domain. Any of the three
fields may be specified as ‘‘wildcards’’ that match any string.

The function **getnetgrent**\ () sets the three pointer arguments to the
strings of the next member of the current netgroup. If any of the string
pointers are NULL that field is considered a wildcard.

The functions **setnetgrent**\ () and **endnetgrent**\ () set the
current netgroup and terminate the current netgroup respectively. If
**setnetgrent**\ () is called with a different netgroup than the
previous call, an implicit **endnetgrent**\ () is implied. The
**setnetgrent**\ () function also sets the offset to the first member of
the netgroup.

The function **innetgr**\ () searches for a match of all fields within
the specified group. If any of the **host**, **user**, or **domain**
arguments are NULL those fields will match any string value in the
netgroup member.

**RETURN VALUES**

The function **getnetgrent**\ () returns 0 for ‘‘no more netgroup
members’’ and 1 otherwise. The function **innetgr**\ () returns 1 for a
successful match and 0 otherwise. The functions **setnetgrent**\ () and
**endnetgrent**\ () have no return value.

| **FILES**
| /etc/netgroup

netgroup database file

**COMPATIBILITY**

The netgroup members have three string fields to maintain compatibility
with other vendor implementations, however it is not obvious what use
the **domain** string has within BSD.

**SEE ALSO**

netgroup(5)

**BUGS**

The function **getnetgrent**\ () returns pointers to dynamically
allocated data areas that are freed when the function
**endnetgrent**\ () is called.

BSD June 5, 2016 BSD

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

