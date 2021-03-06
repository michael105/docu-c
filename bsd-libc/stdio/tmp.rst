--------------

| <!-- Creator : groff version 1.22.3 --> <!-- CreationDate: Sun Mar 24
  02:00:40 2019 --> <!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01
  Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd"> <html>
  <head> <meta name="generator" content="groff -Thtml, see www.gnu.org">
  <meta http-equiv="Content-Type" content="text/html; charset=US-ASCII">
  <meta name="Content-Style" content="text/css"> <style type="text/css">
| p { margin-top: 0; margin-bottom: 0; vertical-align: top }
| pre { margin-top: 0; margin-bottom: 0; vertical-align: top }
| table { margin-top: 0; margin-bottom: 0; vertical-align: top }
| h1 { text-align: center } </style> <title></title> </head> <body>

<hr>

<p>WSCANF(3) BSD Library Functions Manual WSCANF(3)</p>

<p style="margin-top: 1em"><b>NAME</b></p>

<p style="margin-left:6%;"><b>wscanf</b>, <b>fwscanf</b>,
<b>swscanf</b>, <b>vwscanf</b>, <b>vswscanf</b>, <b>vfwscanf</b> &mdash;
wide character input format conversion</p>

<p style="margin-top: 1em"><b>LIBRARY</b></p>

<p style="margin-left:6%;">Standard C&nbsp;Library (libc, &minus;lc)</p>

<p style="margin-top: 1em"><b>SYNOPSIS</b></p>

<p style="margin-left:6%;"><b>#include &lt;stdio.h&gt; <br> #include
&lt;wchar.h&gt;</b></p>

<p style="margin-left:6%; margin-top: 1em"><i>int</i></p>

<p
style="margin-left:12%;"><b>wscanf</b>(<i>const&nbsp;wchar_t&nbsp;*&nbsp;restrict&nbsp;format</i>,
<i>...</i>);</p>

<p style="margin-left:6%; margin-top: 1em"><i>int</i></p>

<p
style="margin-left:12%;"><b>fwscanf</b>(<i>FILE&nbsp;*&nbsp;restrict&nbsp;stream</i>,
<i>const&nbsp;wchar_t&nbsp;*&nbsp;restrict&nbsp;format</i>,
<i>...</i>);</p>

<p style="margin-left:6%; margin-top: 1em"><i>int</i></p>

<p
style="margin-left:12%;"><b>swscanf</b>(<i>const&nbsp;wchar_t&nbsp;*&nbsp;restrict&nbsp;str</i>,
<i>const&nbsp;wchar_t&nbsp;*&nbsp;restrict&nbsp;format</i>,
<i>...</i>);</p>

<p style="margin-left:6%; margin-top: 1em"><b>#include
&lt;stdarg.h&gt;</b></p>

<p style="margin-left:6%; margin-top: 1em"><i>int</i></p>

<p
style="margin-left:12%;"><b>vwscanf</b>(<i>const&nbsp;wchar_t&nbsp;*&nbsp;restrict&nbsp;format</i>,
<i>va_list&nbsp;ap</i>);</p>

<p style="margin-left:6%; margin-top: 1em"><i>int</i></p>

<p
style="margin-left:12%;"><b>vswscanf</b>(<i>const&nbsp;wchar_t&nbsp;*&nbsp;restrict&nbsp;str</i>,
<i>const&nbsp;wchar_t&nbsp;*&nbsp;restrict&nbsp;format</i>,
<i>va_list&nbsp;ap</i>);</p>

<p style="margin-left:6%; margin-top: 1em"><i>int</i></p>

<p
style="margin-left:12%;"><b>vfwscanf</b>(<i>FILE&nbsp;*&nbsp;restrict&nbsp;stream</i>,
<i>const&nbsp;wchar_t&nbsp;*&nbsp;restrict&nbsp;format</i>,
<i>va_list&nbsp;ap</i>);</p>

<p style="margin-top: 1em"><b>DESCRIPTION</b></p>

