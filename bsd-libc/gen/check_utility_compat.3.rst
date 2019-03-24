--------------

CHECK_UTILITY_COMPAT(3) BSD Library Functions Manual
CHECK_UTILITY_COMPAT(3)

**NAME**

**check_utility_compat** — determine whether a utility should be
compatible

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <unistd.h>**

*int*

**check_utility_compat**\ (*const char *utility*);

**DESCRIPTION**

The **check_utility_compat**\ () function checks whether *utility*
should behave in a traditional (FreeBSD 4.7-compatible) manner, or in
accordance with IEEE Std 1003.1-2001 (‘‘POSIX.1’’). The configuration is
given as a comma-separated list of utility names; if the list is present
but empty, all supported utilities assume their most compatible mode.
The **check_utility_compat**\ () function first checks for an
environment variable named \_COMPAT_FreeBSD_4. If that environment
variable does not exist, then **check_utility_compat**\ () will attempt
to read the contents of a symbolic link named
*/etc/compat-FreeBSD-4-util*. If no configuration is found,
compatibility mode is disabled.

**RETURN VALUES**

The **check_utility_compat**\ () function returns zero if *utility*
should implement strict IEEE Std 1003.1-2001 (‘‘POSIX.1’’) behavior, and
nonzero otherwise.

| **FILES**
| /etc/compat-FreeBSD-4-util

If present, a symbolic link whose expansion gives system-wide default
settings for the **check_utility_compat**\ () function.

**ERRORS**

No errors are detected.

**HISTORY**

The **check_utility_compat**\ () function first appeared in FreeBSD 5.0.

**AUTHORS**

This manual page was written by Garrett Wollman <*wollman@FreeBSD.org*>.

BSD October 27, 2002 BSD

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

