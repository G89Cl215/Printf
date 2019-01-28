/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 15:22:28 by tgouedar          #+#    #+#             */
/*   Updated: 2019/01/28 18:24:27 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "ft_printf.h"
#include <stdarg.h>

int		ft_printf(const char * restrict format, ...)
{
	va_list		ap;
	char		*str;
	t_pattern	**pattern;
	t_list		**buff;
	t_list		**conv;

	if (!(str = ft_strdup(format))
			|| !(pattern = (t_pattern**)malloc(sizeof(t_pattern*)))
			|| !(buff = (t_list**)malloc(sizeof(t_list*))))
	{
		free(str);
		ft_free_pattern(pattern);
		return (-1);
	}
	*pattern = NULL;
	*buff = NULL;
	if ((ft_pattern_detect(str, buff, pattern)))
	{
		va_start(ap, format);
		if (!(conv = ft_conv(pattern, &ap, buff)) && (*pattern))
		{
			va_end(ap);
			return (-1);
		}
		va_end(ap);
		free(str);
		ft_free_pattern(pattern);
		return (ft_concat_buffer(buff, conv));
	}
	ft_strdel(&str);
	ft_lstfree(buff);
	ft_free_pattern(pattern);
	return (-1);
}
