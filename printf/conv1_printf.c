/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv1_printf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 18:04:44 by tgouedar          #+#    #+#             */
/*   Updated: 2019/01/30 13:24:59 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_ull		ft_unsigned_num_conv(va_list *ap, int flag)
{
	t_ull	i;

	i = 0;
	if (!flag)
		i = ((t_ull)0 ^ (unsigned)va_arg(*ap, int));
	else if (flag == 2)
		i = ((t_ull)0 ^ (unsigned char)va_arg(*ap, int));
	else if (flag == 1)
		i = ((t_ull)0 ^ (unsigned short)va_arg(*ap, int));
	else if (flag == 4)
		i = (unsigned long)va_arg(*ap, long);
	else if (flag == 8)
		i = (t_ull)va_arg(*ap, long long);
	else if (flag == 32)
		i = (uintmax_t)va_arg(*ap, uintmax_t);
	else if (flag == 64)
		i = (ssize_t)va_arg(*ap, ssize_t);
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
	i = ft_unsigned_num_conv(ap, ft_lmod_flag(conv));
	return (ft_unsigned_itoa_base(i, "01"));
}

char		*ft_conv_uint(va_list *ap, t_ul type, t_pattern *conv)
{
	t_ull	i;

	if (conv)
	{
		if (type & ((t_ul)1 << STAR_FW))
			conv->field_width = va_arg(*ap, int);
		if (type & ((t_ul)1 << STAR_PR))
			conv->precision = va_arg(*ap, int);
	}
	i = ft_unsigned_num_conv(ap, ft_lmod_flag(conv));
	return (ft_unsigned_itoa_base(i, "0123456789"));
}

char		*ft_conv_hex(va_list *ap, t_ul type, t_pattern *conv)
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
	i = ft_unsigned_num_conv(ap, ft_lmod_flag(conv));
	if (!(res = ft_unsigned_itoa_base(i, "0123456789abcdef")))
		return (NULL);
	if (type & ((t_ul)1 << (TYPE_START + ft_indice('X', KNOWN_CONV))))
		ft_strupper(res);
	return (res);
}

char		*ft_conv_octal(va_list *ap, t_ul type, t_pattern *conv)
{
	t_ull	i;

	if (conv)
	{
		if (type & ((t_ul)1 << STAR_FW))
			conv->field_width = va_arg(*ap, int);
		if (type & ((t_ul)1 << STAR_PR))
			conv->precision = va_arg(*ap, int);
	}
	if (!(type & ((t_ul)1 << (TYPE_START + ft_indice('O', KNOWN_CONV)))))
		i = ft_unsigned_num_conv(ap, ft_lmod_flag(conv));
	else
		i = (t_ull)va_arg(*ap, long long);
	return (ft_unsigned_itoa_base(i, "01234567"));
}
