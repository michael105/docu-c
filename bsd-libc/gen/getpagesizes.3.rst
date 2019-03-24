--------------

GETPAGESIZES(3) BSD Library Functions Manual GETPAGESIZES(3)

**NAME**

**getpagesizes** — get system page sizes

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/mman.h>**

*int*

**getpagesizes**\ (*size_t pagesize[]*, *int nelem*);

**DESCRIPTION**

The **getpagesizes**\ () function retrieves page size information from
the system. When it is called with *pagesize* specified as NULL and
*nelem* specified as 0, it returns the number of distinct page sizes
that are supported by the system. Otherwise, it assigns up to *nelem* of
the system-supported page sizes to consecutive elements of the array
referenced by *pagesize*. These page sizes are expressed in bytes. In
this case, **getpagesizes**\ () returns the number of such page sizes
that it assigned to the array.

**RETURN VALUES**

If successful, the **getpagesizes**\ () function returns either the
number of page sizes that are supported by the system or the number of
supported page sizes that it assigned to the array referenced by
*pagesize*. Otherwise, it returns the value −1 and sets *errno* to
indicate the error.

**ERRORS**

The **getpagesizes**\ () function will succeed unless:

[EINVAL]

The *pagesize* argument is NULL and the *nelem* argument is non-zero.

[EINVAL]

The *nelem* argument is less than zero.

**SEE ALSO**

getpagesize(3)

**HISTORY**

The **getpagesizes**\ () function first appeared in Solaris 9. This
manual page was written in conjunction with a new but compatible
implementation that was first released in FreeBSD 7.3.

**AUTHORS**

This manual page was written by Alan L. Cox <*alc@cs.rice.edu*>.

BSD September 21, 2009 BSD

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

