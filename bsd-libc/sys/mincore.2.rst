--------------

MINCORE(2) BSD System Calls Manual MINCORE(2)

**NAME**

**mincore** — determine residency of memory pages

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/mman.h>**

*int*

**mincore**\ (*const void *addr*, *size_t len*, *char *vec*);

**DESCRIPTION**

The **mincore**\ () system call determines whether each of the pages in
the region beginning at *addr* and continuing for *len* bytes is
resident or mapped, depending on the value of sysctl
*vm.mincore_mapped*. The status is returned in the *vec* array, one
character per page. Each character is either 0 if the page is not
resident, or a combination of the following flags (defined in
<*sys/mman.h*>):

MINCORE_INCORE

Page is in core (resident).

MINCORE_REFERENCED

Page has been referenced by us.

MINCORE_MODIFIED

Page has been modified by us.

MINCORE_REFERENCED_OTHER

Page has been referenced.

MINCORE_MODIFIED_OTHER

Page has been modified.

MINCORE_SUPER

Page is part of a large (‘‘super’’) page.

The information returned by **mincore**\ () may be out of date by the
time the system call returns. The only way to ensure that a page is
resident is to lock it into memory with the mlock(2) system call.

If the *vm.mincore_mapped* sysctl is set to a non-zero value (default),
only the current process’ mappings of the pages in the specified virtual
address range are examined. This does not preclude the system from
returning MINCORE_REFERENCED_OTHER and MINCORE_MODIFIED_OTHER statuses.
Otherwise, if the sysctl value is zero, all resident pages backing the
specified address range are examined, regardless of the mapping state.

**RETURN VALUES**

The **mincore**\ () function returns the value 0 if successful;
otherwise the value −1 is returned and the global variable *errno* is
set to indicate the error.

**ERRORS**

The **mincore**\ () system call will fail if:

[ENOMEM]

The virtual address range specified by the *addr* and *len* arguments is
not fully mapped.

[EFAULT]

The *vec* argument points to an illegal address.

**SEE ALSO**

madvise(2), mlock(2), mprotect(2), msync(2), munmap(2), getpagesize(3)

**HISTORY**

The **mincore**\ () system call first appeared in 4.4BSD.

BSD January 7, 2019 BSD

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

