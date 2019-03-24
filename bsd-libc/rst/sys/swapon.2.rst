--------------

SWAPON(2) BSD System Calls Manual SWAPON(2)

**NAME**

**swapon**, **swapoff** — control devices for interleaved
paging/swapping

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <unistd.h>**

*int*

**swapon**\ (*const char *special*);

*int*

**swapoff**\ (*const char *special*);

**DESCRIPTION**

The **swapon**\ () system call makes the block device *special*
available to the system for allocation for paging and swapping. The
names of potentially available devices are known to the system and
defined at system configuration time. The size of the swap area on
*special* is calculated at the time the device is first made available
for swapping.

The **swapoff**\ () system call disables paging and swapping on the
given device. All associated swap metadata are deallocated, and the
device is made available for other purposes.

**RETURN VALUES**

If an error has occurred, a value of -1 is returned and *errno* is set
to indicate the error.

**ERRORS**

Both **swapon**\ () and **swapoff**\ () can fail if:

[ENOTDIR]

A component of the path prefix is not a directory.

[ENAMETOOLONG]

A component of a pathname exceeded 255 characters, or an entire path
name exceeded 1023 characters.

[ENOENT]

The named device does not exist.

[EACCES]

Search permission is denied for a component of the path prefix.

[ELOOP]

Too many symbolic links were encountered in translating the pathname.

[EPERM]

The caller is not the super-user.

[EFAULT]

The *special* argument points outside the process’s allocated address
space.

Additionally, **swapon**\ () can fail for the following reasons:

[ENOTBLK]

The *special* argument is not a block device.

[EBUSY]

The device specified by *special* has already been made available for
swapping

[ENXIO]

The major device number of *special* is out of range (this indicates no
device driver exists for the associated hardware).

[EIO]

An I/O error occurred while opening the swap device.

Lastly, **swapoff**\ () can fail if:

[EINVAL]

The system is not currently swapping to *special*.

[ENOMEM]

Not enough virtual memory is available to safely disable paging and
swapping to the given device.

**SEE ALSO**

config(8), swapon(8), sysctl(8)

**HISTORY**

The **swapon**\ () system call appeared in 4.0BSD. The **swapoff**\ ()
system call appeared in FreeBSD 5.0.

BSD October 4, 2013 BSD

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

