/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_padding1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baavril <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 13:20:02 by baavril           #+#    #+#             */
/*   Updated: 2019/01/31 11:15:47 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_padding_flags4(t_pattern *voyager, t_list *vonc)
{
	size_t i;

	i = 1;
	if (!(voyager->conv & (i << (ft_indice('+', KNOWN_FLAG) + 1))))
	{
		if (voyager->precision > -1
		&& !(voyager->conv & (i << (TYPE_START + ft_indice('f', KNOWN_CONV)))))
		{
			if (!(ft_padding_prec(voyager, vonc)))
				return (0);
		}
		if (voyager->field_width > -1)
		{
			if (!(ft_padding_spaces(voyager, vonc)))
				return (0);
		}
	}
	return (1);
}

int		ft_padding_flags3(t_pattern *voyager, t_list *vonc)
{
	size_t i;

	i = 1;
	if (voyager->conv & (i << (ft_indice('#', KNOWN_FLAG) + 1))
	&& !(voyager->conv & (i << (TYPE_START + ft_indice('f', KNOWN_CONV))))
	&& !(voyager->conv & (i << (TYPE_START + ft_indice('E', KNOWN_CONV)))
	&& !(voyager->conv & (i << (TYPE_START + ft_indice('e', KNOWN_CONV))))))
	{
		if (!(ft_base_prefix(voyager, vonc)))
			return (0);
	}
	if (!(ft_padding_flags4(voyager, vonc)))
		return (0);
	return (1);
}

int		ft_padding_flags2(t_pattern *voyager, t_list *vonc)
{
	size_t j;

	j = 1;
	if (voyager->conv & (j << (ft_indice('-', KNOWN_FLAG) + 1)))
	{
		if (!(ft_padding_negativ(voyager, vonc)))
			return (0);
	}
	if (voyager->conv & (j << (ft_indice('+', KNOWN_FLAG) + 1)))
	{
		if (!(ft_padding_positiv(voyager, vonc)))
			return (0);
	}
	if (voyager->conv & (j << (ft_indice(' ', KNOWN_FLAG) + 1))
	&& !(voyager->conv & (j << (TYPE_START + (ft_indice('k', KNOWN_CONV))))))
	{
		if (!(ft_padding_flag_space(voyager, vonc)))
			return (0);
	}
	return (1);
}

int		ft_padding_flags(t_pattern *voyager, t_list *vonc)
{
	size_t j;

	j = 2;
	if ((voyager->conv & (j << (ft_indice('0', KNOWN_FLAG)))
	&& (!(voyager->conv & (j << (ft_indice('-', KNOWN_FLAG))))
	&& voyager->precision == -1))
	|| (voyager->conv & (j << (ft_indice('-', KNOWN_FLAG)))
	&& voyager->conv & (j << (ft_indice('+', KNOWN_FLAG)))
	&& voyager->conv & (j << (ft_indice('0', KNOWN_FLAG)))))
	{
		if (!(ft_padding_zero(voyager, vonc)))
			return (0);
	}
	if (!(ft_padding_flags2(voyager, vonc)))
		return (0);
	if (!(ft_padding_flags3(voyager, vonc)))
		return (0);
	return (1);
}
