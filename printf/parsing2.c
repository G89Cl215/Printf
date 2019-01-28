/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 18:40:57 by tgouedar          #+#    #+#             */
/*   Updated: 2019/01/28 22:45:25 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_translate_f_w(char **str, t_pattern *pattern)
{
	if (**str != 'd')
	{
		if (**str == '*' && (*str)++)
			pattern->conv |= (1 << STAR_FW);
		pattern->field_width = ft_translate_int(str);
		if (**str == '$' && (*str)++ && !(pattern->conv % 2)) 
			return (0);
		if ((((pattern->conv >> STAR_FW) % 2) ^ (pattern->conv % 2))
				&& pattern->field_width != -1)
			return (0);
	}
	return (1);
}

int			ft_translate_precision(char **str, t_pattern *pattern)
{
	if (**str == '.' && (*str)++)
	{
		if (**str == '*' && (*str)++)
			pattern->conv |=  ((t_ul)1 << STAR_PR);
		if (ft_isdigit(**str))
			pattern->precision = ft_translate_int(str); 
		else if (!(pattern->conv & (1 << STAR_PR)))
			pattern->precision = 0;
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
				pattern->conv |= 
					((t_ul)1 << (ft_indice(**str, KNOWN_LMOD) + LMOD_START + 1));
			else
				return (0);
			(*str)++;
		}
		else
			pattern->conv |= ((t_ul)1 << (ft_indice(**str, KNOWN_LMOD) + LMOD_START));
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
	else if (!(pattern->conv % 2))
	{
		pattern->conv |= ((t_ul)1 << (TYPE_START + ft_indice('k', KNOWN_CONV)));
		pattern->nbr = (**str);
		(*str) += (**str) ? 1 : 0;
		return (1);
	}
	return (0);
}
