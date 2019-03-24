--------------

SHM_OPEN(2) BSD System Calls Manual SHM_OPEN(2)

**NAME**

**shm_open**, **shm_unlink** — shared memory object operations

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/types.h>
#include <sys/mman.h>
#include <fcntl.h>**

*int*

**shm_open**\ (*const char *path*, *int flags*, *mode_t mode*);

*int*

**shm_unlink**\ (*const char *path*);

**DESCRIPTION**

The **shm_open**\ () system call opens (or optionally creates) a POSIX
shared memory object named *path*. The *flags* argument contains a
subset of the flags used by open(2). An access mode of either O_RDONLY
or O_RDWR must be included in *flags*. The optional flags O_CREAT,
O_EXCL, and O_TRUNC may also be specified.

If O_CREAT is specified, then a new shared memory object named *path*
will be created if it does not exist. In this case, the shared memory
object is created with mode *mode* subject to the process’ umask value.
If both the O_CREAT and O_EXCL flags are specified and a shared memory
object named *path* already exists, then **shm_open**\ () will fail with
EEXIST.

Newly created objects start off with a size of zero. If an existing
shared memory object is opened with O_RDWR and the O_TRUNC flag is
specified, then the shared memory object will be truncated to a size of
zero. The size of the object can be adjusted via ftruncate(2) and
queried via fstat(2).

The new descriptor is set to close during execve(2) system calls; see
close(2) and fcntl(2).

As a FreeBSD extension, the constant SHM_ANON may be used for the *path*
argument to **shm_open**\ (). In this case, an anonymous, unnamed shared
memory object is created. Since the object has no name, it cannot be
removed via a subsequent call to **shm_unlink**\ (). Instead, the shared
memory object will be garbage collected when the last reference to the
shared memory object is removed. The shared memory object may be shared
with other processes by sharing the file descriptor via fork(2) or
sendmsg(2). Attempting to open an anonymous shared memory object with
O_RDONLY will fail with EINVAL. All other flags are ignored.

The **shm_unlink**\ () system call removes a shared memory object named
*path*.

**RETURN VALUES**

If successful, **shm_open**\ () returns a non-negative integer, and
**shm_unlink**\ () returns zero. Both functions return -1 on failure,
and set *errno* to indicate the error.

**COMPATIBILITY**

The *path* argument does not necessarily represent a pathname (although
it does in most other implementations). Two processes opening the same
*path* are guaranteed to access the same shared memory object if and
only if *path* begins with a slash (‘/’) character.

Only the O_RDONLY, O_RDWR, O_CREAT, O_EXCL, and O_TRUNC flags may be
used in portable programs.

POSIX specifications state that the result of using open(2), read(2), or
write(2) on a shared memory object, or on the descriptor returned by
**shm_open**\ (), is undefined. However, the FreeBSD kernel
implementation explicitly includes support for read(2) and write(2).

FreeBSD also supports zero-copy transmission of data from shared memory
objects with sendfile(2).

Neither shared memory objects nor their contents persist across reboots.

Writes do not extend shared memory objects, so ftruncate(2) must be
called before any data can be written. See *EXAMPLES*.

**EXAMPLES**

This example fails without the call to ftruncate(2):

| uint8_t buffer[getpagesize()];
| ssize_t len;
| int fd;

| fd = shm_open(SHM_ANON, O_RDWR \| O_CREAT, 0600);
| if (fd < 0)
| err(EX_OSERR, "%s: shm_open", \__func__);
| if (ftruncate(fd, getpagesize()) < 0)
| err(EX_IOERR, "%s: ftruncate", \__func__);
| len = pwrite(fd, buffer, getpagesize(), 0);
| if (len < 0)
| err(EX_IOERR, "%s: pwrite", \__func__);
| if (len != getpagesize())
| errx(EX_IOERR, "%s: pwrite length mismatch", \__func__);

**ERRORS**

**shm_open**\ () fails with these error codes for these conditions:

[EINVAL]

A flag other than O_RDONLY, O_RDWR, O_CREAT, O_EXCL, or O_TRUNC was
included in *flags*.

[EMFILE]

The process has already reached its limit for open file descriptors.

[ENFILE]

The system file table is full.

[EINVAL]

O_RDONLY was specified while creating an anonymous shared memory object
via SHM_ANON.

[EFAULT]

The *path* argument points outside the process’ allocated address space.

[ENAMETOOLONG]

The entire pathname exceeded 1023 characters.

[EINVAL]

The *path* does not begin with a slash (‘/’) character.

[ENOENT]

O_CREAT is specified and the named shared memory object does not exist.

[EEXIST]

O_CREAT and O_EXCL are specified and the named shared memory object does
exist.

[EACCES]

The required permissions (for reading or reading and writing) are
denied.

**shm_unlink**\ () fails with these error codes for these conditions:

[EFAULT]

The *path* argument points outside the process’ allocated address space.

[ENAMETOOLONG]

The entire pathname exceeded 1023 characters.

[ENOENT]

The named shared memory object does not exist.

[EACCES]

The required permissions are denied. **shm_unlink**\ () requires write
permission to the shared memory object.

**SEE ALSO**

close(2), fstat(2), ftruncate(2), mmap(2), munmap(2), sendfile(2)

**STANDARDS**

The **shm_open**\ () and **shm_unlink**\ () functions are believed to
conform to IEEE Std 1003.1b-1993 (‘‘POSIX.1’’).

**HISTORY**

The **shm_open**\ () and **shm_unlink**\ () functions first appeared in
FreeBSD 4.3. The functions were reimplemented as system calls using
shared memory objects directly rather than files in FreeBSD 8.0.

**AUTHORS**

Garrett A. Wollman <*wollman@FreeBSD.org*> (C library support and this
manual page)

Matthew Dillon <*dillon@FreeBSD.org*> (MAP_NOSYNC)

BSD January 20, 2017 BSD

--------------
