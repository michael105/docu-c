--------------

SYSARCH(2) BSD System Calls Manual SYSARCH(2)

**NAME**

**sysarch** — architecture-dependent system call

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <machine/sysarch.h>**

*int*

**sysarch**\ (*int number*, *void *args*);

**DESCRIPTION**

The **sysarch**\ () system call performs the architecture-dependent
function specified by *number* with the arguments specified by the
*args* pointer. The *args* argument is a pointer to a structure defining
the actual arguments of the function. Symbolic constants and argument
structures for the architecture-dependent functions can be found in the
header file <*machine/sysarch.h*>.

The **sysarch**\ () system call should never be called directly by user
programs. Instead, they should access its functions using the
architecture-dependent library.

**RETURN VALUES**

See the manual pages for specific architecture-dependent system calls
for information about their return values.

**SEE ALSO**

i386_get_ioperm(2), i386_get_ldt(2), i386_vm86(2)

**HISTORY**

This manual page was taken from NetBSD.

BSD October 11, 1993 BSD

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

