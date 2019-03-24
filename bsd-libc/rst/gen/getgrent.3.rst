--------------

GETGRENT(3) BSD Library Functions Manual GETGRENT(3)

**NAME**

**getgrent**, **getgrent_r**, **getgrnam**, **getgrnam_r**,
**getgrgid**, **getgrgid_r**, **setgroupent**, **setgrent**,
**endgrent** — group database operations

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <grp.h>**

*struct group \**

**getgrent**\ (*void*);

*int*

**getgrent_r**\ (*struct group *grp*, *char *buffer*, *size_t bufsize*,
*struct group **result*);

*struct group \**

**getgrnam**\ (*const char *name*);

*int*

**getgrnam_r**\ (*const char *name*, *struct group *grp*,
*char *buffer*, *size_t bufsize*, *struct group **result*);

*struct group \**

**getgrgid**\ (*gid_t gid*);

*int*

**getgrgid_r**\ (*gid_t gid*, *struct group *grp*, *char *buffer*,
*size_t bufsize*, *struct group **result*);

*int*

**setgroupent**\ (*int stayopen*);

*void*

**setgrent**\ (*void*);

*void*

**endgrent**\ (*void*);

**DESCRIPTION**

These functions operate on the group database file */etc/group* which is
described in group(5). Each line of the database is defined by the
structure *group* found in the include file <*grp.h*>:

struct group {

+-----------+-----------+-----------+-----------+-----------+-----------+
|           | char      | \*gr_name |           | /\* group |           |
|           |           | ;         |           | name \*/  |           |
+-----------+-----------+-----------+-----------+-----------+-----------+
|           | char      | \*gr_pass |           | /\* group |           |
|           |           | wd;       |           | password  |           |
|           |           |           |           | \*/       |           |
+-----------+-----------+-----------+-----------+-----------+-----------+
|           | gid_t     | gr_gid;   |           | /\* group |           |
|           |           |           |           | id \*/    |           |
+-----------+-----------+-----------+-----------+-----------+-----------+
|           | char      | \**gr_mem |           | /\* group |           |
|           |           | ;         |           | members   |           |
|           |           |           |           | \*/       |           |
+-----------+-----------+-----------+-----------+-----------+-----------+

};

The functions **getgrnam**\ () and **getgrgid**\ () search the group
database for the given group name pointed to by *name* or the group id
pointed to by *gid*, respectively, returning the first one encountered.
Identical group names or group gids may result in undefined behavior.

The **getgrent**\ () function sequentially reads the group database and
is intended for programs that wish to step through the complete list of
groups.

The functions **getgrent_r**\ (), **getgrnam_r**\ (), and
**getgrgid_r**\ () are thread-safe versions of **getgrent**\ (),
**getgrnam**\ (), and **getgrgid**\ (), respectively. The caller must
provide storage for the results of the search in the *grp*, *buffer*,
*bufsize*, and *result* arguments. When these functions are successful,
the *grp* argument will be filled-in, and a pointer to that argument
will be stored in *result*. If an entry is not found or an error occurs,
*result* will be set to NULL.

These functions will open the group file for reading, if necessary.

The **setgroupent**\ () function opens the file, or rewinds it if it is
already open. If *stayopen* is non-zero, file descriptors are left open,
significantly speeding functions subsequent calls. This functionality is
unnecessary for **getgrent**\ () as it does not close its file
descriptors by default. It should also be noted that it is dangerous for
long-running programs to use this functionality as the group file may be
updated.

The **setgrent**\ () function is identical to **setgroupent**\ () with
an argument of zero.

The **endgrent**\ () function closes any open files.

**RETURN VALUES**

The functions **getgrent**\ (), **getgrnam**\ (), and **getgrgid**\ (),
return a pointer to a group structure on success or NULL if the entry is
not found or if an error occurs. If an error does occur, *errno* will be
set. Note that programs must explicitly set *errno* to zero before
calling any of these functions if they need to distinguish between a
non-existent entry and an error. The functions **getgrent_r**\ (),
**getgrnam_r**\ (), and **getgrgid_r**\ () return 0 if no error
occurred, or an error number to indicate failure. It is not an error if
a matching entry is not found. (Thus, if *result* is set to NULL and the
return value is 0, no matching entry exists.)

The function **setgroupent**\ () returns the value 1 if successful,
otherwise the value 0 is returned. The functions **endgrent**\ (),
**setgrent**\ () and **setgrfile**\ () have no return value.

| **FILES**
| /etc/group

group database file

**COMPATIBILITY**

The historic function **setgrfile**\ (), which allowed the specification
of alternate password databases, has been deprecated and is no longer
available.

**SEE ALSO**

getpwent(3), group(5), nsswitch.conf(5), yp(8)

**STANDARDS**

The **getgrent**\ (), **getgrnam**\ (), **getgrnam_r**\ (),
**getgrgid**\ (), **getgrgid_r**\ () and **endgrent**\ () functions
conform to ISO/IEC 9945-1:1996 (‘‘POSIX.1’’). The **setgrent**\ ()
function differs from that standard in that its return type is *int*
rather than *void*.

**HISTORY**

The functions **endgrent**\ (), **getgrent**\ (), **getgrnam**\ (),
**getgrgid**\ (), and **setgrent**\ () appeared in Version 7 AT&T UNIX.
The functions **setgrfile**\ () and **setgroupent**\ () appeared in
4.3BSD−Reno. The functions **getgrent_r**\ (), **getgrnam_r**\ (), and
**getgrgid_r**\ () appeared in FreeBSD 5.1.

**BUGS**

The functions **getgrent**\ (), **getgrnam**\ (), **getgrgid**\ (),
**setgroupent**\ () and **setgrent**\ () leave their results in an
internal static object and return a pointer to that object. Subsequent
calls to the same function will modify the same object.

The functions **getgrent**\ (), **getgrent_r**\ (), **endgrent**\ (),
**setgroupent**\ (), and **setgrent**\ () are fairly useless in a
networked environment and should be avoided, if possible. The
**getgrent**\ () and **getgrent_r**\ () functions make no attempt to
suppress duplicate information if multiple sources are specified in
nsswitch.conf(5).

BSD July 31, 2016 BSD

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

