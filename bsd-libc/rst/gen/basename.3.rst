--------------

BASENAME(3) BSD Library Functions Manual BASENAME(3)

**NAME**

**basename** — extract the base portion of a pathname

**SYNOPSIS**

**#include <libgen.h>**

*char \**

**basename**\ (*char *path*);

**DESCRIPTION**

The **basename**\ () function returns the last component from the
pathname pointed to by *path*, deleting any trailing ‘/’ characters.

**IMPLEMENTATION NOTES**

This implementation of **basename**\ () uses the buffer provided by the
caller to store the resulting pathname component. Other vendor
implementations may return a pointer to internal storage space instead.
The advantage of the former approach is that it ensures thread-safety,
while also placing no upper limit on the supported length of the
pathname.

**RETURN VALUES**

If *path* consists entirely of ‘/’ characters, a pointer to the string
"/" is returned. If *path* is a null pointer or the empty string, a
pointer to the string "." is returned. Otherwise, it returns a pointer
to the last component of *path*.

**SEE ALSO**

basename(1), dirname(1), dirname(3)

**STANDARDS**

The **basename**\ () function conforms to X/Open Portability Guide
Issue 4, Version 2 (‘‘XPG4.2’’).

**HISTORY**

The **basename**\ () function first appeared in OpenBSD 2.2 and
FreeBSD 4.2.

In FreeBSD 12.0, this function was reimplemented to store its result in
the provided input buffer. There is no longer any need to use the
**basename_r**\ () function.

**AUTHORS**

Nuxi, the Netherlands

BSD May 22, 2017 BSD

--------------
