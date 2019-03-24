--------------

ACL_SET_QUALIFIER(3) BSD Library Functions Manual ACL_SET_QUALIFIER(3)

**NAME**

**acl_set_qualifier** — set ACL tag qualifier

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/types.h>
#include <sys/acl.h>**

*int*

**acl_set_qualifier**\ (*acl_entry_t entry_d*,
*const void *tag_qualifier_p*);

**DESCRIPTION**

The **acl_set_qualifier**\ () function is a POSIX.1e call that sets the
qualifier of the tag for the ACL entry *entry_d* to the value referred
to by *tag_qualifier_p*.

**RETURN VALUES**

The **acl_set_qualifier**\ () function returns the value 0 if
successful; otherwise the value −1 is returned and the global variable
*errno* is set to indicate the error.

**ERRORS**

The **acl_set_qualifier**\ () function fails if:

[EINVAL]

Argument *entry_d* is not a valid descriptor for an ACL entry. The tag
type of the ACL entry *entry_d* is not ACL_USER or ACL_GROUP. The value
pointed to by *tag_qualifier_p* is not valid.

[ENOMEM]

The value to be returned requires more memory than is allowed by the
hardware or system-imposed memory management constraints.

**SEE ALSO**

acl(3), acl_get_qualifier(3), posix1e(3)

**STANDARDS**

POSIX.1e is described in IEEE POSIX.1e draft 17.

**HISTORY**

POSIX.1e support was introduced in FreeBSD 4.0. The
**acl_get_qualifier**\ () function was added in FreeBSD 5.0.

**AUTHORS**

The **acl_get_qualifier**\ () function was written by Chris D. Faulhaber
<*jedgar@fxp.org*>.

BSD March 10, 2001 BSD

--------------
