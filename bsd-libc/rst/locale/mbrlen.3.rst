--------------

MBRLEN(3) BSD Library Functions Manual MBRLEN(3)

**NAME**

**mbrlen** — get number of bytes in a character (restartable)

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <wchar.h>**

*size_t*

**mbrlen**\ (*const char * restrict s*, *size_t n*,
*mbstate_t * restrict ps*);

**DESCRIPTION**

The **mbrlen**\ () function inspects at most *n* bytes pointed to by *s*
to determine the number of bytes needed to complete the next multibyte
character.

The *mbstate_t* argument, *ps*, is used to keep track of the shift
state. If it is NULL, **mbrlen**\ () uses an internal, static
*mbstate_t* object, which is initialized to the initial conversion state
at program startup.

It is equivalent to:

mbrtowc(NULL, s, n, ps);

Except that when *ps* is a NULL pointer, **mbrlen**\ () uses its own
static, internal *mbstate_t* object to keep track of the shift state.

**RETURN VALUES**

The **mbrlen**\ () functions returns:

0

The next *n* or fewer bytes represent the null wide character (L’\0’).

>0

The next *n* or fewer bytes represent a valid character, **mbrlen**\ ()
returns the number of bytes used to complete the multibyte character.

( *
size_t*)−2

The next *n* contribute to, but do not complete, a valid multibyte
character sequence, and all *n* bytes have been processed.

( *
size_t*)−1

An encoding error has occurred. The next *n* or fewer bytes do not
contribute to a valid multibyte character.

**EXAMPLES**

A function that calculates the number of characters in a multibyte
character string:

| size_t
| nchars(const char \*s)
| {

+-----------------+-----------------+-----------------+-----------------+
|                 | size_t charlen, |                 |                 |
|                 | chars;          |                 |                 |
+-----------------+-----------------+-----------------+-----------------+
|                 | mbstate_t mbs;  |                 |                 |
+-----------------+-----------------+-----------------+-----------------+
|                 | chars = 0;      |                 |                 |
+-----------------+-----------------+-----------------+-----------------+
|                 | memset(&mbs, 0, |                 |                 |
|                 | sizeof(mbs));   |                 |                 |
+-----------------+-----------------+-----------------+-----------------+
|                 | while ((charlen |                 |                 |
|                 | = mbrlen(s,     |                 |                 |
|                 | MB_CUR_MAX,     |                 |                 |
|                 | &mbs)) != 0 &&  |                 |                 |
+-----------------+-----------------+-----------------+-----------------+
|                 | charlen !=      |                 |                 |
|                 | (size_t)-1 &&   |                 |                 |
|                 | charlen !=      |                 |                 |
|                 | (size_t)-2) {   |                 |                 |
+-----------------+-----------------+-----------------+-----------------+
|                 |                 | s += charlen;   |                 |
+-----------------+-----------------+-----------------+-----------------+
|                 |                 | chars++;        |                 |
+-----------------+-----------------+-----------------+-----------------+
|                 | }               |                 |                 |
+-----------------+-----------------+-----------------+-----------------+
|                 | return (chars); |                 |                 |
+-----------------+-----------------+-----------------+-----------------+

}

**ERRORS**

The **mbrlen**\ () function will fail if:

[EILSEQ]

An invalid multibyte sequence was detected.

[EINVAL]

The conversion state is invalid.

**SEE ALSO**

mblen(3), mbrtowc(3), multibyte(3)

**STANDARDS**

The **mbrlen**\ () function conforms to ISO/IEC 9899:1999 (‘‘ISO C99’’).

BSD April 7, 2004 BSD

--------------
