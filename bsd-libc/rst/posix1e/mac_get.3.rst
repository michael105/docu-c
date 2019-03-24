--------------

MAC_GET(3) BSD Library Functions Manual MAC_GET(3)

**NAME**

**mac_get_file**, **mac_get_link**, **mac_get_fd**, **mac_get_peer**,
**mac_get_pid**, **mac_get_proc** — get the label of a file, socket,
socket peer or process

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/mac.h>**

*int*

**mac_get_file**\ (*const char *path*, *mac_t label*);

*int*

**mac_get_link**\ (*const char *path*, *mac_t label*);

*int*

**mac_get_fd**\ (*int fd*, *mac_t label*);

*int*

**mac_get_peer**\ (*int fd*, *mac_t label*);

*int*

**mac_get_pid**\ (*pid_t pid*, *mac_t label*);

*int*

**mac_get_proc**\ (*mac_t label*);

**DESCRIPTION**

The **mac_get_file**\ () system call returns the label associated with a
file specified by pathname. The **mac_get_link**\ () function is the
same as **mac_get_file**\ (), except that it does not follow symlinks.

The **mac_get_fd**\ () system call returns the label associated with an
object referenced by the specified file descriptor. Note that in the
case of a file system socket, the label returned will be the socket
label, which may be different from the label of the on-disk node acting
as a rendezvous for the socket. The **mac_get_peer**\ () system call
returns the label associated with the remote endpoint of a socket; the
exact semantics of this call will depend on the protocol domain,
communications type, and endpoint; typically this label will be cached
when a connection-oriented protocol instance is first set up, and is
undefined for datagram protocols.

The **mac_get_pid**\ () and **mac_get_proc**\ () system calls return the
process label associated with an arbitrary process ID, or the current
process.

Label storage for use with these calls must first be allocated and
prepared using the mac_prepare(3) functions. When an application is done
using a label, the memory may be returned using mac_free(3).

| **ERRORS**
| [EACCES]

A component of *path* is not searchable, or MAC read access to the file
is denied.

[EINVAL]

The requested label operation is not valid for the object referenced by
*fd*.

[ENAMETOOLONG]

The pathname pointed to by *path* exceeds PATH_MAX, or a component of
the pathname exceeds NAME_MAX.

[ENOENT]

A component of *path* does not exist.

[ENOMEM]

Insufficient memory is available to allocate a new MAC label structure.

[ENOTDIR]

A component of *path* is not a directory.

**SEE ALSO**

mac(3), mac_free(3), mac_prepare(3), mac_set(3), mac_text(3),
posix1e(3), mac(4), mac(9)

**STANDARDS**

POSIX.1e is described in IEEE POSIX.1e draft 17. Discussion of the draft
continues on the cross-platform POSIX.1e implementation mailing list. To
join this list, see the FreeBSD POSIX.1e implementation page for more
information.

**HISTORY**

Support for Mandatory Access Control was introduced in FreeBSD 5.0 as
part of the TrustedBSD Project.

BSD December 21, 2001 BSD

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

