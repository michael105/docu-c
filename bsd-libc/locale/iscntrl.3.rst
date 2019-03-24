--------------

ISCNTRL(3) BSD Library Functions Manual ISCNTRL(3)

**NAME**

**iscntrl** — control character test

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <ctype.h>**

*int*

**iscntrl**\ (*int c*);

*int*

**iscntrl_l**\ (*int c*, *locale_t loc*);

**DESCRIPTION**

The **iscntrl**\ () function tests for any control character. The value
of the argument must be representable as an *unsigned char* or the value
of EOF.

In the ASCII character set, this includes the following characters (with
their numeric values shown in octal):

+-----------------------------------+-----------------------------------+
|                                   | 000 NUL                           |
+-----------------------------------+-----------------------------------+
|                                   | 001 SOH                           |
+-----------------------------------+-----------------------------------+
|                                   | 002 STX                           |
+-----------------------------------+-----------------------------------+
|                                   | 003 ETX                           |
+-----------------------------------+-----------------------------------+
|                                   | 004 EOT                           |
+-----------------------------------+-----------------------------------+
|                                   | 005 ENQ                           |
+-----------------------------------+-----------------------------------+
|                                   | 006 ACK                           |
+-----------------------------------+-----------------------------------+
|                                   | 007 BEL                           |
+-----------------------------------+-----------------------------------+
|                                   | 010 BS                            |
+-----------------------------------+-----------------------------------+
|                                   | 011 HT                            |
+-----------------------------------+-----------------------------------+
|                                   | 012 NL                            |
+-----------------------------------+-----------------------------------+
|                                   | 013 VT                            |
+-----------------------------------+-----------------------------------+
|                                   | 014 NP                            |
+-----------------------------------+-----------------------------------+
|                                   | 015 CR                            |
+-----------------------------------+-----------------------------------+
|                                   | 016 SO                            |
+-----------------------------------+-----------------------------------+
|                                   | 017 SI                            |
+-----------------------------------+-----------------------------------+
|                                   | 020 DLE                           |
+-----------------------------------+-----------------------------------+
|                                   | 021 DC1                           |
+-----------------------------------+-----------------------------------+
|                                   | 022 DC2                           |
+-----------------------------------+-----------------------------------+
|                                   | 023 DC3                           |
+-----------------------------------+-----------------------------------+
|                                   | 024 DC4                           |
+-----------------------------------+-----------------------------------+
|                                   | 025 NAK                           |
+-----------------------------------+-----------------------------------+
|                                   | 026 SYN                           |
+-----------------------------------+-----------------------------------+
|                                   | 027 ETB                           |
+-----------------------------------+-----------------------------------+
|                                   | 030 CAN                           |
+-----------------------------------+-----------------------------------+
|                                   | 031 EM                            |
+-----------------------------------+-----------------------------------+
|                                   | 032 SUB                           |
+-----------------------------------+-----------------------------------+
|                                   | 033 ESC                           |
+-----------------------------------+-----------------------------------+
|                                   | 034 FS                            |
+-----------------------------------+-----------------------------------+
|                                   | 035 GS                            |
+-----------------------------------+-----------------------------------+
|                                   | 036 RS                            |
+-----------------------------------+-----------------------------------+
|                                   | 037 US                            |
+-----------------------------------+-----------------------------------+
|                                   | 177 DEL                           |
+-----------------------------------+-----------------------------------+

The **iscntrl_l**\ () function takes an explicit locale argument,
whereas the **iscntrl**\ () function uses the current global or
per-thread locale.

**RETURN VALUES**

The **iscntrl**\ () function returns zero if the character tests false
and returns non-zero if the character tests true.

**COMPATIBILITY**

The 4.4BSD extension of accepting arguments outside of the range of the
*unsigned char* type in locales with large character sets is considered
obsolete and may not be supported in future releases. The
**iswcntrl**\ () function should be used instead.

**SEE ALSO**

ctype(3), iswcntrl(3), xlocale(3), ascii(7)

**STANDARDS**

The **iscntrl**\ () function conforms to ISO/IEC 9899:1990
(‘‘ISO C90’’). The **iscntrl_l**\ () function conforms to IEEE Std
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

