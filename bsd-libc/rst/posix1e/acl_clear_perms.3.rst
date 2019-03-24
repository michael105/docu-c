--------------

ACL_CLEAR_PERMS(3) BSD Library Functions Manual ACL_CLEAR_PERMS(3)

**NAME**

**acl_clear_perms** — clear permissions from a permission set

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/types.h>
#include <sys/acl.h>**

*int*

**acl_clear_perms**\ (*acl_permset_t permset_d*);

**DESCRIPTION**

The **acl_clear_perms**\ () function is a POSIX.1e call that clears all
permissions from permissions set *permset_d*.

**RETURN VALUES**

The **acl_clear_perms**\ () function returns the value 0 if successful;
otherwise the value −1 is returned and the global variable *errno* is
set to indicate the error.

**ERRORS**

The **acl_clear_perms**\ () function fails if:

[EINVAL]

Argument *permset_d* is not a valid descriptor for a permission set.

**SEE ALSO**

acl(3), acl_add_perm(3), acl_delete_perm(3), acl_get_permset(3),
acl_set_permset(3), posix1e(3)

**STANDARDS**

POSIX.1e is described in IEEE POSIX.1e draft 17.

**HISTORY**

POSIX.1e support was introduced in FreeBSD 4.0. The
**acl_clear_perms**\ () function was added in FreeBSD 5.0.

**AUTHORS**

The **acl_clear_perms**\ () function was written by Chris D. Faulhaber
<*jedgar@fxp.org*>.

BSD March 10, 2001 BSD

--------------
