--------------

FNMATCH(3) BSD Library Functions Manual FNMATCH(3)

**NAME**

**fnmatch** — test whether a filename or pathname matches a shell-style
pattern

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <fnmatch.h>**

*int*

**fnmatch**\ (*const char *pattern*, *const char *string*, *int flags*);

**DESCRIPTION**

The **fnmatch**\ () function matches patterns according to the rules
used by the shell. It checks the string specified by the *string*
argument to see if it matches the pattern specified by the *pattern*
argument.

The *flags* argument modifies the interpretation of *pattern* and
*string*. The value of *flags* is the bitwise inclusive OR of any of the
following constants, which are defined in the include file
<*fnmatch.h*>.

FNM_NOESCAPE

Normally, every occurrence of a backslash (‘\’) followed by a character
in *pattern* is replaced by that character. This is done to negate any
special meaning for the character. If the FNM_NOESCAPE flag is set, a
backslash character is treated as an ordinary character.

FNM_PATHNAME

Slash characters in *string* must be explicitly matched by slashes in
*pattern*. If this flag is not set, then slashes are treated as regular
characters.

FNM_PERIOD

Leading periods in *string* must be explicitly matched by periods in
*pattern*. If this flag is not set, then leading periods are treated as
regular characters. The definition of ‘‘leading’’ is related to the
specification of FNM_PATHNAME. A period is always ‘‘leading’’ if it is
the first character in *string*. Additionally, if FNM_PATHNAME is set, a
period is leading if it immediately follows a slash.

FNM_LEADING_DIR

Ignore ‘‘/*’’ rest after successful *pattern* matching.

FNM_CASEFOLD

Ignore case distinctions in both the *pattern* and the *string*.

**RETURN VALUES**

The **fnmatch**\ () function returns zero if *string* matches the
pattern specified by *pattern*, otherwise, it returns the value
FNM_NOMATCH.

**SEE ALSO**

sh(1), glob(3), regex(3)

**STANDARDS**

The current implementation of the **fnmatch**\ () function *does not*
conform to IEEE Std 1003.2 (‘‘POSIX.2’’). Collating symbol expressions,
equivalence class expressions and character class expressions are not
supported.

**HISTORY**

The **fnmatch**\ () function first appeared in 4.4BSD.

**BUGS**

The pattern ‘*’ matches the empty string, even if FNM_PATHNAME is
specified.

BSD July 18, 2004 BSD

--------------
