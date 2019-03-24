--------------

KLDLOAD(2) BSD System Calls Manual KLDLOAD(2)

**NAME**

**kldload** — load KLD files into the kernel

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/param.h>
#include <sys/linker.h>**

*int*

**kldload**\ (*const char *file*);

**DESCRIPTION**

The **kldload**\ () system call loads a kld file into the kernel using
the kernel linker.

**RETURN VALUES**

The **kldload**\ () system call returns the fileid of the kld file which
was loaded into the kernel. If an error occurs, **kldload**\ () will
return -1 and set *errno* to indicate the error.

**ERRORS**

The named file is loaded unless:

[EPERM]

You do not have access to read the file or link it with the kernel. You
should be the root user to be able to use the **kld** system calls.

[EFAULT]

Bad address encountered when adding kld info into the kernel space.

[ENOMEM]

There is no memory to load the file into the kernel.

[ENOENT]

The file was not found.

[ENOEXEC]

The file format of *file* was unrecognized.

[EEXIST]

The supplied *file* has already been loaded.

**SEE ALSO**

kldfind(2), kldfirstmod(2), kldnext(2), kldstat(2), kldsym(2),
kldunload(2), modfind(2), modfnext(2), modnext(2), modstat(2), kld(4),
kldload(8)

**HISTORY**

The **kld** interface first appeared in FreeBSD 3.0.

BSD March 3, 1999 BSD

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

