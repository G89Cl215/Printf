/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_conv2_printf.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 07:24:58 by tgouedar          #+#    #+#             */
/*   Updated: 2019/01/16 13:18:14 by baavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	i = ft_num_conv(ap, ft_lmod_flag(type));
	return (ft_itoa(i));
}

char			*ft_conv_res(va_list *ap, t_ul type, t_pattern *pattern)
{
	return(0);
}

char			*ft_conv_scient(va_list *ap, t_ul type, t_pattern *conv)
{
	return (0);
}

char			*ft_conv_float(va_list *ap, t_ul type, t_pattern *conv)
{
	return (0);
}

char			*ft_conv_opti_ef(va_list *ap, t_ul type, t_pattern *conv)
{
	return (0);
}
