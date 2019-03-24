--------------

STRSPN(3) BSD Library Functions Manual STRSPN(3)

**NAME**

**strspn**, **strcspn** — span a string

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <string.h>**

*size_t*

**strspn**\ (*const char *s*, *const char *charset*);

*size_t*

**strcspn**\ (*const char *s*, *const char *charset*);

**DESCRIPTION**

The **strspn**\ () function spans the initial part of the
null-terminated string *s* as long as the characters from *s* occur in
the null-terminated string *charset*. In other words, it computes the
string array index of the first character of *s* which is not in
*charset*, else the index of the first null character.

The **strcspn**\ () function spans the initial part of the
null-terminated string *s* as long as the characters from *s* **do not**
occur in the null-terminated string *charset* (

it spans the **complement** of *charset* ). In other words, it computes
the string array index of the first character of *s* which is also in
*charset*, else the index of the first null character.

**RETURN VALUES**

The **strspn**\ () and **strcspn**\ () functions return the number of
characters spanned.

**SEE ALSO**

memchr(3), strchr(3), strpbrk(3), strrchr(3), strsep(3), strstr(3),
strtok(3), wcsspn(3)

**STANDARDS**

The **strspn**\ () and **strcspn**\ () functions conform to ISO/IEC
9899:1990 (‘‘ISO C90’’).

BSD May 24, 2014 BSD

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

