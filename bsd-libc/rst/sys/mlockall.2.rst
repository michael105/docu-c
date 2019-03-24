--------------

MLOCKALL(2) BSD System Calls Manual MLOCKALL(2)

**NAME**

**mlockall**, **munlockall** — lock (unlock) the address space of a
process

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/mman.h>**

*int*

**mlockall**\ (*int flags*);

*int*

**munlockall**\ (*void*);

**DESCRIPTION**

The **mlockall**\ () system call locks into memory the physical pages
associated with the address space of a process until the address space
is unlocked, the process exits, or execs another program image.

The following flags affect the behavior of **mlockall**\ ():

MCL_CURRENT

Lock all pages currently mapped into the process’s address space.

MCL_FUTURE

Lock all pages mapped into the process’s address space in the future, at
the time the mapping is established. Note that this may cause future
mappings to fail if those mappings cause resource limits to be exceeded.

Since physical memory is a potentially scarce resource, processes are
limited in how much they can lock down. A single process can lock the
minimum of a system-wide ‘‘wired pages’’ limit *vm.max_wired* and the
per-process RLIMIT_MEMLOCK resource limit.

If *security.bsd.unprivileged_mlock* is set to 0 these calls are only
available to the super-user. If *vm.old_mlock* is set to 1 the
per-process RLIMIT_MEMLOCK resource limit will not be applied for
**mlockall**\ () calls.

The **munlockall**\ () call unlocks any locked memory regions in the
process address space. Any regions mapped after an **munlockall**\ ()
call will not be locked.

**RETURN VALUES**

A return value of 0 indicates that the call succeeded and all pages in
the range have either been locked or unlocked. A return value of −1
indicates an error occurred and the locked status of all pages in the
range remains unchanged. In this case, the global location *errno* is
set to indicate the error.

**ERRORS**

**mlockall**\ () will fail if:

[EINVAL]

The *flags* argument is zero, or includes unimplemented flags.

[ENOMEM]

Locking the indicated range would exceed either the system or
per-process limit for locked memory.

[EAGAIN]

Some or all of the memory mapped into the process’s address space could
not be locked when the call was made.

[EPERM]

The calling process does not have the appropriate privilege to perform
the requested operation.

**SEE ALSO**

mincore(2), mlock(2), mmap(2), munmap(2), setrlimit(2)

**STANDARDS**

The **mlockall**\ () and **munlockall**\ () functions are believed to
conform to IEEE Std 1003.1-2001 (‘‘POSIX.1’’).

**HISTORY**

The **mlockall**\ () and **munlockall**\ () functions first appeared in
FreeBSD 5.1.

**BUGS**

The per-process resource limit is a limit on the amount of virtual
memory locked, while the system-wide limit is for the number of locked
physical pages. Hence a process with two distinct locked mappings of the
same physical page counts as 2 pages against the per-process limit and
as only a single page in the system limit.

BSD December 25, 2012 BSD

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

