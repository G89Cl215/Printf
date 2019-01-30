/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_padding2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 02:56:58 by tgouedar          #+#    #+#             */
/*   Updated: 2019/01/30 07:54:25 by baavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_padding_prec(t_pattern *voyager, t_list *vonc)
{
	char		*str;
	char		**bus;

	if (voyager->precision > -1)
	{
		bus = (char**)&(vonc->content);
		if (**bus == '-')
			ft_padding_prec_neg(voyager, vonc);
		if (voyager->precision - (int)ft_strlen(*bus) > 0
				&& (int)ft_strlen(*bus) > 0)
		{
			if (!(str = ft_strnew(voyager->precision - (int)ft_strlen(*bus))))
				return ;
			ft_memset(str, '0', voyager->precision - (int)ft_strlen(*bus));
			ft_strappend_back(&str, bus);
			ft_strdel(&str);
		}
		if (voyager->precision == 0 && ft_strlen(*bus) == 1
				&& **bus == '0'
				&& !(voyager->conv & (2 << (ft_indice('#', KNOWN_FLAG)))))
			ft_bzero(*bus, ft_strlen(*bus));
	}
}

void		ft_padding_prec_neg(t_pattern *voyager, t_list *vonc)
{
	char		*str;
	char		**bus;

	bus = (char**)&(vonc->content);
	if (voyager->precision > -1)
	{
		ft_memmove(*bus, (*bus) + 1, ft_strlen(*bus));
		if (voyager->precision - ft_strlen(*bus) > 0)
		{
			if (!(str = ft_strnew(voyager->precision - ft_strlen(*bus) + 1)))
				return ;
			ft_memset(str, '0', voyager->precision - ft_strlen(*bus) + 1);
			str[0] = '-';
			ft_strappend_back(&str, bus);
			ft_strdel(&str);
		}
	}
}

void		ft_padding_spaces(t_pattern *voyager, t_list *vonc)
{
	char	*str;
	char	**bus;
	int		length;

	if (voyager->field_width > -1)
	{
		bus = (char**)&(vonc->content);
		length = (ft_strcmp(*bus, "^@") == 0)
			? (ft_strlen(*bus) - 1) : (ft_strlen(*bus));
		if (voyager->field_width - length > 0)
		{
			if (!(str = ft_strnew(voyager->field_width - length)))
				return ;
			ft_memset(str, ' ', voyager->field_width - length);
			ft_strappend_back(&str, bus);
			ft_strdel(&str);
		}
	}
}
