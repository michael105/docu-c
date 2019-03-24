--------------

GETLOGINCLASS(2) BSD System Calls Manual GETLOGINCLASS(2)

**NAME**

**getloginclass**, **setloginclass** — get/set login class

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <unistd.h>**

*int*

**getloginclass**\ (*char *name*, *size_t len*);

*int*

**setloginclass**\ (*const char *name*);

**DESCRIPTION**

The **getloginclass**\ () routine returns the login class name
associated with the calling process, as previously set by
**setloginclass**\ (). The caller must provide the buffer *name* with
length *len* bytes to hold the result. The buffer should be at least
MAXLOGNAME bytes in length.

The **setloginclass**\ () system call sets the login class of the
calling process to *name*. This system call is restricted to the
super-user, and is normally used only when a new session is being
created on behalf of the named user (for example, at login time, or when
a remote shell is invoked). Processes inherit login class from their
parents.

**RETURN VALUES**

Upon successful completion, the value 0 is returned; otherwise the
value −1 is returned and the global variable *errno* is set to indicate
the error.

**ERRORS**

The following errors may be returned by these calls:

[EFAULT]

The *name* argument gave an invalid address.

[EINVAL]

The *name* argument pointed to a string that was too long. Login class
names are limited to MAXLOGNAME (from <*sys/param.h*>) characters,
currently 33 including null.

[EPERM]

The caller tried to set the login class and was not the super-user.

[ENAMETOOLONG]

The size of the buffer is smaller than the result to be returned.

**SEE ALSO**

ps(1), setusercontext(3), login.conf(5), rctl(8)

**HISTORY**

The **getloginclass**\ () and **setloginclass**\ () system calls first
appeared in FreeBSD 9.0.

BSD July 12, 2016 BSD

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

