/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_parsing2_printf.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 11:17:31 by tgouedar          #+#    #+#             */
/*   Updated: 2019/01/18 14:54:35 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_translate_f_w(char **str, t_pattern *pattern)
{
	if (**str == '*' && (*str)++)
		pattern->conv |= (1 << STAR_FW);
	pattern->field_width = ft_translate_int(str);
	if (**str == '$' && (*str)++ && !(pattern->conv % 2)) 
		return (0);
	if ((((pattern->conv >> STAR_FW) % 2) ^ (pattern->conv % 2))
			&& pattern->field_width != -1)
		return (0);
	return (1);
}

int			ft_translate_precision(char **str, t_pattern *pattern)
{
	if (**str == '.' && (*str)++)
	{
		if (**str == '*' && (*str)++)
			pattern->conv |= (4 + (1 << STAR_PR));
		pattern->precision = ft_translate_int(str);
		if (**str == '$' && (*str)++ && !(pattern->conv % 2)) 
			return (0);
		if ((((pattern->conv >> STAR_PR) % 2) ^ (pattern->conv % 2))
				&& pattern->precision != -1)
			return (0);
	}
	return (1);
}

void		ft_translate_flag(char **str, t_pattern *pattern)
{
	while (ft_isin(**str, KNOWN_FLAG))
	{
		pattern->conv |= ((t_ul)2 << (ft_indice(**str, KNOWN_FLAG)));
		(*str)++;
	}
}

int			ft_translate_lmod(char **str, t_pattern *pattern)
{
	if (ft_isin(**str, KNOWN_LMOD))
	{
		if (**str == *(*str + 1))
		{
			if (**str == 'h' || **str == 'l')
				pattern->conv |= ((t_ul)1 << (ft_indice(**str, KNOWN_LMOD) + 2));
			else
				return (0);
			(*str)++;
		}
		else
			pattern->conv |= ((t_ul)1 << (ft_indice(**str, KNOWN_LMOD) + 1));
		(*str)++;
	}
	return (1);
}

int			ft_translate_type(char **str, t_pattern *pattern)
{
	if (ft_isin(**str, KNOWN_CONV))
	{
		pattern->conv |= ((t_ul)1 << (TYPE_START + ft_indice(**str, KNOWN_CONV)));
		(*str)++;
		return(1);
	}
	return (0);
}
