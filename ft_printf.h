/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 11:41:14 by tgouedar          #+#    #+#             */
/*   Updated: 2019/01/20 16:51:00 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/* >>>GUIDE ON PRINTF OPTIONS<<<
 * 
 * I_ Global Output
 *
 * 		Printf reads the first param, which is always a string.
 * 	Any pattern in this string starting with  '%'  and recognized by printf will
 * 	be swapped with one of the next params. this param will take a specific form
 * 	(conversion) according to what is specified by the pattern (an int can be
 * 	converted into a given base, etc). By default, the first recognized pattern
 * 	will be swapped with the first param and so on.
 * 		The number of params must match the number of patterns. There must
 * 	not be unused params.
 *
 * 		Once all of the patterns are swapped with converted params, the final
 * 	string is outputted standard output and the number of outputted char is
 * 	returned by the function.
 * 		In case of error, a negative value is returned.
 *
 *
 * II_ Recognized Patterns
 *
 *	%[int$][flag][f_w(int\*[int$])][prec(.int\.*[int$])][l_modif]type (.)?
 *
 *	-> field_width : fixed int value (either written in the pattern or written
 *	in the next param and referred to thanks to the  '*'  char). The diff with 
 *	the length of param will be padded according to the flag. If there is no
 *	flag then the padding is filled with spaces and he param is aligned with the
 *	right of the padding.
 *
 *	-> precision :	a  '.'  followed by a fixed int value.
 *					Or a  '.*'  which fetches the precision value in the next
 *	param converted into an int.
 *					If  '.'  and  '*'  are both together and in this order, the
 *	  '.'  symbol stands for the 0 flag (see below. Identified through test).
 *	With  '*'  , a negative value will be ignored. A precision of 0 will ignore
 *	a 0 output.
 *	. An int type will dipslay at least this amount of digits.
 *	. A float type will display this amount of digit after the "float-point".
 *	. A string type will display at most this amount of char.
 *	. For a scientific conversion it will the number of significant digits.
 *	(NB : you need  -  flag for negative int to be displayed with a
 *	precision.)
 *
 *	-> length_modifier : a prefixe to type that specifies the size of the param.
 *
 *
 * III_ Types printf can handle
 *
 *		Each of the following letter represents a type and allows printf to
 *	know how to cast accordingly the parameters it takes.
 *	-> c	: the param is a char.
 *	-> s	: the param is a char* / string.
 *	-> d	: the param is an int ouputed in decimal base.
 *	-> i	: the param is an int ouputed in decimal base.
 *	-> o	: the param is an unsigned int converted in octal base.
 *	-> u	: the param is an unsigned int in decimal base.
 *	-> x/X	: the param is an unsigned int converted to hexadecimal base.
 *				(the abcdef chars of the base are capitalized or not if x is)
 *	-> n 	: the param is curent value of printf fonction.
 *				(One less param is needed)
 *	-> b 	: the param is an unsigned int converted in binary base.
 *	-> e/E 	: the param is an int value in scientific notation.
 *				(e = 10^ is capitalized if e is)
 *	-> f/F	: the param is a float.
 *	-> g/G	: the param is an int value that is the shortest between e and f.
 *				(or E and F if g is capitalized)
 *	-> p	: the param is the address of a pointer (void* type).
 *	-> %	: allows to output the  '%'  char.
 *
 *
 * IV_ Available flags
 *
 *		Specifies how padding is made. More than one can be specified but there
 *	can be 'unknown behaviours'
 *	-> #	:	adds a prefixe according to chosen base 
 *	-> 0	: 	for int and float types the padding is filled with zeros 
 *				(ignored for none value type)
 *	-> +	:	outputs a positive sign to positive values.
 *	-> -	:	the param is aligned with the left of the padding.
 *	-> '	:	the decimal values are separated by blocs of 3
 *				(thousand, million >>>)
 *	-> ' '	:	the 'space' flag allows to output a space before positive 
 *				and empty values in signed values.
 *				NB : is ignored when + flag is active 
 *
 *
 * V_ Length Modifier list
 *
 * 		Changes the length of memory read to fill in the param ?
 * 		
 *	Type			d, i			b, B, o, u, x, X	n
 *	
 *	Modifier
 *	hh				signed char		unsigned char		signed char *
 *	h               short			unsigned short		short *
 *	l (ell)         long			unsigned long		long *
 *	ll (ell ell)    long long		unsigned long long	long long *
 * [j               intmax_t		uintmax_t			intmax_t *
 *	t               ptrdiff_t		(see note)			ptrdiff_t *
 *	z               (see note)		size_t				(see note)
 *	q (deprecated)  quad_t			u_quad_t			quad_t *]
 *	L				
 *
 * VI_ The $ Flag
 *
 *		By default the param are treated the way they come but specifying an
 *	int value m followed by  '$'  will call the param placed m in the list of
 *	params. This can occur after  '%'  and  '*'  to choose the param you want.
 *	If one $ (positional flag) is specified, all of the pattern must bear this
 *	flag when invoking a param. One param can be referred to twice. If so, then
 *	one less param is needed.
 *	NB : this flag starts counting from one not zero.
 *
 *	Example :
 *		printf("[%1$*2$d]", 4, 42);
 *			Will output 4 padded in 42 spaces.
 *			[                                          4]
 *
 *
 * VII_ My Flag management /!\ THIS SECTION CAN BE SUBMITTED TO CHANGE
 *
 * 	Type, flags, length_mofifiers and precision star flag will be stocked in an
 * 	long int were the options will be stored as triggered bits. There is
 * 	potential in extending the fonctionnalities of printf with up to 3 more
 * 	flags, 5 more length_modifiers and 26 more conversion types.
 *
 *	Currently the l_int is mapped thusly (care not to separate 'l's and 'h's,
 *	the second one stands for double the letter) :
 *	
 *	[$#0+-' ...**hhllL.....bcdefginopsuxEFGX.........................]
 *   ^      ^       ^       ^       ^       ^       ^       ^       ^     
 * 	 0		7		15		23		31		39		47		55		63	: bit_nb
 *
*/

