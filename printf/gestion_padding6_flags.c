/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_padding6_flags.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baavril <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 11:13:38 by baavril           #+#    #+#             */
/*   Updated: 2019/01/30 20:01:15 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_padding_0_pos(t_pattern *voyager, t_list *vonc)
{
	char	*str;
	char	**bus;

	str = NULL;
	if (voyager->field_width != -1)
	{
		bus = (char**)&(vonc->content);
		if (voyager->field_width - (int)ft_strlen(*bus) > 0)
		{
			if (!(str = ft_strnew(voyager->field_width - ft_strlen(*bus))))
				return (0);
			ft_memset(str, '0', voyager->field_width - ft_strlen(*bus));
			str[0] = '+';
			if (!(ft_strappend_back(&str, bus)))
				return (0);
			ft_strdel(&str);
		}
	}
	return (1);
}

int		ft_padding_str(t_pattern *voyager, t_list *vonc)
{
	char		*str;
	char		**bus;
	int			i;

	i = 0;
	str = NULL;
	bus = (char**)&(vonc->content);
	if (voyager->precision != -1)
	{
		if ((int)(ft_strlen(*bus) - voyager->precision > 0))
		{
			while (i < voyager->precision)
				i++;
			if (!(*bus = ft_strndup(*bus, i)))
				return (0);
		}
	}
	return (1);
}

int		ft_padding_0_neg(t_pattern *voyager, t_list *vonc)
{
	char	*str;
	char	**bus;

	str = NULL;
	if (voyager->field_width != -1)
	{
		bus = (char**)&(vonc->content);
		ft_memmove(*bus, (*bus) + 1, ft_strlen(*bus));
		if (voyager->field_width - (int)ft_strlen(*bus) > 0)
		{
			if (!(str = ft_strnew(voyager->field_width - ft_strlen(*bus))))
				return (0);
			ft_memset(str, '0', voyager->field_width - ft_strlen(*bus));
			str[0] = '-';
			if (!(ft_strappend_back(&str, bus)))
				return (0);
			ft_strdel(&str);
		}
	}
	return (1);
}
