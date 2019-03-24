--------------

REALPATH(3) BSD Library Functions Manual REALPATH(3)

**NAME**

**realpath** — returns the canonicalized absolute pathname

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <stdlib.h>**

*char \**

**realpath**\ (*const char * restrict pathname*,
*char * restrict resolved_path*);

**DESCRIPTION**

The **realpath**\ () function resolves all symbolic links, extra ‘‘/’’
characters and references to */./* and */../* in *pathname*, and copies
the resulting absolute pathname into the memory pointed to by
*resolved_path*. The *resolved_path* argument *must* point to a buffer
capable of storing at least PATH_MAX characters, or be NULL.

The **realpath**\ () function will resolve both absolute and relative
paths and return the absolute pathname corresponding to *pathname*. All
components of *pathname* must exist when **realpath**\ () is called, and
all but the last component must name either directories or symlinks
pointing to the directories.

**RETURN VALUES**

The **realpath**\ () function returns *resolved_path* on success. If the
function was supplied NULL as *resolved_path*, and operation did not
cause errors, the returned value is a null-terminated string in a buffer
allocated by a call to **malloc**\ (*3*). If an error occurs,
**realpath**\ () returns NULL, and if *resolved_path* is not NULL, the
array that it points to contains the pathname which caused the problem.

**ERRORS**

The function **realpath**\ () may fail and set the external variable
*errno* for any of the errors specified for the library functions
lstat(2), readlink(2) and getcwd(3).

**SEE ALSO**

getcwd(3)

**HISTORY**

The **realpath**\ () function first appeared in 4.4BSD.

**CAVEATS**

This implementation of **realpath**\ () differs slightly from the
Solaris implementation. The 4.4BSD version always returns absolute
pathnames, whereas the Solaris implementation will, under certain
circumstances, return a relative *resolved_path* when given a relative
*pathname*.

BSD May 11, 2012 BSD

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

