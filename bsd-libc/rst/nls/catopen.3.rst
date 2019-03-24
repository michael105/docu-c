--------------

CATOPEN(3) BSD Library Functions Manual CATOPEN(3)

**NAME**

**catopen** — open message catalog

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <nl_types.h>**

*nl_catd*

**catopen**\ (*const char *name*, *int oflag*);

**DESCRIPTION**

The **catopen**\ () function opens the message catalog specified by
*name* and returns a message catalog descriptor. If *name* contains a
‘/’ then *name* specifies the full pathname for the message catalog,
otherwise the value of the environment variable NLSPATH is used with the
following substitutions:

%N

The value of the *name* argument.

%L

The value of the LANG environment variable or the LC_MESSAGES category
(see below).

%l

The language element from the LANG environment variable or from the
LC_MESSAGES category.

%t

The territory element from the LANG environment variable or from the
LC_MESSAGES category.

%c

The codeset element from the LANG environment variable or from the
LC_MESSAGES category.

%%

A single % character.

An empty string is substituted for undefined values.

Path names templates defined in NLSPATH are separated by colons (‘:’). A
leading or two adjacent colons is equivalent to specifying %N.

If the *oflag* argument is set to the NL_CAT_LOCALE constant,
LC_MESSAGES locale category used to open the message catalog; using
NL_CAT_LOCALE conforms to the X/Open Portability Guide Issue 4
(‘‘XPG4’’) standard. You can specify 0 for compatibility with X/Open
Portability Guide Issue 3 (‘‘XPG3’’); when *oflag* is set to 0, the LANG
environment variable determines the message catalog locale.

A message catalog descriptor remains valid in a process until that
process closes it, or until a successful call to one of the exec(3)
function.

**RETURN VALUES**

Upon successful completion, **catopen**\ () returns a message catalog
descriptor. Otherwise, (nl_catd) -1 is returned and *errno* is set to
indicate the error.

| **ERRORS**
| [EINVAL]

Argument *name* does not point to a valid message catalog, or catalog is
corrupt.

[ENAMETOOLONG]

An entire path to the message catalog exceeded 1024 characters.

[ENOENT]

The named message catalog does not exists, or the *name* argument points
to an empty string.

[ENOMEM]

Insufficient memory is available.

**SEE ALSO**

gencat(1), catclose(3), catgets(3), setlocale(3)

**STANDARDS**

The **catopen**\ () function conforms to IEEE Std 1003.1-2001
(‘‘POSIX.1’’).

BSD February 12, 2005 BSD

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

