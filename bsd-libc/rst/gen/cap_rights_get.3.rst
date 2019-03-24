--------------

CAP_RIGHTS_GET(3) BSD Library Functions Manual CAP_RIGHTS_GET(3)

**NAME**

**cap_rights_get** — obtain capability rights

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/capsicum.h>**

*int*

**cap_rights_get**\ (*int fd*, *cap_rights_t *rights*);

**DESCRIPTION**

The **cap_rights_get** function allows to obtain current capability
rights for the given descriptor. The function will fill the *rights*
argument with all capability rights if they were not limited or
capability rights configured during the last successful call of
cap_rights_limit(2) on the given descriptor.

The *rights* argument can be inspected using cap_rights_init(3) family
of functions.

The complete list of the capability rights can be found in the rights(4)
manual page.

**RETURN VALUES**

Upon successful completion, the value 0 is returned; otherwise the
value −1 is returned and the global variable *errno* is set to indicate
the error.

**EXAMPLES**

The following example demonstrates how to limit file descriptor
capability rights and how to obtain them.

| cap_rights_t setrights, getrights;
| int fd;

| memset(&setrights, 0, sizeof(setrights));
| memset(&getrights, 0, sizeof(getrights));

| fd = open("/tmp/foo", O_RDONLY);
| if (fd < 0)

+-----------------------+-----------------------+-----------------------+
|                       | err(1, "open()        |                       |
|                       | failed");             |                       |
+-----------------------+-----------------------+-----------------------+

| cap_rights_init(&setrights, CAP_FSTAT, CAP_READ);
| if (cap_rights_limit(fd, &setrights) < 0 && errno != ENOSYS)

+-----------------------------------+-----------------------------------+
|                                   | err(1, "cap_rights_limit()        |
|                                   | failed");                         |
+-----------------------------------+-----------------------------------+

if (cap_rights_get(fd, &getrights) < 0 && errno != ENOSYS)

+-----------------------------------+-----------------------------------+
|                                   | err(1, "cap_rights_get()          |
|                                   | failed");                         |
+-----------------------------------+-----------------------------------+

assert(memcmp(&setrights, &getrights, sizeof(setrights)) == 0);

**ERRORS**

**cap_rights_get**\ () succeeds unless:

[EBADF]

The *fd* argument is not a valid active descriptor.

[EFAULT]

The *rights* argument points at an invalid address.

**SEE ALSO**

cap_rights_limit(2), errno(2), open(2), assert(3), cap_rights_init(3),
err(3), memcmp(3), memset(3), capsicum(4), rights(4)

**HISTORY**

Support for capabilities and capabilities mode was developed as part of
the TrustedBSD Project.

**AUTHORS**

This function was created by Pawel Jakub Dawidek <*pawel@dawidek.net*>
under sponsorship of the FreeBSD Foundation.

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

