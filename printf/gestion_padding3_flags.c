/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_padding3_positiv.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baavril <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 11:02:56 by baavril           #+#    #+#             */
/*   Updated: 2019/01/30 07:56:47 by baavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_padding_positiv4(t_pattern *voyager, char **bus, char *str)
{
	if (voyager->precision != -1)
	{
		if (!(str = ft_memalloc(voyager->precision - ft_strlen(*bus) + 1)))
			return ;
		if (voyager->field_width == -1)
			str[voyager->precision - (ft_strlen(*bus))] = '+';
		ft_strappend_back(&str, bus);
		ft_strdel(&str);
	}
}

void	ft_padding_positiv3(t_pattern *voyager, char **bus, char *str)
{
	if (voyager->field_width && (voyager->precision == -1) && **bus != '+')
	{
		if (!(str = ft_memalloc(voyager->field_width - ft_strlen(*bus) + 1)))
			return ;
		if (voyager->precision == -1)
			str[voyager->field_width - (ft_strlen(*bus))] = '+';
		ft_strappend_back(&str, bus);
		ft_strdel(&str);
		if (!(voyager->conv & (2 << (ft_indice('0', KNOWN_FLAG)))))
			*bus = ft_strndup(*bus, ft_strlen(*bus) - 1);
	}
	else if (**bus != '+')
	{
		if (!(str = ft_strnew(0)))
			return ;
		str[0] = '+';
		ft_strappend_back(&str, bus);
		ft_strdel(&str);
		if ((int)(ft_strlen(*bus) - 1) == voyager->field_width)
			*bus = ft_strndup(*bus, ft_strlen(*bus) - 1);
	}
}

void	ft_padding_positiv2(t_pattern *voyager, char **bus, char *str)
{
	if ((voyager->field_width - (int)ft_strlen(*bus)) > 0)
	{
		if (!(str = ft_memalloc(voyager->field_width - ft_strlen(*bus) + 1)))
			return ;
		ft_memset(str, ' ', voyager->field_width - ft_strlen(*bus));
		if (voyager->precision == -1)
			str[voyager->field_width - (ft_strlen(*bus)) - 1] = '+';
		ft_strappend_back(&str, bus);
		ft_strdel(&str);
	}
	if (voyager->precision == -1 && voyager->field_width == -1)
	{
		if ((int)ft_strlen(*bus) > 0)
		{
			if (!(str = ft_strnew(ft_strlen(*bus))))
				return ;
			str[0] = '+';
			ft_strappend_back(&str, bus);
			ft_strdel(&str);
		}
	}
	if (voyager->field_width
			&& voyager->conv & (2 << (ft_indice('-', KNOWN_FLAG)))
			&& **bus != '-')
		ft_padding_positiv3(voyager, bus, str);
}

void	ft_padding_positiv5(t_pattern *voyager, char **bus)
{
	char		*str;
	t_ul		type;

	str = NULL;
	type = ft_type_flag(voyager);
	if (voyager->precision > -1
			&& !(type & (1 << (ft_indice('u', KNOWN_CONV)))))
	{
		if ((voyager->precision - (int)ft_strlen(*bus)) > 0)
		{
			if (!(str = ft_strnew(voyager->precision - ft_strlen(*bus) + 1)))
				return ;
			ft_memset(str, '0', voyager->precision - ft_strlen(*bus) + 1);
			str[0] = '+';
			ft_strappend_back(&str, bus);
			ft_strdel(&str);
		}
		else
			ft_padding_positiv4(voyager, bus, str);
	}
}

void	ft_padding_positiv(t_pattern *voyager, t_list *vonc)
{
	char		*str;
	char		**bus;
	t_ul		type;

	str = NULL;
	type = ft_type_flag(voyager);
	if (!(bus = (char**)malloc(sizeof(char*))))
		return ;
	bus = (char**)&(vonc->content);
	ft_padding_positiv5(voyager, bus);
	if ((voyager->field_width > -1 || (voyager->precision == -1
					&& voyager->field_width == -1 && **bus != '-'))
			&& !(type & (1 << (ft_indice('u', KNOWN_CONV)))))
		ft_padding_positiv2(voyager, bus, str);
}
