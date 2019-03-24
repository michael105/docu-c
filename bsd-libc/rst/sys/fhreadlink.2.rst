--------------

FHREADLINK(2) BSD System Calls Manual FHREADLINK(2)

**NAME**

**fhreadlink** — read value of a symbolic link

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/param.h>
#include <sys/mount.h>**

*int*

**fhreadlink**\ (*fhandle_t *fhp*, *char *buf*, *size_t bufsize*);

**DESCRIPTION**

The **fhreadlink**\ () system call places the contents of the symbolic
link *fhp* in the buffer *buf*, which has size *bufsiz*. The
**fhreadlink**\ () system call does not append a NUL character to *buf*.

**RETURN VALUES**

The call returns the count of characters placed in the buffer if it
succeeds, or a −1 if an error occurs, placing the error code in the
global variable *errno*.

**ERRORS**

The **readlink**\ () system call will fail if:

[ENOENT]

The named file does not exist.

[ELOOP]

Too many symbolic links were encountered in translating the file handle
*fhp*.

[EINVAL]

The named file is not a symbolic link.

[EIO]

An I/O error occurred while reading from the file system.

[EFAULT]

The *buf* argument extends outside the process’s allocated address
space.

[ESTALE]

The file handle *fhp* is no longer valid

**SEE ALSO**

fhstat(2), fhlink(2),

BSD November 29, 2018 BSD

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

