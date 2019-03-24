--------------

PSIGNAL(3) BSD Library Functions Manual PSIGNAL(3)

**NAME**

**psignal**, **strsignal**, **sys_siglist**, **sys_signame** — system
signal messages

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <signal.h>**

*void*

**psignal**\ (*int sig*, *const char *s*);

*extern const char \* const sys_siglist[]*; *
extern const char \* const sys_signame[]*;

**#include <string.h>**

*char \**

**strsignal**\ (*int sig*);

**DESCRIPTION**

The **psignal**\ () and **strsignal**\ () functions locate the
descriptive message string for a signal number.

The **strsignal**\ () function accepts a signal number argument *sig*
and returns a pointer to the corresponding message string.

The **psignal**\ () function accepts a signal number argument *sig* and
writes it to the standard error. If the argument *s* is non-NULL and
does not point to the null character, *s* is written to the standard
error file descriptor prior to the message string, immediately followed
by a colon and a space. If the signal number is not recognized
(sigaction(2)), the string ‘‘Unknown signal’’ is produced.

The message strings can be accessed directly through the external array
*sys_siglist*, indexed by recognized signal numbers. The external array
*sys_signame* is used similarly and contains short, upper-case
abbreviations for signals which are useful for recognizing signal names
in user input. The defined variable NSIG contains a count of the strings
in *sys_siglist* and *sys_signame*.

**SEE ALSO**

sigaction(2), perror(3), strerror(3)

**HISTORY**

The **psignal**\ () function appeared in 4.2BSD.

BSD May 30, 2016 BSD

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

