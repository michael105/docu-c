--------------

STRFMON(3) BSD Library Functions Manual STRFMON(3)

**NAME**

**strfmon** — convert monetary value to string

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <monetary.h>**

*ssize_t*

**strfmon**\ (*char * restrict s*, *size_t maxsize*,
*const char * restrict format*, *...*);

*ssize_t*

**strfmon_l**\ (*char * restrict s*, *size_t maxsize*, *locale_t loc*,
*const char * restrict format*, *...*);

**DESCRIPTION**

The **strfmon**\ () function places characters into the array pointed to
by *s* as controlled by the string pointed to by *format*. No more than
*maxsize* bytes are placed into the array.

The **strfmon_l**\ () function does the same as **strfmon**\ () but
takes an explicit locale rather than using the current locale.

The format string is composed of zero or more directives: ordinary
characters (not **%**), which are copied unchanged to the output stream;
and conversion specifications, each of which results in fetching zero or
more subsequent arguments. Each conversion specification is introduced
by the **%** character. After the **%**, the following appear in
sequence:

**•**

Zero or more of the following flags:

**=**\ *f*

A ‘\ **=**\ ’ character followed by another character *f* which is used
as the numeric fill character.

**^**

Do not use grouping characters, regardless of the current locale
default.

**+**

Represent positive values by prefixing them with a positive sign, and
negative values by prefixing them with a negative sign. This is the
default.

**(**

Enclose negative values in parentheses.

**!**

Do not include a currency symbol in the output.

**−**

Left justify the result. Only valid when a field width is specified.

**•**

An optional minimum field width as a decimal number. By default, there
is no minimum width.

**•**

A ‘\ **#**\ ’ sign followed by a decimal number specifying the maximum
expected number of digits after the radix character.

**•**

A ‘\ **.**\ ’ character followed by a decimal number specifying the
number the number of digits after the radix character.

**•**

One of the following conversion specifiers:

**i**

The *double* argument is formatted as an international monetary amount.

**n**

The *double* argument is formatted as a national monetary amount.

**%**

A ‘%’ character is written.

**RETURN VALUES**

If the total number of resulting bytes including the terminating NUL
byte is not more than *maxsize*, **strfmon**\ () returns the number of
bytes placed into the array pointed to by *s*, not including the
terminating NUL byte. Otherwise, −1 is returned, the contents of the
array are indeterminate, and *errno* is set to indicate the error.

The **strfmon_l**\ () function returns the same values as
**strfmon**\ ().

**ERRORS**

The **strfmon**\ () function will fail if:

[E2BIG]

Conversion stopped due to lack of space in the buffer.

[EINVAL]

The format string is invalid.

[ENOMEM]

Not enough memory for temporary buffers.

**SEE ALSO**

localeconv(3)

**STANDARDS**

The **strfmon**\ () function conforms to IEEE Std 1003.1-2001
(‘‘POSIX.1’’). The **strfmon_l**\ () function conforms to IEEE Std
1003.1-2008 (‘‘POSIX.1’’).

**AUTHORS**

The **strfmon**\ () function was implemented by Alexey Zelkin
<*phantom@FreeBSD.org*>.

This manual page was written by Jeroen Ruigrok van der Werven
<*asmodai@FreeBSD.org*> based on the standards’ text.

**BUGS**

The **strfmon**\ () function does not correctly handle multibyte
characters in the *format* argument.

BSD June 25, 2012 BSD

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

