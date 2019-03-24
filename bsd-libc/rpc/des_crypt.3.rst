--------------

DES_CRYPT(3) BSD Library Functions Manual DES_CRYPT(3)

**NAME**

**des_crypt**, **ecb_crypt**, **cbc_crypt**, **des_setparity** — fast
DES encryption

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <rpc/des_crypt.h>**

*int*

**ecb_crypt**\ (*char *key*, *char *data*, *unsigned datalen*,
*unsigned mode*);

*int*

**cbc_crypt**\ (*char *key*, *char *data*, *unsigned datalen*,
*unsigned mode*, *char *ivec*);

*void*

**des_setparity**\ (*char *key*);

**DESCRIPTION**

The **ecb_crypt**\ () and **cbc_crypt**\ () functions implement the NBS
DES (Data Encryption Standard). These routines are faster and more
general purpose than crypt(3). They also are able to utilize DES
hardware if it is available. The **ecb_crypt**\ () function encrypts in
ECB (Electronic Code Book) mode, which encrypts blocks of data
independently. The **cbc_crypt**\ () function encrypts in CBC (Cipher
Block Chaining) mode, which chains together successive blocks. CBC mode
protects against insertions, deletions and substitutions of blocks.
Also, regularities in the clear text will not appear in the cipher text.

Here is how to use these routines. The first argument, *key*, is the
8-byte encryption key with parity. To set the key’s parity, which for
DES is in the low bit of each byte, use **des_setparity**\ (). The
second argument, *data*, contains the data to be encrypted or decrypted.
The third argument, *datalen*, is the length in bytes of *data*, which
must be a multiple of 8. The fourth argument, *mode*, is formed by
*OR*\ ’ing together some things. For the encryption direction *OR* in
either DES_ENCRYPT or DES_DECRYPT. For software versus hardware
encryption, *OR* in either DES_HW or DES_SW. If DES_HW is specified, and
there is no hardware, then the encryption is performed in software and
the routine returns DESERR_NOHWDEVICE. For **cbc_crypt**\ (), the *ivec*
argument is the 8-byte initialization vector for the chaining. It is
updated to the next initialization vector upon return.

| **ERRORS**
| [DESERR_NONE]

No error.

[DESERR_NOHWDEVICE]

Encryption succeeded, but done in software instead of the requested
hardware.

[DESERR_HWERROR]

An error occurred in the hardware or driver.

[DESERR_BADPARAM]

Bad argument to routine.

Given a result status *stat*, the macro **DES_FAILED**\ (*stat*) is
false only for the first two statuses.

**SEE ALSO**

crypt(3)

**RESTRICTIONS**

These routines are not available in RPCSRC 4.0. This information is
provided to describe the DES interface expected by Secure RPC.

BSD October 6, 1987 BSD

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

