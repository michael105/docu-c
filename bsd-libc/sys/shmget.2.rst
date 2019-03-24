--------------

SHMGET(2) BSD System Calls Manual SHMGET(2)

**NAME**

**shmget** — obtain a shared memory identifier

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/shm.h>**

*int*

**shmget**\ (*key_t key*, *size_t size*, *int flag*);

**DESCRIPTION**

Based on the values of *key* and *flag*, **shmget**\ () returns the
identifier of a newly created or previously existing shared memory
segment. The key is analogous to a filename: it provides a handle that
names an IPC object. There are three ways to specify a key:

**•**

IPC_PRIVATE may be specified, in which case a new IPC object will be
created.

**•**

An integer constant may be specified. If no IPC object corresponding to
*key* is specified and the IPC_CREAT bit is set in *flag*, a new one
will be created.

**•**

The ftok(3) may be used to generate a key from a pathname.

The mode of a newly created IPC object is determined by which are set by
ORing these constants into the *flag* argument:

0400

Read access for owner.

0200

Write access for owner.

0040

Read access for group.

0020

Write access for group.

0004

Read access for other.

0002

Write access for other.

When creating a new shared memory segment, *size* indicates the desired
size of the new segment in bytes. The size of the segment may be rounded
up to a multiple convenient to the kernel (i.e., the page size).

**RETURN VALUES**

Upon successful completion, **shmget**\ () returns the positive integer
identifier of a shared memory segment. Otherwise, -1 is returned and
*errno* set to indicate the error.

**ERRORS**

The **shmget**\ () system call will fail if:

[EINVAL]

Size specified is greater than the size of the previously existing
segment. Size specified is less than the system imposed minimum, or
greater than the system imposed maximum.

[ENOENT]

No shared memory segment was found matching *key*, and IPC_CREAT was not
specified.

[ENOSPC]

The kernel was unable to allocate enough memory to satisfy the request.

[EEXIST]

IPC_CREAT and IPC_EXCL were specified, and a shared memory segment
corresponding to *key* already exists.

**SEE ALSO**

shmat(2), shmctl(2), shmdt(2), ftok(3)

BSD March 4, 2018 BSD

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

