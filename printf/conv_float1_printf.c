/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_float1_printf.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baavril <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 16:36:05 by baavril           #+#    #+#             */
/*   Updated: 2019/01/31 12:53:00 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "float_conv_tools.h"

char			*ft_conv_double2(long exp, t_ull mant, t_ul s)
{
	char				*str;

	if ((exp - 1023) ^ 2047)
	{
		mant |= (exp) ? ((t_ul)1 << 52) : 0;
		exp -= (exp) ? 1023 : 1022;
		if (!(str = ft_create_float(mant, 53)))
			return (NULL);
		while (exp)
		{
			(exp > 0) ? ft_strsum_dec(str, str) : ft_strdiv_2(str);
			exp += (exp < 0) ? 1 : -1;
		}
		ft_trim_0(str, s);
		return (str);
	}
	else if (mant)
		return (ft_strdup("NaN"));
	return (s ? ft_strdup("-INF") : ft_strdup("INF"));
}

char			*ft_conv_double(va_list *ap)
{
	union u_float		u;
	t_ul				s;
	long				exp;
	t_ul				mant;

	u.d = va_arg(*ap, double);
	s = (((t_ul)1 << 63) & u.l) ? 1 : 0;
	mant = ((((t_ul)1 << 53) - 1) & u.l);
	exp = ((long)2047) & (u.l >> 52);
	return (ft_conv_double2(exp, mant, s));
}

char			*ft_conv_long_double(va_list *ap)
{
	union u_l_float		u;
	int					s;
	long				exp;
	t_ul				mant;
	char				*str;

	u.d = va_arg(*ap, long double);
	s = (((t_ul)1 << 15) & u.l[1]) ? 1 : 0;
	exp = u.l[1] & ((1 << 15) - 1);
	if (((mant = u.l[0]) || 1) && (exp - 16383) ^ ((1 << 15) - 1))
	{
		exp -= (exp) ? 16383 : 16382;
		if (!(str = ft_create_float(mant, 64)))
			return (NULL);
		while (exp)
		{
			(exp > 0) ? ft_strsum_dec(str, str) : ft_strdiv_2(str);
			exp += (exp < 0) ? 1 : -1;
		}
		ft_trim_0(str, s);
		return (str);
	}
	else if (mant & (((t_ul)1 << 63) - 1))
		return (ft_strdup("NaN"));
	return (s ? ft_strdup("-INF") : ft_strdup("INF"));
}
