--------------

INDEX(3) BSD Library Functions Manual INDEX(3)

**NAME**

**index**, **rindex** — locate character in string

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <strings.h>**

*char \**

**index**\ (*const char *s*, *int c*);

*char \**

**rindex**\ (*const char *s*, *int c*);

**DESCRIPTION**

**The index**\ () **and rindex**\ () **functions have been deprecated in
favor of** strchr(\ **3**) **and** strrchr(\ **3**)\ **.**

The **index**\ () function locates the first occurrence of *c*
(converted to a *char*) in the string pointed to by *s*. The terminating
null character is considered part of the string; therefore if *c* is
‘\0’, the functions locate the terminating ‘\0’.

The **rindex**\ () function is identical to **index**\ (), except it
locates the last occurrence of *c*.

**RETURN VALUES**

The functions **index**\ () and **rindex**\ () return a pointer to the
located character, or NULL if the character does not appear in the
string.

**SEE ALSO**

memchr(3), strchr(3), strcspn(3), strpbrk(3), strrchr(3), strsep(3),
strspn(3), strstr(3), strtok(3)

**HISTORY**

The **index**\ () and **rindex**\ () functions appeared in Version 6
AT&T UNIX. Their prototypes existed previously in <*string.h*> before
they were moved to <*strings.h*> for IEEE Std 1003.1-2001 (‘‘POSIX.1’’)
compliance. The functions are not specified by IEEE Std 1003.1-2008
(‘‘POSIX.1’’).

BSD March 20, 2011 BSD

--------------
