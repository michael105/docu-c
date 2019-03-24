--------------

WMEMCHR(3) BSD Library Functions Manual WMEMCHR(3)

**NAME**

**wmemchr**, **wmemcmp**, **wmemcpy**, **wmemmove**, **wmemset**,
**wcpcpy**, **wcpncpy**, **wcscasecmp**, **wcscat**, **wcschr**,
**wcscmp**, **wcscpy**, **wcscspn**, **wcsdup**, **wcslcat**,
**wcslcpy**, **wcslen**, **wcsncasecmp**, **wcsncat**, **wcsncmp**,
**wcsncpy**, **wcsnlen**, **wcspbrk**, **wcsrchr**, **wcsspn**,
**wcsstr** — wide character string manipulation operations

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <wchar.h>**

*wchar_t \**

**wmemchr**\ (*const wchar_t *s*, *wchar_t c*, *size_t n*);

*int*

**wmemcmp**\ (*const wchar_t *s1*, *const wchar_t *s2*, *size_t n*);

*wchar_t \**

**wmemcpy**\ (*wchar_t * restrict s1*, *const wchar_t * restrict s2*,
*size_t n*);

*wchar_t \**

**wmemmove**\ (*wchar_t *s1*, *const wchar_t *s2*, *size_t n*);

*wchar_t \**

**wmemset**\ (*wchar_t *s*, *wchar_t c*, *size_t n*);

*wchar_t \**

**wcpcpy**\ (*wchar_t *s1*, *wchar_t *s2*);

*wchar_t \**

**wcpncpy**\ (*wchar_t *s1*, *wchar_t *s2*, *size_t n*);

*int*

**wcscasecmp**\ (*const wchar_t *s1*, *const wchar_t *s2*);

*wchar_t \**

**wcscat**\ (*wchar_t * restrict s1*, *const wchar_t * restrict s2*);

*wchar_t \**

**wcschr**\ (*const wchar_t *s*, *wchar_t c*);

*int*

**wcscmp**\ (*const wchar_t *s1*, *const wchar_t *s2*);

*wchar_t \**

**wcscpy**\ (*wchar_t * restrict s1*, *const wchar_t * restrict s2*);

*size_t*

**wcscspn**\ (*const wchar_t *s1*, *const wchar_t *s2*);

*wchar_t \**

**wcsdup**\ (*const wchar_t *s*);

*size_t*

**wcslcat**\ (*wchar_t *s1*, *const wchar_t *s2*, *size_t n*);

*size_t*

**wcslcpy**\ (*wchar_t *s1*, *const wchar_t *s2*, *size_t n*);

*size_t*

**wcslen**\ (*const wchar_t *s*);

*int*

**wcsncasecmp**\ (*const wchar_t *s1*, *const wchar_t *s2*, *size_t n*);

*wchar_t \**

**wcsncat**\ (*wchar_t * restrict s1*, *const wchar_t * restrict s2*,
*size_t n*);

*int*

**wcsncmp**\ (*const wchar_t *s1*, *const wchar_t * s2*, *size_t n*);

*wchar_t \**

**wcsncpy**\ (*wchar_t * restrict s1*, *const wchar_t * restrict s2*,
*size_t n*);

*size_t*

**wcsnlen**\ (*const wchar_t *s*, *size_t maxlen*);

*wchar_t \**

**wcspbrk**\ (*const wchar_t *s1*, *const wchar_t *s2*);

*wchar_t \**

**wcsrchr**\ (*const wchar_t *s*, *wchar_t c*);

*size_t*

**wcsspn**\ (*const wchar_t *s1*, *const wchar_t *s2*);

*wchar_t \**

**wcsstr**\ (*const wchar_t * restrict s1*,
*const wchar_t * restrict s2*);

**DESCRIPTION**

The functions implement string manipulation operations over wide
character strings. For a detailed description, refer to documents for
the respective single-byte counterpart, such as memchr(3).

**SEE ALSO**

memchr(3), memcmp(3), memcpy(3), memmove(3), memset(3), stpcpy(3),
stpncpy(3), strcasecmp(3), strcat(3), strchr(3), strcmp(3), strcpy(3),
strcspn(3), strdup(3), strlcat(3), strlcpy(3), strlen(3), strncat(3),
strncmp(3), strncpy(3), strnlen(3), strpbrk(3), strrchr(3), strspn(3),
strstr(3)

**STANDARDS**

These functions conform to ISO/IEC 9899:1999 (‘‘ISO C99’’), with the
exception of **wcpcpy**\ (), **wcpncpy**\ (), **wcscasecmp**\ (),
**wcsdup**\ (), **wcsncasecmp**\ (), and **wcsnlen**\ (), which conform
to IEEE Std 1003.1-2008 (‘‘POSIX.1’’); and **wcslcat**\ () and
**wcslcpy**\ (), which are extensions.

BSD March 4, 2009 BSD

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

