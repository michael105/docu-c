--------------

GETBOOTFILE(3) BSD Library Functions Manual GETBOOTFILE(3)

**NAME**

**getbootfile** — get kernel boot file name

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <paths.h>**

*const char \**

**getbootfile**\ (*void*);

**DESCRIPTION**

The **getbootfile**\ () function retrieves the full pathname of the file
from which the current kernel was loaded, and returns a static pointer
to the name. A read/write interface to this information is available via
the sysctl(3) MIB variable ‘‘kern.bootfile’’.

**RETURN VALUES**

If the call succeeds a string giving the pathname is returned. If it
fails, a null pointer is returned and an error code is placed in the
global location *errno*.

**SEE ALSO**

sysctl(3)

**HISTORY**

The **getbootfile**\ () function appeared in FreeBSD 2.0.

**BUGS**

If the boot blocks have not been modified to pass this information into
the kernel at boot time, the static string ‘‘\ */boot/kernel/kernel*\ ’’
is returned instead of the real boot file.

BSD September 23, 1994 BSD

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

