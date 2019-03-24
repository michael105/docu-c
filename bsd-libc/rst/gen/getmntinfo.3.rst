--------------

GETMNTINFO(3) BSD Library Functions Manual GETMNTINFO(3)

**NAME**

**getmntinfo** — get information about mounted file systems

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/param.h>
#include <sys/ucred.h>
#include <sys/mount.h>**

*int*

**getmntinfo**\ (*struct statfs **mntbufp*, *int mode*);

**DESCRIPTION**

The **getmntinfo**\ () function returns an array of **statfs**\ ()
structures describing each currently mounted file system (see
statfs(2)).

The **getmntinfo**\ () function passes its *mode* argument transparently
to getfsstat(2).

**RETURN VALUES**

On successful completion, **getmntinfo**\ () returns a count of the
number of elements in the array. The pointer to the array is stored into
*mntbufp*.

If an error occurs, zero is returned and the external variable *errno*
is set to indicate the error. Although the pointer *mntbufp* will be
unmodified, any information previously returned by **getmntinfo**\ ()
will be lost.

**ERRORS**

The **getmntinfo**\ () function may fail and set errno for any of the
errors specified for the library routines getfsstat(2) or malloc(3).

**SEE ALSO**

getfsstat(2), mount(2), statfs(2), mount(8)

**HISTORY**

The **getmntinfo**\ () function first appeared in 4.4BSD.

**BUGS**

The **getmntinfo**\ () function writes the array of structures to an
internal static object and returns a pointer to that object. Subsequent
calls to **getmntinfo**\ () will modify the same object.

The memory allocated by **getmntinfo**\ () cannot be free(3)’d by the
application.

BSD December 27, 2016 BSD

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

