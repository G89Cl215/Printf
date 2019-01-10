/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 15:22:28 by tgouedar          #+#    #+#             */
/*   Updated: 2019/01/10 19:00:03 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdarg.h>

/*	Recolle les bouts en lisant un buffer puis une chaine convertie,
 * 	jusau'a epuisement de la liste chainee buffer.
 *	NB : La fonction doit avoir epuise les conversions avant le dernier
 *	buffer.
 *
 *	write la chaine de caractere creee et retourne la longueur totale de la
 *	chaine de caractere.
 */

int		ft_concat_buffer(t_list **buff, t_list **conv)
{
	int 	res;
	char	*str;
	t_list	*conv_cur;
	t_list	*buff_cur;

	conv_cur = *conv;
	buff_cur = *buff;
	while (buff_cur)
	{
		ft_strappend(str, (char*)(buff_cur->data));
		res = ft_strlen(str):
			if (conv_cur)
		{
			ft_strappend(str, (char*)(conv_cur->data));
			conv_cur = conv_cur->next;
		}
		buff_cur = buff_cur->next;
	}
	ft_putstr(str);
	ft_memdel(&str);
	res = ft_strlen(str);
	ft_lstfree(conv);
	ft_lstfree(buff);
	return (res);	
}


/*
 * ** detecte si positionnal mod est actif - si oui go parse - si non go liste de conversion
 * */

t_list	**ft_positional_mod(t_pattern **pattern, va_list *ap)
{
	t_pattern	*voyager;

	voyager = *pattern;
	if (max = ft_verif_nbr_arg(pattern))
	{
		while (i <= max)
		{
			if (!(ft_verif_type(i, pattern, ap)))
				return (NULL);
		}
		return (ft_positional_conv(pattern));
	}
	return (NULL);
}

/* C conversions en strings de la bonne longueur
*/

t_list		**ft_conv(t_pattern **pattern, va_list *ap)
{
	t_pattern	*voyager;
	t_list		**conv;
	char		*str;
	int			i;
	int			type;
	int			flag;

	voyager = *pattern;
	if (!(conv = (t_list**)malloc(sizeof(t_list*))))
		return (NULL);
	if (voyager->conv % 2)
		return (ft_positional_mod(pattern, ap));
	while (*voyager)
	{
		i = 0;
		while (g_convtab[i].type != TYPE_FLAG(voyager))
			i++;
		str = (*g_convtab[i])(ap, voyager);



		ft_lstadd_back(conv, ft_lstnew(str, strlen(str)));
		voyager = voyager->next;
	}
	ft_lstfree(pattern);
	return (conv);
}

int		ft_printf(const char * restrict format, ...)
{
	va_list		ap;
	char		*str;
	t_pattern	**pattern;
	t_list		*buff;
	t_list		**conv;

	str = ft_strdup(format);
	if (!(pattern = (t_pattern**)malloc(sizeof(t_pattern*))) ||
			!(buff = (t_list**)malloc(sizeof(t_list*))))
	{
		//du free ici
		return (-1);
	}
	if (ft_pattern_detect(str, buff, pattern))
	{
		va_start(format, ap);
		conv = ft_conv(pattern, &ap);
		va_end(ap);
		free(str);
		return (ft_concat_buffer(buff, conv));
	}
	//ici aussi
	free(str);
	return (-1);
}
