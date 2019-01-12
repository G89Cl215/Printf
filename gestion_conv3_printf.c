/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_conv3_printf.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 07:25:48 by tgouedar          #+#    #+#             */
/*   Updated: 2019/01/11 18:03:27 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_conv_char(va_list *ap, t_ul type, t_pattern *conv)
{
	char	*c;

	c = ft_strnew(1);
	c[0] = va_arg(*ap, char);
	return (c);
}

	char			*ft_conv_addr(va_list *ap, t_ul type, t_pattern *conv)
	{
		void	*ptr;
		char	*str;

		ptr = va_arg(*ap, void*);
		str = ft_Uitoa_base((), "0123456789abcdef")
	return (str);
}

char			*ft_conv_string(va_list *ap, t_ul type, t_pattern *conv)
{
	char	*str;
	
	if (conv)
	{
		if (type & ((t_ul)1 << STAR_FW))
			conv->field_width = va_arg(*ap, int);
		if (type & ((t_ul)1 << STAR_PR))
			conv->precision = va_arg(*ap, int);
	}
	str = ; //  ??
}
