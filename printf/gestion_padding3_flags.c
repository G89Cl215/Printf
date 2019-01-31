/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_padding3_flags.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 21:57:36 by tgouedar          #+#    #+#             */
/*   Updated: 2019/01/31 11:40:57 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_padding_positiv4(t_pattern *voyager, t_list *vonc)
{
	char	*str;
	int		len;

	len = ft_strlen((char*)(vonc->content));
	if (voyager->precision != -1)
	{
		if (!(str = ft_strnew(voyager->precision - len)))
			return (0);
		if (voyager->field_width == -1)
			str[voyager->precision - len] = '+';
		if (!(ft_strappend_back(&str, (char**)(&(vonc->content)))))
			return (0);
	}
	return (1);
}

int		ft_padding_positiv3(t_pattern *voyager, t_list *vonc)
{
	char	*str;
	int		len;

	len = ft_strlen((char*)(vonc->content));
	if (voyager->field_width && voyager->precision == -1
	&& *((char*)vonc->content) != '+')
	{
		if (!(str = ft_strnew(voyager->field_width - len)))
			return (0);
		if (voyager->precision == -1)
			str[voyager->field_width - len] = '+';
		if (!(ft_strappend_back(&str, (char**)(&(vonc->content)))))
			return (0);
		if (!(voyager->conv & (2 << (ft_indice('0', KNOWN_FLAG)))))
			((char*)(vonc->content))[len - 1] = '\0';
	}
	else if (*((char*)(vonc->content)) != '+'
		&& !(ft_padding_positiv6(voyager, vonc)))
		return (0);
	return (1);
}

int		ft_padding_positiv2(t_pattern *voyager, t_list *vonc)
{
	char	*str;
	int		len;

	len = ft_strlen((char*)(vonc->content));
	if (voyager->field_width - len > 0)
	{
		if (!(str = ft_strnew(voyager->field_width - len)))
			return (0);
		ft_memset(str, ' ', voyager->field_width - len);
		if (voyager->precision == -1)
			str[voyager->field_width - len - 1] = '+';
		if (!(ft_strappend_back(&str, (char**)(&(vonc->content)))))
			return (0);
	}
	ft_padding_positiv7(voyager, vonc);
	return (1);
}

int		ft_padding_positiv(t_pattern *voyager, t_list *vonc)
{
	size_t		i;

	i = 1;
	ft_padding_positiv5(voyager, vonc);
	if (voyager->field_width > -1 || (voyager->precision == -1
	&& voyager->field_width == -1 && *((char*)(vonc->content)) != '-'
	&& !(voyager->conv & (i << (TYPE_START + ft_indice('u', KNOWN_CONV))))))
	{
		if (!(ft_padding_positiv2(voyager, vonc)))
			return (0);
	}
	return (1);
}
