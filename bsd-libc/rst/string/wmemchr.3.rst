--------------

WMEMCHR(3) BSD Library Functions Manual WMEMCHR(3)

**NAME**

**wmemchr**, **wmemcmp**, **wmemcpy**, **wmemmove**, **wmemset**,
**wcpcpy**, **wcpncpy**, **wcscasecmp**, **wcscat**, **wcschr**,
**wcscmp**, **wcscpy**, **wcscspn**, **wcsdup**, **wcslcat**,
**wcslcpy**, **wcslen**, **wcsncasecmp**, **wcsncat**, **wcsncmp**,
**wcsncpy**, **wcsnlen**, **wcspbrk**, **wcsrchr**, **wcsspn**,
**wcsstr** — wide character string manipulation operations

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <wchar.h>**

*wchar_t \**

**wmemchr**\ (*const wchar_t *s*, *wchar_t c*, *size_t n*);

*int*

**wmemcmp**\ (*const wchar_t *s1*, *const wchar_t *s2*, *size_t n*);

*wchar_t \**

**wmemcpy**\ (*wchar_t * restrict s1*, *const wchar_t * restrict s2*,
*size_t n*);

*wchar_t \**

**wmemmove**\ (*wchar_t *s1*, *const wchar_t *s2*, *size_t n*);

*wchar_t \**

**wmemset**\ (*wchar_t *s*, *wchar_t c*, *size_t n*);

*wchar_t \**

**wcpcpy**\ (*wchar_t *s1*, *wchar_t *s2*);

*wchar_t \**

**wcpncpy**\ (*wchar_t *s1*, *wchar_t *s2*, *size_t n*);

*int*

**wcscasecmp**\ (*const wchar_t *s1*, *const wchar_t *s2*);

*wchar_t \**

**wcscat**\ (*wchar_t * restrict s1*, *const wchar_t * restrict s2*);

*wchar_t \**

**wcschr**\ (*const wchar_t *s*, *wchar_t c*);

*int*

**wcscmp**\ (*const wchar_t *s1*, *const wchar_t *s2*);

*wchar_t \**

**wcscpy**\ (*wchar_t * restrict s1*, *const wchar_t * restrict s2*);

*size_t*

**wcscspn**\ (*const wchar_t *s1*, *const wchar_t *s2*);

*wchar_t \**

**wcsdup**\ (*const wchar_t *s*);

*size_t*

**wcslcat**\ (*wchar_t *s1*, *const wchar_t *s2*, *size_t n*);

*size_t*

**wcslcpy**\ (*wchar_t *s1*, *const wchar_t *s2*, *size_t n*);

*size_t*

**wcslen**\ (*const wchar_t *s*);

*int*

**wcsncasecmp**\ (*const wchar_t *s1*, *const wchar_t *s2*, *size_t n*);

*wchar_t \**

**wcsncat**\ (*wchar_t * restrict s1*, *const wchar_t * restrict s2*,
*size_t n*);

*int*

**wcsncmp**\ (*const wchar_t *s1*, *const wchar_t * s2*, *size_t n*);

*wchar_t \**

**wcsncpy**\ (*wchar_t * restrict s1*, *const wchar_t * restrict s2*,
*size_t n*);

*size_t*

**wcsnlen**\ (*const wchar_t *s*, *size_t maxlen*);

*wchar_t \**

**wcspbrk**\ (*const wchar_t *s1*, *const wchar_t *s2*);

*wchar_t \**

**wcsrchr**\ (*const wchar_t *s*, *wchar_t c*);

*size_t*

**wcsspn**\ (*const wchar_t *s1*, *const wchar_t *s2*);

*wchar_t \**

**wcsstr**\ (*const wchar_t * restrict s1*,
*const wchar_t * restrict s2*);

**DESCRIPTION**

The functions implement string manipulation operations over wide
character strings. For a detailed description, refer to documents for
the respective single-byte counterpart, such as memchr(3).

**SEE ALSO**

memchr(3), memcmp(3), memcpy(3), memmove(3), memset(3), stpcpy(3),
stpncpy(3), strcasecmp(3), strcat(3), strchr(3), strcmp(3), strcpy(3),
strcspn(3), strdup(3), strlcat(3), strlcpy(3), strlen(3), strncat(3),
strncmp(3), strncpy(3), strnlen(3), strpbrk(3), strrchr(3), strspn(3),
strstr(3)

**STANDARDS**

These functions conform to ISO/IEC 9899:1999 (‘‘ISO C99’’), with the
exception of **wcpcpy**\ (), **wcpncpy**\ (), **wcscasecmp**\ (),
**wcsdup**\ (), **wcsncasecmp**\ (), and **wcsnlen**\ (), which conform
to IEEE Std 1003.1-2008 (‘‘POSIX.1’’); and **wcslcat**\ () and
**wcslcpy**\ (), which are extensions.

BSD March 4, 2009 BSD

--------------
