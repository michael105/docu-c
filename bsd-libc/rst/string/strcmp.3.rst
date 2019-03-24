--------------

STRCMP(3) BSD Library Functions Manual STRCMP(3)

**NAME**

**strcmp**, **strncmp** — compare strings

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <string.h>**

*int*

**strcmp**\ (*const char *s1*, *const char *s2*);

*int*

**strncmp**\ (*const char *s1*, *const char *s2*, *size_t len*);

**DESCRIPTION**

The **strcmp**\ () and **strncmp**\ () functions lexicographically
compare the null-terminated strings *s1* and *s2*.

The **strncmp**\ () function compares not more than *len* characters.
Because **strncmp**\ () is designed for comparing strings rather than
binary data, characters that appear after a ‘\0’ character are not
compared.

**RETURN VALUES**

The **strcmp**\ () and **strncmp**\ () functions return an integer
greater than, equal to, or less than 0, according as the string *s1* is
greater than, equal to, or less than the string *s2*. The comparison is
done using unsigned characters, so that ‘\200’ is greater than ‘\0’.

**SEE ALSO**

bcmp(3), memcmp(3), strcasecmp(3), strcoll(3), strxfrm(3), wcscmp(3)

**STANDARDS**

The **strcmp**\ () and **strncmp**\ () functions conform to ISO/IEC
9899:1990 (‘‘ISO C90’’).

BSD October 11, 2001 BSD

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

