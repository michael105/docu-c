--------------

RADIXSORT(3) BSD Library Functions Manual RADIXSORT(3)

**NAME**

**radixsort**, **sradixsort** — radix sort

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <limits.h>
#include <stdlib.h>**

*int*

**radixsort**\ (*const unsigned char **base*, *int nmemb*,
*const unsigned char *table*, *unsigned endbyte*);

*int*

**sradixsort**\ (*const unsigned char **base*, *int nmemb*,
*const unsigned char *table*, *unsigned endbyte*);

**DESCRIPTION**

The **radixsort**\ () and **sradixsort**\ () functions are
implementations of radix sort.

These functions sort an array of pointers to byte strings, the initial
member of which is referenced by *base*. The byte strings may contain
any values; the end of each string is denoted by the user-specified
value *endbyte*.

Applications may specify a sort order by providing the *table* argument.
If non-NULL, *table* must reference an array of UCHAR_MAX + 1 bytes
which contains the sort weight of each possible byte value. The
end-of-string byte must have a sort weight of 0 or 255 (for sorting in
reverse order). More than one byte may have the same sort weight. The
*table* argument is useful for applications which wish to sort different
characters equally, for example, providing a table with the same weights
for A-Z as for a-z will result in a case-insensitive sort. If *table* is
NULL, the contents of the array are sorted in ascending order according
to the ASCII order of the byte strings they reference and *endbyte* has
a sorting weight of 0.

The **sradixsort**\ () function is stable, that is, if two elements
compare as equal, their order in the sorted array is unchanged. The
**sradixsort**\ () function uses additional memory sufficient to hold
*nmemb* pointers.

The **radixsort**\ () function is not stable, but uses no additional
memory.

These functions are variants of most-significant-byte radix sorting; in
particular, see D.E. Knuth’s *Algorithm R* and section 5.2.5, exercise
10. They take linear time relative to the number of bytes in the
strings.

**RETURN VALUES**

The **radixsort**\ () function returns the value 0 if successful;
otherwise the value −1 is returned and the global variable *errno* is
set to indicate the error.

| **ERRORS**
| [EINVAL]

The value of the *endbyte* element of *table* is not 0 or 255.

Additionally, the **sradixsort**\ () function may fail and set *errno*
for any of the errors specified for the library routine malloc(3).

**SEE ALSO**

sort(1), qsort(3)

Knuth, D.E.

, "

| Sorting and Searching ", *
  The Art of Computer Programming* ,
| Vol. 3 ,
| pp. 170-178 ,
| 1968 .

Paige, R.

, "

| Three Partition Refinement Algorithms ", *
  SIAM J. Comput.* ,
| No. 6 ,
| Vol. 16 ,
| 1987 .

McIlroy, P.

, "

| Computing Systems ", *
  Engineering Radix Sort* ,
| Vol. 6:1 ,
| pp. 5-27 ,
| 1993 .

**HISTORY**

The **radixsort**\ () function first appeared in 4.4BSD.

BSD January 27, 1994 BSD

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

