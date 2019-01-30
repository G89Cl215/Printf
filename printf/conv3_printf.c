/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv3_printf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 18:05:14 by tgouedar          #+#    #+#             */
/*   Updated: 2019/01/30 13:28:29 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "float_conv_tools.h"

char	*ft_conv_char(va_list *ap, t_ul type, t_pattern *conv)
{
	char	*str;
	char	c;

	(void)type;
	(void)conv;
	c = (char)va_arg(*ap, int);
	if (!(str = ft_strnew(1)))
		return (NULL);
	str[0] = c;
	return (str);
}

char	*ft_conv_addr(va_list *ap, t_ul type, t_pattern *conv)
{
	void	*ptr;
	char	*ptr_val;

	(void)type;
	(void)conv;
	ptr = va_arg(*ap, void*);
	ptr_val = ft_unsigned_itoa_base((t_ul)ptr, "0123456789abcdef");
	return (ptr_val);
}

char	*ft_conv_str(va_list *ap, t_ul type, t_pattern *conv)
{
	char	*str;

	if (conv)
	{
		if (type & ((t_ul)1 << STAR_FW))
			conv->field_width = va_arg(*ap, int);
		if (type & ((t_ul)1 << STAR_PR))
			conv->precision = va_arg(*ap, int);
	}
	str = va_arg(*ap, char*);
	if (!str)
		return (ft_strdup("(null)"));
	return (ft_strdup(str));
}
