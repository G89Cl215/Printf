/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 17:15:19 by tgouedar          #+#    #+#             */
/*   Updated: 2019/01/13 15:23:32 by baavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void			ft_strappend(char **dest, char **src)
{
	char	*tmp;
	size_t	i;

	i = ft_strlen(*dest) + ft_strlen(*src) + 1;
	ft_putendl("seg");
	if (!(tmp = (char*)malloc(i)))
		return ;
	ft_memcpy(tmp, *dest, ft_strlen(*dest) + 1);
	tmp = ft_strcat(tmp, *src);
	ft_memdel((void**)dest);
	ft_memdel((void**)src);
	*dest = tmp;
}
