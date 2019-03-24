--------------

GAI_STRERROR(3) BSD Library Functions Manual GAI_STRERROR(3)

**NAME**

**gai_strerror** — get error message string from EAI_xxx error code

**SYNOPSIS**

**#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>**

*const char \**

**gai_strerror**\ (*int ecode*);

**DESCRIPTION**

The **gai_strerror**\ () function returns an error message string
corresponding to the error code returned by getaddrinfo(3) or
getnameinfo(3).

The following error codes and their meaning are defined in <*netdb.h*>:

EAI_AGAIN

Name could not be resolved at this time

EAI_BADFLAGS

flags parameter had an invalid value

EAI_BADHINTS

invalid value for *hints*

EAI_FAIL

Non-recoverable failure in name resolution

EAI_FAMILY

Address family was not recognized

EAI_MEMORY

Memory allocation failure

EAI_NONAME

Name does not resolve

EAI_OVERFLOW

argument buffer overflow

EAI_PROTOCOL

Resolved protocol is unknown

EAI_SERVICE

Service was not recognized for socket type

EAI_SOCKTYPE

Intended socket type was not recognized

EAI_SYSTEM

System error returned in *errno*

**RETURN VALUES**

The **gai_strerror**\ () function returns a pointer to the error message
string corresponding to *ecode*. If *ecode* is out of range, an
implementation-specific error message string is returned.

**SEE ALSO**

getaddrinfo(3), getnameinfo(3)

| **STANDARDS**
| RFC 3493

Basic Socket Interface Extensions for IPv6

BSD December 23, 2018 BSD

--------------
