/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing4_conv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 14:00:28 by tgouedar          #+#    #+#             */
/*   Updated: 2019/01/30 13:47:52 by tgouedar         ###   ########.fr       */
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
	else if (!(ft_ezequiel(voyager, conv, ap)))
		return (0);
	if (!(ft_central_padding(pattern, conv)))
	{
		ft_parse_error(3, buff, conv, pattern);
		return (NULL);
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

int			ft_unilen(char *str)
{
	int		len;

	len = 0;
	while ((str[0]) || (str[1]) || (str[2]) || (str[3]))
	{
		str += 4;
		len += 4;
	}
	return (len);
}

int			ft_stock_conv(t_list **conv, size_t ez_type, char *str)
{
	size_t		index;

	index = 1;
	if (!(ez_type & (index << (TYPE_START + ft_indice('S', KNOWN_CONV)))))
	{
		if (!(ft_stock_string(conv, str, ft_strlen(str) + 1)))
			return (0);
	}
	if (!(*str)
	&& ez_type & (index << (TYPE_START + ft_indice('c', KNOWN_CONV))))
		ft_set_spevalue(conv, -1);
	if (ez_type & (index << (TYPE_START + ft_indice('C', KNOWN_CONV))))
		ft_set_spevalue(conv, -2);
	if (ez_type & (index << (TYPE_START + ft_indice('S', KNOWN_CONV))))
	{
		if (!(ft_stock_string(conv, str, ft_unilen(str) + 4)))
			return (0);
		ft_set_spevalue(conv, -3);
	}
	return (1);
}

/*
**	Utilise la globale g_convtab pour chercher la conversion et la stocker
**	dans la liste des conv en string
*/

int			ft_ezequiel(t_pattern *ezequiel, t_list **conv, va_list *ap)
{
	char		*str;
	int			j;

	while (ezequiel)
	{
		j = 0;
		while (g_convtab[j].type != ft_type_flag(ezequiel))
			j++;
		if ((str = (*g_convtab[j].ft_conv)(ap, ezequiel->conv, ezequiel)))
		{
			if (!(ft_stock_conv(conv, ezequiel->conv, str)))
				return (0);
		}
		else
		{
			if (!(ft_stock_string(conv, NULL, 0)))
				return (0);
		}
		ezequiel = ezequiel->next;
		ft_strdel(&str);
	}
	return (1);
}
