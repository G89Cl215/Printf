/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 15:22:28 by tgouedar          #+#    #+#             */
/*   Updated: 2019/01/16 20:12:05 by baavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "g_convtab.h"
#include <stdarg.h>

/*
 ** Recolle les bouts en lisant un buffer puis une chaine convertie,
 **	jusau'a epuisement de la liste chainee buffer.
 **	NB : La fonction doit avoir epuise les conversions avant le dernier
 **	buffer.
 **
 **	write la chaine de caractere creee et retourne la longueur totale de la
 **	chaine de caractere.
 */

int		ft_concat_buffer(t_list **buff, t_list **conv)
{
	int 	res;
	char	**str;
	char	**bus;
	t_list	*conv_cur;
	t_list	*buff_cur;

	conv_cur = *conv;
	buff_cur = *buff;
	ft_putendl("n");
	if (!(str = (char**)malloc(sizeof(char*))))
		return (0);
	if (!(bus = (char**)malloc(sizeof(char*))))
		return (0);
	*bus = NULL;
	*str = ft_strnew(0);
	while (buff_cur)
	{
		*bus = ft_strdup(buff_cur->content);
		ft_putendl("n1");
		ft_print_nods(buff_cur);
		ft_putendl(*bus);
		ft_strappend(str, bus);
		ft_putendl("n2");
		ft_putendl(*str);
		res = ft_strlen(*str);
		if (conv_cur)
		{
			if (!conv_cur->content)
				*bus = ft_itoa(res);
			else
			{
				*bus = ft_strdup(conv_cur->content);
				ft_putendl("n3");
				ft_putendl(*bus);
			}
			ft_strappend(str, bus);
			ft_putendl("n4");
			conv_cur = conv_cur->next;
		}
		buff_cur = buff_cur->next;
	}
	ft_putendl("n5");
	ft_putstr(*str);
	res = ft_strlen(*str);
	ft_memdel((void**)str);
	ft_lstfree(conv);
	ft_lstfree(buff);
	return (res);	
}


/*
 ** 	fonction qui permet d'organiser les va_args en fonction des ints adequate
 */


t_list	**ft_positional_conv(t_pattern **pattern, t_list **tmp)
{
	t_pattern *voyager;
	t_list	**conv;
	t_list	*bus;
	t_list	*sub;
	int		i;

	ft_putendl("e");
	if (!(conv = (t_list**)malloc(sizeof(t_list*))) 
			&& (!(*conv = ft_lstnew(0, 0))))
		return(NULL);
	ft_putendl("e1");
	voyager = *pattern;
	while (voyager)
	{
		ft_putendl("e2");
		bus = *tmp;
		ft_putendl("e3");
		ft_putnbr((int)voyager->nbr);
		i = 1;
		while (i < voyager->nbr)
		{
			ft_putendl("e4");
			i++;
			bus = bus->next;
		}
		ft_putendl("e5");
		ft_lstadd_back(conv, ft_lstnew(bus->content, (bus->content_size)));
		ft_putendl("e6");
		voyager = voyager->next;
		ft_putendl("e7");
	}
	ft_lstfree(tmp);
	return (conv);
}



/*
 **	On verifie ensuite que les casts de chaque parametre ne soient pas conflictuels
 **	Si ca n'est pas le cas, on cree la liste chainee des params castes dans le type
 **	adequat et on remplace les precisions / field_width positionnels par leurs valeurs
 */
