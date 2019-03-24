--------------

GETUSERSHELL(3) BSD Library Functions Manual GETUSERSHELL(3)

**NAME**

**getusershell**, **setusershell**, **endusershell** — get valid user
shells

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <unistd.h>**

*char \**

**getusershell**\ (*void*);

*void*

**setusershell**\ (*void*);

*void*

**endusershell**\ (*void*);

**DESCRIPTION**

The **getusershell**\ () function returns a pointer to a valid user
shell as defined by the system manager in the shells database as
described in shells(5). If the shells database is not available,
**getusershell**\ () behaves as if */bin/sh* and */bin/csh* were listed.

The **getusershell**\ () function reads the next line (opening the file
if necessary); **setusershell**\ () rewinds the file;
**endusershell**\ () closes it.

| **FILES**
| /etc/shells **
  DIAGNOSTICS**

The routine **getusershell**\ () returns a null pointer (0) on EOF.

**SEE ALSO**

nsswitch.conf(5), shells(5)

**HISTORY**

The **getusershell**\ () function appeared in 4.3BSD.

**BUGS**

The **getusershell**\ () function leaves its result in an internal
static object and returns a pointer to that object. Subsequent calls to
**getusershell**\ () will modify the same object.

BSD January 16, 1999 BSD

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

