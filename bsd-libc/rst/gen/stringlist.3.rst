--------------

STRINGLIST(3) BSD Library Functions Manual STRINGLIST(3)

**NAME**

**stringlist**, **sl_init**, **sl_add**, **sl_free**, **sl_find** —
stringlist manipulation functions

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <stringlist.h>**

*StringList \**

**sl_init**\ ();

*int*

**sl_add**\ (*StringList *sl*, *char *item*);

*void*

**sl_free**\ (*StringList *sl*, *int freeall*);

*char \**

**sl_find**\ (*StringList *sl*, *const char *item*);

**DESCRIPTION**

The **stringlist** functions manipulate stringlists, which are lists of
strings that extend automatically if necessary.

The *StringList* structure has the following definition:

typedef struct \_stringlist {

+-----------------+-----------------+-----------------+-----------------+
|                 | char            | \**sl_str;      |                 |
+-----------------+-----------------+-----------------+-----------------+
|                 | size_t          | sl_max;         |                 |
+-----------------+-----------------+-----------------+-----------------+
|                 | size_t          | sl_cur;         |                 |
+-----------------+-----------------+-----------------+-----------------+

} StringList;

*sl_str*

a pointer to the base of the array containing the list.

*sl_max*

the size of *sl_str*.

*sl_cur*

the offset in *sl_str* of the current element.

The following stringlist manipulation functions are available:

**sl_init**\ ()

Create a stringlist. Returns a pointer to a *StringList*, or NULL in
case of failure.

**sl_free**\ ()

Releases memory occupied by *sl* and the *sl->sl_str* array. If
*freeall* is non-zero, then each of the items within *sl->sl_str* is
released as well.

**sl_add**\ ()

Add *item* to *sl->sl_str* at *sl->sl_cur*, extending the size of
*sl->sl_str*. Returns zero upon success, −1 upon failure.

**sl_find**\ ()

Find *item* in *sl*, returning NULL if it is not found.

**SEE ALSO**

free(3), malloc(3)

**HISTORY**

The **stringlist** functions appeared in FreeBSD 2.2.6 and NetBSD 1.3.

BSD November 28, 1999 BSD

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

