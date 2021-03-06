--------------

DL_ITERATE_PHDR(3) BSD Library Functions Manual DL_ITERATE_PHDR(3)

**NAME**

**dl_iterate_phdr** — iterate over program headers

**LIBRARY**

For the dynamically linked binaries, the service is provided by
ld-elf.so.1(1) dynamic linker. Statically linked programs use an
implementation of **dl_iterate_phdr**\ () from libc.

**SYNOPSIS**

**#include <link.h>**

*int*

**dl_iterate_phdr**\ (*int (*callback)(struct dl_phdr_info *, size_t, void *)*,
*void *data*);

**DESCRIPTION**

The **dl_iterate_phdr**\ () function iterates over all ELF objects
loaded into a process’s address space, calling *callback* for each
object, passing it information about the object’s program headers and
the *data* argument. The iteration is aborted when all objects are
passed, or when the next *callback* call returns non-zero value. The
information about the program headers is passed in a structure that is
defined as:

struct dl_phdr_info {

+-------------+-------------+-------------+-------------+-------------+
|             | Elf_Addr    |             | dlpi_addr;  |             |
+-------------+-------------+-------------+-------------+-------------+
|             | const char  |             | \*dlpi_name |             |
|             |             |             | ;           |             |
+-------------+-------------+-------------+-------------+-------------+
|             | const       |             | \*dlpi_phdr |             |
|             | Elf_Phdr    |             | ;           |             |
+-------------+-------------+-------------+-------------+-------------+
|             | Elf_Half    |             | dlpi_phnum; |             |
+-------------+-------------+-------------+-------------+-------------+
|             | unsigned    |             |             |             |
|             | long long   |             |             |             |
|             | int         |             |             |             |
|             | dlpi_adds;  |             |             |             |
+-------------+-------------+-------------+-------------+-------------+
|             | unsigned    |             |             |             |
|             | long long   |             |             |             |
|             | int         |             |             |             |
|             | dlpi_subs;  |             |             |             |
+-------------+-------------+-------------+-------------+-------------+
|             | size_t      |             | dlpi_tls_mo |             |
|             |             |             | did;        |             |
+-------------+-------------+-------------+-------------+-------------+
|             | void        |             | \*dlpi_tls_ |             |
|             |             |             | data;       |             |
+-------------+-------------+-------------+-------------+-------------+

};

The members of struct dl_phdr_info have the following meaning:

*dlpi_addr*

The base address at which the object is mapped into the address space of
the calling process.

*dlpi_name*

The pathname of the ELF object.

*dlpi_phdr*

A pointer to the object’s program headers.

*dlpi_phnum*

The number of program headers in the object.

*dlpi_adds*

The counter of the object loads performed by the dynamic linker.

*dlpi_subs*

The counter of the object unloads performed by the dynamic linker.

*dlpi_tls_modid*

The TLS index of the object.

*dlpi_tls_data*

A pointer to the initialization data for the object TLS segment.

Future versions of FreeBSD might add more members to this structure. To
make it possible for programs to check whether any new members have been
added, the size of the structure is passed as an second argument to
*callback*.

The third argument to callback is the *data* value passed to the call to
**dl_iterate_phdr**\ (), allowing the *callback* to have a context.

**RETURN VALUES**

The **dl_iterate_phdr**\ () returns the value returned by the last
*callback* call executed.

**SEE ALSO**

ld(1), ld-elf.so.1(1), dlopen(3), elf(5)

**HISTORY**

The **dl_iterate_phdr** function first appeared in FreeBSD 7.0.

BSD October 9, 2014 BSD

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

