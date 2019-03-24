--------------

ALLOCA(3) BSD Library Functions Manual ALLOCA(3)

**NAME**

**alloca** — memory allocator

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <stdlib.h>**

*void \**

**alloca**\ (*size_t size*);

**DESCRIPTION**

The **alloca**\ () function allocates *size* bytes of space in the stack
frame of the caller. This temporary space is automatically freed on
return.

**RETURN VALUES**

The **alloca**\ () function returns a pointer to the beginning of the
allocated space.

**SEE ALSO**

brk(2), calloc(3), getpagesize(3), malloc(3), realloc(3)

**HISTORY**

The **alloca**\ () function appeared in Version 32V AT&T UNIX.

**BUGS**

The **alloca**\ () function is machine and compiler dependent; its use
is discouraged.

The **alloca**\ () function is slightly unsafe because it cannot ensure
that the pointer returned points to a valid and usable block of memory.
The allocation made may exceed the bounds of the stack, or even go
further into other objects in memory, and **alloca**\ () cannot
determine such an error. Avoid **alloca**\ () with large unbounded
allocations.

BSD September 5, 2006 BSD

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

