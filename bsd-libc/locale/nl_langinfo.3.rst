--------------

NL_LANGINFO(3) BSD Library Functions Manual NL_LANGINFO(3)

**NAME**

**nl_langinfo** — language information

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <langinfo.h>**

*char \**

**nl_langinfo**\ (*nl_item item*);

*char \**

**nl_langinfo_l**\ (*nl_item item*, *locale_t loc*);

**DESCRIPTION**

The **nl_langinfo**\ () function returns a pointer to a string
containing information relevant to the particular language or cultural
area defined in the program or thread’s locale, or in the case of
**nl_langinfo_l**\ (), the locale passed as the second argument. The
manifest constant names and values of *item* are defined in
<*langinfo.h*>.

Calls to **setlocale**\ () with a category corresponding to the category
of *item*, or to the category LC_ALL, may overwrite the buffer pointed
to by the return value.

**RETURN VALUES**

In a locale where langinfo data is not defined, **nl_langinfo**\ ()
returns a pointer to the corresponding string in the POSIX locale.
**nl_langinfo_l**\ () returns the same values as **nl_langinfo**\ (). In
all locales, **nl_langinfo**\ () returns a pointer to an empty string if
*item* contains an invalid setting.

**EXAMPLES**

For example:

nl_langinfo(ABDAY_1)

would return a pointer to the string "Dom" if the identified language
was Portuguese, and "Sun" if the identified language was English.

**SEE ALSO**

setlocale(3)

**STANDARDS**

The **nl_langinfo**\ () function conforms to Version 2 of the Single
UNIX Specification (‘‘SUSv2’’). The **nl_langinfo_l**\ () function
conforms to IEEE Std 1003.1-2008 (‘‘POSIX.1’’).

**HISTORY**

The **nl_langinfo**\ () function first appeared in FreeBSD 4.6.

BSD July 30, 2012 BSD

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

