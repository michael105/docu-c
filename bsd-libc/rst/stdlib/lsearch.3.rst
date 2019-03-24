--------------

LSEARCH(3) BSD Library Functions Manual LSEARCH(3)

**NAME**

**lsearch**, **lfind** — linear search and append

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <search.h>**

*void \**

**lsearch**\ (*const void *key*, *void *base*, *size_t *nelp*,
*size_t width*, *int *\ (*\*compar*)(\ *const void *, const void \**));

*void \**

**lfind**\ (*const void *key*, *const void *base*, *size_t *nelp*,
*size_t width*, *int *\ (*\*compar*)(\ *const void *, const void \**));

**DESCRIPTION**

The **lsearch**\ () and **lfind**\ () functions walk linearly through an
array and compare each element with the one to be sought using a
supplied comparison function.

The *key* argument points to an element that matches the one that is
searched. The array’s address in memory is denoted by the *base*
argument. The width of one element (i.e., the size as returned by
**sizeof**\ ()) is passed as the *width* argument. The number of valid
elements contained in the array (not the number of elements the array
has space reserved for) is given in the integer pointed to by *nelp*.
The *compar* argument points to a function which compares its two
arguments and returns zero if they are matching, and non-zero otherwise.

If no matching element was found in the array, **lsearch**\ () copies
*key* into the position after the last element and increments the
integer pointed to by *nelp*.

**RETURN VALUES**

The **lsearch**\ () and **lfind**\ () functions return a pointer to the
first element found. If no element was found, **lsearch**\ () returns a
pointer to the newly added element, whereas **lfind**\ () returns NULL.
Both functions return NULL if an error occurs.

**EXAMPLES**

| #include <search.h>
| #include <stdio.h>
| #include <stdlib.h>

| static int
| element_compare(const void \*p1, const void \*p2)
| {

+-----------------------+-----------------------+-----------------------+
|                       | int left = \*(const   |                       |
|                       | int \*)p1;            |                       |
+-----------------------+-----------------------+-----------------------+
|                       | int right = \*(const  |                       |
|                       | int \*)p2;            |                       |
+-----------------------+-----------------------+-----------------------+
|                       | return (left -        |                       |
|                       | right);               |                       |
+-----------------------+-----------------------+-----------------------+

}

| int
| main(int argc, char \**argv)
| {

+-----------------+-----------------+-----------------+-----------------+
|                 | const int       |                 |                 |
|                 | array[10] = {1, |                 |                 |
|                 | 2, 3, 4, 5, 6,  |                 |                 |
|                 | 7, 8, 9, 10};   |                 |                 |
+-----------------+-----------------+-----------------+-----------------+
|                 | size_t          |                 |                 |
|                 | element_size =  |                 |                 |
|                 | sizeof(array[0] |                 |                 |
|                 | );              |                 |                 |
+-----------------+-----------------+-----------------+-----------------+
|                 | size_t          |                 |                 |
|                 | array_size =    |                 |                 |
|                 | sizeof(array) / |                 |                 |
|                 | element_size;   |                 |                 |
+-----------------+-----------------+-----------------+-----------------+
|                 | int key;        |                 |                 |
+-----------------+-----------------+-----------------+-----------------+
|                 | void \*element; |                 |                 |
+-----------------+-----------------+-----------------+-----------------+
|                 | printf("Enter a |                 |                 |
|                 | number: ");     |                 |                 |
+-----------------+-----------------+-----------------+-----------------+
|                 | if (scanf("%d", |                 |                 |
|                 | &key) != 1) {   |                 |                 |
+-----------------+-----------------+-----------------+-----------------+
|                 |                 | printf("Bad     |                 |
|                 |                 | input\n");      |                 |
+-----------------+-----------------+-----------------+-----------------+
|                 |                 | return          |                 |
|                 |                 | (EXIT_FAILURE); |                 |
+-----------------+-----------------+-----------------+-----------------+
|                 | }               |                 |                 |
+-----------------+-----------------+-----------------+-----------------+
|                 | element =       |                 |                 |
|                 | lfind(&key,     |                 |                 |
|                 | array,          |                 |                 |
|                 | &array_size,    |                 |                 |
|                 | element_size,   |                 |                 |
+-----------------+-----------------+-----------------+-----------------+
|                 | element_compare |                 |                 |
|                 | );              |                 |                 |
+-----------------+-----------------+-----------------+-----------------+
|                 | if (element !=  |                 |                 |
|                 | NULL)           |                 |                 |
+-----------------+-----------------+-----------------+-----------------+
|                 |                 | printf("Element |                 |
|                 |                 | found: %d\n",   |                 |
|                 |                 | \*(int          |                 |
|                 |                 | \*)element);    |                 |
+-----------------+-----------------+-----------------+-----------------+
|                 | else            |                 |                 |
+-----------------+-----------------+-----------------+-----------------+
|                 |                 | printf("Element |                 |
|                 |                 | not found\n");  |                 |
+-----------------+-----------------+-----------------+-----------------+
|                 | return          |                 |                 |
|                 | (EXIT_SUCCESS); |                 |                 |
+-----------------+-----------------+-----------------+-----------------+

}

**SEE ALSO**

bsearch(3), hsearch(3), tsearch(3)

**STANDARDS**

The **lsearch**\ () and **lfind**\ () functions conform to IEEE Std
1003.1-2001 (‘‘POSIX.1’’).

**HISTORY**

The **lsearch**\ () and **lfind**\ () functions appeared in 4.2BSD. In
FreeBSD 5.0, they reappeared conforming to IEEE Std 1003.1-2001
(‘‘POSIX.1’’).

BSD April 17, 2016 BSD

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

