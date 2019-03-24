--------------

GETPROGNAME(3) BSD Library Functions Manual GETPROGNAME(3)

**NAME**

**getprogname**, **setprogname** — get or set the program name

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <stdlib.h>**

*const char \**

**getprogname**\ (*void*);

*void*

**setprogname**\ (*const char *progname*);

**DESCRIPTION**

The **getprogname**\ () and **setprogname**\ () functions manipulate the
name of the current program. They are used by error-reporting routines
to produce consistent output.

The **getprogname**\ () function returns the name of the program. If the
name has not been set yet, it will return NULL.

The **setprogname**\ () function sets the name of the program to be the
last component of the *progname* argument. Since a pointer to the given
string is kept as the program name, it should not be modified for the
rest of the program’s lifetime.

In FreeBSD, the name of the program is set by the start-up code that is
run before **main**\ (); thus, running **setprogname**\ () is not
necessary. Programs that desire maximum portability should still call
it; on another operating system, these functions may be implemented in a
portability library. Calling **setprogname**\ () allows the
aforementioned library to learn the program name without modifications
to the start-up code.

**SEE ALSO**

err(3), setproctitle(3)

**HISTORY**

These functions first appeared in NetBSD 1.6, and made their way into
FreeBSD 4.4.

BSD May 1, 2001 BSD

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

