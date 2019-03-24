--------------

ACL_SET_TAG_TYPE(3) BSD Library Functions Manual ACL_SET_TAG_TYPE(3)

**NAME**

**acl_set_tag_type** — set the tag type of an ACL entry

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/types.h>
#include <sys/acl.h>**

*int*

**acl_set_tag_type**\ (*acl_entry_t entry_d*, *acl_tag_t tag_type*);

**DESCRIPTION**

The **acl_set_tag_type**\ () function is a POSIX.1e call that sets the
ACL tag type of ACL entry *entry_d* to the value of *tag_type*.

Valid values are:

+-----------------------+-----------------------+-----------------------+
|                       | ACL_USER_OBJ          | Permissions apply to  |
|                       |                       | file owner            |
+-----------------------+-----------------------+-----------------------+
|                       | ACL_USER              | Permissions apply to  |
|                       |                       | additional user       |
|                       |                       | specified by          |
|                       |                       | qualifier             |
+-----------------------+-----------------------+-----------------------+
|                       | ACL_GROUP_OBJ         | Permissions apply to  |
|                       |                       | file group            |
+-----------------------+-----------------------+-----------------------+
|                       | ACL_GROUP             | Permissions apply to  |
|                       |                       | additional group      |
|                       |                       | specified by          |
|                       |                       | qualifier             |
+-----------------------+-----------------------+-----------------------+
|                       | ACL_MASK              | Permissions specify   |
|                       |                       | mask                  |
+-----------------------+-----------------------+-----------------------+
|                       | ACL_OTHER             | Permissions apply to  |
|                       |                       | other                 |
+-----------------------+-----------------------+-----------------------+
|                       | ACL_OTHER_OBJ         | Same as ACL_OTHER     |
+-----------------------+-----------------------+-----------------------+
|                       | ACL_EVERYONE          | Permissions apply to  |
|                       |                       | everyone@             |
+-----------------------+-----------------------+-----------------------+

Calling **acl_set_tag_type**\ () with *tag_type* equal to ACL_MASK,
ACL_OTHER or ACL_OTHER_OBJ brands the ACL as POSIX.1e. Calling it with
ACL_EVERYONE brands the ACL as NFSv4.

**RETURN VALUES**

The **acl_set_tag_type**\ () function returns the value 0 if successful;
otherwise the value −1 is returned and the global variable *errno* is
set to indicate the error.

**ERRORS**

The **acl_set_tag_type**\ () function fails if:

[EINVAL]

Argument *entry_d* is not a valid descriptor for an ACL entry. Argument
*tag_type* is not a valid ACL tag type. ACL is already branded
differently.

**SEE ALSO**

acl(3), acl_get_brand_np(3), acl_get_tag_type(3), posix1e(3)

**STANDARDS**

POSIX.1e is described in IEEE POSIX.1e draft 17.

**HISTORY**

POSIX.1e support was introduced in FreeBSD 4.0. The
**acl_set_tag_type**\ () function was added in FreeBSD 5.0.

**AUTHORS**

The **acl_set_tag_type**\ () function was written by Chris D. Faulhaber
<*jedgar@fxp.org*>.

BSD June 25, 2009 BSD

--------------
