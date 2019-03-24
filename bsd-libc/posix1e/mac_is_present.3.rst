--------------

MAC_IS_PRESENT(3) BSD Library Functions Manual MAC_IS_PRESENT(3)

**NAME**

**mac_is_present** — report whether the running system has MAC support

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/mac.h>**

*int*

**mac_is_present**\ (*const char *policyname*);

**DESCRIPTION**

The **mac_is_present**\ () function determines whether the
currently-running kernel supports MAC for a given policy or not. If
*policyname* is non-NULL, the presence of the named policy (e.g.
‘‘biba’’, ‘‘mls’’, ‘‘te’’) is checked, otherwise the presence of any MAC
policies at all is checked.

**RETURN VALUES**

If the system supports the given MAC policy, the value 1 is returned. If
the specified MAC policy is not supported, the value 0 is returned. If
an error occurs, the value −1 is returned.

| **ERRORS**
| [EINVAL]

The value of *policyname* is not valid.

[ENOMEM]

Insufficient memory was available to allocate internal storage.

**SEE ALSO**

mac(3), mac_free(3), mac_get(3), mac_prepare(3), mac_set(3),
mac_text(3), mac(4), mac(9)

**HISTORY**

Support for Mandatory Access Control was introduced in FreeBSD 5.0 as
part of the TrustedBSD Project.

BSD July 7, 2006 BSD

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

