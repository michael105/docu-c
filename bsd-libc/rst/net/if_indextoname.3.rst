--------------

IF_NAMETOINDEX(3) BSD Library Functions Manual IF_NAMETOINDEX(3)

**NAME**

**if_nametoindex**, **if_indextoname**, **if_nameindex**,
**if_freenameindex** — provide mappings between interface names and
indexes

**SYNOPSIS**

**#include <sys/types.h>
#include <sys/socket.h>
#include <net/if.h>**

*unsigned int*

**if_nametoindex**\ (*const char *ifname*);

*char \**

**if_indextoname**\ (*unsigned int ifindex*, *char *ifname*);

*struct if_nameindex \**

**if_nameindex**\ (*void*);

*void*

**if_freenameindex**\ (*struct if_nameindex *ptr*);

**DESCRIPTION**

The **if_nametoindex**\ () function maps the interface name specified in
*ifname* to its corresponding index. If the specified interface does not
exist, it returns 0.

The **if_indextoname**\ () function maps the interface index specified
in *ifindex* to it corresponding name, which is copied into the buffer
pointed to by *ifname*, which must be of at least IFNAMSIZ bytes. This
pointer is also the return value of the function. If there is no
interface corresponding to the specified index, NULL is returned.

The **if_nameindex**\ () function returns an array of *if_nameindex*
structures, one structure per interface, as defined in the include file
<*net/if.h*>. The *if_nameindex* structure contains at least the
following entries:

| unsigned int if_index; /\* 1, 2, ... \*/
| char \*if_name; /\* null terminated name: "le0", ... \*/

The end of the array of structures is indicated by a structure with an
*if_index* of 0 and an *if_name* of NULL. A NULL pointer is returned
upon an error.

The **if_freenameindex**\ () function frees the dynamic memory that was
allocated by **if_nameindex**\ ().

**RETURN VALUES**

Upon successful completion, **if_nametoindex**\ () returns the index
number of the interface. If the interface is not found, a value of 0 is
returned and *errno* is set to ENXIO. A value of 0 is also returned if
an error occurs while retrieving the list of interfaces via
getifaddrs(3).

Upon successful completion, **if_indextoname**\ () returns *ifname*. If
the interface is not found, a NULL pointer is returned and *errno* is
set to ENXIO. A NULL pointer is also returned if an error occurs while
retrieving the list of interfaces via getifaddrs(3).

The **if_nameindex**\ () returns a NULL pointer if an error occurs while
retrieving the list of interfaces via getifaddrs(3), or if sufficient
memory cannot be allocated.

**SEE ALSO**

getifaddrs(3), networking(4)

**STANDARDS**

The **if_nametoindex**\ (), **if_indextoname**\ (),
**if_nameindex**\ (), and **if_freenameindex**\ () functions conform to
*RFC 2553*.

**HISTORY**

The implementation first appeared in BSDi BSD/OS.

BSD November 23, 2005 BSD

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