<p style="margin-left:6%;">The <b>wscanf</b>() family of functions scans
input according to a <i>format</i> as described below. This format may
contain <i>conversion specifiers</i>; the results from such conversions,
if any, are stored through the <i>pointer</i> arguments. The
<b>wscanf</b>() function reads input from the standard input stream
stdin, <b>fwscanf</b>() reads input from the stream pointer
<i>stream</i>, and <b>swscanf</b>() reads its input from the wide
character string pointed to by <i>str</i>. The <b>vfwscanf</b>()
function is analogous to vfwprintf(3) and reads input from the stream
pointer <i>stream</i> using a variable argument list of pointers (see
stdarg(3)). The <b>vwscanf</b>() function scans a variable argument list
from the standard input and the <b>vswscanf</b>() function scans it from
a wide character string; these are analogous to the <b>vwprintf</b>()
and <b>vswprintf</b>() functions respectively. Each successive
<i>pointer</i> argument must correspond properly with each successive
conversion specifier (but see the <b>*</b> conversion below). All
conversions are introduced by the <b>%</b> (percent sign) character. The
<i>format</i> string may also contain other characters. White space
(such as blanks, tabs, or newlines) in the <i>format</i> string match
any amount of white space, including none, in the input. Everything else
matches only itself. Scanning stops when an input character does not
match such a format character. Scanning also stops when an input
conversion cannot be made (see below).</p>

<p style="margin-top: 1em"><b>CONVERSIONS</b></p>

<p style="margin-left:6%;">Following the <b>%</b> character introducing
a conversion there may be a number of <i>flag</i> characters, as
follows:</p>

<p style="margin-top: 1em"><b>*</b></p>

<p style="margin-left:18%; margin-top: 1em">Suppresses assignment. The
conversion that follows occurs as usual, but no pointer is used; the
result of the conversion is simply discarded.</p>

<p style="margin-top: 1em"><b>hh</b></p>

<p style="margin-left:18%; margin-top: 1em">Indicates that the
conversion will be one of <b>dioux</b> or <b>n</b> and the next pointer
is a pointer to a <i>char</i> (rather than <i>int</i>).</p>

<p style="margin-top: 1em"><b>h</b></p>

<p style="margin-left:18%; margin-top: 1em">Indicates that the
conversion will be one of <b>dioux</b> or <b>n</b> and the next pointer
is a pointer to a <i>short int</i> (rather than <i>int</i>).</p>

<p style="margin-top: 1em"><b>l</b> (ell)</p>

<p style="margin-left:18%; margin-top: 1em">Indicates that the
conversion will be one of <b>dioux</b> or <b>n</b> and the next pointer
is a pointer to a <i>long int</i> (rather than <i>int</i>), that the
conversion will be one of <b>a</b>, <b>e</b>, <b>f</b>, or <b>g</b> and
the next pointer is a pointer to <i>double</i> (rather than
<i>float</i>), or that the conversion will be one of <b>c</b> or
<b>s</b> and the next pointer is a pointer to an array of <i>wchar_t</i>
(rather than <i>char</i>).</p>

<p style="margin-top: 1em"><b>ll</b> (ell ell)</p>

<p style="margin-left:18%;">Indicates that the conversion will be one of
<b>dioux</b> or <b>n</b> and the next pointer is a pointer to a <i>long
long int</i> (rather than <i>int</i>).</p>

<p style="margin-top: 1em"><b>L</b></p>

<p style="margin-left:18%; margin-top: 1em">Indicates that the
conversion will be one of <b>a</b>, <b>e</b>, <b>f</b>, or <b>g</b> and
the next pointer is a pointer to <i>long double</i>.</p>

<p style="margin-top: 1em"><b>j</b></p>

<p style="margin-left:18%; margin-top: 1em">Indicates that the
conversion will be one of <b>dioux</b> or <b>n</b> and the next pointer
is a pointer to a <i>intmax_t</i> (rather than <i>int</i>).</p>

<p style="margin-top: 1em"><b>t</b></p>

<p style="margin-left:18%; margin-top: 1em">Indicates that the
conversion will be one of <b>dioux</b> or <b>n</b> and the next pointer
is a pointer to a <i>ptrdiff_t</i> (rather than <i>int</i>).</p>

<p style="margin-top: 1em"><b>z</b></p>

<p style="margin-left:18%; margin-top: 1em">Indicates that the
conversion will be one of <b>dioux</b> or <b>n</b> and the next pointer
is a pointer to a <i>size_t</i> (rather than <i>int</i>).</p>

