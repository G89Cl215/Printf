/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing3_pos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 15:51:47 by tgouedar          #+#    #+#             */
/*   Updated: 2019/01/20 16:51:05 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

void	ft_pos_pr_fw(int i, t_pattern **pattern, t_list **tmp, va_list *ap)
{
	t_pattern	*voyager;
	char		*str;
	int			flag;
	int			j;

	j = va_arg(*ap, int);
	flag = 0;
	voyager = *pattern;
	str = ft_itoa(j);
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
		if (voyager->nbr == i && !(flag++))
			ft_lstadd_back(tmp, ft_lstnew(str, (strlen(str) + 1)));
		voyager = voyager->next;
	}
}

/*
 ** 	fonction qui permet d'organiser les va_args en fonction des ints adequats
 */

t_list	**ft_positional_conv(t_pattern **pattern, t_list **tmp)
{
	t_pattern	*voyager;
	t_list		**conv;
	t_list		*bus;
	int			i;

	if (!(conv = (t_list**)malloc(sizeof(t_list*))) 
			&& (!(*conv = ft_lstnew(0, 0))))
		return(NULL);
	voyager = *pattern;
	while (voyager)
	{
		bus = *tmp;
		i = 1;
		while (i++ < voyager->nbr)
			bus = bus->next;
		ft_lstadd_back(conv, ft_lstnew(bus->content, (bus->content_size)));
		voyager = voyager->next;
	}
	ft_lstfree(tmp);
	return (conv);
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
	while (voyager)
	{
		if (voyager->nbr > max)
			max = voyager->nbr;
		if ((voyager->conv ^ (1 << STAR_PR)) && voyager->precision > max)
			max = voyager->precision;
		if ((voyager->conv ^ (1 << STAR_FW)) && voyager->field_width > max)
			max = voyager->field_width;
		if (voyager->nbr == min + 1
				|| (voyager->precision == min + 1 && (voyager->conv ^ (1 << STAR_PR)))
				|| (voyager->field_width == min + 1 && (voyager->conv ^ (1 << STAR_FW))))
			return (ft_verif_nbr_arg(pattern, min + 1, max));
		voyager = voyager->next;
	}
	return ((min == max) ? max : 0);
}

/*
 **	On verifie ensuite que les casts de chaque parametre ne soient pas
 **	conflictuels.
 **	Si ca n'est pas le cas, on cree la liste chainee des params castes dans le
 **	type adequat et on remplace les precisions / field_width positionnels par
 **	leurs valeurs.
 */

int		ft_verif_type(int i, t_pattern **pattern, t_list **tmp, va_list *ap)
{
	t_pattern	*voyager;
	t_ul		type;

	type = 0;
	voyager = *pattern;
	while (voyager)
	{
		if (voyager->nbr == i)
		{
			if (!type)
				type = ft_type_flag_pos(voyager);
			else if (!(ft_type_flag_pos(voyager) & type)
				|| !((((ft_int_flag() & type) < ft_int_flag())
				&& ((ft_int_flag() & ft_type_flag_pos(voyager)) < ft_int_flag()))
				&& !(ft_lmod_flag(voyager) ^ (type & (((t_ul)1 << ft_strlen(KNOWN_LMOD)) - 1)))))
				return (ft_parse_error(2, tmp, 0, pattern));
		}
		if ((voyager->precision == i && (voyager->conv ^ (1 << STAR_PR)))
				|| (voyager->field_width == i && (voyager->conv ^ (1 << STAR_FW))))
		{
			if (!type)
				type = ((t_ul)1 << ft_indice('d', KNOWN_CONV));
			else if (((ft_int_flag() ^ type) > ft_int_flag())
						|| (type & (((t_ul)1 << ft_strlen(KNOWN_LMOD)) - 1)))
				return (ft_parse_error(2, tmp, 0, pattern));
		}
		voyager = voyager->next;
	}
	if ((ft_int_flag() ^ type) < ft_int_flag()
			&& !(type & (((t_ul)1 << ft_strlen(KNOWN_LMOD)) - 1)))
		ft_pos_pr_fw(i, pattern, tmp, ap);
	else
		ft_ezequiel(*pattern, tmp, ap);
	return (1);
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
	if ((max = ft_verif_nbr_arg(pattern, 0, 0)))
	{
		i = 0;
		while (i < max)
		{
			i++;
			if (!(ft_verif_type(i, pattern, tmp, ap)))
				return (NULL);
		}
		return (ft_positional_conv(pattern, tmp));
	}
	else
		ft_parse_error(1, tmp, 0, pattern);
	return (NULL);
}
