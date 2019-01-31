/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv4_printf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 18:05:25 by tgouedar          #+#    #+#             */
/*   Updated: 2019/01/30 07:06:28 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "float_conv_tools.h"

void			ft_conv_scient2(char *pow_10, int i)
{
	if (i >= 0 && i < 10)
		pow_10 = ft_strcat(pow_10, "+0\0");
	if (i >= 10)
		pow_10 = ft_strcat(pow_10, "+\0");
	if (i < 0 && i > -10)
	{
		pow_10 = ft_strcat(pow_10, "-0\0");
		pow_10 = ft_strcat(pow_10, ft_itoa(-i));
	}
	else
		pow_10 = ft_strcat(pow_10, ft_itoa(i));
}

char			*ft_conv_scient(va_list *ap, t_ul type, t_pattern *conv)
{
	char	*str;
	int		i;
	char	*pow_10;

	if (!(pow_10 = ft_strnew(5)))
		return (NULL);
	pow_10[0] = 'e';
	pow_10[1] = '\0';
	str = ft_conv_float(ap, type, conv);
	i = ft_reajust_zero(str);
	ft_conv_scient2(pow_10, i);
	str = ft_strcat(str, pow_10);
	free(pow_10);
	if (type & ((t_ul)1 << (TYPE_START + ft_indice('E', KNOWN_CONV))))
		ft_strupper(str);
	return (str);
}

char			*ft_conv_float(va_list *ap, t_ul type, t_pattern *conv)
{
	if (conv)
	{
		if (type & ((t_ul)1 << STAR_FW))
			conv->field_width = va_arg(*ap, int);
		if (type & ((t_ul)1 << STAR_PR))
			conv->precision = va_arg(*ap, int);
	}
	return ((ft_t_ul_flag(type) & (1 << ft_indice('L', KNOWN_LMOD)))
			? ft_conv_long_double(ap) : ft_conv_double(ap));
}

char			*ft_conv_opti_ef(va_list *ap, t_ul type, t_pattern *conv)
{
	if (conv)
	{
		if (type & ((t_ul)1 << STAR_FW))
			conv->field_width = va_arg(*ap, int);
		if (type & ((t_ul)1 << STAR_PR))
			conv->precision = va_arg(*ap, int);
	}
	return (0);
}
