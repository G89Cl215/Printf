/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing4_conv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 14:00:28 by tgouedar          #+#    #+#             */
/*   Updated: 2019/01/20 16:53:38 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "g_convtab.h"

/* 
 * Conversions en strings de la bonne longueur
 * On peut verser dans le parsing des argument en
 * mode positionnel :	coherence des conversions
 * 						continuite de la zone memoire a convertir
 */

t_list		**ft_conv(t_pattern **pattern, va_list *ap, t_list **buff)
{
	t_pattern	*voyager;
	t_list		**conv;
	char		*str;
	int			i;

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
		ft_ezequiel(voyager, conv, ap);
	if (!(ft_central_padding(pattern, conv)))
		return (ft_parse_error(3, buff, conv, pattern));
	va_end(*ap);
	return (conv);
}

/*	
 *	Utilise la globale g_convtab pour chercher la conversion et la stocker
 *	dans la liste des conv en string
 */

void		ft_ezequiel(t_pattern *ezequiel, t_list **conv, va_list *ap)
{
	char		*str;
	int			j;

	while (ezequiel)
	{
		j = 0;
		while (g_convtab[j].type != ft_type_flag(ezequiel))
			j++;
		str = (*g_convtab[j].ft_conv)(ap, ezequiel->conv, ezequiel);
		if (str)
			ft_lstadd_back(conv, ft_lstnew(str, (ft_strlen(str) + 1)));
		else
			ft_lstadd_back(conv, ft_lstnew(NULL, 0));
		ft_lstadd_back(conv, ft_lstnew(str, (strlen(str) + 1)));
		ezequiel = ezequiel->next;
	}
}
