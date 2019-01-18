/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 15:22:28 by tgouedar          #+#    #+#             */
/*   Updated: 2019/01/18 21:19:46 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "g_convtab.h"
#include <stdarg.h>

/*
 ** Recolle les bouts en lisant un buffer puis une chaine convertie,
 **	jusau'a epuisement de la liste chainee buffer.
 **	NB : La fonction doit avoir epuise les conversions avant le dernier
 **	buffer.
 **
 **	write la chaine de caractere creee et retourne la longueur totale de la
 **	chaine de caractere.
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
		*bus = ft_strdup(buff_cur->content); //pourquoi du strdup ici ?
		res = ft_strlen(*str);
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
	res = ft_strlen(*str);
	ft_memdel((void**)str);
	ft_lstfree(conv);
	ft_lstfree(buff);
	return (res);	
}



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
		ft_putendl(str);
		va_start(ap, format);
		if (!(conv = ft_conv(pattern, &ap, buff)))
		{
			va_end(ap);
			return (-1);
		}
		va_end(ap);
		free(str);
		return (ft_concat_buffer(buff, conv));
	}
	ft_free_pattern(pattern);
	free(str);
	return (-1);
}
