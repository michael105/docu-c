--------------

CTERMID(3) BSD Library Functions Manual CTERMID(3)

**NAME**

**ctermid** — generate terminal pathname

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <stdio.h>**

*char \**

**ctermid**\ (*char *buf*);

*char \**

**ctermid_r**\ (*char *buf*);

**DESCRIPTION**

The **ctermid**\ () function generates a string, that, when used as a
pathname, refers to the current controlling terminal of the calling
process.

If *buf* is the NULL pointer, a pointer to a static area is returned.
Otherwise, the pathname is copied into the memory referenced by *buf*.
The argument *buf* is assumed to be at least L_ctermid (as defined in
the include file <*stdio.h*>) bytes long.

The **ctermid_r**\ () function provides the same functionality as
**ctermid**\ () except that if *buf* is a NULL pointer, NULL is
returned.

If no suitable lookup of the controlling terminal name can be performed,
this implementation returns ‘/dev/tty’.

**RETURN VALUES**

Upon successful completion, a non-NULL pointer is returned. Otherwise, a
NULL pointer is returned and the global variable *errno* is set to
indicate the error.

**ERRORS**

The current implementation detects no error conditions.

**SEE ALSO**

ttyname(3)

**STANDARDS**

The **ctermid**\ () function conforms to IEEE Std 1003.1-1988
(‘‘POSIX.1’’).

**BUGS**

By default the **ctermid**\ () function writes all information to an
internal static object. Subsequent calls to **ctermid**\ () will modify
the same object.

BSD October 1, 2011 BSD

--------------
