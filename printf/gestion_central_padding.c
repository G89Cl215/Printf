/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_central_padding.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baavril <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 14:25:35 by baavril           #+#    #+#             */
/*   Updated: 2019/01/31 11:50:31 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		ft_need_flag_pad(void)
{
	size_t	j;

	j = 1;
	return (j << ft_indice('c', KNOWN_CONV) | j << ft_indice('s', KNOWN_CONV)
		| j << ft_indice('%', KNOWN_CONV) | j << ft_indice('d', KNOWN_CONV)
		| j << ft_indice('D', KNOWN_CONV) | j << ft_indice('i', KNOWN_CONV)
		| j << ft_indice('b', KNOWN_CONV) | j << ft_indice('o', KNOWN_CONV)
		| j << ft_indice('O', KNOWN_CONV) | j << ft_indice('x', KNOWN_CONV)
		| j << ft_indice('X', KNOWN_CONV) | j << ft_indice('u', KNOWN_CONV)
		| j << ft_indice('U', KNOWN_CONV) | j << ft_indice('f', KNOWN_CONV)
		| j << ft_indice('e', KNOWN_CONV) | j << ft_indice('E', KNOWN_CONV)
		| j << ft_indice('k', KNOWN_CONV) | j << ft_indice('p', KNOWN_CONV));
}

int			ft_type_redirect(t_pattern *voyager, t_list *vonc)
{
	size_t	type;
	size_t	i;

	i = 1;
	type = ft_type_flag(voyager);
	if (type & (i << (ft_indice('p', KNOWN_CONV)))
			&& !(ft_base_prefix(voyager, vonc)))
		return (0);
	if (type & (i << (ft_indice('s', KNOWN_CONV)))
	&& !(ft_padding_str(voyager, vonc)))
		return (0);
	if (type & (i << (ft_indice('e', KNOWN_CONV))
				| i << (ft_indice('E', KNOWN_CONV))))
		ft_prec_scient(vonc->content, voyager->precision);
	if (type & (i << (ft_indice('f', KNOWN_CONV))))
		ft_prec_float(vonc->content, voyager->precision);
	if ((type & ft_need_flag_pad()) && !(ft_padding_flags(voyager, vonc)))
		return (0);
	return (1);
}

int			ft_central_padding(t_pattern **pattern, t_list **conv)
{
	t_pattern	*voyager;
	t_list		*vonc;

	vonc = *conv;
	voyager = *pattern;
	while (voyager)
	{
		if (!(ft_type_redirect(voyager, vonc)))
			return (0);
		vonc = vonc->next;
		voyager = voyager->next;
	}
	return (1);
}
