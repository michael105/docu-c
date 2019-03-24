--------------

RCTL_ADD_RULE(2) BSD System Calls Manual RCTL_ADD_RULE(2)

**NAME**

**rctl_add_rule**, **rctl_get_limits**, **rctl_get_racct**,
**rctl_get_rules**, **rctl_remove_rule** — manipulate and query the
resource limits database

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/rctl.h>**

*int*

**rctl_add_rule**\ (*const char *inbufp*, *size_t inbuflen*,
*char *outbufp*, *size_t outbuflen*);

*int*

**rctl_get_limits**\ (*const char *inbufp*, *size_t inbuflen*,
*char *outbufp*, *size_t outbuflen*);

*int*

**rctl_get_racct**\ (*const char *inbufp*, *size_t inbuflen*,
*char *outbufp*, *size_t outbuflen*);

*int*

**rctl_get_rules**\ (*const char *inbufp*, *size_t inbuflen*,
*char *outbufp*, *size_t outbuflen*);

*int*

**rctl_remove_rule**\ (*const char *inbufp*, *size_t inbuflen*,
*char *outbufp*, *size_t outbuflen*);

**DESCRIPTION**

These system calls are used to manipulate and query the resource limits
database. For all functions, *inbuflen* refers to the length of the
buffer pointed to by *inbufp* and *outbuflen* refers to the length of
the buffer pointed to by *outbufp*.

The **rctl_add_rule**\ () function adds the rule pointed to by *inbufp*
to the resource limits database. The *outbufp* and *outbuflen* arguments
are unused. Rule format is as described in rctl(8), with exceptions
noted in the *RULES AND FILTERS* section.

The **rctl_get_limits**\ () function returns in *outbufp* a
comma-separated list of rules that apply to the process that matches the
filter specified in *inbufp*. This includes rules with a subject of the
process itself as well as rules with a different subject (such as user
or loginclass) that apply to the process.

The **rctl_get_racct**\ () function returns resource usage information
for a given subject. The subject is specified by passing a filter in
*inbufp*. Filter syntax is as described in rctl(8), with exceptions
noted in the *RULES AND FILTERS* section. A comma-separated list of
resources and the amount used of each by the specified subject is
returned in *outbufp*. The resource and amount is formatted as
"resource=amount".

The **rctl_get_rules**\ () function returns in *outbufp* a
comma-separated list of rules from the resource limits database that
match the filter passed in *inbufp*. Filter syntax is as described in
rctl(8), with exceptions noted in the *RULES AND FILTERS* section. A
filter of *::* may be passed to return all rules.

The **rctl_remove_rule**\ () function removes all rules matching the
filter passed in *inbufp* from the resource limits database. Filter
syntax is as described in rctl(8), with exceptions noted in the *RULES
AND FILTERS* section. *outbufp* and *outbuflen* are unused.

**RULES AND FILTERS**

This section explains how the rule and filter format described in
rctl(8) differs from the format passed to the system calls themselves.
The rctl tool provides several conveniences that the system calls do
not. When using the system call:

**−**

The subject must be fully specified. For example, abbreviating ‘user’ to
‘u’ is not acceptable.

**−**

User and group IDs must be numeric. For example, ‘root’ must be
expressed as ‘0’.

**−**

Units are not permitted on resource amounts. For example, a quantity of
1024 bytes must be expressed as ‘1024’ and not ‘1k’.

**RETURN VALUES**

Upon successful completion, the value 0 is returned; otherwise the
value −1 is returned and the global variable *errno* is set to indicate
the error.

**ERRORS**

The rctl system calls may fail if:

[ENOSYS]

RACCT/RCTL support is not present in the kernel or the
*kern.racct.enable* sysctl is 0.

[EINVAL]

The rule or filter passed in *inbufp* is invalid.

[EPERM]

User has insufficient privileges to carry out the requested operation.

[E2BIG]

*inbufp* or *outbufp* are too large.

[ESRCH]

No process matched the provided rule or filter.

[ENAMETOOLONG]

The loginclass or jail name specified is too long.

[ERANGE]

The rule amount is outside of the allowable range or *outbufp* is too
small.

[EOPNOTSUPP]

The requested operation is not supported for the given rule or filter.

[EFAULT]

*inbufp* or *outbufp* refer to invalid addresses.

**SEE ALSO**

rctl(8)

**HISTORY**

The rctl family of system calls appeared in FreeBSD 9.0.

**AUTHORS**

The rctl system calls were developed by Edward Tomasz Napierala
<*trasz@FreeBSD.org*> under sponsorship from the FreeBSD Foundation.
This manual page was written by Eric Badger <*badger@FreeBSD.org*>.

BSD September 14, 2016 BSD

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

