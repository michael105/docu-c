--------------

INET_NET(3) BSD Library Functions Manual INET_NET(3)

**NAME**

**inet_net_ntop**, **inet_net_pton** — Internet network number
manipulation routines

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>**

*char \**

**inet_net_ntop**\ (*int af*, *const void *src*, *int bits*,
*char *dst*, *size_t size*);

*int*

**inet_net_pton**\ (*int af*, *const char *src*, *void *dst*,
*size_t size*);

**DESCRIPTION**

The **inet_net_ntop**\ () function converts an Internet network number
from network format (usually a *struct in_addr* or some other binary
form, in network byte order) to CIDR presentation format (suitable for
external display purposes). The *bits* argument is the number of bits in
*src* that are the network number. It returns NULL if a system error
occurs (in which case, *errno* will have been set), or it returns a
pointer to the destination string.

The **inet_net_pton**\ () function converts a presentation format
Internet network number (that is, printable form as held in a character
string) to network format (usually a *struct in_addr* or some other
internal binary representation, in network byte order). It returns the
number of bits (either computed based on the class, or specified with
/CIDR), or −1 if a failure occurred (in which case *errno* will have
been set. It will be set to ENOENT if the Internet network number was
not valid).

The currently supported values for *af* are AF_INET and AF_INET6. The
*size* argument is the size of the result buffer *dst*.

**NETWORK NUMBERS (IP VERSION 4)**

Internet network numbers may be specified in one of the following forms:

| a.b.c.d/bits
| a.b.c.d
| a.b.c
| a.b
| a

When four parts are specified, each is interpreted as a byte of data and
assigned, from left to right, to the four bytes of an Internet network
number. Note that when an Internet network number is viewed as a 32-bit
integer quantity on a system that uses little-endian byte order (such as
the Intel 386, 486, and Pentium processors) the bytes referred to above
appear as ‘‘d.c.b.a’’. That is, little-endian bytes are ordered from
right to left.

When a three part number is specified, the last part is interpreted as a
16-bit quantity and placed in the rightmost two bytes of the Internet
network number. This makes the three part number format convenient for
specifying Class B network numbers as ‘‘128.net.host’’.

When a two part number is supplied, the last part is interpreted as a
24-bit quantity and placed in the rightmost three bytes of the Internet
network number. This makes the two part number format convenient for
specifying Class A network numbers as ‘‘net.host’’.

When only one part is given, the value is stored directly in the
Internet network number without any byte rearrangement.

All numbers supplied as ‘‘parts’’ in a ‘.’ notation may be decimal,
octal, or hexadecimal, as specified in the C language (i.e., a leading
0x or 0X implies hexadecimal; otherwise, a leading 0 implies octal;
otherwise, the number is interpreted as decimal).

**SEE ALSO**

byteorder(3), inet(3), networks(5)

**HISTORY**

The **inet_net_ntop**\ () and **inet_net_pton**\ () functions appeared
in BIND 4.9.4.

BSD August 18, 2016 BSD

--------------
