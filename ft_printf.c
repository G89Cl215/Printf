/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 15:22:28 by tgouedar          #+#    #+#             */
/*   Updated: 2018/12/11 14:32:03 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdarg.h>
#include <stdio.h>

int		ft_printf(const char * restrict format, ...)
{
	char		*str;
	va_list		param;
	size_t		i;

	str = ft_strdup(format);
	while (*str)
	{
		i = ft_strcspn(str, "%");
		str[i] = 0;
		ft_putstr(str);
		str += i + 1;
	}
	return (0);
}
/*
int		foo(int i, ...)
{
	va_list ap;
	int		res;

	res = 0;
	va_start(ap, i);
	res = sizeof(ap);
	va_end(ap);
	return (res);
}
		...
		use ap2 to iterate over the arguments again 
		...
		va_end(ap2);
		}*/

int		main(int ac, char **av)
{
	int	i = 0;
//	ft_putnbr(foo(1, 65));
//	ft_putchar('\n');
	ft_printf("pump %it% up");
	ft_putchar('\n');
//	ft_putnbr(foo(2, 65, 3, 89, 95));
//	ft_putchar('\n');

	return (0);
}
