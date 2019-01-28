/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_padding4_float.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 02:54:37 by tgouedar          #+#    #+#             */
/*   Updated: 2019/01/24 19:25:08 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_prec_float(char *str, int prec)
{
	int		point_str;
	int		ret;

	if (prec < 0)
		prec = 6;
	point_str = ft_indice('.', str);
	ret = (str[point_str + prec + 1] - '0' > 4);
	if (!(prec))
		point_str--;
	str[point_str + prec + 1] = '\0';
	while (ret && (point_str + prec) >= 0)
	{
		if (str[point_str + prec] == '.')
			prec--;
		ret += str[point_str + prec] - '0';
		str[point_str + prec] = (ret % 10) + '0';
		ret = (ret > 9 ? 1 : 0);
		prec--;
	}
	if ((ret) && (point_str + prec) < 0)
	{
		ft_memmove(str + 1, str, ft_strlen(str) + 1);
		str[0] = ret + '0';
	}
}

void	ft_exp_increment(char *str)
{
	int		exp_str;
	int		len;
	int		ret;
	int		flag;

	len = ft_strlen(str) - 1;
	if ((exp_str = ft_indice('e', str)) == len)
		exp_str = ft_indice('E', str);
	ret = str[++exp_str] == '-' ? -1 : 1;
	flag = str[++exp_str] == '-' ? -1 : 1;
	while ((ret) && len > exp_str)
	{
		ret += str[len] - '0';
		str[len--] = (ret + 10) % 10 + '0';
		if (flag == -1)
			ret = ((ret + 10) == 9 ? -1 : 0);
		if (flag == 1)
			ret = (ret > 9 ? 1 : 0);
	}
	if ((ret) && len == exp_str)
	{
		ft_memmove(str + exp_str + 1, str + exp_str, len - exp_str + 1);
		str[exp_str + 1] = ret + '0';
	}
}

void	ft_prec_scient(char *str, int prec)
{
	int		point;
	int		e;
	int		ret;

	prec = (prec < 0) ? 6 : prec;
	if ((t_ul)(e = ft_indice('e', str)) == ft_strlen(str))
		e = ft_indice('E', str);
	point = (prec) ? prec + 2 : 1;
	ret = (prec) ? ((str[point] - '0') > 4) : ((str[point + 1] - '0') > 4);
	ft_memmove(str + point, str + e, ft_strlen(str) - e + 1);
	while ((ret) && point-- >= 0)
	{
		(str[point] == '.') ? point-- : 1;
		str[point] = (ret + str[point] - '0') % 10 + '0';
		ret = ((str[point] == '0') && (ret)) ? 1 : 0;
	}
	if ((ret) && (point) < 0)
	{
		ft_memmove(str + 1, str, ft_strlen(str) + 1);
		str[0] = ret + '0';
		str[2] = str[1];
		str[1] = '.';
		ft_exp_increment(str);
		ft_prec_scient(str, prec);
	}
}
