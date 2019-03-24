--------------

NLIST(3) BSD Library Functions Manual NLIST(3)

**NAME**

**nlist** — retrieve symbol table name list from an executable file

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <nlist.h>**

*int*

**nlist**\ (*const char *filename*, *struct nlist *nl*);

**DESCRIPTION**

The **nlist**\ () function retrieves name list entries from the symbol
table of an executable file (see a.out(5)). The argument *nl* is set to
reference the beginning of the list. The list is preened of binary and
invalid data; if an entry in the name list is valid, the *n_type* and
*n_value* for the entry are copied into the list referenced by *nl*. No
other data is copied. The last entry in the list is always NULL.

**RETURN VALUES**

The number of invalid entries is returned if successful; otherwise, if
the file *filename* does not exist or is not executable, the returned
value is −1.

**SEE ALSO**

a.out(5)

**HISTORY**

A **nlist**\ () function appeared in Version 6 AT&T UNIX.

BSD April 19, 1994 BSD

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

