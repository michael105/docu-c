--------------

STRCPY(3) BSD Library Functions Manual STRCPY(3)

**NAME**

**stpcpy**, **stpncpy**, **strcpy**, **strncpy** — copy strings

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <string.h>**

*char \**

**stpcpy**\ (*char * restrict dst*, *const char * restrict src*);

*char \**

**stpncpy**\ (*char * restrict dst*, *const char * restrict src*,
*size_t len*);

*char \**

**strcpy**\ (*char * restrict dst*, *const char * restrict src*);

*char \**

**strncpy**\ (*char * restrict dst*, *const char * restrict src*,
*size_t len*);

**DESCRIPTION**

The **strcpy**\ () and **stpcpy**\ () functions copy the string *src* to
*dst* (including the terminating ‘\0’ character.)

The **strncpy**\ () and **stpncpy**\ () functions copy at most *len*
characters from *src* into *dst*. **If** *src* **is less than** *len*
**characters long, the remainder of** *dst* **is filled with ‘\0’
characters.** Otherwise, *dst* is *not* terminated.

For all of **strcpy**\ (), **strncpy**\ (), **stpcpy**\ (), and
**stpncpy**\ (), the result is undefined if *src* and *dst* overlap.

**RETURN VALUES**

The **strcpy**\ () and **strncpy**\ () functions return *dst*. The
**stpcpy**\ () and **stpncpy**\ () functions return a pointer to the
terminating ‘\0’ character of *dst*. If **stpncpy**\ () does not
terminate *dst* with a NUL character, it instead returns a pointer to
dst[n] (which does not necessarily refer to a valid memory location.)

**EXAMPLES**

The following sets *chararray* to ‘‘abc\0\0\0’’:

char chararray[6];

(void)strncpy(chararray, "abc", sizeof(chararray));

The following sets *chararray* to ‘‘abcdef’’:

char chararray[6];

(void)strncpy(chararray, "abcdefgh", sizeof(chararray));

Note that it does *not* NUL terminate *chararray* because the length of
the source string is greater than or equal to the length argument.

The following copies as many characters from *input* to *buf* as will
fit and NUL terminates the result. Because **strncpy**\ () does *not*
guarantee to NUL terminate the string itself, this must be done
explicitly.

char buf[1024];

| (void)strncpy(buf, input, sizeof(buf) - 1);
| buf[sizeof(buf) - 1] = ’\0’;

This could be better achieved using strlcpy(3), as shown in the
following example:

(void)strlcpy(buf, input, sizeof(buf));

**SEE ALSO**

bcopy(3), memccpy(3), memcpy(3), memmove(3), strlcpy(3), wcscpy(3)

**STANDARDS**

The **strcpy**\ () and **strncpy**\ () functions conform to ISO/IEC
9899:1990 (‘‘ISO C90’’). The **stpcpy**\ () and **stpncpy**\ ()
functions conform to IEEE Std 1003.1-2008 (‘‘POSIX.1’’).

**HISTORY**

The **stpcpy**\ () function first appeared in FreeBSD 4.4, and
**stpncpy**\ () was added in FreeBSD 8.0.

**SECURITY CONSIDERATIONS**

All of the functions documented in this manual page are easily misused
in a manner which enables malicious users to arbitrarily change a
running program’s functionality through a buffer overflow attack.

It is strongly suggested that the **strlcpy**\ () function be used in
almost all cases.

For some, but not all, fixed-length records, non-terminated strings may
be both valid and desirable. In that specific case, the **strncpy**\ ()
function may be most sensible.

BSD June 6, 2018 BSD

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

