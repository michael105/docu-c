--------------

ACL_GET_FLAG_NP(3) BSD Library Functions Manual ACL_GET_FLAG_NP(3)

**NAME**

**acl_get_flag_np** — check if a flag is set in a flagset

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/types.h>
#include <sys/acl.h>**

*int*

**acl_get_flag_np**\ (*acl_flagset_t flagset_d*, *acl_flag_t flag*);

**DESCRIPTION**

The **acl_get_flag_np**\ () function is a non-portable function that
checks if a NFSv4 ACL flag is set in a flagset.

**RETURN VALUES**

If the flag in *flag* is set in the flagset *flagset_d*, a value of 1 is
returned, otherwise a value of 0 is returned.

**ERRORS**

If any of the following conditions occur, the **acl_get_flag_np**\ ()
function will return a value of −1 and set global variable *errno* to
the corresponding value:

[EINVAL]

Argument *flag* does not contain a valid ACL flag or argument
*flagset_d* is not a valid ACL flagset.

**SEE ALSO**

acl(3), acl_add_flag_np(3), acl_clear_flags_np(3),
acl_delete_flag_np(3), acl_get_flagset_np(3), acl_set_flagset_np(3),
posix1e(3)

**STANDARDS**

POSIX.1e is described in IEEE POSIX.1e draft 17.

**HISTORY**

POSIX.1e support was introduced in FreeBSD 4.0. The
**acl_get_flag_np**\ () function was added in FreeBSD 8.0.

**AUTHORS**

The **acl_get_flag_np**\ () function was written by Edward Tomasz
Napierala <*trasz@FreeBSD.org*>.

BSD October 30, 2014 BSD

--------------
