/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 15:42:58 by tgouedar          #+#    #+#             */
/*   Updated: 2018/12/09 12:22:21 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *cont, size_t cont_size)
{
	t_list	*new;

	if (!(new = (t_list*)malloc(sizeof(*new))))
		return (NULL);
	new->content_size = ((cont) ? cont_size : 0);
	if (!(new->content = (void*)malloc(new->content_size)))
		return (NULL);
	new->content = ((cont) ? ft_memcpy(new->content, cont, cont_size) : NULL);
	new->next = NULL;
	return (new);
}
