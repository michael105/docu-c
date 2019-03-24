--------------

ACL_GET_PERM_NP(3) BSD Library Functions Manual ACL_GET_PERM_NP(3)

**NAME**

**acl_get_perm_np** — check if a permission is set in a permission set

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/types.h>
#include <sys/acl.h>**

*int*

**acl_get_perm_np**\ (*acl_permset_t permset_d*, *acl_perm_t perm*);

**DESCRIPTION**

The **acl_get_perm_np**\ () function is a non-portable function that
checks if a permission is set in a permission set.

**RETURN VALUES**

If the permission in *perm* is set in the permission set *permset_d*, a
value of 1 is returned, otherwise a value of 0 is returned.

**ERRORS**

If any of the following conditions occur, the **acl_get_perm_np**\ ()
function will return a value of −1 and set global variable *errno* to
the corresponding value:

[EINVAL]

Argument *perm* does not contain a valid ACL permission or argument
*permset_d* is not a valid ACL permset.

**SEE ALSO**

acl(3), acl_add_perm(3), acl_clear_perms(3), acl_delete_perm(3),
acl_get_permset(3), acl_set_permset(3), posix1e(3)

**STANDARDS**

POSIX.1e is described in IEEE POSIX.1e draft 17.

**HISTORY**

POSIX.1e support was introduced in FreeBSD 4.0. The
**acl_get_perm_np**\ () function was added in FreeBSD 5.0.

**AUTHORS**

The **acl_get_perm_np**\ () function was written by Chris D. Faulhaber
<*jedgar@fxp.org*>.

BSD April 10, 2001 BSD

--------------
