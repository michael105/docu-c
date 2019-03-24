--------------

WCWIDTH(3) BSD Library Functions Manual WCWIDTH(3)

**NAME**

**wcwidth** — number of column positions of a wide-character code

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <wchar.h>**

*int*

**wcwidth**\ (*wchar_t wc*);

**DESCRIPTION**

The **wcwidth**\ () function determines the number of column positions
required to display the wide character *wc*.

**RETURN VALUES**

The **wcwidth**\ () function returns 0 if the *wc* argument is a null
wide character (L’\0’), −1 if *wc* is not printable, otherwise it
returns the number of column positions the character occupies.

**EXAMPLES**

This code fragment reads text from standard input and breaks lines that
are more than 20 column positions wide, similar to the fold(1) utility:

| wint_t ch;
| int column, w;

| column = 0;
| while ((ch = getwchar()) != WEOF) {

+-----------------+-----------------+-----------------+-----------------+
|                 | w =             |                 |                 |
|                 | wcwidth(ch);    |                 |                 |
+-----------------+-----------------+-----------------+-----------------+
|                 | if (w > 0 &&    |                 |                 |
|                 | column + w >=   |                 |                 |
|                 | 20) {           |                 |                 |
+-----------------+-----------------+-----------------+-----------------+
|                 |                 | putwchar(L’\n’) |                 |
|                 |                 | ;               |                 |
+-----------------+-----------------+-----------------+-----------------+
|                 |                 | column = 0;     |                 |
+-----------------+-----------------+-----------------+-----------------+
|                 | }               |                 |                 |
+-----------------+-----------------+-----------------+-----------------+
|                 | putwchar(ch);   |                 |                 |
+-----------------+-----------------+-----------------+-----------------+
|                 | if (ch ==       |                 |                 |
|                 | L’\n’)          |                 |                 |
+-----------------+-----------------+-----------------+-----------------+
|                 |                 | column = 0;     |                 |
+-----------------+-----------------+-----------------+-----------------+
|                 | else if (w > 0) |                 |                 |
+-----------------+-----------------+-----------------+-----------------+
|                 |                 | column += w;    |                 |
+-----------------+-----------------+-----------------+-----------------+

}

**SEE ALSO**

iswprint(3), wcswidth(3)

**STANDARDS**

The **wcwidth**\ () function conforms to IEEE Std 1003.1-2001
(‘‘POSIX.1’’).

BSD August 17, 2004 BSD

--------------
