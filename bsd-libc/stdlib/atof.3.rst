--------------

ATOF(3) BSD Library Functions Manual ATOF(3)

**NAME**

**atof** — convert ASCII string to double

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <stdlib.h>**

*double*

**atof**\ (*const char *nptr*);

**DESCRIPTION**

The **atof**\ () function converts the initial portion of the string
pointed to by *nptr* to *double* representation.

It is equivalent to:

strtod(nptr, (char \**)NULL);

The decimal point character is defined in the program’s locale (category
LC_NUMERIC).

**IMPLEMENTATION NOTES**

The **atof**\ () function is not thread-safe and also not
async-cancel-safe.

The **atof**\ () function has been deprecated by **strtod**\ () and
should not be used in new code.

**ERRORS**

The function **atof**\ () need not affect the value of *errno* on an
error.

**SEE ALSO**

atoi(3), atol(3), strtod(3), strtol(3), strtoul(3)

**STANDARDS**

The **atof**\ () function conforms to ISO/IEC 9945-1:1990 (‘‘POSIX.1’’),
ISO/IEC 9899:1990 (‘‘ISO C90’’), and ISO/IEC 9899:1999 (‘‘ISO C99’’).

BSD June 4, 1993 BSD

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

