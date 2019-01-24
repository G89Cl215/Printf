/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_padding1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baavril <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 16:07:38 by baavril           #+#    #+#             */
/*   Updated: 2019/01/24 03:47:32 by tgouedar         ###   ########.fr       */
/*   Updated: 2019/01/24 03:00:43 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_paddering_spe(t_pattern *voyager, t_list *vonc)
{
	return ((voyager->conv & (2 << (ft_indice('0', KNOWN_FLAG)))) ?
			ft_padding_zero(voyager, vonc)
			: ft_padding_spaces(voyager, vonc));
}

void		ft_paddering_integers(t_pattern *voyager, t_list *vonc)
{
	if (voyager->conv & (2 << (ft_indice('0', KNOWN_FLAG)))
			&& (!(voyager->conv & (2 << (ft_indice('-', KNOWN_FLAG))))))
		ft_padding_zero(voyager, vonc);
	if (voyager->conv & (2 << (ft_indice('-', KNOWN_FLAG)))
			&& voyager->conv & (2 << (ft_indice('+', KNOWN_FLAG)))
			&& voyager->conv & (2 << (ft_indice('0', KNOWN_FLAG))))
		ft_padding_zero(voyager, vonc);
	if (voyager->conv & (2 << (ft_indice('-', KNOWN_FLAG))))
		ft_padding_negativ(voyager, vonc);
	if (voyager->conv & (2 << (ft_indice('+', KNOWN_FLAG))))
		ft_padding_positiv(voyager, vonc);
	if (voyager->conv & (2 << (ft_indice(' ', KNOWN_FLAG))))
		ft_padding_flag_space(voyager, vonc);
	if (voyager->conv & (2 << (ft_indice('#', KNOWN_FLAG))))
		ft_padding_flag_prefix(voyager, vonc);
	if (!(voyager->conv & (2 << (ft_indice('+', KNOWN_FLAG)))))
	{
		if (voyager->precision > -1)
			ft_padding_prec(voyager, vonc);
		if (voyager->field_width > -1)
			ft_padding_spaces(voyager, vonc);
	}
}

void	ft_padding_flag_prefix(t_pattern *voyager, t_list *vonc)
{	
	char		*str;
	char		**bus;
	t_ul		type;
	
	type = ft_type_flag(voyager);
	if (!(bus = (char**)malloc(sizeof(char*)))
				|| !(str = ft_strnew(1)))
		{
			ft_memdel((void**)bus);
			return ;
		}
	bus = (char**)&(vonc->content);
	if (type & (1 << (ft_indice('x', KNOWN_CONV))))
	{
		str[0] = '0';
		str[1] = 'x';
	}
	if (type & (1 << (ft_indice('X', KNOWN_CONV))))
	{	
		str[0] = '0';
		str[1] = 'X';
	}
	else if (type & (1 << (ft_indice('o', KNOWN_CONV))))	
		str[0] = '0';
	if (voyager->conv & (2 << (ft_indice('0', KNOWN_FLAG)))
				&& (!(voyager->conv & (2 << (ft_indice('-', KNOWN_FLAG))))))
		ft_memmove(*bus, (*bus) + 2, ft_strlen(*bus + 2) + 1);
	if ((int)ft_strlen(*bus) > 1 || **bus != '0')
		ft_strappend_back(&str, bus);
	if (voyager->conv & (2 << (ft_indice('-', KNOWN_FLAG))))
		*bus = ft_strndup(*bus, (ft_strlen(*bus) - 2));
//	if (voyager->field_width > -1 || voyager->precision > -1)
}

void	ft_padding_flag_space(t_pattern *voyager, t_list *vonc)
{
	char		*str;
	char		**bus;

	if (voyager->field_width == -1
			&& !(voyager->conv & (2 << (ft_indice('+', KNOWN_FLAG)))))
	{
		if (!(bus = (char**)malloc(sizeof(char*)))
				|| !(str = ft_strnew(0)))
		{
			ft_memdel((void**)bus);
			return ;
		}
		bus = (char**)&(vonc->content);
		if (voyager->precision != -1)
			ft_padding_prec(voyager, vonc);
		str[0] = ' ';
		ft_strappend_back(&str, bus);
	}
	else
		ft_padding_spaces(voyager, vonc);
}

void	ft_padding_positiv4(t_pattern *voyager, t_list *vonc, char **bus, char *str)
{
	if (voyager->precision)
	{
		if (!(str = ft_memalloc(voyager->precision - ft_strlen(*bus) + 1)))
			return ;
		if (voyager->field_width == -1)
			str[voyager->precision - (ft_strlen(*bus))] = '+';
		ft_strappend_back(&str, bus);
	}
}

void	ft_padding_positiv3(t_pattern *voyager, t_list *vonc, char **bus, char *str)
{
	if (voyager->field_width)
	{
		if (!(str = ft_memalloc(voyager->field_width - ft_strlen(*bus) + 1)))
			return ;
		if (voyager->precision == -1)
			str[voyager->field_width - (ft_strlen(*bus))] = '+';
		ft_strappend_back(&str, bus);
		if (!(voyager->conv & (2 << (ft_indice('0', KNOWN_FLAG)))))
		*bus = ft_strndup(*bus, ft_strlen(*bus) - 1);
	}
}

void	ft_padding_positiv2(t_pattern *voyager, t_list *vonc, char **bus, char *str)
{
	if ((voyager->field_width - (int)ft_strlen(*bus)) > 0)
	{
		if (!(str = ft_memalloc(voyager->field_width - ft_strlen(*bus) + 1)))
			return ;
		ft_memset(str, ' ', voyager->field_width - ft_strlen(*bus));
		if (voyager->precision == -1)
			str[voyager->field_width - (ft_strlen(*bus)) - 1] = '+';
		ft_strappend_back(&str, bus);
	}
	if (voyager->precision == -1 && voyager->field_width == -1)
	{
		if ((int)ft_strlen(*bus) > 0)
		{
			if (!(str = ft_strnew(ft_strlen(*bus))))
				return ;
			str[0] = '+';
			ft_strappend_back(&str, bus);
		}
	}
	if (voyager->field_width
			&& voyager->conv & (2 << (ft_indice('-', KNOWN_FLAG))) && **bus != '-')
		ft_padding_positiv3(voyager, vonc, bus, str);
}

void		ft_padding_positiv(t_pattern *voyager, t_list *vonc)
{
	char		*str;
	char		**bus;

	if (!(bus = (char**)malloc(sizeof(char*))))
		return ;
	bus = (char**)&(vonc->content);
	if (voyager->precision > -1)
	{
		if ((voyager->precision - (int)ft_strlen(*bus)) > 0)
		{
			if (!(str = ft_strnew(voyager->precision - ft_strlen(*bus) + 1)))
				return ;
			ft_memset(str, '0', voyager->precision - ft_strlen(*bus) + 1);
			str[0] = '+';
			ft_strappend_back(&str, bus);
		}
		else
			ft_padding_positiv4(voyager, vonc, bus, str);
	}
	if (voyager->field_width > -1
			|| (voyager->precision == -1
				&& voyager->field_width == -1 && **bus != '-'))
		ft_padding_positiv2(voyager, vonc, bus, str);
}

void		ft_padding_negativ(t_pattern *voyager, t_list *vonc)
{
	char	*str;
	char	**bus;

	if (!(bus = (char**)malloc(sizeof(char*))))
		return ;
	bus = (char**)&(vonc->content);
	if (voyager->precision > -1)
	{
		(**bus == '-') ? ft_padding_prec_neg(voyager, vonc)
			: ft_padding_prec(voyager, vonc);
	}
	if (voyager->field_width > -1)
	{
		if (voyager->field_width - (int)ft_strlen(*bus) > 0)
		{
			if (!(str = ft_strnew(voyager->field_width - ft_strlen(*bus))))
				return ;
			ft_memset(str, ' ', voyager->field_width - ft_strlen(*bus));
			ft_strappend(bus, &str);
		}
	}
}

void		ft_padding_0_neg(t_pattern *voyager, t_list *vonc)
{
	char	*str;
	char	**bus;

	if (voyager->field_width != -1)
	{
		if (!(bus = (char**)malloc(sizeof(char*))))
			return ;
		bus = (char**)&(vonc->content);
		ft_memmove(*bus, (*bus) + 1, ft_strlen(*bus));
		if (voyager->field_width - (int)ft_strlen(*bus) > 0)
		{
			if (!(str = ft_strnew(voyager->field_width - ft_strlen(*bus))))
				return ;
			ft_memset(str, '0', voyager->field_width - ft_strlen(*bus));
			str[0] = '-';
			ft_strappend_back(&str, bus);
		}
	}
}

void		ft_padding_str(t_pattern *voyager, t_list *vonc)
{
	char		*str;
	char		**bus;
	int			i;

	i = 0;
	bus = (char**)&(vonc->content);
	if (voyager->precision != -1)
	{
		if ((int)(ft_strlen(*bus) - voyager->precision > 0))
		{
			if (!(str = malloc(voyager->precision) + 1))
				return ;
			while (i < voyager->precision)
				i++;
			*bus = ft_strndup(*bus, i);
		}
	}
}

int			ft_central_padding(t_pattern **pattern, t_list **conv)
{
	t_pattern	*voyager;
	t_list		*vonc;
	t_ul		type;

	vonc = *conv;
	voyager = *pattern;
	while (voyager)
	{
		type = ft_type_flag(voyager);
		if (type & (1 << (ft_indice('s', KNOWN_CONV))))
		{
			ft_padding_str(voyager, vonc);
			ft_paddering_spe(voyager, vonc);
		}
		else if (type & (1 << (ft_indice('c', KNOWN_CONV))))
		{
			ft_paddering_spe(voyager, vonc);
		}
		else if (type & (1 << (ft_indice('d', KNOWN_CONV)))
				|| type & (1 << (ft_indice('i', KNOWN_CONV))))
		{
			ft_paddering_integers(voyager, vonc);
		}
		else if (type & (1 << (ft_indice('x', KNOWN_CONV)))
					|| type & (1 << (ft_indice('X', KNOWN_CONV))))
			ft_paddering_integers(voyager, vonc);
		vonc = vonc->next;
		voyager = voyager->next;
	}
	return (1);
}
