--------------

ACL_COPY_ENTRY(3) BSD Library Functions Manual ACL_COPY_ENTRY(3)

**NAME**

**acl_copy_entry** — copy an ACL entry to another ACL entry

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/types.h>
#include <sys/acl.h>**

*int*

**acl_copy_entry**\ (*acl_entry_t dest_d*, *acl_entry_t src_d*);

**DESCRIPTION**

The **acl_copy_entry**\ () function is a POSIX.1e call that copies the
contents of ACL entry *src_d* to ACL entry *dest_d*.

**RETURN VALUES**

The **acl_copy_entry**\ () function returns the value 0 if successful;
otherwise the value −1 is returned and the global variable *errno* is
set to indicate the error.

**ERRORS**

The **acl_copy_entry**\ () function fails if:

[EINVAL]

Argument *src_d* or *dest_d* is not a valid descriptor for an ACL entry,
or arguments *src_d* and *dest_d* reference the same ACL entry.

**SEE ALSO**

acl(3), acl_get_entry(3), posix1e(3)

**STANDARDS**

POSIX.1e is described in IEEE POSIX.1e draft 17.

**HISTORY**

POSIX.1e support was introduced in FreeBSD 4.0. The
**acl_copy_entry**\ () function was added in FreeBSD 5.0.

**AUTHORS**

The **acl_copy_entry**\ () function was written by Chris D. Faulhaber
<*jedgar@fxp.org*>.

BSD March 10, 2001 BSD

--------------
