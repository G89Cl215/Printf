/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_padding2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 02:56:58 by tgouedar          #+#    #+#             */
/*   Updated: 2019/01/24 03:00:38 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_padding_prec(t_pattern *voyager, t_list *vonc)
{
	char		*str;
	char		**bus;

	if (voyager->precision > -1)
	{
		if (!(bus = (char**)malloc(sizeof(char*))))
			return ;
		bus = (char**)&(vonc->content);
		if (**bus == '-')
		{
			ft_padding_prec_neg(voyager, vonc);
			return ;
		}
		if (voyager->precision - (int)ft_strlen(*bus) > 0)
		{
			if (!(str = ft_strnew(voyager->precision - (int)ft_strlen(*bus))))
				return ;
			ft_memset(str, '0', voyager->precision - (int)ft_strlen(*bus));
			ft_strappend_back(&str, bus);
		}
	}
}

void		ft_padding_prec_neg(t_pattern *voyager, t_list *vonc)
{
	char		*str;
	char		**bus;

	if (!(bus = (char**)malloc(sizeof(char*))))
		return ;
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
		}
	}
}

void		ft_padding_spaces(t_pattern *voyager, t_list *vonc)
{
	char	*str;
	char	**bus;

	if (voyager->field_width > -1)
	{
		if (!(bus = (char**)malloc(sizeof(char*))))
			return ;
		bus = (char**)&(vonc->content);
		if (voyager->field_width - ft_strlen(*bus) > 0)
		{
			if (!(str = ft_strnew(voyager->field_width - ft_strlen(*bus))))
				return ;
			ft_memset(str, ' ', voyager->field_width - ft_strlen(*bus));
			ft_strappend_back(&str, bus);
		}
	}
}
