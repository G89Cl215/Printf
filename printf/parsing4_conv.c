/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing4_conv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 14:00:28 by tgouedar          #+#    #+#             */
/*   Updated: 2019/01/29 00:05:32 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "g_convtab.h"

/*
** Conversions en strings de la bonne longueur
** On peut verser dans le parsing des argument en
** mode positionnel :	coherence des conversions
** 						continuite de la zone memoire a convertir
*/

t_list		**ft_conv(t_pattern **pattern, va_list *ap, t_list **buff)
{
	t_pattern	*voyager;
	t_list		**conv;
	char		*str;
	int			i;

	if (!(*pattern))
		return (NULL);
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
	{
		ft_parse_error(3, buff, conv, pattern);
		return (0);
	}
	va_end(*ap);
	return (conv);
}

void		ft_set_spevalue(t_list **conv, int i)
{
	t_list *vonc;

	vonc = *conv;
	while (vonc->next != NULL)
		vonc = vonc->next;
	vonc->content_size = i;
}

/*
**	Utilise la globale g_convtab pour chercher la conversion et la stocker
**	dans la liste des conv en string
*/

void		ft_ezequiel(t_pattern *ezequiel, t_list **conv, va_list *ap)
{
	t_list		*lb;
	char		*str;
	int			j;

	while (ezequiel)
	{
		j = 0;
		while (g_convtab[j].type != ft_type_flag(ezequiel))
			j++;
		str = (*g_convtab[j].ft_conv)(ap, ezequiel->conv, ezequiel);
		if (str)
		{
			ft_lstadd_back(conv, ft_lstnew(str, (ft_strlen(str) + 1)));
			if (!(*str)
			&& ezequiel->conv & ((t_ul)1 << (TYPE_START + ft_indice('c', KNOWN_CONV))))
				ft_set_spevalue(conv, -1);
			if (ezequiel->conv & ((t_ul)1 << (TYPE_START + ft_indice('C', KNOWN_CONV))))
				ft_set_spevalue(conv, -2);
			if (ezequiel->conv & ((t_ul)1 << (TYPE_START + ft_indice('S', KNOWN_CONV))))
				ft_set_spevalue(conv, -3);
		}
		else
			ft_lstadd_back(conv, ft_lstnew(NULL, 0));
		ezequiel = ezequiel->next;
	}
}
