--------------

STRTOK(3) BSD Library Functions Manual STRTOK(3)

**NAME**

**strtok**, **strtok_r** — string tokens

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <string.h>**

*char \**

**strtok**\ (*char *str*, *const char *sep*);

*char \**

**strtok_r**\ (*char *str*, *const char *sep*, *char **last*);

**DESCRIPTION**

**This interface is obsoleted by** strsep(\ **3**)\ **.**

The **strtok**\ () function is used to isolate sequential tokens in a
null-terminated string, *str*. These tokens are separated in the string
by at least one of the characters in *sep*. The first time that
**strtok**\ () is called, *str* should be specified; subsequent calls,
wishing to obtain further tokens from the same string, should pass a
null pointer instead. The separator string, *sep*, must be supplied each
time, and may change between calls.

The implementation will behave as if no library function calls
**strtok**\ ().

The **strtok_r**\ () function is a reentrant version of **strtok**\ ().
The context pointer *last* must be provided on each call. The
**strtok_r**\ () function may also be used to nest two parsing loops
within one another, as long as separate context pointers are used.

The **strtok**\ () and **strtok_r**\ () functions return a pointer to
the beginning of each subsequent token in the string, after replacing
the token itself with a NUL character. When no more tokens remain, a
null pointer is returned.

**EXAMPLES**

The following uses **strtok_r**\ () to parse two strings using separate
contexts:

| char test[80], blah[80];
| char \*sep = "\\/:;=-";
| char \*word, \*phrase, \*brkt, \*brkb;

strcpy(test, "This;is.a:test:of=the/string\\tokenizer-function.");

| for (word = strtok_r(test, sep, &brkt);
| word;
| word = strtok_r(NULL, sep, &brkt))
| {
| strcpy(blah, "blah:blat:blab:blag");

| for (phrase = strtok_r(blah, sep, &brkb);
| phrase;
| phrase = strtok_r(NULL, sep, &brkb))
| {
| printf("So far we’re at %s:%s\n", word, phrase);
| }
| }

**SEE ALSO**

memchr(3), strchr(3), strcspn(3), strpbrk(3), strrchr(3), strsep(3),
strspn(3), strstr(3), wcstok(3)

**STANDARDS**

The **strtok**\ () function conforms to ISO/IEC 9899:1990 (‘‘ISO C90’’).
The **strtok_r**\ () function conforms to IEEE Std 1003.1-2001
(‘‘POSIX.1’’).

**AUTHORS**

Wes Peters <*wes@softweyr.com*>, Softweyr LLC

Based on the FreeBSD 3.0 implementation.

**BUGS**

The System V **strtok**\ (), if handed a string containing only
delimiter characters, will not alter the next starting point, so that a
call to **strtok**\ () with a different (or empty) delimiter string may
return a non-NULL value. Since this implementation always alters the
next starting point, such a sequence of calls would always return NULL.

BSD January 22, 2016 BSD

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

