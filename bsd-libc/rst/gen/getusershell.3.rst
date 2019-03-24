--------------

GETUSERSHELL(3) BSD Library Functions Manual GETUSERSHELL(3)

**NAME**

**getusershell**, **setusershell**, **endusershell** — get valid user
shells

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <unistd.h>**

*char \**

**getusershell**\ (*void*);

*void*

**setusershell**\ (*void*);

*void*

**endusershell**\ (*void*);

**DESCRIPTION**

The **getusershell**\ () function returns a pointer to a valid user
shell as defined by the system manager in the shells database as
described in shells(5). If the shells database is not available,
**getusershell**\ () behaves as if */bin/sh* and */bin/csh* were listed.

The **getusershell**\ () function reads the next line (opening the file
if necessary); **setusershell**\ () rewinds the file;
**endusershell**\ () closes it.

| **FILES**
| /etc/shells **
  DIAGNOSTICS**

The routine **getusershell**\ () returns a null pointer (0) on EOF.

**SEE ALSO**

nsswitch.conf(5), shells(5)

**HISTORY**

The **getusershell**\ () function appeared in 4.3BSD.

**BUGS**

The **getusershell**\ () function leaves its result in an internal
static object and returns a pointer to that object. Subsequent calls to
**getusershell**\ () will modify the same object.

BSD January 16, 1999 BSD

--------------
