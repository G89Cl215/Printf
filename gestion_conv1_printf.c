/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_conv1_printf.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 06:37:44 by tgouedar          #+#    #+#             */
/*   Updated: 2019/01/12 18:17:04 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_ull		num_conv(va_list *ap, int flag)
{
	t_ull	i;
	
	i = 0;
	if (!flag)
		i = (t_ull)va_arg(*ap, int);
	else if (flag == 2)
		i = (t_ull)((char)va_arg(*ap, int));
	else if (flag == 1)
		i = (t_ull)((short)va_arg(*ap, int));
	else if (flag == 4)
		i = (t_ull)va_arg(*ap, long);
	else if (flag == 8)
		i = (t_ull)va_arg(*ap, long long);
	return (i);
}

char		*ft_conv_binary(va_list *ap, t_ul type, t_pattern *conv)
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
	return (ft_unsigned_itoa_base(i, "01"));
}

char			*ft_conv_Uint(va_list *ap, t_ul type, t_pattern *conv)
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
	return (ft_unsigned_itoa_base(i, "0123456789"));
}

char			*ft_conv_hex(va_list *ap, t_ul type, t_pattern *conv)
{
	t_ull	i;
	char	*res;

	if (conv)
	{
		if (type & ((t_ul)1 << STAR_FW))
			conv->field_width = va_arg(*ap, int);
		if (type & ((t_ul)1 << STAR_PR))
			conv->precision = va_arg(*ap, int);
	}
	i = ft_num_conv(ap, ft_lmod_flag(type));
	res = ft_unsigned_itoa_base(i, "0123456789abcdef");
	if (type & (1 << ft_indice('X', KNOWN_CONV)))
		ft_strupper(res);
	return (res);
}

char			*ft_conv_octal(va_list *ap, t_ul type, t_pattern *conv)
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
	return (ft_unsigned_itoa_base(i, "01234567"));
}
