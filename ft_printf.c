/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 15:22:28 by tgouedar          #+#    #+#             */
/*   Updated: 2019/01/20 16:54:19 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdarg.h>

/*
 * Recolle les bouts en lisant un buffer puis une chaine convertie,
 *	jusau'a epuisement de la liste chainee buffer.
 *	NB : La fonction doit avoir epuise les conversions avant le dernier
 *	buffer.
 *
 *	write la chaine de caractere creee et retourne la longueur totale de la
 *	chaine de caractere.
 */

int		ft_concat_buffer(t_list **buff, t_list **conv)
{
	int 	res;
	char	**str;
	char	**bus;
	t_list	*conv_cur;
	t_list	*buff_cur;

	conv_cur = *conv;
	buff_cur = *buff;
	if (!(str = (char**)malloc(sizeof(char*))) 
			|| (*str = ft_strnew(0))
			|| !(bus = (char**)malloc(sizeof(char*))))
		return (-1);
	*bus = NULL;
	while (buff_cur)
	{
		*bus = ft_strdup(buff_cur->content);
		ft_strappend(str, bus);
		if (conv_cur)
		{
			if (!conv_cur->content)
				*bus = ft_itoa(res);
			else
				*bus = ft_strdup(conv_cur->content);
			ft_strappend(str, bus);
			conv_cur = conv_cur->next;
		}
		buff_cur = buff_cur->next;
	}
	ft_memdel((void**)str);
	ft_lstfree(conv);
	ft_lstfree(buff);
	return (ft_strlen(*str));	
}

int		ft_printf(const char * restrict format, ...)
{
	va_list		ap;
	char		*str;
	t_pattern	**pattern;
	t_list		**buff;
	t_list		**conv;

	str = ft_strdup(format);
	if (!(pattern = (t_pattern**)malloc(sizeof(t_pattern*)))
			|| !(buff = (t_list**)malloc(sizeof(t_list*))))
	{
		ft_free_pattern(pattern);
		return (-1);
	}
	*pattern = NULL;
	*buff = NULL;
	if ((ft_pattern_detect(str, buff, pattern)))
	{
		va_start(ap, format);
		if (!(conv = ft_conv(pattern, &ap, buff)))
		{
			va_end(ap);
			return (-1);
		}
		return (ft_concat_buffer(buff, conv));
	}
	return (-1);
}
