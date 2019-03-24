--------------

ACL_CREATE_ENTRY(3) BSD Library Functions Manual ACL_CREATE_ENTRY(3)

**NAME**

**acl_create_entry**, **acl_create_entry_np** — create a new ACL entry

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/types.h>
#include <sys/acl.h>**

*int*

**acl_create_entry**\ (*acl_t *acl_p*, *acl_entry_t *entry_p*);

*int*

**acl_create_entry_np**\ (*acl_t *acl_p*, *acl_entry_t *entry_p*,
*int index*);

**DESCRIPTION**

The **acl_create_entry**\ () function is a POSIX.1e call that creates a
new ACL entry in the ACL pointed to by *acl_p*. The
**acl_create_entry_np**\ () function is a non-portable version that
creates the ACL entry at position *index*. Positions are numbered
starting from zero, i.e. calling **acl_create_entry_np**\ () with
*index* argument equal to zero will prepend the entry to the ACL.

**RETURN VALUES**

The **acl_create_entry**\ () function returns the value 0 if successful;
otherwise the value −1 is returned and the global variable *errno* is
set to indicate the error.

**ERRORS**

The **acl_create_entry**\ () function fails if:

[EINVAL]

Argument *acl_p* does not point to a pointer to a valid ACL. Argument
*index* is out of bounds.

[ENOMEM]

The ACL working storage requires more memory than is allowed by the
hardware or system-imposed memory management constraints.

**SEE ALSO**

acl(3), acl_delete_entry(3), acl_get_entry(3), posix1e(3)

**STANDARDS**

POSIX.1e is described in IEEE POSIX.1e draft 17.

**HISTORY**

POSIX.1e support was introduced in FreeBSD 4.0. The
**acl_create_entry**\ () function was added in FreeBSD 5.0.

**AUTHORS**

The **acl_create_entry**\ () function was written by Chris D. Faulhaber
<*jedgar@fxp.org*>.

BSD June 25, 2009 BSD

--------------
