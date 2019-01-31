/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_padding2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 02:56:58 by tgouedar          #+#    #+#             */
/*   Updated: 2019/01/31 11:40:10 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_padding_prec2(t_pattern *voyager, t_list *vonc)
{
	char	*str;
	int		len;

	len = ft_strlen((char*)(vonc->content));
	if (voyager->precision > len && len > 0)
	{
		if (!(str = ft_strnew(voyager->precision - len)))
			return (0);
		ft_memset(str, '0', voyager->precision - len);
		if (!(ft_strappend_back(&str, (char**)(&(vonc->content)))))
			return (0);
	}
	return (1);
}

int		ft_padding_prec(t_pattern *voyager, t_list *vonc)
{
	int		len;

	if (voyager->precision > -1)
	{
		if (*((char*)vonc->content) == '-')
		{
			if (!(ft_padding_prec_neg(voyager, vonc)))
				return (0);
		}
		len = ft_strlen((char*)(vonc->content));
		ft_padding_prec2(voyager, vonc);
		if (voyager->precision == 0 && len == 1
		&& *((char*)(vonc->content)) == '0'
		&& !(voyager->conv & (2 << (ft_indice('#', KNOWN_FLAG)))))
			*((char*)vonc->content) = '\0';
	}
	return (1);
}

int		ft_padding_prec_neg(t_pattern *voyager, t_list *vonc)
{
	char	*str;
	int		len;

	len = ft_strlen((char*)(vonc->content));
	if (voyager->precision > -1)
	{
		ft_memmove(vonc->content, vonc->content + 1, len);
		if (voyager->precision > len)
		{
			if (!(str = ft_strnew(voyager->precision - len + 1)))
				return (0);
			ft_memset(str, '0', voyager->precision - len + 1);
			str[0] = '-';
			if (!(ft_strappend_back(&str, (char**)(&(vonc->content)))))
				return (0);
		}
	}
	return (1);
}

int		ft_padding_spaces(t_pattern *voyager, t_list *vonc)
{
	char	*str;
	int		len;

	len = ft_strlen((char*)(vonc->content));
	if (voyager->field_width > len)
	{
		if (!(str = ft_strnew(voyager->field_width - len)))
			return (0);
		ft_memset(str, ' ', voyager->field_width - len);
		if (!(ft_strappend_back(&str, (char**)(&(vonc->content)))))
			return (0);
	}
	return (1);
}
