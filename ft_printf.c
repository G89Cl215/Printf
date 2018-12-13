/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 15:22:28 by tgouedar          #+#    #+#             */
/*   Updated: 2018/12/13 19:36:23 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>

/*	Recolle les bouts en lisant un buffer puis une conversion puis une
 *	conversion, jusau'a epuisement de la liste chainee buffer
 *	NB : La fonction ne doit pas avoir a faire de conversion passee la fin du
 *	buffer.
 *
 *	write la chaine de caractere creee et retourne la longueur totale de la
 *	chaine de caractere.
 */

char		*ft_concat_buffer(t_buff *buff, t_pattern *pattern, va_list *ap)
{
	
}

/*	Cette fonction decoupe les chaines entre deux patterns et les stocke dans
 *	une liste chainee, elle envoie ensuite les patterns en traduction.
 *	NB : un maillon vide sera stocke en cas 2 patterns se suivant immediatement,
 *	ou de pattern directement en debut ou fin de chaine.
 */

int		*ft_pattern_detect(char *str, t_list **buff, t_list *pattern_list)
{
	size_t		i;
	int			flag;
	t_pattern	*pattern;

	flag = 3;
	
	while ((i = ft_strcspn(str, "%")) != ft_strlen(str))
	{
		str[i] = 0;
		ft_lstadd_back(buff, ft_lstnew(str, ft_strlen(str)));
		str += i + 1;
		if ((i = ft_pattern_translate(&str, &pattern)) && (flag &= i))
		{
			free(buff);
			return (ft_error(flag));
		}

	}
	
}

int		ft_printf(const char * restrict format, ...)
{
	va_list		ap;
	char		*str;
	va_list		param;
	size_t		i;
	t_list		*buff;
	t_list		*pattern;

	str = ft_strdup(format);
	if (ft_pattern_detect(str, &buff, &pattern))
		return (ft_concat_buffer(buff, pattern, &ap));
	return (0);
}
