--------------

NEWLOCALE(3) BSD Library Functions Manual NEWLOCALE(3)

**NAME**

**newlocale** — Creates a new locale

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <locale.h>**

*locale_t*

**newlocale**\ (*int mask*, *const char * locale*, *locale_t base*);

**DESCRIPTION**

Creates a new locale, inheriting some properties from an existing
locale. The *mask* defines the components that the new locale will have
set to the locale with the name specified in the *locale* parameter. Any
other components will be inherited from *base*. The *mask* is either
*LC_ALL_MASK*, indicating all possible locale components, or the logical
OR of some combination of the following:

LC_COLLATE_MASK

The locale for string collation routines. This controls alphabetic
ordering in strcoll(3) and strxfrm(3).

LC_CTYPE_MASK

The locale for the ctype(3) and multibyte(3) functions. This controls
recognition of upper and lower case, alphabetic or non-alphabetic
characters, and so on.

LC_MESSAGES_MASK

Set a locale for message catalogs, see catopen(3) function.

LC_MONETARY_MASK

Set a locale for formatting monetary values; this affects the
localeconv(3) function.

LC_NUMERIC_MASK

Set a locale for formatting numbers. This controls the formatting of
decimal points in input and output of floating point numbers in
functions such as printf(3) and scanf(3), as well as values returned by
localeconv(3).

LC_TIME_MASK

Set a locale for formatting dates and times using the strftime(3)
function.

This function uses the same rules for loading locale components as
setlocale(3).

**RETURN VALUES**

Returns a new, valid, *locale_t* or NULL if an error occurs. You must
free the returned locale with freelocale(3).

**SEE ALSO**

duplocale(3), freelocale(3), localeconv(3), querylocale(3),
uselocale(3), xlocale(3)

**STANDARDS**

This function conforms to IEEE Std 1003.1-2008 (‘‘POSIX.1’’).

BSD September 17, 2011 BSD

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

