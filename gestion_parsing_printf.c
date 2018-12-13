/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_parsing_printf.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 17:02:05 by tgouedar          #+#    #+#             */
/*   Updated: 2018/12/13 17:21:23 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*	Cette fonction traduit le pattern et renvoit 0 s'il est invalide, 1 s'il est
 *	valide et non positionnel et 2 s'il est positionnel.
 */

int			ft_pattern_translate(char **str, t_pattern *pattern)
{
	int		i;
	int		flag;

	flag = 1;
	if (ft_isdigit(**str))
	{
		i = ft_atoi(*str);
		while (**str || ft_isdigit(**str))
			(*str)++;
		if (**str == $)
		{
			pattern->nbr = i;
			*str++;
			flag++;
			i = 0;
			while (ft_isin((*str)[i], KNOWN_FLAG))
				i++;
			pattern->flag = ft_strndup(*str, i);
			*str += i;
			if (ft_isdigit(**str))
				i = ft_atoi(*str);
			while (**str || ft_isdigit(**str))
				(*str)++;
			pattern->field_width = i;
		}
		else
			pattern->field_width = i;
	}
	else
	{
		while (ft_isin((*str)[i], KNOWN_FLAG))
			i++;
		pattern->flag = ft_strndup(*str, i);
		*str += i;
		if (ft_isdigit(**str))
			i = ft_atoi(*str);
		while (**str || ft_isdigit(**str))
			(*str)++;
		pattern->field_width = i;
	}

	if (**str == '.')
	{
		(*str)++;
		if (**str == '*' && (*str)++ && !(ft_isin('0', pattern->flag)))
		{
			ft_strcat(pattern->flag, "0");
			pattern->star = 1;
		}
		i = ft_atoi(*str);
		while (**str || ft_isdigit(**str))
			(*str)++;
		if (**str == '$' && (*str)++ && flag == 2)
			return (0);
		pattern->precision = i;
	}
	else if (**str == '*')
	{
		(*str)++;
		pattern->star = 1;
		i = ft_atoi(*str);
		while (**str || ft_isdigit(**str))
			(*str)++;
		if (**str == '$' && (*str)++ && flag == 2)
			return (0);
		pattern->precision = i;
	}
	if (ft_isin(**str, KNOWN_LMOD))
	{
		if ((**str == 'l' || **str == 'h') && (*(*str + 1) == **str))
		{
			pattern->length_modif = ft_strndup(str, 2);
			*str++;
		}
		else
			pattern->length_modif = ft_strndup(str, 1);
		*str++;
	}
	if (ft_isin(**str, KNOWN_CONV))
	{
		pattern->type = **str;
		(*str)++;
		return (flag);
	}
	else
		return (0);
}
