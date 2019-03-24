--------------

REMOVE(3) BSD Library Functions Manual REMOVE(3)

**NAME**

**remove** — remove directory entry

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <stdio.h>**

*int*

**remove**\ (*const char *path*);

**DESCRIPTION**

The **remove**\ () function removes the file or directory specified by
*path*.

If *path* specifies a directory, **remove**\ (*path*) is the equivalent
of **rmdir**\ (*path*). Otherwise, it is the equivalent of
**unlink**\ (*path*).

**RETURN VALUES**

The **remove**\ () function returns the value 0 if successful; otherwise
the value −1 is returned and the global variable *errno* is set to
indicate the error.

**ERRORS**

The **remove**\ () function may fail and set *errno* for any of the
errors specified for the routines lstat(2), rmdir(2) or unlink(2).

**SEE ALSO**

rmdir(2), unlink(2)

**STANDARDS**

The **remove**\ () function conforms to ISO/IEC 9899:1990 (‘‘ISO C90’’)
and X/Open Portability Guide Issue 4, Version 2 (‘‘XPG4.2’’).

BSD June 4, 1993 BSD

--------------
