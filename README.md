# ft_printf
Basic test	=	94/197		Fails
undefined	=	29/40		Fails
moulitest	=	37/48		Fails
Curqui		=	95/233		Pass

       Basic tests          2/2
       Conv d-i-D           34/40
       Conv u-U             0/26
       Conv o-O             13/34
       Conv x-X             13/39
       Conv c               8/8
       Conv C               1/22
       Conv s               15/15
       Conv S               4/23
       Conv p               7/7
       Percent              12/12
       Mixed tests          1/5
       ----------------------------
       TOTAL                110/233
       ----------------------------

	Modifier          d, i           o, u, x, X
	hh                signed char    unsigned char
	h                 short          unsigned short
	l (ell)           long           unsigned long
	ll (ell ell)      long long      unsigned long long

	Modifier    a, A, e, E, f, F, g, G
    l (ell)     double (ignored, same behavior as without it)
    L           long double

unsigned char
signed char
unsigned short
short
unsigned long
long
unsigned long long
long long
double
long double

flag_space			/* for ' ' */
flag_plus			/* for '+' */
flag_minus			/* for '-' */
flag_hash			/* for '#' */
flag_zero			/* for '0' */

width_asterics		/* for '*' */
width				/* for '1'...'9' */
precision			/* for '.' */

mod_half			/* for 'h' */
mod_halfhalf
mod_long			/* for 'l' */
mod_longlong
