/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 11:41:14 by tgouedar          #+#    #+#             */
/*   Updated: 2019/01/12 16:40:52 by tgouedar         ###   ########.fr       */
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
 *	-> #	:	adds a prefixe 
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

# define KNOWN_CONV	"bcdfeginopsuxEFGX"
# define TYPE_START	22
# define KNOWN_FLAG	"#0+- '"
# define KNOW_LMOD "hhllL" /*care not to separate 'l's and 'h's*/
# define LMOD_START	12
# define LMOD_FLAG(a) (((((t_ul)1 << TYPE_START) - 1) & a) >> LMOD_START)
# define TYPE_FLAG(a) ((~((t_ul)0) & a->conv) >> TYPE_START)
# define TYPE_FLAG_POS(a) ((~((t_ul)0) & a->conv) >> (TYPE_START - LMOD_START))
# define STAR_FW 10
# define STAR_PR 11

typedef	unsigned long		t_ul;
typedef	unsigned long long	t_ull;

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

t_ull           ft_unsigned_conv(va_list *ap, int flag);
char			*ft_conv_binary(va_list *ap, t_ul type, t_pattern *conv);
char			*ft_conv_Uint(va_list *ap, t_ul type, t_pattern *conv);
char			*ft_conv_hex(va_list *ap, t_ul type, t_pattern *conv);
char			*ft_conv_octal(va_list *ap, t_ul type, t_pattern *conv);
long long       ft_signed_conv(va_list *ap, t_ul type, int flag);
char			*ft_conv_int(va_list *ap, t_ul type, t_pattern *conv);
char			*ft_conv_scient(va_list *ap, t_ul type, t_pattern *conv);
char			*ft_conv_float(va_list *ap, t_ul type, t_pattern *conv);
char			*ft_conv_opti_ef(va_list *ap, t_ul type, t_pattern *conv);
char			*ft_conv_addr(va_list *ap, t_ul type, t_pattern *conv);
char			*ft_conv_char(va_list *ap, t_ul type, t_pattern *conv);
char			*ft_conv_str(va_list *ap, t_ul type, t_pattern *conv);

/*
 ** ANY CHANGE TO VII SECTION WILL INDUCE >>>MASSIVE<<< CHANGES BELOW
 */

t_conv			g_convtab[] =
{
	{(1), &ft_conv_binary},
	{(1 << 1), &ft_conv_char},
	{(1 << 2), &ft_conv_int},
	{(1 << 3), &ft_conv_scient},
	{(1 << 4), &ft_conv_float},
	{(1 << 5), &ft_conv_opti_ef},
	{(1 << 6), &ft_conv_int},
//	{(1 << 7), &ft_conv_res},
	{(1 << 8), &ft_conv_octal},
	{(1 << 9), &ft_conv_addr},
	{(1 << 10), &ft_conv_str},
	{(1 << 11), &ft_conv_Uint},
	{(1 << 12), &ft_conv_hex},
	{(1 << 13), &ft_conv_scient},
	{(1 << 14), &ft_conv_float},
	{(1 << 15), &ft_conv_opti_ef},
	{(1 << 16), &ft_conv_hex}
};

int					ft_pattern_translate(char **str, t_pattern *pattern);
int					ft_parse_error(t_list **buff, t_pattern **pattern);
int					ft_pattern_detect(char *str, t_list **buff,
										t_pattern **pattern_list);
int					ft_translate_int(char **str);
void				ft_translate_flag(char **str, t_pattern *pattern);
int					ft_translate_lmod(char **str, t_pattern *pattern);
int					ft_translate_type(char **str, t_pattern *pattern);
int					ft_verif_nbr_arg(t_pattern **pattern, int min, int max);
t_ul				ft_int_flag(void);
void				ft_padding(t_pattern **pattern, t_list **conv);
#endif
