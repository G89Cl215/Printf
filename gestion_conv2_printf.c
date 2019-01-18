/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_conv2_printf.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 07:24:58 by tgouedar          #+#    #+#             */
/*   Updated: 2019/01/18 21:05:46 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_conv_int(va_list *ap, t_ul type, t_pattern *conv)
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
	return (ft_itoa(i));
}

char			*ft_conv_res(va_list *ap, t_ul type, t_pattern *pattern)
{
	(void)
	return(0);
}

char			*ft_conv_scient(va_list *ap, t_ul type, t_pattern *conv)
{
	return (0);
}

char			*ft_conv_float(va_list *ap, t_ul type, t_pattern *conv)
{
	u_double		u;
	t_ul			s;
	t_ul			exp;
	t_ul			mant;
	char			*str;


	u.d = va_arg(*ap, double);
	s = (((t_ul)1 << 63) & u.l) ? 1 : 0;
	mant = ((((t_ul)1 << 53) - 1) & u.l);
	exp = ((((t_ul)2047 << 53) & u.l) >> 53) - 1023;
	if (exp ^ 2047)
	{
		mant &= ((t_ul)1 << 54); // conditions de denormalisation d'un double ????
		str = ft_create_float(mant, 54);
		while (exp)
		{
			if (exp > 0)
			{
				ft_strsum_dec(str, str);
				exp--;
			}
			if (exp < 0)
			{
				ft_strdiv_2(str);
				exp++;
			}
		}
		return (ft_trim_0(str, s));
	}
	else if (mant)
		return ("NaN");
	return (s ? "-Infinity" : "Infinity");
}

char			*ft_conv_opti_ef(va_list *ap, t_ul type, t_pattern *conv)
{
	return (0);
}
