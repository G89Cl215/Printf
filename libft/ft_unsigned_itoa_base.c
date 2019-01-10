/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_itoa_base.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 17:40:47 by tgouedar          #+#    #+#             */
/*   Updated: 2018/12/18 17:40:58 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_unsigned_itoa_base(unsigned long long nb, char *base_to)
{
	char	*res;
	size_t	i;
	int		l;
	int		base_length;

	i = 0;
	l = 1;
	base_length = ft_strlen(base_to);
	while ((nb / l) && ++i)
		l *= base_length;
	if (!(res = ft_strnew(i)))
		return (NULL);
	i = 0;
	while (l > 1)
	{
		res[i++] = base_to[(nb / l) % base_length];
		l /= base_length;
	}
	res[i] = base_to[nb % base_length];
	res[++i] = '\0';
	return (res);
}
