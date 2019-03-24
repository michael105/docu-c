--------------

REALLOCARRAY(3) BSD Library Functions Manual REALLOCARRAY(3)

**NAME**

**reallocarray** — memory reallocation function

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <stdlib.h>**

*void \**

**reallocarray**\ (*void *ptr*, *size_t nmemb*, *size_t size*);

**DESCRIPTION**

The **reallocarray**\ () function is similar to the **realloc**\ ()
function except it operates on *nmemb* members of size *size* and checks
for integer overflow in the calculation *nmemb* \* *size*.

**RETURN VALUES**

The **reallocarray**\ () function returns a pointer to the allocated
space; otherwise, a NULL pointer is returned and *errno* is set to
ENOMEM.

**EXAMPLES**

Consider **reallocarray**\ () when there is multiplication in the *size*
argument of **malloc**\ () or **realloc**\ (). For example, avoid this
common idiom as it may lead to integer overflow:

if ((p = malloc(num \* size)) == NULL)

+-----------------------+-----------------------+-----------------------+
|                       | err(1, "malloc");     |                       |
+-----------------------+-----------------------+-----------------------+

A drop-in replacement is the OpenBSD extension **reallocarray**\ ():

if ((p = reallocarray(NULL, num, size)) == NULL)

+-----------------------------------+-----------------------------------+
|                                   | err(1, "reallocarray");           |
+-----------------------------------+-----------------------------------+

When using **realloc**\ (), be careful to avoid the following idiom:

| size += 50;
| if ((p = realloc(p, size)) == NULL)

+-----------------------------------+-----------------------------------+
|                                   | return (NULL);                    |
+-----------------------------------+-----------------------------------+

Do not adjust the variable describing how much memory has been allocated
until the allocation has been successful. This can cause aberrant
program behavior if the incorrect size value is used. In most cases, the
above sample will also result in a leak of memory. As stated earlier, a
return value of NULL indicates that the old object still remains
allocated. Better code looks like this:

| newsize = size + 50;
| if ((newp = realloc(p, newsize)) == NULL) {

+-----------------------------------+-----------------------------------+
|                                   | free(p);                          |
+-----------------------------------+-----------------------------------+
|                                   | p = NULL;                         |
+-----------------------------------+-----------------------------------+
|                                   | size = 0;                         |
+-----------------------------------+-----------------------------------+
|                                   | return (NULL);                    |
+-----------------------------------+-----------------------------------+

| }
| p = newp;
| size = newsize;

As with **malloc**\ (), it is important to ensure the new size value
will not overflow; i.e. avoid allocations like the following:

if ((newp = realloc(p, num \* size)) == NULL) {

+-----------------------------------+-----------------------------------+
|                                   | ...                               |
+-----------------------------------+-----------------------------------+

Instead, use **reallocarray**\ ():

if ((newp = reallocarray(p, num, size)) == NULL) {

+-----------------------------------+-----------------------------------+
|                                   | ...                               |
+-----------------------------------+-----------------------------------+

**SEE ALSO**

realloc(3)

**HISTORY**

The **reallocarray**\ () function first appeared in OpenBSD 5.6 and
FreeBSD 11.0.

BSD May 1, 2015 BSD

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

