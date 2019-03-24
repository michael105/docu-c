--------------

\__ICONV_GET_LIST(3) BSD Library Functions Manual \__ICONV_GET_LIST(3)

**NAME**

**\__iconv_get_list**, **\__iconv_free_list** — retrieving a list of
character encodings supported by iconv(3)

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <iconv.h>**

*int*

**\__iconv_get_list**\ (*char ***names*, *size_t count*, *bool paired*);

*void*

**\__iconv_free_list**\ (*char **names*, *size_t count*);

**DESCRIPTION**

The **\__iconv_get_list**\ () function obtains a list of character
encodings that are supported by the iconv(3) call. The list of the
encoding names will be stored in *names* and the number of the entries
is stored in *count*. If the *paired* variable is true, the list will be
arranged into canonical/alias name pairs.

The **\__iconv_free_list**\ () function is to free the allocated memory
during the call of **\__iconv_get_list**\ ().

**RETURN VALUES**

Upon successful completion **\__iconv_get_list**\ () returns 0 and set
the *names* and *count* arguments. Otherwise, −1 is returned and errno
is set to indicate the error.

**SEE ALSO**

iconv(3), iconvlist(3)

**STANDARDS**

The **\__iconv_get_list** and **\__iconv_free_list** functions are
non-standard interfaces, which appeared in the implementation of the
Citrus Project. The iconv implementation of the Citrus Project was
adopted in FreeBSD 9.0.

**AUTHORS**

This manual page was written by Gabor Kovesdan <*gabor@FreeBSD.org*>.

BSD October 20, 2009 BSD

--------------
