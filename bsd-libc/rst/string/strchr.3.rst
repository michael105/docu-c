--------------

STRCHR(3) BSD Library Functions Manual STRCHR(3)

**NAME**

**strchr**, **strrchr**, **strchrnul** — locate character in string

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <string.h>**

*char \**

**strchr**\ (*const char *s*, *int c*);

*char \**

**strrchr**\ (*const char *s*, *int c*);

*char \**

**strchrnul**\ (*const char *s*, *int c*);

**DESCRIPTION**

The **strchr**\ () function locates the first occurrence of *c*
(converted to a *char*) in the string pointed to by *s*. The terminating
null character is considered part of the string; therefore if *c* is
‘\0’, the functions locate the terminating ‘\0’.

The **strrchr**\ () function is identical to **strchr**\ () except it
locates the last occurrence of *c*.

The **strchrnul**\ () function is identical to **strchr**\ () except
that if *c* is not found in *s* a pointer to the terminating ‘\0’ is
returned.

**RETURN VALUES**

The functions **strchr**\ () and **strrchr**\ () return a pointer to the
located character, or NULL if the character does not appear in the
string.

**strchrnul**\ () returns a pointer to the terminating ‘\0’ if the
character does not appear in the string.

**SEE ALSO**

memchr(3), memmem(3), strcspn(3), strpbrk(3), strsep(3), strspn(3),
strstr(3), strtok(3), wcschr(3)

**STANDARDS**

The functions **strchr**\ () and **strrchr**\ () conform to ISO/IEC
9899:1990 (‘‘ISO C90’’). The function **strchrnul**\ () is a GNU
extension.

**HISTORY**

The **strchrnul**\ () function first appeared in glibc 2.1.1 and was
added in FreeBSD 10.0.

BSD February 13, 2013 BSD

--------------
