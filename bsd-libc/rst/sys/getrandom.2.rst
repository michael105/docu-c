--------------

GETRANDOM(2) BSD System Calls Manual GETRANDOM(2)

**NAME**

**getrandom** — get random data

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/random.h>**

*ssize_t*

**getrandom**\ (*void *buf*, *size_t buflen*, *unsigned int flags*);

**DESCRIPTION**

**getrandom**\ () fills *buf* with up to *buflen* bytes of random data.

The *flags* argument may include zero or more of the following:

‘GRND_NONBLOCK’

Return EAGAIN instead of blocking, if the random(4) device has not yet
been seeded. By default, **getrandom**\ () will block until the device
is seeded.

‘GRND_RANDOM’

This flag does nothing on FreeBSD. */dev/random* and */dev/urandom* are
identical.

If the random(4) device has been seeded, reads of up to 256 bytes will
always return as many bytes as requested and will not be interrupted by
signals.

**RETURN VALUES**

Upon successful completion, the number of bytes which were actually read
is returned. For requests larger than 256 bytes, this can be fewer bytes
than were requested. Otherwise, -1 is returned and the global variable
*errno* is set to indicate the error.

**ERRORS**

The **getrandom**\ () operation returns the following errors:

[EAGAIN]

The ‘GRND_NONBLOCK’ flag was set and the random(4) device was not yet
seeded.

[EFAULT]

The *buf* parameter points to an invalid address.

[EINTR]

The sleep was interrupted by a signal.

[EINVAL]

An invalid *flags* was specified.

[EINVAL]

The requested *buflen* was larger than IOSIZE_MAX.

**SEE ALSO**

arc4random(3), getentropy(3), random(4)

**STANDARDS**

**getentropy**\ () is non-standard. It is present in Linux.

**HISTORY**

The **getrandom**\ () system call first appeared in FreeBSD 12.0.

BSD February 24, 2018 BSD

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

