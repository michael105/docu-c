--------------

STRLCPY(3) BSD Library Functions Manual STRLCPY(3)

**NAME**

**strlcpy**, **strlcat** — size-bounded string copying and concatenation

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <string.h>**

*size_t*

**strlcpy**\ (*char * restrict dst*, *const char * restrict src*,
*size_t dstsize*);

*size_t*

**strlcat**\ (*char * restrict dst*, *const char * restrict src*,
*size_t dstsize*);

**DESCRIPTION**

The **strlcpy**\ () and **strlcat**\ () functions copy and concatenate
strings with the same input parameters and output result as snprintf(3).
They are designed to be safer, more consistent, and less error prone
replacements for the easily misused functions strncpy(3) and strncat(3).

**strlcpy**\ () and **strlcat**\ () take the full size of the
destination buffer and guarantee NUL-termination if there is room. Note
that room for the NUL should be included in *dstsize*.

**strlcpy**\ () copies up to *dstsize* − 1 characters from the string
*src* to *dst*, NUL-terminating the result if *dstsize* is not 0.

**strlcat**\ () appends string *src* to the end of *dst*. It will append
at most *dstsize* − strlen(dst) − 1 characters. It will then
NUL-terminate, unless *dstsize* is 0 or the original *dst* string was
longer than *dstsize* (in practice this should not happen as it means
that either *dstsize* is incorrect or that *dst* is not a proper
string).

If the *src* and *dst* strings overlap, the behavior is undefined.

**RETURN VALUES**

Besides quibbles over the return type (*size_t* versus *int*) and signal
handler safety (snprintf(3) is not entirely safe on some systems), the
following two are equivalent:

| n = strlcpy(dst, src, len);
| n = snprintf(dst, len, "%s", src);

Like snprintf(3), the **strlcpy**\ () and **strlcat**\ () functions
return the total length of the string they tried to create. For
**strlcpy**\ () that means the length of *src*. For **strlcat**\ () that
means the initial length of *dst* plus the length of *src*.

If the return value is **>=** *dstsize*, the output string has been
truncated. It is the caller’s responsibility to handle this.

**EXAMPLES**

The following code fragment illustrates the simple case:

char \*s, \*p, buf[BUFSIZ];

...

| (void)strlcpy(buf, s, sizeof(buf));
| (void)strlcat(buf, p, sizeof(buf));

To detect truncation, perhaps while building a pathname, something like
the following might be used:

char \*dir, \*file, pname[MAXPATHLEN];

...

if (strlcpy(pname, dir, sizeof(pname)) >= sizeof(pname))

+-----------------------+-----------------------+-----------------------+
|                       | goto toolong;         |                       |
+-----------------------+-----------------------+-----------------------+

if (strlcat(pname, file, sizeof(pname)) >= sizeof(pname))

+-----------------------------------+-----------------------------------+
|                                   | goto toolong;                     |
+-----------------------------------+-----------------------------------+

Since it is known how many characters were copied the first time, things
can be sped up a bit by using a copy instead of an append:

| char \*dir, \*file, pname[MAXPATHLEN];
| size_t n;

...

| n = strlcpy(pname, dir, sizeof(pname));
| if (n >= sizeof(pname))

+-----------------------------------+-----------------------------------+
|                                   | goto toolong;                     |
+-----------------------------------+-----------------------------------+

if (strlcpy(pname + n, file, sizeof(pname) - n) >= sizeof(pname) - n)

+-----------------------------------+-----------------------------------+
|                                   | goto toolong;                     |
+-----------------------------------+-----------------------------------+

However, one may question the validity of such optimizations, as they
defeat the whole purpose of **strlcpy**\ () and **strlcat**\ (). As a
matter of fact, the first version of this manual page got it wrong.

**SEE ALSO**

snprintf(3), strncat(3), strncpy(3), wcslcpy(3)

**HISTORY**

The **strlcpy**\ () and **strlcat**\ () functions first appeared in
OpenBSD 2.4, and FreeBSD 3.3.

BSD February 26, 2016 BSD

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

