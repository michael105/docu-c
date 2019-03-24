--------------

SWAPON(2) BSD System Calls Manual SWAPON(2)

**NAME**

**swapon**, **swapoff** — control devices for interleaved
paging/swapping

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <unistd.h>**

*int*

**swapon**\ (*const char *special*);

*int*

**swapoff**\ (*const char *special*);

**DESCRIPTION**

The **swapon**\ () system call makes the block device *special*
available to the system for allocation for paging and swapping. The
names of potentially available devices are known to the system and
defined at system configuration time. The size of the swap area on
*special* is calculated at the time the device is first made available
for swapping.

The **swapoff**\ () system call disables paging and swapping on the
given device. All associated swap metadata are deallocated, and the
device is made available for other purposes.

**RETURN VALUES**

If an error has occurred, a value of -1 is returned and *errno* is set
to indicate the error.

**ERRORS**

Both **swapon**\ () and **swapoff**\ () can fail if:

[ENOTDIR]

A component of the path prefix is not a directory.

[ENAMETOOLONG]

A component of a pathname exceeded 255 characters, or an entire path
name exceeded 1023 characters.

[ENOENT]

The named device does not exist.

[EACCES]

Search permission is denied for a component of the path prefix.

[ELOOP]

Too many symbolic links were encountered in translating the pathname.

[EPERM]

The caller is not the super-user.

[EFAULT]

The *special* argument points outside the process’s allocated address
space.

Additionally, **swapon**\ () can fail for the following reasons:

[ENOTBLK]

The *special* argument is not a block device.

[EBUSY]

The device specified by *special* has already been made available for
swapping

[ENXIO]

The major device number of *special* is out of range (this indicates no
device driver exists for the associated hardware).

[EIO]

An I/O error occurred while opening the swap device.

Lastly, **swapoff**\ () can fail if:

[EINVAL]

The system is not currently swapping to *special*.

[ENOMEM]

Not enough virtual memory is available to safely disable paging and
swapping to the given device.

**SEE ALSO**

config(8), swapon(8), sysctl(8)

**HISTORY**

The **swapon**\ () system call appeared in 4.0BSD. The **swapoff**\ ()
system call appeared in FreeBSD 5.0.

BSD October 4, 2013 BSD

--------------
