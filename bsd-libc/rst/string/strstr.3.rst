--------------

STRSTR(3) BSD Library Functions Manual STRSTR(3)

**NAME**

**strstr**, **strcasestr**, **strnstr** — locate a substring in a string

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <string.h>**

*char \**

**strstr**\ (*const char *big*, *const char *little*);

*char \**

**strcasestr**\ (*const char *big*, *const char *little*);

*char \**

**strnstr**\ (*const char *big*, *const char *little*, *size_t len*);

**#include <string.h>
#include <xlocale.h>**

*char \**

**strcasestr_l**\ (*const char *big*, *const char *little*,
*locale_t loc*);

**DESCRIPTION**

The **strstr**\ () function locates the first occurrence of the
null-terminated string *little* in the null-terminated string *big*.

The **strcasestr**\ () function is similar to **strstr**\ (), but
ignores the case of both strings.

The **strcasestr_l**\ () function does the same as **strcasestr**\ ()
but takes an explicit locale rather than using the current locale.

The **strnstr**\ () function locates the first occurrence of the
null-terminated string *little* in the string *big*, where not more than
*len* characters are searched. Characters that appear after a ‘\0’
character are not searched. Since the **strnstr**\ () function is a
FreeBSD specific API, it should only be used when portability is not a
concern.

**RETURN VALUES**

If *little* is an empty string, *big* is returned; if *little* occurs
nowhere in *big*, NULL is returned; otherwise a pointer to the first
character of the first occurrence of *little* is returned.

**EXAMPLES**

The following sets the pointer *ptr* to the "Bar Baz" portion of
*largestring*:

| const char \*largestring = "Foo Bar Baz";
| const char \*smallstring = "Bar";
| char \*ptr;

ptr = strstr(largestring, smallstring);

The following sets the pointer *ptr* to NULL, because only the first 4
characters of *largestring* are searched:

| const char \*largestring = "Foo Bar Baz";
| const char \*smallstring = "Bar";
| char \*ptr;

ptr = strnstr(largestring, smallstring, 4);

**SEE ALSO**

memchr(3), memmem(3), strchr(3), strcspn(3), strpbrk(3), strrchr(3),
strsep(3), strspn(3), strtok(3), wcsstr(3)

**STANDARDS**

The **strstr**\ () function conforms to ISO/IEC 9899:1990 (‘‘ISO C90’’).

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

