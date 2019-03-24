--------------

FMTCHECK(3) BSD Library Functions Manual FMTCHECK(3)

**NAME**

**fmtcheck** — sanitizes user-supplied printf(3)-style format string

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <stdio.h>**

*const char \**

**fmtcheck**\ (*const char *fmt_suspect*, *const char *fmt_default*);

**DESCRIPTION**

The **fmtcheck**\ () scans *fmt_suspect* and *fmt_default* to determine
if *fmt_suspect* will consume the same argument types as *fmt_default*
and to ensure that *fmt_suspect* is a valid format string.

The printf(3) family of functions cannot verify the types of arguments
that they are passed at run-time. In some cases, like catgets(3), it is
useful or necessary to use a user-supplied format string with no
guarantee that the format string matches the specified arguments.

The **fmtcheck**\ () was designed to be used in these cases, as in:

printf(fmtcheck(user_format, standard_format), arg1, arg2);

In the check, field widths, fillers, precisions, etc. are ignored
(unless the field width or precision is an asterisk ‘*’ instead of a
digit string). Also, any text other than the format specifiers is
completely ignored.

**RETURN VALUES**

If *fmt_suspect* is a valid format and consumes the same argument types
as *fmt_default*, then the **fmtcheck**\ () will return *fmt_suspect*.
Otherwise, it will return *fmt_default*.

**SEE ALSO**

printf(3)

**BUGS**

The **fmtcheck**\ () function does not recognize positional parameters.

**SECURITY CONSIDERATIONS**

Note that the formats may be quite different as long as they accept the
same arguments. For example, "%p %o %30s %#llx %-10.*e %n" is compatible
with "This number %lu %d%% and string %s has %qd numbers and %.*g floats
(%n)". However, "%o" is not equivalent to "%lx" because the first
requires an integer and the second requires a long.

BSD October 16, 2002 BSD

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

