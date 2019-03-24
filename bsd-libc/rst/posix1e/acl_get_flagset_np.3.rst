--------------

ACL_GET_FLAGSET_NP(3) BSD Library Functions Manual ACL_GET_FLAGSET_NP(3)

**NAME**

**acl_get_flagset_np** — retrieve flagset from an NFSv4 ACL entry

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/types.h>
#include <sys/acl.h>**

*int*

**acl_get_flagset_np**\ (*acl_entry_t entry_d*,
*acl_flagset_t *flagset_p*);

**DESCRIPTION**

The **acl_get_flagset_np**\ () function is a non-portable call that
returns via *flagset_np_p* a descriptor to the flagset in the NFSv4 ACL
entry *entry_d*. Subsequent operations using the returned flagset
operate on the flagset within the ACL entry.

**RETURN VALUES**

The **acl_get_flagset_np**\ () function returns the value 0 if
successful; otherwise the value −1 is returned and the global variable
*errno* is set to indicate the error.

**ERRORS**

The **acl_get_flagset_np**\ () function fails if:

[EINVAL]

Argument *entry_d* is not a valid descriptor for an ACL entry.

**SEE ALSO**

acl(3), acl_add_flag_np(3), acl_clear_flags_np(3),
acl_delete_flag_np(3), acl_set_flagset_np(3), posix1e(3)

**STANDARDS**

POSIX.1e is described in IEEE POSIX.1e draft 17.

**HISTORY**

POSIX.1e support was introduced in FreeBSD 4.0. The
**acl_get_flagset_np**\ () function was added in FreeBSD 8.0.

**AUTHORS**

The **acl_get_flagset_np**\ () function was written by Edward Tomasz
Napierala <*trasz@FreeBSD.org*>.

BSD October 30, 2014 BSD

--------------
