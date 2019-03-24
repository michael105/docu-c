--------------

CATGETS(3) BSD Library Functions Manual CATGETS(3)

**NAME**

**catgets** — retrieve string from message catalog

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <nl_types.h>**

*char \**

**catgets**\ (*nl_catd catd*, *int set_id*, *int msg_id*,
*const char *s*);

**DESCRIPTION**

The **catgets**\ () function attempts to retrieve message *msg_id* of
set *set_id* from the message catalog referenced by the descriptor
*catd*. The argument *s* points to a default message which is returned
if the function is unable to retrieve the specified message.

**RETURN VALUES**

If the specified message was retrieved successfully, **catgets**\ ()
returns a pointer to an internal buffer containing the message string;
otherwise it returns *s*.

| **ERRORS**
| [EBADF]

The *catd* argument is not a valid message catalog descriptor.

[EBADMSG]

The message identified by *set_id* and *msg_id* is not in the message
catalog.

**SEE ALSO**

gencat(1), catclose(3), catopen(3)

**STANDARDS**

The **catgets**\ () function conforms to IEEE Std 1003.1-2001
(‘‘POSIX.1’’).

BSD February 12, 2005 BSD

--------------
