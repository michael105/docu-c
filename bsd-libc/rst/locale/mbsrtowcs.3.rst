--------------

MBSRTOWCS(3) BSD Library Functions Manual MBSRTOWCS(3)

**NAME**

**mbsrtowcs**, **mbsnrtowcs** — convert a character string to a
wide-character string (restartable)

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <wchar.h>**

*size_t*

**mbsrtowcs**\ (*wchar_t * restrict dst*, *const char ** restrict src*,
*size_t len*, *mbstate_t * restrict ps*);

*size_t*

**mbsnrtowcs**\ (*wchar_t * restrict dst*, *const char ** restrict src*,
*size_t nms*, *size_t len*, *mbstate_t * restrict ps*);

**DESCRIPTION**

The **mbsrtowcs**\ () function converts a sequence of multibyte
characters pointed to indirectly by *src* into a sequence of
corresponding wide characters and stores at most *len* of them in the
*wchar_t* array pointed to by *dst*, until it encounters a terminating
null character (’\0’).

If *dst* is NULL, no characters are stored.

If *dst* is not NULL, the pointer pointed to by *src* is updated to
point to the character after the one that conversion stopped at. If
conversion stops because a null character is encountered, *\*src* is set
to NULL.

The *mbstate_t* argument, *ps*, is used to keep track of the shift
state. If it is NULL, **mbsrtowcs**\ () uses an internal, static
*mbstate_t* object, which is initialized to the initial conversion state
at program startup.

The **mbsnrtowcs**\ () function behaves identically to
**mbsrtowcs**\ (), except that conversion stops after reading at most
*nms* bytes from the buffer pointed to by *src*.

**RETURN VALUES**

The **mbsrtowcs**\ () and **mbsnrtowcs**\ () functions return the number
of wide characters stored in the array pointed to by *dst* if
successful, otherwise it returns (

*size_t* )−1.

**ERRORS**

The **mbsrtowcs**\ () and **mbsnrtowcs**\ () functions will fail if:

[EILSEQ]

An invalid multibyte character sequence was encountered.

[EINVAL]

The conversion state is invalid.

**SEE ALSO**

mbrtowc(3), mbstowcs(3), multibyte(3), wcsrtombs(3)

**STANDARDS**

The **mbsrtowcs**\ () function conforms to ISO/IEC 9899:1999
(‘‘ISO C99’’).

The **mbsnrtowcs**\ () function is an extension to the standard.

BSD July 21, 2004 BSD

--------------
