/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_padding6_flags.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baavril <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 11:13:38 by baavril           #+#    #+#             */
/*   Updated: 2019/01/30 08:16:02 by baavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_padding_flag_space(t_pattern *voyager, t_list *vonc)
{
	char		*str;
	char		**bus;
	t_ul		type;

	bus = NULL;
	str = NULL;
	type = ft_type_flag(voyager);
	if (voyager->field_width == -1
			&& !(voyager->conv & (2 << (ft_indice('+', KNOWN_FLAG))))
				&& !(type & (1 << (ft_indice('u', KNOWN_CONV))))
				&& !(type & (1 << (ft_indice('%', KNOWN_CONV)))))
	{
		if (!(str = ft_strnew(1)))
			return ;
		bus = (char**)&(vonc->content);
		if (voyager->precision != -1)
			ft_padding_prec(voyager, vonc);
		if (!(**bus == '-') && !(**bus == '^'))
		{
			str[0] = ' ';
			ft_strappend_back(&str, bus);
			ft_strdel(&str);
		}
	}
}

void		ft_padding_0_pos(t_pattern *voyager, t_list *vonc)
{
	char	*str;
	char	**bus;
	
	str = NULL;
	bus = NULL;
	if (voyager->field_width != -1)
	{
		bus = (char**)&(vonc->content);
		if (voyager->field_width - (int)ft_strlen(*bus) > 0)
		{
			if (!(str = ft_strnew(voyager->field_width - ft_strlen(*bus))))
				return ;
			ft_memset(str, '0', voyager->field_width - ft_strlen(*bus));
			str[0] = '+';
			ft_strappend_back(&str, bus);
			ft_strdel(&str);
		}
	}
}

void		ft_padding_zero(t_pattern *voyager, t_list *vonc)
{
	char	*str;
	char	**bus;

	str = NULL;
	bus = NULL;
	bus = (char**)&(vonc->content);
	if (**bus == '-')
	{
		ft_padding_0_neg(voyager, vonc);
		return ;
	}
	if (voyager->conv & (2 << (ft_indice('+', KNOWN_FLAG))))
	{
		ft_padding_0_pos(voyager, vonc);
		return ;
	}
	if (voyager->field_width - (int)ft_strlen(*bus) > 0)
	{
		if (!(str = ft_strnew(voyager->field_width - ft_strlen(*bus))))
			return ;
		ft_memset(str, '0', voyager->field_width - ft_strlen(*bus));
		ft_strappend_back(&str, bus);
		ft_strdel(&str);
	}
}

void		ft_padding_str(t_pattern *voyager, t_list *vonc)
{
	char		*str;
	char		**bus;
	int			i;

	i = 0;
	str = NULL;
	bus = NULL;
	bus = (char**)&(vonc->content);
	if (voyager->precision != -1)
	{
		if ((int)(ft_strlen(*bus) - voyager->precision > 0))
		{
			if (!(str = malloc(voyager->precision) + 1))
				return ;
			while (i < voyager->precision)
				i++;
			*bus = ft_strndup(*bus, i);
		}
	}
}

void		ft_padding_0_neg(t_pattern *voyager, t_list *vonc)
{
	char	*str;
	char	**bus;

	str = NULL;
	bus = NULL;
	if (voyager->field_width != -1)
	{
		bus = (char**)&(vonc->content);
		ft_memmove(*bus, (*bus) + 1, ft_strlen(*bus));
		if (voyager->field_width - (int)ft_strlen(*bus) > 0)
		{
			if (!(str = ft_strnew(voyager->field_width - ft_strlen(*bus))))
				return ;
			ft_memset(str, '0', voyager->field_width - ft_strlen(*bus));
			str[0] = '-';
			ft_strappend_back(&str, bus);
			ft_strdel(&str);
		}
	}
}
