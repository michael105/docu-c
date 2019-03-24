--------------

STATFS(2) BSD System Calls Manual STATFS(2)

**NAME**

**statfs** — get file system statistics

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/param.h>
#include <sys/mount.h>**

*int*

**statfs**\ (*const char *path*, *struct statfs *buf*);

*int*

**fstatfs**\ (*int fd*, *struct statfs *buf*);

**DESCRIPTION**

The **statfs**\ () system call returns information about a mounted file
system. The *path* argument is the path name of any file within the
mounted file system. The *buf* argument is a pointer to a *statfs*
structure defined as follows:

typedef struct fsid { int32_t val[2]; } fsid_t; /\* file system id type
\*/

| /\*
| \* filesystem statistics
| \*/

+--------+--------+--------+--------+--------+--------+--------+--------+
|        | #defin | MFSNAM |        | 16     |        | /\*    |        |
|        | e      | ELEN   |        |        |        | length |        |
|        |        |        |        |        |        | of     |        |
|        |        |        |        |        |        | type   |        |
|        |        |        |        |        |        | name   |        |
|        |        |        |        |        |        | includ |        |
|        |        |        |        |        |        | ing    |        |
|        |        |        |        |        |        | null   |        |
|        |        |        |        |        |        | \*/    |        |
+--------+--------+--------+--------+--------+--------+--------+--------+
|        | #defin | MNAMEL |        | 1024   |        | /\*    |        |
|        | e      | EN     |        |        |        | size   |        |
|        |        |        |        |        |        | of     |        |
|        |        |        |        |        |        | on/fro |        |
|        |        |        |        |        |        | m      |        |
|        |        |        |        |        |        | name   |        |
|        |        |        |        |        |        | bufs   |        |
|        |        |        |        |        |        | \*/    |        |
+--------+--------+--------+--------+--------+--------+--------+--------+
|        | #defin | STATFS |        | 0x2014 |        | /\*    |        |
|        | e      | _VERSI |        | 0518   |        | curren |        |
|        |        | ON     |        |        |        | t      |        |
|        |        |        |        |        |        | versio |        |
|        |        |        |        |        |        | n      |        |
|        |        |        |        |        |        | number |        |
|        |        |        |        |        |        | \*/    |        |
+--------+--------+--------+--------+--------+--------+--------+--------+

