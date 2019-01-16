/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_t_pattern.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 15:25:27 by tgouedar          #+#    #+#             */
/*   Updated: 2019/01/15 18:29:08 by baavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_ul	ft_int_flag(void)
{
	t_ul	j;

	j = TYPE_START - LMOD_START;
	return ((t_ul)1 << (j + ft_indice('i', KNOWN_CONV))
			| ((t_ul)1 << (j + ft_indice('d', KNOWN_CONV))));
}

t_ul	ft_lmod_flag(t_ul conv)
{
	return (((((t_ul)1 << TYPE_START) - 1) & conv) >> LMOD_START);
}

t_ul	ft_type_flag(t_pattern *pattern)
{
	return ((~((t_ul)0) & pattern->conv) >> TYPE_START);
}

t_ul	ft_type_flag_pos(t_pattern *pattern)
{
	return ((~((t_ul)0) & pattern->conv) >> (TYPE_START - LMOD_START));
}

void	ft_free_pattern(t_pattern **pattern)
{
	t_pattern	*voyager;
	
	voyager = *pattern;
	while (voyager)
	{
		voyager = voyager->next;
		free((void**)pattern);
		*pattern = voyager;
	}
}
