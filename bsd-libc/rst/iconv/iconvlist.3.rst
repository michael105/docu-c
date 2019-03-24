--------------

ICONVLIST(3) BSD Library Functions Manual ICONVLIST(3)

**NAME**

**iconvlist** — retrieving a list of character encodings supported by
iconv(3)

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <iconv.h>**

*void*

**iconvlist**\ (*int *\ (*\*do_one*)(\ *unsigned int *count, const char * const *names, void *arg*),
*void *arg*);

**DESCRIPTION**

The **iconvlist**\ () function obtains a list of character encodings
that are supported by the iconv(3) call. The **do_one**\ () callback
function will be called, where the *count* argument will be set to the
number of the encoding names found, the *names* argument will be the
list of the supported encoding names and the *arg* argument will be the
*arg* argument of the **iconvlist**\ () function. This argument can be
used to interchange custom data between the caller of **iconvlist**\ ()
and the callback function.

If an error occurs, *names* will be NULL when calling **do_one**\ ().

**SEE ALSO**

\__iconv_free_list(3), \__iconv_get_list(3), iconv(3)

**STANDARDS**

The **iconvlist** function is a non-standard extension, which appeared
in the GNU implementation and was adopted in FreeBSD 9.0 for
compatibility’s sake.

**AUTHORS**

This manual page was written by Gabor Kovesdan <*gabor@FreeBSD.org*>.

BSD October 20, 2009 BSD

--------------
