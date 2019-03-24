--------------

ISPUNCT(3) BSD Library Functions Manual ISPUNCT(3)

**NAME**

**ispunct** — punctuation character test

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <ctype.h>**

*int*

**ispunct**\ (*int c*);

*int*

**ispunct_l**\ (*int c*, *locale_t loc*);

**DESCRIPTION**

The **ispunct**\ () function tests for any printing character except for
space (‘ ’) or a character for which isalnum(3) is true. The value of
the argument must be representable as an *unsigned char* or the value of
EOF.

In the ASCII character set, this includes the following characters (with
their numeric values shown in octal):

+-----------------------------------+-----------------------------------+
|                                   | 041 ‘‘!’’                         |
+-----------------------------------+-----------------------------------+
|                                   | 042 ‘‘"’’                         |
+-----------------------------------+-----------------------------------+
|                                   | 043 ‘‘#’’                         |
+-----------------------------------+-----------------------------------+
|                                   | 044 ‘‘$’’                         |
+-----------------------------------+-----------------------------------+
|                                   | 045 ‘‘%’’                         |
+-----------------------------------+-----------------------------------+
|                                   | 046 ‘‘&’’                         |
+-----------------------------------+-----------------------------------+
|                                   | 047 ‘‘’’’                         |
+-----------------------------------+-----------------------------------+
|                                   | 050 ‘‘(’’                         |
+-----------------------------------+-----------------------------------+
|                                   | 051 ‘‘)’’                         |
+-----------------------------------+-----------------------------------+
|                                   | 052 ‘‘*’’                         |
+-----------------------------------+-----------------------------------+
|                                   | 053 ‘‘+’’                         |
+-----------------------------------+-----------------------------------+
|                                   | 054 ‘‘,’’                         |
+-----------------------------------+-----------------------------------+
|                                   | 055 ‘‘-’’                         |
+-----------------------------------+-----------------------------------+
|                                   | 056 ‘‘.’’                         |
+-----------------------------------+-----------------------------------+
|                                   | 057 ‘‘/’’                         |
+-----------------------------------+-----------------------------------+
|                                   | 072 ‘‘:’’                         |
+-----------------------------------+-----------------------------------+
|                                   | 073 ‘‘;’’                         |
+-----------------------------------+-----------------------------------+
|                                   | 074 ‘‘<’’                         |
+-----------------------------------+-----------------------------------+
|                                   | 075 ‘‘=’’                         |
+-----------------------------------+-----------------------------------+
|                                   | 076 ‘‘>’’                         |
+-----------------------------------+-----------------------------------+
|                                   | 077 ‘‘?’’                         |
+-----------------------------------+-----------------------------------+
|                                   | 100 ‘‘@’’                         |
+-----------------------------------+-----------------------------------+
|                                   | 133 ‘‘[’’                         |
+-----------------------------------+-----------------------------------+
|                                   | 134 ‘‘\’’                         |
+-----------------------------------+-----------------------------------+
|                                   | 135 ‘‘]’’                         |
+-----------------------------------+-----------------------------------+
|                                   | 136 ‘‘^’’                         |
+-----------------------------------+-----------------------------------+
|                                   | 137 ‘‘_’’                         |
+-----------------------------------+-----------------------------------+
|                                   | 140 ‘‘‘’’                         |
+-----------------------------------+-----------------------------------+
|                                   | 173 ‘‘{’’                         |
+-----------------------------------+-----------------------------------+
|                                   | 174 ‘‘|’’                         |
+-----------------------------------+-----------------------------------+
|                                   | 175 ‘‘}’’                         |
+-----------------------------------+-----------------------------------+
|                                   | 176 ‘‘~’’                         |
+-----------------------------------+-----------------------------------+

The **ispunct_l**\ () function takes an explicit locale argument,
whereas the **ispunct**\ () function uses the current global or
per-thread locale.

**RETURN VALUES**

The **ispunct**\ () and **ispunct_l**\ () functions return zero if the
character tests false and return non-zero if the character tests true.

**COMPATIBILITY**

The 4.4BSD extension of accepting arguments outside of the range of the
*unsigned char* type in locales with large character sets is considered
obsolete and may not be supported in future releases. The
**iswpunct**\ () function should be used instead.

**SEE ALSO**

ctype(3), iswpunct(3), ascii(7)

**STANDARDS**

The **ispunct**\ () function conforms to ISO/IEC 9899:1990
(‘‘ISO C90’’). The **ispunct_l**\ () function conforms to IEEE Std
1003.1-2008 (‘‘POSIX.1’’).

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

