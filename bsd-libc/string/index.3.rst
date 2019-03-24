--------------

INDEX(3) BSD Library Functions Manual INDEX(3)

**NAME**

**index**, **rindex** — locate character in string

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <strings.h>**

*char \**

**index**\ (*const char *s*, *int c*);

*char \**

**rindex**\ (*const char *s*, *int c*);

**DESCRIPTION**

**The index**\ () **and rindex**\ () **functions have been deprecated in
favor of** strchr(\ **3**) **and** strrchr(\ **3**)\ **.**

The **index**\ () function locates the first occurrence of *c*
(converted to a *char*) in the string pointed to by *s*. The terminating
null character is considered part of the string; therefore if *c* is
‘\0’, the functions locate the terminating ‘\0’.

The **rindex**\ () function is identical to **index**\ (), except it
locates the last occurrence of *c*.

**RETURN VALUES**

The functions **index**\ () and **rindex**\ () return a pointer to the
located character, or NULL if the character does not appear in the
string.

**SEE ALSO**

memchr(3), strchr(3), strcspn(3), strpbrk(3), strrchr(3), strsep(3),
strspn(3), strstr(3), strtok(3)

**HISTORY**

The **index**\ () and **rindex**\ () functions appeared in Version 6
AT&T UNIX. Their prototypes existed previously in <*string.h*> before
they were moved to <*strings.h*> for IEEE Std 1003.1-2001 (‘‘POSIX.1’’)
compliance. The functions are not specified by IEEE Std 1003.1-2008
(‘‘POSIX.1’’).

BSD March 20, 2011 BSD

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

