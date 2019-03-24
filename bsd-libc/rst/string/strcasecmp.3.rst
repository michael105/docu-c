--------------

STRCASECMP(3) BSD Library Functions Manual STRCASECMP(3)

**NAME**

**strcasecmp**, **strncasecmp** — compare strings, ignoring case

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <strings.h>**

*int*

**strcasecmp**\ (*const char *s1*, *const char *s2*);

*int*

**strncasecmp**\ (*const char *s1*, *const char *s2*, *size_t len*);

**#include <strings.h>
#include <xlocale.h>**

*int*

**strcasecmp_l**\ (*const char *s1*, *const char *s2*, *locale_t loc*);

*int*

**strncasecmp_l**\ (*const char *s1*, *const char *s2*, *size_t len*,
*locale_t loc*);

**DESCRIPTION**

The **strcasecmp**\ () and **strncasecmp**\ () functions compare the
null-terminated strings *s1* and *s2*.

The **strncasecmp**\ () function compares at most *len* characters. The
**strcasecmp_l**\ () and **strncasecmp_l**\ () functions do the same as
their non-locale versions above, but take an explicit locale rather than
using the current locale.

**RETURN VALUES**

The functions **strcasecmp**\ () and **strncasecmp**\ () return an
integer greater than, equal to, or less than 0, depending on whether
*s1* is lexicographically greater than, equal to, or less than *s2*
after translation of each corresponding character to lower-case. The
strings themselves are not modified. The comparison is done using
unsigned characters, so that ‘\200’ is greater than ‘\0’. The functions
**strcasecmp_l**\ () and **strncasecmp_l**\ () do the same but take
explicit locales.

**SEE ALSO**

bcmp(3), memcmp(3), strcmp(3), strcoll(3), strxfrm(3), tolower(3),
wcscasecmp(3)

**HISTORY**

The **strcasecmp**\ () and **strncasecmp**\ () functions first appeared
in 4.4BSD. Their prototypes existed previously in <*string.h*> before
they were moved to <*strings.h*> for IEEE Std 1003.1-2001 (‘‘POSIX.1’’)
compliance.

BSD May 29, 2014 BSD

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

