/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_conv1_printf.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 06:37:44 by tgouedar          #+#    #+#             */
/*   Updated: 2018/12/18 17:09:48 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_ull		ft_unsigned_conv(va_list *ap, int flag)
{
	t_ull	i;

	if (!flag)
		i = (t_ull)va_arg(*ap, unsigned int);
	else if (flag == 2)
		i = (t_ull)va_arg(*ap, unsigned char);
	else if (flag == 1)
		i = (t_ull)va_arg(*ap, unsigned short);
	else if (flag == 4)
		i = (t_ull)va_arg(*ap, t_ul);
	else if (flag == 8)
		i = va_arg(*ap, t_ull);
	else
		//PARSING_ERROR... IGNORED ?
		return (i);
}

char		*ft_conv_binary(va_list *ap, t_pattern *conv)
{
	t_ull	i;
	char	*res;

	i = ft_unsigned_conv(ap, LMOD_FLAG(conv));
	res = ft_Uitoa_base(i, "01");

	//PADDING, PRECISION, >>>>
}

char			*ft_conv_Uint(va_list *ap, t_pattern *conv)
{
	t_ull	i;
	char	*res;

	i = ft_unsigned_conv(ap, LMOD_FLAG(conv));
	res = ft_Uitoa_base(i, "0123456789");
}

char			*ft_conv_hex(va_list *ap, t_pattern *conv)
{
	t_ull	i;
	char	*res;

	i = ft_unsigned_conv(ap, LMOD_FLAG(conv));
	res = ft_Uitoa_base(i, "0123456789abcdef");
	if (TYPE_FLAG(conv) & (1 << ft_indice('X', KNOWN_CONV)))
		ft_toupper(&res);

	//PADDING, PRECISION, >>>>

}

char			*ft_conv_octal(va_list *ap, t_pattern *conv)
{
	t_ull	i;
	char	*res;

	i = ft_unsigned_conv(ap, LMOD_FLAG(conv));
	res = ft_Uitoa_base(i, "01234567");

	//PADDING, PRECISION, >>>>
}
