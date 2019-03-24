--------------

ACL_GET_QUALIFIER(3) BSD Library Functions Manual ACL_GET_QUALIFIER(3)

**NAME**

**acl_get_qualifier** — retrieve the qualifier from an ACL entry

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/types.h>
#include <sys/acl.h>**

*void \**

**acl_get_qualifier**\ (*acl_entry_t entry_d*);

**DESCRIPTION**

The **acl_get_qualifier**\ () function is a POSIX.1e call that retrieves
the qualifier of the tag for the ACL entry indicated by the argument
*entry_d* into working storage and returns a pointer to that storage.

If the value of the tag type in the ACL entry referred to by *entry_d*
is ACL_USER, then the value returned by **acl_get_qualifier**\ () will
be a pointer to type *uid_t*.

If the value of the tag type in the ACL entry referred to by *entry_d*
is ACL_GROUP, then the value returned by **acl_get_qualifier**\ () will
be a pointer to type *gid_t*.

If the value of the tag type in the ACL entry referred to by *entry_d*
is ACL_UNDEFINED_TAG, ACL_USER_OBJ, ACL_GROUP_OBJ, ACL_OTHER, ACL_MASK,
or an implementation-defined value for which a qualifier is not
supported, then **acl_get_qualifier**\ () will return a value of (*void
\**)NULL and the function will fail.

This function may cause memory to be allocated. The caller should free
any releasable memory, when the new qualifier is no longer required, by
calling **acl_free**\ () with *void \** as the argument.

**RETURN VALUES**

The **acl_get_qualifier**\ () function returns a pointer to the
allocated storage if successful; otherwise a NULL pointer is returned
and the global variable *errno* is set to indicate the error.

**ERRORS**

The **acl_get_qualifier**\ () fails if:

[EINVAL]

Argument *entry_d* does not point to a valid descriptor for an ACL
entry. The value of the tag type in the ACL entry referenced by argument
*entry_d* is not ACL_USER or ACL_GROUP.

[ENOMEM]

The value to be returned requires more memory than is allowed by the
hardware or system-imposed memory management constraints.

**SEE ALSO**

acl(3), acl_create_entry(3), acl_free(3), acl_get_entry(3),
acl_get_tag_type(3), acl_set_qualifier(3), acl_set_tag_type(3),
posix1e(3)

**STANDARDS**

POSIX.1e is described in IEEE POSIX.1e draft 17.

**HISTORY**

POSIX.1e support was introduced in FreeBSD 4.0. The
**acl_get_qualifier**\ () function was added in FreeBSD 5.0.

**AUTHORS**

The **acl_get_qualifier**\ () function was written by Chris D. Faulhaber
<*jedgar@fxp.org*>.

BSD March 13, 2001 BSD

--------------