struct statfs {

+---------+---------+---------+---------+---------+---------+---------+
|         | uint32_ |         |         |         | /\*     |         |
|         | t       |         |         |         | structu |         |
|         | f_versi |         |         |         | re      |         |
|         | on;     |         |         |         | version |         |
|         |         |         |         |         | number  |         |
|         |         |         |         |         | \*/     |         |
+---------+---------+---------+---------+---------+---------+---------+
|         | uint32_ |         |         |         | /\*     |         |
|         | t       |         |         |         | type of |         |
|         | f_type; |         |         |         | filesys |         |
|         |         |         |         |         | tem     |         |
|         |         |         |         |         | \*/     |         |
+---------+---------+---------+---------+---------+---------+---------+
|         | uint64_ |         |         |         | /\*     |         |
|         | t       |         |         |         | copy of |         |
|         | f_flags |         |         |         | mount   |         |
|         | ;       |         |         |         | exporte |         |
|         |         |         |         |         | d       |         |
|         |         |         |         |         | flags   |         |
|         |         |         |         |         | \*/     |         |
+---------+---------+---------+---------+---------+---------+---------+
|         | uint64_ |         |         |         | /\*     |         |
|         | t       |         |         |         | filesys |         |
|         | f_bsize |         |         |         | tem     |         |
|         | ;       |         |         |         | fragmen |         |
|         |         |         |         |         | t       |         |
|         |         |         |         |         | size    |         |
|         |         |         |         |         | \*/     |         |
+---------+---------+---------+---------+---------+---------+---------+
|         | uint64_ |         |         |         | /\*     |         |
|         | t       |         |         |         | optimal |         |
|         | f_iosiz |         |         |         | transfe |         |
|         | e;      |         |         |         | r       |         |
|         |         |         |         |         | block   |         |
|         |         |         |         |         | size    |         |
|         |         |         |         |         | \*/     |         |
+---------+---------+---------+---------+---------+---------+---------+
|         | uint64_ |         |         |         | /\*     |         |
|         | t       |         |         |         | total   |         |
|         | f_block |         |         |         | data    |         |
|         | s;      |         |         |         | blocks  |         |
|         |         |         |         |         | in      |         |
|         |         |         |         |         | filesys |         |
|         |         |         |         |         | tem     |         |
|         |         |         |         |         | \*/     |         |
+---------+---------+---------+---------+---------+---------+---------+
|         | uint64_ |         |         |         | /\*     |         |
|         | t       |         |         |         | free    |         |
|         | f_bfree |         |         |         | blocks  |         |
|         | ;       |         |         |         | in      |         |
|         |         |         |         |         | filesys |         |
|         |         |         |         |         | tem     |         |
|         |         |         |         |         | \*/     |         |
+---------+---------+---------+---------+---------+---------+---------+
|         | int64_t | f_bavai |         |         | /\*     |         |
|         |         | l;      |         |         | free    |         |
|         |         |         |         |         | blocks  |         |
|         |         |         |         |         | avail   |         |
|         |         |         |         |         | to      |         |
|         |         |         |         |         | non-sup |         |
|         |         |         |         |         | eruser  |         |
|         |         |         |         |         | \*/     |         |
+---------+---------+---------+---------+---------+---------+---------+
|         | uint64_ |         |         |         | /\*     |         |
|         | t       |         |         |         | total   |         |
|         | f_files |         |         |         | file    |         |
|         | ;       |         |         |         | nodes   |         |
|         |         |         |         |         | in      |         |
|         |         |         |         |         | filesys |         |
|         |         |         |         |         | tem     |         |
|         |         |         |         |         | \*/     |         |
+---------+---------+---------+---------+---------+---------+---------+
|         | int64_t | f_ffree |         |         | /\*     |         |
|         |         | ;       |         |         | free    |         |
|         |         |         |         |         | nodes   |         |
|         |         |         |         |         | avail   |         |
|         |         |         |         |         | to      |         |
|         |         |         |         |         | non-sup |         |
|         |         |         |         |         | eruser  |         |
|         |         |         |         |         | \*/     |         |
+---------+---------+---------+---------+---------+---------+---------+
|         | uint64_ |         |         |         | /\*     |         |
|         | t       |         |         |         | count   |         |
|         | f_syncw |         |         |         | of sync |         |
|         | rites;  |         |         |         | writes  |         |
|         |         |         |         |         | since   |         |
|         |         |         |         |         | mount   |         |
|         |         |         |         |         | \*/     |         |
+---------+---------+---------+---------+---------+---------+---------+
|         | uint64_ |         |         |         | /\*     |         |
|         | t       |         |         |         | count   |         |
|         | f_async |         |         |         | of      |         |
|         | writes; |         |         |         | async   |         |
|         |         |         |         |         | writes  |         |
|         |         |         |         |         | since   |         |
|         |         |         |         |         | mount   |         |
|         |         |         |         |         | \*/     |         |
+---------+---------+---------+---------+---------+---------+---------+
|         | uint64_ |         |         |         | /\*     |         |
|         | t       |         |         |         | count   |         |
|         | f_syncr |         |         |         | of sync |         |
|         | eads;   |         |         |         | reads   |         |
|         |         |         |         |         | since   |         |
|         |         |         |         |         | mount   |         |
|         |         |         |         |         | \*/     |         |
+---------+---------+---------+---------+---------+---------+---------+
|         | uint64_ |         |         |         | /\*     |         |
|         | t       |         |         |         | count   |         |
|         | f_async |         |         |         | of      |         |
|         | reads;  |         |         |         | async   |         |
|         |         |         |         |         | reads   |         |
|         |         |         |         |         | since   |         |
|         |         |         |         |         | mount   |         |
|         |         |         |         |         | \*/     |         |
+---------+---------+---------+---------+---------+---------+---------+
|         | uint64_ |         |         |         | /\*     |         |
|         | t       |         |         |         | unused  |         |
|         | f_spare |         |         |         | spare   |         |
|         | [10];   |         |         |         | \*/     |         |
+---------+---------+---------+---------+---------+---------+---------+
|         | uint32_ |         |         |         | /\*     |         |
|         | t       |         |         |         | maximum |         |
|         | f_namem |         |         |         | filenam |         |
|         | ax;     |         |         |         | e       |         |
|         |         |         |         |         | length  |         |
|         |         |         |         |         | \*/     |         |
+---------+---------+---------+---------+---------+---------+---------+
|         | uid_t   | f_owner |         |         | /\*     |         |
|         |         | ;       |         |         | user    |         |
|         |         |         |         |         | that    |         |
|         |         |         |         |         | mounted |         |
|         |         |         |         |         | the     |         |
|         |         |         |         |         | filesys |         |
|         |         |         |         |         | tem     |         |
|         |         |         |         |         | \*/     |         |
+---------+---------+---------+---------+---------+---------+---------+
|         | fsid_t  | f_fsid; |         |         | /\*     |         |
|         |         |         |         |         | filesys |         |
|         |         |         |         |         | tem     |         |
|         |         |         |         |         | id \*/  |         |
+---------+---------+---------+---------+---------+---------+---------+
|         | char    | f_chars |         |         | /\*     |         |
|         |         | pare[80 |         |         | spare   |         |
|         |         | ];      |         |         | string  |         |
|         |         |         |         |         | space   |         |
|         |         |         |         |         | \*/     |         |
+---------+---------+---------+---------+---------+---------+---------+
|         | char    | f_fstyp |         |         |         |         |
|         |         | ename[M |         |         |         |         |
|         |         | FSNAMEL |         |         |         |         |
|         |         | EN];    |         |         |         |         |
|         |         | /\*     |         |         |         |         |
|         |         | filesys |         |         |         |         |
|         |         | tem     |         |         |         |         |
|         |         | type    |         |         |         |         |
|         |         | name    |         |         |         |         |
|         |         | \*/     |         |         |         |         |
+---------+---------+---------+---------+---------+---------+---------+
|         | char    | f_mntfr |         |         |         |         |
|         |         | omname[ |         |         |         |         |
|         |         | MNAMELE |         |         |         |         |
|         |         | N];     |         |         |         |         |
|         |         | /\*     |         |         |         |         |
|         |         | mounted |         |         |         |         |
|         |         | filesys |         |         |         |         |
|         |         | tem     |         |         |         |         |
|         |         | \*/     |         |         |         |         |
+---------+---------+---------+---------+---------+---------+---------+
|         | char    | f_mnton |         |         |         |         |
|         |         | name[MN |         |         |         |         |
|         |         | AMELEN] |         |         |         |         |
|         |         | ;       |         |         |         |         |
|         |         | /\*     |         |         |         |         |
|         |         | directo |         |         |         |         |
|         |         | ry      |         |         |         |         |
|         |         | on      |         |         |         |         |
|         |         | which   |         |         |         |         |
|         |         | mounted |         |         |         |         |
|         |         | \*/     |         |         |         |         |
+---------+---------+---------+---------+---------+---------+---------+

};

