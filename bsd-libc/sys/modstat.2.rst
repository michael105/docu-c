--------------

MODSTAT(2) BSD System Calls Manual MODSTAT(2)

**NAME**

**modstat** — get status of kernel module

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/param.h>
#include <sys/module.h>**

*int*

**modstat**\ (*int modid*, *struct module_stat *stat*);

**DESCRIPTION**

The **modstat**\ () system call writes the info for the kernel module
referred to by *modid* into *stat*.

struct module_stat {

+-----------------------+-----------------------+-----------------------+
|                       | int version; /\* set  |                       |
|                       | to                    |                       |
|                       | sizeof(module_stat)   |                       |
|                       | \*/                   |                       |
+-----------------------+-----------------------+-----------------------+
|                       | char                  |                       |
|                       | name[MAXMODNAME];     |                       |
+-----------------------+-----------------------+-----------------------+
|                       | int refs;             |                       |
+-----------------------+-----------------------+-----------------------+
|                       | int id;               |                       |
+-----------------------+-----------------------+-----------------------+
|                       | modspecific_t data;   |                       |
+-----------------------+-----------------------+-----------------------+

| };
| typedef union modspecific {

+-----------------------------------+-----------------------------------+
|                                   | int intval;                       |
+-----------------------------------+-----------------------------------+
|                                   | u_int uintval;                    |
+-----------------------------------+-----------------------------------+
|                                   | long longval;                     |
+-----------------------------------+-----------------------------------+
|                                   | u_long ulongval;                  |
+-----------------------------------+-----------------------------------+

} modspecific_t;

version

This field is set to the size of the structure mentioned above by the
code calling **modstat**\ (), and not **modstat**\ () itself.

name

The name of the module referred to by *modid*.

refs

The number of modules referenced by *modid*.

id

The id of the module specified in *modid*.

data

Module specific data.

**RETURN VALUES**

The **modstat**\ () function returns the value 0 if successful;
otherwise the value −1 is returned and the global variable *errno* is
set to indicate the error.

**ERRORS**

The information for the module referred to by *modid* is filled into the
structure pointed to by *stat* unless:

[ENOENT]

The module was not found (probably not loaded).

[EINVAL]

The version specified in the *version* field of stat is not the proper
version. You would need to rebuild world, the kernel, or your
application, if this error occurs, given that you did properly fill in
the *version* field.

[EFAULT]

There was a problem copying one, some, or all of the fields into *stat*
in the copyout(9) function.

**SEE ALSO**

kldfind(2), kldfirstmod(2), kldload(2), kldnext(2), kldstat(2),
kldsym(2), kldunload(2), modfind(2), modfnext(2), modnext(2), kld(4),
kldstat(8)

**HISTORY**

The **kld** interface first appeared in FreeBSD 3.0.

BSD July 15, 2008 BSD

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

