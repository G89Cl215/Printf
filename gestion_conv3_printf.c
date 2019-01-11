/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_conv3_printf.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 07:25:48 by tgouedar          #+#    #+#             */
/*   Updated: 2019/01/11 14:56:04 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_conv_char(va_list *ap, t_pattern *conv, int flag_p)
{
	char	*c;

	c = ft_strnew(1);
	c[0] = va_arg(*ap, char);
	return (c);
}

char			*ft_conv_addr(va_list *ap, t_pattern *conv, int flag_p)
{
	void	*ptr;
	char	*str;

	ptr = va_arg(*ap, void*);
	str = 
	return (str);
}

char			*ft_conv_string(va_list *ap, t_pattern *conv, int flag_p)
{
	char	*str;

	
}
