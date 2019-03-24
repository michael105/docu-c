--------------

ATEXIT(3) BSD Library Functions Manual ATEXIT(3)

**NAME**

**atexit** — register a function to be called on exit

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <stdlib.h>**

*int*

**atexit**\ (*void (*function)(void)*);

*int*

**atexit_b**\ (*void (^function)(void)*);

**DESCRIPTION**

The **atexit**\ () function registers the given *function* to be called
at program exit, whether via exit(3) or via return from the program’s
**main**\ (). Functions so registered are called in reverse order; no
arguments are passed.

These functions must not call **exit**\ (); if it should be necessary to
terminate the process while in such a function, the \_exit(2) function
should be used. (Alternatively, the function may cause abnormal process
termination, for example by calling abort(3).)

At least 32 functions can always be registered, and more are allowed as
long as sufficient memory can be allocated.

The **atexit_b**\ () function behaves identically to **atexit**\ (),
except that it takes a block, rather than a function pointer.

**RETURN VALUES**

The **atexit**\ () function returns the value 0 if successful; otherwise
the value −1 is returned and the global variable *errno* is set to
indicate the error.

| **ERRORS**
| [ENOMEM]

No memory was available to add the function to the list. The existing
list of functions is unmodified.

[ENOSYS]

The **atexit_b**\ () function was called by a program that did not
supply a **\_Block_copy**\ () implementation.

**SEE ALSO**

at_quick_exit(3), exit(3)

**STANDARDS**

The **atexit**\ () function conforms to ISO/IEC 9899:1990 (‘‘ISO C90’’).

BSD September 6, 2002 BSD

--------------
