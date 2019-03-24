--------------

NFSSVC(2) BSD System Calls Manual NFSSVC(2)

**NAME**

**nfssvc** — NFS services

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/param.h>
#include <sys/mount.h>
#include <sys/time.h>
#include <nfs/rpcv2.h>
#include <nfsserver/nfs.h>
#include <unistd.h>**

*int*

**nfssvc**\ (*int flags*, *void *argstructp*);

**DESCRIPTION**

The **nfssvc**\ () system call is used by the NFS daemons to pass
information into and out of the kernel and also to enter the kernel as a
server daemon. The *flags* argument consists of several bits that show
what action is to be taken once in the kernel and the *argstructp*
points to one of three structures depending on which bits are set in
flags.

On the client side, nfsiod(8) calls **nfssvc**\ () with the *flags*
argument set to NFSSVC_BIOD and *argstructp* set to NULL to enter the
kernel as a block I/O server daemon. For NQNFS, mount_nfs(8) calls
**nfssvc**\ () with the NFSSVC_MNTD flag, optionally or’d with the flags
NFSSVC_GOTAUTH and NFSSVC_AUTHINFAIL along with a pointer to a

struct nfsd_cargs {

+---------+---------+---------+---------+---------+---------+---------+
|         | char    |         | \*ncd_d |         | /\*     |         |
|         |         |         | irp;    |         | Mount   |         |
|         |         |         |         |         | dir     |         |
|         |         |         |         |         | path    |         |
|         |         |         |         |         | \*/     |         |
+---------+---------+---------+---------+---------+---------+---------+
|         | uid_t   |         | ncd_aut |         | /\*     |         |
|         |         |         | huid;   |         | Effecti |         |
|         |         |         |         |         | ve      |         |
|         |         |         |         |         | uid \*/ |         |
+---------+---------+---------+---------+---------+---------+---------+
|         | int     |         | ncd_aut |         | /\*     |         |
|         |         |         | htype;  |         | Type of |         |
|         |         |         |         |         | authent |         |
|         |         |         |         |         | icator  |         |
|         |         |         |         |         | \*/     |         |
+---------+---------+---------+---------+---------+---------+---------+
|         | int     |         | ncd_aut |         | /\*     |         |
|         |         |         | hlen;   |         | Length  |         |
|         |         |         |         |         | of      |         |
|         |         |         |         |         | authent |         |
|         |         |         |         |         | icator  |         |
|         |         |         |         |         | string  |         |
|         |         |         |         |         | \*/     |         |
+---------+---------+---------+---------+---------+---------+---------+
|         | u_char  |         | \*ncd_a |         | /\*     |         |
|         |         |         | uthstr; |         | Authent |         |
|         |         |         |         |         | icator  |         |
|         |         |         |         |         | string  |         |
|         |         |         |         |         | \*/     |         |
+---------+---------+---------+---------+---------+---------+---------+
|         | int     |         | ncd_ver |         | /\* and |         |
|         |         |         | flen;   |         | the     |         |
|         |         |         |         |         | verifie |         |
|         |         |         |         |         | r       |         |
|         |         |         |         |         | \*/     |         |
+---------+---------+---------+---------+---------+---------+---------+
|         | u_char  |         | \*ncd_v |         |         |         |
|         |         |         | erfstr; |         |         |         |
+---------+---------+---------+---------+---------+---------+---------+
|         | NFSKERB |         | ncd_key |         | /\*     |         |
|         | KEY_T   |         | ;       |         | Session |         |
|         |         |         |         |         | key \*/ |         |
+---------+---------+---------+---------+---------+---------+---------+

};

structure. The initial call has only the NFSSVC_MNTD flag set to specify
service for the mount point. If the mount point is using Kerberos, then
the mount_nfs(8) utility will return from **nfssvc**\ () with *errno* ==
ENEEDAUTH whenever the client side requires an ‘‘rcmd’’ authentication
ticket for the user. The mount_nfs(8) utility will attempt to get the
Kerberos ticket, and if successful will call **nfssvc**\ () with the
flags NFSSVC_MNTD and NFSSVC_GOTAUTH after filling the ticket into the
ncd_authstr field and setting the ncd_authlen and ncd_authtype fields of
the nfsd_cargs structure. If mount_nfs(8) failed to get the ticket,
**nfssvc**\ () will be called with the flags NFSSVC_MNTD, NFSSVC_GOTAUTH
and NFSSVC_AUTHINFAIL to denote a failed authentication attempt.

On the server side, **nfssvc**\ () is called with the flag NFSSVC_NFSD
and a pointer to a

