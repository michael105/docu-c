--------------

ACL_ADD_PERM(3) BSD Library Functions Manual ACL_ADD_PERM(3)

**NAME**

**acl_add_perm** — add permissions to a permission set

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/types.h>
#include <sys/acl.h>**

*int*

**acl_add_perm**\ (*acl_permset_t permset_d*, *acl_perm_t perm*);

**DESCRIPTION**

The **acl_add_perm**\ () function is a POSIX.1e call that adds the
permission contained in *perm* to the permission set *permset_d*.

Note: it is not considered an error to attempt to add permissions that
already exist in the permission set.

For POSIX.1e ACLs, valid values are:

+-----------------------+-----------------------+-----------------------+
|                       | ACL_EXECUTE           | Execute permission    |
+-----------------------+-----------------------+-----------------------+
|                       | ACL_WRITE             | Write permission      |
+-----------------------+-----------------------+-----------------------+
|                       | ACL_READ              | Read permission       |
+-----------------------+-----------------------+-----------------------+

For NFSv4 ACLs, valid values are:

+-----------------------+-----------------------+-----------------------+
|                       | ACL_READ_DATA         | Read permission       |
+-----------------------+-----------------------+-----------------------+
|                       | ACL_LIST_DIRECTORY    | Same as ACL_READ_DATA |
+-----------------------+-----------------------+-----------------------+
|                       | ACL_WRITE_DATA        | Write permission, or  |
|                       |                       | permission to create  |
|                       |                       | files                 |
+-----------------------+-----------------------+-----------------------+
|                       | ACL_ADD_FILE          | Same as ACL_READ_DATA |
+-----------------------+-----------------------+-----------------------+
|                       | ACL_APPEND_DATA       | Permission to create  |
|                       |                       | directories. Ignored  |
|                       |                       | for files             |
+-----------------------+-----------------------+-----------------------+
|                       | ACL_ADD_SUBDIRECTORY  | Same as               |
|                       |                       | ACL_APPEND_DATA       |
+-----------------------+-----------------------+-----------------------+
|                       | ACL_READ_NAMED_ATTRS  | Ignored               |
+-----------------------+-----------------------+-----------------------+
|                       | ACL_WRITE_NAMED_ATTRS | Ignored               |
+-----------------------+-----------------------+-----------------------+
|                       | ACL_EXECUTE           | Execute permission    |
+-----------------------+-----------------------+-----------------------+
|                       | ACL_DELETE_CHILD      | Permission to delete  |
|                       |                       | files and             |
|                       |                       | subdirectories        |
+-----------------------+-----------------------+-----------------------+
|                       | ACL_READ_ATTRIBUTES   | Permission to read    |
|                       |                       | basic attributes      |
+-----------------------+-----------------------+-----------------------+
|                       | ACL_WRITE_ATTRIBUTES  | Permission to change  |
|                       |                       | basic attributes      |
+-----------------------+-----------------------+-----------------------+
|                       | ACL_DELETE            | Permission to delete  |
|                       |                       | the object this ACL   |
|                       |                       | is placed on          |
+-----------------------+-----------------------+-----------------------+
|                       | ACL_READ_ACL          | Permission to read    |
|                       |                       | ACL                   |
+-----------------------+-----------------------+-----------------------+
|                       | ACL_WRITE_ACL         | Permission to change  |
|                       |                       | the ACL and file mode |
+-----------------------+-----------------------+-----------------------+
|                       | ACL_SYNCHRONIZE       | Ignored               |
+-----------------------+-----------------------+-----------------------+

Calling **acl_add_perm**\ () with *perm* equal to ACL_WRITE or ACL_READ
brands the ACL as POSIX. Calling it with ACL_READ_DATA,
ACL_LIST_DIRECTORY, ACL_WRITE_DATA, ACL_ADD_FILE, ACL_APPEND_DATA,
ACL_ADD_SUBDIRECTORY, ACL_READ_NAMED_ATTRS, ACL_WRITE_NAMED_ATTRS,
ACL_DELETE_CHILD, ACL_READ_ATTRIBUTES, ACL_WRITE_ATTRIBUTES, ACL_DELETE,
ACL_READ_ACL, ACL_WRITE_ACL or ACL_SYNCHRONIZE brands the ACL as NFSv4.

**RETURN VALUES**

The **acl_add_perm**\ () function returns the value 0 if successful;
otherwise the value −1 is returned and the global variable *errno* is
set to indicate the error.

**ERRORS**

The **acl_add_perm**\ () function fails if:

[EINVAL]

Argument *permset_d* is not a valid descriptor for a permission set
within an ACL entry. Argument *perm* does not contain a valid
*acl_perm_t* value. ACL is already branded differently.

**SEE ALSO**

acl(3), acl_clear_perms(3), acl_delete_perm(3), acl_get_brand_np(3),
acl_get_permset(3), acl_set_permset(3), posix1e(3)

**STANDARDS**

POSIX.1e is described in IEEE POSIX.1e draft 17.

**HISTORY**

POSIX.1e support was introduced in FreeBSD 4.0. The **acl_add_perm**\ ()
function was added in FreeBSD 5.0.

**AUTHORS**

The **acl_add_perm**\ () function was written by Chris D. Faulhaber
<*jedgar@fxp.org*>.

BSD June 25, 2009 BSD

--------------
