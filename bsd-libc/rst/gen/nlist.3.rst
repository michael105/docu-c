--------------

NLIST(3) BSD Library Functions Manual NLIST(3)

**NAME**

**nlist** — retrieve symbol table name list from an executable file

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <nlist.h>**

*int*

**nlist**\ (*const char *filename*, *struct nlist *nl*);

**DESCRIPTION**

The **nlist**\ () function retrieves name list entries from the symbol
table of an executable file (see a.out(5)). The argument *nl* is set to
reference the beginning of the list. The list is preened of binary and
invalid data; if an entry in the name list is valid, the *n_type* and
*n_value* for the entry are copied into the list referenced by *nl*. No
other data is copied. The last entry in the list is always NULL.

**RETURN VALUES**

The number of invalid entries is returned if successful; otherwise, if
the file *filename* does not exist or is not executable, the returned
value is −1.

**SEE ALSO**

a.out(5)

**HISTORY**

A **nlist**\ () function appeared in Version 6 AT&T UNIX.

BSD April 19, 1994 BSD

--------------
