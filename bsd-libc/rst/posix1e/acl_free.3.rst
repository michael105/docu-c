--------------

ACL_FREE(3) BSD Library Functions Manual ACL_FREE(3)

**NAME**

**acl_free** — free ACL working state

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/types.h>
#include <sys/acl.h>**

*int*

**acl_free**\ (*void *obj_p*);

**DESCRIPTION**

The **acl_free**\ () call allows the freeing of ACL working space, such
as is allocated by acl_dup(3), or acl_from_text(3).

**IMPLEMENTATION NOTES**

FreeBSD’s support for POSIX.1e interfaces and features is still under
development at this time.

**RETURN VALUES**

The **acl_free**\ () function returns the value 0 if successful;
otherwise the value −1 is returned and the global variable *errno* is
set to indicate the error.

**ERRORS**

If any of the following conditions occur, the **acl_free**\ () function
shall return -1 and set *errno* to the corresponding value:

[EINVAL]

The value of the *obj_p* argument is invalid.

**SEE ALSO**

acl(3), acl_dup(3), acl_from_text(3), acl_get(3), acl_init(3),
posix1e(3)

**STANDARDS**

POSIX.1e is described in IEEE POSIX.1e draft 17. Discussion of the draft
continues on the cross-platform POSIX.1e implementation mailing list. To
join this list, see the FreeBSD POSIX.1e implementation page for more
information.

**HISTORY**

POSIX.1e support was introduced in FreeBSD 4.0, and development
continues.

**AUTHORS**

Robert N M Watson

BSD January 28, 2000 BSD

--------------
