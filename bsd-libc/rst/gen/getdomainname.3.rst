--------------

GETDOMAINNAME(3) BSD Library Functions Manual GETDOMAINNAME(3)

**NAME**

**getdomainname**, **setdomainname** — get/set the NIS domain name of
current host

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <unistd.h>**

*int*

**getdomainname**\ (*char *name*, *int namelen*);

*int*

**setdomainname**\ (*const char *name*, *int namelen*);

**DESCRIPTION**

The **getdomainname**\ () function returns the standard NIS domain name
for the current host, as previously set by **setdomainname**\ (). The
*namelen* argument specifies the size of the *name* array. The returned
name is null-terminated unless insufficient space is provided.

The **setdomainname**\ () function sets the NIS domain name of the host
machine to be *name*, which has length *namelen*. This call is
restricted to the super-user and is normally used only when the system
is bootstrapped.

**RETURN VALUES**

Upon successful completion, the value 0 is returned; otherwise the
value −1 is returned and the global variable *errno* is set to indicate
the error.

**ERRORS**

The following errors may be returned by these calls:

[EFAULT]

The *name* or *namelen* argument gave an invalid address.

[EPERM]

The caller tried to set the hostname and was not the super-user.

**SEE ALSO**

gethostid(3), gethostname(3), sysctl(3)

**HISTORY**

The **getdomainname**\ () function appeared in 4.2BSD.

**BUGS**

Domain names are limited to MAXHOSTNAMELEN (from <*sys/param.h*>)
characters, currently 256.

BSD May 6, 1994 BSD

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

