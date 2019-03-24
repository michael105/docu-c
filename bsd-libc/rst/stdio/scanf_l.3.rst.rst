--------------

--------------

SCANF_L(3) BSD Library Functions Manual SCANF_L(3)

\**NAME*\*

\**scanf_l**, \**fscanf_l**, \**sscanf_l**, \**vfscanf_l**,
\**vscanf_l**, \**vsscanf_l*\* â input format conversion

\**LIBRARY*\*

Standard CÂ Library (libc, âlc)

\**SYNOPSIS*\*

\**#include <stdio.h> #include <xlocale.h>*\*

\*int\*

\**scanf_l** (*locale_tÂ loc*, \*constÂ charÂ *Â restrictÂ format*,
\*...*);

\*int\*

\**fscanf_l** (*FILEÂ *Â restrictÂ stream*, \*locale_tÂ loc*,
\*constÂ charÂ *Â restrictÂ format*, \*...*);

\*int\*

\**sscanf_l** (*constÂ charÂ *Â restrictÂ str*, \*locale_tÂ loc*,
\*constÂ charÂ *Â restrictÂ format*, \*...*);

\*int\*

\**vfscanf_l** (*FILEÂ *Â restrictÂ stream*, \*locale_tÂ loc*,
\*constÂ charÂ *Â restrictÂ format*, \*va_listÂ ap*);

\*int\*

\**vscanf_l** (*locale_tÂ loc*, \*constÂ charÂ *Â restrictÂ format*,
\*va_listÂ ap*);

\*int\*

\**vsscanf_l** (*constÂ charÂ *Â restrictÂ str*, \*locale_tÂ loc*,
\*constÂ charÂ *Â restrictÂ format*, \*va_listÂ ap*);

\**DESCRIPTION*\*

The above functions scan input according to a specified \*format\* in
the locale \*loc*. They behave in the same way as the versions without
the \_l suffix, but use the specific locale rather than the global or
per-thread locale. See the specific manual pages for more information.

\**SEE ALSO*\*

scanf(3), xlocale(3)

\**STANDARDS*\*

These functions do not conform to any specific standard so they should
be considered as non-portable local extensions.

\**HISTORY*\*

These functions first appeared in Darwin and were first implemented in
FreeBSDÂ 9.1.

BSD AprilÂ 8, 2012 BSD

--------------

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

