--------------

ISALPHA(3) BSD Library Functions Manual ISALPHA(3)

**NAME**

**isalpha** — alphabetic character test

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <ctype.h>**

*int*

**isalpha**\ (*int c*);

*int*

**isalpha_l**\ (*int c*, *locale_t loc*);

**DESCRIPTION**

The **isalpha**\ () function tests for any character for which
isupper(3) or islower(3) is true. The value of the argument must be
representable as an *unsigned char* or the value of EOF.

In the ASCII character set, this includes the following characters (with
their numeric values shown in octal):

+-----------------------------------+-----------------------------------+
|                                   | 101 ‘‘A’’                         |
+-----------------------------------+-----------------------------------+
|                                   | 102 ‘‘B’’                         |
+-----------------------------------+-----------------------------------+
|                                   | 103 ‘‘C’’                         |
+-----------------------------------+-----------------------------------+
|                                   | 104 ‘‘D’’                         |
+-----------------------------------+-----------------------------------+
|                                   | 105 ‘‘E’’                         |
+-----------------------------------+-----------------------------------+
|                                   | 106 ‘‘F’’                         |
+-----------------------------------+-----------------------------------+
|                                   | 107 ‘‘G’’                         |
+-----------------------------------+-----------------------------------+
|                                   | 110 ‘‘H’’                         |
+-----------------------------------+-----------------------------------+
|                                   | 111 ‘‘I’’                         |
+-----------------------------------+-----------------------------------+
|                                   | 112 ‘‘J’’                         |
+-----------------------------------+-----------------------------------+
|                                   | 113 ‘‘K’’                         |
+-----------------------------------+-----------------------------------+
|                                   | 114 ‘‘L’’                         |
+-----------------------------------+-----------------------------------+
|                                   | 115 ‘‘M’’                         |
+-----------------------------------+-----------------------------------+
|                                   | 116 ‘‘N’’                         |
+-----------------------------------+-----------------------------------+
|                                   | 117 ‘‘O’’                         |
+-----------------------------------+-----------------------------------+
|                                   | 120 ‘‘P’’                         |
+-----------------------------------+-----------------------------------+
|                                   | 121 ‘‘Q’’                         |
+-----------------------------------+-----------------------------------+
|                                   | 122 ‘‘R’’                         |
+-----------------------------------+-----------------------------------+
|                                   | 123 ‘‘S’’                         |
+-----------------------------------+-----------------------------------+
|                                   | 124 ‘‘T’’                         |
+-----------------------------------+-----------------------------------+
|                                   | 125 ‘‘U’’                         |
+-----------------------------------+-----------------------------------+
|                                   | 126 ‘‘V’’                         |
+-----------------------------------+-----------------------------------+
|                                   | 127 ‘‘W’’                         |
+-----------------------------------+-----------------------------------+
|                                   | 130 ‘‘X’’                         |
+-----------------------------------+-----------------------------------+
|                                   | 131 ‘‘Y’’                         |
+-----------------------------------+-----------------------------------+
|                                   | 132 ‘‘Z’’                         |
+-----------------------------------+-----------------------------------+
|                                   | 141 ‘‘a’’                         |
+-----------------------------------+-----------------------------------+
|                                   | 142 ‘‘b’’                         |
+-----------------------------------+-----------------------------------+
|                                   | 143 ‘‘c’’                         |
+-----------------------------------+-----------------------------------+
|                                   | 144 ‘‘d’’                         |
+-----------------------------------+-----------------------------------+
|                                   | 145 ‘‘e’’                         |
+-----------------------------------+-----------------------------------+
|                                   | 146 ‘‘f’’                         |
+-----------------------------------+-----------------------------------+
|                                   | 147 ‘‘g’’                         |
+-----------------------------------+-----------------------------------+
|                                   | 150 ‘‘h’’                         |
+-----------------------------------+-----------------------------------+
|                                   | 151 ‘‘i’’                         |
+-----------------------------------+-----------------------------------+
|                                   | 152 ‘‘j’’                         |
+-----------------------------------+-----------------------------------+
|                                   | 153 ‘‘k’’                         |
+-----------------------------------+-----------------------------------+
|                                   | 154 ‘‘l’’                         |
+-----------------------------------+-----------------------------------+
|                                   | 155 ‘‘m’’                         |
+-----------------------------------+-----------------------------------+
|                                   | 156 ‘‘n’’                         |
+-----------------------------------+-----------------------------------+
|                                   | 157 ‘‘o’’                         |
+-----------------------------------+-----------------------------------+
|                                   | 160 ‘‘p’’                         |
+-----------------------------------+-----------------------------------+
|                                   | 161 ‘‘q’’                         |
+-----------------------------------+-----------------------------------+
|                                   | 162 ‘‘r’’                         |
+-----------------------------------+-----------------------------------+
|                                   | 163 ‘‘s’’                         |
+-----------------------------------+-----------------------------------+
|                                   | 164 ‘‘t’’                         |
+-----------------------------------+-----------------------------------+
|                                   | 165 ‘‘u’’                         |
+-----------------------------------+-----------------------------------+
|                                   | 166 ‘‘v’’                         |
+-----------------------------------+-----------------------------------+
|                                   | 167 ‘‘w’’                         |
+-----------------------------------+-----------------------------------+
|                                   | 170 ‘‘x’’                         |
+-----------------------------------+-----------------------------------+
|                                   | 171 ‘‘y’’                         |
+-----------------------------------+-----------------------------------+
|                                   | 172 ‘‘z’’                         |
+-----------------------------------+-----------------------------------+

The **isalpha_l**\ () function takes an explicit locale argument,
whereas the **isalpha**\ () function uses the current global or
per-thread locale.

**RETURN VALUES**

The **isalpha**\ () function returns zero if the character tests false
and returns non-zero if the character tests true.

**COMPATIBILITY**

The 4.4BSD extension of accepting arguments outside of the range of the
*unsigned char* type in locales with large character sets is considered
obsolete and may not be supported in future releases. The
**iswalpha**\ () function should be used instead.

**SEE ALSO**

ctype(3), islower(3), isupper(3), iswalpha(3), xlocale(3), ascii(7)

**STANDARDS**

The **isalpha**\ () function conforms to ISO/IEC 9899:1990
(‘‘ISO C90’’). The **isalpha_l**\ () function conforms to IEEE Std
1003.1-2008 (‘‘POSIX.1’’).

BSD July 17, 2005 BSD

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

