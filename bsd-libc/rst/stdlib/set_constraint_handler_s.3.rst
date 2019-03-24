--------------

SET_CONSTRAINT_HANDLE... BSD Library Functions Manual
SET_CONSTRAINT_HANDLE...

**NAME**

**set_constraint_handler_s**, **abort_handler_s**, **ignore_handler_s**
— runtime-constraint violation handling

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#define \__STDC_WANT_LIB_EXT1_\_ 1
#include <stdlib.h>**

*constraint_handler_t*

**set_constraint_handler_s**\ (*constraint_handler_t handler*);

**Handler Prototype** *
typedef void*

**(*constraint_handler_t)**\ (*const char * restrict msg*,
*void * restrict ptr*, *errno_t error*);

**Predefined Handlers** *
void*

**abort_handler_s**\ (*const char * restrict msg*,
*void * restrict ptr*, *errno_t error*);

*void*

**ignore_handler_s**\ (*const char * restrict msg*,
*void * restrict ptr*, *errno_t error*);

**DESCRIPTION**

The **set_constraint_handler_s**\ () function sets the
runtime-constraint violation handler to be *handler*.

The runtime-constraint handler is the callback function invoked when a
library function detects a runtime-constraint violation.

The arguments are as follows:

*msg*

A pointer to a character string describing the runtime-constraint
violation.

*ptr*

A NULL pointer.

*error*

If the function calling the handler has a return type declared as
*errno_t*, the return value of the function is passed. Otherwise, a
positive value of type *errno_t* is passed.

Only the most recent handler registered with
**set_constraint_handler_s**\ () is called when a runtime-constraint
violation occurs.

The implementation has a default constraint handler that is used if no
calls to the **set_constraint_handler_s**\ () function have been made.
If the *handler* argument to **set_constraint_handler_s**\ () is a NULL
pointer, the default handler becomes the current constraint handler.

The **abort_handler_s**\ () and **ignore_handler_s**\ () are the
standard-defined runtime-constraint handlers provided by the C library.

The **abort_handler_s**\ () function writes the error message including
the *msg* to stderr and calls the abort(3) function. The
**abort_handler_s**\ () is currently the default runtime-constraint
handler.

The **ignore_handler_s**\ () simply returns to its caller.

**RETURN VALUES**

The **set_constraint_handler_s**\ () function returns a pointer to the
previously registered handler, or NULL if none was previously
registered.

The **abort_handler_s**\ () function does not return to its caller.

The **ignore_handler_s**\ () function returns no value.

**STANDARDS**

The **set_constraint_handler_s**\ () function conforms to ISO/IEC
9899:2011 (‘‘ISO C11’’) K.3.6.1.1.

**AUTHORS**

This manual page was written by Yuri Pankov <*yuripv@yuripv.net*>.

BSD August 18, 2018 BSD

--------------
