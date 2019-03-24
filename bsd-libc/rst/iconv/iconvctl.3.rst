--------------

ICONVCTL(3) BSD Library Functions Manual ICONVCTL(3)

**NAME**

**iconvctl** — controlling and diagnostical facility for iconv(3)

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <iconv.h>**

*int*

**iconvctl**\ (*iconv_t cd*, *int request*, *void *argument*);

**DESCRIPTION**

The **iconvctl**\ () function can retrieve or set specific conversion
setting from the *cd* conversion descriptor. The *request* parameter
specifies the operation to accomplish and *argument* is an
operation-specific argument.

The possible operations are the following:

ICONV_TRIVIALP

In this case *argument* is an *int \** variable, which is set to 1 if
the encoding is trivial one, i.e. the input and output encodings are the
same. Otherwise, the variable will be 0.

ICONV_GET_TRANSLITERATE

Determines if transliteration is enabled. The answer is stored in
*argument*, which is of *int \**. It will be set to 1 if this feature is
enabled or set to 0 otherwise.

ICONV_SET_TRANSLITERATE

Enables transliteration if *argument*, which is of *int \** set to 1 or
disables it if *argument* is set to 0.

ICONV_GET_DISCARD_ILSEQ

Determines if illegal sequences are discarded or not. The answer is
stored in *argument*, which is of *int \**. It will be set to 1 if this
feature is enabled or set to 0 otherwise.

ICONV_SET_DISCARD_ILSEQ

Sets whether illegal sequences are discarded or not. *argument*, which
is of *int \** set to 1 or disables it if *argument* is set to 0.

ICONV_SET_HOOKS

Sets callback functions, which will be called back after successful
conversions. The callback functions are stored in a *struct iconv_hooks*
variable, which is passed to **iconvctl** via *argument* by its address.

ICONV_GET_ILSEQ_INVALID

Determines if a character in the input buffer that is valid, but for
which an identical character does not exist in the target codeset
returns EILSEQ or not. The answer is stored in *argument*, which is of
*int \**. It will be set to 1 if this feature is enabled or set to 0
otherwise.

ICONV_SET_ILSEQ_INVALID

Sets whether a character in the input buffer that is valid, but for
which an identical character does not exist in the target codeset
returns EILSEQ or not. If *argument*, which is of *int \** is set to 1
it will be enabled, and if *argument* is set to 0 it will be disabled.

**RETURN VALUES**

Upon successful completion **iconvctl**\ (), returns 0. Otherwise, −1 is
returned and errno is set to specify the kind of error.

**ERRORS**

The **iconvctl**\ () function may cause an error in the following cases:

[EINVAL]

Unknown or unimplemented operation.

[EBADF]

The conversion descriptor specified by *cd* is invalid.

**SEE ALSO**

iconv(1), iconv(3)

**STANDARDS**

The **iconvctl** facility is a non-standard extension, which appeared in
the GNU implementation and was adopted in FreeBSD 9.0 for
compatibility’s sake.

**AUTHORS**

This manual page was written by Gabor Kovesdan <*gabor@FreeBSD.org*>.

**BUGS**

Transliteration is enabled in this implementation by default, so it is
impossible by design to turn it off. Accordingly, trying to turn it off
will always fail and −1 will be returned. Getting the transliteration
state will always succeed and indicate that it is turned on, though.

BSD November 25, 2009 BSD

--------------
