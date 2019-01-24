/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_conv4_float.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 01:16:25 by tgouedar          #+#    #+#             */
/*   Updated: 2019/01/24 01:19:27 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "float_conv_tools.h"

char			*ft_conv_scient(va_list *ap, t_ul type, t_pattern *conv)
{
	char	*str;
	int 	i;
	char	*pow_10;

	if (!(pow_10 = ft_strnew(5)))
		return (NULL);
	pow_10[0] = 'e';
	pow_10[1] = '\0';
	str = ft_conv_float(ap, type, conv);
	i = ft_reajust_zero(str);
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
	return (ft_t_ul_flag(type) == (1 << ft_indice('L', KNOWN_LMOD))
			? ft_conv_long_float(ap) : ft_conv_float(ao) );

}

char			*ft_conv_double(va_list *ap)
{
	u_float		u;
	t_ul		s;
	long		exp;
	t_ullll		mant;
	char		*str;

	u.d = va_arg(*ap, double);
	s = (((t_ul)1 << 63) & u.l) ? 1 : 0;
	mant = ((((t_ul)1 << 53) - 1) & u.l);
	exp = ((long)2047) & (u.l >> 52);
	if ((exp - 1023) ^ 2047)
	{
		if (exp)
		{
			exp -= 1023;
			mant |= ((t_ul)1 << 52);
		}
		else
			exp -= 1022;
		str = ft_create_float(mant, 53);
		while (exp)
		{
			(exp > 0) ?	ft_strsum_dec(str, str) : ft_strdiv_2(str);
			exp += (exp < 0) ? 1 : -1;
		}
		return (ft_trim_0(str, s));
	}
	else if (mant)
		return ("NaN");
	return (s ? "-INF" : "INF");
}

char			*ft_conv_long_double(va_list *ap)
{
	u_l_float		u;
	t_ull		s;
	long long	exp;
	t_ull		mant;
	char		*str;

	u.d = va_arg(*ap, long double);
	s = (((t_ull)1 << 127) & u.l) ? 1 : 0;
	mant = ((((t_ull)1 << 111) - 1) & u.l);
	exp = ((t_ull)u.l << 1) >> 111;
	if ((exp - 16383) & ~((t_ull)0))
	{
		if (exp)
		{
			exp -= 16383;
			mant |= ((t_ul)1 << 111);
		}
		else
			exp -= 16382;
		str = ft_create_float(mant, 112);
		while (exp)
		{
			(exp > 0) ?	ft_strsum_dec(str, str) : ft_strdiv_2(str);
			exp += (exp < 0) ? 1 : -1;
		}
		return (ft_trim_0(str, s));
	}
	else if (mant)
		return ("NaN");
	return (s ? "-INF" : "INF");
}

char			*ft_conv_opti_ef(va_list *ap, t_ul type, t_pattern *conv)
{
	return (0);
}