int		ft_verif_type(int i, t_pattern **pattern, t_list **tmp, va_list *ap)
{
	t_pattern	*voyager;
	t_ul		type;
	t_pattern	*ezequiel;
	char		*str;
	int			j;

	type = 0;
	voyager = *pattern;
	ezequiel = *pattern;
	while (voyager)
	{
		ft_putendl("v12");
		if (voyager->nbr == i)
		{
			ft_putendl("v13");
			if (!type)
			{
				type = ft_type_flag_pos(voyager);
				ft_putnbr(ft_type_flag_pos(voyager));
				ft_putendl("v14");
			}
			else if (!(ft_type_flag_pos(voyager) & type)
					|| !((((ft_int_flag() & type) < ft_int_flag()) && ((ft_int_flag() & ft_type_flag_pos(voyager)) < ft_int_flag()))
						&& !(ft_lmod_flag(voyager->conv) & (type & (((t_ul)1 << ft_strlen(KNOWN_LMOD)) - 1)))))
			{
				ft_putnbr(ft_type_flag_pos(voyager));
				return (ft_parse_error(2, tmp, pattern));
			}
		}
		ft_putendl("v15");
		if ((voyager->precision == i && (voyager->conv ^ (1 << STAR_PR)))
				|| (voyager->field_width == i && (voyager->conv ^ (1 << STAR_FW))))

		{
			ft_putendl("d");
			if (!type)
			{
				type = ((t_ul)1 << ft_indice('d', KNOWN_CONV));
				ft_putendl("d2");
			}
			else if (((((ft_int_flag() ^ type) < ft_int_flag()))
						&& !(type & (((t_ul)1 << ft_strlen(KNOWN_LMOD)) - 1))))
			{	
				ft_putendl("g");
				return (ft_parse_error(2, tmp, pattern));
			}
		}
		voyager = voyager->next;
	}
	ft_putendl("v16");
	if ((ft_int_flag() ^ type) < ft_int_flag() && !(type & (((t_ul)1 << ft_strlen(KNOWN_LMOD)) - 1)))
	{
		j = (t_ull)va_arg(*ap, int);
		str = ft_itoa(j);
		voyager = *pattern;
		while (voyager)
		{
			if (voyager->precision == i && (voyager->conv & (1 << STAR_PR)))
			{
				voyager->precision = j;
				voyager->conv ^= (1 << STAR_PR);
			}
			if (voyager->field_width == i && (voyager->conv & (1 << STAR_FW)))
			{
				voyager->field_width = j;
				voyager->conv ^= (1 << STAR_FW);
			}
			voyager = voyager->next;
		}
		ft_putendl("v15");
	}
	else
	{
		while (ezequiel->next != NULL)
		{

			ft_putendl("v16");
			j = 0;
			while (g_convtab[j].type != ft_type_flag(ezequiel))
			{
				ft_putendl("v15");
				j++;
			}
			str = (*g_convtab[j].ft_conv)(ap, ezequiel->conv, ezequiel);
			ft_putendl(str);
			ft_lstadd_back(tmp, ft_lstnew(str, (strlen(str) + 1)));
			ezequiel = ezequiel->next;	
		}
	}
	ft_putendl("s");
	ft_print_nods(*tmp);
	return (1);
}


/*
 **	Lorsque le flag positionnel est active, apres le parsing,
 **	on verifie que tous les arguments invoques sont atteignables
 **	dans notre va_list
 */

int		ft_verif_nbr_arg(t_pattern **pattern, int min, int max)
{
	t_pattern	*voyager;

	voyager = *pattern;
	ft_putendl("B0");
	while (voyager)
	{
		ft_putendl("B1");
		ft_putnbr((int)voyager->nbr);
		if (voyager->nbr > max)
			max = voyager->nbr;
		ft_putendl("B2");
		ft_putnbr(voyager->nbr);
		if ((voyager->conv ^ (1 << STAR_PR)) && voyager->precision > max)
			max = voyager->precision;
		ft_putendl("B3");
		ft_putnbr(voyager->precision);
		if ((voyager->conv ^ (1 << STAR_FW)) && voyager->field_width > max)
		{
			max = voyager->field_width;
			ft_putendl("B4");
			ft_putnbr(voyager->field_width);
		}
		if (voyager->nbr == min + 1
				|| (voyager->precision == min + 1 && (voyager->conv ^ (1 << STAR_PR)))
				|| (voyager->field_width == min + 1 && (voyager->conv ^ (1 << STAR_FW))))
			return (ft_verif_nbr_arg(pattern, min + 1, max));
		ft_putendl("B5");
		ft_putnbr(max);
		voyager = voyager->next;
	}
	ft_putnbr(max);
	ft_putnbr(min);
	return ((min == max) ? max : 0);
}

