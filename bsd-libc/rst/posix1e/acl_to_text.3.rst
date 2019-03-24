--------------

ACL_TO_TEXT(3) BSD Library Functions Manual ACL_TO_TEXT(3)

**NAME**

**acl_to_text**, **acl_to_text_np** — convert an ACL to text

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/types.h>
#include <sys/acl.h>**

*char \**

**acl_to_text**\ (*acl_t acl*, *ssize_t *len_p*);

*char \**

**acl_to_text_np**\ (*acl_t acl*, *ssize_t *len_p*, *int flags*);

**DESCRIPTION**

The **acl_to_text**\ () and **acl_to_text_np**\ () functions translate
the ACL pointed to by argument *acl* into a NULL terminated character
string. If the pointer *len_p* is not NULL, then the function shall
return the length of the string (not including the NULL terminator) in
the location pointed to by *len_p*. If the ACL is POSIX.1e, the format
of the text string returned by **acl_to_text**\ () shall be the POSIX.1e
long ACL form. If the ACL is NFSv4, the format of the text string shall
be the compact form, unless the *ACL_TEXT_VERBOSE* flag is given.

The flags specified are formed by *or*\ ’ing the following values

+-----------------------+-----------------------+-----------------------+
|                       | ACL_TEXT_VERBOSE      | Format ACL using      |
|                       |                       | verbose form          |
+-----------------------+-----------------------+-----------------------+
|                       | ACL_TEXT_NUMERIC_IDS  | Do not resolve IDs    |
|                       |                       | into user or group    |
|                       |                       | names                 |
+-----------------------+-----------------------+-----------------------+
|                       | ACL_TEXT_APPEND_ID    | In addition to user   |
|                       |                       | and group names,      |
|                       |                       | append numeric IDs    |
+-----------------------+-----------------------+-----------------------+

This function allocates any memory necessary to contain the string and
returns a pointer to the string. The caller should free any releasable
memory, when the new string is no longer required, by calling
acl_free(3) with the *(void*)char* as an argument.

**IMPLEMENTATION NOTES**

FreeBSD’s support for POSIX.1e interfaces and features is still under
development at this time.

**RETURN VALUES**

Upon successful completion, the function shall return a pointer to the
long text form of an ACL. Otherwise, a value of *(char*)NULL* shall be
returned and *errno* shall be set to indicate the error.

**ERRORS**

If any of the following conditions occur, the **acl_to_text**\ ()
function shall return a value of *(acl_t)NULL* and set *errno* to the
corresponding value:

[EINVAL]

Argument *acl* does not point to a valid ACL.

The ACL denoted by *acl* contains one or more improperly formed ACL
entries, or for some other reason cannot be translated into a text form
of an ACL.

[ENOMEM]

The character string to be returned requires more memory than is allowed
by the hardware or software-imposed memory management constraints.

**SEE ALSO**

acl(3), acl_free(3), acl_from_text(3), posix1e(3)

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

**BUGS**

The **acl_from_text**\ () and **acl_to_text**\ () functions rely on the
getpwent(3) library calls to manage username and uid mapping, as well as
the getgrent(3) library calls to manage groupname and gid mapping. These
calls are not thread safe, and so transitively, neither are
**acl_from_text**\ () and **acl_to_text**\ (). These functions may also
interfere with stateful calls associated with the **getpwent**\ () and
**getgrent**\ () calls.

BSD June 25, 2009 BSD

--------------
