/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_conv2_printf.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 07:24:58 by tgouedar          #+#    #+#             */
/*   Updated: 2019/01/11 18:03:27 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long	ft_signed_conv(va_list *ap, int flag)
{
	long long	i;

	if (!flag)
		i = (long long)va_arg(*ap, int);
	else if (flag == 2)
		i = (long long)va_arg(*ap, char);
	else if (flag == 1)
		i = (long long)va_arg(*ap, short);
	else if (flag == 4)
		i = (long long)va_arg(*ap, long);
	else if (flag == 8)
		i = va_arg(*ap, long long);
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
	i = ft_unsigned_conv(ap, LMOD_FLAG(type));
	return (ft_itoa(i));
}

char			*ft_conv_scient(va_list *ap, t_ul type, t_pattern *conv)
{

}

char			*ft_conv_float(va_list *ap, t_ul type, t_pattern *conv)
{
	
}

char			*ft_conv_opti_ef(va_list *ap, tu_ul type, t_pattern *conv)
{

}
