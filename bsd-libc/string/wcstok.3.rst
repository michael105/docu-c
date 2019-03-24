--------------

WCSTOK(3) BSD Library Functions Manual WCSTOK(3)

**NAME**

**wcstok** — split wide-character string into tokens

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <wchar.h>**

*wchar_t \**

**wcstok**\ (*wchar_t * restrict str*, *const wchar_t * restrict sep*,
*wchar_t ** restrict last*);

**DESCRIPTION**

The **wcstok**\ () function is used to isolate sequential tokens in a
null-terminated wide character string, *str*. These tokens are separated
in the string by at least one of the characters in *sep*. The first time
that **wcstok**\ () is called, *str* should be specified; subsequent
calls, wishing to obtain further tokens from the same string, should
pass a null pointer instead. The separator string, *sep*, must be
supplied each time, and may change between calls. The context pointer
*last* must be provided on each call.

The **wcstok**\ () function is the wide character counterpart of the
**strtok_r**\ () function.

**RETURN VALUES**

The **wcstok**\ () function returns a pointer to the beginning of each
subsequent token in the string, after replacing the token itself with a
null wide character (L’\0’). When no more tokens remain, a null pointer
is returned.

**EXAMPLES**

The following code fragment splits a wide character string on ASCII
space, tab and newline characters and writes the tokens to standard
output:

| const wchar_t \*seps = L" \\t\n";
| wchar_t \*last, \*tok, text[] = L" \\none\ttwo\t\tthree \\n";

| for (tok = wcstok(text, seps, &last); tok != NULL;
| tok = wcstok(NULL, seps, &last))

+-----------------------+-----------------------+-----------------------+
|                       | wprintf(L"%ls\n",     |                       |
|                       | tok);                 |                       |
+-----------------------+-----------------------+-----------------------+

**COMPATIBILITY**

Some early implementations of **wcstok**\ () omit the context pointer
argument, *last*, and maintain state across calls in a static variable
like **strtok**\ () does.

**SEE ALSO**

strtok(3), wcschr(3), wcscspn(3), wcspbrk(3), wcsrchr(3), wcsspn(3)

**STANDARDS**

The **wcstok**\ () function conforms to ISO/IEC 9899:1999 (‘‘ISO C99’’).

BSD October 3, 2002 BSD

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

