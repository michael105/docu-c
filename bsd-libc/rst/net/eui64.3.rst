--------------

EUI64(3) BSD Library Functions Manual EUI64(3)

**NAME**

**eui64**, **eui64_aton**, **eui64_ntoa**, **eui64_ntohost**,
**eui64_hostton** — IEEE EUI-64 conversion and lookup routines

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/types.h>
#include <sys/eui64.h>**

*int*

**eui64_aton**\ (*const char *a*, *struct eui64 *e*);

*int*

**eui64_ntoa**\ (*const struct eui64 *id*, *char *a*, *size_t len*);

*int*

**eui64_ntohost**\ (*char *hostname*, *size_t len*,
*const struct eui64 *id*);

*int*

**eui64_hostton**\ (*const char *hostname*, *struct eui64 *id*);

**DESCRIPTION**

These functions operate on IEEE EUI-64s using an *eui64* structure,
which is defined in the header file <*sys/eui64.h*>:

| /\*
| \* The number of bytes in an EUI-64.
| \*/

+-----------+-----------+-----------+-----------+-----------+-----------+
|           | #define   |           |           | 8         |           |
|           | EUI64_LEN |           |           |           |           |
+-----------+-----------+-----------+-----------+-----------+-----------+

| /\*
| \* Structure of an IEEE EUI-64.
| \*/
| struct eui64 {
| u_char octet[EUI64_LEN];
| };

The **eui64_aton**\ () function converts an ASCII representation of an
EUI-64 into an *eui64* structure. Likewise, **eui64_ntoa**\ () converts
an EUI-64 specified as an *eui64* structure into an ASCII string.

The **eui64_ntohost**\ () and **eui64_hostton**\ () functions map
EUI-64s to their corresponding hostnames as specified in the
*/etc/eui64* database. The **eui64_ntohost**\ () function converts from
EUI-64 to hostname, and **eui64_hostton**\ () converts from hostname to
EUI-64.

**RETURN VALUES**

On success, **eui64_ntoa**\ () returns a pointer to a string containing
an ASCII representation of an EUI-64. If it is unable to convert the
supplied *eui64* structure, it returns a NULL pointer. Likewise,
**eui64_aton**\ () returns a pointer to an *eui64* structure on success
and a NULL pointer on failure.

The **eui64_ntohost**\ () and **eui64_hostton**\ () functions both
return zero on success or non-zero if they were unable to find a match
in the */etc/eui64* database.

**NOTES**

The user must ensure that the hostname strings passed to the
**eui64_ntohost**\ () and **eui64_hostton**\ () functions are large
enough to contain the returned hostnames.

**NIS INTERACTION**

If the */etc/eui64* contains a line with a single ‘+’ in it, the
**eui64_ntohost**\ () and **eui64_hostton**\ () functions will attempt
to consult the NIS *eui64.byname* and *eui64.byid* maps in addition to
the data in the */etc/eui64* file.

**SEE ALSO**

firewire(4), eui64(5), yp(8)

**HISTORY**

These functions first appears in FreeBSD 5.3. They are derived from the
ethers(3) family of functions.

BSD March 4, 2004 BSD

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

