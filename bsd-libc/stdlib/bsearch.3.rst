--------------

BSEARCH(3) BSD Library Functions Manual BSEARCH(3)

**NAME**

**bsearch** — binary search of a sorted table

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <stdlib.h>**

*void \**

**bsearch**\ (*const void *key*, *const void *base*, *size_t nmemb*,
*size_t size*, *int (*compar) (const void *, const void *)*);

**DESCRIPTION**

The **bsearch**\ () function searches an array of *nmemb* objects, the
initial member of which is pointed to by *base*, for a member that
matches the object pointed to by *key*. The size of each member of the
array is specified by *size*.

The contents of the array should be in ascending sorted order according
to the comparison function referenced by *compar*. The *compar* routine
is expected to have two arguments which point to the *key* object and to
an array member, in that order, and should return an integer less than,
equal to, or greater than zero if the *key* object is found,
respectively, to be less than, to match, or be greater than the array
member. See the *int_compare* sample function in qsort(3) for a
comparison function that is also compatible with **bsearch**\ ().

**RETURN VALUES**

The **bsearch**\ () function returns a pointer to a matching member of
the array, or a null pointer if no match is found. If two members
compare as equal, which member is matched is unspecified.

**SEE ALSO**

db(3), lsearch(3), qsort(3)

**STANDARDS**

The **bsearch**\ () function conforms to ISO/IEC 9899:1990
(‘‘ISO C90’’).

BSD February 22, 2013 BSD

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

