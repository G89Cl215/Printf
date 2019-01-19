/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_itoa_base.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 14:25:34 by tgouedar          #+#    #+#             */
/*   Updated: 2019/01/19 13:32:42 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_unsigned_itoa_base(unsigned int nbr, char *base)
{
	unsigned int	conv;
	int				i;
	char			*res;
	int				length;

	length = ft_strlen(base);
	conv = (nbr > 0) ? nbr : -nbr;
	i = (nbr > 0) ? 1 : 2;
	while (conv /= length)
		i++;
	conv = (nbr > 0) ? nbr : -nbr;
	if (!(res = malloc(i + 1)))
		return (NULL);
	res[0] = (nbr > 0) ? base[0] : '-';
	while (conv)
	{
		res[--i] = base[conv % length];
		conv /= length;
	}
	return (res);
}
