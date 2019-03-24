--------------

SYSCONF(3) BSD Library Functions Manual SYSCONF(3)

**NAME**

**sysconf** — get configurable system variables

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <unistd.h>**

*long*

**sysconf**\ (*int name*);

**DESCRIPTION**

This interface is defined by IEEE Std 1003.1-1988 (‘‘POSIX.1’’). A far
more complete interface is available using sysctl(3).

The **sysconf**\ () function provides a method for applications to
determine the current value of a configurable system limit or option
variable. The *name* argument specifies the system variable to be
queried. Symbolic constants for each name value are found in the include
file <*unistd.h*>. Shell programmers who need access to these parameters
should use the getconf(1) utility.

The available values are as follows:

\_SC_ARG_MAX

The maximum bytes of argument to execve(2).

\_SC_CHILD_MAX

The maximum number of simultaneous processes per user id.

\_SC_CLK_TCK

The frequency of the statistics clock in ticks per second.

\_SC_IOV_MAX

The maximum number of elements in the I/O vector used by readv(2),
writev(2), recvmsg(2), and sendmsg(2).

\_SC_NGROUPS_MAX

The maximum number of supplemental groups.

\_SC_NPROCESSORS_CONF

The number of processors configured.

\_SC_NPROCESSORS_ONLN

The number of processors currently online.

\_SC_OPEN_MAX

One more than the maximum value the system may assign to a new file
descriptor.

\_SC_PAGESIZE

The size of a system page in bytes.

\_SC_PAGE_SIZE

Equivalent to \_SC_PAGESIZE.

\_SC_STREAM_MAX

The minimum maximum number of streams that a process may have open at
any one time.

\_SC_TZNAME_MAX

The minimum maximum number of types supported for the name of a
timezone.

\_SC_JOB_CONTROL

Return 1 if job control is available on this system, otherwise −1.

\_SC_SAVED_IDS

Returns 1 if saved set-group and saved set-user ID is available,
otherwise −1.

\_SC_VERSION

The version of IEEE Std 1003.1 (‘‘POSIX.1’’) with which the system
attempts to comply.

\_SC_BC_BASE_MAX

The maximum ibase/obase values in the bc(1) utility.

\_SC_BC_DIM_MAX

The maximum array size in the bc(1) utility.

\_SC_BC_SCALE_MAX

The maximum scale value in the bc(1) utility.

\_SC_BC_STRING_MAX

The maximum string length in the bc(1) utility.

\_SC_COLL_WEIGHTS_MAX

The maximum number of weights that can be assigned to any entry of the
LC_COLLATE order keyword in the locale definition file.

\_SC_EXPR_NEST_MAX

The maximum number of expressions that can be nested within parenthesis
by the expr(1) utility.

\_SC_LINE_MAX

The maximum length in bytes of a text-processing utility’s input line.

\_SC_RE_DUP_MAX

The maximum number of repeated occurrences of a regular expression
permitted when using interval notation.

\_SC_2_VERSION

The version of IEEE Std 1003.2 (‘‘POSIX.2’’) with which the system
attempts to comply.

\_SC_2_C_BIND

Return 1 if the system’s C-language development facilities support the
C-Language Bindings Option, otherwise −1.

\_SC_2_C_DEV

Return 1 if the system supports the C-Language Development Utilities
Option, otherwise −1.

\_SC_2_CHAR_TERM

Return 1 if the system supports at least one terminal type capable of
all operations described in IEEE Std 1003.2 (‘‘POSIX.2’’), otherwise −1.

\_SC_2_FORT_DEV

Return 1 if the system supports the FORTRAN Development Utilities
Option, otherwise −1.

\_SC_2_FORT_RUN

Return 1 if the system supports the FORTRAN Runtime Utilities Option,
otherwise −1.

\_SC_2_LOCALEDEF

Return 1 if the system supports the creation of locales, otherwise −1.

\_SC_2_SW_DEV

Return 1 if the system supports the Software Development Utilities
Option, otherwise −1.

\_SC_2_UPE

Return 1 if the system supports the User Portability Utilities Option,
otherwise −1.

\_SC_AIO_LISTIO_MAX

Maximum number of I/O operations in a single list I/O call supported.

\_SC_AIO_MAX

Maximum number of outstanding asynchronous I/O operations supported.

\_SC_AIO_PRIO_DELTA_MAX

The maximum amount by which a process can decrease its asynchronous I/O
priority level from its own scheduling priority.

\_SC_DELAYTIMER_MAX

Maximum number of timer expiration overruns.

\_SC_MQ_OPEN_MAX

The maximum number of open message queue descriptors a process may hold.

\_SC_RTSIG_MAX

Maximum number of realtime signals reserved for application use.

\_SC_SEM_NSEMS_MAX

Maximum number of semaphores that a process may have.

\_SC_SEM_VALUE_MAX

The maximum value a semaphore may have.

\_SC_SIGQUEUE_MAX

Maximum number of queued signals that a process may send and have
pending at the receiver(s) at any time.

\_SC_TIMER_MAX

Maximum number of timers per process supported.

\_SC_GETGR_R_SIZE_MAX

Suggested initial value for the size of the group entry buffer.

\_SC_GETPW_R_SIZE_MAX

Suggested initial value for the size of the password entry buffer.

\_SC_HOST_NAME_MAX

Maximum length of a host name (not including the terminating null) as
returned from the **gethostname**\ () function.

\_SC_LOGIN_NAME_MAX

Maximum length of a login name.

\_SC_THREAD_STACK_MIN

Minimum size in bytes of thread stack storage.

\_SC_THREAD_THREADS_MAX

Maximum number of threads that can be created per process.

\_SC_TTY_NAME_MAX

Maximum length of terminal device name.

\_SC_SYMLOOP_MAX

Maximum number of symbolic links that can be reliably traversed in the
resolution of a pathname in the absence of a loop.

\_SC_ATEXIT_MAX

Maximum number of functions that may be registered with **atexit**\ ().

\_SC_XOPEN_VERSION

An integer value greater than or equal to 4, indicating the version of
the X/Open Portability Guide to which this system conforms.

\_SC_XOPEN_XCU_VERSION

An integer value indicating the version of the XCU Specification to
which this system conforms.

These values also exist, but may not be standard:

\_SC_CPUSET_SIZE

Size of the kernel cpuset.

\_SC_PHYS_PAGES

The number of pages of physical memory. Note that it is possible that
the product of this value and the value of \_SC_PAGESIZE will overflow a
*long* in some configurations on a 32bit machine.

**RETURN VALUES**

If the call to **sysconf**\ () is not successful, −1 is returned and
*errno* is set appropriately. Otherwise, if the variable is associated
with functionality that is not supported, −1 is returned and *errno* is
not modified. Otherwise, the current variable value is returned.

**ERRORS**

The **sysconf**\ () function may fail and set *errno* for any of the
errors specified for the library function sysctl(3). In addition, the
following error may be reported:

[EINVAL]

The value of the *name* argument is invalid.

**SEE ALSO**

getconf(1), pathconf(2), confstr(3), sysctl(3)

**STANDARDS**

Except for the fact that values returned by **sysconf**\ () may change
over the lifetime of the calling process, this function conforms to IEEE
Std 1003.1-1988 (‘‘POSIX.1’’).

**HISTORY**

The **sysconf**\ () function first appeared in 4.4BSD.

**BUGS**

The value for \_SC_STREAM_MAX is a minimum maximum, and required to be
the same as ANSI C’s FOPEN_MAX, so the returned value is a ridiculously
small and misleading number.

BSD April 26, 2013 BSD

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

