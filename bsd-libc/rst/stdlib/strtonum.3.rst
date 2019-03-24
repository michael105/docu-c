--------------

STRTONUM(3) BSD Library Functions Manual STRTONUM(3)

**NAME**

**strtonum** — reliably convert string value to an integer

**SYNOPSIS**

**#include <stdlib.h>**

*long long*

**strtonum**\ (*const char *nptr*, *long long minval*,
*long long maxval*, *const char **errstr*);

**DESCRIPTION**

The **strtonum**\ () function converts the string in *nptr* to a *long
long* value. The **strtonum**\ () function was designed to facilitate
safe, robust programming and overcome the shortcomings of the atoi(3)
and strtol(3) family of interfaces.

The string may begin with an arbitrary amount of whitespace (as
determined by isspace(3)) followed by a single optional ‘+’ or ‘-’ sign.

The remainder of the string is converted to a *long long* value
according to base 10.

The value obtained is then checked against the provided *minval* and
*maxval* bounds. If *errstr* is non-null, **strtonum**\ () stores an
error string in *\*errstr* indicating the failure.

**RETURN VALUES**

The **strtonum**\ () function returns the result of the conversion,
unless the value would exceed the provided bounds or is invalid. On
error, 0 is returned, *errno* is set, and *errstr* will point to an
error message. On success, *\*errstr* will be set to NULL; this fact can
be used to differentiate a successful return of 0 from an error.

**EXAMPLES**

Using **strtonum**\ () correctly is meant to be simpler than the
alternative functions.

| int iterations;
| const char \*errstr;

| iterations = strtonum(optarg, 1, 64, &errstr);
| if (errstr != NULL)

+-----------------------+-----------------------+-----------------------+
|                       | errx(1, "number of    |                       |
|                       | iterations is %s:     |                       |
|                       | %s", errstr, optarg); |                       |
+-----------------------+-----------------------+-----------------------+

The above example will guarantee that the value of iterations is between
1 and 64 (inclusive).

| **ERRORS**
| [ERANGE]

The given string was out of range.

[EINVAL]

The given string did not consist solely of digit characters.

[EINVAL]

The supplied *minval* was larger than *maxval*.

If an error occurs, *errstr* will be set to one of the following
strings:

too large

The result was larger than the provided maximum value.

too small

The result was smaller than the provided minimum value.

invalid

The string did not consist solely of digit characters.

**SEE ALSO**

atof(3), atoi(3), atol(3), atoll(3), sscanf(3), strtod(3), strtol(3),
strtoul(3)

**STANDARDS**

The **strtonum**\ () function is a BSD extension. The existing
alternatives, such as atoi(3) and strtol(3), are either impossible or
difficult to use safely.

**HISTORY**

The **strtonum**\ () function first appeared in OpenBSD 3.6.

BSD April 29, 2004 BSD

--------------
