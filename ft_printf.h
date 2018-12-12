/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 11:41:14 by tgouedar          #+#    #+#             */
/*   Updated: 2018/12/12 22:11:30 by tgouedar         ###   ########.fr       */
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
 *	%[int$][flag][field_width][precision=(.int || *int$)][length_modif]type
 *
 *	-> field_width : fixed int value (either written in the pattern or written
 *	in the next param and referred to thanks to the  '*'  char). The diff with 
 *	the length of param will be padded according to the flag. If there is no flag
 *	then the padding is filled with spaces and he param is aligned with the left
 *	of the padding.
 *
 *	-> .precision : a  '.'  followed by a fixed int value (either written in the
 *	pattern or written in the next param and referred to thanks to the  '*'  char).
 *	A negative value will be ignored. A precision of 0 will ignore a 0 output.
 *	. An int type will dipslay at least this amount of digits.
 *	. A float type will display this amount of digit after the "float-point".
 *	. A string type will display at most this amount of char.
 *
 *	(NB : you need  -  flag for negative int to be displayed with a
 *	precision.)
 *
 *	-> length_modif : a prefixe to type that specifies the size of the param.
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
 *	-> a/A	: the param is a (C++ specific).
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
 *	-> '	:	the decimal values are separated by blocs of 3 (thousand, million >>>)
 *	-> ' '	:	the 'space' flag allows to output a space before positive 
 *				and empty values in signed values.
 *				NB : is ignored when + flag is active 
 *
 *
 * V_ Length Modifier list
 *
 * 		Changes the length of memory read to fill in the param ?
 * 		
 *	Type			d, i			o, u, x, X			n
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
 *	If one $ (positional flag) is specified, all of the pattern must bear this flag 
 *	when invoking a param. One param can be referred to twice. If so, then one less
 *	param is needed.
 *	NB : this flag starts counting from one not zero.
 *
 *	Example :
 *		printf("[%1$*2$d]", 4, 42);
 *			Will output 4 padded in 42 spaces.
 *			[                                          4]
 */	

# define KNOWN_CONV	"abcdfiopsuxFX"
# define KNOWN_FLAG	"#0+- '"
# define KNOW_LMOD	"lhL"

typedef struct		s_type_and_flag
{
	char			type;
	int				field_width;
	char			*flag;
	int				precision;
	int				precision_nbr;
	char			*length_modif;
	int				nbr;
}					t_pattern;

typedef struct		s_conversion
{
	char			type;
	void			(*ft_conv)();
}					t_conv;

#endif
