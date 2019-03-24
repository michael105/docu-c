--------------

SET_CONSTRAINT_HANDLE... BSD Library Functions Manual
SET_CONSTRAINT_HANDLE...

**NAME**

**set_constraint_handler_s**, **abort_handler_s**, **ignore_handler_s**
— runtime-constraint violation handling

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#define \__STDC_WANT_LIB_EXT1_\_ 1
#include <stdlib.h>**

*constraint_handler_t*

**set_constraint_handler_s**\ (*constraint_handler_t handler*);

**Handler Prototype** *
typedef void*

**(*constraint_handler_t)**\ (*const char * restrict msg*,
*void * restrict ptr*, *errno_t error*);

**Predefined Handlers** *
void*

**abort_handler_s**\ (*const char * restrict msg*,
*void * restrict ptr*, *errno_t error*);

*void*

**ignore_handler_s**\ (*const char * restrict msg*,
*void * restrict ptr*, *errno_t error*);

**DESCRIPTION**

The **set_constraint_handler_s**\ () function sets the
runtime-constraint violation handler to be *handler*.

The runtime-constraint handler is the callback function invoked when a
library function detects a runtime-constraint violation.

The arguments are as follows:

*msg*

A pointer to a character string describing the runtime-constraint
violation.

*ptr*

A NULL pointer.

*error*

If the function calling the handler has a return type declared as
*errno_t*, the return value of the function is passed. Otherwise, a
positive value of type *errno_t* is passed.

Only the most recent handler registered with
**set_constraint_handler_s**\ () is called when a runtime-constraint
violation occurs.

The implementation has a default constraint handler that is used if no
calls to the **set_constraint_handler_s**\ () function have been made.
If the *handler* argument to **set_constraint_handler_s**\ () is a NULL
pointer, the default handler becomes the current constraint handler.

The **abort_handler_s**\ () and **ignore_handler_s**\ () are the
standard-defined runtime-constraint handlers provided by the C library.

The **abort_handler_s**\ () function writes the error message including
the *msg* to stderr and calls the abort(3) function. The
**abort_handler_s**\ () is currently the default runtime-constraint
handler.

The **ignore_handler_s**\ () simply returns to its caller.

**RETURN VALUES**

The **set_constraint_handler_s**\ () function returns a pointer to the
previously registered handler, or NULL if none was previously
registered.

The **abort_handler_s**\ () function does not return to its caller.

The **ignore_handler_s**\ () function returns no value.

**STANDARDS**

The **set_constraint_handler_s**\ () function conforms to ISO/IEC
9899:2011 (‘‘ISO C11’’) K.3.6.1.1.

**AUTHORS**

This manual page was written by Yuri Pankov <*yuripv@yuripv.net*>.

BSD August 18, 2018 BSD

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

