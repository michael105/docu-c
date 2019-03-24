--------------

CAP_SANDBOXED(3) BSD Library Functions Manual CAP_SANDBOXED(3)

**NAME**

**cap_sandboxed** — Check if in a capability mode sandbox

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/capsicum.h>
#include <stdbool.h>**

*bool*

**cap_sandboxed**\ (*void*);

**DESCRIPTION**

**cap_sandboxed**\ () returns *true* if the process is in a capability
mode sandbox or *false* if it is not. This function is a more handy
alternative to the cap_getmode(2) system call as it always succeeds, so
there is no need for error checking. If the support for capability mode
is not compiled into the kernel, **cap_sandboxed**\ () will always
return *false*.

**RETURN VALUES**

Function **cap_sandboxed**\ () is always successful and will return
either *true* or *false*.

**SEE ALSO**

cap_enter(2), capsicum(4)

**AUTHORS**

This function was implemented and manual page was written by Pawel Jakub
Dawidek <*pawel@dawidek.net*> under sponsorship of the FreeBSD
Foundation.

BSD March 27, 2014 BSD

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

