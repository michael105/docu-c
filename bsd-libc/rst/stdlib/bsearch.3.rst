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
