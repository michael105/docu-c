--------------

SETLOCALE(3) BSD Library Functions Manual SETLOCALE(3)

**NAME**

**setlocale** — natural language formatting for C

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <locale.h>**

*char \**

**setlocale**\ (*int category*, *const char *locale*);

**DESCRIPTION**

The **setlocale**\ () function sets the C library’s notion of natural
language formatting style for particular sets of routines. Each such
style is called a ‘locale’ and is invoked using an appropriate name
passed as a C string.

The **setlocale**\ () function recognizes several categories of
routines. These are the categories and the sets of routines they select:

LC_ALL

Set the entire locale generically.

LC_COLLATE

Set a locale for string collation routines. This controls alphabetic
ordering in **strcoll**\ () and **strxfrm**\ ().

LC_CTYPE

Set a locale for the ctype(3) and multibyte(3) functions. This controls
recognition of upper and lower case, alphabetic or non-alphabetic
characters, and so on.

LC_MESSAGES

Set a locale for message catalogs, see catopen(3) function.

LC_MONETARY

Set a locale for formatting monetary values; this affects the
**localeconv**\ () function.

LC_NUMERIC

Set a locale for formatting numbers. This controls the formatting of
decimal points in input and output of floating point numbers in
functions such as **printf**\ () and **scanf**\ (), as well as values
returned by **localeconv**\ ().

LC_TIME

Set a locale for formatting dates and times using the **strftime**\ ()
function.

Only three locales are defined by default, the empty string "" which
denotes the native environment, and the "C" and "POSIX" locales, which
denote the C language environment. A *locale* argument of NULL causes
**setlocale**\ () to return the current locale. By default, C programs
start in the "C" locale. The only function in the library that sets the
locale is **setlocale**\ (); the locale is never changed as a side
effect of some other routine.

**RETURN VALUES**

Upon successful completion, **setlocale**\ () returns the string
associated with the specified *category* for the requested *locale*. The
**setlocale**\ () function returns NULL and fails to change the locale
if the given combination of *category* and *locale* makes no sense.

| **FILES**
| $PATH_LOCALE/\ *locale/category*
| /usr/share/locale/*locale/category*

locale file for the locale *locale* and the category *category*.

**ERRORS**

No errors are defined.

**SEE ALSO**

colldef(1), mklocale(1), catopen(3), ctype(3), localeconv(3),
multibyte(3), strcoll(3), strxfrm(3), euc(5), utf8(5), environ(7)

**STANDARDS**

The **setlocale**\ () function conforms to ISO/IEC 9899:1999
(‘‘ISO C99’’).

**HISTORY**

The **setlocale**\ () function first appeared in 4.4BSD.

BSD November 21, 2003 BSD

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