<p style="margin-top: 1em"><b>q</b></p>

<p style="margin-left:18%; margin-top: 1em">(deprecated.) Indicates that
the conversion will be one of <b>dioux</b> or <b>n</b> and the next
pointer is a pointer to a <i>long long int</i> (rather than
<i>int</i>).</p>

<p style="margin-left:6%; margin-top: 1em">In addition to these flags,
there may be an optional maximum field width, expressed as a decimal
integer, between the <b>%</b> and the conversion. If no width is given,
a default of &lsquo;&lsquo;infinity&rsquo;&rsquo; is used (with one
exception, below); otherwise at most this many characters are scanned in
processing the conversion. Before conversion begins, most conversions
skip white space; this white space is not counted against the field
width.</p>

<p style="margin-left:6%; margin-top: 1em">The following conversions are
available:</p>

<p style="margin-top: 1em"><b>%</b></p>

<p style="margin-left:14%; margin-top: 1em">Matches a literal
&lsquo;%&rsquo;. That is, &lsquo;&lsquo;%%&rsquo;&rsquo; in the format
string matches a single input &lsquo;%&rsquo; character. No conversion
is done, and assignment does not occur.</p>

<p style="margin-top: 1em"><b>d</b></p>

<p style="margin-left:14%; margin-top: 1em">Matches an optionally signed
decimal integer; the next pointer must be a pointer to <i>int</i>.</p>

<p style="margin-top: 1em"><b>i</b></p>

<p style="margin-left:14%; margin-top: 1em">Matches an optionally signed
integer; the next pointer must be a pointer to <i>int</i>. The integer
is read in base 16 if it begins with &lsquo;0x&rsquo; or
&lsquo;0X&rsquo;, in base 8 if it begins with &lsquo;0&rsquo;, and in
base 10 otherwise. Only characters that correspond to the base are
used.</p>

<p style="margin-top: 1em"><b>o</b></p>

<p style="margin-left:14%; margin-top: 1em">Matches an octal integer;
the next pointer must be a pointer to <i>unsigned int</i>.</p>

<p style="margin-top: 1em"><b>u</b></p>

<p style="margin-left:14%; margin-top: 1em">Matches an optionally signed
decimal integer; the next pointer must be a pointer to <i>unsigned
int</i>.</p>

<p style="margin-top: 1em"><b>x</b>, <b>X</b></p>

<p style="margin-left:14%; margin-top: 1em">Matches an optionally signed
hexadecimal integer; the next pointer must be a pointer to <i>unsigned
int</i>.</p>

<p style="margin-top: 1em"><b>a</b>, <b>A</b>, <b>e</b>, <b>E</b>,
<b>f</b>, <b>F</b>, <b>g</b>, <b>G</b></p>

<p style="margin-left:14%;">Matches a floating-point number in the style
of wcstod(3). The next pointer must be a pointer to <i>float</i> (unless
<b>l</b> or <b>L</b> is specified.)</p>

<p style="margin-top: 1em"><b>s</b></p>

<p style="margin-left:14%; margin-top: 1em">Matches a sequence of
non-white-space wide characters; the next pointer must be a pointer to
<i>char</i>, and the array must be large enough to accept the multibyte
representation of all the sequence and the terminating NUL character.
The input string stops at white space or at the maximum field width,
whichever occurs first.</p>

<p style="margin-left:14%; margin-top: 1em">If an <b>l</b> qualifier is
present, the next pointer must be a pointer to <i>wchar_t</i>, into
which the input will be placed.</p>

<p style="margin-top: 1em"><b>S</b></p>

<p style="margin-left:14%; margin-top: 1em">The same as <b>ls</b>.</p>

<p style="margin-top: 1em"><b>c</b></p>

<p style="margin-left:14%; margin-top: 1em">Matches a sequence of
<i>width</i> count wide characters (default 1); the next pointer must be
a pointer to <i>char</i>, and there must be enough room for the
multibyte representation of all the characters (no terminating NUL is
added). The usual skip of leading white space is suppressed. To skip
white space first, use an explicit space in the format.</p>

<p style="margin-left:14%; margin-top: 1em">If an <b>l</b> qualifier is
present, the next pointer must be a pointer to <i>wchar_t</i>, into
which the input will be placed.</p>

