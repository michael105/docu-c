--------------

INSQUE(3) BSD Library Functions Manual INSQUE(3)

**NAME**

**insque**, **remque** — doubly-linked list management

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <search.h>**

*void*

**insque**\ (*void *element1*, *void *pred*);

*void*

**remque**\ (*void *element*);

**DESCRIPTION**

The **insque**\ () and **remque**\ () functions encapsulate the
ever-repeating task of doing insertion and removal operations on doubly
linked lists. The functions expect their arguments to point to a
structure whose first and second members are pointers to the next and
previous element, respectively. The **insque**\ () function also allows
the *pred* argument to be a NULL pointer for the initialization of a new
list’s head element.

**STANDARDS**

The **insque**\ () and **remque**\ () functions conform to IEEE Std
1003.1-2001 (‘‘POSIX.1’’).

**HISTORY**

The **insque**\ () and **remque**\ () functions appeared in 4.2BSD. In
FreeBSD 5.0, they reappeared conforming to IEEE Std 1003.1-2001
(‘‘POSIX.1’’).

BSD October 10, 2002 BSD

--------------
