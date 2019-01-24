/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_conv2_printf.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 07:24:58 by tgouedar          #+#    #+#             */
/*   Updated: 2019/01/24 01:18:43 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_ull		ft_num_conv(va_list *ap, int flag)
{
	t_ull	i;

	i = 0;
	if (!flag)
		i = (t_ull)va_arg(*ap, int);
	else if (flag == 2)
		i = (t_ull)va_arg(*ap, int);
	else if (flag == 1)
		i = (t_ull)va_arg(*ap, int);
	else if (flag == 4)
		i = (t_ull)va_arg(*ap, long);
	else if (flag == 8)
		i = (t_ull)va_arg(*ap, long long);
	return (i);
}

char			*ft_conv_int(va_list *ap, t_ul type, t_pattern *conv)
{
	t_ull	i;

	if (conv)
	{
		if (type & ((t_ul)1 << STAR_FW))
			conv->field_width = va_arg(*ap, int);
		if (type & ((t_ul)1 << STAR_PR))
			conv->precision = va_arg(*ap, int);
	}
	i = ft_num_conv(ap, ft_t_ul_flag(type));
	return (ft_itoa(i));
}
