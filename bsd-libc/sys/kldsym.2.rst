--------------

KLDSYM(2) BSD System Calls Manual KLDSYM(2)

**NAME**

**kldsym** — look up address by symbol name in a KLD

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/param.h>
#include <sys/linker.h>**

*int*

**kldsym**\ (*int fileid*, *int cmd*, *void *data*);

**DESCRIPTION**

The **kldsym**\ () system call returns the address of the symbol
specified in *data* in the module specified by *fileid*. If *fileid* is
0, all loaded modules are searched. Currently, the only *cmd*
implemented is KLDSYM_LOOKUP.

The *data* argument is of the following structure:

| struct kld_sym_lookup {
| int version; /\* sizeof(struct kld_sym_lookup) \*/
| char \*symname; /\* Symbol name we are looking up \*/
| u_long symvalue;
| size_t symsize;
| };

The *version* member is to be set by the code calling **kldsym**\ () to
**sizeof**\ (*struct kld_sym_lookup*). The next two members, *version*
and *symname*, are specified by the user. The last two, *symvalue* and
*symsize*, are filled in by **kldsym**\ () and contain the address
associated with *symname* and the size of the data it points to,
respectively.

**RETURN VALUES**

The **kldsym**\ () function returns the value 0 if successful; otherwise
the value −1 is returned and the global variable *errno* is set to
indicate the error.

**ERRORS**

The **kldsym**\ () system call will fail if:

[EINVAL]

Invalid value in *data->version* or *cmd*.

[ENOENT]

The *fileid* argument is invalid, or the specified symbol could not be
found.

**SEE ALSO**

kldfind(2), kldfirstmod(2), kldload(2), kldnext(2), kldunload(2),
modfind(2), modnext(2), modstat(2), kld(4)

**HISTORY**

The **kldsym**\ () system call first appeared in FreeBSD 3.0.

BSD October 17, 2016 BSD

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

