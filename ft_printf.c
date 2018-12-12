/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 15:22:28 by tgouedar          #+#    #+#             */
/*   Updated: 2018/12/12 22:12:39 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>



char		*ft_concat_buffer(t_buff *buff, t_pattern *pattern, va_list *ap)
{

}
/*	Cette fonction traduit le pattern et renvoit 0 s'il est invalide, 1 s'il est
 *	valide et non positionnel et 2 s'il est positionnel.
 */

int			ft_pattern_translate(char **str, t_pattern *pattern)
{
	int		i;
	int		flag;

	flag = 0;
	if (ft_isdigit(**str))
	{
		i = ft_atoi(*str);
		while (**str || ft_isdigit(**str))
			(*str)++;
		if (**str == $)
		{
			pattern->nbr = i;
			*str++;
			flag++;
			i = 0;
			while (ft_isin((*str)[i], KNOWN_FLAG))
				i++;
			pattern->flag = ft_strndup(*str, i);
			*str += i;
			if (ft_isdigit(**str))
				i = ft_atoi(*str);
			while (**str || ft_isdigit(**str))
				(*str)++;
			pattern->field_width = i;
		}
		else
			pattern->field_width = i;
		if (ft_isin(**str, ".*"))
		{
			if (ft_isdigit(**str))
				i = ft_atoi(*str);
			while (**str || ft_isdigit(**str))
				(*str)++;
			if (ft_isin(**str, KNOWN_LMOD))
		}
	}
}

/*	Cette foction decoupe les chaienes entre deux patterns et les stocke dans
 *	une liste chainee, elle envoie ensuite les patterns en traduction.
 */

t_pattern	*ft_pattern_detect(char *str, t_list **buff)
{
	size_t		i;
	int			flag;
	t_pattern	*reco;

	flag = 3;
	while ((i = ft_strcspn(str, "%")) != ft_strlen(str))
	{
		str[i] = 0;
		ft_lstadd_back(buff, ft_lstnew(str, ft_strlen(str)));
		str += i + 1;
		if ((i = ft_pattern_translate(&str, &reco)) && (flag &= i))
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


	str = ft_strdup(format);
	ft_pattern_detect(str, &buff);
	ft_concat_buffer()
		return (0);
}
