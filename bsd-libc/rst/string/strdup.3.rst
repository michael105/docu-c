--------------

STRDUP(3) BSD Library Functions Manual STRDUP(3)

**NAME**

**strdup**, **strndup** — save a copy of a string

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <string.h>**

*char \**

**strdup**\ (*const char *str*);

*char \**

**strndup**\ (*const char *str*, *size_t len*);

**DESCRIPTION**

The **strdup**\ () function allocates sufficient memory for a copy of
the string *str*, does the copy, and returns a pointer to it. The
pointer may subsequently be used as an argument to the function free(3).

If insufficient memory is available, NULL is returned and *errno* is set
to ENOMEM.

The **strndup**\ () function copies at most *len* characters from the
string *str* always NUL terminating the copied string.

**SEE ALSO**

free(3), malloc(3), wcsdup(3)

**STANDARDS**

The **strdup**\ () function is specified by IEEE Std 1003.1-2001
(‘‘POSIX.1’’). The **strndup**\ () function is specified by IEEE Std
1003.1-2008 (‘‘POSIX.1’’).

**HISTORY**

The **strdup**\ () function first appeared in 4.4BSD. The
**strndup**\ () function was added in FreeBSD 7.2.

BSD June 6, 2018 BSD

--------------
