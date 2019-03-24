--------------

GETIFMADDRS(3) BSD Library Functions Manual GETIFMADDRS(3)

**NAME**

**getifmaddrs** — get multicast group memberships

**SYNOPSIS**

**#include <ifaddrs.h>**

*int*

**getifmaddrs**\ (*struct ifmaddrs **ifmap*);

*void*

**freeifmaddrs**\ (*struct ifmaddrs *ifmp*);

**DESCRIPTION**

The **getifmaddrs**\ () function stores a reference to a linked list of
the multicast memberships on the local machine in the memory referenced
by *ifmap*. The list consists of *ifmaddrs* structures, as defined in
the include file <*ifaddrs.h*>. The *ifmaddrs* structure contains at
least the following entries:

| struct ifmaddrs \*ifma_next; /\* Pointer to next struct \*/
| struct sockaddr \*ifma_name; /\* Interface name (AF_LINK) \*/
| struct sockaddr \*ifma_addr; /\* Multicast address \*/
| struct sockaddr \*ifma_lladdr; /\* Link-layer translation, if any \*/

The *ifma_next* field contains a pointer to the next structure on the
list. This field is NULL in last structure on the list.

The *ifma_name* field references an AF_LINK address structure,
containing the name of the interface where the membership exists.

The *ifma_addr* references the address that this membership is for.

The *ifma_lladdr* field references a link-layer translation for the
protocol-level address in *ifma_addr*, if one is set, otherwise it is
NULL.

The data returned by **getifmaddrs**\ () is dynamically allocated and
should be freed using **freeifmaddrs**\ () when no longer needed.

**RETURN VALUES**

The **getifmaddrs**\ () function returns the value 0 if successful;
otherwise the value −1 is returned and the global variable *errno* is
set to indicate the error.

**ERRORS**

The **getifmaddrs**\ () may fail and set *errno* for any of the errors
specified for the library routines malloc(3) or sysctl(3).

**SEE ALSO**

sysctl(3), networking(4), ifconfig(8)

**HISTORY**

The **getifmaddrs**\ () function first appeared in FreeBSD 5.2.

**BUGS**

If both <*net/if.h*> and <*ifaddrs.h*> are being included, <*net/if.h*>
*must* be included before <*ifaddrs.h*>.

BSD May 21, 2013 BSD

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

