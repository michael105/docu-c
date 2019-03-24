--------------

ACL_GET_ENTRY_TYPE_NP(3) BSD Library Functions Manual
ACL_GET_ENTRY_TYPE_NP(3)

**NAME**

**acl_get_entry_type_np** — retrieve the ACL type from an NFSv4 ACL
entry

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/types.h>
#include <sys/acl.h>**

*int*

**acl_get_entry_type_np**\ (*acl_entry_t entry_d*,
*acl_entry_type_t *entry_type_p*);

**DESCRIPTION**

The **acl_get_entry_type_np**\ () function is a non-portable call that
returns the ACL type for the NFSv4 ACL entry *entry_d*. Upon successful
completion, the location referred to by the argument *entry_type_p* will
be set to the ACL type of the ACL entry *entry_d*.

**RETURN VALUES**

The **acl_get_entry_type_np**\ () function returns the value 0 if
successful; otherwise the value −1 is returned and the global variable
*errno* is set to indicate the error.

**ERRORS**

The **acl_get_entry_type_np**\ () function fails if:

[EINVAL]

Argument *entry_d* is not a valid descriptor for an NFSv4 ACL entry;

**SEE ALSO**

acl(3), acl_set_entry_type_np(3), posix1e(3)

**STANDARDS**

POSIX.1e is described in IEEE POSIX.1e draft 17.

**HISTORY**

POSIX.1e support was introduced in FreeBSD 4.0. The
**acl_get_entry_type_np**\ () function was added in FreeBSD 8.0.

**AUTHORS**

The **acl_get_entry_type_np**\ () function was written by Edward Tomasz
Napierala <*trasz@FreeBSD.org*>.

BSD June 25, 2009 BSD

--------------
