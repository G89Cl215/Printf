/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#[+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 15:22:28 by tgouedar          #+#    #+#             */
/*   Updated: 2019/01/11 15:02:45 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
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
	char	*str;
	t_list	*conv_cur;
	t_list	*buff_cur;

	conv_cur = *conv;
	buff_cur = *buff;
	while (buff_cur)
	{
		ft_strappend(str, (char*)(buff_cur->data));
		res = ft_strlen(str):
			if (conv_cur)
		{
			ft_strappend(str, (char*)(conv_cur->data));
			conv_cur = conv_cur->next;
		}
		buff_cur = buff_cur->next;
	}
	ft_putstr(str);
	ft_memdel(&str);
	res = ft_strlen(str);
	ft_lstfree(conv);
	ft_lstfree(buff);
	return (res);	
}

int		ft_verif_type(int i, t_pattern **pattern, t_list *tmp, va_list **ap)
{
	t_pattern	*voyager;
	t_ul		type;
	char		*str;
	int			j;

	type = 0;
	voyager = *pattern;
	while (voyager)
	{
		if (voyager->nbr == i)
		{
			if (!type)
				type = TYPE_FLAG_POS(voyager);
			else if ((TYPE_FLAG_POS(voyager) ^ type)
					|| !((((INT ^ type) < INT) && ((INT ^ TYPE_FLAG_POS(voyager)) < INT))
					&& !(LMOD_FLAG(voyager) ^ (type & (((t_ul)1 << ft_strlen(KNOW_LMOD)) - 1)))))
				return (0);
		}
		if ((voyager->precision == i && (voyager->conv & (1 << STAR_PR)))
				|| (voyager->field_width == i && (voyager->conv & (1 << STAR_FW))))

		{
			if (!type)
				type = ((t_ul)1 << ft_indice('d', KNOWN_CONV));
			else if (!((((INT ^ type) < INT))
					&& !(type & (((t_ul)1 << ft_strlen(KNOW_LMOD)) - 1))))
				return (0);
		}
		voyager = voyager->next;
	}
	if ((INT ^ type) < INT && !(type & (((t_ul)1 << ft_strlen(KNOW_LMOD)) - 1)))
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
	}
	else
	{
		j = 0;
		while (g_convtab[j].type != (type >> (TYPE_START - LMOD_START)))
			j++;
		str = (*g_convtab[j])(ap, (type << LMOD_START));
	}
	ft_lstadd_back(conv, ft_lstnew(str, strlen(str)));
	return (1);
}

/*
 **  Lorsque le flag positionnel est active, apres le parsing,
 ** on verifie que tous les arguments invoques sont atteignables
 **  dans notre va_list
 */

int		ft_verif_nbr_arg(t_pattern **pattern, int min, int max)
{
	t_pattern	*voyager;

	voyager = *pattern;
	while (voyager)
	{
		if (voyager->nbr > max)
			max = voyager->nbr;
		if ((voyager->conv & (1 << STAR_PR)) && voyager->precision > max)
			max = voyager->precision;
		if ((voyager->conv & (1 << STAR_FW)) && voyager->field_width > max)
			max = voyager-field_width;
		if (voyager->nbr == min + 1
				|| (voyager->precision == min + 1 && (voyager->conv & (1 << STAR_PR)))
				|| (voyager->field_width == min + 1 && (voyager->conv & (1 << STAR_FW))))
			return (ft_verif_nbr_arg(pattern, min + 1, max))
		voyager = voyager->next;
	}
	return ((min == max) ? max : 0);
}

/*
 **  Detecte si positionnal mod est actif - si oui go parse -
 ** si non go liste de conversion
 */

t_list	*ft_positional_mod(t_pattern **pattern, va_list *ap)
{
	t_pattern	*voyager;
	t_list		**tmp;
	int			i;
	int			max;

	i = 0;
	voyager = *pattern;
	tmp = malloc;
	if (max = ft_verif_nbr_arg(pattern, 0, 0))
	{
		while (i++ <= max)
		{
			if (!(ft_verif_type(i, pattern, *tmp, ap)))
				return (NULL);
		}
		return (ft_positional_conv(pattern, tmp)); // devra free tmp
	}
	return (NULL);
}

/*
 **  Conversions en strings de la bonne longueur
 */

t_list		**ft_conv(t_pattern **pattern, va_list *ap)
{
	t_pattern	*voyager;
	t_list		**conv;
	char		*str;
	int			i;
	int			type;
	int			flag;

	voyager = *pattern;
	if (!(conv = (t_list**)malloc(sizeof(t_list*))))
		return (NULL);
	if (voyager->conv % 2)
		*conv = ft_positional_mod(pattern, ap);
	else
	{	
		while (*voyager)
		{
			i = 0;
			while (g_convtab[i].type != TYPE_FLAG(voyager))
				i++;
			str = (*g_convtab[i])(ap, voyager);



			ft_lstadd_back(conv, ft_lstnew(str, strlen(str)));
			voyager = voyager->next;
		}
	}
	ft_padding(pattern, conv);  // a ecrire
	ft_lstfree(pattern);
	return (conv);
}

int		ft_printf(const char * restrict format, ...)
{

	va_list		ap;
	char		*str;
	t_pattern	**pattern;
	t_list		*buff;
	t_list		**conv;

	str = ft_strdup(format);
	if (!(pattern = (t_pattern**)malloc(sizeof(t_pattern*))) ||
			!(buff = (t_list**)malloc(sizeof(t_list*))))
	{
		//du free ici
		return (-1);
	}
	if (ft_pattern_detect(str, buff, pattern))
	{
		va_start(format, ap);
		conv = ft_conv(pattern, &ap);
		va_end(ap);
		free(str);
		return (ft_concat_buffer(buff, conv));
	}
	//ici aussi
	free(str);
	return (-1);
}
