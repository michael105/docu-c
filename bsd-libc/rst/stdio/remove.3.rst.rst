--------------

--------------

REMOVE(3) BSD Library Functions Manual REMOVE(3)

\**NAME*\*

\**remove*\* â remove directory entry

\**LIBRARY*\*

Standard CÂ Library (libc, âlc)

\**SYNOPSIS*\*

\**#include <stdio.h>*\*

\*int\*

\**remove** (*constÂ charÂ *path*);

\**DESCRIPTION*\*

The \**remove** () function removes the file or directory specified by
\*path*.

If \*path\* specifies a directory, \**remove** (*path*) is the
equivalent of \**rmdir** (*path*). Otherwise, it is the equivalent of
\**unlink** (*path*).

\**RETURN VALUES*\*

The \**remove** () function returns the valueÂ 0 if successful;
otherwise the valueÂ â1 is returned and the global variable \*errno\* is
set to indicate the error.

\**ERRORS*\*

The \**remove** () function may fail and set \*errno\* for any of the
errors specified for the routines lstat(2), rmdir(2) or unlink(2).

\**SEE ALSO*\*

rmdir(2), unlink(2)

\**STANDARDS*\*

The \**remove** () function conforms to ISO/IEC 9899:1990 (ââISOÂ C90ââ)
and X/Open Portability Guide IssueÂ 4, VersionÂ 2 (ââXPG4.2ââ).

BSD JuneÂ 4, 1993 BSD

--------------

--------------
