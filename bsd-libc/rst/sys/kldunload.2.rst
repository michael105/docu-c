--------------

KLDUNLOAD(2) BSD System Calls Manual KLDUNLOAD(2)

**NAME**

**kldunload**, **kldunloadf** — unload kld files

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/param.h>
#include <sys/linker.h>**

*int*

**kldunload**\ (*int fileid*);

*int*

**kldunloadf**\ (*int fileid*, *int flags*);

**DESCRIPTION**

The **kldunload**\ () system call unloads a kld file from the kernel
that was previously linked via kldload(2).

The **kldunloadf**\ () system call accepts an additional flags argument,
which may be one of LINKER_UNLOAD_NORMAL, giving the same behavior as
**kldunload**\ (), or LINKER_UNLOAD_FORCE, which causes the unload to
ignore a failure to quiesce the module.

**RETURN VALUES**

Upon successful completion, the value 0 is returned; otherwise the
value −1 is returned and the global variable *errno* is set to indicate
the error.

**ERRORS**

The file referred to by *fileid* is unloaded unless:

[EPERM]

You do not have access to unlink the file from the kernel.

[ENOENT]

The file was not found.

[EBUSY]

You attempted to unload a file linked by the kernel.

[EINVAL]

The **kldunloadf**\ () system call was passed invalid flags.

**SEE ALSO**

kldfind(2), kldfirstmod(2), kldload(2), kldnext(2), kldstat(2),
kldsym(2), modfind(2), modfnext(2), modnext(2), modstat(2), kld(4),
kldunload(8)

**HISTORY**

The **kld** interface first appeared in FreeBSD 3.0.

BSD December 25, 2008 BSD

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