<p style="margin-top: 1em"><b>C</b></p>

<p style="margin-left:14%; margin-top: 1em">The same as <b>lc</b>.</p>

<p style="margin-top: 1em"><b>[</b></p>

<p style="margin-left:14%; margin-top: 1em">Matches a nonempty sequence
of characters from the specified set of accepted characters; the next
pointer must be a pointer to <i>char</i>, and there must be enough room
for the multibyte representation of all the characters in the string,
plus a terminating NUL character. The usual skip of leading white space
is suppressed. The string is to be made up of characters in (or not in)
a particular set; the set is defined by the characters between the open
bracket <b>[</b> character and a close bracket <b>]</b> character. The
set <i>excludes</i> those characters if the first character after the
open bracket is a circumflex <b>^</b>. To include a close bracket in the
set, make it the first character after the open bracket or the
circumflex; any other position will end the set. To include a hyphen in
the set, make it the last character before the final close bracket; some
implementations of <b>wscanf</b>() use &lsquo;&lsquo;A-Z&rsquo;&rsquo;
to represent the range of characters between &lsquo;A&rsquo; and
&lsquo;Z&rsquo;. The string ends with the appearance of a character not
in the (or, with a circumflex, in) set or when the field width runs
out.</p>

<p style="margin-left:14%; margin-top: 1em">If an <b>l</b> qualifier is
present, the next pointer must be a pointer to <i>wchar_t</i>, into
which the input will be placed.</p>

<p style="margin-top: 1em"><b>p</b></p>

<p style="margin-left:14%; margin-top: 1em">Matches a pointer value (as
printed by &lsquo;%p&rsquo; in wprintf(3)); the next pointer must be a
pointer to <i>void</i>.</p>

<p style="margin-top: 1em"><b>n</b></p>

<p style="margin-left:14%; margin-top: 1em">Nothing is expected;
instead, the number of characters consumed thus far from the input is
stored through the next pointer, which must be a pointer to <i>int</i>.
This is <i>not</i> a conversion, although it can be suppressed with the
<b>*</b> flag.</p>

<p style="margin-left:6%; margin-top: 1em">The decimal point character
is defined in the program&rsquo;s locale (category LC_NUMERIC).</p>

<p style="margin-left:6%; margin-top: 1em">For backwards compatibility,
a &lsquo;&lsquo;conversion&rsquo;&rsquo; of &lsquo;% &rsquo; causes an
immediate return of EOF.</p>

<p style="margin-top: 1em"><b>RETURN VALUES</b></p>

<p style="margin-left:6%;">These functions return the number of input
items assigned, which can be fewer than provided for, or even zero, in
the event of a matching failure. Zero indicates that, while there was
input available, no conversions were assigned; typically this is due to
an invalid input character, such as an alphabetic character for a
&lsquo;%d&rsquo; conversion. The value EOF is returned if an input
failure occurs before any conversion such as an end-of-file occurs. If
an error or end-of-file occurs after conversion has begun, the number of
conversions which were successfully completed is returned.</p>

<p style="margin-top: 1em"><b>SEE ALSO</b></p>

<p style="margin-left:6%;">fgetwc(3), scanf(3), wcrtomb(3), wcstod(3),
wcstol(3), wcstoul(3), wprintf(3)</p>

<p style="margin-top: 1em"><b>STANDARDS</b></p>

<p style="margin-left:6%;">The <b>fwscanf</b>(), <b>wscanf</b>(),
<b>swscanf</b>(), <b>vfwscanf</b>(), <b>vwscanf</b>() and
<b>vswscanf</b>() functions conform to ISO/IEC 9899:1999
(&lsquo;&lsquo;ISO&nbsp;C99&rsquo;&rsquo;).</p>

<p style="margin-top: 1em"><b>BUGS</b></p>

<p style="margin-left:6%;">In addition to the bugs documented in
scanf(3), <b>wscanf</b>() does not support the
&lsquo;&lsquo;A-Z&rsquo;&rsquo; notation for specifying character ranges
with the character class conversion (&lsquo;<b>%[</b>&rsquo;).</p>

<p style="margin-left:6%; margin-top: 1em">BSD July&nbsp;5, 2003 BSD</p>
<hr> </body> </html>

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

