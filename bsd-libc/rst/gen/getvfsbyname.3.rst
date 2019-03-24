--------------

GETVFSBYNAME(3) BSD Library Functions Manual GETVFSBYNAME(3)

**NAME**

**getvfsbyname** — get information about a file system

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/param.h>
#include <sys/mount.h>**

*int*

**getvfsbyname**\ (*const char *name*, *struct xvfsconf *vfc*);

**DESCRIPTION**

The **getvfsbyname**\ () function provides access to information about a
file system module that is configured in the kernel. If successful, the
requested file system *xvfsconf* is returned in the location pointed to
by *vfc*. The fields in a ‘‘struct xvfsconf’’ are defined as follows:

vfc_name

the name of the file system

vfc_typenum

the file system type number assigned by the kernel

vfc_refcount

the number of active mount points using the file system

vfc_flags

flag bits, as described below

The flags are defined as follows:

VFCF_STATIC

statically compiled into kernel

VFCF_NETWORK

may get data over the network

VFCF_READONLY

writes are not implemented

VFCF_SYNTHETIC

data does not represent real files

VFCF_LOOPBACK

aliases some other mounted FS

VFCF_UNICODE

stores file names as Unicode

VFCF_JAIL

can be mounted from within a jail if *allow.mount* and
*allow.mount.<vfc_name>* jail parameters are set

VFCF_DELEGADMIN

supports delegated administration if *vfs.usermount* sysctl is set to 1

**RETURN VALUES**

The **getvfsbyname**\ () function returns the value 0 if successful;
otherwise the value −1 is returned and the global variable *errno* is
set to indicate the error.

**ERRORS**

The following errors may be reported:

[ENOENT]

The *name* argument specifies a file system that is unknown or not
configured in the kernel.

**SEE ALSO**

jail(2), mount(2), sysctl(3), jail(8), mount(8), sysctl(8)

**HISTORY**

A variant of the **getvfsbyname**\ () function first appeared in
FreeBSD 2.0.

BSD August 16, 2018 BSD

--------------
