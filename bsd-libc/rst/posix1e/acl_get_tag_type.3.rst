--------------

ACL_GET_TAG_TYPE(3) BSD Library Functions Manual ACL_GET_TAG_TYPE(3)

**NAME**

**acl_get_tag_type** — retrieve the tag type from an ACL entry

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/types.h>
#include <sys/acl.h>**

*int*

**acl_get_tag_type**\ (*acl_entry_t entry_d*, *acl_tag_t *tag_type_p*);

**DESCRIPTION**

The **acl_get_tag_type**\ () function is a POSIX.1e call that returns
the tag type for the ACL entry *entry_d*. Upon successful completion,
the location referred to by the argument *tag_type_p* will be set to the
tag type of the ACL entry *entry_d*.

**RETURN VALUES**

The **acl_get_tag_type**\ () function returns the value 0 if successful;
otherwise the value −1 is returned and the global variable *errno* is
set to indicate the error.

**ERRORS**

The **acl_get_tag_type**\ () function fails if:

[EINVAL]

Argument *entry_d* is not a valid descriptor for an ACL entry;

**SEE ALSO**

acl(3), acl_create_entry(3), acl_get_entry(3), acl_get_qualifier(3),
acl_init(3), acl_set_qualifier(3), acl_set_tag_type(3), posix1e(3)

**STANDARDS**

POSIX.1e is described in IEEE POSIX.1e draft 17.

**HISTORY**

POSIX.1e support was introduced in FreeBSD 4.0. The
**acl_get_tag_type**\ () function was added in FreeBSD 5.0.

**AUTHORS**

The **acl_get_tag_type**\ () function was written by Chris D. Faulhaber
<*jedgar@fxp.org*>.

BSD March 10, 2001 BSD

--------------
