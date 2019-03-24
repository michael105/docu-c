--------------

\__ICONV_GET_LIST(3) BSD Library Functions Manual \__ICONV_GET_LIST(3)

**NAME**

**\__iconv_get_list**, **\__iconv_free_list** — retrieving a list of
character encodings supported by iconv(3)

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <iconv.h>**

*int*

**\__iconv_get_list**\ (*char ***names*, *size_t count*, *bool paired*);

*void*

**\__iconv_free_list**\ (*char **names*, *size_t count*);

**DESCRIPTION**

The **\__iconv_get_list**\ () function obtains a list of character
encodings that are supported by the iconv(3) call. The list of the
encoding names will be stored in *names* and the number of the entries
is stored in *count*. If the *paired* variable is true, the list will be
arranged into canonical/alias name pairs.

The **\__iconv_free_list**\ () function is to free the allocated memory
during the call of **\__iconv_get_list**\ ().

**RETURN VALUES**

Upon successful completion **\__iconv_get_list**\ () returns 0 and set
the *names* and *count* arguments. Otherwise, −1 is returned and errno
is set to indicate the error.

**SEE ALSO**

iconv(3), iconvlist(3)

**STANDARDS**

The **\__iconv_get_list** and **\__iconv_free_list** functions are
non-standard interfaces, which appeared in the implementation of the
Citrus Project. The iconv implementation of the Citrus Project was
adopted in FreeBSD 9.0.

**AUTHORS**

This manual page was written by Gabor Kovesdan <*gabor@FreeBSD.org*>.

BSD October 20, 2009 BSD

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

