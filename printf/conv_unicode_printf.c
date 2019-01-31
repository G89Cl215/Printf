/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv5_printf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 17:27:40 by tgouedar          #+#    #+#             */
/*   Updated: 2019/01/31 12:07:36 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_translate_unichar(union u_unicode *un)
{
	if (un->i >= 128)
	{
		if (un->i >= 4096)
		{
			if (un->i >= 65536)
			{
				(un->str)[3] = 240 | ((1835008 & un->i) >> 17);
				(un->str)[2] = ((un->str)[2] & 3) << 4;
				(un->str)[2] |= ((un->str[1] & 60) >> 2) | 128;
			}
			else
				(un->str)[2] = 224 | ((61440 & un->i) >> 12);
			(un->str)[1] = ((un->str)[1] & 15) << 2;
			(un->str)[1] |= 128 | ((un->str)[0] & 192) >> 6;
		}
		else
			(un->str)[1] = 192 | ((4032 & un->i) >> 6);
		(un->str)[0] = ((un->str)[0] & 191) | 128;
	}
}

char	*ft_conv_unichar(va_list *ap, t_ul type, t_pattern *conv)
{
	union u_unicode	un;
	char			*str;

	(void)conv;
	(void)type;
	un.i = va_arg(*ap, wchar_t);
	ft_translate_unichar(&un);
	if (!(str = (char*)ft_memalloc(4)))
		return (NULL);
	ft_memmove(str, un.str, 4);
	return (str);
}

char	*ft_conv_unistring(va_list *ap, t_ul type, t_pattern *conv)
{
	union u_unicode	un;
	wchar_t			*uni;
	char			*str;
	int				i;

	(void)conv;
	(void)type;
	i = 1;
	uni = va_arg(*ap, wchar_t*);
	while (uni[i])
		i++;
	if (!i)
		return ("\0\0\0\0");
	if (!(str = ft_strnew(i * 4)))
		return (NULL);
	i = 0;
	while (*uni)
	{
		un.i = *uni;
		ft_translate_unichar(&un);
		ft_memmove(str + 4 * i++, (char*)un.str, 4);
		uni++;
	}
	ft_memcpy(str + 4 * i++, "\0\0\0\0", 4);
	return (str);
}
