--------------

ACL_GET_ENTRY(3) BSD Library Functions Manual ACL_GET_ENTRY(3)

**NAME**

**acl_get_entry** — retrieve an ACL entry from an ACL

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/types.h>
#include <sys/acl.h>**

*int*

**acl_get_entry**\ (*acl_t acl*, *int entry_id*,
*acl_entry_t *entry_p*);

**DESCRIPTION**

The **acl_get_entry**\ () function is a POSIX.1e call that retrieves a
descriptor for an ACL entry specified by the argument *entry_d* within
the ACL indicated by the argument *acl*.

If the value of *entry_id* is ACL_FIRST_ENTRY, then the function will
return in *entry_p* a descriptor for the first ACL entry within *acl*.
If a call is made to **acl_get_entry**\ () with *entry_id* set to
ACL_NEXT_ENTRY when there has not been either an initial successful call
to **acl_get_entry**\ (), or a previous successful call to
**acl_create_entry**\ (), **acl_delete_entry**\ (), **acl_dup**\ (),
**acl_from_text**\ (), **acl_get_fd**\ (), **acl_get_file**\ (),
**acl_set_fd**\ (), **acl_set_file**\ (), or **acl_valid**\ (), then the
result is unspecified.

**RETURN VALUES**

If the **acl_get_entry**\ () function successfully obtains an ACL entry,
a value of 1 is returned. If the ACL has no ACL entries, the
**acl_get_entry**\ () returns a value of 0. If the value of *entry_id*
is ACL_NEXT_ENTRY and the last ACL entry in the ACL has already been
returned by a previous call to **acl_get_entry**\ (), a value of 0 will
be returned until a successful call with *entry_id* of ACL_FIRST_ENTRY
is made. Otherwise, a value of -1 will be returned and the global
variable *errno* will be set to indicate the error.

**ERRORS**

The **acl_get_entry**\ () fails if:

[EINVAL]

Argument *acl* does not point to a valid ACL. Argument *entry_id* is
neither ACL_FIRST_ENTRY nor ACL_NEXT_ENTRY.

**SEE ALSO**

acl(3), acl_calc_mask(3), acl_create_entry(3), acl_delete_entry(3),
acl_dup(3), acl_from_text(3), acl_get_fd(3), acl_get_file(3),
acl_init(3), acl_set_fd(3), acl_set_file(3), acl_valid(3), posix1e(3)

**STANDARDS**

POSIX.1e is described in IEEE POSIX.1e draft 17.

**HISTORY**

POSIX.1e support was introduced in FreeBSD 4.0. The
**acl_get_entry**\ () function was added in FreeBSD 5.0.

**AUTHORS**

The **acl_get_entry**\ () function was written by Chris D. Faulhaber
<*jedgar@fxp.org*>.

BSD April 13, 2001 BSD

--------------
