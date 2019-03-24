--------------

BYTEORDER(3) BSD Library Functions Manual BYTEORDER(3)

**NAME**

**htonl**, **htons**, **ntohl**, **ntohs** — convert values between host
and network byte order

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <arpa/inet.h>**

or

**#include <netinet/in.h>**

*uint32_t*

**htonl**\ (*uint32_t hostlong*);

*uint16_t*

**htons**\ (*uint16_t hostshort*);

*uint32_t*

**ntohl**\ (*uint32_t netlong*);

*uint16_t*

**ntohs**\ (*uint16_t netshort*);

**DESCRIPTION**

These routines convert 16 and 32 bit quantities between network byte
order and host byte order. On machines which have a byte order which is
the same as the network order, routines are defined as null macros.

These routines are most often used in conjunction with Internet
addresses and ports as returned by gethostbyname(3) and getservent(3).

**SEE ALSO**

gethostbyname(3), getservent(3), byteorder(9)

**STANDARDS**

The **byteorder** functions conform to IEEE Std 1003.1-2001
(‘‘POSIX.1’’).

**HISTORY**

The **byteorder** functions appeared in 4.2BSD.

**BUGS**

On the VAX bytes are handled backwards from most everyone else in the
world. This is not expected to be fixed in the near future.

BSD March 20, 2005 BSD

--------------
