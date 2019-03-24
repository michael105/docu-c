--------------

GETRPCENT(3) BSD Library Functions Manual GETRPCENT(3)

**NAME**

**getrpcent**, **getrpcbyname**, **getrpcbynumber**, **endrpcent**,
**setrpcent** — get RPC entry

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <rpc/rpc.h>**

*struct rpcent \**

**getrpcent**\ (*void*);

*struct rpcent \**

**getrpcbyname**\ (*const char *name*);

*struct rpcent \**

**getrpcbynumber**\ (*int number*);

*void*

**setrpcent**\ (*int stayopen*);

*void*

**endrpcent**\ (*void*);

**DESCRIPTION**

The **getrpcent**\ (), **getrpcbyname**\ (), and **getrpcbynumber**\ ()
functions each return a pointer to an object with the following
structure containing the broken-out fields of a line in the rpc program
number data base, */etc/rpc*:

struct rpcent {

+-----------+-----------+-----------+-----------+-----------+-----------+
|           | char      | \*r_name; |           | /\* name  |           |
|           |           |           |           | of server |           |
|           |           |           |           | for this  |           |
|           |           |           |           | rpc       |           |
|           |           |           |           | program   |           |
|           |           |           |           | \*/       |           |
+-----------+-----------+-----------+-----------+-----------+-----------+
|           | char      | \**r_alia |           | /\* alias |           |
|           |           | ses;      |           | list \*/  |           |
+-----------+-----------+-----------+-----------+-----------+-----------+
|           | long      | r_number; |           | /\* rpc   |           |
|           |           |           |           | program   |           |
|           |           |           |           | number    |           |
|           |           |           |           | \*/       |           |
+-----------+-----------+-----------+-----------+-----------+-----------+

};

The members of this structure are:

*r_name*

The name of the server for this rpc program.

*r_aliases*

A zero terminated list of alternate names for the rpc program.

*r_number*

The rpc program number for this service.

The **getrpcent**\ () function reads the next line of the file, opening
the file if necessary.

The **setrpcent**\ () function opens and rewinds the file. If the
*stayopen* flag is non-zero, the net data base will not be closed after
each call to **getrpcent**\ () (either directly, or indirectly through
one of the other ‘‘getrpc’’ calls).

The **endrpcent**\ () function closes the file.

The **getrpcbyname**\ () and **getrpcbynumber**\ () functions
sequentially search from the beginning of the file until a matching rpc
program name or program number is found, or until end-of-file is
encountered.

| **FILES**
| /etc/rpc **
  DIAGNOSTICS**

A NULL pointer is returned on EOF or error.

**SEE ALSO**

rpc(5), rpcinfo(8), ypserv(8)

**BUGS**

All information is contained in a static area so it must be copied if it
is to be saved.

BSD February 26, 2016 BSD

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

