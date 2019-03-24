--------------

CATCLOSE(3) BSD Library Functions Manual CATCLOSE(3)

**NAME**

**catclose** — close message catalog

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <nl_types.h>**

*int*

**catclose**\ (*nl_catd catd*);

**DESCRIPTION**

The **catclose**\ () function closes the message catalog specified by
the argument *catd*.

**RETURN VALUES**

The **catclose**\ () function returns the value 0 if successful;
otherwise the value −1 is returned and the global variable *errno* is
set to indicate the error.

| **ERRORS**
| [EBADF]

An invalid message catalog descriptor was passed by the *catd* argument.

**SEE ALSO**

gencat(1), catgets(3), catopen(3)

**STANDARDS**

The **catclose**\ () function conforms to IEEE Std 1003.1-2001
(‘‘POSIX.1’’).

BSD February 12, 2005 BSD

--------------