The flags that may be returned include:

MNT_RDONLY

The file system is mounted read-only; Even the super-user may not write
on it.

MNT_NOEXEC

Files may not be executed from the file system.

MNT_NOSUID

Setuid and setgid bits on files are not honored when they are executed.

MNT_SYNCHRONOUS

All I/O to the file system is done synchronously.

MNT_ASYNC

No file system I/O is done synchronously.

MNT_SOFTDEP

Soft updates being done (see ffs(7)).

MNT_GJOURNAL

Journaling with gjournal is enabled (see gjournal(8)).

MNT_SUIDDIR

Special handling of SUID bit on directories.

MNT_UNION

Union with underlying file system.

MNT_NOSYMFOLLOW

Symbolic links are not followed.

MNT_NOCLUSTERR

Read clustering is disabled.

MNT_NOCLUSTERW

Write clustering is disabled.

MNT_MULTILABEL

Mandatory Access Control (MAC) support for individual objects (see
mac(4)).

MNT_ACLS

Access Control List (ACL) support enabled.

MNT_LOCAL

The file system resides locally.

MNT_QUOTA

The file system has quotas enabled on it.

MNT_ROOTFS

Identifies the root file system.

MNT_EXRDONLY

The file system is exported read-only.

MNT_NOATIME

Updating of file access times is disabled.

MNT_USER

The file system has been mounted by a user.

MNT_EXPORTED

The file system is exported for both reading and writing.

MNT_DEFEXPORTED

The file system is exported for both reading and writing to any Internet
host.

MNT_EXPORTANON

The file system maps all remote accesses to the anonymous user.

MNT_EXKERB

The file system is exported with Kerberos uid mapping.

MNT_EXPUBLIC

The file system is exported publicly (WebNFS).

Fields that are undefined for a particular file system are set to -1.
The **fstatfs**\ () system call returns the same information about an
open file referenced by descriptor *fd*.

**RETURN VALUES**

Upon successful completion, the value 0 is returned; otherwise the
value −1 is returned and the global variable *errno* is set to indicate
the error.

**ERRORS**

The **statfs**\ () system call fails if one or more of the following are
true:

[ENOTDIR]

A component of the path prefix of *path* is not a directory.

[ENAMETOOLONG]

The length of a component of *path* exceeds 255 characters, or the
length of *path* exceeds 1023 characters.

[ENOENT]

The file referred to by *path* does not exist.

[EACCES]

Search permission is denied for a component of the path prefix of
*path*.

[ELOOP]

Too many symbolic links were encountered in translating *path*.

[EFAULT]

The *buf* or *path* argument points to an invalid address.

[EIO]

An I/O error occurred while reading from or writing to the file system.

The **fstatfs**\ () system call fails if one or more of the following
are true:

[EBADF]

The *fd* argument is not a valid open file descriptor.

[EFAULT]

The *buf* argument points to an invalid address.

[EIO]

An I/O error occurred while reading from or writing to the file system.

**SEE ALSO**

fhstatfs(2), getfsstat(2)

**HISTORY**

The **statfs**\ () system call first appeared in 4.4BSD.

BSD February 13, 2017 BSD

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

