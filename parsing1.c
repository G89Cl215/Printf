/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_parsing_printf.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 17:02:05 by tgouedar          #+#    #+#             */
/*   Updated: 2019/01/18 14:54:35 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_translate_int(char **str)
{
	int	i;

	i = -1;
	if (ft_isdigit(**str))
		i = ft_atoi(*str);
	while (**str && ft_isdigit(**str))
		(*str)++;
	return (i);
}

/*	Cette fonction traduit le pattern et renvoie 0 s'il est invalide, 1 s'il est
 *	valide et non positionnel et 2 s'il est positionnel.
 */

int			ft_pattern_translate(char **str, t_pattern *pattern)
{
	int		i;
	
	if (**str == '0' && (*str)++)
		pattern->conv = (t_ul)2 << ft_indice('0', KNOWN_FLAG);
	if (ft_isdigit(**str) && (i = ft_translate_int(str)))
	{
		if ((**str == '$' && (*str)++) || (pattern->field_width = i && 0))
		{	
			pattern->conv++;
			pattern->nbr = i;
			pattern->conv &= ~((t_ul)2 << ft_indice('0', KNOWN_FLAG));
			ft_translate_flag(str, pattern);
			if (!(ft_translate_f_w(str, pattern)))
				return (0);
		}
	}
	else
	{
		ft_translate_flag(str, pattern);
		if (!(ft_translate_f_w(str, pattern)))
			return (0);
	}
	if (!(ft_translate_precision(str, pattern))
					|| !(ft_translate_lmod(str, pattern)))
		return (0);
	return ((ft_translate_type(str, pattern)) ? (1 + (pattern->conv % 2)) : 0);
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
	while ((j = ft_strcspn(str + i, "%")) != ft_strlen(str + i))
	{
		if (str[i + j + 1] != '%')
		{
			pattern = ft_new_pattern(pattern_list);
			ft_lstadd_back(buff, ft_lstnew(str, i + j));
			ft_memmove(str,  str + i + j + 1, ft_strlen(str + i + j));
			if (!(i = ft_pattern_translate(&str, pattern)) || !(flag &= i))
			{
				ft_putnbr(i);
				return (ft_parse_error(flag, buff, pattern_list));
			}
			i = 0;
		}
		else
		{
			i += j + 1;
			ft_memmove(str + i - 1, str + i, ft_strlen(str + i));
		}
	}
	ft_lstadd_back(buff, ft_lstnew(str, i + j));
	//etape de fin
	return (1);	
}