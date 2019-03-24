--------------

WCTRANS(3) BSD Library Functions Manual WCTRANS(3)

**NAME**

**towctrans**, **wctrans** — wide character mapping functions

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <wctype.h>**

*wint_t*

**towctrans**\ (*wint_t wc*, *wctrans_t desc*);

*wctrans_t*

**wctrans**\ (*const char *charclass*);

**DESCRIPTION**

The **wctrans**\ () function returns a value of type *wctrans_t* which
represents the requested wide character mapping operation and may be
used as the second argument for calls to **towctrans**\ ().

The following character mapping names are recognised:

+-----------------+-----------------+-----------------+-----------------+
|                 | tolower         | toupper         |                 |
+-----------------+-----------------+-----------------+-----------------+

The **towctrans**\ () function transliterates the wide character *wc*
according to the mapping described by *desc*.

**RETURN VALUES**

The **towctrans**\ () function returns the transliterated character if
successful, otherwise it returns the character unchanged and sets
*errno*.

The **wctrans**\ () function returns non-zero if successful, otherwise
it returns zero and sets *errno*.

**EXAMPLES**

Reimplement **towupper**\ () in terms of **towctrans**\ () and
**wctrans**\ ():

| wint_t
| mytowupper(wint_t wc)
| {

+-----------------------+-----------------------+-----------------------+
|                       | return (towctrans(wc, |                       |
|                       | wctrans("toupper"))); |                       |
+-----------------------+-----------------------+-----------------------+

}

**ERRORS**

The **towctrans**\ () function will fail if:

[EINVAL]

The supplied *desc* argument is invalid.

The **wctrans**\ () function will fail if:

[EINVAL]

The requested mapping name is invalid.

**SEE ALSO**

tolower(3), toupper(3), wctype(3)

**STANDARDS**

The **towctrans**\ () and **wctrans**\ () functions conform to IEEE Std
1003.1-2001 (‘‘POSIX.1’’).

**HISTORY**

The **towctrans**\ () and **wctrans**\ () functions first appeared in
FreeBSD 5.0.

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