/*
 **	Detecte si positionnal mod est actif - si oui go parse -
 **	si non go liste de conversion
 */

t_list	**ft_positional_mod(t_pattern **pattern, va_list *ap)
{
	t_pattern	*voyager;
	t_list		**tmp;
	int			i;
	int			max;

	voyager = *pattern;
	if (!(tmp = (t_list**)malloc(sizeof(t_list*))))
		return (NULL);
	*tmp = NULL;
	ft_putendl("A2");
	ft_putnbr((int)voyager->nbr);
	if ((max = ft_verif_nbr_arg(pattern, 0, 0)))
	{
		ft_putendl("A23");
		ft_putnbr(max);
		i = 0;
		while (i < max)
		{
			ft_putendl("v1");
			i++;
			if (!(ft_verif_type(i, pattern, tmp, ap)))
				return (NULL);
			ft_putendl("v2");
		}
		ft_putendl("v3");
		return (ft_positional_conv(pattern, tmp)); // devra free tmp
	}
	else
		ft_parse_error(1, tmp, pattern);
	return (NULL);
}

/*
 **  Conversions en strings de la bonne longueur
 */

t_list		**ft_conv(t_pattern **pattern, va_list *ap, t_list **buff)
{
	t_pattern	*voyager;
	t_list		**conv;
	char		*str;
	int			i;
	int			c;

	voyager = *pattern;
	if (!(conv = (t_list**)malloc(sizeof(t_list*))))
		return (NULL);
	*conv = NULL;
	if (voyager->conv % 2)
	{
		if (!(conv = ft_positional_mod(pattern, ap)))
			return(NULL);
		ft_putendl("A1");
	}	
	else
	{	
		ft_putendl("L");
		c = 0;
		while (voyager)
		{
			c++;
			i = 0;
			while (g_convtab[i].type != ft_type_flag(voyager))
			{
				ft_putendl("12o");
				i++;
			}
			ft_putendl("Ll");
			str = (*g_convtab[i].ft_conv)(ap, voyager->conv, voyager);
			if (str)
			{
				ft_putendl("w");
				ft_putendl(str);
				ft_lstadd_back(conv, ft_lstnew(str, (ft_strlen(str) + 1)));
				ft_print_nods(*conv);
			}
			else
			{
				ft_lstadd_back(conv, ft_lstnew(NULL, 0));
				ft_putendl("M");
//				ft_stock_n_char(conv, ap, buff, c);
				ft_putendl("M1");
			}
			voyager = voyager->next;
		}
	}
	ft_putendl("A2");
	ft_padding(pattern, conv);
	ft_putendl("A3");
	//	ft_lstfree(pattern); incompatible avec le type t_pattern
	return (conv);
}

int		ft_printf(const char * restrict format, ...)
{

	va_list		ap;
	char		*str;
	t_pattern	**pattern;
	t_list		**buff;
	t_list		**conv;

	str = ft_strdup(format);
	ft_putendl(str);
	if (!(pattern = (t_pattern**)malloc(sizeof(t_pattern*))) ||
			!(buff = (t_list**)malloc(sizeof(t_list*))))
	{
		//du free ici
		return (-1);
	}
	*pattern = NULL;
	*buff = NULL;
	if ((ft_pattern_detect(str, buff, pattern)))
	{
		ft_putendl("A");
		ft_putendl(str);
		va_start(ap, format);
		ft_putendl("A");
		if (!(conv = ft_conv(pattern, &ap, buff)))
		{
			va_end(ap);
			return (-1);
		}
		ft_putendl("A");
		va_end(ap);
		free(str);
		return (ft_concat_buffer(buff, conv));
	}
	//ici aussi
	free(str);
	return (-1);
}
