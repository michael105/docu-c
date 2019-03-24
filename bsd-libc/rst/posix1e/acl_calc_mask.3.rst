--------------

ACL_CALC_MASK(3) BSD Library Functions Manual ACL_CALC_MASK(3)

**NAME**

**acl_calc_mask** — calculate and set ACL mask permissions

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/types.h>
#include <sys/acl.h>**

*int*

**acl_calc_mask**\ (*acl_t *acl_p*);

**DESCRIPTION**

The **acl_calc_mask**\ () function is a POSIX.1e call that calculates
and set the permissions associated with the ACL_MASK ACL entry of the
ACL referred to by *acl_p*.

The value of new permissions are the union of the permissions granted by
the ACL_GROUP, ACL_GROUP_OBJ, ACL_USER tag types which match processes
in the file group class contained in the ACL referred to by *acl_p*.

If the ACL referred to by *acl_p* already contains an ACL_MASK entry,
its permissions shall be overwritten; if it does not contain an ACL_MASK
entry, one shall be added.

**RETURN VALUES**

The **acl_calc_mask**\ () function returns the value 0 if successful;
otherwise the value −1 is returned and the global variable *errno* is
set to indicate the error.

**ERRORS**

The **acl_calc_mask**\ () function fails if:

[EINVAL]

Argument *acl_p* does not point to a pointer to a valid ACL.

**SEE ALSO**

acl(3), acl_get_entry(3), acl_valid(3), posix1e(3)

**STANDARDS**

POSIX.1e is described in IEEE POSIX.1e draft 17.

**HISTORY**

POSIX.1e support was introduced in FreeBSD 4.0. The
**acl_calc_mask**\ () function was added in FreeBSD 5.0.

**AUTHORS**

The **acl_calc_mask**\ () function was written by Chris D. Faulhaber
<*jedgar@fxp.org*>.

BSD March 10, 2001 BSD

--------------
