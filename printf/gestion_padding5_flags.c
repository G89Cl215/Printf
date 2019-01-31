/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_padding5_flags.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baavril <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 11:08:47 by baavril           #+#    #+#             */
/*   Updated: 2019/01/30 20:18:18 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_prefix2(t_pattern *voyager, char **bus, t_ul type)
{
	if (voyager->conv & (2 << (ft_indice('-', KNOWN_FLAG)))
	&& !(type & (1 << (ft_indice('o', KNOWN_CONV)))
	|| type & (1 << (ft_indice('p', KNOWN_CONV)))))
	{
		if (!(*bus = ft_strndup(*bus, (ft_strlen(*bus) - 2))))
			return (0);
	}
	if (voyager->conv & (2 << (ft_indice('-', KNOWN_FLAG)))
	&& type & (1 << (ft_indice('o', KNOWN_CONV))))
	{
		if (!(*bus = ft_strndup(*bus, (ft_strlen(*bus) - 1))))
			return (0);
	}
	if (!(type & (1 << (ft_indice('o', KNOWN_CONV)))))
	{
		if ((voyager->field_width == -1 && (ft_strlen(*bus) == 1
		&& **bus == '0' && voyager->precision > -1))
		|| (voyager->precision > -1
		&& (!(type & (1 << (ft_indice('p', KNOWN_CONV)))))))
			ft_bzero(*bus, ft_strlen(*bus));
	}
	return (1);
}

int		ft_prefix(t_pattern *voyager, char **bus, char *str)
{
	t_ul		type;

	type = ft_type_flag(voyager);
	if (voyager->conv & (2 << (ft_indice('0', KNOWN_FLAG)))
	&& (!(voyager->conv & (2 << (ft_indice('-', KNOWN_FLAG))))))
		ft_memmove(*bus, (*bus) + 2, ft_strlen(*bus + 2) + 1);
	if ((type & (1 << (ft_indice('p', KNOWN_CONV))))
	|| ((int)ft_strlen(*bus) > 1 || **bus != '0'
	|| type & (1 << (ft_indice('o', KNOWN_CONV)))))
	{
		if (!(ft_strappend_back(&str, bus)))
			return (0);
	}
	ft_prefix2(voyager, bus, type);
	return (1);
}

int		ft_padding_flag_prefix(t_pattern *voyager, t_list *vonc)
{
	char		*str;
	char		**bus;
	t_ul		type;

	type = ft_type_flag(voyager);
	if (!(str = ft_strnew(2)))
		return (0);
	bus = (char**)&(vonc->content);
	str[0] = '0';
	if (type & (1 << (ft_indice('x', KNOWN_CONV)))
	|| type & (1 << (ft_indice('p', KNOWN_CONV))))
		str[1] = 'x';
	if (type & (1 << (ft_indice('X', KNOWN_CONV))))
		str[1] = 'X';
	else if (type & (1 << (ft_indice('b', KNOWN_CONV))))
		str[1] = 'b';
	else if (**bus == '0' && (int)ft_strlen(*bus) == 1
			&& !(type & (1 << (ft_indice('p', KNOWN_CONV)))))
		str[0] = '\0';
	str[2] = '\0';
	if (!(ft_prefix(voyager, bus, str)))
		return (0);
	ft_strdel(&str);
	return (1);
}

int		ft_padding_negativ2(t_pattern *voyager, t_list *vonc,
											char **bus, char *str)
{
	if (voyager->field_width > -1)
	{
		if (voyager->field_width - (int)ft_strlen(*bus) > 0)
		{
			if (!(str = ft_strnew(voyager->field_width - ft_strlen(*bus))))
				return (0);
			ft_memset(str, ' ', voyager->field_width - ft_strlen(*bus));
			if (!(ft_strappend(bus, &str)))
				return (0);
			ft_strdel(&str);
		}
	}
	if (voyager->conv & (2 << (ft_indice('+', KNOWN_FLAG))))
	{
		if (!(ft_padding_positiv(voyager, vonc)))
			return (0);
	}
	return (1);
}

int		ft_padding_negativ(t_pattern *voyager, t_list *vonc)
{
	char	*str;
	char	**bus;
	t_ul	type;

	str = NULL;
	type = ft_type_flag(voyager);
	bus = (char**)&(vonc->content);
	if (voyager->precision > -1
	&& !(type & (1 << (ft_indice('c', KNOWN_CONV)))))
	{
		if (!((**bus == '-') ? ft_padding_prec_neg(voyager, vonc)
			: ft_padding_prec(voyager, vonc)))
			return (0);
	}
	if (!(ft_padding_negativ2(voyager, vonc, bus, str)))
		return (0);
	return (1);
}
