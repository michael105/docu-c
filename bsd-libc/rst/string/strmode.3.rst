--------------

STRMODE(3) BSD Library Functions Manual STRMODE(3)

**NAME**

**strmode** — convert inode status information into a symbolic string

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <string.h>**

*void*

**strmode**\ (*mode_t mode*, *char *bp*);

**DESCRIPTION**

The **strmode**\ () function converts a file *mode* (the type and
permission information associated with an inode, see stat(2)) into a
symbolic string which is stored in the location referenced by *bp*. This
stored string is eleven characters in length plus a trailing NUL.

The first character is the inode type, and will be one of the following:

−

regular file

b

block special

c

character special

d

directory

l

symbolic link

p

fifo

s

socket

w

whiteout

?

unknown inode type

The next nine characters encode three sets of permissions, in three
characters each. The first three characters are the permissions for the
owner of the file, the second three for the group the file belongs to,
and the third for the ‘‘other’’, or default, set of users.

Permission checking is done as specifically as possible. If read
permission is denied to the owner of a file in the first set of
permissions, the owner of the file will not be able to read the file.
This is true even if the owner is in the file’s group and the group
permissions allow reading or the ‘‘other’’ permissions allow reading.

If the first character of the three character set is an ‘‘r’’, the file
is readable for that set of users; if a dash ‘‘−’’, it is not readable.

If the second character of the three character set is a ‘‘w’’, the file
is writable for that set of users; if a dash ‘‘−’’, it is not writable.

The third character is the first of the following characters that apply:

S

If the character is part of the owner permissions and the file is not
executable or the directory is not searchable by the owner, and the
set-user-id bit is set.

S

If the character is part of the group permissions and the file is not
executable or the directory is not searchable by the group, and the
set-group-id bit is set.

T

If the character is part of the other permissions and the file is not
executable or the directory is not searchable by others, and the
‘‘sticky’’ (S_ISVTX) bit is set.

s

If the character is part of the owner permissions and the file is
executable or the directory searchable by the owner, and the set-user-id
bit is set.

s

If the character is part of the group permissions and the file is
executable or the directory searchable by the group, and the
set-group-id bit is set.

t

If the character is part of the other permissions and the file is
executable or the directory searchable by others, and the ‘‘sticky’’
(S_ISVTX) bit is set.

x

The file is executable or the directory is searchable.

−

None of the above apply.

The last character will always be a space.

**SEE ALSO**

chmod(1), find(1), stat(2), getmode(3), setmode(3)

**HISTORY**

The **strmode**\ () function first appeared in 4.4BSD.

BSD July 28, 1994 BSD

--------------
