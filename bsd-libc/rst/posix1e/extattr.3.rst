--------------

EXTATTR(3) BSD Library Functions Manual EXTATTR(3)

**NAME**

**extattr_namespace_to_string**, **extattr_string_to_namespace** —
convert an extended attribute namespace identifier to a string and vice
versa

**LIBRARY**

System Utilities Library (libutil, −lutil)

**SYNOPSIS**

**#include <sys/extattr.h>
#include <libutil.h>**

*int*

**extattr_namespace_to_string**\ (*int attrnamespace*, *char **string*);

*int*

**extattr_string_to_namespace**\ (*const char *string*,
*int *attrnamespace*);

**DESCRIPTION**

The **extattr_namespace_to_string**\ () function converts a VFS extended
attribute identifier to a human-readable string; the
**extattr_string_to_namespace**\ () function undoes the aforementioned
operation, and converts a human-readable string representing a namespace
to a namespace identifier. Although a file system may implement
arbitrary namespaces, these functions only support the
EXTATTR_NAMESPACE_USER (‘‘user’’) and EXTATTR_NAMESPACE_SYSTEM
(‘‘system’’) namespaces, which are defined in extattr(9).

These functions are meant to be used in error reporting and other
interactive tasks. For example, instead of printing the integer
identifying an extended attribute in an error message, a program might
use **extattr_namespace_to_string**\ () to obtain a human-readable
representation. Likewise, instead of requiring a user to enter the
integer representing a namespace, an interactive program might ask for a
name and use **extattr_string_to_namespace**\ () to get the desired
identifier.

**RETURN VALUES**

If any of the calls are unsuccessful, the value −1 is returned and the
global variable *errno* is set to indicate the error.

| **ERRORS**
| [EINVAL]

The requested namespace could not be identified.

**SEE ALSO**

extattr(2), getextattr(8), setextattr(8), extattr(9)

**HISTORY**

Extended attribute support was developed as part of the TrustedBSD
Project, and introduced in FreeBSD 5.0. It was developed to support
security extensions requiring additional labels to be associated with
each file or directory.

BSD June 24, 2001 BSD

--------------
