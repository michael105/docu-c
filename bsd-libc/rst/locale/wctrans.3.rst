--------------

WCTRANS(3) BSD Library Functions Manual WCTRANS(3)

**NAME**

**towctrans**, **wctrans** — wide character mapping functions

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <wctype.h>**

*wint_t*

**towctrans**\ (*wint_t wc*, *wctrans_t desc*);

*wctrans_t*

**wctrans**\ (*const char *charclass*);

**DESCRIPTION**

The **wctrans**\ () function returns a value of type *wctrans_t* which
represents the requested wide character mapping operation and may be
used as the second argument for calls to **towctrans**\ ().

The following character mapping names are recognised:

+-----------------+-----------------+-----------------+-----------------+
|                 | tolower         | toupper         |                 |
+-----------------+-----------------+-----------------+-----------------+

The **towctrans**\ () function transliterates the wide character *wc*
according to the mapping described by *desc*.

**RETURN VALUES**

The **towctrans**\ () function returns the transliterated character if
successful, otherwise it returns the character unchanged and sets
*errno*.

The **wctrans**\ () function returns non-zero if successful, otherwise
it returns zero and sets *errno*.

**EXAMPLES**

Reimplement **towupper**\ () in terms of **towctrans**\ () and
**wctrans**\ ():

| wint_t
| mytowupper(wint_t wc)
| {

+-----------------------+-----------------------+-----------------------+
|                       | return (towctrans(wc, |                       |
|                       | wctrans("toupper"))); |                       |
+-----------------------+-----------------------+-----------------------+

}

**ERRORS**

The **towctrans**\ () function will fail if:

[EINVAL]

The supplied *desc* argument is invalid.

The **wctrans**\ () function will fail if:

[EINVAL]

The requested mapping name is invalid.

**SEE ALSO**

tolower(3), toupper(3), wctype(3)

**STANDARDS**

The **towctrans**\ () and **wctrans**\ () functions conform to IEEE Std
1003.1-2001 (‘‘POSIX.1’’).

**HISTORY**

The **towctrans**\ () and **wctrans**\ () functions first appeared in
FreeBSD 5.0.

BSD October 3, 2002 BSD

--------------
