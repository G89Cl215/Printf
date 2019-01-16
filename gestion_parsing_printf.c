/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_parsing_printf.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 17:02:05 by tgouedar          #+#    #+#             */
/*   Updated: 2019/01/16 18:43:46 by baavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*	Quelques fonctions de gestin de la nouvelle liste chainee
 */

t_pattern	*ft_new_pattern(t_pattern **pattern_list)
{
	t_pattern	*new;
	t_pattern	*voyager;

			ft_putendl("1");
	if (!(new = (t_pattern*)malloc(sizeof(t_pattern))))
		return (NULL);
			ft_putendl("2");
	new->conv = 0;
	new->field_width = -1;
	new->precision = -1;
	new->nbr = 0;
	new->next = NULL;
			ft_putendl("3");
	if (!(*pattern_list))
	{
		ft_putendl("4");
		*pattern_list = new;
	}
	else
	{
			ft_putendl("5");
		voyager = *pattern_list;
		while (voyager->next)
			voyager = voyager->next;
		voyager->next = new;
	}
			ft_putendl("6");
	return (new);
}

/*	Cette fonction traduit le pattern et renvoie 0 s'il est invalide, 1 s'il est
 *	valide et non positionnel et 2 s'il est positionnel.
 */

int			ft_pattern_translate(char **str, t_pattern *pattern)
{
	int		i;
	
	if (ft_isdigit(**str))
	{
		if (**str == '0')
			pattern->conv = (t_ul)2 << ft_indice('0', KNOWN_FLAG);
		i = ft_atoi(*str);
		ft_putendl("o");
		ft_putendl(*str);
		while (**str && ft_isdigit(**str))
		{
			(*str)++;
			ft_putendl(*str);
			ft_putnbr(i);
		}
		if (**str == '$' && (*str)++)
		{	
			pattern->conv++;
			ft_putendl("e");
			ft_putnbr(i);
			pattern->nbr = i;
			ft_translate_flag(str, pattern);
			if (!(ft_translate_f_w(str, pattern)))
				return (0);
			ft_putendl("f");
			ft_putendl(*str);
		}
		else
			pattern->field_width = i;
	}
	else
	{
		ft_putendl("g");
		ft_translate_flag(str, pattern);
		ft_putendl(*str);
		if (!(ft_translate_f_w(str, pattern)))
				return (0);
	}
		ft_putendl("l");
		ft_putendl(*str);
	if ((!(ft_translate_precision(str, pattern)))
					|| !(ft_translate_lmod(str, pattern)))
		return (0);
		ft_putendl("u");
		ft_putendl(*str);
	if (ft_translate_type(str, pattern))
	{
		ft_putendl("us");
		return (1 + (pattern->conv % 2));
	}
	return (0);
}

/*	Cette fonction decoupe les chaines entre deux patterns et les stocke dans
 *	une liste chainee, elle envoie ensuite les patterns en traduction.
 *	NB : un maillon vide sera stocke en cas 2 patterns se suivant immediatement,
 *	ou de pattern directement en debut ou fin de chaine.
 */

int		ft_pattern_detect(char *str, t_list **buff, t_pattern **pattern_list)
{
	size_t		i;
	size_t		j;
	int			flag;
	t_pattern	*pattern;

	flag = 3;
	i = 0;
	ft_putendl(str);
	while ((j = ft_strcspn(str + i, "%")) != ft_strlen(str + i))
	{
		ft_putendl("B");
		ft_putendl(str);
		if (str[i + j + 1] != '%')
		{
			ft_putendl("C");
			ft_putendl(str);
			pattern = ft_new_pattern(pattern_list);
			ft_putendl("r");
			ft_putendl(str);
			ft_lstadd_back(buff, ft_lstnew(str, i + j));
			ft_putendl("i");
			ft_memmove(str,  str + i + j + 1, ft_strlen(str + i + j));
			ft_putendl(str);
			ft_putendl("n");
			if (!(i = ft_pattern_translate(&str, pattern)) || !(flag &= i))
			{
				ft_putnbr(i);
				return (ft_parse_error(flag, buff, pattern_list));
			}
			i = 0;
		}
		else
		{
			ft_memmove(str + i + j, str + i + j + 1, ft_strlen(str + i + j + 1));
			i += j + 1;
		}
	}
	ft_lstadd_back(buff, ft_lstnew(str, i + j));
	//etape de fin
	return (1);	
}
