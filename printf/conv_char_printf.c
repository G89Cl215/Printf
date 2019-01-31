/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv3_printf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 18:05:14 by tgouedar          #+#    #+#             */
/*   Updated: 2019/01/31 12:05:40 by tgouedar         ###   ########.fr       */
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

char			*ft_conv_percent(va_list *ap, t_ul type, t_pattern *conv)
{
	if (conv)
	{
		if (type & ((t_ul)1 << STAR_FW))
			conv->field_width = va_arg(*ap, int);
		if (type & ((t_ul)1 << STAR_PR))
			conv->precision = va_arg(*ap, int);
	}
	(void)type;
	(void)conv;
	return (ft_strdup("%"));
}
