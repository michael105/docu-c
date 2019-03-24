--------------

MAC_FREE(3) BSD Library Functions Manual MAC_FREE(3)

**NAME**

**mac_free** — free MAC label

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/mac.h>**

*int*

**mac_free**\ (*mac_t label*);

**DESCRIPTION**

The **mac_free**\ () function frees the storage allocated to contain a
*mac_t*.

**RETURN VALUES**

The **mac_free**\ () function always returns 0. WARNING: see the notes
in the *BUGS* section regarding the use of this function.

**SEE ALSO**

mac(3), mac_get(3), mac_prepare(3), mac_set(3), mac_text(3), posix1e(3),
mac(4), mac(9)

**STANDARDS**

POSIX.1e is described in IEEE POSIX.1e draft 17. Discussion of the draft
continues on the cross-platform POSIX.1e implementation mailing list. To
join this list, see the FreeBSD POSIX.1e implementation page for more
information.

**HISTORY**

Support for Mandatory Access Control was introduced in FreeBSD 5.0 as
part of the TrustedBSD Project.

**BUGS**

POSIX.1e specifies that **mac_free**\ () will be used to free text
strings created using mac_to_text(3). Because *mac_t* is a complex
structure in the TrustedBSD implementation, **mac_free**\ () is specific
to *mac_3*, and must not be used to free the character strings returned
from **mac_to_text**\ (). Doing so may result in undefined behavior.

BSD December 21, 2001 BSD

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

