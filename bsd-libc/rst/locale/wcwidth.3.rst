--------------

WCWIDTH(3) BSD Library Functions Manual WCWIDTH(3)

**NAME**

**wcwidth** — number of column positions of a wide-character code

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <wchar.h>**

*int*

**wcwidth**\ (*wchar_t wc*);

**DESCRIPTION**

The **wcwidth**\ () function determines the number of column positions
required to display the wide character *wc*.

**RETURN VALUES**

The **wcwidth**\ () function returns 0 if the *wc* argument is a null
wide character (L’\0’), −1 if *wc* is not printable, otherwise it
returns the number of column positions the character occupies.

**EXAMPLES**

This code fragment reads text from standard input and breaks lines that
are more than 20 column positions wide, similar to the fold(1) utility:

| wint_t ch;
| int column, w;

| column = 0;
| while ((ch = getwchar()) != WEOF) {

+-----------------+-----------------+-----------------+-----------------+
|                 | w =             |                 |                 |
|                 | wcwidth(ch);    |                 |                 |
+-----------------+-----------------+-----------------+-----------------+
|                 | if (w > 0 &&    |                 |                 |
|                 | column + w >=   |                 |                 |
|                 | 20) {           |                 |                 |
+-----------------+-----------------+-----------------+-----------------+
|                 |                 | putwchar(L’\n’) |                 |
|                 |                 | ;               |                 |
+-----------------+-----------------+-----------------+-----------------+
|                 |                 | column = 0;     |                 |
+-----------------+-----------------+-----------------+-----------------+
|                 | }               |                 |                 |
+-----------------+-----------------+-----------------+-----------------+
|                 | putwchar(ch);   |                 |                 |
+-----------------+-----------------+-----------------+-----------------+
|                 | if (ch ==       |                 |                 |
|                 | L’\n’)          |                 |                 |
+-----------------+-----------------+-----------------+-----------------+
|                 |                 | column = 0;     |                 |
+-----------------+-----------------+-----------------+-----------------+
|                 | else if (w > 0) |                 |                 |
+-----------------+-----------------+-----------------+-----------------+
|                 |                 | column += w;    |                 |
+-----------------+-----------------+-----------------+-----------------+

}

**SEE ALSO**

iswprint(3), wcswidth(3)

**STANDARDS**

The **wcwidth**\ () function conforms to IEEE Std 1003.1-2001
(‘‘POSIX.1’’).

BSD August 17, 2004 BSD

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

