# ft_printf

## About this printf
This printf is **malloc-free** and **use a buffer** to reduce his system calls to write.   
It use global conversion table to direcly apply the right conversion function, **No else if required**.

### Structs & Buffer
The buffer is allocated in the stack and it uses less than 3kb.   
```t_data``` is my env, it hold :
```
idx     : current index for the buffer.
carry   : Return value of the printf, everytime we write to stdout it add the idx value to the carry.
conf    : Conf generate everytime there is a %. It store all the padding and such parameters. More on that below.
buff    : Char buffer where the conversion function write.
tmp     : temp buffer for itob functions (before padding for ex).
```
```t_config``` is generated by format_parser,
It built when there is stuff between the '%' and the conversion, it hold:
```
conv    : Conversion char (for debug).
flags   : Bitwise flags (see [ft_printf.h](includes/ft_printf.h). for more)
space   : Space count
prec    : Precision
width   :
rpad    : Right padding
zpad    : Zero padding
```
README#L18
### g_conv g_mod
It use a conversion table ```g_conv``` define in [ft_conv.h](includes/ft_conv.h).
It is a array of function pointer that return the number of char written into the buffer.   
The conversion and the call to the g_conv is in [ft_process](srcs/ft_printf.c) :
f_unkn is a dummy function to still know that if :
> g_conv[(int)c] != NULL

then c is a conversion.    
g_mod is only uses to check if this is a valid modifier char.

### Functions:
```itob``` or ```ulltob``` are like itoa but they don't allocate they write into a buffer.    
All the form_*.c are conversion functions in the table g_conv.
### Makefile
> make curqui

Rebuilt the project and run curqui test on it.
It will create a folder on the parent directory of the makefile for the curci repo.
> make run

Rebuilt the project and run test.c.
This is a detail output for the current work cases.


## To do :
- [ ] d-i-D (WIP Nico)
- [ ] u-U
- [ ] x-X
- [ ] float
- [ ] Use g_mod table
- [ ] Unit test ?
- [ ] Refactor

## Current test results:
```
Basic test	=	77/182		Fails
undefined	=	40/55		Fails
moulitest	=	37/48		Fails (timeout)
PFT         =   784/1765    Pass
Curqui		=	110/233		Pass
```
```
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
```
## Notes:
```
Modifier          d, i           o, u, x, X
hh                signed char    unsigned char
h                 short          unsigned short
l (ell)           long           unsigned long
ll (ell ell)      long long      unsigned long long

Modifier    a, A, e, E, f, F, g, G
l (ell)     double (ignored, same behavior as without it)
L           long double
```
All the types
```
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
```
Name ideas from the GNU LIBC printf
```
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
```