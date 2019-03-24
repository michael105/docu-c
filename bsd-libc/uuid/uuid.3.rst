--------------

UUID(3) BSD Library Functions Manual UUID(3)

**NAME**

**uuid_compare**, **uuid_create**, **uuid_create_nil**, **uuid_equal**,
**uuid_from_string**, **uuid_hash**, **uuid_is_nil**, **uuid_to_string**
— DCE 1.1 compliant UUID functions

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <uuid.h>**

*int32_t*

**uuid_compare**\ (*const uuid_t *uuid1*, *const uuid_t *uuid2*,
*uint32_t *status*);

*void*

**uuid_create**\ (*uuid_t *uuid*, *uint32_t *status*);

*void*

**uuid_create_nil**\ (*uuid_t *uuid*, *uint32_t *status*);

*int32_t*

**uuid_equal**\ (*const uuid_t *uuid1*, *const uuid_t *uuid2*,
*uint32_t *status*);

*void*

**uuid_from_string**\ (*const char *str*, *uuid_t *uuid*,
*uint32_t *status*);

*uint16_t*

**uuid_hash**\ (*const uuid_t *uuid*, *uint32_t *status*);

*int32_t*

**uuid_is_nil**\ (*const uuid_t *uuid*, *uint32_t *status*);

*void*

**uuid_to_string**\ (*const uuid_t *uuid*, *char **str*,
*uint32_t *status*);

*void*

**uuid_enc_le**\ (*void *buf*, *const uuid_t *uuid*);

*void*

**uuid_dec_le**\ (*const void *buf*, *uuid_t \**);

*void*

**uuid_enc_be**\ (*void *buf*, *const uuid_t *uuid*);

*void*

**uuid_dec_be**\ (*const void *buf*, *uuid_t \**);

**DESCRIPTION**

The family of DCE 1.1 compliant UUID functions allow applications to
operate on universally unique identifiers, or UUIDs. The
**uuid_create**\ () and **uuid_create_nil**\ () functions create UUIDs.
The **uuid_compare**\ (), **uuid_equal**\ () and **uuid_is_nil**\ ()
functions can be used to test UUIDs. To convert from the binary
representation to the string representation or vice versa, use
**uuid_to_string**\ () or **uuid_from_string**\ () respectively. A
16-bit hash value can be obtained by calling **uuid_hash**\ ().

The **uuid_to_string**\ () function set *\*str* to be a pointer to a
buffer sufficiently large to hold the string. This pointer should be
passed to free(3) to release the allocated storage when it is no longer
needed.

The **uuid_enc_le**\ () and **uuid_enc_be**\ () functions encode a
binary representation of a UUID into an octet stream in little-endian
and big-endian byte-order, respectively. The destination buffer must be
pre-allocated by the caller, and must be large enough to hold the
16-octet binary UUID. These routines are not part of the DCE RPC API.
They are provided for convenience.

The **uuid_dec_le**\ () and **uuid_dec_be**\ () functions decode a UUID
from an octet stream in little-endian and big-endian byte-order,
respectively. These routines are not part of the DCE RPC API. They are
provided for convenience.

**RETURN VALUES**

The successful or unsuccessful completion of the function is returned in
the *status* argument. Possible values are:

uuid_s_ok

The function completed successfully.

uuid_s_bad_version

The UUID does not have a known version.

uuid_s_invalid_string_uuid

The string representation of an UUID is not valid.

uuid_s_no_memory

The function can not allocate memory to store an UUID representation.

**SEE ALSO**

uuidgen(1), uuidgen(2)

**STANDARDS**

The UUID functions conform to the DCE 1.1 RPC specification.

**BUGS**

This manpage can be improved.

BSD March 1, 2012 BSD

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

