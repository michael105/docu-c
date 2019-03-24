--------------

ACL_CLEAR_FLAGS_NP(3) BSD Library Functions Manual ACL_CLEAR_FLAGS_NP(3)

**NAME**

**acl_clear_flags_np** — clear flags from a flagset

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/types.h>
#include <sys/acl.h>**

*int*

**acl_clear_flags_np**\ (*acl_flagset_t flagset_d*);

**DESCRIPTION**

The **acl_clear_flags_np**\ () function is a non-portable call that
clears all NFSv4 ACL flags from flagset *flagset_d*.

**RETURN VALUES**

The **acl_clear_flags_np**\ () function returns the value 0 if
successful; otherwise the value −1 is returned and the global variable
*errno* is set to indicate the error.

**ERRORS**

The **acl_clear_flags_np**\ () function fails if:

[EINVAL]

Argument *flagset_d* is not a valid descriptor for a flagset.

**SEE ALSO**

acl(3), acl_add_flag_np(3), acl_delete_flag_np(3),
acl_get_flagset_np(3), acl_set_flagset_np(3), posix1e(3)

**STANDARDS**

POSIX.1e is described in IEEE POSIX.1e draft 17.

**HISTORY**

POSIX.1e support was introduced in FreeBSD 4.0. The
**acl_clear_flags_np**\ () function was added in FreeBSD 5.0.

**AUTHORS**

The **acl_clear_flags_np**\ () function was written by Edward Tomasz
Napierala <*trasz@FreeBSD.org*>.

BSD October 30, 2014 BSD

--------------
