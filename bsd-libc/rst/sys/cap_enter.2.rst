--------------

CAP_ENTER(2) BSD System Calls Manual CAP_ENTER(2)

**NAME**

**cap_enter**, **cap_getmode** — Capability mode system calls

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/capsicum.h>**

*int*

**cap_enter**\ (*void*);

*int*

**cap_getmode**\ (*u_int *modep*);

**DESCRIPTION**

**cap_enter**\ () places the current process into capability mode, a
mode of execution in which processes may only issue system calls
operating on file descriptors or reading limited global system state.
Access to global name spaces, such as file system or IPC name spaces, is
prevented. If the process is already in a capability mode sandbox, the
system call is a no-op. Future process descendants created with fork(2)
or pdfork(2) will be placed in capability mode from inception.

When combined with cap_rights_limit(2), cap_ioctls_limit(2),
cap_fcntls_limit(2), **cap_enter**\ () may be used to create
kernel-enforced sandboxes in which appropriately-crafted applications or
application components may be run.

**cap_getmode**\ () returns a flag indicating whether or not the process
is in a capability mode sandbox.

**RUN-TIME SETTINGS**

If the kern.trap_enotcap sysctl MIB is set to a non-zero value, then for
any process executing in a capability mode sandbox, any syscall which
results in either an ENOTCAPABLE or ECAPMODE error also generates the
synchronous SIGTRAP signal to the thread on the syscall return. On
signal delivery, the *si_errno* member of the *siginfo* signal handler
parameter is set to the syscall error value, and the *si_code* member is
set to TRAP_CAP.

See also the PROC_TRAPCAP_CTL and PROC_TRAPCAP_STATUS operations of the
procctl(2) function for similar per-process functionality.

**CAVEAT**

Creating effective process sandboxes is a tricky process that involves
identifying the least possible rights required by the process and then
passing those rights into the process in a safe manner. Consumers of
**cap_enter**\ () should also be aware of other inherited rights, such
as access to VM resources, memory contents, and other process properties
that should be considered. It is advisable to use fexecve(2) to create a
runtime environment inside the sandbox that has as few implicitly
acquired rights as possible.

**RETURN VALUES**

The **cap_enter**\ () and **cap_getmode**\ () functions return the
value 0 if successful; otherwise the value −1 is returned and the global
variable *errno* is set to indicate the error.

When the process is in capability mode, **cap_getmode**\ () sets the
flag to a non-zero value. A zero value means the process is not in
capability mode.

**ERRORS**

The **cap_enter**\ () and **cap_getmode**\ () system calls will fail if:

[ENOSYS]

The kernel is compiled without:

**options CAPABILITY_MODE**

The **cap_getmode**\ () system call may also return the following error:

[EFAULT]

Pointer *modep* points outside the process’s allocated address space.

**SEE ALSO**

cap_fcntls_limit(2), cap_ioctls_limit(2), cap_rights_limit(2),
fexecve(2), procctl(2), cap_sandboxed(3), capsicum(4), sysctl(9)

**HISTORY**

Support for capabilities and capabilities mode was developed as part of
the TrustedBSD Project.

**AUTHORS**

These functions and the capability facility were created by Robert N. M.
Watson at the University of Cambridge Computer Laboratory with support
from a grant from Google, Inc.

BSD May 23, 2017 BSD

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

