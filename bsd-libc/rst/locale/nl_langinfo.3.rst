--------------

NL_LANGINFO(3) BSD Library Functions Manual NL_LANGINFO(3)

**NAME**

**nl_langinfo** — language information

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <langinfo.h>**

*char \**

**nl_langinfo**\ (*nl_item item*);

*char \**

**nl_langinfo_l**\ (*nl_item item*, *locale_t loc*);

**DESCRIPTION**

The **nl_langinfo**\ () function returns a pointer to a string
containing information relevant to the particular language or cultural
area defined in the program or thread’s locale, or in the case of
**nl_langinfo_l**\ (), the locale passed as the second argument. The
manifest constant names and values of *item* are defined in
<*langinfo.h*>.

Calls to **setlocale**\ () with a category corresponding to the category
of *item*, or to the category LC_ALL, may overwrite the buffer pointed
to by the return value.

**RETURN VALUES**

In a locale where langinfo data is not defined, **nl_langinfo**\ ()
returns a pointer to the corresponding string in the POSIX locale.
**nl_langinfo_l**\ () returns the same values as **nl_langinfo**\ (). In
all locales, **nl_langinfo**\ () returns a pointer to an empty string if
*item* contains an invalid setting.

**EXAMPLES**

For example:

nl_langinfo(ABDAY_1)

would return a pointer to the string "Dom" if the identified language
was Portuguese, and "Sun" if the identified language was English.

**SEE ALSO**

setlocale(3)

**STANDARDS**

The **nl_langinfo**\ () function conforms to Version 2 of the Single
UNIX Specification (‘‘SUSv2’’). The **nl_langinfo_l**\ () function
conforms to IEEE Std 1003.1-2008 (‘‘POSIX.1’’).

**HISTORY**

The **nl_langinfo**\ () function first appeared in FreeBSD 4.6.

BSD July 30, 2012 BSD

--------------
