--------------

ICONV_CANONICALIZE(3) BSD Library Functions Manual ICONV_CANONICALIZE(3)

**NAME**

**iconv_canonicalize** — resolving character encoding names to canonical
form

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <iconv.h>**

*const char \**

**iconv_canonicalize**\ (*const char *name*);

**DESCRIPTION**

The **iconv_canonicalize**\ () function resolves the character encoding
name specified by the *name* argument to its canonical form.

**RETURN VALUES**

Upon successful completion **iconv_canonicalize**\ (), returns the
canonical name of the given encoding. If the specified name is already a
canonical name, the same value is returned. If the specified name is not
an existing character encoding name, NULL is returned.

**SEE ALSO**

iconv(3)

**STANDARDS**

The **iconv_canonicalize** function is a non-standard extension, which
appeared in the GNU implementation and was adopted in FreeBSD 9.0 for
compatibility’s sake.

**AUTHORS**

This manual page was written by Gabor Kovesdan <*gabor@FreeBSD.org*>.

BSD October 20, 2009 BSD

--------------
