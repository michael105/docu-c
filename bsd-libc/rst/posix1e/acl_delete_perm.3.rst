--------------

ACL_DELETE_PERM(3) BSD Library Functions Manual ACL_DELETE_PERM(3)

**NAME**

**acl_delete_perm** — delete permissions from a permission set

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/types.h>
#include <sys/acl.h>**

*int*

**acl_delete_perm**\ (*acl_permset_t permset_d*, *acl_perm_t perm*);

**DESCRIPTION**

The **acl_delete_perm**\ () function is a POSIX.1e call that removes
specific permissions from permissions set *perm*.

**RETURN VALUES**

The **acl_delete_perm**\ () function returns the value 0 if successful;
otherwise the value −1 is returned and the global variable *errno* is
set to indicate the error.

**ERRORS**

The **acl_delete_perm**\ () function fails if:

[EINVAL]

Argument *permset_d* is not a valid descriptor for a permission set.
Argument *perm* does not contain a valid *acl_perm_t* value.

**SEE ALSO**

acl(3), acl_add_perm(3), acl_clear_perms(3), acl_get_permset(3),
acl_set_permset(3), posix1e(3)

**STANDARDS**

POSIX.1e is described in IEEE POSIX.1e draft 17.

**HISTORY**

POSIX.1e support was introduced in FreeBSD 4.0. The
**acl_delete_perm**\ () function was added in FreeBSD 5.0.

**AUTHORS**

The **acl_delete_perm**\ () function was written by Chris D. Faulhaber
<*jedgar@fxp.org*>.

BSD March 10, 2001 BSD

--------------
