--------------

GETPASS(3) BSD Library Functions Manual GETPASS(3)

**NAME**

**getpass** — get a password

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <pwd.h>
#include <unistd.h>**

*char \**

**getpass**\ (*const char *prompt*);

**DESCRIPTION**

The **getpass**\ () function displays a prompt to, and reads in a
password from, */dev/tty*. If this file is not accessible,
**getpass**\ () displays the prompt on the standard error output and
reads from the standard input.

The password may be up to \_PASSWORD_LEN (currently 128) characters in
length. Any additional characters and the terminating newline character
are discarded.

The **getpass**\ () function turns off character echoing while reading
the password.

**RETURN VALUES**

The **getpass**\ () function returns a pointer to the null terminated
password.

| **FILES**
| /dev/tty **
  SEE ALSO**

crypt(3), readpassphrase(3)

**HISTORY**

A **getpass**\ () function appeared in Version 7 AT&T UNIX.

**BUGS**

The **getpass**\ () function leaves its result in an internal static
object and returns a pointer to that object. Subsequent calls to
**getpass**\ () will modify the same object.

The calling process should zero the password as soon as possible to
avoid leaving the cleartext password visible in the process’s address
space.

Upon receipt of a SIGTSTP, the input buffer will be flushed, so any
partially typed password must be retyped when the process continues.

BSD June 4, 1993 BSD

--------------