/*
** ANY CHANGE TO VII SECTION WILL INDUCE CHANGES BELOW
*/

# include <stdarg.h>
# include <stdlib.h>
# include "libft/libft.h"

/* done : bcdinousxX
 * p : prefixe
 * to do : fegEFG
 * idees supplementaires du sujet : r pour les caracteres non imprimables,
 * 									k pour les dates
 * 									fd ?!?
 * doc on floats :
 * input given by va_arg
 * floating point type represented as 3 sections of unsigned word (size 1, 2, 4, 8 bytes) :
 * float = 4 bytes
 * double = 8 bytes
 * first section single bit for sign.
 * second is exponent of base 2
 * third = mantissa : significatn digits, in binary.
 * main problem in printing float = base conversion.
 * to solve : optimization division and modulo in 64 bits.
 * trick to convert base properly : where the unit (where the radix to the power 0, where the floating point is positioned) = point in a floating point number is the fundamental limit.
 * left side of the point handed by itoa_base protocol.
 * right side, fractional part, weirder : example -> powers = 5 in base 10 for negative powers of 2 (1/2 = 0.5, 1/4 = 0.25, 1/8 = 0.125 etc.).
 * float strings : must be able to implement your own "bigint" type and all basic operations using both uint arrays and/or strings of digits in a given base for as speedy and accurate arbitrary precision arithmetic.
 * 3 format : %a (hexadecimal floating point), %e (exponential/scientific notation) and %f (decimal point notation). %g is a weird mix of %e and %f.
 * For %a, itoa, uitoa_base and an understanding of floats suffices.
 *
*/
# define KNOWN_CONV	"bcdfeginopsuxEFGX"
# define TYPE_START	22
# define KNOWN_FLAG	"#0+- '"
# define KNOWN_LMOD "hhllL" /*care not to separate 'l's and 'h's*/
# define LMOD_START	12
# define STAR_FW 10
# define STAR_PR 11

typedef	unsigned long		t_ul;
typedef	unsigned long long	t_ull;

typedef union
{
	double	d;
	t_ul	l;
} 							u_float;

typedef struct				s_type_and_flag
{
	t_ul						conv;
	int							field_width;
	int							precision;
	int							nbr;
	struct s_type_and_flag		*next;
}							t_pattern;

typedef struct				s_conversion
{
	t_ul			type;
	char			*(*ft_conv)(va_list *ap, t_ul type, t_pattern *conv);
}							t_conv;

t_ull				ft_num_conv(va_list *ap, int flag);
long long       	ft_signed_conv(va_list *ap, t_ul type, int flag);
char				*ft_conv_binary(va_list *ap, t_ul type, t_pattern *conv);
char				*ft_conv_uint(va_list *ap, t_ul type, t_pattern *conv);
char				*ft_conv_hex(va_list *ap, t_ul type, t_pattern *conv);
char				*ft_conv_octal(va_list *ap, t_ul type, t_pattern *conv);
char				*ft_conv_int(va_list *ap, t_ul type, t_pattern *conv);
char				*ft_conv_res(va_list *ap, t_ul type, t_pattern *conv);
char				*ft_conv_scient(va_list *ap, t_ul type, t_pattern *conv);
char				*ft_conv_float(va_list *ap, t_ul type, t_pattern *conv);
char				*ft_conv_opti_ef(va_list *ap, t_ul type, t_pattern *conv);
char				*ft_conv_addr(va_list *ap, t_ul type, t_pattern *conv);
char				*ft_conv_char(va_list *ap, t_ul type, t_pattern *conv);
char				*ft_conv_str(va_list *ap, t_ul type, t_pattern *conv);
int					ft_stock_n_char(t_list **conv, va_list *ap, t_list **buff, int c);

int					ft_pattern_translate(char **str, t_pattern *pattern);
int					ft_pattern_detect(char *str, t_list **buff,
										t_pattern **pattern_list);

int					ft_translate_int(char **str);
void				ft_translate_flag(char **str, t_pattern *pattern);
int					ft_translate_lmod(char **str, t_pattern *pattern);
int					ft_translate_f_w(char **str, t_pattern *pattern);
int					ft_translate_precision(char **str, t_pattern *pattern);
int					ft_translate_type(char **str, t_pattern *pattern);

int					ft_parse_error(int flag, t_list **buff, t_list **conv,
																t_pattern **pattern);

int					ft_verif_nbr_arg(t_pattern **pattern, int min, int max);
int					ft_verif_type(int i, t_pattern **pattern, t_list **tmp, va_list *ap);
t_list				**ft_positional_conv(t_pattern **pattern, t_list **tmp);
void				ft_pos_pr_fw(int i, t_pattern **pattern, t_list **tmp, va_list *ap);

t_list				**ft_conv(t_pattern **pattern, va_list *ap, t_list **buff);
void				ft_ezequiel(t_pattern *ezequiel, t_list **tmp, va_list *ap);

void				ft_padding(t_pattern **pattern, t_list **conv);

t_ul				ft_int_flag(void);
t_ul				ft_type_flag(t_pattern *pattern);
t_ul				ft_lmod_flag(t_pattern *pattern);
t_ul				ft_type_flag_pos(t_pattern *pattern);
t_ul				ft_t_ul_flag(t_ul conv);

t_pattern			*ft_new_pattern(t_pattern **pattern_list);
void				ft_free_pattern(t_pattern **pattern);

int					ft_printf(const char * restrict format, ...);

#endif
