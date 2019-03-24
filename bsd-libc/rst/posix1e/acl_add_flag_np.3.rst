--------------

ACL_ADD_FLAG_NP(3) BSD Library Functions Manual ACL_ADD_FLAG_NP(3)

**NAME**

**acl_add_flag_np** — add flags to a flagset

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/types.h>
#include <sys/acl.h>**

*int*

**acl_add_flag_np**\ (*acl_flagset_t flagset_d*, *acl_flag_t flag*);

**DESCRIPTION**

The **acl_add_flag_np**\ () function is a non-portable call that adds
the NFSv4 ACL flags contained in *flags* to the flagset *flagset_d*.

Note: it is not considered an error to attempt to add flags that already
exist in the flagset.

Valid values are:

+-----------------------+-----------------------+-----------------------+
|                       | ACL_ENTRY_FILE_INHERI | Will be inherited by  |
|                       | T                     | files.                |
+-----------------------+-----------------------+-----------------------+
|                       | ACL_ENTRY_DIRECTORY_I | Will be inherited by  |
|                       | NHERIT                | directories.          |
+-----------------------+-----------------------+-----------------------+
|                       | ACL_ENTRY_NO_PROPAGAT | Will not propagate.   |
|                       | E_INHERIT             |                       |
+-----------------------+-----------------------+-----------------------+
|                       | ACL_ENTRY_INHERIT_ONL | Inherit-only.         |
|                       | Y                     |                       |
+-----------------------+-----------------------+-----------------------+
|                       | ACL_ENTRY_INHERITED   | Inherited from parent |
+-----------------------+-----------------------+-----------------------+

**RETURN VALUES**

The **acl_add_flag_np**\ () function returns the value 0 if successful;
otherwise the value −1 is returned and the global variable *errno* is
set to indicate the error.

**ERRORS**

The **acl_add_flag_np**\ () function fails if:

[EINVAL]

Argument *flagset_d* is not a valid descriptor for a flagset within an
ACL entry. Argument *flag* does not contain a valid *acl_flag_t* value.

**SEE ALSO**

acl(3), acl_clear_flags_np(3), acl_delete_flag_np(3),
acl_get_flagset_np(3), acl_set_flagset_np(3), posix1e(3)

**STANDARDS**

POSIX.1e is described in IEEE POSIX.1e draft 17.

**HISTORY**

POSIX.1e support was introduced in FreeBSD 4.0. The
**acl_add_flag_np**\ () function was added in FreeBSD 8.0.

**AUTHORS**

The **acl_add_flag_np**\ () function was written by Edward Tomasz
Napierala <*trasz@FreeBSD.org*>.

BSD September 4, 2015 BSD

--------------
