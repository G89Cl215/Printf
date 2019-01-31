/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_padding7_flags.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baavril <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 14:47:10 by baavril           #+#    #+#             */
/*   Updated: 2019/01/30 20:21:02 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_padding_flag_space2(t_pattern *voyager, t_list *vonc)
{
	char		*str;
	char		**bus;
	t_ul		type;

	bus = NULL;
	str = NULL;
	type = ft_type_flag(voyager);
	if (!(str = ft_strnew(1)))
		return (0);
	bus = (char**)&(vonc->content);
	if (voyager->precision != -1)
		ft_padding_prec(voyager, vonc);
	if (!(**bus == '-') && !(**bus == '^'))
	{
		str[0] = ' ';
		ft_strappend_back(&str, bus);
		ft_strdel(&str);
	}
	return (1);
}

int		ft_padding_flag_space(t_pattern *voyager, t_list *vonc)
{
	t_ul		type;

	type = ft_type_flag(voyager);
	if ((voyager->field_width == -1
	|| !(voyager->conv & ((size_t)2 << (ft_indice('0', KNOWN_FLAG)))))
	&& !(voyager->conv & ((size_t)2 << (ft_indice('+', KNOWN_FLAG))))
	&& !(type & ((size_t)1 << (ft_indice('u', KNOWN_CONV))))
	&& !(type & ((size_t)1 << (ft_indice('%', KNOWN_CONV)))))
		if (!(ft_padding_flag_space2(voyager, vonc)))
			return (0);
	return (1);
}

int		ft_padding_zero2(t_pattern *voyager, char **bus, char *str)
{
	if (voyager->field_width - (int)ft_strlen(*bus) > 0
			&& !(voyager->conv & ((size_t)2 << (ft_indice(' ', KNOWN_FLAG)))))
	{
		if (!(str = ft_strnew(voyager->field_width - ft_strlen(*bus))))
			return (0);
		ft_memset(str, '0', voyager->field_width - ft_strlen(*bus));
		ft_strappend_back(&str, bus);
		ft_strdel(&str);
	}
	else if (voyager->field_width - (int)ft_strlen(*bus) - 1 > 0
			&& (voyager->conv & ((size_t)2 << (ft_indice(' ', KNOWN_FLAG)))))
	{
		if (!(str = ft_strnew(voyager->field_width - ft_strlen(*bus) - 1)))
			return (0);
		ft_memset(str, '0', voyager->field_width - ft_strlen(*bus) - 1);
		ft_strappend_back(&str, bus);
		ft_strdel(&str);
	}
	return (1);
}

int		ft_padding_zero(t_pattern *voyager, t_list *vonc)
{
	char	*str;
	char	**bus;

	str = NULL;
	bus = NULL;
	bus = (char**)&(vonc->content);
	if (**bus == '-')
	{
		if ((ft_padding_0_neg(voyager, vonc)))
			return (1);
	}
	if (voyager->conv & (2 << (ft_indice('+', KNOWN_FLAG))))
	{
		if ((ft_padding_0_pos(voyager, vonc)))
			return (1);
	}
	if (!(ft_padding_zero2(voyager, bus, str)))
		return (0);
	return (1);
}
