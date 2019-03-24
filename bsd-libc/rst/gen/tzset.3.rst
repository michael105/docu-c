--------------

TZSET(3) BSD Library Functions Manual TZSET(3)

**NAME**

**tzset**, **tzsetwall** — initialize time conversion information

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <time.h>**

*void*

**tzset**\ (*void*);

*void*

**tzsetwall**\ (*void*);

**DESCRIPTION**

The **tzset**\ () function initializes time conversion information used
by the library routine localtime(3). The environment variable TZ
specifies how this is done.

If TZ does not appear in the environment, the best available
approximation to local wall clock time, as specified by the
tzfile(5)-format file */etc/localtime* is used.

If TZ appears in the environment but its value is a null string,
Coordinated Universal Time (UTC) is used (without leap second
correction).

If TZ appears in the environment and its value begins with a colon
(‘:’), the rest of its value is used as a pathname of a tzfile(5)-format
file from which to read the time conversion information. If the first
character of the pathname is a slash (‘/’) it is used as an absolute
pathname; otherwise, it is used as a pathname relative to the system
time conversion information directory.

If its value does not begin with a colon, it is first used as the
pathname of a file (as described above) from which to read the time
conversion information. If that file cannot be read, the value is then
interpreted as a direct specification (the format is described below) of
the time conversion information.

If the TZ environment variable does not specify a tzfile(5)-format file
and cannot be interpreted as a direct specification, UTC is used.

The **tzsetwall**\ () function sets things up so that localtime(3)
returns the best available approximation of local wall clock time.

**SPECIFICATION FORMAT**

When TZ is used directly as a specification of the time conversion
information, it must have the following syntax (spaces inserted for
clarity):

*std offset* [

*dst* [*offset*] [, *rule*] ]

Where:

*std* and *dst*

Three or more bytes that are the designation for the standard (*std*) or
summer (*dst*) time zone. Only *std* is required; if *dst* is missing,
then summer time does not apply in this locale. Upper and lowercase
letters are explicitly allowed. Any characters except a leading colon
(‘:’), digits, comma (‘,’), minus (‘−’), plus (‘+’), and ASCII NUL are
allowed.

*offset*

Indicates the value one must add to the local time to arrive at
Coordinated Universal Time. The *offset* has the form:

*hh*\ [

:*mm*\ [:*ss*] ]

The minutes (*mm*) and seconds (*ss*) are optional. The hour (*hh*) is
required and may be a single digit. The *offset* following *std* is
required. If no *offset* follows *dst*, summer time is assumed to be one
hour ahead of standard time. One or more digits may be used; the value
is always interpreted as a decimal number. The hour must be between zero
and 24, and the minutes (and seconds) — if present — between zero and
59. If preceded by a (‘−’) the time zone shall be east of the Prime
Meridian; otherwise it shall be west (which may be indicated by an
optional preceding (‘+’)).

*rule*

Indicates when to change to and back from summer time. The *rule* has
the form:

*date/time,date/time*

where the first *date* describes when the change from standard to summer
time occurs and the second *date* describes when the change back
happens. Each *time* field describes when, in current local time, the
change to the other time is made.

The format of *date* is one of the following:

**J** *n*

The Julian day *n* (1 ≤ *n* ≤ 365). Leap days are not counted; that is,
in all years — including leap years — February 28 is day 59 and March 1
is day 60. It is impossible to explicitly refer to the occasional
February 29.

*n*

The zero-based Julian day (0 ≤ *n* ≤ 365 ) . Leap days are counted, and
it is possible to refer to February 29.

**M** *m.n.d*

The *d*\ ’th day (0 ≤ *d* ≤ 6) of week *n* of month *m* of the year (1 ≤
*n* ≤ 5), (1 ≤ *m* ≤ 12), where week 5 means ‘‘

the last *d* day in month *m* ’’ which may occur in either the fourth or
the fifth week). Week 1 is the first week in which the *d*\ ’th day
occurs. Day zero is Sunday.

The *time* has the same format as *offset* except that no leading sign
(‘−’) or (‘+’) is allowed. The default, if *time* is not given, is
**02:00:00**.

If no *rule* is present in the TZ specification, the rules specified by
the tzfile(5)-format file *posixrules* in the system time conversion
information directory are used, with the standard and summer time
offsets from UTC replaced by those specified by the *offset* values in
TZ.

For compatibility with System V Release 3.1, a semicolon (‘;’) may be
used to separate the *rule* from the rest of the specification.

| **FILES**
| /etc/localtime

local time zone file

/usr/share/zoneinfo

time zone directory

/usr/share/zoneinfo/posixrules

rules for POSIX-style TZ’s

/usr/share/zoneinfo/Etc/GMT

for UTC leap seconds

If the file */usr/share/zoneinfo/UTC* does not exist, UTC leap seconds
are loaded from */usr/share/zoneinfo/posixrules*.

**SEE ALSO**

date(1), gettimeofday(2), ctime(3), getenv(3), time(3), tzfile(5)

**HISTORY**

The **tzset**\ () and **tzsetwall**\ () functions first appeared in
4.4BSD.

BSD November 17, 1993 BSD

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

