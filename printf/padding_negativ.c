/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding_negativ.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 15:34:38 by tgouedar          #+#    #+#             */
/*   Updated: 2019/02/06 13:31:59 by baavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_padding_negative_fw(t_pattern *voyager, t_list *vonc)
{
	char	*str;
	int		len;

	str = NULL;
	len = ft_strlen((char*)(vonc->content));
	voyager->field_width = -(voyager->field_width);
	if (voyager->field_width > 0)
	{
		if (voyager->field_width > len)
		{
			if (!(str = ft_strnew(voyager->field_width - len)))
				return (0);
			ft_memset(str, ' ', voyager->field_width - len);
			if (!(ft_strappend((char**)(&(vonc->content)), &str)))
				return (0);
		}
		voyager->field_width = -(voyager->field_width);
	}
	return (1);
}

int		ft_padding_negativ2(t_pattern *voyager, t_list *vonc)
{
	char	*str;
	int		len;

	str = NULL;
	len = ft_strlen((char*)(vonc->content));
	if (voyager->field_width > -1)
	{
		if (voyager->field_width > len)
		{
			if (!(str = ft_strnew(voyager->field_width - len)))
				return (0);
			ft_memset(str, ' ', voyager->field_width - len);
			if (!(ft_strappend((char**)(&(vonc->content)), &str)))
				return (0);
		}
		if (voyager->conv & (1 << (ft_indice('#', KNOWN_FLAG) + 1))
		&& voyager->precision > -1
		&& voyager->field_width > voyager->precision
		&& voyager->field_width > len
		&& voyager->precision != len)
			((char*)(vonc->content))[voyager->field_width - 1] = '\0';
		if (voyager->conv & (1 << (ft_indice('#', KNOWN_FLAG) + 1))
		&& (voyager->field_width == len + 1
		&& voyager->precision == -1
		&& *((char*)(vonc->content)) != '0'))
			((char*)(vonc->content))[voyager->field_width - 1] = '\0';


	}
	return (1);
}

int		ft_padding_negativ(t_pattern *voyager, t_list *vonc)
{
	t_ul	type;

	type = ft_type_flag(voyager);
	if (voyager->precision > -1
	&& !(type & (1 << (ft_indice('c', KNOWN_CONV)))))
	{
		if (!((*((char*)(vonc->content)) == '-')
		? ft_padding_prec_neg(voyager, vonc)
		: ft_padding_prec(voyager, vonc)))
			return (0);
	}
	if (!(ft_padding_negativ2(voyager, vonc)))
		return (0);
	return (1);
}
