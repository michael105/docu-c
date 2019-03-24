--------------

INET(3) BSD Library Functions Manual INET(3)

**NAME**

**inet_aton**, **inet_addr**, **inet_network**, **inet_ntoa**,
**inet_ntoa_r**, **inet_ntop**, **inet_pton**, **inet_makeaddr**,
**inet_lnaof**, **inet_netof** — Internet address manipulation routines

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>**

*int*

**inet_aton**\ (*const char *cp*, *struct in_addr *pin*);

*in_addr_t*

**inet_addr**\ (*const char *cp*);

*in_addr_t*

**inet_network**\ (*const char *cp*);

*char \**

**inet_ntoa**\ (*struct in_addr in*);

*char \**

**inet_ntoa_r**\ (*struct in_addr in*, *char *buf*, *socklen_t size*);

*const char \**

**inet_ntop**\ (*int af*, *const void * restrict src*,
*char * restrict dst*, *socklen_t size*);

*int*

**inet_pton**\ (*int af*, *const char * restrict src*,
*void * restrict dst*);

*struct in_addr*

**inet_makeaddr**\ (*in_addr_t net*, *in_addr_t lna*);

*in_addr_t*

**inet_lnaof**\ (*struct in_addr in*);

*in_addr_t*

**inet_netof**\ (*struct in_addr in*);

**DESCRIPTION**

The routines **inet_aton**\ (), **inet_addr**\ () and
**inet_network**\ () interpret character strings representing numbers
expressed in the Internet standard ‘.’ notation.

The **inet_pton**\ () function converts a presentation format address
(that is, printable form as held in a character string) to network
format (usually a *struct in_addr* or some other internal binary
representation, in network byte order). It returns 1 if the address was
valid for the specified address family, or 0 if the address was not
parseable in the specified address family, or -1 if some system error
occurred (in which case *errno* will have been set). This function is
presently valid for AF_INET and AF_INET6.

The **inet_aton**\ () routine interprets the specified character string
as an Internet address, placing the address into the structure provided.
It returns 1 if the string was successfully interpreted, or 0 if the
string is invalid. The **inet_addr**\ () and **inet_network**\ ()
functions return numbers suitable for use as Internet addresses and
Internet network numbers, respectively.

The function **inet_ntop**\ () converts an address *\*src* from network
format (usually a *struct in_addr* or some other binary form, in network
byte order) to presentation format (suitable for external display
purposes). The *size* argument specifies the size, in bytes, of the
buffer *\*dst*. INET_ADDRSTRLEN and INET6_ADDRSTRLEN define the maximum
size required to convert an address of the respective type. It returns
NULL if a system error occurs (in which case, *errno* will have been
set), or it returns a pointer to the destination string. This function
is presently valid for AF_INET and AF_INET6.

The routine **inet_ntoa**\ () takes an Internet address and returns an
ASCII string representing the address in ‘.’ notation. The routine
**inet_ntoa_r**\ () is the reentrant version of **inet_ntoa**\ (). The
routine **inet_makeaddr**\ () takes an Internet network number and a
local network address and constructs an Internet address from it. The
routines **inet_netof**\ () and **inet_lnaof**\ () break apart Internet
host addresses, returning the network number and local network address
part, respectively.

All Internet addresses are returned in network order (bytes ordered from
left to right). All network numbers and local address parts are returned
as machine byte order integer values.

**INTERNET ADDRESSES**

Values specified using the ‘.’ notation take one of the following forms:

| a.b.c.d
| a.b.c
| a.b
| a

When four parts are specified, each is interpreted as a byte of data and
assigned, from left to right, to the four bytes of an Internet address.
Note that when an Internet address is viewed as a 32-bit integer
quantity on the VAX the bytes referred to above appear as ‘‘d.c.b.a’’.
That is, VAX bytes are ordered from right to left.

When a three part address is specified, the last part is interpreted as
a 16-bit quantity and placed in the right-most two bytes of the network
address. This makes the three part address format convenient for
specifying Class B network addresses as ‘‘128.net.host’’.

When a two part address is supplied, the last part is interpreted as a
24-bit quantity and placed in the right most three bytes of the network
address. This makes the two part address format convenient for
specifying Class A network addresses as ‘‘net.host’’.

When only one part is given, the value is stored directly in the network
address without any byte rearrangement.

All numbers supplied as ‘‘parts’’ in a ‘.’ notation may be decimal,
octal, or hexadecimal, as specified in the C language (i.e., a leading
0x or 0X implies hexadecimal; otherwise, a leading 0 implies octal;
otherwise, the number is interpreted as decimal).

**DIAGNOSTICS**

The constant INADDR_NONE is returned by **inet_addr**\ () and
**inet_network**\ () for malformed requests.

**ERRORS**

The **inet_ntop**\ () call fails if:

[ENOSPC]

*size* was not large enough to store the presentation form of the
address.

[EAFNOSUPPORT]

*\*src* was not an AF_INET or AF_INET6 family address.

**SEE ALSO**

byteorder(3), getaddrinfo(3), gethostbyname(3), getnameinfo(3),
getnetent(3), inet_net(3), hosts(5), networks(5)

*IP Version 6 Addressing Architecture*

,

| RFC ,
| 2373 ,
| July 1998 .

**STANDARDS**

The **inet_ntop**\ () and **inet_pton**\ () functions conform to X/Open
Networking Services Issue 5.2 (‘‘XNS5.2’’). Note that **inet_pton**\ ()
does not accept 1-, 2-, or 3-part dotted addresses; all four parts must
be specified and are interpreted only as decimal values. This is a
narrower input set than that accepted by **inet_aton**\ ().

**HISTORY**

These functions appeared in 4.2BSD.

**BUGS**

The value INADDR_NONE (0xffffffff) is a valid broadcast address, but
**inet_addr**\ () cannot return that value without indicating failure.
The newer **inet_aton**\ () function does not share this problem. The
problem of host byte ordering versus network byte ordering is confusing.
The string returned by **inet_ntoa**\ () resides in a static memory
area.

The **inet_addr**\ () function should return a *struct in_addr*.

BSD June 14, 2007 BSD

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

