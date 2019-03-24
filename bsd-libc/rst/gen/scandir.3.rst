--------------

SCANDIR(3) BSD Library Functions Manual SCANDIR(3)

**NAME**

**scandir**, **alphasort** — scan a directory

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <dirent.h>**

*int*

**scandir**\ (*const char *dirname*, *struct dirent ***namelist*,
*int *\ (*\*select*)(\ *const struct dirent \**),
*int *\ (*\*compar*)(\ *const struct dirent **, const struct dirent *\**));

*int*

**scandir_b**\ (*const char *dirname*, *struct dirent ***namelist*,
*int *\ (*\*select(rp*\ (*const struct dirent \**),
*int *\ (*^compar*)(\ *const struct dirent **, const struct dirent *\**));

*int*

**alphasort**\ (*const struct dirent **d1*, *const struct dirent **d2*);

**DESCRIPTION**

The **scandir**\ () function reads the directory *dirname* and builds an
array of pointers to directory entries using malloc(3). It returns the
number of entries in the array. A pointer to the array of directory
entries is stored in the location referenced by *namelist*.

The *select* argument is a pointer to a user supplied subroutine which
is called by **scandir**\ () to select which entries are to be included
in the array. The select routine is passed a pointer to a directory
entry and should return a non-zero value if the directory entry is to be
included in the array. If *select* is null, then all the directory
entries will be included.

The *compar* argument is a pointer to a user supplied subroutine which
is passed to qsort(3) to sort the completed array. If this pointer is
null, the array is not sorted.

The **alphasort**\ () function is a routine which can be used for the
*compar* argument to sort the array alphabetically using strcoll(3).

The memory allocated for the array can be deallocated with free(3), by
freeing each pointer in the array and then the array itself.

The **scandir_b**\ () function behaves in the same way as
**scandir**\ (), but takes blocks as arguments instead of function
pointers and calls **qsort_b**\ () rather than **qsort**\ ().

**DIAGNOSTICS**

Returns −1 if the directory cannot be opened for reading or if malloc(3)
cannot allocate enough memory to hold all the data structures.

**SEE ALSO**

directory(3), malloc(3), qsort(3), strcoll(3), dir(5)

**HISTORY**

The **scandir**\ () and **alphasort**\ () functions appeared in 4.2BSD.

BSD January 3, 2010 BSD

--------------
