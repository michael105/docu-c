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

