--------------

DIRNAME(3) BSD Library Functions Manual DIRNAME(3)

**NAME**

**dirname** — extract the directory part of a pathname

**SYNOPSIS**

**#include <libgen.h>**

*char \**

**dirname**\ (*char *path*);

**DESCRIPTION**

The **dirname**\ () function is the converse of basename(3); it returns
a pointer to the parent directory of the pathname pointed to by *path*.
Any trailing ‘/’ characters are not counted as part of the directory
name.

**IMPLEMENTATION NOTES**

This implementation of **dirname**\ () uses the buffer provided by the
caller to store the resulting parent directory. Other vendor
implementations may return a pointer to internal storage space instead.
The advantage of the former approach is that it ensures thread-safety,
while also placing no upper limit on the supported length of the
pathname.

**RETURN VALUES**

If *path* is a null pointer, the empty string, or contains no ‘/’
characters, **dirname**\ () returns a pointer to the string ".",
signifying the current directory. Otherwise, it returns a pointer to the
parent directory of *path*.

**SEE ALSO**

basename(1), dirname(1), basename(3)

**STANDARDS**

The **dirname**\ () function conforms to X/Open Portability Guide
Issue 4, Version 2 (‘‘XPG4.2’’).

**HISTORY**

The **dirname**\ () function first appeared in OpenBSD 2.2 and
FreeBSD 4.2.

In FreeBSD 12.0, this function was reimplemented to store its result in
the provided input buffer.

**AUTHORS**

Nuxi, the Netherlands

BSD September 5, 2016 BSD

--------------
