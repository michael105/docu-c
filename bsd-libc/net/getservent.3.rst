--------------

GETSERVENT(3) BSD Library Functions Manual GETSERVENT(3)

**NAME**

**getservent**, **getservbyport**, **getservbyname**, **setservent**,
**endservent** — get service entry

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <netdb.h>**

*struct servent \**

**getservent**\ ();

*struct servent \**

**getservbyname**\ (*const char *name*, *const char *proto*);

*struct servent \**

**getservbyport**\ (*int port*, *const char *proto*);

*void*

**setservent**\ (*int stayopen*);

*void*

**endservent**\ (*void*);

**DESCRIPTION**

The **getservent**\ (), **getservbyname**\ (), and **getservbyport**\ ()
functions each return a pointer to an object with the following
structure containing the broken-out fields of a line in the network
services data base, */etc/services*.

struct servent {

+-----------+-----------+-----------+-----------+-----------+-----------+
|           | char      | \*s_name; |           | /\*       |           |
|           |           |           |           | official  |           |
|           |           |           |           | name of   |           |
|           |           |           |           | service   |           |
|           |           |           |           | \*/       |           |
+-----------+-----------+-----------+-----------+-----------+-----------+
|           | char      | \**s_alia |           | /\* alias |           |
|           |           | ses;      |           | list \*/  |           |
+-----------+-----------+-----------+-----------+-----------+-----------+
|           | int       | s_port;   |           | /\* port  |           |
|           |           |           |           | service   |           |
|           |           |           |           | resides   |           |
|           |           |           |           | at \*/    |           |
+-----------+-----------+-----------+-----------+-----------+-----------+
|           | char      | \*s_proto |           | /\*       |           |
|           |           | ;         |           | protocol  |           |
|           |           |           |           | to use    |           |
|           |           |           |           | \*/       |           |
+-----------+-----------+-----------+-----------+-----------+-----------+

};

The members of this structure are:

*s_name*

The official name of the service.

*s_aliases*

A zero terminated list of alternate names for the service.

*s_port*

The port number at which the service resides. Port numbers are returned
in network byte order.

*s_proto*

The name of the protocol to use when contacting the service.

The **getservent**\ () function reads the next line of the file, opening
the file if necessary.

The **setservent**\ () function opens and rewinds the file. If the
*stayopen* flag is non-zero, the net data base will not be closed after
each call to **getservbyname**\ () or **getservbyport**\ ().

The **endservent**\ () function closes the file.

The **getservbyname**\ () and **getservbyport**\ () functions
sequentially search from the beginning of the file until a matching
protocol name or port number (which must be specified in network byte
order) is found, or until EOF is encountered. If a protocol name is also
supplied (non- NULL), searches must also match the protocol.

| **FILES**
| /etc/services **
  DIAGNOSTICS**

Null pointer returned on EOF or error.

**SEE ALSO**

getprotoent(3), services(5)

**HISTORY**

The **getservent**\ (), **getservbyport**\ (), **getservbyname**\ (),
**setservent**\ (), and **endservent**\ () functions appeared in 4.2BSD.

**BUGS**

These functions use a thread-specific data storage; if the data is
needed for future use, it should be copied before any subsequent calls
overwrite it. Expecting port numbers to fit in a 32 bit quantity is
probably naive.

BSD July 9, 1995 BSD

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

