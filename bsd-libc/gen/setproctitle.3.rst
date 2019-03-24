--------------

SETPROCTITLE(3) BSD Library Functions Manual SETPROCTITLE(3)

**NAME**

**setproctitle** — set process title

**SYNOPSIS**

**#include <sys/types.h>
#include <unistd.h>**

*void*

**setproctitle**\ (*const char *fmt*, *...*);

*void*

**setproctitle_fast**\ (*const char *fmt*, *...*);

**DESCRIPTION**

The **setproctitle**\ () library routine sets the process title that
appears on the ps(1) command. The **setproctitle_fast**\ () variant is
optimized for high frequency updates, but may make the ps(1) command
slightly slower by not updating the kernel cache of the program
arguments.

The title is set from the executable’s name, followed by the result of a
printf(3) style expansion of the arguments as specified by the *fmt*
argument. If the *fmt* argument begins with a ‘‘-’’ character, the
executable’s name is skipped.

If *fmt* is NULL, the process title is restored.

**EXAMPLES**

To set the title on a daemon to indicate its activity:

setproctitle("talking to %s", inet_ntoa(addr));

**SEE ALSO**

ps(1), w(1), kvm(3), kvm_getargv(3), printf(3)

**STANDARDS**

The **setproctitle**\ () function is implicitly non-standard. Other
methods of causing the ps(1) command line to change, including copying
over the argv[0] string are also implicitly non-portable. It is
preferable to use an operating system supplied **setproctitle**\ () if
present.

Unfortunately, it is possible that there are other calling conventions
to other versions of **setproctitle**\ (), although none have been found
by the author as yet. This is believed to be the predominant convention.

It is thought that the implementation is compatible with other systems,
including NetBSD and BSD/OS.

**HISTORY**

The **setproctitle**\ () function first appeared in FreeBSD 2.2. The
**setproctitle_fast**\ () function first appeared in FreeBSD 12. Other
operating systems have similar functions.

**AUTHORS**

Peter Wemm <*peter@FreeBSD.org*> stole the idea from the **Sendmail
8.7.3** source code by Eric Allman <*eric@sendmail.org*>.

**BUGS**

Never pass a string with user-supplied data as a format without using
‘%s’. An attacker can put format specifiers in the string to mangle your
stack, leading to a possible security hole. This holds true even if the
string was built using a function like **snprintf**\ (), as the
resulting string may still contain user-supplied conversion specifiers
for later interpolation by **setproctitle**\ ().

Always use the proper secure idiom:

setproctitle("%s", string);

BSD July 4, 2018 BSD

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

