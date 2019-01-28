/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_padding1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baavril <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 16:07:38 by baavril           #+#    #+#             */
/*   Updated: 2019/01/28 19:15:30 by baavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_padding_flags(t_pattern *voyager, t_list *vonc)
{
	if ((voyager->conv & (2 << (ft_indice('0', KNOWN_FLAG)))
			&& (!(voyager->conv & (2 << (ft_indice('-', KNOWN_FLAG))))
				&& voyager->precision == -1))
			|| (voyager->conv & (2 << (ft_indice('-', KNOWN_FLAG)))
			&& voyager->conv & (2 << (ft_indice('+', KNOWN_FLAG)))
			&& voyager->conv & (2 << (ft_indice('0', KNOWN_FLAG)))))
		ft_padding_zero(voyager, vonc);
	if (voyager->conv & (2 << (ft_indice('-', KNOWN_FLAG))))
		ft_padding_negativ(voyager, vonc);
	if (voyager->conv & (2 << (ft_indice('+', KNOWN_FLAG))))
		ft_padding_positiv(voyager, vonc);
	if (voyager->conv & (2 << (ft_indice(' ', KNOWN_FLAG))))
		ft_padding_flag_space(voyager, vonc);
	if (voyager->conv & (2 << (ft_indice('#', KNOWN_FLAG)))
	&& !(voyager->conv & (1 << (TYPE_START + ft_indice('f', KNOWN_CONV))))
	&& !(voyager->conv & (1 << (TYPE_START + ft_indice('e', KNOWN_CONV))))
	&& !(voyager->conv & ((t_ul)1 << (TYPE_START + ft_indice('E', KNOWN_CONV)))))
		ft_padding_flag_prefix(voyager, vonc);
	if (!(voyager->conv & (2 << (ft_indice('+', KNOWN_FLAG)))))
	{
		if (voyager->precision > -1)
			ft_padding_prec(voyager, vonc);
		if (voyager->field_width > -1)
			ft_padding_spaces(voyager, vonc);
	}
}

void		ft_central_padding2(t_pattern *voyager, t_list *vonc)
{
	t_ul	type;

	type = ft_type_flag(voyager);
	if (type & (1 << (ft_indice('e', KNOWN_CONV)))
			|| type & (1 << (ft_indice('E', KNOWN_CONV))))
		ft_prec_scient(vonc->content, voyager->precision);
	if (type & (1 << (ft_indice('f', KNOWN_CONV))))
		ft_prec_float(vonc->content, voyager->precision);
	if (type & (1 << (ft_indice('c', KNOWN_CONV)))
				|| type & (1 << (ft_indice('%', KNOWN_CONV)))
				|| type & (1 << (ft_indice('d', KNOWN_CONV)))
				|| type & ((t_ul)1 << (ft_indice('D', KNOWN_CONV)))
				|| type & (1 << (ft_indice('i', KNOWN_CONV)))
				|| type & (1 << (ft_indice('b', KNOWN_CONV)))
				|| type & (1 << (ft_indice('o', KNOWN_CONV)))
				|| type & (1 << (ft_indice('O', KNOWN_CONV)))
				|| type & (1 << (ft_indice('x', KNOWN_CONV)))
				|| type & (1 << (ft_indice('X', KNOWN_CONV)))
				|| type & (1 << (ft_indice('u', KNOWN_CONV)))
				|| type & (1 << (ft_indice('U', KNOWN_CONV)))
				|| type & (1 << (ft_indice('f', KNOWN_CONV)))
				|| type & (1 << (ft_indice('e', KNOWN_CONV)))
				|| type & (1 << (ft_indice('E', KNOWN_CONV))))
		ft_padding_flags(voyager, vonc);
}

int			ft_central_padding(t_pattern **pattern, t_list **conv)
{
	t_pattern	*voyager;
	t_list		*vonc;
	t_ul		type;

	vonc = *conv;
	voyager = *pattern;
	while (voyager)
	{
		type = ft_type_flag(voyager);
		if (type & (1 << (ft_indice('s', KNOWN_CONV))))
		{
			ft_padding_str(voyager, vonc);
			ft_padding_flags(voyager, vonc);
		}
		ft_central_padding2(voyager, vonc);
		if (type & (1 << (ft_indice('p', KNOWN_CONV))))
		{
			ft_padding_flag_prefix(voyager, vonc);
			ft_padding_flags(voyager, vonc);
		}
		vonc = vonc->next;
		voyager = voyager->next;
	}
	return (1);
}