struct nfsd_srvargs {

+---------+---------+---------+---------+---------+---------+---------+
|         | struct  |         | \*nsd_n |         | /\*     |         |
|         | nfsd    |         | fsd;    |         | Pointer |         |
|         |         |         |         |         | to in   |         |
|         |         |         |         |         | kernel  |         |
|         |         |         |         |         | nfsd    |         |
|         |         |         |         |         | struct  |         |
|         |         |         |         |         | \*/     |         |
+---------+---------+---------+---------+---------+---------+---------+
|         | uid_t   |         | nsd_uid |         | /\*     |         |
|         |         |         | ;       |         | Effecti |         |
|         |         |         |         |         | ve      |         |
|         |         |         |         |         | uid     |         |
|         |         |         |         |         | mapped  |         |
|         |         |         |         |         | to cred |         |
|         |         |         |         |         | \*/     |         |
+---------+---------+---------+---------+---------+---------+---------+
|         | uint32_ |         | nsd_had |         | /\* Ip  |         |
|         | t       |         | dr;     |         | address |         |
|         |         |         |         |         | of      |         |
|         |         |         |         |         | client  |         |
|         |         |         |         |         | \*/     |         |
+---------+---------+---------+---------+---------+---------+---------+
|         | struct  |         | nsd_cr; |         | /\*     |         |
|         | ucred   |         |         |         | Cred.   |         |
|         |         |         |         |         | uid     |         |
|         |         |         |         |         | maps to |         |
|         |         |         |         |         | \*/     |         |
+---------+---------+---------+---------+---------+---------+---------+
|         | int     |         | nsd_aut |         | /\*     |         |
|         |         |         | hlen;   |         | Length  |         |
|         |         |         |         |         | of auth |         |
|         |         |         |         |         | string  |         |
|         |         |         |         |         | (ret)   |         |
|         |         |         |         |         | \*/     |         |
+---------+---------+---------+---------+---------+---------+---------+
|         | u_char  |         | \*nsd_a |         | /\*     |         |
|         |         |         | uthstr; |         | Auth    |         |
|         |         |         |         |         | string  |         |
|         |         |         |         |         | (ret)   |         |
|         |         |         |         |         | \*/     |         |
+---------+---------+---------+---------+---------+---------+---------+
|         | int     |         | nsd_ver |         | /\* and |         |
|         |         |         | flen;   |         | the     |         |
|         |         |         |         |         | verifie |         |
|         |         |         |         |         | r       |         |
|         |         |         |         |         | \*/     |         |
+---------+---------+---------+---------+---------+---------+---------+
|         | u_char  |         | \*nsd_v |         |         |         |
|         |         |         | erfstr; |         |         |         |
+---------+---------+---------+---------+---------+---------+---------+
|         | struct  |         | nsd_tim |         | /\*     |         |
|         | timeval |         | estamp; |         | timesta |         |
|         |         |         |         |         | mp      |         |
|         |         |         |         |         | from    |         |
|         |         |         |         |         | verifie |         |
|         |         |         |         |         | r       |         |
|         |         |         |         |         | \*/     |         |
+---------+---------+---------+---------+---------+---------+---------+
|         | uint32_ |         | nsd_ttl |         | /\*     |         |
|         | t       |         | ;       |         | credent |         |
|         |         |         |         |         | ial     |         |
|         |         |         |         |         | ttl     |         |
|         |         |         |         |         | (sec)   |         |
|         |         |         |         |         | \*/     |         |
+---------+---------+---------+---------+---------+---------+---------+
|         | NFSKERB |         | nsd_key |         | /\*     |         |
|         | KEY_T   |         | ;       |         | Session |         |
|         |         |         |         |         | key \*/ |         |
+---------+---------+---------+---------+---------+---------+---------+

};

to enter the kernel as an nfsd(8) daemon. Whenever an nfsd(8) daemon
receives a Kerberos authentication ticket, it will return from
**nfssvc**\ () with *errno* == ENEEDAUTH. The nfsd(8) utility will
attempt to authenticate the ticket and generate a set of credentials on
the server for the ‘‘user id’’ specified in the field nsd_uid. This is
done by first authenticating the Kerberos ticket and then mapping the
Kerberos principal to a local name and getting a set of credentials for
that user via getpwnam(3) and getgrouplist(3). If successful, the
nfsd(8) utility will call **nfssvc**\ () with the NFSSVC_NFSD and
NFSSVC_AUTHIN flags set to pass the credential mapping in nsd_cr into
the kernel to be cached on the server socket for that client. If the
authentication failed, nfsd(8) calls **nfssvc**\ () with the flags
NFSSVC_NFSD and NFSSVC_AUTHINFAIL to denote an authentication failure.

The master nfsd(8) server daemon calls **nfssvc**\ () with the flag
NFSSVC_ADDSOCK and a pointer to a

struct nfsd_args {

+-------------+-------------+-------------+-------------+-------------+
|             | int         | sock;       | /\* Socket  |             |
|             |             |             | to serve    |             |
|             |             |             | \*/         |             |
+-------------+-------------+-------------+-------------+-------------+
|             | caddr_t     | name;       | /\* Client  |             |
|             |             |             | address for |             |
|             |             |             | connection  |             |
|             |             |             | based       |             |
|             |             |             | sockets \*/ |             |
+-------------+-------------+-------------+-------------+-------------+
|             | int         | namelen;/\* |             |             |
|             |             | Length of   |             |             |
|             |             | name \*/    |             |             |
+-------------+-------------+-------------+-------------+-------------+

};

to pass a server side NFS socket into the kernel for servicing by the
nfsd(8) daemons.

**RETURN VALUES**

Normally **nfssvc**\ () does not return unless the server is terminated
by a signal when a value of 0 is returned. Otherwise, -1 is returned and
the global variable *errno* is set to specify the error.

| **ERRORS**
| [ENEEDAUTH]

This special error value is really used for authentication support,
particularly Kerberos, as explained above.

[EPERM]

The caller is not the super-user.

**SEE ALSO**

mount_nfs(8), nfsd(8), nfsiod(8)

**HISTORY**

The **nfssvc**\ () system call first appeared in 4.4BSD.

**BUGS**

The **nfssvc**\ () system call is designed specifically for the NFS
support daemons and as such is specific to their requirements. It should
really return values to indicate the need for authentication support,
since ENEEDAUTH is not really an error. Several fields of the argument
structures are assumed to be valid and sometimes to be unchanged from a
previous call, such that **nfssvc**\ () must be used with extreme care.

BSD June 9, 1993 BSD

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

