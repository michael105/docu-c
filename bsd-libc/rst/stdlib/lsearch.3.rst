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
