--------------

FTOK(3) BSD Library Functions Manual FTOK(3)

**NAME**

**ftok** — create IPC identifier from path name

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/types.h>
#include <sys/ipc.h>**

*key_t*

**ftok**\ (*const char *path*, *int id*);

**DESCRIPTION**

The **ftok**\ () function attempts to create a unique key suitable for
use with the msgget(2), semget(2) and shmget(2) functions given the
*path* of an existing file and a user-selectable *id*.

The specified *path* must specify an existing file that is accessible to
the calling process or the call will fail. Also, note that links to
files will return the same key, given the same *id*.

**RETURN VALUES**

The **ftok**\ () function will return -1 if *path* does not exist or if
it cannot be accessed by the calling process.

**SEE ALSO**

msgget(2), semget(2), shmget(2)

**HISTORY**

The **ftok**\ () function originates with System V and is typically used
by programs that use the System V IPC routines.

**AUTHORS**

Thorsten Lockert <*tholo@sigmasoft.com*>

**BUGS**

The returned key is computed based on the device minor number and inode
of the specified *path* in combination with the lower 8 bits of the
given *id*. Thus it is quite possible for the routine to return
duplicate keys.

BSD July 9, 2009 BSD

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

