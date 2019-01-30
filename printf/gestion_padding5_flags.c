/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_padding5_flags.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baavril <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 11:08:47 by baavril           #+#    #+#             */
/*   Updated: 2019/01/30 08:00:32 by baavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_prefix(t_pattern *voyager, char **bus, char *str)
{
	t_ul		type;

	type = ft_type_flag(voyager);
	if (voyager->conv & (2 << (ft_indice('0', KNOWN_FLAG)))
	&& (!(voyager->conv & (2 << (ft_indice('-', KNOWN_FLAG))))))
		ft_memmove(*bus, (*bus) + 2, ft_strlen(*bus + 2) + 1);
	if ((type & (1 << (ft_indice('p', KNOWN_CONV))))
	|| ((int)ft_strlen(*bus) > 1 || **bus != '0'
	|| type & (1 << (ft_indice('o', KNOWN_CONV)))))
		ft_strappend_back(&str, bus);
	if (voyager->conv & (2 << (ft_indice('-', KNOWN_FLAG)))
	&& !(type & (1 << (ft_indice('o', KNOWN_CONV)))
	|| type & (1 << (ft_indice('p', KNOWN_CONV)))))
		*bus = ft_strndup(*bus, (ft_strlen(*bus) - 2));
	if (voyager->conv & (2 << (ft_indice('-', KNOWN_FLAG)))
	&& type & (1 << (ft_indice('o', KNOWN_CONV))))
		*bus = ft_strndup(*bus, (ft_strlen(*bus) - 1));
	if (!(type & (1 << (ft_indice('o', KNOWN_CONV)))))
	{
		if ((voyager->field_width == -1 && (ft_strlen(*bus) == 1
		&& **bus == '0' && voyager->precision > -1))
		|| (voyager->precision > -1
		&& (!(type & (1 << (ft_indice('p', KNOWN_CONV)))))))
			ft_bzero(*bus, ft_strlen(*bus));
	}
}

void	ft_padding_flag_prefix(t_pattern *voyager, t_list *vonc)
{
	char		*str;
	char		**bus;
	t_ul		type;

	type = ft_type_flag(voyager);
	if (!(bus = (char**)malloc(sizeof(char*)))
				|| !(str = ft_strnew(1)))
	{
		ft_memdel((void**)bus);
		return ;
	}
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
	ft_prefix(voyager, bus, str);
}

void	ft_padding_negativ2(t_pattern *voyager, t_list *vonc,
											char **bus, char *str)
{
	if (voyager->field_width > -1)
	{
		if (voyager->field_width - (int)ft_strlen(*bus) > 0)
		{
			if (!(str = ft_strnew(voyager->field_width - ft_strlen(*bus))))
				return ;
			ft_memset(str, ' ', voyager->field_width - ft_strlen(*bus));
			ft_strappend(bus, &str);
			ft_strdel(&str);
		}
	}
	if (voyager->conv & (2 << (ft_indice('+', KNOWN_FLAG))))
		ft_padding_positiv(voyager, vonc);
}

void	ft_padding_negativ(t_pattern *voyager, t_list *vonc)
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
		(**bus == '-') ? ft_padding_prec_neg(voyager, vonc)
			: ft_padding_prec(voyager, vonc);
	}
	ft_padding_negativ2(voyager, vonc, bus, str);
}
