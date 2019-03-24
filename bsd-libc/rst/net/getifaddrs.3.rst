--------------

GETIFADDRS(3) BSD Library Functions Manual GETIFADDRS(3)

**NAME**

**getifaddrs** — get interface addresses

**SYNOPSIS**

**#include <ifaddrs.h>**

*int*

**getifaddrs**\ (*struct ifaddrs **ifap*);

*void*

**freeifaddrs**\ (*struct ifaddrs *ifp*);

**DESCRIPTION**

The **getifaddrs**\ () function stores a reference to a linked list of
the network interfaces on the local machine in the memory referenced by
*ifap*. The list consists of **ifaddrs** structures, as defined in the
include file <*ifaddrs.h*>. The **ifaddrs** structure contains at least
the following entries:

| struct ifaddrs \*ifa_next; /\* Pointer to next struct \*/
| char \*ifa_name; /\* Interface name \*/
| u_int ifa_flags; /\* Interface flags \*/
| struct sockaddr \*ifa_addr; /\* Interface address \*/
| struct sockaddr \*ifa_netmask; /\* Interface netmask \*/
| struct sockaddr \*ifa_broadaddr; /\* Interface broadcast address \*/
| struct sockaddr \*ifa_dstaddr; /\* P2P interface destination \*/

void \*ifa_data;

/\* Address specific data \*/

The ifa_next field contains a pointer to the next structure on the list.
This field is NULL in last structure on the list.

The ifa_name field contains the interface name.

The ifa_flags field contains the interface flags, as set by ifconfig(8)
utility.

The ifa_addr field references either the address of the interface or the
link level address of the interface, if one exists, otherwise it is
NULL. (The sa_family field of the ifa_addr field should be consulted to
determine the format of the ifa_addr address.)

The ifa_netmask field references the netmask associated with ifa_addr,
if one is set, otherwise it is NULL.

The ifa_broadaddr field, which should only be referenced for non-P2P
interfaces, references the broadcast address associated with ifa_addr,
if one exists, otherwise it is NULL.

The ifa_dstaddr field references the destination address on a P2P
interface, if one exists, otherwise it is NULL.

The ifa_data field references address family specific data in a pointer
to the *struct if_data* (as defined in include file <*net/if.h*>). For
AF_LINK addresses, it contains various interface attributes and
statistics. For all other address families, it contains per-address
interface statistics.

The data returned by **getifaddrs**\ () is dynamically allocated and
should be freed using **freeifaddrs**\ () when no longer needed.

**RETURN VALUES**

The **getifaddrs**\ () function returns the value 0 if successful;
otherwise the value −1 is returned and the global variable *errno* is
set to indicate the error.

**ERRORS**

The **getifaddrs**\ () may fail and set *errno* for any of the errors
specified for the library routines ioctl(2), socket(2), malloc(3) or
sysctl(3).

**SEE ALSO**

ioctl(2), socket(2), sysctl(3), networking(4), ifconfig(8)

**HISTORY**

The **getifaddrs** implementation first appeared in BSDi BSD/OS.

**BUGS**

If both <*net/if.h*> and <*ifaddrs.h*> are being included, <*net/if.h*>
*must* be included before <*ifaddrs.h*>.

BSD November 25, 2014 BSD

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

