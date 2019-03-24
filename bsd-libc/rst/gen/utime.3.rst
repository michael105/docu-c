--------------

UTIME(3) BSD Library Functions Manual UTIME(3)

**NAME**

**utime** — set file times

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <utime.h>**

*int*

**utime**\ (*const char *file*, *const struct utimbuf *timep*);

**DESCRIPTION**

**This interface is obsoleted by** utimensat(\ **2**) **because it is
not accurate to fractions of a second.**

The **utime**\ () function sets the access and modification times of the
named file from the *actime* and *modtime* fields of the *struct
utimbuf* pointed at by *timep*.

If the times are specified (the *timep* argument is non-NULL) the caller
must be the owner of the file or be the super-user.

If the times are not specified (the *timep* argument is NULL) the caller
must be the owner of the file, have permission to write the file, or be
the super-user.

**ERRORS**

The **utime**\ () function may fail and set *errno* for any of the
errors specified for the library function utimes(2).

**SEE ALSO**

stat(2), utimensat(2), utimes(2)

**STANDARDS**

The **utime**\ () function conforms to IEEE Std 1003.1-1988
(‘‘POSIX.1’’).

**HISTORY**

A **utime**\ () function appeared in Version 7 AT&T UNIX.

BSD June 9, 2016 BSD

--------------
