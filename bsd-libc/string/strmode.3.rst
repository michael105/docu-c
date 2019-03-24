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

.. Copyright (c) 1990, 1991, 1993
..	The Regents of the University of California.  All rights reserved.
..
.. This code is derived from software contributed to Berkeley by
.. Chris Torek and the American National Standards Committee X3,
.. on Information Processing Systems.
..
.. Redistribution and use in source and binary forms, with or without
.. modification, are permitted provided that the following conditions
.. are met:
.. 1. Redistributions of source code must retain the above copyright
..    notice, this list of conditions and the following disclaimer.
.. 2. Redistributions in binary form must reproduce the above copyright
..    notice, this list of conditions and the following disclaimer in the
..    documentation and/or other materials provided with the distribution.
.. 3. Neither the name of the University nor the names of its contributors
..    may be used to endorse or promote products derived from this software
..    without specific prior written permission.
..
.. THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
.. ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
.. IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
.. ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
.. FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
.. DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
.. OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
.. HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
.. LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
.. OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
.. SUCH DAMAGE.

