/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_conv3_printf.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 07:25:48 by tgouedar          #+#    #+#             */
/*   Updated: 2019/01/16 20:12:02 by baavril          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_conv_char(va_list *ap, t_ul type, t_pattern *conv)
{
	char	*c;

	c = ft_strnew(1);
	c[0] = (char)va_arg(*ap, int);
	return (c);
}

char			*ft_conv_addr(va_list *ap, t_ul type, t_pattern *conv)
{
	void	*ptr;
	char	*str;

	ptr = va_arg(*ap, void*);
	// "0x"
	str = ft_unsigned_itoa_base((t_ul)ptr , "0123456789abcdef");
	return (str);
}

char			*ft_conv_str(va_list *ap, t_ul type, t_pattern *conv)
{
	char	*str;

	if (conv)
	{
		if (type & ((t_ul)1 << STAR_FW))
			conv->field_width = va_arg(*ap, int);
		if (type & ((t_ul)1 << STAR_PR))
			conv->precision = va_arg(*ap, int);
	}
	str = va_arg(*ap, char*);
	if (!str)
		return ("(null)");
	return (str);
}

/* fonction qui compte nombre de caractere avant flag 'n' et "tente" de l'inscrire dans l.adresse de l'int* concerne*/

int		ft_stock_n_char(t_list **conv, va_list *ap, t_list **buff, int c)
{
	t_list	*buff_cur;
	t_list	*conv_cur;
	void	*ptr;
	int res;
	char **str;
	char **bus;

	ptr = va_arg(*ap, void*);
	buff_cur = *buff;
	conv_cur = *conv;
	ft_putnbr(c);
	if (!(str = (char**)malloc(sizeof(char*))))
		return (0);
	if (!(bus = (char**)malloc(sizeof(char*))))
		return (0);
	*bus = NULL;
	*str = ft_strnew(0);
	while (buff_cur && c > 0)
	{
		ft_putendl("x1");
		*bus = ft_strdup(buff_cur->content);
		ft_putendl("x2");
		ft_strappend(str, bus);
		ft_putendl("x3");
		res = ft_strlen(*str);
		ft_putendl("x4");
		buff_cur = buff_cur->next;
		c--;
	}
	ft_putendl("x5");
	ft_putendl("x6");
//	**j = res;
	ft_putendl("x7");
	ft_putendl(*str);
	ft_putnbr(res);
	return (1);
}

void	ft_padding(t_pattern **pattern, t_list **conv)
{
	t_pattern *voyager;
	t_list *vonc;
	char *str;
	char **bus;
	int i;

	i = 0;
	vonc = *conv;
	voyager = *pattern;
	ft_putendl("e");
	if (!(bus = (char**)malloc(sizeof(char*))))
			return ;
	while (voyager)
	{
		ft_putendl("e1");
		if (voyager->precision != -1 
			   || voyager->conv & 2 << ft_indice('0', KNOWN_FLAG))
		{
			ft_putendl("e2");
			bus = (char**)&(vonc->content);
			ft_putendl(*bus);
			ft_putnbr(voyager->precision);
			if (voyager->precision - ft_strlen(*bus) > 0)
			{
				if (!(str = malloc(voyager->precision - (ft_strlen(*bus) + 1))))
					return ;
			}
			else	
					return ;
			ft_putendl("e3");
			while (i <= (voyager->precision - (ft_strlen(*bus) + 1)))
				str[i++] = '0';
			ft_putendl("e4");
			ft_putendl(str);
			ft_strappend_back(&str, bus);
			ft_putendl(str);
			ft_putendl("e5");
			ft_putendl(*bus);
		} 
		/* attention : fonction pour prec et str non terminee centre de controle a realiser */
		if ((ft_strlen(*bus) - voyager->precision > 0))
		{
			ft_putendl("e9");
			if (!(str = malloc((ft_strlen(*bus) - voyager->precision) + 1)))
					return ;
		}
		else
			return ;
		while (i <= voyager->precision - (voyager->precision - (ft_strlen(*bus) + 1)))
			i++;
		str = ft_strndup(*bus, i);
		ft_strappend(&str, bus);
	}
	voyager = voyager->next;
	vonc = vonc->next;
}
