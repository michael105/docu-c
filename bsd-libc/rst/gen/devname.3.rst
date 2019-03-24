--------------

DEVNAME(3) BSD Library Functions Manual DEVNAME(3)

**NAME**

**devname** — get device name

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/stat.h>
#include <stdlib.h>**

*char \**

**devname**\ (*dev_t dev*, *mode_t type*);

*char \**

**devname_r**\ (*dev_t dev*, *mode_t type*, *char *buf*, *int len*);

*char \**

**fdevname**\ (*int fd*);

*char \**

**fdevname_r**\ (*int fd*, *char *buf*, *int len*);

**DESCRIPTION**

The **devname**\ () function returns a pointer to the name of the block
or character device in */dev* with a device number of *dev*, and a file
type matching the one encoded in *type* which must be one of S_IFBLK or
S_IFCHR. To find the right name, **devname**\ () asks the kernel via the
*kern.devname* sysctl. If it is unable to come up with a suitable name,
it will format the information encapsulated in *dev* and *type* in a
human-readable format.

The **fdevname**\ () and **fdevname_r**\ () function obtains the device
name directly from a file descriptor pointing to a character device. If
it is unable to come up with a suitable name, these functions will
return a NULL pointer.

**devname**\ () and **fdevname**\ () return the name stored in a static
buffer which will be overwritten on subsequent calls. **devname_r**\ ()
and **fdevname_r**\ () take a buffer and length as argument to avoid
this problem.

**EXAMPLES**

| int fd;
| struct stat buf;
| char \*name;

+-----------------------+-----------------------+-----------------------+
|                       | fd =                  |                       |
|                       | open("/dev/tun");     |                       |
+-----------------------+-----------------------+-----------------------+
|                       | fstat(fd, &buf);      |                       |
+-----------------------+-----------------------+-----------------------+
|                       | printf("devname is    |                       |
|                       | /dev/%s\n",           |                       |
|                       | devname(buf.st_rdev,  |                       |
|                       | S_IFCHR));            |                       |
+-----------------------+-----------------------+-----------------------+
|                       | printf("fdevname is   |                       |
|                       | /dev/%s\n",           |                       |
|                       | fdevname(fd));        |                       |
+-----------------------+-----------------------+-----------------------+

**SEE ALSO**

stat(2)

**HISTORY**

The **devname**\ () function appeared in 4.4BSD. The **fdevname**\ ()
function appeared in FreeBSD 8.0.

BSD February 22, 2005 BSD

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

