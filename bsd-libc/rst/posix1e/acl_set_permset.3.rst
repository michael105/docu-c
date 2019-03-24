--------------

ACL_SET_PERMSET(3) BSD Library Functions Manual ACL_SET_PERMSET(3)

**NAME**

**acl_set_permset** — set the permissions of an ACL entry

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/types.h>
#include <sys/acl.h>**

*int*

**acl_set_permset**\ (*acl_entry_t entry_d*, *acl_permset_t permset_d*);

**DESCRIPTION**

The **acl_set_permset**\ () function is a POSIX.1e call that sets the
permissions of ACL entry *entry_d* with the permissions contained in
*permset_d*.

**RETURN VALUES**

The **acl_set_permset**\ () function returns the value 0 if successful;
otherwise the value −1 is returned and the global variable *errno* is
set to indicate the error.

**ERRORS**

The **acl_set_permset**\ () function fails if:

[EINVAL]

Argument *entry_d* is not a valid descriptor for an ACL entry.

**SEE ALSO**

acl(3), acl_add_perm(3), acl_clear_perms(3), acl_delete_perm(3),
acl_get_permset(3), posix1e(3)

**STANDARDS**

POSIX.1e is described in IEEE POSIX.1e draft 17.

**HISTORY**

POSIX.1e support was introduced in FreeBSD 4.0. The
**acl_set_permset**\ () function was added in FreeBSD 5.0.

**AUTHORS**

The **acl_set_permset**\ () function was written by Chris D. Faulhaber
<*jedgar@fxp.org*>.

BSD March 10, 2001 BSD

--------------
