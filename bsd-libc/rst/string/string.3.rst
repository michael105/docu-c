--------------

STRING(3) BSD Library Functions Manual STRING(3)

**NAME**

**stpcpy**, **strcat**, **strncat**, **strchr**, **strrchr**,
**strcmp**, **strncmp**, **strcasecmp**, **strncasecmp**, **strcpy**,
**strncpy**, **strerror**, **strlen**, **strpbrk**, **strsep**,
**strspn**, **strcspn**, **strstr**, **strtok**, **index**, **rindex** —
string specific functions

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <string.h>**

*char \**

**stpcpy**\ (*char *dst*, *const char *src*);

*char \**

**strcat**\ (*char *s*, *const char * append*);

*char \**

**strncat**\ (*char *s*, *const char *append*, *size_t count*);

*char \**

**strchr**\ (*const char *s*, *int c*);

*char \**

**strrchr**\ (*const char *s*, *int c*);

*int*

**strcmp**\ (*const char *s1*, *const char *s2*);

*int*

**strncmp**\ (*const char *s1*, *const char *s2*, *size_t count*);

*int*

**strcasecmp**\ (*const char *s1*, *const char *s2*);

*int*

**strncasecmp**\ (*const char *s1*, *const char *s2*, *size_t count*);

*char \**

**strcpy**\ (*char *dst*, *const char *src*);

*char \**

**strncpy**\ (*char *dst*, *const char *src*, *size_t count*);

*char \**

**strerror**\ (*int errno*);

*size_t*

**strlen**\ (*const char *s*);

*char \**

**strpbrk**\ (*const char *s*, *const char *charset*);

*char \**

**strsep**\ (*char **stringp*, *const char *delim*);

*size_t*

**strspn**\ (*const char *s*, *const char *charset*);

*size_t*

**strcspn**\ (*const char *s*, *const char *charset*);

*char \**

**strstr**\ (*const char *big*, *const char *little*);

*char \**

**strtok**\ (*char *s*, *const char *delim*);

*char \**

**index**\ (*const char *s*, *int c*);

*char \**

**rindex**\ (*const char *s*, *int c*);

**DESCRIPTION**

The string functions manipulate strings terminated by a null byte.

See the specific manual pages for more information. For manipulating
variable length generic objects as byte strings (without the null byte
check), see bstring(3).

Except as noted in their specific manual pages, the string functions do
not test the destination for size limitations.

**SEE ALSO**

bstring(3), index(3), rindex(3), stpcpy(3), strcasecmp(3), strcat(3),
strchr(3), strcmp(3), strcpy(3), strcspn(3), strerror(3), strlen(3),
strpbrk(3), strrchr(3), strsep(3), strspn(3), strstr(3), strtok(3)

**STANDARDS**

The **strcat**\ (), **strncat**\ (), **strchr**\ (), **strrchr**\ (),
**strcmp**\ (), **strncmp**\ (), **strcpy**\ (), **strncpy**\ (),
**strerror**\ (), **strlen**\ (), **strpbrk**\ (), **strspn**\ (),
**strcspn**\ (), **strstr**\ (), and **strtok**\ () functions conform to
ISO/IEC 9899:1990 (‘‘ISO C90’’).

BSD December 11, 1993 BSD

--------------
