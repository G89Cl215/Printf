/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 17:00:33 by tgouedar          #+#    #+#             */
/*   Updated: 2019/01/30 13:34:00 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "ft_printf.h"
#include <unistd.h>

int			ft_print_unichar(char *str)
{
	int		i;

	i = 4;
	while (--i)
	{
		if (str[i])
			write(1, &((str[i])), 1);
	}
	write(1, &((str[0])), 1);
	return (1);
}

int			ft_altprint(t_list *conv_cur)
{
	int		res;
	char	*str;

	res = 0;
	str = conv_cur->content;
	if ((int)conv_cur->content_size == -1)
	{
		(ft_strlen(str)) ? write(1, str, (ft_strlen(str) - 1)) : res++;
		ft_putchar(0);
		return (res + ft_strlen(str));
	}
	if ((int)conv_cur->content_size == -2)
		return (ft_print_unichar(str));
	if ((int)conv_cur->content_size == -3)
	{
		while ((str[0]) || (str[1]) || (str[2]) || (str[3]))
		{
			res += ft_print_unichar(str);
			str += 4;
		}
	}
	return (res);
}

/*
** Recolle les bouts en lisant un buffer puis une chaine convertie,
**	jusau'a epuisement de la liste chainee buffer.
**	NB : La fonction doit avoir epuise les conversions avant le dernier
**	buffer.
**
**	write la chaine de caractere creee et retourne la longueur totale de la
**	chaine de caractere.
*/

int			ft_concat_buffer(t_list **buff, t_list **conv)
{
	int			res;
	t_list		*conv_cur;
	t_list		*buff_cur;

	conv_cur = (conv) ? *conv : NULL;
	buff_cur = *buff;
	res = 0;
	while (buff_cur)
	{
		res += write(1, buff_cur->content, buff_cur->content_size);
		if (conv_cur)
		{
			if ((int)(conv_cur->content_size) < 0)
				res += ft_altprint(conv_cur);
			else
			{
				ft_putstr(conv_cur->content);
				res += ft_strlen(conv_cur->content);
			}
			conv_cur = conv_cur->next;
		}
		buff_cur = buff_cur->next;
	}
	ft_free_mem(buff, conv, NULL, NULL);
	return (res);
}
