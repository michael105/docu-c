--------------

--------------

REMOVE(3) BSD Library Functions Manual REMOVE(3)

\**NAME*\*

\**remove*\* â remove directory entry

\**LIBRARY*\*

Standard CÂ Library (libc, âlc)

\**SYNOPSIS*\*

\**#include <stdio.h>*\*

\*int\*

\**remove** (*constÂ charÂ *path*);

\**DESCRIPTION*\*

The \**remove** () function removes the file or directory specified by
\*path*.

If \*path\* specifies a directory, \**remove** (*path*) is the
equivalent of \**rmdir** (*path*). Otherwise, it is the equivalent of
\**unlink** (*path*).

\**RETURN VALUES*\*

The \**remove** () function returns the valueÂ 0 if successful;
otherwise the valueÂ â1 is returned and the global variable \*errno\* is
set to indicate the error.

\**ERRORS*\*

The \**remove** () function may fail and set \*errno\* for any of the
errors specified for the routines lstat(2), rmdir(2) or unlink(2).

\**SEE ALSO*\*

rmdir(2), unlink(2)

\**STANDARDS*\*

The \**remove** () function conforms to ISO/IEC 9899:1990 (ââISOÂ C90ââ)
and X/Open Portability Guide IssueÂ 4, VersionÂ 2 (ââXPG4.2ââ).

BSD JuneÂ 4, 1993 BSD

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

