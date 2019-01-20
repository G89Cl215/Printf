/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing4_conv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 14:00:28 by tgouedar          #+#    #+#             */
/*   Updated: 2019/01/20 14:20:08 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "g_convtab.h"

/*
 **  Conversions en strings de la bonne longueur
 */

t_list		**ft_conv(t_pattern **pattern, va_list *ap, t_list **buff)
{
	t_pattern	*voyager;
	t_list		**conv;
	char		*str;
	int			i;
	int			c;

	voyager = *pattern;
	if (!(conv = (t_list**)malloc(sizeof(t_list*))))
		return (NULL);
	*conv = NULL;
	if (voyager->conv % 2)
	{
		if (!(conv = ft_positional_mod(pattern, ap)))
			return (NULL);
	}	
	else
	{	
		c = 0;
		while (voyager)
		{
			c++;
			i = 0;
			while (g_convtab[i].type != ft_type_flag(voyager))
				i++;
			str = (*g_convtab[i].ft_conv)(ap, voyager->conv, voyager);
			if (str)
				ft_lstadd_back(conv, ft_lstnew(str, (ft_strlen(str) + 1)));
			else
				ft_lstadd_back(conv, ft_lstnew(NULL, 0));
			//				ft_stock_n_char(conv, ap, buff, c);
			voyager = voyager->next;
		}
	}
	if (!(ft_central_padding(pattern, conv)))
		return (ft_parse_error(3, buff, pattern));
	return (conv);
}

void	ft_ezequiel(t_pattern *ezequiel, t_list **tmp, va_list *ap)
{
	char		*str;
	int			j;

	while (ezequiel->next != NULL)
	{
		j = 0;
		while (g_convtab[j].type != ft_type_flag(ezequiel))
			j++;
		str = (*g_convtab[j].ft_conv)(ap, ezequiel->conv, ezequiel);
		ft_lstadd_back(tmp, ft_lstnew(str, (strlen(str) + 1)));
		ezequiel = ezequiel->next;
	}
}
