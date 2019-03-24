--------------

PSELECT(2) BSD System Calls Manual PSELECT(2)

**NAME**

**pselect** — synchronous I/O multiplexing a la POSIX.1g

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/select.h>**

*int*

**pselect**\ (*int nfds*, *fd_set * restrict readfds*,
*fd_set * restrict writefds*, *fd_set * restrict exceptfds*,
*const struct timespec * restrict timeout*,
*const sigset_t * restrict newsigmask*);

**DESCRIPTION**

The **pselect**\ () function was introduced by IEEE Std 1003.1g-2000
(‘‘POSIX.1’’) as a slightly stronger version of select(2). The *nfds*,
*readfds*, *writefds*, and *exceptfds* arguments are all identical to
the analogous arguments of **select**\ (). The *timeout* argument in
**pselect**\ () points to a *const struct timespec* rather than the
(modifiable) *struct timeval* used by **select**\ (); as in
**select**\ (), a null pointer may be passed to indicate that
**pselect**\ () should wait indefinitely. Finally, *newsigmask*
specifies a signal mask which is set while waiting for input. When
**pselect**\ () returns, the original signal mask is restored.

See select(2) for a more detailed discussion of the semantics of this
interface, and for macros used to manipulate the *fd_set* data type.

**RETURN VALUES**

The **pselect**\ () function returns the same values and under the same
conditions as **select**\ ().

**ERRORS**

The **pselect**\ () function may fail for any of the reasons documented
for select(2) and (if a signal mask is provided) sigprocmask(2).

**SEE ALSO**

kqueue(2), poll(2), select(2), sigprocmask(2), sigsuspend(2)

**STANDARDS**

The **pselect**\ () function conforms to IEEE Std 1003.1-2001
(‘‘POSIX.1’’).

**HISTORY**

The **pselect**\ () function first appeared in FreeBSD 5.0.

**AUTHORS**

The first implementation of **pselect**\ () function and this manual
page were written by Garrett Wollman <*wollman@FreeBSD.org*>.

BSD August 16, 2013 BSD

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

