--------------

RCMDSH(3) BSD Library Functions Manual RCMDSH(3)

**NAME**

**rcmdsh** — return a stream to a remote command without superuser

**SYNOPSIS**

**#include <unistd.h>**

*int*

**rcmdsh**\ (*char **ahost*, *int inport*, *const char *locuser*,
*const char *remuser*, *const char *cmd*, *const char *rshprog*);

**DESCRIPTION**

The **rcmdsh**\ () function is used by normal users to execute a command
on a remote machine using an authentication scheme based on reserved
port numbers using rshd(8) or the value of *rshprog* (if non-NULL).

The **rcmdsh**\ () function looks up the host *\*ahost* using
gethostbyname(3), returning −1 if the host does not exist. Otherwise
*\*ahost* is set to the standard name of the host and a connection is
established to a server residing at the well-known Internet port
‘‘shell/tcp’’ (or whatever port is used by *rshprog*). The *inport*
argument is ignored; it is only included to provide an interface similar
to rcmd(3).

If the connection succeeds, a socket in the UNIX domain of type
SOCK_STREAM is returned to the caller, and given to the remote command
as stdin, stdout, and stderr.

**RETURN VALUES**

The **rcmdsh**\ () function returns a valid socket descriptor on
success. Otherwise, −1 is returned and a diagnostic message is printed
on the standard error.

**SEE ALSO**

rsh(1), socketpair(2), rcmd(3), rshd(8)

**HISTORY**

The **rcmdsh**\ () function first appeared in OpenBSD 2.0, and made its
way into FreeBSD 4.6.

**BUGS**

If rsh(1) encounters an error, a file descriptor is still returned
instead of −1.

BSD September 1, 1996 BSD

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

